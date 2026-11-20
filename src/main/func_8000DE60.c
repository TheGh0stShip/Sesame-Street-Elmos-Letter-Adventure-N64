extern s32 D_80071D08;
s32 func_8005B640();
s32 func_8005B6E0();

void f(s32 arg0) {
    if (arg0 != 0) {
        func_8005B6E0(((s32)&D_80071D08), 3);
        return;
    }
    func_8005B640(((s32)&D_80071D08), 3);
}
