
struct n64dk_mE8_40 { u8 pad[0xE8]; struct { u8 b[0x40]; } m[1]; };
struct gd_A_u16 { u8 pad[0xA]; u16 v; };
struct gd_C_s32 { u8 pad[0xC]; s32 v; };
struct gd_1C_s32 { u8 pad[0x1C]; s32 v; };
struct gd_1A8_f64 { u8 pad[0x1A8]; f64 v; };
struct gd_1B0_s32 { u8 pad[0x1B0]; s32 v; };
struct gd_1D4_s8 { u8 pad[0x1D4]; s8 v; };
struct gd_1D4_u8 { u8 pad[0x1D4]; u8 v; };
struct gd_1E8_s32 { u8 pad[0x1E8]; s32 v; };
struct gd_1F0_s32 { u8 pad[0x1F0]; s32 v; };
extern s32 D_80024C1C;
extern s32 D_80070760;
extern u8 D_80075C30;
extern s32 D_80075C34;
extern u8 D_800ACC2E;
extern s32 D_80106880;
extern s32 D_80109B8C;
s32 func_80001424(s32, s32, s32, s32, f32);
s32 func_80012B60();
struct V3 { f32 x, y, z; };
s32 func_8001F1C8();

void func_800243AC(s32 arg0) {
    s32 sp18;
    s32 pad0;
    s32 pad1[26];
    s32 sp88;
    s32 pad2;
    s32 pad3;
    s32 sp94;
    f64 sp98;
    s32 pad4[4];
    s8 pad5;

    sp18 = arg0;
    sp88 = 0;
    sp94 = 0;
    if (D_800ACC2E == 0) {
        if (((struct gd_A_u16 *)sp18)->v == 0x4002) {
            if ((D_80106880 & 7) == 0) {
                ((struct gd_1D4_s8 *)sp18)->v++;
                if ((u32)((struct gd_1D4_u8 *)sp18)->v >= 10) {
                    ((struct gd_1D4_s8 *)sp18)->v = 0;
                }
            }
        }
        return;
    }
    sp98 = 0.0;
    sp18 = arg0;
    if (D_80109B8C >= 5) {
        if (D_80109B8C >= 8) {
            ((struct gd_C_s32 *)sp18)->v = ((struct gd_C_s32 *)sp18)->v | 1;
        }
        return;
    }
    if ((((struct gd_A_u16 *)sp18)->v == 0x5004) || ((((struct gd_A_u16 *)sp18)->v == 0x5006) || ((((struct gd_A_u16 *)sp18)->v == 0x5505) || ((((struct gd_A_u16 *)sp18)->v == 0x4001) || ((((struct gd_A_u16 *)sp18)->v == 0x4002) || ((((struct gd_A_u16 *)sp18)->v == 0x2505) || ((((struct gd_A_u16 *)sp18)->v == 0x2005) || ((((struct gd_A_u16 *)sp18)->v == 0x2006) || ((((struct gd_A_u16 *)sp18)->v == 0x2009) || ((((struct gd_A_u16 *)sp18)->v == 0x4609) || (((struct gd_A_u16 *)sp18)->v == 0x1502))))))))))) {
        sp94 = 1;
    }
    if ((sp94 != 0) || (func_80012B60((sp18 + 36)) != 0)) {
        if ((((struct gd_A_u16 *)sp18)->v != 0x1015) && ((((struct gd_A_u16 *)sp18)->v != 0x7016) && ((((struct gd_A_u16 *)sp18)->v != 0x7017) && ((((struct gd_1E8_s32 *)sp18)->v != 0) && ((((struct gd_A_u16 *)sp18)->v != 0x1502) || (D_80075C30 != 0)))))) {
            if (((struct gd_A_u16 *)sp18)->v == 0x4002) {
                ((struct gd_1C_s32 *)((struct gd_1E8_s32 *)sp18)->v)->v = *(s32 *)((((struct gd_1D4_u8 *)sp18)->v * 4) + ((s32)&D_80075C34));
            }
            func_8001F1C8(((s32)&((struct n64dk_mE8_40 *)sp18)->m[D_80070760]), (sp18 + 36), ((struct { u8 pad[0x1A8]; struct V3 v; } *)sp18)->v);
            func_80001424(((s32)&D_80024C1C), sp18, ((struct gd_1F0_s32 *)sp18)->v, 1, ((f32)sp98));
        }
    }
}
