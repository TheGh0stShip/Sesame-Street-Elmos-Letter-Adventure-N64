#include "common.h"

s32 func_8001FFC0();

void func_8004BAE0(s32 arg0, s32 arg1, s32 arg2) {
    register s32 reg_s0;
    register s32 reg_s1;
    f32 sp18;
    f32 sp1C;
    f32 sp20;
    s32 pad0;
    f32 sp28;
    f32 sp2C;
    f32 sp30;
    s32 pad1;
    s32 pad2[8];
    s32 sp58;
    s32 sp5C;
    f32 sp60;
    f32 sp64;
    f32 sp68;
    s32 pad3;
    f32 sp70;
    f32 sp74;
    f32 sp78;
    f32 sp7C;
    f32 sp80;
    f32 sp84;
    f64 sp88;

    if (arg0 == 0) {
        return;
    }
    reg_s0 = arg0;
    reg_s1 = *(s32 *)reg_s0;
    memcpy(arg2, arg1, 40);
    switch (D_8012C270) {
    case 0:
        sp2C = -__sinf(((struct gd_10_f32 *)arg2)->v);
        sp28 = __cosf(((struct gd_C_f32 *)arg2)->v) * __cosf(((struct gd_10_f32 *)arg2)->v);
        sp30 = __sinf(((struct gd_C_f32 *)arg2)->v) * __cosf(((struct gd_10_f32 *)arg2)->v);
        sp18 = (*(f32 *)arg2) - (sp28 * ((struct gd_18_f32 *)arg2)->v);
        sp1C = ((struct gd_4_f32 *)arg2)->v - (sp2C * ((struct gd_18_f32 *)arg2)->v);
        sp20 = ((struct gd_8_f32 *)arg2)->v - (sp30 * ((struct gd_18_f32 *)arg2)->v);
        if (((struct gd_4_s32 *)reg_s0)->v == 0) {
            ((struct gd_8_f32 *)reg_s0)->v = sp18;
            ((struct gd_C_f32 *)reg_s0)->v = sp1C;
            ((struct gd_10_f32 *)reg_s0)->v = sp20;
            ((struct gd_8C_f32 *)reg_s0)->v = sp18;
            ((struct gd_90_f32 *)reg_s0)->v = -sp20;
            ((struct gd_94_f32 *)reg_s0)->v = sp1C;
            ((struct gd_4_s32 *)reg_s0)->v = 1;
            return;
        }
        sp80 = sp18 - ((struct gd_8_f32 *)reg_s0)->v;
        sp84 = sp20 - ((struct gd_10_f32 *)reg_s0)->v;
        sp7C = (sp80 * sp80) + (sp84 * sp84);
        if (sp7C > 3.24e+06f) {
            ((struct gd_8_f32 *)reg_s0)->v = sp18;
            ((struct gd_C_f32 *)reg_s0)->v = sp1C;
            ((struct gd_10_f32 *)reg_s0)->v = sp20;
            ((struct gd_8C_f32 *)reg_s0)->v = sp18;
            ((struct gd_90_f32 *)reg_s0)->v = -sp20;
            ((struct gd_94_f32 *)reg_s0)->v = sp1C;
            ((struct gd_4_s32 *)reg_s0)->v = 1;
            return;
        }
        sp5C = 0x80000000;
        sp58 = func_8001FFC0((reg_s0 + 20), (reg_s0 + 112), (reg_s0 + 8), ((s32)&sp18), ((s32)&sp28), ((s32)&sp5C));
        if ((sp5C & 0x80000000) != 0) {
            D_8012C270 = 1;
            sp74 = ((struct gd_60_f32 *)reg_s0)->v;
            sp78 = ((struct gd_64_f32 *)reg_s0)->v;
            sp70 = (f32)func_80068880(((f64)((sp74 * sp74) + (sp78 * sp78))));
            if (!(sp70 == 0.0f)) {
                sp74 = sp74 / sp70;
                sp78 = sp78 / sp70;
            }
            ((struct gd_8_f32 *)reg_s0)->v = sp18 + (D_8013EBD0 * sp74);
            ((struct gd_10_f32 *)reg_s0)->v = sp20 - (D_8013EBD0 * sp78);
            ((struct gd_C_f32 *)reg_s0)->v = sp1C;
            D_8013EBD0 = D_8013EBD0 + ((f32)D_80115248);
            if (((f32)D_800A8CCC) < D_8013EBD0) {
                D_8013EBD0 = (f32)D_800A8CCC;
            }
            sp60 = (*(f32 *)arg2) - sp18;
            sp64 = ((struct gd_4_f32 *)arg2)->v - sp1C;
            sp68 = ((struct gd_8_f32 *)arg2)->v - sp20;
            sp70 = sqrtf((((sp60 * sp60) + (sp64 * sp64)) + (sp68 * sp68)));
            if (sp70 >= 1e-07f) {
                sp88 = D_8007B070 / ((f64)sp70);
                sp60 = (f32)(((f64)sp60) * sp88);
                sp64 = (f32)(((f64)sp64) * sp88);
                sp68 = (f32)(((f64)sp68) * sp88);
            } else {
            }
            ((struct gd_C_f32 *)arg2)->v = (f32)func_80067FB0(((f64)sp68), ((f64)sp60));
            ((struct gd_10_f32 *)arg2)->v = (f32)func_80067B60(((f64)(-sp64)));
            ((struct gd_24_s32 *)arg2)->v = ((struct gd_24_s32 *)arg2)->v | 2;
        } else {
            D_8013EBD0 = D_8013EBD0 - ((f32)D_800A75E4);
            if (((f32)D_801078D0) > D_8013EBD0) {
                D_8013EBD0 = (f32)D_801078D0;
            }
            ((struct gd_8_f32 *)reg_s0)->v = sp18;
            ((struct gd_10_f32 *)reg_s0)->v = sp20;
            ((struct gd_C_f32 *)reg_s0)->v = sp1C;
        }
        ((struct gd_8C_f32 *)reg_s0)->v = sp18;
        ((struct gd_90_f32 *)reg_s0)->v = -sp20;
        ((struct gd_94_f32 *)reg_s0)->v = sp1C;
    }
}
