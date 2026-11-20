#include "common.h"


void func_8003B4B0(s32 arg0) {
    if ((u32)D_801282A3 < 240) {
        D_801282A3 = D_801282A3 + 16;
        return;
    }
    D_801282A3 = 255;
    osViBlack(1);
    if (D_80115374 == 0) {
        if (D_8012FCE0 == 22) {
            func_8001D8E0(18);
            return;
        }
        func_8001D8E0(12);
    }
}
