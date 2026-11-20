#include "common.h"


s32 func_80025A00(s32 arg0, s32 arg1) {
    f32 sp10;
    f32 sp14;
    f32 sp18;
    s32 pad0;
    f32 sp20;
    f32 sp24;
    f32 sp28;
    f64 sp30;
    f64 sp38;
    f64 sp40;

    if (func_800258A4(((s32)&sp10), (D_80075C20 + 36), ((s32)&D_800ACC20), arg0) != 0) {
        if (arg1 != 0) {
            (*(f64 *)arg1) = 0.0;
        }
        return 1;
    }
    sp20 = sp10;
    sp24 = sp14;
    sp28 = sp18;
    sp20 = sp20 - (*(f32 *)(D_80075C20 + 36));
    sp24 = sp24 - ((struct gd_4_f32 *)(D_80075C20 + 36))->v;
    sp28 = sp28 - ((struct gd_8_f32 *)(D_80075C20 + 36))->v;
    sp38 = (f64)(((sp20 * sp20) + (sp24 * sp24)) + (sp28 * sp28));
    if (sp38 < D_8007A0C0) {
        return 1;
    }
    sp38 = (f64)sqrtf(((f32)sp38));
    sp40 = D_8007A0C8 / sp38;
    sp20 = (f32)(((f64)sp20) * sp40);
    sp24 = (f32)(((f64)sp24) * sp40);
    sp28 = (f32)(((f64)sp28) * sp40);
    sp30 = (f64)(((D_8012FD30 * sp20) + (D_8012FD34 * sp24)) + (D_8012FD38 * sp28));
    if (arg1 != 0) {
        (*(f64 *)arg1) = sp30 * sp38;
    }
    if (sp30 < D_8007A0D0) {
        D_80075CB4++;
        D_80075CB8++;
        return 0;
    }
    return 1;
}
