/* with the PI/SI access held, ensure the device is initialised once, run a call and return its result */
extern u8 D_801180A2;
extern char D_800ACBB0[];
void func_80062B44(void);
void func_80062BB0(void);
void func_8005DE44(void);
s32 func_80062A50(s32, void *);
s32 func_80057100(void *, s32, s32);
s32 func_8005DD20(void *mq)
{
    s32 ret;
    func_80062B44();
    if (D_801180A2 != 1) {
        func_8005DE44();
        func_80062A50(1, D_800ACBB0);
        func_80057100(mq, 0, 1);
    }
    ret = func_80062A50(0, D_800ACBB0);
    D_801180A2 = 1;
    func_80062BB0();
    return ret;
}
