struct gd_4_f32 { u8 pad[0x4]; f32 v; };
struct gd_8_f32 { u8 pad[0x8]; f32 v; };
struct gd_C_s32 { u8 pad[0xC]; s32 v; };
struct gd_200_s32 { u8 pad[0x200]; s32 v; };
extern s32 D_80073310;
extern s32 D_80073320;
extern u8 D_800A75EE;
extern s32 D_80115374;
extern s32 D_8013ED88;
s32 func_800356D0();
s32 func_80035750();
s32 func_80057230();

void f(s32 arg0) {
    func_80035750(arg0);
    if (D_800A75EE == 0) {
        if (D_80115374 == 0) {
            D_80115374 = (s32)&D_80073310;
            func_80057230(((s32)&D_8013ED88), 0, 1);
        }
        func_800356D0(arg0, 10);
        D_800A75EE = 1;
    } else {
        if (D_80115374 == 0) {
            D_80115374 = (s32)&D_80073320;
            func_80057230(((s32)&D_8013ED88), 0, 1);
        }
        func_800356D0(arg0, 12);
    }
    ((struct gd_C_s32 *)arg0)->v = ((struct gd_C_s32 *)arg0)->v | 128;
    ((struct gd_200_s32 *)arg0)->v = ((struct gd_200_s32 *)arg0)->v & -2;
    ((struct gd_200_s32 *)arg0)->v = ((struct gd_200_s32 *)arg0)->v & -3;
    ((struct gd_200_s32 *)arg0)->v = ((struct gd_200_s32 *)arg0)->v | 4;
    (*(f32 *)(arg0 + 536)) = *(f32 *)(arg0 + 36);
    ((struct gd_4_f32 *)(arg0 + 536))->v = ((struct gd_4_f32 *)(arg0 + 36))->v;
    ((struct gd_8_f32 *)(arg0 + 536))->v = ((struct gd_8_f32 *)(arg0 + 36))->v;
}
