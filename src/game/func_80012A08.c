#include "common.h"

s32 func_80012A08(void) {
    register s32 reg_v1;

    reg_v1 = D_801283A8;
    if (reg_v1 != 0) {
        D_801283A8 = *(s32 *)reg_v1;
        if (D_800A7B00 != 0) {
            ((struct gd_4_s32 *)D_800A7B00)->v = reg_v1;
        }
        ((struct gd_4_s32 *)reg_v1)->v = 0;
        (*(s32 *)reg_v1) = D_800A7B00;
        D_800A7B00 = reg_v1;
        D_8013C5BC++;
        return reg_v1;
        return;
    }
    return 0;
}
