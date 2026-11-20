#include "common.h"


void func_8002A120(s32 arg0) {
    register s32 reg_s0;
    register s32 reg_s1;
    s32 sp10;
    s32 sp14;
    f32 sp18;
    s32 pad0;
    s32 pad1[2];
    s32 sp28;
    s32 pad2;
    f32 sp30;
    f32 sp34;
    f32 sp38;
    s32 pad3;
    f32 sp40;
    f32 sp44;
    f32 sp48;
    s32 pad4;
    f32 sp50;
    f32 sp54;
    f32 sp58;
    f64 sp60;

    sp14 = 0;
    sp28 = 0;
    sp10 = arg0;
    reg_s1 = arg0;
    switch (D_8012EFD0) {
    case 18:
        sp28 = (s32)&D_80168D60;
        break;
    case 15:
        sp28 = (s32)&D_802E3118;
        break;
    case 16:
        sp28 = (s32)&D_802E3118;
        break;
    case 14:
        sp28 = (s32)&D_8015B7C8;
        break;
    case 13:
        sp28 = (s32)&D_8015F3A8;
        break;
    default:
        sp28 = (s32)&D_802AEAC0;
        break;
    }
    sp14 = func_80018530(sp28, ((struct gd_4_u16 *)sp28)->v);
    switch (sp14) {
    case 0:
        func_80057BD0(((s32)&D_8007A370), ((s32)&D_8007A374), 413);
    }
    if ((*(s32 *)reg_s1) == 5) {
        goto L65;
    }
    func_80057BD0(((s32)&D_8007A370), ((s32)&D_8007A374), 416);
L65: ;
    reg_s0 = func_80040400(560);
    switch (reg_s0) {
    case 0:
        func_80057BD0(((s32)&D_8007A370), ((s32)&D_8007A374), 419);
    }
    if (reg_s0 == 0) {
        return;
    }
    D_80106888 = reg_s0;
    func_80068300(reg_s0, 0, 560);
    ((struct gd_10_s32 *)reg_s0)->v = (s32)&D_8002AB50;
    ((struct gd_14_s32 *)reg_s0)->v = (s32)&D_8002BC90;
    ((struct gd_18_s32 *)reg_s0)->v = (s32)&D_80030094;
    ((struct gd_8_s16 *)reg_s0)->v = ((struct gd_2_u16 *)reg_s1)->v;
    ((struct gd_A_s16 *)reg_s0)->v = ((struct gd_6_u16 *)reg_s1)->v;
    ((struct gd_C_s32 *)reg_s0)->v = ((struct gd_8_s32 *)reg_s1)->v;
    ((struct gd_54_f32 *)reg_s0)->v = 1.0f;
    ((struct gd_58_f32 *)reg_s0)->v = 1.0f;
    ((struct gd_5C_f32 *)reg_s0)->v = 1.0f;
    ((struct gd_F0_s32 *)reg_s0)->v = sp14;
    ((struct gd_24_f32 *)reg_s0)->v = ((struct gd_C_f32 *)reg_s1)->v;
    ((struct gd_28_f32 *)reg_s0)->v = ((struct gd_10_f32 *)reg_s1)->v;
    ((struct gd_2C_f32 *)reg_s0)->v = ((struct gd_14_f32 *)reg_s1)->v;
    ((struct gd_30_f32 *)reg_s0)->v = ((struct gd_18_f32 *)reg_s1)->v;
    ((struct gd_34_f32 *)reg_s0)->v = ((struct gd_1C_f32 *)reg_s1)->v;
    ((struct gd_38_f32 *)reg_s0)->v = ((struct gd_20_f32 *)reg_s1)->v;
    sp18 = sqrtf((((((struct gd_30_f32 *)reg_s0)->v * ((struct gd_30_f32 *)reg_s0)->v) + (((struct gd_34_f32 *)reg_s0)->v * ((struct gd_34_f32 *)reg_s0)->v)) + (((struct gd_38_f32 *)reg_s0)->v * ((struct gd_38_f32 *)reg_s0)->v)));
    if (sp18 >= 1e-07f) {
        sp60 = D_8007A3A0 / ((f64)sp18);
        ((struct gd_30_f32 *)reg_s0)->v = (f32)(((f64)((struct gd_30_f32 *)reg_s0)->v) * sp60);
        ((struct gd_34_f32 *)reg_s0)->v = (f32)(((f64)((struct gd_34_f32 *)reg_s0)->v) * sp60);
        ((struct gd_38_f32 *)reg_s0)->v = (f32)(((f64)((struct gd_38_f32 *)reg_s0)->v) * sp60);
    } else {
    }
    ((struct gd_1B8_f32 *)reg_s0)->v = ((struct gd_30_f32 *)reg_s0)->v;
    ((struct gd_1BC_f32 *)reg_s0)->v = ((struct gd_34_f32 *)reg_s0)->v;
    ((struct gd_1C0_f32 *)reg_s0)->v = ((struct gd_38_f32 *)reg_s0)->v;
    D_8012EFC0 = ((struct gd_30_f32 *)reg_s0)->v;
    D_8012EFC4 = ((struct gd_34_f32 *)reg_s0)->v;
    D_8012EFC8 = ((struct gd_38_f32 *)reg_s0)->v;
    ((struct gd_3C_f32 *)reg_s0)->v = ((struct gd_24_f32 *)reg_s1)->v;
    ((struct gd_40_f32 *)reg_s0)->v = ((struct gd_28_f32 *)reg_s1)->v;
    ((struct gd_44_f32 *)reg_s0)->v = ((struct gd_2C_f32 *)reg_s1)->v;
    sp18 = sqrtf((((((struct gd_3C_f32 *)reg_s0)->v * ((struct gd_3C_f32 *)reg_s0)->v) + (((struct gd_40_f32 *)reg_s0)->v * ((struct gd_40_f32 *)reg_s0)->v)) + (((struct gd_44_f32 *)reg_s0)->v * ((struct gd_44_f32 *)reg_s0)->v)));
    if (sp18 >= 1e-07f) {
        sp60 = D_8007A3A8 / ((f64)sp18);
        ((struct gd_3C_f32 *)reg_s0)->v = (f32)(((f64)((struct gd_3C_f32 *)reg_s0)->v) * sp60);
        ((struct gd_40_f32 *)reg_s0)->v = (f32)(((f64)((struct gd_40_f32 *)reg_s0)->v) * sp60);
        ((struct gd_44_f32 *)reg_s0)->v = (f32)(((f64)((struct gd_44_f32 *)reg_s0)->v) * sp60);
    } else {
    }
    ((struct gd_48_f32 *)reg_s0)->v = (((struct gd_34_f32 *)reg_s0)->v * ((struct gd_44_f32 *)reg_s0)->v) - (((struct gd_38_f32 *)reg_s0)->v * ((struct gd_40_f32 *)reg_s0)->v);
    ((struct gd_4C_f32 *)reg_s0)->v = (((struct gd_38_f32 *)reg_s0)->v * ((struct gd_3C_f32 *)reg_s0)->v) - (((struct gd_30_f32 *)reg_s0)->v * ((struct gd_44_f32 *)reg_s0)->v);
    ((struct gd_50_f32 *)reg_s0)->v = (((struct gd_30_f32 *)reg_s0)->v * ((struct gd_40_f32 *)reg_s0)->v) - (((struct gd_34_f32 *)reg_s0)->v * ((struct gd_3C_f32 *)reg_s0)->v);
    ((struct gd_1F8_s32 *)reg_s0)->v = 0;
    ((struct gd_1F4_f32 *)reg_s0)->v = -3.0f;
    ((struct gd_204_s32 *)reg_s0)->v = 0;
    ((struct gd_1D4_s32 *)reg_s0)->v = 2;
    ((struct gd_226_s16 *)reg_s0)->v = 8;
    ((struct gd_1D8_s32 *)reg_s0)->v = 0;
    ((struct gd_1DC_s32 *)reg_s0)->v = 0;
    ((struct gd_1E0_s32 *)reg_s0)->v = 0;
    ((struct gd_1E4_s32 *)reg_s0)->v = 0;
    ((struct gd_1E8_s32 *)reg_s0)->v = 0;
    ((struct gd_1EC_s32 *)reg_s0)->v = 0;
    ((struct gd_1F0_s32 *)reg_s0)->v = 0;
    ((struct gd_200_s32 *)reg_s0)->v = 0;
    ((struct gd_214_s32 *)reg_s0)->v = 0;
    ((struct gd_1AC_s32 *)reg_s0)->v = 0;
    ((struct gd_1B0_s32 *)reg_s0)->v = 0;
    ((struct gd_1B4_s32 *)reg_s0)->v = 0;
    D_800A8D3C = 0;
    switch (D_8012EFD0) {
    case 2:
        ((struct gd_1F4_f32 *)reg_s0)->v = -2.0f;
        ((struct gd_EC_s32 *)reg_s0)->v = (s32)&D_8002C1B4;
        ((struct gd_60_f32 *)reg_s0)->v = 75.0f;
        func_80035828(reg_s0, 7);
        break;
    case 18:
        ((struct gd_1F4_f32 *)reg_s0)->v = -2.0f;
        ((struct gd_EC_s32 *)reg_s0)->v = (s32)&D_8002D060;
        ((struct gd_60_f32 *)reg_s0)->v = 125.0f;
        ((struct gd_1C4_f32 *)reg_s0)->v = 2e+01f;
        func_80035828(reg_s0, 16);
        break;
    case 17:
        ((struct gd_1F4_f32 *)reg_s0)->v = -2.0f;
        ((struct gd_EC_s32 *)reg_s0)->v = (s32)&D_8002C1B4;
        ((struct gd_60_f32 *)reg_s0)->v = 75.0f;
        func_80035828(reg_s0, 10);
        break;
    case 15:
        ((struct gd_1F4_f32 *)reg_s0)->v = -2.0f;
        ((struct gd_EC_s32 *)reg_s0)->v = (s32)&D_8002D060;
        ((struct gd_60_f32 *)reg_s0)->v = 175.0f;
        ((struct gd_1C4_f32 *)reg_s0)->v = 2e+01f;
        func_80035828(reg_s0, 12);
        break;
    case 16:
        ((struct gd_1F4_f32 *)reg_s0)->v = -0.5f;
        ((struct gd_EC_s32 *)reg_s0)->v = (s32)&D_8002D060;
        ((struct gd_60_f32 *)reg_s0)->v = 175.0f;
        ((struct gd_1C4_f32 *)reg_s0)->v = 2e+01f;
        func_80035828(reg_s0, 12);
        break;
    case 14:
        ((struct gd_1F4_f32 *)reg_s0)->v = -2.0f;
        ((struct gd_EC_s32 *)reg_s0)->v = (s32)&D_8002D060;
        ((struct gd_60_f32 *)reg_s0)->v = 125.0f;
        ((struct gd_1C4_f32 *)reg_s0)->v = 4e+01f;
        func_80035828(reg_s0, 20);
        break;
    case 13:
        ((struct gd_1F4_f32 *)reg_s0)->v = -5.0f;
        ((struct gd_EC_s32 *)reg_s0)->v = (s32)&D_8002D060;
        ((struct gd_60_f32 *)reg_s0)->v = 175.0f;
        ((struct gd_1C4_f32 *)reg_s0)->v = 2e+01f;
        func_80035828(reg_s0, 24);
        break;
    case 19:
        ((struct gd_EC_s32 *)reg_s0)->v = (s32)&D_8002F274;
        ((struct gd_1F0_s8 *)reg_s0)->v = 0;
        ((struct gd_1F1_s8 *)reg_s0)->v = 0;
        ((struct gd_60_f32 *)reg_s0)->v = 75.0f;
        sp40 = 8.9f;
        sp44 = 84.2f;
        sp48 = -208.3f;
        sp30 = sp40;
        sp34 = sp44;
        sp38 = sp48;
        sp50 = ((struct gd_24_f32 *)reg_s0)->v;
        sp54 = ((struct gd_28_f32 *)reg_s0)->v;
        sp58 = ((struct gd_2C_f32 *)reg_s0)->v;
        sp30 = sp30 - sp50;
        sp34 = sp34 - sp54;
        sp38 = sp38 - sp58;
        sp60 = (f64)sqrtf((((sp30 * sp30) + (sp34 * sp34)) + (sp38 * sp38)));
        if (!(sp60 == 0.0)) {
            sp30 = (f32)(((f64)sp30) * (D_8007A3F8 / sp60));
            sp34 = (f32)(((f64)sp34) * (D_8007A400 / sp60));
            sp38 = (f32)(((f64)sp38) * (D_8007A408 / sp60));
        }
        ((struct gd_30_f32 *)reg_s0)->v = sp30;
        ((struct gd_34_f32 *)reg_s0)->v = sp34;
        ((struct gd_38_f32 *)reg_s0)->v = sp38;
        ((struct gd_48_f32 *)reg_s0)->v = (((struct gd_34_f32 *)reg_s0)->v * ((struct gd_44_f32 *)reg_s0)->v) - (((struct gd_38_f32 *)reg_s0)->v * ((struct gd_40_f32 *)reg_s0)->v);
        ((struct gd_4C_f32 *)reg_s0)->v = (((struct gd_38_f32 *)reg_s0)->v * ((struct gd_3C_f32 *)reg_s0)->v) - (((struct gd_30_f32 *)reg_s0)->v * ((struct gd_44_f32 *)reg_s0)->v);
        ((struct gd_50_f32 *)reg_s0)->v = (((struct gd_30_f32 *)reg_s0)->v * ((struct gd_40_f32 *)reg_s0)->v) - (((struct gd_34_f32 *)reg_s0)->v * ((struct gd_3C_f32 *)reg_s0)->v);
        func_80035828(reg_s0, 28);
        break;
    default:
        ((struct gd_EC_s32 *)reg_s0)->v = (s32)&D_8002C1B4;
        ((struct gd_60_f32 *)reg_s0)->v = 75.0f;
        func_80035828(reg_s0, 7);
        break;
    }
    func_8003FE00(reg_s0, D_8011525C, 4, 0);
    ((struct gd_B8_s32 *)reg_s0)->v = ((struct gd_30_s32 *)reg_s1)->v;
    ((struct gd_8C_s32 *)reg_s0)->v = 0;
    ((struct gd_90_s32 *)reg_s0)->v = -2;
    ((struct gd_BC_s32 *)reg_s0)->v = 0;
    ((struct gd_C0_s32 *)reg_s0)->v = 0;
    ((struct gd_C4_s32 *)reg_s0)->v = reg_s0 + 200;
    ((struct gd_C8_s32 *)reg_s0)->v = 1;
    ((struct gd_CC_s32 *)reg_s0)->v = reg_s0;
    ((struct gd_D0_s32 *)reg_s0)->v = 1;
    ((struct gd_E4_f32 *)reg_s0)->v = ((struct gd_60_f32 *)reg_s0)->v;
    ((struct gd_D8_f32 *)reg_s0)->v = ((struct gd_24_f32 *)reg_s0)->v;
    ((struct gd_DC_f32 *)reg_s0)->v = -((struct gd_2C_f32 *)reg_s0)->v;
    ((struct gd_E0_f32 *)reg_s0)->v = ((struct gd_28_f32 *)reg_s0)->v;
    func_800445D0(((struct gd_B8_s32 *)reg_s0)->v, (reg_s0 + 188), 2, 0);
    func_80017790(reg_s0, 0);
    ((struct gd_228_s16 *)reg_s0)->v = 0xFFFF8000;
    D_80106860 = 0;
    (*(f32 *)&D_80106860) = 1.0f;
    D_80106860 = 0;
}
