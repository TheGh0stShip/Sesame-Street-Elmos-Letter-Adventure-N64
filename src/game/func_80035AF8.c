#include "common.h"

extern u16 D_801078BA;

void func_80035AF8(s32 arg0) {
    f32 sp10;
    f32 sp14;
    f32 sp18;
    s32 pad0;
    f32 sp20;
    f64 sp28;

    sp10 = ((struct gd_1AC_f32 *)arg0)->v;
    sp14 = 0;
    sp18 = ((struct gd_1B4_f32 *)arg0)->v;
    sp20 = sqrtf((((sp10 * sp10) + (sp14 * sp14)) + (sp18 * sp18)));
    if (sp20 >= 1e-07f) {
        sp28 = D_8007AA78 / ((f64)sp20);
        sp10 = (f32)(((f64)sp10) * sp28);
        sp14 = (f32)(((f64)sp14) * sp28);
        sp18 = (f32)(((f64)sp18) * sp28);
    } else {
    }
    if (((f64)sp20) > D_8007AA80) {
        sp20 = 127.0f;
    }
    D_80140F90 = (s32)sp20;
    ((struct gd_226_s16 *)arg0)->v = ((u8)sp20 << 1) + 8;
    if ((u32)((struct gd_226_u16 *)arg0)->v >= 17) {
        ((struct gd_226_s16 *)arg0)->v = 16;
    }
    func_80035A28();
    if (((D_801078BA & 0xC00F) & 0xFFFF) != 0) {
        if (D_8012EFD0 != 11) {
            func_80035828(arg0, 6);
        }
    } else {
        if (((struct gd_204_s32 *)arg0)->v == 0) {
            func_80035828(arg0, 0);
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
