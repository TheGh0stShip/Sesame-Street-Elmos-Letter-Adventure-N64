struct gd_F0_s32 { u8 pad[0xF0]; s32 v; };
extern s32 D_80106888;
s32 func_80040680();

void f(s32 arg0) {
    s32 sp10;

    sp10 = arg0;
    func_80040680(((struct gd_F0_s32 *)sp10)->v);
    D_80106888 = 0;
    func_80040680(sp10);
    return;
}
