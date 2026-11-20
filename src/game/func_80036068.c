#include "common.h"


void func_80036068(s32 arg0) {
    func_80035750(arg0);
    if ((*(u8 (*))&D_800A75EE) == 0) {
        if (D_80115374 == 0) {
            D_80115374 = (s32)&D_80073310;
            osSendMesg(((s32)&D_8013ED88), 0, 1);
        }
        func_800356D0(arg0, 10);
        (*(u8 (*))&D_800A75EE) = 1;
    } else {
        if (D_80115374 == 0) {
            D_80115374 = (s32)&D_80073320;
            osSendMesg(((s32)&D_8013ED88), 0, 1);
        }
        func_800356D0(arg0, 12);
    }
    ((struct gd_C_s32 *)arg0)->v = ((struct gd_C_s32 *)arg0)->v | 128;
    ((struct gd_200_s32 *)arg0)->v = ((struct gd_200_s32 *)arg0)->v & -2;
    ((struct gd_200_s32 *)arg0)->v = ((struct gd_200_s32 *)arg0)->v & -3;
    ((struct gd_200_s32 *)arg0)->v = ((struct gd_200_s32 *)arg0)->v | 4;
    (*(f32 *)(arg0 + 536)) = *(f32 *)(arg0 + 36);
    ((struct gd_4_f32 *)(arg0 + 536))->v = ((struct gd_4_f32 *)(arg0 + 36))->v;
    ((struct gd_8_f32 *)(arg0 + 536))->v = ((struct gd_8_f32 *)(arg0 + 36))->v;
}
