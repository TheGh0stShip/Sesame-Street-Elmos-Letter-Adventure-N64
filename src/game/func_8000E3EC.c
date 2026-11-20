#include "common.h"


s32 func_8000E3EC(s32 arg0) {
    s32 sp0;

    if (D_80071E5C == 0) {
        return -1;
    }
    sp0 = (*(s32 *)((D_80071E4C * 4) + D_80071E44)) % arg0;
    D_80071E4C++;
    D_80071E4C = D_80071E4C % D_80071E40;
    return sp0;
}
