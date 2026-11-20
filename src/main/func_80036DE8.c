/* Selects letter/number table pointers on first use, then sets object flags and copies position to 0x218. */


struct gd_4_f32 { u8 pad[0x4]; f32 v; };
struct gd_8_f32 { u8 pad[0x8]; f32 v; };
struct gd_C_s32 { u8 pad[0xC]; s32 v; };
struct gd_1F0_s8 { u8 pad[0x1F0]; s8 v; };
struct gd_200_s32 { u8 pad[0x200]; s32 v; };
extern s32 D_80073708;
extern struct { s32 a, b; } D_80073EE0[];
extern struct { s32 a, b; } D_80073FF0[];
extern struct { s32 a, b; } D_80074100[];
extern struct { s32 a, b; } D_800742A8[];
extern u8 D_800745F4;
extern u8 D_800745F5;
extern u8 D_80106870;
extern s32 D_80115258;
extern s32 D_80115374;
extern s32 D_8013E680;
extern s32 D_8013ED88;
s32 func_800356D0();
s32 func_80035750();
s32 func_80057230();

void f(s32 arg0) {
    func_80035750(arg0);
    if (D_80115374 == 0) {
        if (D_80106870 == 0) {
            D_80115258 = (s32)&D_80073EE0[D_800745F4];
            D_8013E680 = (s32)&D_80073FF0[D_800745F5];
            D_80115374 = (s32)&D_80073708;
        } else {
            D_80115258 = (s32)&D_80074100[D_800745F4];
            D_8013E680 = (s32)&D_800742A8[D_800745F5];
            D_80115374 = (s32)&D_80073708;
        }
        func_80057230(((s32)&D_8013ED88), 0, 1);
    }
    func_800356D0(arg0, 19);
    ((struct gd_C_s32 *)arg0)->v = ((struct gd_C_s32 *)arg0)->v | 128;
    ((struct gd_200_s32 *)arg0)->v = ((struct gd_200_s32 *)arg0)->v & -2;
    ((struct gd_200_s32 *)arg0)->v = ((struct gd_200_s32 *)arg0)->v & -3;
    ((struct gd_200_s32 *)arg0)->v = ((struct gd_200_s32 *)arg0)->v | 4;
    (*(f32 *)(arg0 + 536)) = *(f32 *)(arg0 + 36);
    ((struct gd_4_f32 *)(arg0 + 536))->v = ((struct gd_4_f32 *)(arg0 + 36))->v;
    ((struct gd_8_f32 *)(arg0 + 536))->v = ((struct gd_8_f32 *)(arg0 + 36))->v;
    ((struct gd_1F0_s8 *)arg0)->v = 3;
}
