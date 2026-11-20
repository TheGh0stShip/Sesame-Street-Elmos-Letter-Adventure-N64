/* SDK audio/env.c */
/*====================================================================
 * envmixer.c
 *
 * Copyright 1993, Silicon Graphics, Inc.
 * All Rights Reserved.
 *
 * This is UNPUBLISHED PROPRIETARY SOURCE CODE of Silicon Graphics,
 * Inc.; the contents of this file may not be disclosed to third
 * parties, copied or duplicated in any form, in whole or in part,
 * without the prior written permission of Silicon Graphics, Inc.
 *
 * RESTRICTED RIGHTS LEGEND:
 * Use, duplication or disclosure by the Government is subject to
 * restrictions as set forth in subdivision (c)(1)(ii) of the Rights
 * in Technical Data and Computer Software clause at DFARS
 * 252.227-7013, and/or in similar or successor clauses in the FAR,
 * DOD or NASA FAR Supplement. Unpublished - rights reserved under the
 * Copyright Laws of the United States.
 *====================================================================*/
#include <libaudio.h>
#include "synthInternals.h"
#include <os.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
/* env.c's static _getVol: in this ROM its name belongs to the libmus copy (80052D1C); the libultra copy is
   the unit at 80059C7C */
#define _getVol func_80059C7C
// TODO: these come from headers
#ident "$Revision: 1.49 $"
#ident "$Revision: 1.17 $"
#ifdef AUD_PROFILE
extern u32 cnt_index, env_num, env_cnt, env_max, env_min, lastCnt[];
extern u32 rate_num, rate_cnt, rate_max, rate_min;
extern u32 vol_num, vol_cnt, vol_max, vol_min;
#endif
#define EQPOWER_LENGTH 128

extern s16 eqpower[ EQPOWER_LENGTH ];

extern	f64	__pow(f64, f64);

/*
 * prototypes for private enveloper functions
 */
static  Acmd *_pullSubFrame(void *filter, s16 *inp, s16 *outp, s32 outCount,
                            s32 sampleOffset, Acmd *p) ;
static  s16 _getRate(f64 vol, f64 tgt, s32 count, u16* ratel);

static  f32 _getVol(f32 ivol, s32 samples, s16 ratem, u16 ratel);

/***********************************************************************
 * Enveloper filter public interfaces
 ***********************************************************************/
Acmd *alEnvmixerPull(void *filter, s16 *outp, s32 outCount, s32 sampleOffset,
                     Acmd *p) 
{
    Acmd        *ptr = p;
    ALEnvMixer	*e = (ALEnvMixer *)filter;
    s16         inp;
    s32         lastOffset;
    s32         thisOffset = sampleOffset;
    s32         samples;
    s16         loutp = 0;
    s32         fVol;
    ALParam     *thisParam;
    
#ifdef AUD_PROFILE
    lastCnt[++cnt_index] = osGetCount();
#endif

    /*
     * Force the input to be the resampler output
     */
    inp = AL_RESAMPLER_OUT;

    while (e->ctrlList != 0) { 
        lastOffset = thisOffset;
        thisOffset = e->ctrlList->delta;
        samples    = thisOffset - lastOffset;
        if (samples > outCount)
            break;
#line 103
        assert(samples >= 0);
        assert(samples <= AL_MAX_RSP_SAMPLES);


        switch (e->ctrlList->type) {
          case (AL_FILTER_START_VOICE_ALT):
              {                  
                  ALStartParamAlt *param = (ALStartParamAlt *)e->ctrlList;
                  ALFilter     *f = (ALFilter *) e;
                  s32 tmp;
                  
                  if (param->unity) {
                      (*e->filter.setParam)(&e->filter,
                                            AL_FILTER_SET_UNITY_PITCH, 0);
                  }
                  
                  (*e->filter.setParam)(&e->filter, AL_FILTER_SET_WAVETABLE,
                                        param->wave);
                  (*e->filter.setParam)(&e->filter, AL_FILTER_START, 0);

                  e->first  = 1;

                  e->delta  = 0;
                  e->segEnd = param->samples;

                  tmp = ((s32)param->volume * (s32)param->volume) >> 15;
                  e->volume = (s16) tmp;
                  e->pan    = param->pan;
                  e->dryamt = eqpower[param->fxMix];
                  e->wetamt = eqpower[EQPOWER_LENGTH - param->fxMix - 1];
                  
                  if (param->samples) {
                      e->cvolL  = 1;
                      e->cvolR  = 1;
                  } else {
                      /*
                       * Attack time is zero. Simply set the
                       * volume. We don't want an attack segment.
                       */
                      e->cvolL = (e->volume * eqpower[e->pan]) >> 15;
                      e->cvolR = (e->volume *
                                  eqpower[EQPOWER_LENGTH - e->pan - 1]) >> 15;
                  }

                  if (f->source) {
                      union {
                          f32 f;
                          s32 i;
                      } data;                    
                      data.f = param->pitch;
                      (*f->source->setParam)(f->source, AL_FILTER_SET_PITCH,
                                            (void *)data.i);
                  }
                  
              }
              
              break;
                
          case (AL_FILTER_SET_FXAMT):
          case (AL_FILTER_SET_PAN):
          case (AL_FILTER_SET_VOLUME):
	      ptr = _pullSubFrame(e, &inp, &loutp, samples, sampleOffset, ptr);
            
              if (e->delta >= e->segEnd){
                  /*
                   * We should have reached our target, calculate
                   * target in case e->segEnd was 0
                   */
                  e->ltgt = (e->volume * eqpower[e->pan]) >> 15;
                  e->rtgt = (e->volume *
                             eqpower[EQPOWER_LENGTH - e->pan - 1]) >> 15;
                  e->delta = e->segEnd;   /* To prevent overflow */
                  e->cvolL = e->ltgt;
                  e->cvolR = e->rtgt;
              } else {
                  /* 
                   * Estimate the current volume
                   */
                  e->cvolL = _getVol(e->cvolL, e->delta, e->lratm, e->lratl);
                  e->cvolR = _getVol(e->cvolR, e->delta, e->rratm, e->rratl);
              }
    
              /*
               * We can't have volume of zero, because the envelope
               * would never go anywhere from there
               */
              if( e->cvolL == 0 ) e->cvolL = 1;
              if( e->cvolR == 0 ) e->cvolR = 1;

              if (e->ctrlList->type == AL_FILTER_SET_PAN)

                  /*
                   * This should result in a change to the current
                   * segment rate and target
                   */
                  e->pan = (s16) e->ctrlList->data.i;

              if (e->ctrlList->type == AL_FILTER_SET_VOLUME){

                  /*
                   * Switching to a new segment
                   */
                  e->delta = 0;
                
                  /*
                   * Map volume non-linearly to give something close to
                   * loudness
                   */
                  fVol = (e->ctrlList->data.i);
                  fVol = (fVol*fVol)>>15;
                  e->volume = (s16) fVol;
                
                  e->segEnd = e->ctrlList->moredata.i;

              }
            
              if (e->ctrlList->type == AL_FILTER_SET_FXAMT){
                  e->dryamt = eqpower[e->ctrlList->data.i];
                  e->wetamt = eqpower[EQPOWER_LENGTH - e->ctrlList->data.i - 1];
              }
            
              /*
               * Force a volume update
               */
              e->first = 1;
              break;

          case (AL_FILTER_START_VOICE):
              {
                  ALStartParam *p = (ALStartParam *)e->ctrlList;
                  
                  /*
                   * Changing to PLAYING (since the previous state was
                   * persumable STOPPED, we'll just bump the output
                   * pointer rather than pull a subframe of zeros).
                   */
                  if (p->unity) {
                      (*e->filter.setParam)(&e->filter,
                                            AL_FILTER_SET_UNITY_PITCH, 0);
                  }
                  
                  (*e->filter.setParam)(&e->filter, AL_FILTER_SET_WAVETABLE,
                                        p->wave);
                  (*e->filter.setParam)(&e->filter, AL_FILTER_START, 0);
              }
              break;
              
          case (AL_FILTER_STOP_VOICE):
              {
                  /*
                   * Changing to STOPPED and reset the filter
                   */
		  ptr = _pullSubFrame(e, &inp, &loutp, samples, sampleOffset, ptr);
		  (*e->filter.setParam)(&e->filter, AL_FILTER_RESET, 0);
              }
              break;

          case (AL_FILTER_FREE_VOICE):
              {                  
                  ALSynth *drvr = &alGlobals->drvr;
                  ALFreeParam *param = (ALFreeParam *)e->ctrlList;
                  param->pvoice->offset = 0;
                  _freePVoice(drvr, (PVoice *)param->pvoice);
              }
              break;
              
          default:
              /*
               * Pull the reuired number of samples and then pass the message
               * on down the chain
               */
	      ptr = _pullSubFrame(e, &inp, &loutp, samples, sampleOffset, ptr);
              (*e->filter.setParam)(&e->filter, e->ctrlList->type,
                                    (void *) e->ctrlList->data.i);
              break;
        }
        loutp  += (samples<<1);
        outCount -= samples;

        /*
         * put the param record back on the free list
         */
        thisParam = e->ctrlList;
        e->ctrlList = e->ctrlList->next;
        if (e->ctrlList == 0)
            e->ctrlTail = 0;
        
        __freeParam(thisParam);
        
    }
    
    ptr = _pullSubFrame(e, &inp, &loutp, outCount, sampleOffset, ptr);

    /*
     * Prevent overflow in e->delta
     */
    if (e->delta > e->segEnd)
        e->delta = e->segEnd;

#ifdef AUD_PROFILE
    PROFILE_AUD(env_num, env_cnt, env_max, env_min);
#endif
    return ptr;
}
s32 alEnvmixerParam(void *filter, s32 paramID, void *param);
#line 350

Acmd* _pullSubFrame(void *filter, s16 *inp, s16 *outp, s32 outCount,
                    s32 sampleOffset, Acmd *p);

#define EXP_MASK  0x7f800000
#define MANT_MASK 0x807fffff

f64
_frexpf(f64 value, s32 *eptr);
f64
_ldexpf(f64 in, s32 ex);
/*
    _getRate()  --  This function determines how to go from the
		    current volume level (vol) to the target
		    volume level (tgt) in some number of steps
		    (count).  Two values are returned that are
		    used as multipliers to incrementally scale
		    the volume.  Some tricky math is used and
		    is explained below.
		    RWW 28jun95
*/

static
s16 _getRate(f64 vol, f64 tgt, s32 count, u16* ratel);
f32 _getVol(f32 ivol, s32 samples, s16 ratem, u16 ratel);







