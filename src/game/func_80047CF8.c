#include "common.h"


void func_80047CF8(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (((struct gd_18_s32 *)arg1)->v == 0) {
        func_80047F60(((s32)&D_8007AEE0));
        return;
    }
    if (D_800A00B0 == 0) {
        func_80047F60(((s32)&D_8007AF28));
        return;
    }
    ((struct gd_8_s32 *)D_800A00B0)->v = arg2;
    ((struct gd_C_s32 *)D_800A00B0)->v = arg3;
    ((struct gd_4_s32 *)D_800A00B0)->v = arg0;
    if (((struct gd_1C_s32 *)arg1)->v == 0) {
        ((struct gd_1C_s32 *)arg1)->v = D_800A00B0;
    } else {
        (*(s32 *)((struct gd_20_s32 *)arg1)->v) = D_800A00B0;
    }
    ((struct gd_20_s32 *)arg1)->v = D_800A00B0;
    D_800A00B0 = *(s32 *)D_800A00B0;
    (*(s32 *)((struct gd_20_s32 *)arg1)->v) = 0;
    return;
}
