extern s32 D_80022A9C;
extern u8 D_800ACC2E;
s32 func_80001424();

void f(s32 arg0) {
    if (D_800ACC2E == 0) {
        return;
    }
    func_80001424(((s32)&D_80022A9C), arg0, 1, 0, 0);
}
