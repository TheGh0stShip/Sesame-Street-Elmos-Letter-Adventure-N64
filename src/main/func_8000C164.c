extern s32 D_80000300;
extern s32 D_80082B88;
extern s32 D_80082BA0;
extern s8 D_800A75EC;
extern s8 D_800A75ED;
extern s8 D_800A75EE;
extern s32 D_800A7AA4;
extern s32 D_800A8DE0;
extern s32 D_800ACBA4;
extern s8 D_800B0C90;
extern s16 D_800B0C92;
extern s8 D_800B0C98;
extern s8 D_8010686C;
extern s32 D_80106880;
extern s32 D_80106888;
extern s32 D_8010688C;
extern s8 D_801078D8;
extern s32 D_801078F8;
extern s32 D_80108B28;
extern f32 D_80108DB4;
extern s32 D_80109B08;
extern s8 D_80109C48;
extern s32 D_80109C50;
extern s8 D_80109C78;
extern s32 D_8010E490;
extern s32 D_80115254;
extern s32 D_8011525C;
extern s32 D_801282A0;
extern s32 D_801283D8;
extern s8 D_8012EFCD;
extern s32 D_8012EFD0;
extern s32 D_80133E40;
extern s16 D_8013C650;
extern s32 D_80140F70;
s32 func_80000F60();
s32 func_80001EE8();
s32 func_800170B0();
s32 func_80018840();
s32 func_8003FDD0();
s32 func_800409A0();
s32 func_80056C40();
s32 func_8005F920();
s32 func_8005FA68();
s32 func_8005FB50();

void func_8000C164(void) {
    func_80056C40(((s32)&D_80082B88), ((s32)&D_80082BA0), 1);
    func_80056C40(((s32)&D_8010E490), ((s32)&D_80109B08), 32);
    func_80056C40(((s32)&D_801078F8), ((s32)&D_80109C50), 8);
    if (D_80000300 == 1) {
        func_8005F920(((s32)&D_80108B28), ((s32)&D_80140F70), 240, 2, 1);
    } else if (D_80000300 == 2) {
        func_8005F920(((s32)&D_80108B28), ((s32)&D_80140F70), 240, 30, 1);
    } else {
    spin:
        for (;;) {
        }
    }
    func_8005FA68(((s32)&D_80108B28), ((s32)&D_800ACBA4), ((s32)&D_8010E490));
    D_800A7AA4 = func_8005FB50(((s32)&D_80108B28));
    func_8005FA68(((s32)&D_80108B28), ((s32)&D_801283D8), ((s32)&D_80133E40));
    func_800409A0();
    D_8011525C = (s32)&D_800A8DE0;
    func_8003FDD0(D_8011525C);
    D_8012EFD0 = 19;
    D_801282A0 = 255;
    D_80109C48 = 0;
    D_80115254 = 0;
    D_80106880 = 0;
    D_80106888 = 0;
    D_8010686C = 0;
    D_8013C650 = 0;
    D_800A75EE = 0;
    D_80109C78 = 0;
    D_800A75ED = 0;
    D_800B0C98 = 0;
    D_800B0C90 = 0;
    D_801078D8 = 0;
    D_8012EFCD = 0;
    D_800A75EC = 0;
    D_800B0C92 = 240;
    D_80108DB4 = 4e+01f;
    func_80000F60();
    func_80018840();
    func_80001EE8();
    func_800170B0();
    D_8010688C = 0;
}
