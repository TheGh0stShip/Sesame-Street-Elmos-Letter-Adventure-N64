extern s32 D_800A8D38;

s32 f(void) {
    D_800A8D38 = D_800A8D38 + 16;
    D_800A8D38 = D_800A8D38 | 15;
    return D_800A8D38;
}
