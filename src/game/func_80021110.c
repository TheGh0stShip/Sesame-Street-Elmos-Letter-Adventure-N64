#include "common.h"

s32 func_80049ABC(s32, s32, s32, s32, s32, f32);
s32 func_8004A150(s32, s32, f32, s32, f32, f32, f32);

void func_80021110(s32 arg0) {
    s32 sp28;
    s32 pad0;
    s32 pad1[2];
    f32 sp38;
    f32 sp3C;
    f32 sp40;
    s32 pad2;
    f32 sp48;
    s32 sp4C;
    s32 sp50;
    s32 pad3;
    f32 sp58;
    f32 sp5C;
    f32 sp60;
    s32 pad4;
    f32 sp68;
    f32 sp6C;
    f32 sp70;
    s32 pad5;
    f32 sp78;
    f32 sp7C;
    f32 sp80;
    s32 pad6;
    s32 sp88;
    s32 sp8C;
    s32 sp90;
    s32 sp94;
    s32 pad7;
    s32 sp9C;
    s32 pad8[4];
    f32 spB0;

    sp28 = arg0;
    if ((*(s32 *)sp28) == 1) {
        goto L13;
    }
    func_80057BD0(((s32)&D_80079F30), ((s32)&D_80079F34), 62);
L13: ;
    if (D_8012EFD0 == 11) {
        func_80030A7C(arg0);
        return;
    }
    if (D_8012EFD0 == 19) {
        func_800314C0(arg0);
        return;
    }
    D_80075C20 = func_80040400(180);
    func_80068300(D_80075C20, 0, 180);
    ((struct gd_8_s16 *)D_80075C20)->v = ((struct gd_2_u16 *)sp28)->v;
    ((struct gd_A_s16 *)D_80075C20)->v = ((struct gd_6_u16 *)sp28)->v;
    ((struct gd_C_s32 *)D_80075C20)->v = ((struct gd_8_s32 *)sp28)->v;
    ((struct gd_14_s32 *)D_80075C20)->v = (s32)&D_80022ADC;
    ((struct gd_18_s32 *)D_80075C20)->v = 0;
    ((struct gd_1C_s32 *)D_80075C20)->v = 0;
    ((struct gd_20_s32 *)D_80075C20)->v = 0;
    ((struct gd_10_s32 *)D_80075C20)->v = (s32)&D_80022A40;
    func_8003FE00(D_80075C20, D_8011525C, 3, 0);
    D_80112CD0 = 0;
    D_80133E3C = 0;
    D_8012FCC0 = 0;
    D_80115380 = 0;
    D_800ACC00 = 0;
    D_800AEC40 = 0;
    D_800A7AAC = 0;
    sp38 = ((struct gd_C_f32 *)sp28)->v;
    sp3C = ((struct gd_10_f32 *)sp28)->v;
    sp40 = ((struct gd_14_f32 *)sp28)->v;
    sp48 = (f32)func_80067FB0(((f64)((struct gd_20_f32 *)sp28)->v), ((f64)((struct gd_18_f32 *)sp28)->v));
    sp4C = 0;
    sp50 = 0;
    sp78 = ((struct gd_18_f32 *)sp28)->v;
    sp7C = ((struct gd_1C_f32 *)sp28)->v;
    sp80 = ((struct gd_20_f32 *)sp28)->v;
    switch (D_8012EFD0) {
    case 10:
        spB0 = 9e+02f;
        break;
    case 5:
        spB0 = 1.08e+03f;
        break;
    case 6:
        spB0 = 9e+02f;
        break;
    case 8:
        spB0 = 5.5e+02f;
        break;
    case 13:
        spB0 = 8.3e+02f;
        break;
    case 14:
        spB0 = 8.2e+02f;
        break;
    case 15:
    case 16:
        spB0 = 7.2e+02f;
        break;
    case 1:
    case 2:
        spB0 = 6.5e+02f;
        break;
    case 17:
        spB0 = 7e+02f;
        break;
    case 18:
        spB0 = 6.5e+02f;
        break;
    default:
        spB0 = 6e+02f;
        break;
    }
    D_80112CD0 = func_80047FB0(((s32)&sp38), ((s32)&sp48), spB0, ((f32)(*(s32 *)((D_8012EFD0 * 4) + ((s32)&D_80074580)))));
    switch (D_8012EFD0) {
    case 13:
        D_80133E3C = func_8004A150(D_80112CD0, 0, spB0, 0x430C0000, -2e+01f, 2e+01f, 0.4f);
        break;
    case 14:
        D_80133E3C = func_8004A150(D_80112CD0, 0x3F000000, spB0, 0x42F00000, 2e+01f, 24.0f, -0.4f);
        break;
    case 15:
    case 16:
        D_80133E3C = func_8004A150(D_80112CD0, 0x3F000000, spB0, 0x42700000, 5e+01f, 2e+01f, 0.4f);
        break;
    case 2:
        D_80133E3C = func_8004A150(D_80112CD0, 0x3F000000, spB0, 0x42C80000, 1.2e+02f, 24.0f, 0.0f);
        break;
    case 19:
        D_80133E3C = func_8004A150(D_80112CD0, 0x3F000000, spB0, 0x42C80000, 5e+01f, 24.0f, 0.0f);
        break;
    case 17:
        D_80133E3C = func_8004A150(D_80112CD0, 0, spB0, 0x42F00000, 7e+01f, 2e+01f, 0.4f);
        break;
    default:
        D_80133E3C = func_8004A150(D_80112CD0, 0x3F000000, spB0, 0x428C0000, 5e+01f, 24.0f, 0.4f);
        break;
    }
    sp88 = func_80049848(D_80112CD0, D_80133E3C, ((s32)&D_8004A38C), ((s32)&D_8004A6A0), 10, 1.0f);
    func_8004A294(D_80133E3C, ((s32)&sp38), ((s32)&sp78));
    D_8012FCC0 = func_8004A6E4(D_80112CD0);
    sp8C = func_80049848(D_80112CD0, D_8012FCC0, ((s32)&D_8004A73C), ((s32)&D_8004B074), 20, 1.0f);
    D_80115380 = func_8004B234(D_80112CD0);
    sp90 = func_80049848(D_80112CD0, D_80115380, ((s32)&D_8004B28C), ((s32)&D_8004B524), 30, 1.0f);
    switch (D_8012EFD0) {
    case 18:
        break;
    case 13:
    case 14:
        D_800ACC00 = ((s32 (*)())func_8004B568)(D_80112CD0, 0x447A0000, 0x3E4CCCCD, 0x447A0000);
        sp94 = func_80049848(D_80112CD0, D_800ACC00, ((s32)&D_8004B5E8), ((s32)&D_8004B93C), 50, 1.0f);
        break;
    case 2:
        D_800ACC00 = ((s32 (*)())func_8004B568)(D_80112CD0, 0x42200000, 0x3D23D70A, 0x420C0000);
        sp94 = func_80049848(D_80112CD0, D_800ACC00, ((s32)&D_8004B5E8), ((s32)&D_8004B93C), 50, 1.0f);
        break;
    default:
        D_800ACC00 = ((s32 (*)())func_8004B568)(D_80112CD0, 0x42200000, 0x3F000000, 0x420C0000);
        sp94 = func_80049848(D_80112CD0, D_800ACC00, ((s32)&D_8004B5E8), ((s32)&D_8004B93C), 50, 1.0f);
        break;
    }
    D_800AEC40 = func_8004B980(D_80112CD0, arg0, ((s32)&sp38), 170);
    if (D_8012EFD0 != 1) {
        if (D_8012EFD0 != 2) {
            if (D_8012EFD0 != 11) {
                D_800A7AAC = func_8004C0B0(D_80112CD0);
                sp9C = func_80049848(D_80112CD0, D_800A7AAC, ((s32)&D_8004C10C), ((s32)&D_8004C44C), 70, 1.0f);
            }
        }
    }
    if ((D_8012EFD0 == 1) || (D_8012EFD0 == 2)) {
        sp58 = 1.6e+03f;
        sp60 = -1.2e+03f;
        sp5C = 5e+02f;
        func_8004B0E0(D_8012FCC0, 2, 1, ((s32)&sp58), ((s32)&sp58), 2e+04f, 2e+04f, 2e+04f, 0);
        func_80049ABC(D_80112CD0, ((s32)&sp58), 0, 1, 0, 1e+03f);
        sp58 = 2e+01f;
        sp60 = -555.0f;
        sp5C = 1e+02f;
        sp68 = 2e+01f;
        sp70 = -4.8e+02f;
        sp6C = 1e+02f;
        func_8004B0E0(D_8012FCC0, 2, 2, ((s32)&sp58), ((s32)&sp68), 1.5e+02f, 2e+02f, 5e+01f, 0);
        sp68 = 2e+01f;
        sp70 = -5.3e+02f;
        sp6C = 1e+02f;
        func_8004B0E0(D_8012FCC0, 2, 3, ((s32)&sp58), ((s32)&sp68), 1.5e+02f, 2e+02f, 25.0f, 0);
        sp68 = 2e+01f;
        sp70 = -5.8e+02f;
        sp6C = 1e+02f;
        func_8004B0E0(D_8012FCC0, 2, 4, ((s32)&sp58), ((s32)&sp68), 1.5e+02f, 2e+02f, 25.0f, 0);
        sp68 = 2e+01f;
        sp70 = -635.0f;
        sp6C = 1e+02f;
        func_8004B0E0(D_8012FCC0, 2, 5, ((s32)&sp58), ((s32)&sp68), 1.5e+02f, 2e+02f, 55.0f, 0);
        sp68 = -1.6e+02f;
        sp70 = -555.0f;
        sp6C = 2e+02f;
        sp58 = 4e+02f;
        sp60 = -555.0f;
        sp5C = 2.4e+02f;
        func_80049ABC(D_80112CD0, ((s32)&sp58), ((s32)&sp68), 2, 0, 6e+02f);
        sp58 = 4e+02f;
        sp60 = -655.0f;
        sp5C = 2.4e+02f;
        func_80049ABC(D_80112CD0, ((s32)&sp58), ((s32)&sp68), 3, 0, 6e+02f);
        sp58 = 4e+02f;
        sp60 = -455.0f;
        sp5C = 2.4e+02f;
        func_80049ABC(D_80112CD0, ((s32)&sp58), ((s32)&sp68), 4, 0, 6e+02f);
        sp58 = 4e+02f;
        sp60 = -575.0f;
        sp5C = 2.4e+02f;
        func_80049ABC(D_80112CD0, ((s32)&sp58), ((s32)&sp68), 5, 0, 6e+02f);
        sp58 = 1643.0f;
        sp60 = 8.6e+02f;
        sp5C = 1e+02f;
        sp68 = 1493.0f;
        sp70 = 8.6e+02f;
        sp6C = 1e+02f;
        func_8004B0E0(D_8012FCC0, 2, 6, ((s32)&sp58), ((s32)&sp68), 3.2e+02f, 1e+02f, 3.2e+02f, 0);
        sp68 = 1618.0f;
        sp70 = 8.6e+02f;
        sp6C = 1e+02f;
        func_8004B0E0(D_8012FCC0, 2, 7, ((s32)&sp58), ((s32)&sp68), 3.2e+02f, 25.0f, 3.2e+02f, 0);
        sp68 = 1668.0f;
        sp70 = 8.6e+02f;
        sp6C = 1e+02f;
        func_8004B0E0(D_8012FCC0, 2, 8, ((s32)&sp58), ((s32)&sp68), 3.2e+02f, 25.0f, 3.2e+02f, 0);
        sp68 = 1793.0f;
        sp70 = 8.6e+02f;
        sp6C = 1e+02f;
        func_8004B0E0(D_8012FCC0, 2, 9, ((s32)&sp58), ((s32)&sp68), 3.2e+02f, 1e+02f, 3.2e+02f, 0);
        sp68 = 1643.0f;
        sp70 = 8.6e+02f;
        sp6C = 2e+02f;
        sp58 = 1703.0f;
        sp60 = 4e+02f;
        sp5C = 2.4e+02f;
        func_80049ABC(D_80112CD0, ((s32)&sp58), ((s32)&sp68), 9, 0, 6e+02f);
        sp58 = 1593.0f;
        sp60 = 4e+02f;
        sp5C = 2.4e+02f;
        func_80049ABC(D_80112CD0, ((s32)&sp58), ((s32)&sp68), 8, 0, 6e+02f);
        sp58 = 1693.0f;
        sp60 = 4e+02f;
        sp5C = 2.4e+02f;
        func_80049ABC(D_80112CD0, ((s32)&sp58), ((s32)&sp68), 7, 0, 6e+02f);
        sp58 = 1603.0f;
        sp60 = 4e+02f;
        sp5C = 2.4e+02f;
        func_80049ABC(D_80112CD0, ((s32)&sp58), ((s32)&sp68), 6, 0, 6e+02f);
        sp58 = 2.6e+02f;
        sp60 = 842.0f;
        sp5C = 1e+02f;
        sp68 = 2.6e+02f;
        sp70 = 842.0f;
        sp6C = 1e+02f;
        func_8004B0E0(D_8012FCC0, 2, 10, ((s32)&sp58), ((s32)&sp68), 2.5e+02f, 2e+02f, 2e+02f, 0);
        sp68 = 2.6e+02f;
        sp70 = 862.0f;
        sp6C = 1e+02f;
        func_8004B0E0(D_8012FCC0, 2, 11, ((s32)&sp58), ((s32)&sp68), 2.5e+02f, 2e+02f, 2e+01f, 0);
        sp68 = 2.6e+02f;
        sp70 = 822.0f;
        sp6C = 1e+02f;
        func_8004B0E0(D_8012FCC0, 2, 12, ((s32)&sp58), ((s32)&sp68), 2.5e+02f, 2e+02f, 2e+01f, 0);
        sp68 = 2.7e+02f;
        sp70 = 842.0f;
        sp6C = 1e+02f;
        func_8004B0E0(D_8012FCC0, 2, 13, ((s32)&sp58), ((s32)&sp68), 2.5e+02f, 1e+01f, 2e+02f, 0);
        sp68 = 2.4e+02f;
        sp70 = 842.0f;
        sp6C = 1e+02f;
        func_8004B0E0(D_8012FCC0, 2, 14, ((s32)&sp58), ((s32)&sp68), 2.5e+02f, 2e+01f, 2e+02f, 0);
        sp68 = 2e+02f;
        sp70 = 842.0f;
        sp6C = 1e+02f;
        func_8004B0E0(D_8012FCC0, 2, 15, ((s32)&sp58), ((s32)&sp68), 2.5e+02f, 2e+01f, 2e+02f, 0);
        sp68 = 2.6e+02f;
        sp70 = 842.0f;
        sp6C = 2e+02f;
        sp58 = 6.5e+02f;
        sp60 = 6.1e+02f;
        sp5C = 2.4e+02f;
        func_80049ABC(D_80112CD0, ((s32)&sp58), ((s32)&sp68), 10, 0, 7.2e+02f);
        sp58 = 6.5e+02f;
        sp60 = 5.9e+02f;
        sp5C = 2.4e+02f;
        func_80049ABC(D_80112CD0, ((s32)&sp58), ((s32)&sp68), 11, 0, 7.2e+02f);
        sp58 = 625.0f;
        sp60 = 5e+02f;
        sp5C = 2.4e+02f;
        func_80049ABC(D_80112CD0, ((s32)&sp58), ((s32)&sp68), 12, 0, 7.2e+02f);
        sp58 = 4.5e+02f;
        sp60 = 5e+02f;
        sp5C = 2.4e+02f;
        func_80049ABC(D_80112CD0, ((s32)&sp58), ((s32)&sp68), 13, 0, 7.2e+02f);
        sp58 = 375.0f;
        sp60 = 5e+02f;
        sp5C = 2.4e+02f;
        func_80049ABC(D_80112CD0, ((s32)&sp58), ((s32)&sp68), 14, 0, 7.2e+02f);
        sp58 = 325.0f;
        sp60 = 4.5e+02f;
        sp5C = 2.4e+02f;
        func_80049ABC(D_80112CD0, ((s32)&sp58), ((s32)&sp68), 15, 0, 7.2e+02f);
    }
}
