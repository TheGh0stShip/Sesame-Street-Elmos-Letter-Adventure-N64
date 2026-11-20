
struct n64dk_m58_40 { u8 pad[0x58]; struct { u8 b[0x40]; } m[1]; };
struct gd_4_f32 { u8 pad[0x4]; f32 v; };
struct gd_8_f32 { u8 pad[0x8]; f32 v; };
struct gd_C_s32 { u8 pad[0xC]; s32 v; };
struct gd_28_f32 { u8 pad[0x28]; f32 v; };
struct gd_118_f32 { u8 pad[0x118]; f32 v; };
struct gd_118_f64 { u8 pad[0x118]; f64 v; };
struct gd_11C_f32 { u8 pad[0x11C]; f32 v; };
struct gd_120_f32 { u8 pad[0x120]; f32 v; };
struct gd_120_s32 { u8 pad[0x120]; s32 v; };
struct gd_124_s32 { u8 pad[0x124]; s32 v; };
struct gd_145_u8 { u8 pad[0x145]; u8 v; };
struct gd_160_s32 { u8 pad[0x160]; s32 v; };
struct gd_194_f32 { u8 pad[0x194]; f32 v; };
struct gd_198_f32 { u8 pad[0x198]; f32 v; };
extern s32 D_8003FC04;
extern s32 D_80070760;
extern f64 D_8007ADA8;
extern f64 D_8007ADB0;
extern f64 D_8007ADB8;
extern f64 D_8007ADC0;
extern f64 D_8007ADC8;
extern f64 D_8007ADD0;
extern f64 D_8007ADD8;
extern f64 D_8007ADE0;
extern f64 D_8007ADE8;
extern f64 D_8007ADF0;
extern u8 D_800ACC2E;
extern s32 D_80109B8C;
s32 func_80001424(s32, s32, s32, s32, f32);
struct V3 { f32 x, y, z; };
s32 func_8001F1C8();

void func_8003F838(s32 arg0) {
    s32 sp18;
    s32 pad0;
    s32 pad1[24];
    f32 sp80;
    f32 sp84;
    f32 sp88;
    s32 pad2;
    f32 sp90;
    f32 sp94;
    f32 sp98;
    s32 pad3;
    s32 pad4[10];
    f64 spC8;

    sp18 = arg0;
    spC8 = 0.0;
    if (D_800ACC2E == 0) {
        return;
    }
    ((struct gd_124_s32 *)sp18)->v++;
    sp18 = arg0;
    if (D_80109B8C >= 5) {
        if (D_80109B8C >= 8) {
            ((struct gd_C_s32 *)sp18)->v = ((struct gd_C_s32 *)sp18)->v | 1;
        }
        return;
    }
    if (((f64)((struct gd_28_f32 *)sp18)->v) > D_8007ADA8) {
        ((struct gd_C_s32 *)sp18)->v = ((struct gd_C_s32 *)sp18)->v | 1;
        return;
    }
    sp90 = *(f32 *)(sp18 + 36);
    sp94 = ((struct gd_4_f32 *)(sp18 + 36))->v;
    sp98 = ((struct gd_8_f32 *)(sp18 + 36))->v;
    sp80 = *(f32 *)(sp18 + 48);
    sp84 = ((struct gd_4_f32 *)(sp18 + 48))->v;
    sp88 = ((struct gd_8_f32 *)(sp18 + 48))->v;
    ((struct gd_198_f32 *)sp18)->v = (f32)(((f64)((struct gd_198_f32 *)sp18)->v) + D_8007ADB0);
    sp94 = sp94 + ((struct gd_198_f32 *)sp18)->v;
    switch (((struct gd_145_u8 *)sp18)->v) {
    case 0:
        ((struct gd_194_f32 *)sp18)->v = (f32)(((f64)((struct gd_194_f32 *)sp18)->v) + D_8007ADB8);
        sp90 = sp90 + ((struct gd_194_f32 *)sp18)->v;
        break;
    case 1:
        break;
    case 2:
        ((struct gd_194_f32 *)sp18)->v = (f32)(((f64)((struct gd_194_f32 *)sp18)->v) - D_8007ADC0);
        sp90 = sp90 + ((struct gd_194_f32 *)sp18)->v;
        break;
    default:
        break;
    }
    if (((f64)((struct gd_118_f32 *)sp18)->v) < D_8007ADC8) {
        ((struct gd_118_f32 *)sp18)->v = (f32)(((f64)((struct gd_118_f32 *)sp18)->v) + D_8007ADD0);
    }
    if (((f64)((struct gd_11C_f32 *)sp18)->v) < D_8007ADD8) {
        ((struct gd_11C_f32 *)sp18)->v = (f32)(((f64)((struct gd_11C_f32 *)sp18)->v) + D_8007ADE0);
    }
    if (((f64)((struct gd_120_f32 *)sp18)->v) < D_8007ADE8) {
        ((struct gd_120_f32 *)sp18)->v = (f32)(((f64)((struct gd_120_f32 *)sp18)->v) + D_8007ADF0);
    }
    (*(f32 *)(sp18 + 36)) = sp90;
    ((struct gd_4_f32 *)(sp18 + 36))->v = sp94;
    ((struct gd_8_f32 *)(sp18 + 36))->v = sp98;
    func_8001F1C8(((s32)&((struct n64dk_m58_40 *)sp18)->m[D_80070760]), (sp18 + 36), ((struct { u8 pad[0x118]; struct V3 v; } *)sp18)->v);
    func_80001424(((s32)&D_8003FC04), sp18, ((struct gd_160_s32 *)sp18)->v, 1, ((f32)spC8));
}
