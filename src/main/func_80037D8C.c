struct gd_4_f32 { u8 pad[0x4]; f32 v; };
struct gd_8_f32 { u8 pad[0x8]; f32 v; };
struct gd_200_s32 { u8 pad[0x200]; s32 v; };
extern s8 D_8007635C;
s32 func_80035750();

void f(s32 arg0) {
    func_80035750(arg0);
    D_8007635C = 0;
    ((struct gd_200_s32 *)arg0)->v = ((struct gd_200_s32 *)arg0)->v & -2;
    ((struct gd_200_s32 *)arg0)->v = ((struct gd_200_s32 *)arg0)->v & -3;
    ((struct gd_200_s32 *)arg0)->v = ((struct gd_200_s32 *)arg0)->v | 4;
    (*(f32 *)(arg0 + 536)) = *(f32 *)(arg0 + 36);
    ((struct gd_4_f32 *)(arg0 + 536))->v = ((struct gd_4_f32 *)(arg0 + 36))->v;
    ((struct gd_8_f32 *)(arg0 + 536))->v = ((struct gd_8_f32 *)(arg0 + 36))->v;
}
