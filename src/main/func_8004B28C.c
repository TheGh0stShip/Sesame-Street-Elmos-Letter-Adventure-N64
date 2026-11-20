struct gd_4_f32 { u8 pad[0x4]; f32 v; };
struct gd_8_f32 { u8 pad[0x8]; f32 v; };
struct gd_C_f32 { u8 pad[0xC]; f32 v; };
struct gd_10_f32 { u8 pad[0x10]; f32 v; };
struct gd_14_f32 { u8 pad[0x14]; f32 v; };
struct gd_18_f32 { u8 pad[0x18]; f32 v; };
extern f64 D_8007B038;
extern f64 D_8007B040;
extern f64 D_8007B048;
extern f64 D_8007B050;
extern f64 D_8007B058;
extern f64 D_8007B060;
extern f64 D_8007B068;
s32 func_8005F50C();

void f(s32 arg0, s32 arg1, s32 arg2) {
    register s32 reg_s0;

    reg_s0 = arg0;
    func_8005F50C(arg2, arg1, 40);
    ((struct gd_4_f32 *)reg_s0)->v = (f32)(((f64)((struct gd_4_f32 *)reg_s0)->v) - (((f64)((struct gd_8_f32 *)reg_s0)->v) * D_8007B038));
    ((struct gd_C_f32 *)reg_s0)->v = (f32)(((f64)((struct gd_C_f32 *)reg_s0)->v) + (((f64)((struct gd_10_f32 *)reg_s0)->v) * D_8007B040));
    if (((f64)((struct gd_C_f32 *)reg_s0)->v) > D_8007B048) {
        ((struct gd_C_f32 *)reg_s0)->v = 1.2566371f;
    } else {
        if (((f64)((struct gd_C_f32 *)reg_s0)->v) < D_8007B050) {
            ((struct gd_C_f32 *)reg_s0)->v = -0.31415927f;
        }
    }
    ((struct gd_14_f32 *)reg_s0)->v = (f32)(((f64)((struct gd_18_f32 *)reg_s0)->v) * D_8007B058);
    ((struct gd_C_f32 *)arg2)->v = ((struct gd_C_f32 *)arg2)->v + ((struct gd_14_f32 *)reg_s0)->v;
    ((struct gd_10_f32 *)arg2)->v = ((struct gd_10_f32 *)arg2)->v + ((struct gd_C_f32 *)reg_s0)->v;
    ((struct gd_18_f32 *)arg2)->v = ((struct gd_18_f32 *)arg2)->v + ((struct gd_4_f32 *)reg_s0)->v;
    if (((f64)((struct gd_18_f32 *)arg2)->v) > D_8007B060) {
        ((struct gd_18_f32 *)arg2)->v = 1.25e+04f;
        return;
    }
    if (((f64)((struct gd_18_f32 *)arg2)->v) < D_8007B068) {
        ((struct gd_18_f32 *)arg2)->v = 1e+01f;
    }
}
