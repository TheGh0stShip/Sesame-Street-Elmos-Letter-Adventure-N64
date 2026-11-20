#include "common.h"


void func_800376A4(s32 arg0) {
    s32 pad0[2];
    s8 pad1;

    ((struct gd_1CC_s32 *)arg0)->v++;
    if (D_80109B8C == 0) {
        return;
    }
    if ((*(u8 (*))&D_80075E2F) != 0) {
        func_80035828(arg0, 6);
    }
}
