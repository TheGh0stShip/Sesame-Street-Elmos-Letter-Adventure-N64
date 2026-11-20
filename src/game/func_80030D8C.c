#include "common.h"


void func_80030D8C(s32 arg0) {
    s32 sp10;
    s32 sp14;

    sp10 = arg0;
    if ((*(s32 *)sp10) == 19) {
        goto L13;
    }
    func_80057BD0(((s32)&D_8007A370), ((s32)&D_8007A374), 3470);
L13: ;
    sp14 = func_80040400(48);
    func_80068300(sp14, 0, 48);
    ((struct gd_8_s16 *)sp14)->v = ((struct gd_2_u16 *)sp10)->v;
    ((struct gd_A_s16 *)sp14)->v = ((struct gd_6_u16 *)sp10)->v;
    ((struct gd_C_s32 *)sp14)->v = ((struct gd_8_s32 *)sp10)->v;
    ((struct gd_14_s32 *)sp14)->v = (s32)&D_80030C48;
    ((struct gd_18_s32 *)sp14)->v = 0;
    ((struct gd_1C_s32 *)sp14)->v = 0;
    ((struct gd_20_s32 *)sp14)->v = 0;
    ((struct gd_10_s32 *)sp14)->v = (s32)&D_80030C80;
    ((struct gd_24_f32 *)sp14)->v = ((struct gd_C_f32 *)sp10)->v;
    ((struct gd_28_f32 *)sp14)->v = ((struct gd_10_f32 *)sp10)->v;
    ((struct gd_2C_f32 *)sp14)->v = ((struct gd_14_f32 *)sp10)->v;
    func_8003FE00(sp14, D_8011525C, 3, 0);
}
