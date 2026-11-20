struct n64dk_a8006DD18 { s32 m0; u8 pad4[0x4]; };
extern struct n64dk_a8006DD18 D_8006DD18[];
extern s32 D_8006DD58;
extern s32 D_8006DD5C;

void f(void) {
    s32 sp0;

    D_8006DD58 = 0;
    D_8006DD5C = 0;
    sp0 = 0;
    while (!(sp0 >= 8)) {
        D_8006DD18[sp0].m0 = 0;
        sp0++;
    }
}
