struct gd_2_u16 { u8 pad[0x2]; u16 v; };
struct gd_4_u16 { u8 pad[0x4]; u16 v; };
struct gd_6_u16 { u8 pad[0x6]; u16 v; };
struct gd_8_s16 { u8 pad[0x8]; s16 v; };
struct gd_8_s32 { u8 pad[0x8]; s32 v; };
struct gd_A_s16 { u8 pad[0xA]; s16 v; };
struct gd_C_f32 { u8 pad[0xC]; f32 v; };
struct gd_C_s32 { u8 pad[0xC]; s32 v; };
struct gd_10_f32 { u8 pad[0x10]; f32 v; };
struct gd_10_s32 { u8 pad[0x10]; s32 v; };
struct gd_14_f32 { u8 pad[0x14]; f32 v; };
struct gd_14_s32 { u8 pad[0x14]; s32 v; };
struct gd_18_f32 { u8 pad[0x18]; f32 v; };
struct gd_18_s32 { u8 pad[0x18]; s32 v; };
struct gd_1C_f32 { u8 pad[0x1C]; f32 v; };
struct gd_20_f32 { u8 pad[0x20]; f32 v; };
struct gd_24_f32 { u8 pad[0x24]; f32 v; };
struct gd_28_f32 { u8 pad[0x28]; f32 v; };
struct gd_2C_f32 { u8 pad[0x2C]; f32 v; };
struct gd_30_f32 { u8 pad[0x30]; f32 v; };
struct gd_34_f32 { u8 pad[0x34]; f32 v; };
struct gd_38_f32 { u8 pad[0x38]; f32 v; };
struct gd_3C_f32 { u8 pad[0x3C]; f32 v; };
struct gd_40_f32 { u8 pad[0x40]; f32 v; };
struct gd_44_f32 { u8 pad[0x44]; f32 v; };
struct gd_48_f32 { u8 pad[0x48]; f32 v; };
struct gd_4C_f32 { u8 pad[0x4C]; f32 v; };
struct gd_50_f32 { u8 pad[0x50]; f32 v; };
struct gd_54_s32 { u8 pad[0x54]; s32 v; };
struct gd_1A8_f32 { u8 pad[0x1A8]; f32 v; };
struct gd_1AC_f32 { u8 pad[0x1AC]; f32 v; };
struct gd_1B0_f32 { u8 pad[0x1B0]; f32 v; };
struct gd_1B4_s32 { u8 pad[0x1B4]; s32 v; };
struct gd_1B8_s32 { u8 pad[0x1B8]; s32 v; };
struct gd_1BC_s32 { u8 pad[0x1BC]; s32 v; };
struct gd_1C4_s32 { u8 pad[0x1C4]; s32 v; };
struct gd_1D4_s32 { u8 pad[0x1D4]; s32 v; };
struct gd_1D8_s32 { u8 pad[0x1D8]; s32 v; };
struct gd_1DC_s32 { u8 pad[0x1DC]; s32 v; };
struct gd_1E0_s32 { u8 pad[0x1E0]; s32 v; };
struct gd_1E0_s8 { u8 pad[0x1E0]; s8 v; };
struct gd_1E8_s32 { u8 pad[0x1E8]; s32 v; };
extern s32 D_00657E70;
extern s32 D_00668FD0;
extern s32 D_0067BEE0;
extern s32 D_006A2D50;
extern s32 D_006B4150;
extern s32 D_006C4A80;
extern s32 D_006D5E80;
extern s32 D_006E3190;
extern s32 D_006F19C0;
extern s32 D_006F9020;
extern s32 D_0070A5D0;
extern s32 D_800272C8;
extern s32 D_80029CF4;
extern s32 D_80075CD0;
extern s32 D_80075CDC;
extern s32 D_80075CE8;
extern s32 D_8007A190;
extern s32 D_8007A194;
extern f64 D_8007A1F0;
extern f64 D_8007A1F8;
extern s32 D_800A75E0;
extern u8 D_800A7AB4;
extern s32 D_80106874;
extern f32 D_80109C38;
extern s8 D_80109C3C;
extern f32 D_80112CE0;
extern s32 D_8011525C;
extern s32 D_8012EF80;
extern s32 D_8012EFD0;
extern s32 D_80140F78;
s32 func_80018530();
s32 func_8003FE00();
s32 func_80040400();
f32 func_80054D20(f32);
s32 func_80057230();
s32 func_80057BD0();
s32 func_80068300();

void f(s32 arg0, s32 arg1, s32 arg2) {
    register s32 reg_s0;
    register s32 reg_s1;
    register s32 reg_s2;
    s32 sp10;
    s32 sp14;
    f32 sp18;
    f64 sp20;

    sp10 = 0;
    sp14 = 0;
    reg_s1 = arg0;
    reg_s2 = arg0;
    reg_s0 = func_80040400(536);
    switch (reg_s0) {
    case 0:
        func_80057BD0(((s32)&D_8007A190), ((s32)&D_8007A194), 325);
    }
    if (reg_s0 == 0) {
        return;
    }
    func_80068300(reg_s0, 0, 536);
    ((struct gd_10_s32 *)reg_s0)->v = (s32)&D_800272C8;
    ((struct gd_14_s32 *)reg_s0)->v = (s32)&D_80029CF4;
    ((struct gd_18_s32 *)reg_s0)->v = 0;
    ((struct gd_8_s16 *)reg_s0)->v = ((struct gd_2_u16 *)reg_s2)->v;
    ((struct gd_A_s16 *)reg_s0)->v = ((struct gd_6_u16 *)reg_s2)->v;
    ((struct gd_C_s32 *)reg_s0)->v = ((struct gd_8_s32 *)reg_s2)->v;
    sp14 = arg2;
    sp10 = func_80018530(sp14, ((struct gd_4_u16 *)sp14)->v);
    switch (sp10) {
    case 0:
        func_80057BD0(((s32)&D_8007A190), ((s32)&D_8007A194), 342);
    }
    ((struct gd_1C4_s32 *)reg_s0)->v = 0;
    ((struct gd_1BC_s32 *)reg_s0)->v = 0;
    ((struct gd_1E8_s32 *)reg_s0)->v = sp10;
    ((struct gd_1D4_s32 *)reg_s0)->v = 0;
    ((struct gd_1D8_s32 *)reg_s0)->v = 0;
    ((struct gd_1DC_s32 *)reg_s0)->v = 0;
    ((struct gd_1E0_s32 *)reg_s0)->v = 0;
    ((struct gd_54_s32 *)reg_s0)->v = 0;
    if (((u32)D_800A7AB4 >= 49) && ((u32)D_800A7AB4 < 58)) {
        D_8012EF80 = D_800A7AB4 - 49;
    } else {
        if (((u32)D_800A7AB4 >= 65) && ((u32)D_800A7AB4 < 91)) {
            D_8012EF80 = D_800A7AB4 - 65;
        } else {
            if (((u32)D_800A7AB4 >= 97) && ((u32)D_800A7AB4 < 123)) {
                D_8012EF80 = D_800A7AB4 - 97;
            } else {
                D_8012EF80 = 0;
            }
        }
    }
    switch (D_8012EFD0) {
    case 2:
        ((struct gd_1BC_s32 *)reg_s0)->v = *(s32 *)((arg1 * 4) + ((s32)&D_80075CD0));
        ((struct gd_C_s32 *)reg_s0)->v = ((struct gd_C_s32 *)reg_s0)->v & -129;
        ((struct gd_1B4_s32 *)reg_s0)->v = *(s32 *)((arg1 * 4) + ((s32)&D_80075CDC));
        ((struct gd_1B8_s32 *)reg_s0)->v = 0;
        break;
    case 15:
        ((struct gd_1BC_s32 *)reg_s0)->v = 0;
        D_80106874 = (s32)&D_00668FD0;
        D_800A75E0 = ((s32)&D_0067BEE0) - ((s32)&D_00668FD0);
        func_80057230(((s32)&D_80140F78), 0, 1);
        ((struct gd_1B4_s32 *)reg_s0)->v = 26;
        break;
    case 16:
        ((struct gd_1BC_s32 *)reg_s0)->v = 0;
        D_80106874 = (s32)&D_00657E70;
        D_800A75E0 = ((s32)&D_00668FD0) - ((s32)&D_00657E70);
        func_80057230(((s32)&D_80140F78), 0, 1);
        ((struct gd_1B4_s32 *)reg_s0)->v = 24;
        break;
    case 17:
        ((struct gd_1BC_s32 *)reg_s0)->v = 0;
        D_80106874 = (s32)&D_006A2D50;
        D_800A75E0 = ((s32)&D_006B4150) - ((s32)&D_006A2D50);
        func_80057230(((s32)&D_80140F78), 0, 1);
        ((struct gd_1B4_s32 *)reg_s0)->v = 64;
        break;
    case 18:
        ((struct gd_1BC_s32 *)reg_s0)->v = 0;
        D_80106874 = (s32)&D_006C4A80;
        D_800A75E0 = ((s32)&D_006D5E80) - ((s32)&D_006C4A80);
        func_80057230(((s32)&D_80140F78), 0, 1);
        ((struct gd_1B4_s32 *)reg_s0)->v = 67;
        break;
    case 14:
        ((struct gd_1BC_s32 *)reg_s0)->v = 0;
        D_80106874 = (s32)&D_006F9020;
        D_800A75E0 = ((s32)&D_0070A5D0) - ((s32)&D_006F9020);
        func_80057230(((s32)&D_80140F78), 0, 1);
        ((struct gd_1B4_s32 *)reg_s0)->v = 44;
        break;
    case 13:
        ((struct gd_1BC_s32 *)reg_s0)->v = 0;
        D_80106874 = (s32)&D_006E3190;
        D_800A75E0 = ((s32)&D_006F19C0) - ((s32)&D_006E3190);
        func_80057230(((s32)&D_80140F78), 0, 1);
        ((struct gd_1B4_s32 *)reg_s0)->v = 47;
        break;
    case 19:
        ((struct gd_1B4_s32 *)reg_s0)->v = *(s32 *)((arg1 * 4) + ((s32)&D_80075CE8));
        ((struct gd_1B8_s32 *)reg_s0)->v = 0;
        ((struct gd_1E0_s8 *)reg_s0)->v = 1;
        if (D_80109C3C <= 0) {
            D_80109C3C = 0;
        }
        break;
    }
    ((struct gd_1A8_f32 *)reg_s0)->v = 1.0f;
    ((struct gd_1AC_f32 *)reg_s0)->v = 1.0f;
    ((struct gd_1B0_f32 *)reg_s0)->v = 1.0f;
    ((struct gd_24_f32 *)reg_s0)->v = ((struct gd_C_f32 *)reg_s2)->v;
    ((struct gd_28_f32 *)reg_s0)->v = ((struct gd_10_f32 *)reg_s2)->v;
    ((struct gd_2C_f32 *)reg_s0)->v = ((struct gd_14_f32 *)reg_s2)->v;
    D_80112CE0 = ((struct gd_C_f32 *)reg_s2)->v;
    D_80109C38 = ((struct gd_14_f32 *)reg_s2)->v;
    ((struct gd_30_f32 *)reg_s0)->v = ((struct gd_18_f32 *)reg_s2)->v;
    ((struct gd_34_f32 *)reg_s0)->v = ((struct gd_1C_f32 *)reg_s2)->v;
    ((struct gd_38_f32 *)reg_s0)->v = ((struct gd_20_f32 *)reg_s2)->v;
    sp18 = func_80054D20((((((struct gd_30_f32 *)reg_s0)->v * ((struct gd_30_f32 *)reg_s0)->v) + (((struct gd_34_f32 *)reg_s0)->v * ((struct gd_34_f32 *)reg_s0)->v)) + (((struct gd_38_f32 *)reg_s0)->v * ((struct gd_38_f32 *)reg_s0)->v)));
    if (sp18 >= 1e-07f) {
        sp20 = D_8007A1F0 / ((f64)sp18);
        ((struct gd_30_f32 *)reg_s0)->v = (f32)(((f64)((struct gd_30_f32 *)reg_s0)->v) * sp20);
        ((struct gd_34_f32 *)reg_s0)->v = (f32)(((f64)((struct gd_34_f32 *)reg_s0)->v) * sp20);
        ((struct gd_38_f32 *)reg_s0)->v = (f32)(((f64)((struct gd_38_f32 *)reg_s0)->v) * sp20);
    } else {
    }
    ((struct gd_3C_f32 *)reg_s0)->v = ((struct gd_24_f32 *)reg_s2)->v;
    ((struct gd_40_f32 *)reg_s0)->v = ((struct gd_28_f32 *)reg_s2)->v;
    ((struct gd_44_f32 *)reg_s0)->v = ((struct gd_2C_f32 *)reg_s2)->v;
    sp18 = func_80054D20((((((struct gd_3C_f32 *)reg_s0)->v * ((struct gd_3C_f32 *)reg_s0)->v) + (((struct gd_40_f32 *)reg_s0)->v * ((struct gd_40_f32 *)reg_s0)->v)) + (((struct gd_44_f32 *)reg_s0)->v * ((struct gd_44_f32 *)reg_s0)->v)));
    if (sp18 >= 1e-07f) {
        sp20 = D_8007A1F8 / ((f64)sp18);
        ((struct gd_3C_f32 *)reg_s0)->v = (f32)(((f64)((struct gd_3C_f32 *)reg_s0)->v) * sp20);
        ((struct gd_40_f32 *)reg_s0)->v = (f32)(((f64)((struct gd_40_f32 *)reg_s0)->v) * sp20);
        ((struct gd_44_f32 *)reg_s0)->v = (f32)(((f64)((struct gd_44_f32 *)reg_s0)->v) * sp20);
    } else {
    }
    ((struct gd_48_f32 *)reg_s0)->v = (((struct gd_34_f32 *)reg_s0)->v * ((struct gd_44_f32 *)reg_s0)->v) - (((struct gd_38_f32 *)reg_s0)->v * ((struct gd_40_f32 *)reg_s0)->v);
    ((struct gd_4C_f32 *)reg_s0)->v = (((struct gd_38_f32 *)reg_s0)->v * ((struct gd_3C_f32 *)reg_s0)->v) - (((struct gd_30_f32 *)reg_s0)->v * ((struct gd_44_f32 *)reg_s0)->v);
    ((struct gd_50_f32 *)reg_s0)->v = (((struct gd_30_f32 *)reg_s0)->v * ((struct gd_40_f32 *)reg_s0)->v) - (((struct gd_34_f32 *)reg_s0)->v * ((struct gd_3C_f32 *)reg_s0)->v);
    func_8003FE00(reg_s0, D_8011525C, 4, 0);
}
