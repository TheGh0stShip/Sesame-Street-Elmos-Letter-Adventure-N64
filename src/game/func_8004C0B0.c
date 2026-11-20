#include "common.h"


s32 func_8004C0B0(s32 arg0) {
    register s32 reg_s0;

    reg_s0 = func_80040400(16);
    func_80068300(reg_s0, 0, 16);
    (*(s32 *)reg_s0) = arg0;
    return reg_s0;
}
