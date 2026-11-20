s32 func_8000E7A0();

void f(s32 arg0) {
    for (;;) {
        if ((*(u8 *)arg0) == 0) {
            return;
        }
        func_8000E7A0((*(u8 *)(arg0++)));
    }
}
