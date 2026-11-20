#include "common.h"


void func_8001F300(s32 arg0) {
    s32 sp10;
    s32 sp14;
    s32 pad0;
    s32 sp1C;

    sp10 = 0;
    sp14 = arg0 + (sp10 * 4);
    while (!((*(s32 *)sp14) == 0)) {
        sp1C = *(s32 *)sp14;
        switch (*(s32 *)sp1C) {
        case 19:
            func_80030D8C(sp1C);
            break;
        case 1:
            func_80021110(sp1C);
            break;
        case 4:
            func_80024E20(sp1C);
            break;
        case 5:
            func_8002A120(sp1C);
            break;
        case 7:
            func_80023118(sp1C);
            break;
        case 8:
            func_800327E0(sp1C);
            break;
        case 9:
            func_80022C6C(sp1C);
            break;
        case 10:
            func_80034CD0(sp1C);
            break;
        case 12:
            func_8003BB00(sp1C);
            break;
        case 13:
            func_80026ABC(sp1C);
            break;
        case 16:
            func_80026B34(sp1C);
            break;
        case 17:
            func_80026AF8(sp1C);
            break;
        }
        sp10++;
        sp14 = arg0 + (sp10 * 4);
    }
    return;
}
