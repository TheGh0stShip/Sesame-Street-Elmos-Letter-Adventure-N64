extern s32 D_8006D500;
extern s32 D_8007BAE0;
extern s16 D_8007BB08;
extern s8 D_800A8D3E;
extern s32 D_8010E490;
s32 func_80056C40();
s32 func_80057360();
s32 func_8005DF00();

void f(void) {
    s32 sp10[6];
    s32 sp28;
    s32 sp2C;

    D_800A8D3E = 3;
    func_80056C40(((s32)&sp10), ((s32)&sp28), 1);
    func_80057360(5, ((s32)&sp10), 1);
    sp2C = func_8005DF00(((s32)&sp10), ((s32)&D_8006D500), ((s32)&D_8007BAE0));
    if (sp2C != 0) {
    }
    D_8007BB08 = 5;
    func_80057360(5, ((s32)&D_8010E490), ((s32)&D_8007BB08));
}
