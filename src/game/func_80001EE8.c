#include "common.h"


void func_80001EE8(void) {
    D_801201A8 = 6;
    D_801201C8 = (s32)&D_80200000;
    D_80128278 = 7;
    D_80128298 = (s32)&D_80225800;
    osViSetSpecialFeatures(66);
    D_80108B24 = 1;
    D_8006DD58 = 0;
}
