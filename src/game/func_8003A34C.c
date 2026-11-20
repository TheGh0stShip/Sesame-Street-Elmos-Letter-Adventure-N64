#include "common.h"

extern u16 D_801078BA;

void func_8003A34C(s32 arg0) {
    f32 sp10;
    f32 sp14;
    f32 sp18;
    s32 pad0;
    f32 sp20;
    f64 sp28;

    if (((f64)((struct gd_1D8_f32 *)arg0)->v) < D_8007ABE0) {
        func_80035828(arg0, 26);
        return;
    }
    sp10 = ((struct gd_1AC_f32 *)arg0)->v;
    sp14 = 0;
    sp18 = ((struct gd_1B4_f32 *)arg0)->v;
    sp20 = sqrtf((((sp10 * sp10) + (sp14 * sp14)) + (sp18 * sp18)));
    if (sp20 >= 1e-07f) {
        sp28 = D_8007ABE8 / ((f64)sp20);
        sp10 = (f32)(((f64)sp10) * sp28);
        sp14 = (f32)(((f64)sp14) * sp28);
        sp18 = (f32)(((f64)sp18) * sp28);
    } else {
    }
    D_8012EFA8 = (u32)((f64)sp20 * D_8007ABF0);
    if ((u32)D_8012EFA8 >= 129) {
        D_8012EFA8 = 128;
    }
    D_80140F90 = D_8012EFAB;
    ((s32 (*)())func_8004D020)(D_800A7ABC, D_8012EFA8);
    if (((D_801078BA & 0x1000) & 0xFFFF) != 0) {
        if (D_801078F0 != 0) {
            D_8012EFCC = 1;
            D_800A7AFA = 0;
        } else {
        }
    }
}
