#include "common.h"

typedef struct { void *unk_0; s32 unk_4; } Pair;
extern void *__MusIntMemMalloc(s32);
extern void osCreateThread(void *, s32, void *, void *, void *, s32);
extern void osStartThread(void *);
extern s32 osAiSetFrequency(s32);
extern Pair *D_800A0334;
extern void *D_800A0338;
/* audio setup: build config, allocate buffers, start audio thread */
void func_80050CA0(Params *p, s32 arg1, u8 arg2) {
    Cfg c;
    s32 n;
    u32 i;
    c.unk_0 = c.unk_4 = p->unk_4;
    c.unk_8 = p->unk_28;
    c.unk_10 = func_800506A0(p->unk_38, p->unk_3C);
    c.unk_1C = arg2;
    c.unk_18 = osAiSetFrequency(p->unk_2C);
    c.unk_14 = func_80051014();
    func_8004FE50(D_8012FC68, &c);
    n = func_80051CB0(p->unk_34, c.unk_18, arg1, 0xF);
    D_800A0338 = __MusIntMemMalloc(p->unk_30 * 8);
    D_800A0334 = __MusIntMemMalloc(0x18);
    for (i = 0; i < 3; i++) {
        D_800A0334[i].unk_0 = __MusIntMemMalloc(n * 4);
    }
    D_800A0330 = __MusIntMemMalloc(0x2000);
    osCreateThread(D_800A0180, 3, D_80050DD8, NULL, D_800A0330 + 0x2000, p->unk_C);
    osStartThread(D_800A0180);
}
