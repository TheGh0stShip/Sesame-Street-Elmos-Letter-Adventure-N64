#include "common.h"


void func_8001185C(register s32 arg0) {
    ((struct gd_C_s32 *)arg0)->v = (((struct gd_19_s8 *)arg0)->v << 15) + ((struct gd_C_s32 *)arg0)->v;
    ((struct gd_10_s32 *)arg0)->v = (((struct gd_1A_s8 *)arg0)->v << 15) + ((struct gd_10_s32 *)arg0)->v;
    ((struct gd_14_s32 *)arg0)->v = (((struct gd_1B_s8 *)arg0)->v << 15) + ((struct gd_14_s32 *)arg0)->v;
    if (((struct gd_1A_s8 *)arg0)->v >= -118) {
        ((struct gd_1A_s8 *)arg0)->v = ((struct gd_1A_u8 *)arg0)->v - 4;
    }
    func_800110E4(arg0);
}
