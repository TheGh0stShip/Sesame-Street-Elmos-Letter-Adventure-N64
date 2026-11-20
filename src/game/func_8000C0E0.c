#include "common.h"


void func_8000C0E0(s32 arg0, s32 arg1, s32 arg2) {
    s32 sp20[6];
    s32 sp38[2];

    osInvalDCache(arg1, arg2);
    osPiStartDma(((s32)&sp20), 0, 0, arg0, arg1, arg2, ((s32)&D_80082B88));
    osRecvMesg(((s32)&D_80082B88), ((s32)&sp38), 1);
}
