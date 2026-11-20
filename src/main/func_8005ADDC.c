/* if D_800776F0 is set, call func_8005B570 and clear it */
extern s32 D_800776F0;
void func_8005B570(void);
void func_8005ADDC(void)
{
    if (D_800776F0 != 0) {
        func_8005B570();
        D_800776F0 = 0;
    }
}
