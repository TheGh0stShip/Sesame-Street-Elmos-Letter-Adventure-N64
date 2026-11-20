#include "common.h"


s32 func_8004A6E4(s32 arg0) {
    register s32 reg_s0;

    reg_s0 = func_80040400(8);
    func_8004C490(reg_s0, 8);
    (*(s32 *)reg_s0) = arg0;
    return reg_s0;
}
