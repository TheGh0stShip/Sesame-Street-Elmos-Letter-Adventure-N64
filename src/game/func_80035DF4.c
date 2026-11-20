#include "common.h"

extern u16 D_801078BA;

void func_80035DF4(s32 arg0) {
    s32 pad0[2];
    s8 pad1;

    if ((((struct gd_C_s32 *)arg0)->v & 8) != 0) {
        if (D_8012EFD0 != 19) {
            if (((struct gd_204_s32 *)arg0)->v != 0) {
                func_80035828(arg0, 1);
            } else {
                func_80035828(arg0, 0);
            }
        } else {
            D_80075E2F = 0;
            if (D_800745F8 != 0) {
                func_80035828(arg0, 32);
            } else {
                func_80035828(arg0, 30);
            }
        }
    }
    if (((D_801078BA & 0x1000) & 0xFFFF) != 0) {
        if (D_801078F0 != 0) {
            D_8012EFCC = 1;
            D_800A7AFA = 0;
        } else {
        }
    }
}
