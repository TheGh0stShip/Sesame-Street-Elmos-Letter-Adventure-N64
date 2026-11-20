#include "common.h"

#define DIV(a,b) ((a) / (b))

extern f64 D_80109BA0;

/* Per-frame timing: measures the frame time, frame rate and accumulated lag counters. */
void func_8000D0CC(void) {
    u64 step;
    s32 prev;
    s32 over;
    s32 rest;
    s32 half;

    if (D_80070770 == 0) {
        func_8000CF50();
    }
    D_80082BC8 = D_80082BC0;
    D_80082BC0 = DIV(osGetTime(), 46875);
    D_80082BD0 = D_80082BC0 - D_80082BC8;
    D_8012EFD8 = D_80082BD0;
    if (D_80082BD0 != 0) {
        D_80109BA0 = 1.0 / (D_8012EFD8 * 0.001);
    } else {
        D_80109BA0 = 0.0;
    }
    if (D_8007078C != 0) {
        D_80070780 = 0;
        D_8007077C = 0;
        D_80070774 = 0;
        D_80070778 = 0;
    }
    if (D_8007078C != 0 || D_80070784 != 0 || D_80082BD0 > 70) {
        step = 33;
        over = D_80082BD0 - 33;
        D_80082BB0 += over;
        D_80082BB8 += over;
        D_80070788 = 1;
    } else {
        step = D_80082BD0;
        D_80070788 = 0;
    }
    D_80070778 = D_8007077C;
    D_80070774 = D_80070780;
    if (D_80070778 != 0) {
        D_80082BB0 += step;
        D_80082BB8 += step;
    }
    if (D_8007078C != 0) {
        D_80070780 = 1;
        D_8007078C = 0;
    }
    prev = D_8011524C;
    D_8011524C = D_80082BC0 - D_80082BB0;
    D_80106890 = D_8011524C - prev;
    if (D_80070774 && (D_80070778 == 0)) D_80082BB8 += D_80106890;
    else if (D_80070790 != 0) {
        half = DIV(step, 2);
        rest = step - half;
        D_80082BB8 += rest;
    }
    prev = D_80133E34;
    D_80133E34 = D_80082BC0 - D_80082BB8;
    D_80107914 = D_80133E34 - prev;
}
