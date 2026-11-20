extern s32 D_80071E40;
extern s32 D_80071E4C;
extern s32 D_80071E50;
extern s32 D_80071E54;
extern s32 D_80071E58;
extern s32 D_80071E5C;

s32 f(s32 arg0) {
    s32 sp0;

    if (D_80071E5C == 0) {
        return -1;
    }
    if ((arg0 == D_80071E4C) || (arg0 == D_80071E50)) {
        return 0;
    }
    if ((arg0 < 0) || (arg0 > D_80071E40)) {
        arg0 = 0;
    }
    sp0 = D_80071E4C;
    D_80071E50 = D_80071E58 = arg0;
    D_80071E4C = D_80071E54 = arg0;
    return sp0;
}
