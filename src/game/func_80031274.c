#include "common.h"


void func_80031274(s32 arg0) {
    register s32 reg_s0;
    s32 sp28[16];
    s32 sp68[16];
    s32 spA8[22];

    reg_s0 = arg0;
    if (D_800ACC2E != 0) {
        ((s32 (*)(s32, s32, s32, s32, f32, f32, f32))guPerspectiveF)(((s32)&sp28), ((s32)&D_80109C28), 0x42200000, 0x3FAAAAAB, 5e+01f, 1e+04f, 1.0f);
        ((s32 (*)(s32, s32, s32, s32, f32, f32, f32, f32, f32, f32))guLookAtF)(((s32)&sp68), ((struct gd_24_s32 *)reg_s0)->v, ((struct gd_28_s32 *)reg_s0)->v, ((struct gd_2C_s32 *)reg_s0)->v, ((struct gd_30_f32 *)reg_s0)->v, ((struct gd_34_f32 *)reg_s0)->v, ((struct gd_38_f32 *)reg_s0)->v, ((struct gd_3C_f32 *)reg_s0)->v, ((struct gd_40_f32 *)reg_s0)->v, ((struct gd_44_f32 *)reg_s0)->v);
        guMtxCatF(((s32)&sp68), ((s32)&sp28), ((s32)&spA8));
        guMtxF2L(((s32)&spA8), D_8013EF68);
        addActorDL(((s32)&D_80030EBC), reg_s0, 1, 0, 0);
        return;
    }
    if (((struct gd_54_u8 *)reg_s0)->v != 0) {
        ((struct gd_54_s8 *)reg_s0)->v--;
        ((struct gd_30_f32 *)reg_s0)->v = ((struct gd_30_f32 *)reg_s0)->v + ((struct gd_48_f32 *)reg_s0)->v;
        ((struct gd_34_f32 *)reg_s0)->v = ((struct gd_34_f32 *)reg_s0)->v + ((struct gd_4C_f32 *)reg_s0)->v;
        ((struct gd_38_f32 *)reg_s0)->v = ((struct gd_38_f32 *)reg_s0)->v + ((struct gd_50_f32 *)reg_s0)->v;
        ((struct gd_24_f32 *)reg_s0)->v = (f32)(((f64)((struct gd_24_f32 *)reg_s0)->v) + D_8007A8D0);
        ((struct gd_28_f32 *)reg_s0)->v = (f32)(((f64)((struct gd_28_f32 *)reg_s0)->v) + D_8007A8D8);
        ((struct gd_2C_f32 *)reg_s0)->v = (f32)(((f64)((struct gd_2C_f32 *)reg_s0)->v) + D_8007A8E0);
        D_8006DDEC = (f32)(((f64)D_8006DDEC) + D_8007A8E8);
    }
    if (((struct gd_54_u8 *)reg_s0)->v == 0) {
        if (D_80075E2C == 4) {
            D_80075E2C = 5;
            D_8012FD40 = 8;
            D_8013EA92 = 1800;
            D_801078F0 = 0;
            D_80109C4C = func_8004CC30(61);
        }
    }
}
