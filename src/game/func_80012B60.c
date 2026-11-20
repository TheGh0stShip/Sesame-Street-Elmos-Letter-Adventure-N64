#include "common.h"


s32 func_80012B60(s32 arg0) {
    f32 sp10;
    f32 sp14;
    f32 sp18;
    f64 sp20;
    f64 sp28;

    sp10 = *(f32 *)arg0;
    sp14 = ((struct gd_4_f32 *)arg0)->v;
    sp18 = ((struct gd_8_f32 *)arg0)->v;
    sp10 = sp10 - (*(f32 *)(D_80075C20 + 36));
    sp14 = sp14 - ((struct gd_4_f32 *)(D_80075C20 + 36))->v;
    sp18 = sp18 - ((struct gd_8_f32 *)(D_80075C20 + 36))->v;
    sp28 = (f64)(((sp10 * sp10) + (sp14 * sp14)) + (sp18 * sp18));
    if (sp28 > D_80079910) {
        return 0;
    }
    sp28 = D_80079918 / ((f64)sqrtf(((f32)sp28)));
    sp10 = (f32)(((f64)sp10) * sp28);
    sp14 = (f32)(((f64)sp14) * sp28);
    sp18 = (f32)(((f64)sp18) * sp28);
    sp20 = (f64)(((D_8012FD30 * sp10) + (D_8012FD34 * sp14)) + (D_8012FD38 * sp18));
    if (sp20 < D_80079920) {
        return 0;
    }
    return 1;
}
