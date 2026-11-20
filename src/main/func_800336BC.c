
struct n64dk_mF8_40 { u8 pad[0xF8]; struct { u8 b[0x40]; } m[1]; };
struct gd_C_s32 { u8 pad[0xC]; s32 v; };
struct gd_10_s32 { u8 pad[0x10]; s32 v; };
struct gd_24_f32 { u8 pad[0x24]; f32 v; };
struct gd_28_f32 { u8 pad[0x28]; f32 v; };
struct gd_2C_f32 { u8 pad[0x2C]; f32 v; };
struct gd_30_f32 { u8 pad[0x30]; f32 v; };
struct gd_34_f32 { u8 pad[0x34]; f32 v; };
struct gd_34_s32 { u8 pad[0x34]; s32 v; };
struct gd_38_f32 { u8 pad[0x38]; f32 v; };
struct gd_3C_f32 { u8 pad[0x3C]; f32 v; };
struct gd_3C_s32 { u8 pad[0x3C]; s32 v; };
struct gd_40_f32 { u8 pad[0x40]; f32 v; };
struct gd_44_f32 { u8 pad[0x44]; f32 v; };
struct gd_44_s32 { u8 pad[0x44]; s32 v; };
struct gd_48_f32 { u8 pad[0x48]; f32 v; };
struct gd_4C_f32 { u8 pad[0x4C]; f32 v; };
struct gd_50_f32 { u8 pad[0x50]; f32 v; };
struct gd_54_s32 { u8 pad[0x54]; s32 v; };
struct gd_58_f64 { u8 pad[0x58]; f64 v; };
struct gd_60_f32 { u8 pad[0x60]; f32 v; };
struct gd_60_s32 { u8 pad[0x60]; s32 v; };
struct gd_68_f32 { u8 pad[0x68]; f32 v; };
struct gd_1B8_u8 { u8 pad[0x1B8]; u8 v; };
struct gd_1BC_s32 { u8 pad[0x1BC]; s32 v; };
struct gd_1C0_s32 { u8 pad[0x1C0]; s32 v; };
struct gd_1C4_f32 { u8 pad[0x1C4]; f32 v; };
struct gd_1C8_f32 { u8 pad[0x1C8]; f32 v; };
struct gd_1C8_s32 { u8 pad[0x1C8]; s32 v; };
struct gd_1CC_f32 { u8 pad[0x1CC]; f32 v; };
struct gd_1D0_f32 { u8 pad[0x1D0]; f32 v; };
struct gd_1F0_s32 { u8 pad[0x1F0]; s32 v; };
struct gd_1F0_u8 { u8 pad[0x1F0]; u8 v; };
struct gd_200_s32 { u8 pad[0x200]; s32 v; };
extern s32 D_80034B64;
extern s32 D_8006EDD8;
extern u8 D_8006EDE1;
extern s32 D_80070760;
extern s32 D_800731F0;
extern s32 D_80073200;
extern s32 D_80073218;
extern s32 D_80073258;
extern s32 D_800737E8;
extern s32 D_80073860;
extern s32 D_80073930;
extern s32 D_80073A00;
extern s8 D_800745F7;
extern s8 D_800745F8;
extern s8 D_80075E2D;
extern s8 D_80075E2E;
extern s8 D_80075E2F;
extern f64 D_8007A970;
extern f64 D_8007A978;
extern f64 D_8007A9A0;
extern f64 D_8007A9A8;
extern f64 D_8007A9B0;
extern f64 D_8007A9B8;
extern f64 D_8007A9C0;
extern f64 D_8007A9C8;
extern f64 D_8007A9D0;
extern f64 D_8007A9D8;
extern f64 D_8007A9E0;
extern f64 D_8007A9E8;
extern f64 D_8007A9F0;
extern f64 D_8007A9F8;
extern f64 D_8007AA00;
extern f64 D_8007AA08;
extern f64 D_8007AA10;
extern f64 D_8007AA18;
extern s32 D_800A75E8;
extern s32 D_800A7608;
extern s16 D_800A7AA8;
extern s32 D_800A8D48;
extern s8 D_800A8DDC;
extern s32 D_800A8F9C;
extern s32 D_800ACBA0;
extern u8 D_800ACC2E;
extern s32 D_800BD468;
extern s32 D_80106888;
extern u16 D_801078B8;
extern s32 D_80109B8C;
extern u16 D_80109C3E;
extern s32 D_8010E488;
extern s32 D_80112CD0;
extern s32 D_80115258;
extern s32 D_80115374;
extern s8 D_801282A3;
extern s32 D_8012EF88;
extern u8 D_8012EFCC;
extern s32 D_8012EFD0;
extern s16 D_8013C650;
extern s32 D_8013E680;
extern s32 D_8013ED88;
s32 func_80001424(s32, s32, s32, s32, f32);
s32 func_8000E9A0();
s32 func_80012B60();
s32 func_80017568();
struct V3 { f32 x, y, z; };
s32 func_8001F1C8();
s32 func_80020EB4();
s32 func_80035828();
f32 func_80054D20(f32);
f32 func_80054D30(f32);
f32 func_80056500(f32);
s32 func_80057230();
s32 func_80057650();
f64 func_80067FB0();

void func_800336BC(s32 arg0) {
    register s32 reg_s0;
    s32 sp18;
    f64 sp20;
    f32 sp28;
    s32 pad0;
    f32 sp30;
    s32 pad1;
    f32 sp38;
    s32 pad2;
    f32 sp40;
    f32 sp44;
    f32 sp48;
    f32 sp4C;
    f32 sp50;
    s32 sp54;
    s32 sp58;
    f64 sp60;

    sp20 = 0.0;
    sp18 = arg0;
    if (D_800ACC2E != 0) {
        if (D_8012EFD0 != 19) {
            sp54 = func_80012B60((sp18 + 36));
        } else {
            sp54 = 1;
        }
        if (sp54 != 0) {
            func_8001F1C8(((s32)&((struct n64dk_mF8_40 *)sp18)->m[D_80070760]), (sp18 + 36), ((struct { u8 pad[0x58]; struct V3 v; } *)sp18)->v);
            func_80001424(((s32)&D_80034B64), sp18, ((struct gd_1F0_s32 *)sp18)->v, 1, ((f32)sp20));
        }
        return;
    }
    if (D_80109B8C >= 5) {
        if (D_80109B8C >= 8) {
            ((struct gd_C_s32 *)sp18)->v = ((struct gd_C_s32 *)sp18)->v | 1;
        }
        return;
    }
    switch (D_8012EFCC) {
    case 0:
        if (D_8012EFD0 != 19) {
            if (((D_801078B8 & 0xC00F) & 0xFFFF) != 0) {
                if (((struct gd_1BC_s32 *)sp18)->v == 0) {
                    if (((struct gd_1C8_s32 *)D_80106888)->v != 34) {
                        if (((struct gd_1C8_s32 *)D_80106888)->v != 35) {
                            if (D_80115374 == 0) {
                                sp30 = ((struct gd_24_f32 *)D_80106888)->v - ((struct gd_24_f32 *)sp18)->v;
                                sp38 = ((struct gd_2C_f32 *)D_80106888)->v - ((struct gd_2C_f32 *)sp18)->v;
                                sp40 = (sp30 * sp30) + (sp38 * sp38);
                                if (sp40 < 1.6e+05f) {
                                    switch (D_8012EFD0) {
                                    case 15:
                                    case 16:
                                        if (((u32)((struct gd_1B8_u8 *)sp18)->v >= 65) && ((u32)((struct gd_1B8_u8 *)sp18)->v < 91)) {
                                            sp58 = ((struct gd_1B8_u8 *)sp18)->v - 65;
                                        } else {
                                            if (((u32)((struct gd_1B8_u8 *)sp18)->v >= 97) && ((u32)((struct gd_1B8_u8 *)sp18)->v < 123)) {
                                                sp58 = ((struct gd_1B8_u8 *)sp18)->v - 97;
                                            } else {
                                                sp58 = 0;
                                            }
                                        }
                                        D_80115258 = ((s32)&D_80073860) + (sp58 * 8);
                                        break;
                                    case 13:
                                    case 14:
                                        if (((u32)((struct gd_1B8_u8 *)sp18)->v >= 65) && ((u32)((struct gd_1B8_u8 *)sp18)->v < 91)) {
                                            sp58 = ((struct gd_1B8_u8 *)sp18)->v - 65;
                                        } else {
                                            if (((u32)((struct gd_1B8_u8 *)sp18)->v >= 97) && ((u32)((struct gd_1B8_u8 *)sp18)->v < 123)) {
                                                sp58 = ((struct gd_1B8_u8 *)sp18)->v - 97;
                                            } else {
                                                sp58 = 0;
                                            }
                                        }
                                        D_80115258 = ((s32)&D_80073930) + (sp58 * 8);
                                        break;
                                    case 17:
                                    case 18:
                                        if (((u32)((struct gd_1B8_u8 *)sp18)->v >= 65) && ((u32)((struct gd_1B8_u8 *)sp18)->v < 91)) {
                                            sp58 = ((struct gd_1B8_u8 *)sp18)->v - 65;
                                        } else {
                                            if (((u32)((struct gd_1B8_u8 *)sp18)->v >= 97) && ((u32)((struct gd_1B8_u8 *)sp18)->v < 123)) {
                                                sp58 = ((struct gd_1B8_u8 *)sp18)->v - 97;
                                            } else {
                                                sp58 = 0;
                                            }
                                        }
                                        D_80115258 = ((s32)&D_80073A00) + (sp58 * 8);
                                        break;
                                    }
                                    if (D_8012EFD0 != 19) {
                                        if (((struct gd_1C0_s32 *)sp18)->v != -1) {
                                            ((struct gd_1BC_s32 *)sp18)->v = 1;
                                            D_800A7AA8 = 0;
                                            D_8013E680 = ((s32)&D_80073218) + (func_80020EB4(7) * 8);
                                            D_80115374 = (s32)&D_80073200;
                                            func_80057230(((s32)&D_8013ED88), 0, 1);
                                        } else {
                                            ((struct gd_1BC_s32 *)sp18)->v = 2;
                                            D_800A7AA8 = 0;
                                            D_8013E680 = ((s32)&D_80073258) + (func_80020EB4(10) * 8);
                                            D_80115374 = (s32)&D_80073200;
                                            func_80057230(((s32)&D_8013ED88), 0, 1);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        } else {
            if (((D_801078B8 & 0xC00F) & 0xFFFF) != 0) {
                if (((struct gd_1BC_s32 *)sp18)->v == 0) {
                    if (((struct gd_1C8_s32 *)D_80106888)->v != 34) {
                        if (((struct gd_1C8_s32 *)D_80106888)->v != 35) {
                            if (D_80115374 == 0) {
                                if (((struct gd_1F0_u8 *)D_80106888)->v == 0) {
                                    sp30 = ((struct gd_24_f32 *)D_80106888)->v - ((struct gd_24_f32 *)sp18)->v;
                                    sp38 = ((struct gd_2C_f32 *)D_80106888)->v - ((struct gd_2C_f32 *)sp18)->v;
                                    sp40 = (sp30 * sp30) + (sp38 * sp38);
                                    if (sp40 < 3.6e+05f) {
                                        if (((u32)((struct gd_1B8_u8 *)sp18)->v >= 65) && ((u32)((struct gd_1B8_u8 *)sp18)->v < 91)) {
                                            sp58 = ((struct gd_1B8_u8 *)sp18)->v - 65;
                                        } else {
                                            sp58 = 0;
                                        }
                                        if (((struct gd_1C0_s32 *)sp18)->v != -1) {
                                            ((struct gd_1BC_s32 *)sp18)->v = 1;
                                            D_800A7AA8 = 0;
                                            D_80075E2D = 1;
                                            D_800745F8 = 1;
                                            D_80075E2F = 1;
                                            D_800745F7 = 0;
                                            ((struct gd_200_s32 *)D_80106888)->v = ((struct gd_200_s32 *)D_80106888)->v & -2;
                                            ((struct gd_200_s32 *)D_80106888)->v = ((struct gd_200_s32 *)D_80106888)->v & -3;
                                        } else {
                                            ((struct gd_1BC_s32 *)sp18)->v = 2;
                                            D_800A7AA8 = 0;
                                            D_80115258 = ((s32)&D_800737E8) + (func_80020EB4(2) * 8);
                                            D_80115374 = (s32)&D_800731F0;
                                            func_80057230(((s32)&D_8013ED88), 0, 1);
                                            D_80075E2E = 1;
                                            D_80075E2F = 1;
                                            D_800745F7 = 1;
                                            ((struct gd_200_s32 *)D_80106888)->v = ((struct gd_200_s32 *)D_80106888)->v & -2;
                                            ((struct gd_200_s32 *)D_80106888)->v = ((struct gd_200_s32 *)D_80106888)->v & -3;
                                            D_8006EDE1++;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if (((f64)((struct gd_1D0_f32 *)sp18)->v) == D_8007A970) {
            if (((struct gd_1BC_s32 *)sp18)->v == 1) {
                func_80017568(7);
            } else {
                if (((struct gd_1BC_s32 *)sp18)->v == 2) {
                    func_80017568(5);
                }
            }
        }
        if (((f64)((struct gd_1D0_f32 *)sp18)->v) == D_8007A978) {
            switch (D_8012EFD0) {
            case 15:
            case 16:
                if (((struct gd_1BC_s32 *)sp18)->v == 1) {
                    func_80017568(34);
                } else {
                    func_80017568(35);
                }
                break;
            case 13:
                if (((struct gd_1BC_s32 *)sp18)->v == 1) {
                    func_80017568(29);
                } else {
                    func_80017568(30);
                }
                break;
            case 14:
                if (((struct gd_1BC_s32 *)sp18)->v == 1) {
                    func_80017568(24);
                } else {
                    func_80017568(25);
                }
                break;
            case 17:
                if (((struct gd_1BC_s32 *)sp18)->v == 1) {
                    func_80017568(42);
                } else {
                    func_80017568(43);
                }
                break;
            case 18:
                if (((struct gd_1BC_s32 *)sp18)->v == 1) {
                    func_80017568(54);
                } else {
                    func_80017568(55);
                }
                break;
            case 19:
                if (((struct gd_1BC_s32 *)sp18)->v == 1) {
                    func_80017568(17);
                } else {
                    func_80017568(18);
                }
                break;
            }
        }
        if ((((struct gd_1D0_f32 *)sp18)->v < 0.0f) && ((((struct gd_1BC_s32 *)sp18)->v == 1) || (((struct gd_1BC_s32 *)sp18)->v == 2))) {
            ((struct gd_1D0_f32 *)sp18)->v++;
        }
        if (((f64)((struct gd_1D0_f32 *)sp18)->v) < D_8007A9A0) {
            if (((f64)((struct gd_1D0_f32 *)sp18)->v) >= 0.0) {
                if (((struct gd_1BC_s32 *)sp18)->v == 1) {
                    if (((f64)((struct gd_1D0_f32 *)sp18)->v) == D_8007A9A8) {
                        ((struct gd_54_s32 *)sp18)->v = 0;
                        func_80017568(6);
                    }
                    if (((f64)((struct gd_1D0_f32 *)sp18)->v) < D_8007A9B0) {
                        reg_s0 = sp18;
                        ((struct gd_30_f32 *)reg_s0)->v = func_80054D30(((struct gd_1C4_f32 *)sp18)->v);
                        ((struct gd_34_s32 *)sp18)->v = 0;
                        reg_s0 = sp18;
                        ((struct gd_38_f32 *)reg_s0)->v = func_80056500(((struct gd_1C4_f32 *)sp18)->v);
                        ((struct gd_3C_s32 *)sp18)->v = 0;
                        ((struct gd_40_f32 *)sp18)->v = 1.0f;
                        ((struct gd_44_s32 *)sp18)->v = 0;
                        ((struct gd_28_f32 *)sp18)->v = (f32)(((f64)((struct gd_28_f32 *)sp18)->v) + (((f64)((struct gd_1D0_f32 *)sp18)->v) * D_8007A9B8));
                        ((struct gd_1C4_f32 *)sp18)->v = (f32)(((f64)((struct gd_1C4_f32 *)sp18)->v) + D_8007A9C0);
                        if (D_8012EFCC == 0) {
                            func_8000E9A0(sp18);
                        }
                    } else {
                        if (((f64)((struct gd_1D0_f32 *)sp18)->v) < D_8007A9C8) {
                            ((struct gd_24_f32 *)sp18)->v = (f32)(((f64)((struct gd_24_f32 *)sp18)->v) + (((f64)((struct gd_30_f32 *)sp18)->v) * D_8007A9D0));
                            ((struct gd_2C_f32 *)sp18)->v = (f32)(((f64)((struct gd_2C_f32 *)sp18)->v) + (((f64)((struct gd_38_f32 *)sp18)->v) * D_8007A9D8));
                            ((struct gd_28_f32 *)sp18)->v = (f32)(((f64)((struct gd_28_f32 *)sp18)->v) + D_8007A9E0);
                            if (D_8012EFCC == 0) {
                                func_8000E9A0(sp18);
                            }
                        } else {
                            func_80017568(1);
                            D_800ACBA0++;
                            D_800A8F9C++;
                            (*(s8 *)(((struct gd_1C0_s32 *)sp18)->v + ((s32)&D_800BD468))) = 1;
                            if ((D_8012EFD0 != 19) && ((D_800ACBA0 == D_8010E488) || (D_800A8F9C == D_800A8D48))) {
                                func_80035828(D_80106888, 34);
                                if (D_8012EFCC != 0) {
                                    D_800A8DDC = 0;
                                    D_801282A3 = 0;
                                    D_8012EFCC = 0;
                                    D_8006EDD8 = D_8006EDD8 | 112;
                                    D_8006EDD8 = D_8006EDD8 & -1551;
                                    if (D_80115374 != 0) {
                                        D_8013C650 = (u32)D_80109C3E >> 3;
                                        func_80057650(((s32)&D_8012EF88));
                                    }
                                }
                            }
                            ((struct gd_C_s32 *)sp18)->v = ((struct gd_C_s32 *)sp18)->v | 1;
                            ((struct gd_10_s32 *)sp18)->v = 0;
                            return;
                        }
                    }
                    ((struct gd_1D0_f32 *)sp18)->v++;
                } else {
                    if (((struct gd_1BC_s32 *)sp18)->v == 2) {
                        if (((f64)((struct gd_1D0_f32 *)sp18)->v) < D_8007A9E8) {
                            sp44 = func_80054D30(((struct gd_1C4_f32 *)sp18)->v);
                            sp48 = func_80056500(((struct gd_1C4_f32 *)sp18)->v);
                            sp4C = func_80054D30(((struct gd_1C8_f32 *)sp18)->v);
                            sp50 = func_80056500(((struct gd_1C8_f32 *)sp18)->v);
                            ((struct gd_30_f32 *)sp18)->v = sp44 * sp4C;
                            ((struct gd_34_f32 *)sp18)->v = sp50;
                            ((struct gd_38_f32 *)sp18)->v = sp48 * sp4C;
                            sp28 = func_80054D20((((((struct gd_30_f32 *)sp18)->v * ((struct gd_30_f32 *)sp18)->v) + (((struct gd_34_f32 *)sp18)->v * ((struct gd_34_f32 *)sp18)->v)) + (((struct gd_38_f32 *)sp18)->v * ((struct gd_38_f32 *)sp18)->v)));
                            if (sp28 >= 1e-07f) {
                                sp60 = D_8007A9F0 / ((f64)sp28);
                                ((struct gd_30_f32 *)sp18)->v = (f32)(((f64)((struct gd_30_f32 *)sp18)->v) * sp60);
                                ((struct gd_34_f32 *)sp18)->v = (f32)(((f64)((struct gd_34_f32 *)sp18)->v) * sp60);
                                ((struct gd_38_f32 *)sp18)->v = (f32)(((f64)((struct gd_38_f32 *)sp18)->v) * sp60);
                            } else {
                            }
                            ((struct gd_3C_f32 *)sp18)->v = (-sp44) * sp50;
                            ((struct gd_40_f32 *)sp18)->v = sp4C;
                            ((struct gd_44_f32 *)sp18)->v = (-sp48) * sp50;
                            if (((f64)((struct gd_1C8_f32 *)sp18)->v) < (D_8007A9F8 - ((f64)((struct gd_1CC_f32 *)sp18)->v))) {
                                ((struct gd_1C8_f32 *)sp18)->v = ((struct gd_1C8_f32 *)sp18)->v + ((struct gd_1CC_f32 *)sp18)->v;
                                ((struct gd_1CC_f32 *)sp18)->v = (f32)(((f64)((struct gd_1CC_f32 *)sp18)->v) + D_8007AA00);
                            }
                        } else {
                            if (((f64)((struct gd_1D0_f32 *)sp18)->v) < D_8007AA08) {
                                ((struct gd_28_f32 *)sp18)->v = (f32)(((f64)((struct gd_28_f32 *)sp18)->v) - D_8007AA10);
                            } else {
                                D_800A7608++;
                                ((struct gd_C_s32 *)sp18)->v = ((struct gd_C_s32 *)sp18)->v | 1;
                                ((struct gd_10_s32 *)sp18)->v = 0;
                                if (D_8012EFD0 != 19) {
                                    if (D_800A7608 == D_800A75E8) {
                                        func_80035828(D_80106888, 34);
                                        if (D_8012EFCC != 0) {
                                            D_800A8DDC = 0;
                                            D_801282A3 = 0;
                                            D_8012EFCC = 0;
                                            D_8006EDD8 = D_8006EDD8 | 112;
                                            D_8006EDD8 = D_8006EDD8 & -1551;
                                            if (D_80115374 != 0) {
                                                D_8013C650 = (u32)D_80109C3E >> 3;
                                                func_80057650(((s32)&D_8012EF88));
                                            }
                                        }
                                    }
                                }
                                return;
                            }
                        }
                        ((struct gd_1D0_f32 *)sp18)->v++;
                    }
                }
                goto L1140;
            }
        }
        if (D_8012EFD0 != 19) {
            sp30 = ((struct gd_60_f32 *)D_80112CD0)->v - ((struct gd_24_f32 *)sp18)->v;
            sp38 = ((struct gd_68_f32 *)D_80112CD0)->v - ((struct gd_2C_f32 *)sp18)->v;
            ((struct gd_1C4_f32 *)sp18)->v = (f32)func_80067FB0(((f64)sp38), ((f64)sp30));
            reg_s0 = sp18;
            ((struct gd_30_f32 *)reg_s0)->v = func_80054D30(((struct gd_1C4_f32 *)sp18)->v);
            reg_s0 = sp18;
            ((struct gd_38_f32 *)reg_s0)->v = func_80056500(((struct gd_1C4_f32 *)sp18)->v);
            sp28 = func_80054D20((((((struct gd_30_f32 *)sp18)->v * ((struct gd_30_f32 *)sp18)->v) + (((struct gd_34_f32 *)sp18)->v * ((struct gd_34_f32 *)sp18)->v)) + (((struct gd_38_f32 *)sp18)->v * ((struct gd_38_f32 *)sp18)->v)));
            if (sp28 >= 1e-07f) {
                sp60 = D_8007AA18 / ((f64)sp28);
                ((struct gd_30_f32 *)sp18)->v = (f32)(((f64)((struct gd_30_f32 *)sp18)->v) * sp60);
                ((struct gd_34_f32 *)sp18)->v = (f32)(((f64)((struct gd_34_f32 *)sp18)->v) * sp60);
                ((struct gd_38_f32 *)sp18)->v = (f32)(((f64)((struct gd_38_f32 *)sp18)->v) * sp60);
            } else {
L1140: ;
            }
        }
        ((struct gd_48_f32 *)sp18)->v = (((struct gd_34_f32 *)sp18)->v * ((struct gd_44_f32 *)sp18)->v) - (((struct gd_38_f32 *)sp18)->v * ((struct gd_40_f32 *)sp18)->v);
        ((struct gd_4C_f32 *)sp18)->v = (((struct gd_38_f32 *)sp18)->v * ((struct gd_3C_f32 *)sp18)->v) - (((struct gd_30_f32 *)sp18)->v * ((struct gd_44_f32 *)sp18)->v);
        ((struct gd_50_f32 *)sp18)->v = (((struct gd_30_f32 *)sp18)->v * ((struct gd_40_f32 *)sp18)->v) - (((struct gd_34_f32 *)sp18)->v * ((struct gd_3C_f32 *)sp18)->v);
    }
}
