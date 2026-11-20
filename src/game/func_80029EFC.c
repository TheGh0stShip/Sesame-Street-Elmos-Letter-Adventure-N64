#include "common.h"


s32 func_80029EFC(s32 arg0, f32 arg1) {
    f32 sp0;
    f32 sp4;

    sp0 = ((struct gd_24_f32 *)arg0)->v - ((struct gd_24_f32 *)D_80106888)->v;
    sp4 = ((struct gd_2C_f32 *)arg0)->v - ((struct gd_2C_f32 *)D_80106888)->v;
    sp0 = sp0 * sp0;
    sp4 = sp4 * sp4;
    sp4 = sp4 + sp0;
    if (sp4 < arg1) {
        return 1;
    }
    return 0;
}
