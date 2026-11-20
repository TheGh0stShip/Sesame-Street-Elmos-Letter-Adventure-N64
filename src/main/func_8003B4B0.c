extern s32 D_80115374;
extern u8 D_801282A3;
extern s32 D_8012FCE0;
s32 func_8001D8E0();
s32 func_8005DC20();

void f(s32 arg0) {
    if ((u32)D_801282A3 < 240) {
        D_801282A3 = D_801282A3 + 16;
        return;
    }
    D_801282A3 = 255;
    func_8005DC20(1);
    if (D_80115374 == 0) {
        if (D_8012FCE0 == 22) {
            func_8001D8E0(18);
            return;
        }
        func_8001D8E0(12);
    }
}
