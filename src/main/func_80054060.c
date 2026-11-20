/* alInit: set the audio globals once and create the synthesizer */
typedef struct { s32 unk_0; } ALGlobals;
extern ALGlobals *D_800773B0;  /* alGlobals */
extern void *D_800773B4;       /* alSynth */
void func_800546A0(void *c);   /* alSynNew */
void func_80054060(ALGlobals *g, void *c)
{
    if (D_800773B0 == NULL) {
        D_800773B0 = g;
        if (D_800773B4 == NULL) {
            D_800773B4 = g;
            func_800546A0(c);
        }
    }
}
