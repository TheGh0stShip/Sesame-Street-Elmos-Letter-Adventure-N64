struct gd_200_s32 { u8 pad[0x200]; s32 v; };
s32 func_80035828();

void f(s32 arg0) {
    ((struct gd_200_s32 *)arg0)->v = ((struct gd_200_s32 *)arg0)->v & 0xFFFEFFFF;
    func_80035828(arg0, 29);
}
