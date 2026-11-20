#include "common.h"

s32 func_8001694C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    s32 sp28;
    s32 sp2C;

    sp2C = 0;
    sp28 = func_8001602C(arg2, arg0, 257, ((s32)&D_800799AC), ((s32)&D_80079A28), arg5, arg3, arg7, ((s32)&sp2C), ((s32)&D_800A7610));
    if ((sp28 != 0) || ((*(s32 *)arg3) == 0)) {
        return sp28;
    }
    sp28 = func_8001602C(((arg0 * 4) + arg2), arg1, 0, ((s32)&D_80079AA4), ((s32)&D_80079B1C), arg6, arg4, arg7, ((s32)&sp2C), ((s32)&D_800A7610));
    return sp28;
}
