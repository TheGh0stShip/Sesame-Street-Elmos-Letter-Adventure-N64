#include "common.h"


s32 func_8001375C(s32 arg0, s32 arg1, s32 arg2) {
    s32 sp0;

    sp0 = (s32)&D_800A7AC0;
    ((struct gd_24_s32 *)sp0)->v = (s32)&D_8012C280;
    ((struct gd_28_s32 *)sp0)->v = (s32)&D_80134080;
    ((struct gd_2C_s32 *)sp0)->v = ((struct gd_28_s32 *)sp0)->v + 0x8000;
    (*(s32 *)sp0) = 0;
    ((struct gd_1C_s32 *)sp0)->v = 0;
    ((struct gd_20_s32 *)sp0)->v = 0;
    ((struct gd_30_s32 *)sp0)->v = ((struct gd_34_s32 *)sp0)->v = ((struct gd_28_s32 *)sp0)->v;
    (*(s32 *)arg0) = (s32)&D_8012FD50;
    ((struct gd_4_s32 *)arg0)->v = 0;
    ((struct gd_8_s32 *)arg0)->v = ((struct gd_14_s32 *)arg0)->v = 0;
    ((struct gd_10_s32 *)arg0)->v = arg2;
    ((struct gd_C_s32 *)arg0)->v = arg1;
    ((struct gd_18_s32 *)arg0)->v = sp0;
    return 0;
}
