#include "common.h"


void func_8003E3E0(s32 arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4) {
    s32 sp18;
    s32 sp1C;
    s32 sp20;
    f32 sp24;
    s32 pad0[2];
    s32 sp30;
    s32 pad1;
    s32 pad2[4];
    f32 sp48;
    f32 sp4C;
    f32 sp50;
    s32 pad3;
    s32 pad4[6];
    f64 sp70;

    sp18 = 0;
    sp1C = 0;
    sp48 = 0;
    sp4C = 1.0f;
    sp50 = 0;
    sp20 = func_80040400(536);
    func_80068300(sp20, 0, 536);
    ((struct gd_8_s16 *)sp20)->v = 20;
    ((struct gd_A_s16 *)sp20)->v = arg4;
    ((struct gd_1EC_s32 *)sp20)->v = D_80133E34;
    ((struct gd_1F0_s32 *)sp20)->v = 5;
    switch (((struct gd_A_u16 *)sp20)->v) {
    case 0:
        sp1C = (s32)&D_8029CA80;
        sp18 = func_80018530(sp1C, ((struct gd_4_u16 *)sp1C)->v);
        switch (sp18) {
        case 0:
            func_80057BD0(((s32)&D_8007AD40), ((s32)&D_8007AD44), 116);
        }
        if (sp18 == 0) {
            return;
        }
        ((struct gd_1BC_s32 *)sp20)->v = (s32)&D_8029CAD0;
        break;
    default:
        sp1C = (s32)&D_802990C0;
        sp18 = func_80018530(sp1C, ((struct gd_4_u16 *)sp1C)->v);
        switch (sp18) {
        case 0:
            func_80057BD0(((s32)&D_8007AD40), ((s32)&D_8007AD44), 124);
        }
        if (sp18 == 0) {
            return;
        }
        ((struct gd_1BC_s32 *)sp20)->v = (s32)&D_80299110;
        break;
    }
    if (sp18 != 0) {
        if (((struct gd_20_s32 *)sp18)->v != 0) {
            sp30 = func_80040400(((struct gd_20_s32 *)sp18)->v);
            ((struct gd_10_s32 *)sp18)->v = sp30;
            ((struct gd_18_s32 *)sp18)->v = sp30 + (((struct gd_4_u16 *)sp18)->v << 4);
            func_80068300(((struct gd_18_s32 *)sp18)->v, 0, ((struct gd_20_s32 *)sp18)->v);
            func_80000EDC(((struct gd_10_s32 *)sp18)->v, ((struct gd_C_s32 *)sp18)->v, (((struct gd_4_u16 *)sp18)->v * 4));
        }
    } else {
        return;
    }
    ((struct gd_10_s32 *)sp20)->v = (s32)&D_8003EA30;
    ((struct gd_14_s32 *)sp20)->v = (s32)&D_8003F104;
    ((struct gd_1A8_f32 *)sp20)->v = 1.0f;
    ((struct gd_1AC_f32 *)sp20)->v = 1.0f;
    ((struct gd_1B0_f32 *)sp20)->v = 1.0f;
    ((struct gd_1B8_s32 *)sp20)->v = 0;
    ((struct gd_1B4_s32 *)sp20)->v = 0;
    ((struct gd_1D4_s8 *)sp20)->v = 0;
    ((struct gd_1D4_f32 *)sp20)->v = arg1;
    ((struct gd_1D8_f32 *)sp20)->v = arg2;
    ((struct gd_1DC_f32 *)sp20)->v = arg3;
    ((struct gd_1E8_s32 *)sp20)->v = sp18;
    ((struct gd_24_f32 *)sp20)->v = ((struct gd_24_f32 *)arg0)->v;
    ((struct gd_28_f32 *)sp20)->v = ((struct gd_28_f32 *)arg0)->v;
    ((struct gd_2C_f32 *)sp20)->v = ((struct gd_2C_f32 *)arg0)->v;
    ((struct gd_30_f32 *)sp20)->v = ((struct gd_30_f32 *)arg0)->v;
    ((struct gd_34_f32 *)sp20)->v = ((struct gd_34_f32 *)arg0)->v;
    ((struct gd_38_f32 *)sp20)->v = ((struct gd_38_f32 *)arg0)->v;
    sp24 = sqrtf((((((struct gd_30_f32 *)sp20)->v * ((struct gd_30_f32 *)sp20)->v) + (((struct gd_34_f32 *)sp20)->v * ((struct gd_34_f32 *)sp20)->v)) + (((struct gd_38_f32 *)sp20)->v * ((struct gd_38_f32 *)sp20)->v)));
    if (sp24 >= 1e-07f) {
        sp70 = D_8007AD58 / ((f64)sp24);
        ((struct gd_30_f32 *)sp20)->v = (f32)(((f64)((struct gd_30_f32 *)sp20)->v) * sp70);
        ((struct gd_34_f32 *)sp20)->v = (f32)(((f64)((struct gd_34_f32 *)sp20)->v) * sp70);
        ((struct gd_38_f32 *)sp20)->v = (f32)(((f64)((struct gd_38_f32 *)sp20)->v) * sp70);
    } else {
    }
    ((struct gd_3C_f32 *)sp20)->v = sp48;
    ((struct gd_40_f32 *)sp20)->v = sp4C;
    ((struct gd_44_f32 *)sp20)->v = sp50;
    sp24 = sqrtf((((((struct gd_3C_f32 *)sp20)->v * ((struct gd_3C_f32 *)sp20)->v) + (((struct gd_40_f32 *)sp20)->v * ((struct gd_40_f32 *)sp20)->v)) + (((struct gd_44_f32 *)sp20)->v * ((struct gd_44_f32 *)sp20)->v)));
    if (sp24 >= 1e-07f) {
        sp70 = D_8007AD60 / ((f64)sp24);
        ((struct gd_3C_f32 *)sp20)->v = (f32)(((f64)((struct gd_3C_f32 *)sp20)->v) * sp70);
        ((struct gd_40_f32 *)sp20)->v = (f32)(((f64)((struct gd_40_f32 *)sp20)->v) * sp70);
        ((struct gd_44_f32 *)sp20)->v = (f32)(((f64)((struct gd_44_f32 *)sp20)->v) * sp70);
    } else {
    }
    ((struct gd_48_f32 *)sp20)->v = (((struct gd_34_f32 *)sp20)->v * ((struct gd_44_f32 *)sp20)->v) - (((struct gd_38_f32 *)sp20)->v * ((struct gd_40_f32 *)sp20)->v);
    ((struct gd_4C_f32 *)sp20)->v = (((struct gd_38_f32 *)sp20)->v * ((struct gd_3C_f32 *)sp20)->v) - (((struct gd_30_f32 *)sp20)->v * ((struct gd_44_f32 *)sp20)->v);
    ((struct gd_50_f32 *)sp20)->v = (((struct gd_30_f32 *)sp20)->v * ((struct gd_40_f32 *)sp20)->v) - (((struct gd_34_f32 *)sp20)->v * ((struct gd_3C_f32 *)sp20)->v);
    func_8001DE6C((sp20 + 360), (sp20 + 36), (sp20 + 48), (sp20 + 60), (sp20 + 72));
    ((struct gd_1C4_s32 *)sp20)->v = 0;
    func_8003FE00(sp20, D_8011525C, 4, 0);
    return;
}
