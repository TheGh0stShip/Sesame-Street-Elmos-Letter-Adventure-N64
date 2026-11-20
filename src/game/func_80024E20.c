#include "common.h"


void func_80024E20(s32 arg0) {
    s32 sp10;
    s32 sp14;

    sp10 = arg0;
    if ((*(s32 *)sp10) == 4) {
        goto L13;
    }
    func_80057BD0(((s32)&D_8007A060), ((s32)&D_8007A064), 365);
L13: ;
    sp14 = func_80040400(80);
    switch (sp14) {
    case 0:
        func_80057BD0(((s32)&D_8007A060), ((s32)&D_8007A064), 369);
    }
    ((struct gd_10_s32 *)sp14)->v = (s32)&D_8002614C;
    ((struct gd_14_s32 *)sp14)->v = (s32)&D_800268DC;
    ((struct gd_18_s32 *)sp14)->v = 0;
    ((struct gd_1C_s32 *)sp14)->v = 0;
    ((struct gd_20_s32 *)sp14)->v = 0;
    ((struct gd_8_s16 *)sp14)->v = ((struct gd_2_u16 *)sp10)->v;
    ((struct gd_A_s16 *)sp14)->v = ((struct gd_6_u16 *)sp10)->v;
    ((struct gd_C_s32 *)sp14)->v = ((struct gd_8_s32 *)sp10)->v;
    ((struct gd_24_s32 *)sp14)->v = 0;
    ((struct gd_40_s32 *)sp14)->v = 0;
    ((struct gd_48_s32 *)sp14)->v = 0;
    ((struct gd_4C_s16 *)sp14)->v = (func_80020D30() & 180) + 60;
    D_800BD460 = 0;
    D_80115264 = 0;
    D_8013C654 = 0;
    D_800B0C94 = 0;
    func_8003FE00(sp14, D_8011525C, 4, 0);
    if (D_800ACC2C == 0) {
        switch (D_8012EFD0) {
        case 2:
            ((struct gd_44_s32 *)sp14)->v = func_80017568(9);
            func_800445D0(((s32)&D_801A9B08), ((s32)&D_801A9AFC), 2, 0);
            return;
        case 19:
            ((struct gd_44_s32 *)sp14)->v = func_80017568(20);
            func_800445D0(((s32)&D_80164C80), ((s32)&D_80164C74), 2, 0);
            return;
        case 16:
            ((struct gd_44_s32 *)sp14)->v = func_80017568(41);
            func_800445D0(((s32)&D_80191F08), ((s32)&D_80191EFC), 2, 0);
            return;
        case 15:
            ((struct gd_44_s32 *)sp14)->v = func_80017568(41);
            func_800445D0(((s32)&D_80191D18), ((s32)&D_80191D0C), 2, 0);
            return;
        case 18:
            func_800445D0(((s32)&D_80197830), ((s32)&D_80197824), 2, 0);
            return;
        case 17:
            func_800445D0(((s32)&D_801ABC38), ((s32)&D_801ABC2C), 2, 0);
            return;
        case 14:
            func_800445D0(((s32)&D_8018F3B0), ((s32)&D_8018F3A4), 2, 0);
            return;
        case 13:
            func_800445D0(((s32)&D_801A7D90), ((s32)&D_801A7D84), 2, 0);
            return;
        }
    }
}
