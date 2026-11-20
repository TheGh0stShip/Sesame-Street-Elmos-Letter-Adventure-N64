#include "common.h"


void func_80031744(s32 arg0, s32 arg1) {
    D_80115258 = arg1;
    D_80115374 = arg0;
    osSendMesg(((s32)&D_8013ED88), 0, 1);
    D_800A7AA8 = 0;
    D_800ACC2D++;
}
