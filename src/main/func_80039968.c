struct gd_1D8_f32 { u8 pad[0x1D8]; f32 v; };
extern f64 D_8007ABA8;
extern s16 D_800A7AFA;
extern u16 D_801078BA;
extern u8 D_801078F0;
extern s8 D_8012EFCC;
s32 func_80035828();

void f(s32 arg0) {
    if (((f64)((struct gd_1D8_f32 *)arg0)->v) > D_8007ABA8) {
        func_80035828(arg0, 23);
    }
    if (((D_801078BA & 0x1000) & 0xFFFF) != 0) {
        if (D_801078F0 != 0) {
            D_8012EFCC = 1;
            D_800A7AFA = 0;
        } else {
        }
    }
}
