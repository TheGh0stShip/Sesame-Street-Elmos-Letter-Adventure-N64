struct gd_1CC_s32 { u8 pad[0x1CC]; s32 v; };
extern u8 D_80075E2F;
extern s32 D_80109B8C;
s32 func_80035828();

void f(s32 arg0) {
    s32 pad0[2];
    s8 pad1;

    ((struct gd_1CC_s32 *)arg0)->v++;
    if (D_80109B8C == 0) {
        return;
    }
    if (D_80075E2F != 0) {
        func_80035828(arg0, 6);
    }
}
