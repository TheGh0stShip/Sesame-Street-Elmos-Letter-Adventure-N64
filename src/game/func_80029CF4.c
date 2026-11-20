#include "common.h"


void func_80029CF4(s32 arg0) {
    s32 sp10;

    sp10 = arg0;
    if (((struct gd_1E8_s32 *)sp10)->v != 0) {
        func_80040680(((struct gd_1E8_s32 *)sp10)->v);
    }
    func_80040680(sp10);
}
