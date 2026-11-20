#include "common.h"


void func_8003322C(s32 arg0, s32 arg1, s32 arg2) {
    s32 sp18;
    s32 sp1C;
    f32 sp20;
    s32 pad0;
    s32 sp28;
    s32 pad1;
    s32 pad2[32];
    s32 spB0;
    s32 spB4;
    f64 spB8;

    sp1C = func_80040400(536);
    func_80068300(sp1C, 0, 536);
    ((struct gd_1CC_f32 *)sp1C)->v = 0.001f;
    ((struct gd_58_f32 *)sp1C)->v = ((struct gd_1CC_f32 *)sp1C)->v;
    ((struct gd_5C_f32 *)sp1C)->v = ((struct gd_1CC_f32 *)sp1C)->v;
    ((struct gd_60_f32 *)sp1C)->v = ((struct gd_1CC_f32 *)sp1C)->v;
    ((struct gd_1C8_f32 *)sp1C)->v = 15.0f;
    ((struct gd_1EC_s32 *)sp1C)->v = 0;
    spB0 = func_80020D30();
    spB4 = spB0 & 255;
    spB4 = spB4 - 128;
    spB0 = (u32)spB0 >> 8;
    ((struct gd_1D0_f32 *)sp1C)->v = (f32)(((f64)((f32)spB4)) * D_8007A940);
    spB4 = spB0 & 255;
    spB4 = spB4 - 128;
    ((struct gd_1C4_f32 *)sp1C)->v = (f32)(((f64)((f32)spB4)) * D_8007A948);
    ((struct gd_1E4_s32 *)sp1C)->v = 0;
    ((struct gd_EC_s32 *)sp1C)->v = 0;
    ((struct gd_F0_s32 *)sp1C)->v = 0;
    ((struct gd_1F0_s32 *)sp1C)->v = 4;
    ((struct gd_1D8_s32 *)sp1C)->v = 0;
    sp18 = *(s32 *)((func_80020EB4(26) * 4) + ((s32)&D_80075F50));
    if (((struct gd_20_s32 *)sp18)->v != 0) {
        sp28 = func_80040400(((struct gd_20_s32 *)sp18)->v);
        ((struct gd_10_s32 *)sp18)->v = sp28;
        ((struct gd_18_s32 *)sp18)->v = sp28 + (((struct gd_4_u16 *)sp18)->v << 4);
        func_80068300(((struct gd_18_s32 *)sp18)->v, 0, ((struct gd_20_s32 *)sp18)->v);
        func_80000EDC(((struct gd_10_s32 *)sp18)->v, ((struct gd_C_s32 *)sp18)->v, (((struct gd_4_u16 *)sp18)->v * 4));
    }
    ((struct gd_1E8_s32 *)sp1C)->v = sp18;
    ((struct gd_10_s32 *)sp1C)->v = (s32)&D_80032EB4;
    ((struct gd_14_s32 *)sp1C)->v = (s32)&D_80034AF4;
    ((struct gd_24_f32 *)sp1C)->v = (f32)arg0;
    ((struct gd_28_f32 *)sp1C)->v = (f32)arg1;
    ((struct gd_2C_f32 *)sp1C)->v = (f32)arg2;
    ((struct gd_30_s32 *)sp1C)->v = 0;
    ((struct gd_34_s32 *)sp1C)->v = 0;
    ((struct gd_38_f32 *)sp1C)->v = 1.0f;
    ((struct gd_3C_s32 *)sp1C)->v = 0;
    ((struct gd_40_f32 *)sp1C)->v = 1.0f;
    ((struct gd_44_s32 *)sp1C)->v = 0;
    sp20 = sqrtf((((((struct gd_3C_f32 *)sp1C)->v * ((struct gd_3C_f32 *)sp1C)->v) + (((struct gd_40_f32 *)sp1C)->v * ((struct gd_40_f32 *)sp1C)->v)) + (((struct gd_44_f32 *)sp1C)->v * ((struct gd_44_f32 *)sp1C)->v)));
    if (sp20 >= 1e-07f) {
        spB8 = D_8007A950 / ((f64)sp20);
        ((struct gd_3C_f32 *)sp1C)->v = (f32)(((f64)((struct gd_3C_f32 *)sp1C)->v) * spB8);
        ((struct gd_40_f32 *)sp1C)->v = (f32)(((f64)((struct gd_40_f32 *)sp1C)->v) * spB8);
        ((struct gd_44_f32 *)sp1C)->v = (f32)(((f64)((struct gd_44_f32 *)sp1C)->v) * spB8);
    } else {
    }
    ((struct gd_48_f32 *)sp1C)->v = (((struct gd_34_f32 *)sp1C)->v * ((struct gd_44_f32 *)sp1C)->v) - (((struct gd_38_f32 *)sp1C)->v * ((struct gd_40_f32 *)sp1C)->v);
    ((struct gd_4C_f32 *)sp1C)->v = (((struct gd_38_f32 *)sp1C)->v * ((struct gd_3C_f32 *)sp1C)->v) - (((struct gd_30_f32 *)sp1C)->v * ((struct gd_44_f32 *)sp1C)->v);
    ((struct gd_50_f32 *)sp1C)->v = (((struct gd_30_f32 *)sp1C)->v * ((struct gd_40_f32 *)sp1C)->v) - (((struct gd_34_f32 *)sp1C)->v * ((struct gd_3C_f32 *)sp1C)->v);
    func_8001DE6C((sp1C + 376), (sp1C + 36), (sp1C + 48), (sp1C + 60), (sp1C + 72));
    func_8003FE00(sp1C, D_8011525C, 4, 0);
}
