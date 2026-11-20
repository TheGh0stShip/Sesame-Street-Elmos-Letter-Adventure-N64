#include "common.h"


void func_80039D9C(s32 arg0) {
    f32 sp10;
    f32 sp14;
    f32 sp18;

    ((struct gd_28_f32 *)arg0)->v = (f32)(((f64)D_8013C5B0) + D_8007ABC8);
    func_80035828(arg0, 25);
    return;
    if ((((struct gd_1FC_s32 *)arg0)->v & 0x80000000) != 0) {
        sp10 = ((struct gd_AC_f32 *)arg0)->v;
        sp14 = ((struct gd_B4_f32 *)arg0)->v;
        sp18 = -((struct gd_B0_f32 *)arg0)->v;
        if (((f64)sp14) > D_8007ABD0) {
            func_80035828(arg0, 25);
        }
    }
}
