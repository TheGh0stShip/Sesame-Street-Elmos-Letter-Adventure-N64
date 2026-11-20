extern s32 D_8006DD58;
extern s32 D_80108B24;
extern s16 D_801201A8;
extern s32 D_801201C8;
extern s16 D_80128278;
extern s32 D_80128298;
extern s32 D_80200000;
extern s32 D_80225800;
s32 func_8005DAB0();

void f(void) {
    D_801201A8 = 6;
    D_801201C8 = (s32)&D_80200000;
    D_80128278 = 7;
    D_80128298 = (s32)&D_80225800;
    func_8005DAB0(66);
    D_80108B24 = 1;
    D_8006DD58 = 0;
}
