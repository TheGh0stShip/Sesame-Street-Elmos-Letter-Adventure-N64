#include "common.h"


void func_800408C4(s32 arg0) {
    s32 sp10;
    s32 sp14;
    s32 sp18;

    sp18 = 0;
    while (!((u32)sp18 >= (u32)D_8013C5B4)) {
        sp10 = D_801151C4[sp18].m0;
        while (!(sp10 == 0)) {
            sp14 = *(s32 *)sp10;
            if ((((struct gd_C_s32 *)sp10)->v & -16) == arg0) {
                func_80040680(sp10);
            }
            sp10 = sp14;
        }
        sp18++;
    }
    return;
}
