struct gd_C_s32 { u8 pad[0xC]; s32 v; };
struct gd_200_s32 { u8 pad[0x200]; s32 v; };
extern s32 D_80109B8C;
s32 func_800356D0();

void f(s32 arg0) {
    func_800356D0(arg0, 2);
    ((struct gd_C_s32 *)arg0)->v = ((struct gd_C_s32 *)arg0)->v | 128;
    if (D_80109B8C == 0) {
        ((struct gd_200_s32 *)arg0)->v = ((struct gd_200_s32 *)arg0)->v & -3;
    }
    ((struct gd_200_s32 *)arg0)->v = ((struct gd_200_s32 *)arg0)->v | 4;
}
