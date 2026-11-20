#include "common.h"

s32 func_8000E310(s32 arg0) {
    s32 sp0;

    if (D_80071E5C == 0) {
        return -1;
    }
    if ((arg0 == D_80071E4C) || (arg0 == D_80071E50)) {
        return 0;
    }
    if ((arg0 < 0) || (arg0 > D_80071E40)) {
        arg0 = 0;
    }
    sp0 = D_80071E4C;
    D_80071E50 = D_80071E58 = arg0;
    D_80071E4C = D_80071E54 = arg0;
    return sp0;
}
