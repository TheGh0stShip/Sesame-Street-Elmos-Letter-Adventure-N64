#include "common.h"


s32 func_8004B234(s32 arg0) {
    register s32 reg_s0;

    reg_s0 = func_80040400(28);
    func_8004C490(reg_s0, 28);
    (*(s32 *)reg_s0) = arg0;
    return reg_s0;
}
