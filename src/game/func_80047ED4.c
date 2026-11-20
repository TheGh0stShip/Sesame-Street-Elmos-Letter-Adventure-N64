#include "common.h"


void func_80047ED4(s32 arg0) {
    s32 sp10;

    if (((struct gd_1C_s32 *)arg0)->v == 0) {
        func_80047F60(((s32)&D_8007AF4C));
        return;
    }
    sp10 = ((struct gd_1C_s32 *)arg0)->v;
    ((struct gd_1C_s32 *)arg0)->v = *(s32 *)sp10;
    (*(s32 *)sp10) = D_800A00B0;
    D_800A00B0 = sp10;
    return;
}
