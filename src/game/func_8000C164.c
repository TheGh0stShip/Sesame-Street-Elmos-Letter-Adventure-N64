#include "common.h"

s32 osCreateScheduler();
s32 osScAddClient();
s32 func_8005FB50();

void func_8000C164(void) {
    osCreateMesgQueue(((s32)&D_80082B88), ((s32)&D_80082BA0), 1);
    osCreateMesgQueue(((s32)&D_8010E490), ((s32)&D_80109B08), 32);
    osCreateMesgQueue(((s32)&D_801078F8), ((s32)&D_80109C50), 8);
    if (D_80000300 == 1) {
        osCreateScheduler(((s32)&D_80108B28), ((s32)&D_80140F70), 240, 2, 1);
    } else if (D_80000300 == 2) {
        osCreateScheduler(((s32)&D_80108B28), ((s32)&D_80140F70), 240, 30, 1);
    } else {
    spin:
        for (;;) {
        }
    }
    osScAddClient(((s32)&D_80108B28), ((s32)&D_800ACBA4), ((s32)&D_8010E490));
    D_800A7AA4 = func_8005FB50(((s32)&D_80108B28));
    osScAddClient(((s32)&D_80108B28), ((s32)&D_801283D8), ((s32)&D_80133E40));
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
    (*(f32 (*))&D_80108DB4) = 4e+01f;
    func_80000F60();
    func_80018840();
    func_80001EE8();
    func_800170B0();
    D_8010688C = 0;
}
