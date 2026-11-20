struct n64dk_e64 { u8 b[64]; };
extern s32 D_80001DE4;
extern s32 D_8006DD5C;
extern s32 D_80133E78;
s32 func_80001424();
s32 func_80068AA0();

void f(s32 arg0) {
    void *sp18;

    if ((u32)D_8006DD5C < 8) {
        sp18 = (void *)&((struct n64dk_e64 *)&D_80133E78)[D_8006DD5C];
        func_80068AA0(((s32)sp18), arg0);
        if (D_8006DD5C == 0) {
            func_80001424(((s32)&D_80001DE4), ((s32)sp18), 6, 0, 0);
        }
        D_8006DD5C++;
    }
}
