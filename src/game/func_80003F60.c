#include "common.h"

extern struct n64dk_a8013EB38 D_8013EB38[];

void func_80003F60(void) {
    s32 sp0;

    for (sp0 = 0; !(sp0 >= 6); sp0++) {
        D_8013EB38[sp0].m0 = 0;
        D_8013EB38[sp0].m4 = 0;
        D_8013EB38[sp0].m8 = 0;
    }
}
