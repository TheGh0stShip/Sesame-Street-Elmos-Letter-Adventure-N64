

struct n64dk_mE8_40 { u8 pad[0xE8]; struct { u8 b[0x40]; } m[1]; };
struct gd_C_s32 { u8 pad[0xC]; s32 v; };
struct gd_28_f32 { u8 pad[0x28]; f32 v; };
typedef struct { s32 a, b, c; } Trip;
struct gd_1A8_t { u8 pad[0x1A8]; Trip v; };
struct gd_1B0_s32 { u8 pad[0x1B0]; s32 v; };
struct gd_1F0_s32 { u8 pad[0x1F0]; s32 v; };
extern s32 D_80024C1C;
extern s32 D_80070760;
extern s32 D_80073160;
extern f64 D_8007A050;
extern u8 D_800ACC2E;
extern s32 D_80109B8C;
extern f32 D_8010E48C;
extern u8 D_80115370;
extern s32 D_8011537C;
s32 func_80001424(s32, s32, s32, s32, f32);
s32 func_8001F1C8();
f64 func_80022D8C();

void f(s32 arg0) {
    s32 sp18;
    s32 pad0;
    s32 pad1[2];
    s8 pad2;

    sp18 = arg0;
    sp18 = arg0;
    if (D_800ACC2E == 0) {
        if (D_8011537C < 0) {
            ((struct gd_C_s32 *)sp18)->v = ((struct gd_C_s32 *)sp18)->v | 1;
        }
        return;
    }
    if (D_80109B8C >= 5) {
        if (D_80109B8C >= 8) {
            ((struct gd_C_s32 *)sp18)->v = ((struct gd_C_s32 *)sp18)->v | 1;
        }
        return;
    }
    D_80115370 = D_80115370 + 4;
    D_8010E48C = (f32)(((f64)(*(f32 *)(((((u32)D_80115370 >> 3) & 255) * 4) + ((s32)&D_80073160)))) * D_8007A050);
    ((struct gd_28_f32 *)sp18)->v = ((struct gd_28_f32 *)sp18)->v + D_8010E48C;
    func_8001F1C8(((s32)&((struct n64dk_mE8_40 *)sp18)->m[D_80070760]), (sp18 + 36), ((struct gd_1A8_t *)sp18)->v);
    ((struct gd_28_f32 *)sp18)->v = ((struct gd_28_f32 *)sp18)->v - D_8010E48C;
    func_80001424(((s32)&D_80024C1C), sp18, ((struct gd_1F0_s32 *)sp18)->v, 1, ((f32)func_80022D8C((sp18 + 36))));
}
