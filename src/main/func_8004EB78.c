/* random number in [0, range) from a shift-register seed */
extern s32 D_800A00F4;
s32 func_8004EB78(s32 range)
{
    s32 i;
    s32 t;
    for (i = 0; i < 8; i++) {
        t = D_800A00F4 & 0x48000000;
        D_800A00F4 = D_800A00F4 << 1;
        if (t == 0x48000000 || t == 0x08000000) {
            D_800A00F4 |= 1;
        }
    }
    return range * ((f32)D_800A00F4 / 65536.0f / 65536.0f);
}
