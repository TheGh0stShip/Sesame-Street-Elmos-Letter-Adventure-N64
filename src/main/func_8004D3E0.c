typedef struct { s8 unk_00; s32 unk_04; } Msg;
extern s32 D_800A0100;
extern s32 D_800A0104;
s32 func_8004D6D4(Msg *);
void func_8004D3E0(s32 arg0) {
    Msg m;
    s32 ok = 1;
    if (arg0 == 0) {
        m.unk_00 = 2;
        m.unk_04 = D_800A0104;
        D_800A0104 = m.unk_04;
        ok = func_8004D6D4(&m);
    }
    if (ok) {
        D_800A0100 = arg0;
    }
    return;
}
