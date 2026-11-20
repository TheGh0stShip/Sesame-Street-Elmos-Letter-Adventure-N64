
struct n64dk_mF8_40 { u8 pad[0xF8]; struct { u8 b[0x40]; } m[1]; };
struct gd_C_s32 { u8 pad[0xC]; s32 v; };
struct gd_28_f32 { u8 pad[0x28]; f32 v; };
struct gd_2C_f32 { u8 pad[0x2C]; f32 v; };
struct gd_30_f32 { u8 pad[0x30]; f32 v; };
struct gd_34_f32 { u8 pad[0x34]; f32 v; };
struct gd_34_s32 { u8 pad[0x34]; s32 v; };
struct gd_38_f32 { u8 pad[0x38]; f32 v; };
struct gd_3C_f32 { u8 pad[0x3C]; f32 v; };
struct gd_40_f32 { u8 pad[0x40]; f32 v; };
struct gd_44_f32 { u8 pad[0x44]; f32 v; };
struct gd_48_f32 { u8 pad[0x48]; f32 v; };
struct gd_4C_f32 { u8 pad[0x4C]; f32 v; };
struct gd_50_f32 { u8 pad[0x50]; f32 v; };
struct gd_58_f32 { u8 pad[0x58]; f32 v; };
struct gd_58_f64 { u8 pad[0x58]; f64 v; };
struct gd_5C_f32 { u8 pad[0x5C]; f32 v; };
struct gd_60_f32 { u8 pad[0x60]; f32 v; };
struct gd_60_s32 { u8 pad[0x60]; s32 v; };
struct gd_1C4_f32 { u8 pad[0x1C4]; f32 v; };
struct gd_1C8_f32 { u8 pad[0x1C8]; f32 v; };
struct gd_1CC_f32 { u8 pad[0x1CC]; f32 v; };
struct gd_1D0_f32 { u8 pad[0x1D0]; f32 v; };
struct gd_1E4_s32 { u8 pad[0x1E4]; s32 v; };
struct gd_1EC_s32 { u8 pad[0x1EC]; s32 v; };
struct gd_1F0_s32 { u8 pad[0x1F0]; s32 v; };
extern s32 D_80034B64;
extern s32 D_80070760;
extern f64 D_8007A918;
extern f64 D_8007A920;
extern f64 D_8007A928;
extern f64 D_8007A930;
extern f64 D_8007A938;
extern u8 D_800ACC2E;
extern s32 D_80109B8C;
s32 func_80001424();
struct V3 { f32 x, y, z; };
s32 func_8001F1C8();
f32 func_80054D30(f32);
f32 func_80056500(f32);

void func_80032EB4(s32 arg0) {
    s32 sp18;
    f32 sp1C;
    f32 sp20;
    f32 sp24;

    sp18 = arg0;
    if (D_800ACC2E != 0) {
        func_8001F1C8(((s32)&((struct n64dk_mF8_40 *)sp18)->m[D_80070760]), (sp18 + 36), ((struct { u8 pad[0x58]; struct V3 v; } *)sp18)->v);
        func_80001424(((s32)&D_80034B64), sp18, ((struct gd_1F0_s32 *)sp18)->v, 1, 0);
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
    sp1C = func_80054D30(sp24);
    sp20 = func_80056500(sp24);
    ((struct gd_30_f32 *)sp18)->v = sp1C;
    ((struct gd_34_s32 *)sp18)->v = 0;
    ((struct gd_38_f32 *)sp18)->v = sp20;
    ((struct gd_48_f32 *)sp18)->v = (((struct gd_34_f32 *)sp18)->v * ((struct gd_44_f32 *)sp18)->v) - (((struct gd_38_f32 *)sp18)->v * ((struct gd_40_f32 *)sp18)->v);
    ((struct gd_4C_f32 *)sp18)->v = (((struct gd_38_f32 *)sp18)->v * ((struct gd_3C_f32 *)sp18)->v) - (((struct gd_30_f32 *)sp18)->v * ((struct gd_44_f32 *)sp18)->v);
    ((struct gd_50_f32 *)sp18)->v = (((struct gd_30_f32 *)sp18)->v * ((struct gd_40_f32 *)sp18)->v) - (((struct gd_34_f32 *)sp18)->v * ((struct gd_3C_f32 *)sp18)->v);
}
