/* alAuxBusNew / alMainBusNew (libultra audio/drvrnew.c): init a bus filter */
typedef struct ALFilter_s {
    struct ALFilter_s *source;
    void *handler;
    void *setParam;
    s16 *inp;
    s16 *outp;
} ALFilter;
typedef struct {
    ALFilter filter;
    s32 sourceCount;
    s32 maxSources;
    ALFilter **sources;
} ALBus;
void func_80059D00(ALFilter *f, void *h, void *s, s32 type); /* alFilterNew */
s32 func_80058F40();
s32 func_8005901C();
void func_80058330(ALBus *m, void *sources, s32 maxSources)
{
    func_80059D00(&m->filter, func_80058F40, func_8005901C, 6);
    m->sourceCount = 0;
    m->maxSources = maxSources;
    m->sources = (ALFilter **)sources;
}
