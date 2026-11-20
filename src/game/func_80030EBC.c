#include "common.h"


void func_80030EBC(s32 arg0) {
    s32 sp0;

    sp0 = (s32)D_8013EB0C++;
    (*(s32 *)sp0) = 0xBC00000E;
    ((struct gd_4_s32 *)sp0)->v = (*(u16 (*))&D_80109C28);
    sp0 = (s32)D_8013EB0C++;
    (*(s32 *)sp0) = 0x1030040;
    ((struct gd_4_s32 *)sp0)->v = D_8013EF68;
}
