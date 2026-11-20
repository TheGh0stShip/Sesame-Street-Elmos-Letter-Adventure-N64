#include "common.h"


void func_8002BC90(s32 arg0) {
    s32 sp10;

    sp10 = arg0;
    func_80040680(((struct gd_F0_s32 *)sp10)->v);
    D_80106888 = 0;
    func_80040680(sp10);
    return;
}
