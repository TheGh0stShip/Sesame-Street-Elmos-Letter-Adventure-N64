#include "common.h"


void func_8003BB00(s32 arg0) {
    s32 sp18;
    s32 sp1C;
    s32 sp20;
    s32 sp24;
    f32 sp28;
    s32 pad0;
    s32 pad1;
    s32 sp34;
    s32 pad2[4];
    s32 sp48;
    f32 sp4C;
    s32 sp50;
    s32 pad3;
    s32 pad4[20];
    s32 pad5;
    s32 spAC;
    f64 spB0;

    sp18 = arg0;
    sp1C = 0;
    sp20 = 0;
    sp48 = 0;
    sp4C = 1.0f;
    sp50 = 0;
    sp24 = func_80040400(536);
    func_80068300(sp24, 0, 536);
    ((struct gd_8_s16 *)sp24)->v = ((struct gd_2_u16 *)sp18)->v;
    ((struct gd_A_s16 *)sp24)->v = ((struct gd_6_u16 *)sp18)->v;
    ((struct gd_C_s32 *)sp24)->v = ((struct gd_8_s32 *)sp18)->v;
    ((struct gd_1EC_s32 *)sp24)->v = D_80133E34;
    ((struct gd_E0_s32 *)sp24)->v = 0;
    ((struct gd_E4_s32 *)sp24)->v = 0;
    ((struct gd_54_s32 *)sp24)->v = 0;
    if (((((((struct gd_A_u16 *)sp24)->v != 0x2101) && (((struct gd_A_u16 *)sp24)->v != 0x2109)) && (((struct gd_A_u16 *)sp24)->v != 0x4605)) && (((struct gd_A_u16 *)sp24)->v != 0x4606)) && (((struct gd_A_u16 *)sp24)->v != 0x4607)) {
        ((struct gd_1F0_s32 *)sp24)->v = 4;
    } else {
        ((struct gd_1F0_s32 *)sp24)->v = 5;
    }
    switch (((struct gd_A_u16 *)sp24)->v) {
    case 0x6601:
        sp20 = (s32)&D_802870F8;
        sp1C = func_80018530(sp20, ((struct gd_4_u16 *)sp20)->v);
        switch (sp1C) {
        case 0:
            func_80057BD0(((s32)&D_8007AC90), ((s32)&D_8007AC94), 458);
        }
        if (sp1C == 0) {
            return;
        }
        ((struct gd_1BC_s32 *)sp24)->v = (s32)&D_80287120;
        ((struct gd_1D8_s8 *)sp24)->v = 1;
        break;
    case 0x5601:
        sp20 = (s32)&D_802806F0;
        sp1C = func_80018530(sp20, ((struct gd_4_u16 *)sp20)->v);
        switch (sp1C) {
        case 0:
            func_80057BD0(((s32)&D_8007AC90), ((s32)&D_8007AC94), 470);
        }
        if (sp1C == 0) {
            return;
        }
        ((struct gd_1BC_s32 *)sp24)->v = (s32)&D_80280718;
        ((struct gd_1D8_s8 *)sp24)->v = 1;
        break;
    case 0x5602:
        sp20 = (s32)&D_80284938;
        sp1C = func_80018530(sp20, ((struct gd_4_u16 *)sp20)->v);
        switch (sp1C) {
        case 0:
            func_80057BD0(((s32)&D_8007AC90), ((s32)&D_8007AC94), 480);
        }
        if (sp1C == 0) {
            return;
        }
        ((struct gd_1BC_s32 *)sp24)->v = (s32)&D_80284960;
        ((struct gd_1D8_s8 *)sp24)->v = 1;
        break;
    case 0x2106:
        sp20 = (s32)&D_80157BA8;
        sp1C = func_80018530(sp20, ((struct gd_4_u16 *)sp20)->v);
        switch (sp1C) {
        case 0:
            func_80057BD0(((s32)&D_8007AC90), ((s32)&D_8007AC94), 613);
        }
        if (sp1C == 0) {
            return;
        }
        ((struct gd_1BC_s32 *)sp24)->v = (s32)&D_80157BD0;
        ((struct gd_1D8_s8 *)sp24)->v = 1;
        ((struct gd_54_s32 *)sp24)->v = 0;
        break;
    case 0x7602:
        sp20 = (s32)&D_8015F418;
        sp1C = func_80018530(sp20, ((struct gd_4_u16 *)sp20)->v);
        switch (sp1C) {
        case 0:
            func_80057BD0(((s32)&D_8007AC90), ((s32)&D_8007AC94), 624);
        }
        if (sp1C == 0) {
            return;
        }
        ((struct gd_1BC_s32 *)sp24)->v = (s32)&D_8015F440;
        ((struct gd_1D8_s8 *)sp24)->v = 1;
        ((struct gd_54_f32 *)sp24)->v = 5e+01f;
        break;
    case 0x2606:
        sp20 = (s32)&D_8015D950;
        sp1C = func_80018530(sp20, ((struct gd_4_u16 *)sp20)->v);
        switch (sp1C) {
        case 0:
            func_80057BD0(((s32)&D_8007AC90), ((s32)&D_8007AC94), 636);
        }
        if (sp1C == 0) {
            return;
        }
        ((struct gd_1BC_s32 *)sp24)->v = (s32)&D_8015D978;
        ((struct gd_1D8_s8 *)sp24)->v = 4;
        ((struct gd_1DC_s8 *)sp24)->v = 0;
        ((struct gd_1DD_s8 *)sp24)->v = 49;
        ((struct gd_1E0_f32 *)sp24)->v = 5.0f;
        ((struct gd_54_s32 *)sp24)->v = 0;
        break;
    case 0x4605:
        sp20 = (s32)&D_80160A88;
        sp1C = func_80018530(sp20, ((struct gd_4_u16 *)sp20)->v);
        switch (sp1C) {
        case 0:
            func_80057BD0(((s32)&D_8007AC90), ((s32)&D_8007AC94), 652);
        }
        if (sp1C == 0) {
            return;
        }
        ((struct gd_1BC_s32 *)sp24)->v = (s32)&D_80160AB0;
        ((struct gd_1D8_s8 *)sp24)->v = 1;
        ((struct gd_54_f32 *)sp24)->v = 2.5e+02f;
        break;
    case 0x4606:
        sp20 = (s32)&D_80163308;
        sp1C = func_80018530(sp20, ((struct gd_4_u16 *)sp20)->v);
        switch (sp1C) {
        case 0:
            func_80057BD0(((s32)&D_8007AC90), ((s32)&D_8007AC94), 663);
        }
        if (sp1C == 0) {
            return;
        }
        ((struct gd_1BC_s32 *)sp24)->v = (s32)&D_80163330;
        ((struct gd_1D8_s8 *)sp24)->v = 1;
        ((struct gd_54_f32 *)sp24)->v = 2.5e+02f;
        break;
    case 0x4607:
        sp20 = (s32)&D_80165B88;
        sp1C = func_80018530(sp20, ((struct gd_4_u16 *)sp20)->v);
        switch (sp1C) {
        case 0:
            func_80057BD0(((s32)&D_8007AC90), ((s32)&D_8007AC94), 674);
        }
        if (sp1C == 0) {
            return;
        }
        ((struct gd_1BC_s32 *)sp24)->v = (s32)&D_80165BB0;
        ((struct gd_1D8_s8 *)sp24)->v = 1;
        ((struct gd_54_f32 *)sp24)->v = 2.5e+02f;
        break;
    case 0x2104:
        sp20 = (s32)&D_8028ED70;
        sp1C = func_80018530(sp20, ((struct gd_4_u16 *)sp20)->v);
        switch (sp1C) {
        case 0:
            func_80057BD0(((s32)&D_8007AC90), ((s32)&D_8007AC94), 687);
        }
        if (sp1C == 0) {
            return;
        }
        ((struct gd_1BC_s32 *)sp24)->v = (s32)&D_8028ED98;
        ((struct gd_1D8_s8 *)sp24)->v = 1;
        break;
    case 0x2601:
        sp20 = (s32)&D_80163458;
        sp1C = func_80018530(sp20, ((struct gd_4_u16 *)sp20)->v);
        switch (sp1C) {
        case 0:
            func_80057BD0(((s32)&D_8007AC90), ((s32)&D_8007AC94), 700);
        }
        if (sp1C == 0) {
            return;
        }
        ((struct gd_1BC_s32 *)sp24)->v = (s32)&D_80163480;
        ((struct gd_1D8_s8 *)sp24)->v = 1;
        ((struct gd_54_f32 *)sp24)->v = 6e+01f;
        break;
    case 0x3103:
        sp20 = (s32)&D_802A7F70;
        sp1C = func_80018530(sp20, ((struct gd_4_u16 *)sp20)->v);
        switch (sp1C) {
        case 0:
            func_80057BD0(((s32)&D_8007AC90), ((s32)&D_8007AC94), 711);
        }
        if (sp1C == 0) {
            return;
        }
        ((struct gd_1D8_s8 *)sp24)->v = 2;
        ((struct gd_1D9_s8 *)sp24)->v = 1;
        ((struct gd_1DA_s8 *)sp24)->v = 0;
        ((struct gd_1DB_s8 *)sp24)->v = 0;
        spAC = *(s32 *)((((struct gd_1DB_u8 *)sp24)->v * 4) + ((s32)&D_80076B20));
        ((struct gd_1BC_s32 *)sp24)->v = *(s32 *)((((struct gd_1DA_u8 *)sp24)->v * 4) + spAC);
        ((struct gd_54_f32 *)sp24)->v = 6e+01f;
        break;
    case 0x4604:
        sp20 = (s32)&D_8016E460;
        sp1C = func_80018530(sp20, ((struct gd_4_u16 *)sp20)->v);
        switch (sp1C) {
        case 0:
            func_80057BD0(((s32)&D_8007AC90), ((s32)&D_8007AC94), 729);
        }
        if (sp1C == 0) {
            return;
        }
        ((struct gd_1BC_s32 *)sp24)->v = (s32)&D_8016E488;
        ((struct gd_1D8_s8 *)sp24)->v = 1;
        ((struct gd_54_f32 *)sp24)->v = 6e+01f;
        break;
    case 0x4601:
        sp20 = (s32)&D_80173F40;
        sp1C = func_80018530(sp20, ((struct gd_4_u16 *)sp20)->v);
        switch (sp1C) {
        case 0:
            func_80057BD0(((s32)&D_8007AC90), ((s32)&D_8007AC94), 742);
        }
        if (sp1C == 0) {
            return;
        }
        ((struct gd_1BC_s32 *)sp24)->v = (s32)&D_80173F68;
        ((struct gd_1D8_s8 *)sp24)->v = 3;
        ((struct gd_1D9_s8 *)sp24)->v = 1;
        ((struct gd_1DE_s8 *)sp24)->v = 0;
        ((struct gd_1DF_s8 *)sp24)->v = 0;
        ((struct gd_54_f32 *)sp24)->v = 6e+01f;
        D_80076B14 = 1.0f;
        break;
    case 0x3607:
        sp20 = (s32)&D_80160058;
        sp1C = func_80018530(sp20, ((struct gd_4_u16 *)sp20)->v);
        switch (sp1C) {
        case 0:
            func_80057BD0(((s32)&D_8007AC90), ((s32)&D_8007AC94), 758);
        }
        if (sp1C == 0) {
            return;
        }
        ((struct gd_1BC_s32 *)sp24)->v = (s32)&D_80160080;
        ((struct gd_1D8_s8 *)sp24)->v = 1;
        ((struct gd_54_f32 *)sp24)->v = 8e+01f;
        break;
    case 0x2108:
        sp20 = (s32)&D_8015EA10;
        sp1C = func_80018530(sp20, ((struct gd_4_u16 *)sp20)->v);
        switch (sp1C) {
        case 0:
            func_80057BD0(((s32)&D_8007AC90), ((s32)&D_8007AC94), 770);
        }
        if (sp1C == 0) {
            return;
        }
        ((struct gd_1BC_s32 *)sp24)->v = (s32)&D_8015EA38;
        ((struct gd_1D8_s8 *)sp24)->v = 1;
        break;
    case 0x2101:
        sp20 = (s32)&D_802990C0;
        sp1C = func_80018530(sp20, ((struct gd_4_u16 *)sp20)->v);
        switch (sp1C) {
        case 0:
            func_80057BD0(((s32)&D_8007AC90), ((s32)&D_8007AC94), 786);
        }
        if (sp1C == 0) {
            return;
        }
        ((struct gd_1BC_s32 *)sp24)->v = (s32)&D_80299110;
        ((struct gd_1D8_s8 *)sp24)->v = 1;
        break;
    case 0x2109:
        sp20 = (s32)&D_8015C0A0;
        sp1C = func_80018530(sp20, ((struct gd_4_u16 *)sp20)->v);
        switch (sp1C) {
        case 0:
            func_80057BD0(((s32)&D_8007AC90), ((s32)&D_8007AC94), 797);
        }
        if (sp1C == 0) {
            return;
        }
        ((struct gd_1BC_s32 *)sp24)->v = (s32)&D_8015C0C8;
        ((struct gd_1D8_s8 *)sp24)->v = 1;
        break;
    case 0x4603:
        sp20 = (s32)&D_80169F00;
        sp1C = func_80018530(sp20, ((struct gd_4_u16 *)sp20)->v);
        switch (sp1C) {
        case 0:
            func_80057BD0(((s32)&D_8007AC90), ((s32)&D_8007AC94), 808);
        }
        if (sp1C == 0) {
            return;
        }
        ((struct gd_1BC_s32 *)sp24)->v = (s32)&D_80169F28;
        ((struct gd_1D8_s8 *)sp24)->v = 4;
        ((struct gd_1DC_s8 *)sp24)->v = 0;
        ((struct gd_1DD_s8 *)sp24)->v = 5;
        ((struct gd_1E0_f32 *)sp24)->v = 2e+01f;
        ((struct gd_54_s32 *)sp24)->v = 0;
        break;
    case 0x2605:
        sp20 = (s32)&D_8015B0D8;
        sp1C = func_80018530(sp20, ((struct gd_4_u16 *)sp20)->v);
        switch (sp1C) {
        case 0:
            func_80057BD0(((s32)&D_8007AC90), ((s32)&D_8007AC94), 822);
        }
        if (sp1C == 0) {
            return;
        }
        ((struct gd_1BC_s32 *)sp24)->v = (s32)&D_8015B100;
        ((struct gd_1D8_s8 *)sp24)->v = 4;
        ((struct gd_1DC_s8 *)sp24)->v = 0;
        ((struct gd_1DD_s8 *)sp24)->v = 59;
        ((struct gd_1E0_f32 *)sp24)->v = 5.0f;
        ((struct gd_54_s32 *)sp24)->v = 0;
        break;
    case 0x4101:
        sp20 = (s32)&D_8015DD20;
        sp1C = func_80018530(sp20, ((struct gd_4_u16 *)sp20)->v);
        switch (sp1C) {
        case 0:
            func_80057BD0(((s32)&D_8007AC90), ((s32)&D_8007AC94), 836);
        }
        if (sp1C == 0) {
            return;
        }
        ((struct gd_1BC_s32 *)sp24)->v = (s32)&D_8015DD48;
        ((struct gd_1D8_s8 *)sp24)->v = 4;
        ((struct gd_1DC_s8 *)sp24)->v = 0;
        ((struct gd_1DD_s8 *)sp24)->v = 51;
        ((struct gd_1E0_f32 *)sp24)->v = 15.0f;
        ((struct gd_54_s32 *)sp24)->v = 0;
        break;
    default:
        break;
    }
    if (((struct gd_20_s32 *)sp1C)->v != 0) {
        sp34 = func_80040400(((struct gd_20_s32 *)sp1C)->v);
        ((struct gd_10_s32 *)sp1C)->v = sp34;
        ((struct gd_18_s32 *)sp1C)->v = sp34 + (((struct gd_4_u16 *)sp1C)->v << 4);
        func_80068300(((struct gd_18_s32 *)sp1C)->v, 0, ((struct gd_20_s32 *)sp1C)->v);
        func_80000EDC(((struct gd_10_s32 *)sp1C)->v, ((struct gd_C_s32 *)sp1C)->v, (((struct gd_4_u16 *)sp1C)->v * 4));
    }
    ((struct gd_10_s32 *)sp24)->v = (s32)&D_8003CF50;
    ((struct gd_14_s32 *)sp24)->v = (s32)&D_8003E3A0;
    ((struct gd_1A8_f32 *)sp24)->v = 1.0f;
    ((struct gd_1AC_f32 *)sp24)->v = 1.0f;
    ((struct gd_1B0_f32 *)sp24)->v = 1.0f;
    ((struct gd_1B8_s32 *)sp24)->v = 0;
    ((struct gd_1B4_s32 *)sp24)->v = 0;
    ((struct gd_1D4_s8 *)sp24)->v = 0;
    ((struct gd_1DF_s8 *)sp24)->v = 0;
    ((struct gd_1E8_s32 *)sp24)->v = sp1C;
    ((struct gd_24_f32 *)sp24)->v = ((struct gd_C_f32 *)sp18)->v;
    ((struct gd_28_f32 *)sp24)->v = ((struct gd_10_f32 *)sp18)->v;
    ((struct gd_2C_f32 *)sp24)->v = ((struct gd_14_f32 *)sp18)->v;
    ((struct gd_30_f32 *)sp24)->v = ((struct gd_18_f32 *)sp18)->v;
    ((struct gd_34_f32 *)sp24)->v = ((struct gd_1C_f32 *)sp18)->v;
    ((struct gd_38_f32 *)sp24)->v = ((struct gd_20_f32 *)sp18)->v;
    sp28 = sqrtf((((((struct gd_30_f32 *)sp24)->v * ((struct gd_30_f32 *)sp24)->v) + (((struct gd_34_f32 *)sp24)->v * ((struct gd_34_f32 *)sp24)->v)) + (((struct gd_38_f32 *)sp24)->v * ((struct gd_38_f32 *)sp24)->v)));
    if (sp28 >= 1e-07f) {
        spB0 = D_8007ACA8 / ((f64)sp28);
        ((struct gd_30_f32 *)sp24)->v = (f32)(((f64)((struct gd_30_f32 *)sp24)->v) * spB0);
        ((struct gd_34_f32 *)sp24)->v = (f32)(((f64)((struct gd_34_f32 *)sp24)->v) * spB0);
        ((struct gd_38_f32 *)sp24)->v = (f32)(((f64)((struct gd_38_f32 *)sp24)->v) * spB0);
    } else {
    }
    ((struct gd_3C_f32 *)sp24)->v = ((struct gd_24_f32 *)sp18)->v;
    ((struct gd_40_f32 *)sp24)->v = ((struct gd_28_f32 *)sp18)->v;
    ((struct gd_44_f32 *)sp24)->v = ((struct gd_2C_f32 *)sp18)->v;
    sp28 = sqrtf((((((struct gd_3C_f32 *)sp24)->v * ((struct gd_3C_f32 *)sp24)->v) + (((struct gd_40_f32 *)sp24)->v * ((struct gd_40_f32 *)sp24)->v)) + (((struct gd_44_f32 *)sp24)->v * ((struct gd_44_f32 *)sp24)->v)));
    if (sp28 >= 1e-07f) {
        spB0 = D_8007ACB0 / ((f64)sp28);
        ((struct gd_3C_f32 *)sp24)->v = (f32)(((f64)((struct gd_3C_f32 *)sp24)->v) * spB0);
        ((struct gd_40_f32 *)sp24)->v = (f32)(((f64)((struct gd_40_f32 *)sp24)->v) * spB0);
        ((struct gd_44_f32 *)sp24)->v = (f32)(((f64)((struct gd_44_f32 *)sp24)->v) * spB0);
    } else {
    }
    ((struct gd_48_f32 *)sp24)->v = (((struct gd_34_f32 *)sp24)->v * ((struct gd_44_f32 *)sp24)->v) - (((struct gd_38_f32 *)sp24)->v * ((struct gd_40_f32 *)sp24)->v);
    ((struct gd_4C_f32 *)sp24)->v = (((struct gd_38_f32 *)sp24)->v * ((struct gd_3C_f32 *)sp24)->v) - (((struct gd_30_f32 *)sp24)->v * ((struct gd_44_f32 *)sp24)->v);
    ((struct gd_50_f32 *)sp24)->v = (((struct gd_30_f32 *)sp24)->v * ((struct gd_40_f32 *)sp24)->v) - (((struct gd_34_f32 *)sp24)->v * ((struct gd_3C_f32 *)sp24)->v);
    func_8001DE6C((sp24 + 360), (sp18 + 12), (sp18 + 24), (sp18 + 36), (sp24 + 72));
    if (((struct gd_A_u16 *)sp24)->v == 0x4601) {
        ((struct gd_1E0_f32 *)sp24)->v = ((struct gd_28_f32 *)sp24)->v;
    }
    ((struct gd_1C4_s32 *)sp24)->v = 0;
    func_8003FE00(sp24, D_8011525C, 4, 0);
    return;
}
