struct gd_4_s32 { u8 pad[0x4]; s32 v; };
struct n64dk_e8 { u8 b[8]; };
struct n64dk_e64 { u8 b[64]; };
extern s32 D_8006DD5C;
extern s32 D_800749A0;
extern s32 D_80133E78;
extern struct n64dk_e8 *D_8013EB0C;
s32 func_8000DBC0();
s32 func_8000DCFC();
s32 func_8000DD7C();
s32 func_8000DDF4();
s32 func_8000DE60();
s32 func_8000DEBC();

void f(s32 arg0) {
    void *sp10;
    s32 sp14;
    s32 sp18;
    s32 sp1C;
    s32 sp20;

    sp18 = 16;
    sp14 = func_8000DBC0();
    func_8000DE60(1);
    func_8000DDF4(255, 255, 255, 255);
    sp1C = 0;
    while (!((u32)sp1C >= (u32)D_8006DD5C)) {
        sp10 = (void *)&((struct n64dk_e64 *)&D_80133E78)[sp1C];
        func_8000DD7C(72, sp18);
        sp18 = sp18 + 16;
        func_8000DEBC(((s32)sp10));
        sp1C++;
    }
    sp20 = (s32)D_8013EB0C++;
    (*(s32 *)sp20) = 0x6000000;
    ((struct gd_4_s32 *)sp20)->v = (s32)&D_800749A0;
    func_8000DCFC(sp14);
}
