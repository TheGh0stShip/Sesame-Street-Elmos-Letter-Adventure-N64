#include "common.h"
#include "libmus/player.h"

typedef struct { u8 pad[0x1C]; } Slot;
extern Slot *D_800A00D8;
void func_80054620(Slot *);
/* drains the event queue, then advances every active entry by one tick */
s32 func_8004D76C(void) {
    s32 i;
    channel_t *e;
    f32 f;

    while (D_800A0114 != D_800A0118) {
        func_8004D654(&D_800A0120[D_800A0114]);
        if (++D_800A0114 == D_800A011C) {
            D_800A0114 = 0;
        }
    }
    for (i = -4, e = mus_channels; i < max_channels - 4; i++, e++) {
        if ((*(s32 *)&e->pdata) == 0 || ((*(s32 *)&e->flags) & 1)) {
            continue;
        }
        if ((*(s32 *)&e->sample) != 0) {
            func_8004DFA4(e, i);
        }
        e->channel_frame += (*(u16 *)&e->channel_tempo);
        if (e->length != 0x7FFF) {
            while ((s32)(e->note_end_frame - e->channel_frame) < 0) {
                if ((*(s32 *)&e->pdata) == 0) {
                    break;
                }
                func_8004DA5C(e, i);
            }
            if ((*(s32 *)&e->pdata) == 0) {
                continue;
            }
        }
        if ((*(s32 *)&e->pvolume) != 0 && (s32)(e->volume_frame - e->channel_frame) < 0) {
            func_8004E674(e);
        }
        if ((*(s32 *)&e->ppitchbend) != 0 && (s32)(e->pitchbend_frame - e->channel_frame) < 0) {
            func_8004E738(e);
        }
        if (e->stopping != -1) {
            if (--e->stopping == -1) {
                (*(s32 *)&e->pvolume) = 0;
                (*(s32 *)&e->ppitchbend) = 0;
                (*(s32 *)&e->song_addr) = 0;
                (*(s32 *)&e->fx_addr) = 0;
                (*(s32 *)&e->handle) = 0;
                (*(s32 *)&e->sample) = 0;
                (*(s32 *)&e->pdata) = 0;
                if (e->playing != 0) {
                    e->playing = 0;
                    func_80054620(&D_800A00D8[i]);
                }
            }
        }
        if (e->playing != 0) {
            if (e->env_phase != 0) {
                func_8004E2F0(e);
            }
            if (e->sweep_speed != 0 && (s32)(e->sweep_frame - e->channel_frame) < 0) {
                func_8004E500(e);
            }
            f = e->freqoffset;
            if (e->vib_speed != 0) {
                f += func_8004E610(e);
            }
            if (e->wobble_on_speed != 0) {
                f += func_8004E5B8(e);
            }
            if ((*(s32 *)&e->sample) == 0) {
                func_8004E174(e, i, f);
                func_8004E020(e, i);
            }
        }
        (*(s16 *)&e->ticks) = (e->channel_frame - e->note_start_frame) >> 8;
    }
    return D_800A00E8;
}
