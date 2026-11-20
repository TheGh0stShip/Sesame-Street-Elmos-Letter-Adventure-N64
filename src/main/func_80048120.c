s32 func_80040680();
s32 func_80049A24();
s32 func_80049C6C();

void f(s32 arg0) {
    if (arg0 == 0) {
        return;
    }
    func_80049A24(arg0);
    func_80049C6C(arg0);
    func_80040680(arg0);
}
