extern s16 D_800A7AA8;
extern u8 D_800ACC2D;
extern s32 D_80115258;
extern s32 D_80115374;
extern s32 D_8013ED88;
s32 func_80057230();

void f(s32 arg0, s32 arg1) {
    D_80115258 = arg1;
    D_80115374 = arg0;
    func_80057230(((s32)&D_8013ED88), 0, 1);
    D_800A7AA8 = 0;
    D_800ACC2D++;
}
