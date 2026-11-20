#include "common.h"


void func_80032EB4(s32 arg0) {
    s32 sp18;
    f32 sp1C;
    f32 sp20;
    f32 sp24;

    sp18 = arg0;
    if (D_800ACC2E != 0) {
        ((s32 (*)())func_8001F1C8)(((s32)&((struct n64dk_mF8_40 *)sp18)->m[D_80070760]), (sp18 + 36), ((struct { u8 pad[0x58]; struct V3 v; } *)sp18)->v);
        addActorDL(((s32)&D_80034B64), sp18, ((struct gd_1F0_s32 *)sp18)->v, 1, 0);
        return;
    }
    if (D_80109B8C >= 5) {
        if (D_80109B8C >= 8) {
            ((struct gd_C_s32 *)sp18)->v = ((struct gd_C_s32 *)sp18)->v | 1;
        }
        return;
    }
    if ((++((struct gd_1EC_s32 *)sp18)->v) >= 81) {
        ((struct gd_C_s32 *)sp18)->v = ((struct gd_C_s32 *)sp18)->v | 1;
        return;
    }
    if (((f64)((struct gd_1CC_f32 *)sp18)->v) < D_8007A918) {
        ((struct gd_1CC_f32 *)sp18)->v = (f32)(((f64)((struct gd_1CC_f32 *)sp18)->v) + D_8007A920);
    }
    ((struct gd_58_f32 *)sp18)->v = ((struct gd_1CC_f32 *)sp18)->v;
    ((struct gd_5C_f32 *)sp18)->v = ((struct gd_1CC_f32 *)sp18)->v;
    ((struct gd_60_f32 *)sp18)->v = ((struct gd_1CC_f32 *)sp18)->v;
    ((struct gd_2C_f32 *)sp18)->v = ((struct gd_2C_f32 *)sp18)->v + ((struct gd_1D0_f32 *)sp18)->v;
    ((struct gd_28_f32 *)sp18)->v = ((struct gd_28_f32 *)sp18)->v + ((struct gd_1C8_f32 *)sp18)->v;
    ((struct gd_2C_f32 *)sp18)->v = ((struct gd_2C_f32 *)sp18)->v + ((struct gd_1C4_f32 *)sp18)->v;
    if (((f64)((struct gd_1C8_f32 *)sp18)->v) > D_8007A928) {
        ((struct gd_1C8_f32 *)sp18)->v = (f32)(((f64)((struct gd_1C8_f32 *)sp18)->v) - D_8007A930);
    }
    ((struct gd_1E4_s32 *)sp18)->v = ((struct gd_1E4_s32 *)sp18)->v + 8;
    if (((struct gd_1E4_s32 *)sp18)->v >= 361) {
        ((struct gd_1E4_s32 *)sp18)->v = ((struct gd_1E4_s32 *)sp18)->v - 360;
    }
    sp24 = (f32)(((f64)((f32)((struct gd_1E4_s32 *)sp18)->v)) * D_8007A938);
    sp1C = __cosf(sp24);
    sp20 = __sinf(sp24);
    ((struct gd_30_f32 *)sp18)->v = sp1C;
    ((struct gd_34_s32 *)sp18)->v = 0;
    ((struct gd_38_f32 *)sp18)->v = sp20;
    ((struct gd_48_f32 *)sp18)->v = (((struct gd_34_f32 *)sp18)->v * ((struct gd_44_f32 *)sp18)->v) - (((struct gd_38_f32 *)sp18)->v * ((struct gd_40_f32 *)sp18)->v);
    ((struct gd_4C_f32 *)sp18)->v = (((struct gd_38_f32 *)sp18)->v * ((struct gd_3C_f32 *)sp18)->v) - (((struct gd_30_f32 *)sp18)->v * ((struct gd_44_f32 *)sp18)->v);
    ((struct gd_50_f32 *)sp18)->v = (((struct gd_30_f32 *)sp18)->v * ((struct gd_40_f32 *)sp18)->v) - (((struct gd_34_f32 *)sp18)->v * ((struct gd_3C_f32 *)sp18)->v);
}
