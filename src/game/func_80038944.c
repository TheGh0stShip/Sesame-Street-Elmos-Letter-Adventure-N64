#include "common.h"

extern u16 D_801078BA;

void func_80038944(s32 arg0) {
    if (((f64)((struct gd_1D8_f32 *)arg0)->v) > D_8007AB48) {
        func_80035828(arg0, 15);
    }
    if (((D_801078BA & 0x1000) & 0xFFFF) != 0) {
        if (D_801078F0 != 0) {
            D_8012EFCC = 1;
            D_800A7AFA = 0;
        } else {
        }
    }
}
