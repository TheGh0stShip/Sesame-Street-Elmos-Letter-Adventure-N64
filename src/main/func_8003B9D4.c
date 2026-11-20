struct gd_C_s32 { u8 pad[0xC]; s32 v; };
struct gd_200_s32 { u8 pad[0x200]; s32 v; };
s32 func_800356D0();
s32 func_80035750();

void f(s32 arg0) {
    s8 pad0;

    func_80035750(arg0);
    func_800356D0(arg0, 5);
    ((struct gd_C_s32 *)arg0)->v = ((struct gd_C_s32 *)arg0)->v | 128;
    ((struct gd_200_s32 *)arg0)->v = ((struct gd_200_s32 *)arg0)->v | 1;
    ((struct gd_200_s32 *)arg0)->v = ((struct gd_200_s32 *)arg0)->v | 2;
    ((struct gd_200_s32 *)arg0)->v = ((struct gd_200_s32 *)arg0)->v | 4;
}
