extern u8 D_800ACC2C;
extern s32 D_80109B90;
extern s32 D_80133E40;
s32 func_8004CDC8();
s32 func_80056C40();
s32 func_80057100();

void f(s32 arg0) {
    s32 sp10;

    sp10 = 0;
    func_80056C40(((s32)&D_80133E40), ((s32)&D_80109B90), 1);
    for (;;) {
        goto L9;
        return;
L9: ;
        func_80057100(((s32)&D_80133E40), ((s32)&sp10), 1);
        if ((*(s16 *)sp10) == 4) {
            if (D_800ACC2C == 0) {
                D_800ACC2C = 1;
                func_8004CDC8(3, 4);
            }
        }
    }
}
