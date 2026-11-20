#include "common.h"

s32 func_80040C00();

void func_80041230(s32 arg0, s32 arg1) {
    s32 sp10;
    s32 sp14;

    if (arg1 == 0) {
        func_80057BD0(((s32)&D_8007AE00), ((s32)&D_8007AE04), 38);
        return;
    }
    sp10 = *(s32 *)arg1;
    while ((sp10 != 0) && (((struct gd_38_f32 *)arg0)->v > 0.0f)) {
        sp14 = ((struct gd_8_s32 *)sp10)->v;
        if ((((struct gd_30_s32 *)arg0)->v & ((struct gd_8_s32 *)sp14)->v) != 0) {
            switch (*(s32 *)sp14) {
            case 3:
                func_80040C00(arg0, sp14);
                break;
            case 1:
                func_80044910(arg0, sp14);
                break;
            case 12:
                func_80044B90(arg0, sp14);
                break;
            case 13:
                break;
            }
        }
        sp10 = *(s32 *)sp10;
    }
}
