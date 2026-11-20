#include "common.h"

s32 func_80040874(void) {
    D_800A8D38 = D_800A8D38 + 16;
    D_800A8D38 = D_800A8D38 | 15;
    return D_800A8D38;
}
