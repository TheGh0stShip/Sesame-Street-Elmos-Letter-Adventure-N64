extern u64 func_80056D40(void);
extern u64 func_80068FC0(u64, u64);
extern s64 D_80082BC8; extern u64 D_80082BB8, D_80082BB0, D_80082BC0, D_80082BD0;
extern s32 D_80109BA0, D_80109BA4, D_80107914, D_80133E34, D_8011524C;
extern s32 D_80070774, D_80070778, D_80070780, D_8007077C, D_80070790, D_80070784, D_8007078C, D_80070770;
/* resets timers from the current time divided by 46875 and clears state */
void func_8000CF50(void) {
    D_80082BC0 = D_80082BB0 = D_80082BB8 = D_80082BC8 = func_80068FC0(func_80056D40(), 46875);
    D_80082BD0 = 0;
    D_80109BA0 = 0;
    D_80109BA4 = 0;
    D_80107914 = 0;
    D_80133E34 = 0;
    D_8011524C = 0;
    D_80070774 = 0;
    D_80070778 = 0;
    D_80070780 = 0;
    D_8007077C = 0;
    D_80070790 = 0;
    D_80070784 = 0;
    D_8007078C = 0;
    D_80070770 = 1;
}
