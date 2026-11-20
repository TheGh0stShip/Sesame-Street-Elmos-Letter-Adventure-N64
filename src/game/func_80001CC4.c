#include "common.h"


void func_80001CC4(s32 arg0) {
    s32 sp0;

    sp0 = (s32)D_8013EB0C++;
    (*(s32 *)sp0) = 0x6000000;
    ((struct gd_4_s32 *)sp0)->v = (s32)&D_80074A08;
}
