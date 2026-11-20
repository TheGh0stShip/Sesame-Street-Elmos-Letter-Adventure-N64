#include "common.h"


void func_80047C00(s32 arg0) {
    s32 sp10;

    D_800A00B8 = arg0;
    D_800A00B4 = func_80040400((D_800A00B8 * 16));
    D_800A00B0 = D_800A00B4;
    sp10 = 0;
    while (!((u32)sp10 >= (u32)(D_800A00B8 - 1))) {
        ((struct n64dk_v0 *)((sp10 * 16) + D_800A00B4))->v = (void *)&((struct n64dk_m10_10 *)D_800A00B4)->m[sp10];
        sp10++;
    }
    (*(s32 *)((sp10 * 16) + D_800A00B4)) = 0;
    return;
}
