struct gd_8_f32 { u8 pad[0x8]; f32 v; };
struct gd_C_f32 { u8 pad[0xC]; f32 v; };
struct gd_10_f32 { u8 pad[0x10]; f32 v; };
s32 func_80040400();
s32 func_80068300();

s32 f(s32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    register s32 reg_s0;

    reg_s0 = func_80040400(20);
    func_80068300(reg_s0, 0, 20);
    (*(s32 *)reg_s0) = arg0;
    ((struct gd_8_f32 *)reg_s0)->v = arg1;
    ((struct gd_C_f32 *)reg_s0)->v = arg2;
    ((struct gd_10_f32 *)reg_s0)->v = arg3;
    return reg_s0;
}
