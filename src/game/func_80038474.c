#include "common.h"


void func_80038474(s32 arg0) {
    func_80035750(arg0);
    func_800356D0(arg0, 13);
    ((struct gd_C_s32 *)arg0)->v = ((struct gd_C_s32 *)arg0)->v | 128;
    if (D_80109B8C == 0) {
        ((struct gd_200_s32 *)arg0)->v = ((struct gd_200_s32 *)arg0)->v & -3;
    }
    ((struct gd_200_s32 *)arg0)->v = ((struct gd_200_s32 *)arg0)->v | 4;
    D_800A7ABC = 0;
    ((s32 (*)())func_8003E3E0)(arg0, 0, 0x41F00000, 0, 0);
}
