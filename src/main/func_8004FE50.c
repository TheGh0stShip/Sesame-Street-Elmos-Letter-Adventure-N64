void func_800505A0(s32);
void func_8004FEB8(s32);
extern s32 D_800773B0;
extern s32 D_800773B4;
extern s32 D_8013C588;

/* first-time setup: stores arg0, then initialises once with arg1 */
void func_8004FE50(s32 arg0, s32 arg1) {
    if (D_800773B0 == 0) {
        D_800773B0 = arg0;
        if (D_800773B4 == 0) {
            func_800505A0(arg1);
            D_8013C588 = D_800773B0;
            D_800773B4 = D_800773B0;
            func_8004FEB8(arg1);
        }
    }
}
