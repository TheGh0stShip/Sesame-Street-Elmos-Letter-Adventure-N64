#include "common.h"

extern s32 D_800816A0;

void func_8000BB1C(s32 arg0) {
    s32 pad0[16];
    s8 pad1;

    osInitialize();
    osCreateThread(((s32)&D_8007D4F0), 1, ((s32)&D_8000BB84), arg0, ((s32)&D_800816A0), 10);
    osStartThread(((s32)&D_8007D4F0));
}
