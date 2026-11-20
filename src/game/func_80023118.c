#include "common.h"


void func_80023118(s32 arg0) {
    s32 sp20;
    s32 sp24;
    s32 sp28;
    f32 sp2C;
    s32 sp30;
    s32 pad0;
    s32 sp38;
    s32 pad1;
    s32 pad2[4];
    s32 sp50;
    f32 sp54;
    s32 sp58;
    s32 pad3;
    s32 pad4[16];
    f32 spA0;
    f32 spA4;
    f32 spA8;
    s32 pad5;
    f32 spB0;
    f32 spB4;
    f32 spB8;
    s32 pad6;
    f32 spC0;
    f32 spC4;
    f32 spC8;
    s32 pad7;
    s32 spD0;
    s32 spD4;
    s32 spD8;
    s32 spDC;
    s32 spE0;
    s32 spE4;
    s32 spE8;
    f32 spEC;
    f64 spF0;

    sp20 = arg0;
    sp50 = 0;
    sp54 = 1.0f;
    sp58 = 0;
    sp28 = func_80040400(536);
    func_80068300(sp28, 0, 536);
    ((struct gd_8_s16 *)sp28)->v = ((struct gd_2_u16 *)sp20)->v;
    ((struct gd_A_s16 *)sp28)->v = ((struct gd_6_u16 *)sp20)->v;
    ((struct gd_C_s32 *)sp28)->v = ((struct gd_8_s32 *)sp20)->v;
    ((struct gd_1EC_s32 *)sp28)->v = D_80133E34;
    ((struct gd_E0_s32 *)sp28)->v = 0;
    ((struct gd_E4_s32 *)sp28)->v = 0;
    if (((struct gd_A_u16 *)sp28)->v == 0x2005) {
        ((struct gd_1F0_s32 *)sp28)->v = 5;
    } else {
        ((struct gd_1F0_s32 *)sp28)->v = 4;
    }
    ((struct gd_10_s32 *)sp28)->v = (s32)&D_800243AC;
    ((struct gd_14_s32 *)sp28)->v = (s32)&D_80024DB0;
    ((struct gd_1D4_s32 *)sp28)->v = 0;
    ((struct gd_1D8_s32 *)sp28)->v = 0;
    ((struct gd_1DC_s32 *)sp28)->v = 0;
    ((struct gd_1E0_s32 *)sp28)->v = 0;
    ((struct gd_54_s32 *)sp28)->v = 0;
    sp24 = 0;
    spD4 = 0;
    spEC = 0;
    switch (((struct gd_A_u16 *)sp28)->v) {
    case 0x1014:
        sp24 = 0;
        ((struct gd_54_f32 *)sp28)->v = 2.5e+02f;
        break;
    case 0x1016:
        sp24 = 0;
        ((struct gd_54_f32 *)sp28)->v = 7e+01f;
        break;
    case 0x1502:
        sp24 = (s32)&D_8029E244;
        break;
    case 0x3002:
        sp24 = (s32)&D_8027E330;
        spD4 = (s32)&D_80276850;
        break;
    case 0x5501:
        sp24 = (s32)&D_80272A88;
        spD4 = (s32)&D_80271460;
        break;
    case 0x5505:
        sp24 = (s32)&D_80292EF8;
        ((struct gd_54_f32 *)sp28)->v = 44.0f;
        break;
    case 0x1015:
        sp24 = (s32)&D_801AA230;
        spD4 = (s32)&D_801AA110;
        break;
    case 0x1501:
        sp24 = (s32)&D_801AA640;
        spD4 = (s32)&D_801A9C8C;
        break;
    case 0x2002:
        sp24 = (s32)&D_801566E0;
        break;
    case 0x2003:
        sp24 = (s32)&D_801576B0;
        break;
    case 0x2004:
        sp24 = (s32)&D_80158680;
        break;
    case 0x2005:
        sp24 = (s32)&D_801AA640;
        break;
    case 0x2006:
        sp24 = (s32)&D_801622D0;
        break;
    case 0x2009:
        sp24 = (s32)&D_80173120;
        break;
    case 0x2107:
        sp24 = (s32)&D_80296AC0;
        ((struct gd_10_s32 *)sp28)->v = (s32)&D_80024A5C;
        D_8011537C = 0;
        break;
    case 0x2503:
        sp24 = (s32)&D_80154B70;
        break;
    case 0x2504:
        sp24 = (s32)&D_80155710;
        break;
    case 0x2505:
        sp24 = (s32)&D_801791A0;
        break;
    case 0x3003:
        sp24 = (s32)&D_8015ACC8;
        ((struct gd_54_f32 *)sp28)->v = 44.0f;
        break;
    case 0x3004:
        sp24 = (s32)&D_80156428;
        ((struct gd_54_f32 *)sp28)->v = 44.0f;
        break;
    case 0x4001:
        sp24 = (s32)&D_8017DCA8;
        break;
    case 0x4002:
        sp24 = (s32)&D_80182DAC;
        break;
    case 0x4003:
        sp24 = (s32)&D_80188E20;
        ((struct gd_10_s32 *)sp28)->v = (s32)&D_80024A5C;
        D_8011537C = 0;
        break;
    case 0x4004:
        sp24 = 0;
        ((struct gd_54_f32 *)sp28)->v = 3e+02f;
        break;
    case 0x4005:
        sp24 = 0;
        ((struct gd_54_f32 *)sp28)->v = 3.6e+02f;
        break;
    case 0x4006:
        sp24 = 0;
        ((struct gd_54_f32 *)sp28)->v = 525.0f;
        break;
    case 0x4007:
        sp24 = 0;
        ((struct gd_54_f32 *)sp28)->v = 1.06e+03f;
        break;
    case 0x4008:
        sp24 = 0;
        ((struct gd_54_f32 *)sp28)->v = 2e+02f;
        break;
    case 0x4609:
        sp24 = (s32)&D_8018CEC0;
        break;
    case 0x5504:
        sp24 = (s32)&D_80158878;
        ((struct gd_54_f32 *)sp28)->v = 44.0f;
        break;
    case 0x5506:
        sp24 = (s32)&D_8015D118;
        ((struct gd_54_f32 *)sp28)->v = 44.0f;
        break;
    case 0x3503:
        sp24 = (s32)&D_80155CB0;
        ((struct gd_54_f32 *)sp28)->v = 2e+01f;
        break;
    case 0x3505:
        sp24 = (s32)&D_801580A0;
        ((struct gd_54_f32 *)sp28)->v = 2e+01f;
        break;
    }
    if (sp24 != 0) {
        if (((struct gd_20_s32 *)sp24)->v != 0) {
            sp38 = func_80040400(((struct gd_20_s32 *)sp24)->v);
            ((struct gd_10_s32 *)sp24)->v = sp38;
            ((struct gd_18_s32 *)sp24)->v = sp38 + (((struct gd_4_u16 *)sp24)->v << 4);
            func_80068300(((struct gd_18_s32 *)sp24)->v, 0, ((struct gd_20_s32 *)sp24)->v);
            func_80000EDC(((struct gd_10_s32 *)sp24)->v, ((struct gd_C_s32 *)sp24)->v, (((struct gd_4_u16 *)sp24)->v * 4));
        }
    }
    ((struct gd_1A8_f32 *)sp28)->v = 1.0f;
    ((struct gd_1AC_f32 *)sp28)->v = 1.0f;
    ((struct gd_1B0_f32 *)sp28)->v = 1.0f;
    ((struct gd_1B8_s32 *)sp28)->v = 0;
    ((struct gd_1E8_s32 *)sp28)->v = sp24;
    ((struct gd_24_f32 *)sp28)->v = ((struct gd_C_f32 *)sp20)->v;
    ((struct gd_28_f32 *)sp28)->v = ((struct gd_10_f32 *)sp20)->v;
    ((struct gd_2C_f32 *)sp28)->v = ((struct gd_14_f32 *)sp20)->v;
    ((struct gd_30_f32 *)sp28)->v = ((struct gd_18_f32 *)sp20)->v;
    ((struct gd_34_f32 *)sp28)->v = ((struct gd_1C_f32 *)sp20)->v;
    ((struct gd_38_f32 *)sp28)->v = ((struct gd_20_f32 *)sp20)->v;
    sp2C = sqrtf((((((struct gd_30_f32 *)sp28)->v * ((struct gd_30_f32 *)sp28)->v) + (((struct gd_34_f32 *)sp28)->v * ((struct gd_34_f32 *)sp28)->v)) + (((struct gd_38_f32 *)sp28)->v * ((struct gd_38_f32 *)sp28)->v)));
    if (sp2C >= 1e-07f) {
        spF0 = D_8007A030 / ((f64)sp2C);
        ((struct gd_30_f32 *)sp28)->v = (f32)(((f64)((struct gd_30_f32 *)sp28)->v) * spF0);
        ((struct gd_34_f32 *)sp28)->v = (f32)(((f64)((struct gd_34_f32 *)sp28)->v) * spF0);
        ((struct gd_38_f32 *)sp28)->v = (f32)(((f64)((struct gd_38_f32 *)sp28)->v) * spF0);
    } else {
    }
    ((struct gd_3C_f32 *)sp28)->v = ((struct gd_24_f32 *)sp20)->v;
    ((struct gd_40_f32 *)sp28)->v = ((struct gd_28_f32 *)sp20)->v;
    ((struct gd_44_f32 *)sp28)->v = ((struct gd_2C_f32 *)sp20)->v;
    sp2C = sqrtf((((((struct gd_3C_f32 *)sp28)->v * ((struct gd_3C_f32 *)sp28)->v) + (((struct gd_40_f32 *)sp28)->v * ((struct gd_40_f32 *)sp28)->v)) + (((struct gd_44_f32 *)sp28)->v * ((struct gd_44_f32 *)sp28)->v)));
    if (sp2C >= 1e-07f) {
        spF0 = D_8007A038 / ((f64)sp2C);
        ((struct gd_3C_f32 *)sp28)->v = (f32)(((f64)((struct gd_3C_f32 *)sp28)->v) * spF0);
        ((struct gd_40_f32 *)sp28)->v = (f32)(((f64)((struct gd_40_f32 *)sp28)->v) * spF0);
        ((struct gd_44_f32 *)sp28)->v = (f32)(((f64)((struct gd_44_f32 *)sp28)->v) * spF0);
    } else {
    }
    ((struct gd_48_f32 *)sp28)->v = (((struct gd_34_f32 *)sp28)->v * ((struct gd_44_f32 *)sp28)->v) - (((struct gd_38_f32 *)sp28)->v * ((struct gd_40_f32 *)sp28)->v);
    ((struct gd_4C_f32 *)sp28)->v = (((struct gd_38_f32 *)sp28)->v * ((struct gd_3C_f32 *)sp28)->v) - (((struct gd_30_f32 *)sp28)->v * ((struct gd_44_f32 *)sp28)->v);
    ((struct gd_50_f32 *)sp28)->v = (((struct gd_30_f32 *)sp28)->v * ((struct gd_40_f32 *)sp28)->v) - (((struct gd_34_f32 *)sp28)->v * ((struct gd_3C_f32 *)sp28)->v);
    func_8001DE6C((sp28 + 360), (sp20 + 12), (sp20 + 24), (sp20 + 36), (sp28 + 72));
    ((struct gd_1C4_s32 *)sp28)->v = 0;
    func_8003FE00(sp28, D_8011525C, 4, 0);
    if (!(spEC == 0.0f)) {
        ((struct gd_B0_s32 *)sp28)->v = ((struct gd_30_s32 *)sp20)->v;
        ((struct gd_58_f32 *)sp28)->v = spEC;
        ((struct gd_84_s32 *)sp28)->v = 1;
        ((struct gd_88_s32 *)sp28)->v = 0;
        ((struct gd_B4_s32 *)sp28)->v = 0;
        ((struct gd_B8_s32 *)sp28)->v = 0;
        ((struct gd_BC_s32 *)sp28)->v = sp28 + 192;
        ((struct gd_C0_s32 *)sp28)->v = 1;
        ((struct gd_C4_s32 *)sp28)->v = sp28;
        ((struct gd_C8_s32 *)sp28)->v = 16;
        ((struct gd_DC_f32 *)sp28)->v = ((struct gd_58_f32 *)sp28)->v;
        ((struct gd_D0_f32 *)sp28)->v = ((struct gd_24_f32 *)sp28)->v;
        ((struct gd_D4_f32 *)sp28)->v = -((struct gd_2C_f32 *)sp28)->v;
        ((struct gd_D8_f32 *)sp28)->v = ((struct gd_28_f32 *)sp28)->v;
        func_800445D0(((struct gd_B0_s32 *)sp28)->v, (sp28 + 180), 2, 0);
    } else {
        if (spD4 != 0) {
            spD0 = *(s32 *)((struct gd_4_s32 *)spD4)->v;
            ((struct gd_B0_s32 *)sp28)->v = ((struct gd_30_s32 *)arg0)->v;
            spA0 = ((struct gd_24_f32 *)sp28)->v;
            spA4 = -((struct gd_2C_f32 *)sp28)->v;
            spA8 = ((struct gd_28_f32 *)sp28)->v;
            spB0 = ((struct gd_30_f32 *)sp28)->v;
            spB4 = -((struct gd_38_f32 *)sp28)->v;
            spB8 = ((struct gd_34_f32 *)sp28)->v;
            spE8 = (*(s32 *)spD4) * 12;
            spDC = func_80040400(spE8);
            switch (spDC) {
            case 0:
                func_80057BD0(((s32)&D_8007A018), ((s32)&D_8007A01C), 831);
            }
            ((struct gd_E0_s32 *)sp28)->v = spDC;
            spE8 = (*(s32 *)spD4) * 80;
            spE4 = func_80040400(spE8);
            switch (spE4) {
            case 0:
                func_80057BD0(((s32)&D_8007A018), ((s32)&D_8007A01C), 838);
            }
            ((struct gd_E4_s32 *)sp28)->v = spE4;
            sp30 = 0;
            while (!(sp30 >= (*(s32 *)spD4))) {
                spD8 = spDC + (sp30 * 12);
                spE0 = spE4 + (sp30 * 80);
                (*(s32 *)spD8) = 0;
                ((struct gd_4_s32 *)spD8)->v = 0;
                ((struct gd_8_s32 *)spD8)->v = spE0;
                (*(s32 *)spE0) = 3;
                ((struct gd_4_s32 *)spE0)->v = sp28;
                ((struct gd_8_s32 *)spE0)->v = 0x2000000;
                spA0 = *(f32 *)(sp28 + 36);
                spA4 = ((struct gd_4_f32 *)(sp28 + 36))->v;
                spA8 = ((struct gd_8_f32 *)(sp28 + 36))->v;
                spC0 = ((struct gd_20_f32 *)((sp30 * 80) + spD0))->v;
                spC4 = ((struct gd_28_f32 *)((sp30 * 80) + spD0))->v;
                spC8 = -((struct gd_24_f32 *)((sp30 * 80) + spD0))->v;
                guMtxXFMF((sp28 + 360), spC0, spC4, spC8, ((s32)&spA0), (((s32)&spA0) + 4), (((s32)&spA0) + 8));
                ((struct gd_2C_f32 *)spE0)->v = spA0;
                ((struct gd_30_f32 *)spE0)->v = -spA8;
                ((struct gd_34_f32 *)spE0)->v = spA4;
                spA0 = *(f32 *)(sp28 + 36);
                spA4 = ((struct gd_4_f32 *)(sp28 + 36))->v;
                spA8 = ((struct gd_8_f32 *)(sp28 + 36))->v;
                spC0 = ((struct gd_38_f32 *)((sp30 * 80) + spD0))->v;
                spC4 = ((struct gd_40_f32 *)((sp30 * 80) + spD0))->v;
                spC8 = -((struct gd_3C_f32 *)((sp30 * 80) + spD0))->v;
                guMtxXFMF((sp28 + 360), spC0, spC4, spC8, ((s32)&spA0), (((s32)&spA0) + 4), (((s32)&spA0) + 8));
                ((struct gd_20_f32 *)spE0)->v = spA0;
                ((struct gd_24_f32 *)spE0)->v = -spA8;
                ((struct gd_28_f32 *)spE0)->v = spA4;
                spA0 = *(f32 *)(sp28 + 36);
                spA4 = ((struct gd_4_f32 *)(sp28 + 36))->v;
                spA8 = ((struct gd_8_f32 *)(sp28 + 36))->v;
                spC0 = ((struct gd_2C_f32 *)((sp30 * 80) + spD0))->v;
                spC4 = ((struct gd_34_f32 *)((sp30 * 80) + spD0))->v;
                spC8 = -((struct gd_30_f32 *)((sp30 * 80) + spD0))->v;
                guMtxXFMF((sp28 + 360), spC0, spC4, spC8, ((s32)&spA0), (((s32)&spA0) + 4), (((s32)&spA0) + 8));
                ((struct gd_44_f32 *)spE0)->v = spA0;
                ((struct gd_48_f32 *)spE0)->v = -spA8;
                ((struct gd_4C_f32 *)spE0)->v = spA4;
                spA0 = *(f32 *)(sp28 + 36);
                spA4 = ((struct gd_4_f32 *)(sp28 + 36))->v;
                spA8 = ((struct gd_8_f32 *)(sp28 + 36))->v;
                spC0 = ((struct gd_44_f32 *)((sp30 * 80) + spD0))->v;
                spC4 = ((struct gd_4C_f32 *)((sp30 * 80) + spD0))->v;
                spC8 = -((struct gd_48_f32 *)((sp30 * 80) + spD0))->v;
                guMtxXFMF((sp28 + 360), spC0, spC4, spC8, ((s32)&spA0), (((s32)&spA0) + 4), (((s32)&spA0) + 8));
                ((struct gd_38_f32 *)spE0)->v = spA0;
                ((struct gd_3C_f32 *)spE0)->v = -spA8;
                ((struct gd_40_f32 *)spE0)->v = spA4;
                func_80020A24(spE0, (spE0 + 32), (spE0 + 44), (spE0 + 56), (spE0 + 68));
                func_800445D0(((struct gd_B0_s32 *)sp28)->v, spD8, 2, 0);
                sp30++;
            }
        }
    }
    return;
}
