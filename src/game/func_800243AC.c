#include "common.h"


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
            ((s32 (*)())func_8001F1C8)(((s32)&((struct n64dk_mE8_40 *)sp18)->m[D_80070760]), (sp18 + 36), ((struct { u8 pad[0x1A8]; struct V3 v; } *)sp18)->v);
            addActorDL(((s32)&D_80024C1C), sp18, ((struct gd_1F0_s32 *)sp18)->v, 1, ((f32)sp98));
        }
    }
}
