extern s32 D_80071E40;
extern s32 D_80071E44;
extern s32 D_80071E4C;
extern s32 D_80071E5C;

s32 f(s32 arg0) {
    s32 sp0;

    if (D_80071E5C == 0) {
        return -1;
    }
    sp0 = (*(s32 *)((D_80071E4C * 4) + D_80071E44)) % arg0;
    D_80071E4C++;
    D_80071E4C = D_80071E4C % D_80071E40;
    return sp0;
}
