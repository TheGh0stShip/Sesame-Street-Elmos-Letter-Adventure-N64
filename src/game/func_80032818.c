#include "common.h"


s32 func_80032818(s32 arg0, register s32 arg1, s32 arg2) {
    u8 sp18;
    s32 sp1C;
    s32 sp20;
    s32 sp24;
    f32 sp28;
    s32 pad0;
    s32 pad1;
    s32 sp34;
    s32 pad2[40];
    f64 spD8;

    sp18 = arg1;
    sp1C = arg0;
    sp24 = func_80040400(536);
    func_80068300(sp24, 0, 536);
    ((struct gd_58_f32 *)sp24)->v = 1.0f;
    ((struct gd_5C_f32 *)sp24)->v = 1.0f;
    ((struct gd_60_f32 *)sp24)->v = 1.0f;
    ((struct gd_8_s16 *)sp24)->v = ((struct gd_2_u16 *)sp1C)->v;
    ((struct gd_A_s16 *)sp24)->v = ((struct gd_6_u16 *)sp1C)->v;
    ((struct gd_C_s32 *)sp24)->v = ((struct gd_8_s32 *)sp1C)->v;
    ((struct gd_1EC_s32 *)sp24)->v = D_80133E34;
    ((struct gd_EC_s32 *)sp24)->v = 0;
    ((struct gd_F0_s32 *)sp24)->v = 0;
    ((struct gd_1F0_s32 *)sp24)->v = 4;
    ((struct gd_1B8_s8 *)sp24)->v = sp18;
    ((struct gd_1C0_s32 *)sp24)->v = arg2;
    ((struct gd_1BC_s32 *)sp24)->v = 0;
    ((struct gd_1CC_s32 *)sp24)->v = 0;
    ((struct gd_1D0_f32 *)sp24)->v = -3e+01f;
    ((struct gd_1D8_s32 *)sp24)->v = 0;
    if ((((u32)((struct gd_1B8_u8 *)sp24)->v >= 65) && ((u32)((struct gd_1B8_u8 *)sp24)->v < 91)) || (((u32)((struct gd_1B8_u8 *)sp24)->v >= 97) && ((u32)((struct gd_1B8_u8 *)sp24)->v < 123))) {
        goto L90;
    }
    func_80057BD0(((s32)&D_8007A8F0), ((s32)&D_8007A8F4), 849);
L90: ;
    if ((u32)((struct gd_1B8_u8 *)sp24)->v < 91) {
        sp20 = *(s32 *)((((struct gd_1B8_u8 *)sp24)->v * 4) + ((s32)&D_80075E4C));
    } else {
        sp20 = *(s32 *)((((struct gd_1B8_u8 *)sp24)->v * 4) + ((s32)&D_80075E9C));
    }
    if (((struct gd_20_s32 *)sp20)->v != 0) {
        sp34 = func_80040400(((struct gd_20_s32 *)sp20)->v);
        ((struct gd_10_s32 *)sp20)->v = sp34;
        ((struct gd_18_s32 *)sp20)->v = sp34 + (((struct gd_4_u16 *)sp20)->v << 4);
        func_80068300(((struct gd_18_s32 *)sp20)->v, 0, ((struct gd_20_s32 *)sp20)->v);
        func_80000EDC(((struct gd_10_s32 *)sp20)->v, ((struct gd_C_s32 *)sp20)->v, (((struct gd_4_u16 *)sp20)->v * 4));
    }
    ((struct gd_1E8_s32 *)sp24)->v = sp20;
    ((struct gd_10_s32 *)sp24)->v = (s32)&D_800336BC;
    ((struct gd_14_s32 *)sp24)->v = (s32)&D_80034AF4;
    ((struct gd_24_f32 *)sp24)->v = ((struct gd_C_f32 *)sp1C)->v;
    ((struct gd_28_f32 *)sp24)->v = ((struct gd_10_f32 *)sp1C)->v;
    ((struct gd_2C_f32 *)sp24)->v = ((struct gd_14_f32 *)sp1C)->v;
    ((struct gd_30_f32 *)sp24)->v = ((struct gd_18_f32 *)sp1C)->v;
    ((struct gd_34_f32 *)sp24)->v = ((struct gd_1C_f32 *)sp1C)->v;
    ((struct gd_38_f32 *)sp24)->v = ((struct gd_20_f32 *)sp1C)->v;
    sp28 = sqrtf((((((struct gd_30_f32 *)sp24)->v * ((struct gd_30_f32 *)sp24)->v) + (((struct gd_34_f32 *)sp24)->v * ((struct gd_34_f32 *)sp24)->v)) + (((struct gd_38_f32 *)sp24)->v * ((struct gd_38_f32 *)sp24)->v)));
    if (sp28 >= 1e-07f) {
        spD8 = D_8007A908 / ((f64)sp28);
        ((struct gd_30_f32 *)sp24)->v = (f32)(((f64)((struct gd_30_f32 *)sp24)->v) * spD8);
        ((struct gd_34_f32 *)sp24)->v = (f32)(((f64)((struct gd_34_f32 *)sp24)->v) * spD8);
        ((struct gd_38_f32 *)sp24)->v = (f32)(((f64)((struct gd_38_f32 *)sp24)->v) * spD8);
    } else {
    }
    ((struct gd_3C_f32 *)sp24)->v = ((struct gd_24_f32 *)sp1C)->v;
    ((struct gd_40_f32 *)sp24)->v = ((struct gd_28_f32 *)sp1C)->v;
    ((struct gd_44_f32 *)sp24)->v = ((struct gd_2C_f32 *)sp1C)->v;
    sp28 = sqrtf((((((struct gd_3C_f32 *)sp24)->v * ((struct gd_3C_f32 *)sp24)->v) + (((struct gd_40_f32 *)sp24)->v * ((struct gd_40_f32 *)sp24)->v)) + (((struct gd_44_f32 *)sp24)->v * ((struct gd_44_f32 *)sp24)->v)));
    if (sp28 >= 1e-07f) {
        spD8 = D_8007A910 / ((f64)sp28);
        ((struct gd_3C_f32 *)sp24)->v = (f32)(((f64)((struct gd_3C_f32 *)sp24)->v) * spD8);
        ((struct gd_40_f32 *)sp24)->v = (f32)(((f64)((struct gd_40_f32 *)sp24)->v) * spD8);
        ((struct gd_44_f32 *)sp24)->v = (f32)(((f64)((struct gd_44_f32 *)sp24)->v) * spD8);
    } else {
    }
    ((struct gd_48_f32 *)sp24)->v = (((struct gd_34_f32 *)sp24)->v * ((struct gd_44_f32 *)sp24)->v) - (((struct gd_38_f32 *)sp24)->v * ((struct gd_40_f32 *)sp24)->v);
    ((struct gd_4C_f32 *)sp24)->v = (((struct gd_38_f32 *)sp24)->v * ((struct gd_3C_f32 *)sp24)->v) - (((struct gd_30_f32 *)sp24)->v * ((struct gd_44_f32 *)sp24)->v);
    ((struct gd_50_f32 *)sp24)->v = (((struct gd_30_f32 *)sp24)->v * ((struct gd_40_f32 *)sp24)->v) - (((struct gd_34_f32 *)sp24)->v * ((struct gd_3C_f32 *)sp24)->v);
    func_8001DE6C((sp24 + 376), (sp1C + 12), (sp1C + 24), (sp1C + 36), (sp24 + 72));
    ((struct gd_1C4_f32 *)sp24)->v = (f32)func_80067FB0(((f64)((struct gd_38_f32 *)sp24)->v), ((f64)((struct gd_30_f32 *)sp24)->v));
    ((struct gd_1C8_s32 *)sp24)->v = 0;
    func_8003FE00(sp24, D_8011525C, 4, 0);
    if (D_80106870 == 2) {
        ((struct gd_54_f32 *)sp24)->v = 6e+01f;
    } else {
        ((struct gd_54_s32 *)sp24)->v = 0;
    }
    return sp24;
}
