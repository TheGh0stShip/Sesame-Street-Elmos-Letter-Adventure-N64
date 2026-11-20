extern u16 D_800A7AF8;
extern s32 D_800A7AFC;
extern s32 D_80108B24;
extern s32 D_80109B8C;
extern s16 D_80109C40;
extern s32 D_80115180;
extern s32 D_8011518C;
extern s32 D_801151A4;
extern s32 D_801151A8;
extern s32 D_801151AC;
extern s32 D_801151B0;
extern s32 D_8011525C;
s32 func_800174AC();
s32 func_8003FE00();
s32 func_8004002C();
s32 func_8004038C();
s32 func_8004CF14();
s32 func_80051418();

void f(s32 arg0) {
    D_80109C40 = 0;
    D_80108B24 = 0;
    func_800174AC();
    if (D_800A7AFC != 0) {
        func_8004CF14(D_800A7AFC);
    }
    func_80051418(D_800A7AF8);
    D_80109B8C = 8;
    func_8004038C(D_8011525C);
    D_801151A8 = arg0;
    D_801151A4 = 0;
    D_801151AC = 20;
    D_801151B0 = 2;
    D_8011518C = 0;
    if (func_8004002C((*(s32 *)D_8011525C), 3, 0xFFFF) == 0) {
        func_8003FE00(((s32)&D_80115180), D_8011525C, 3, 0);
    }
}
