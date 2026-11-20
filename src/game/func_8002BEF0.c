#include "common.h"

extern u16 D_801078B8;

void func_8002BEF0(s32 arg0, s32 arg1) {
    if (((D_801078B8 & 2560) & 0xFFFF) == 2560) {
        (*(f32 *)arg0) = -28.284f;
        (*(f32 *)arg1) = 28.284f;
        ((struct gd_204_s32 *)D_80106888)->v = 1;
        return;
    }
    if (((D_801078B8 & 2304) & 0xFFFF) == 2304) {
        (*(f32 *)arg0) = 28.284f;
        (*(f32 *)arg1) = 28.284f;
        ((struct gd_204_s32 *)D_80106888)->v = 1;
        return;
    }
    if (((D_801078B8 & 1536) & 0xFFFF) == 1536) {
        (*(f32 *)arg0) = -28.284f;
        (*(f32 *)arg1) = -28.284f;
        ((struct gd_204_s32 *)D_80106888)->v = 1;
        return;
    }
    if (((D_801078B8 & 1280) & 0xFFFF) == 1280) {
        (*(f32 *)arg0) = 28.284f;
        (*(f32 *)arg1) = -28.284f;
        ((struct gd_204_s32 *)D_80106888)->v = 1;
        return;
    }
    if (((D_801078B8 & 2048) & 0xFFFF) != 0) {
        (*(s32 *)arg0) = 0;
        (*(f32 *)arg1) = 4e+01f;
        ((struct gd_204_s32 *)D_80106888)->v = 1;
        return;
    }
    if (((D_801078B8 & 1024) & 0xFFFF) != 0) {
        (*(s32 *)arg0) = 0;
        (*(f32 *)arg1) = -4e+01f;
        ((struct gd_204_s32 *)D_80106888)->v = 1;
        return;
    }
    if (((D_801078B8 & 512) & 0xFFFF) != 0) {
        (*(f32 *)arg0) = -4e+01f;
        (*(s32 *)arg1) = 0;
        ((struct gd_204_s32 *)D_80106888)->v = 1;
        return;
    }
    if (((D_801078B8 & 256) & 0xFFFF) != 0) {
        (*(f32 *)arg0) = 4e+01f;
        (*(s32 *)arg1) = 0;
        ((struct gd_204_s32 *)D_80106888)->v = 1;
    } else {
    }
}
