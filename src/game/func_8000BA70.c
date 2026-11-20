#include "common.h"


void func_8000BA70(s32 arg0) {
    s32 sp10;

    sp10 = 0;
    osCreateMesgQueue(((s32)&D_80133E40), ((s32)&D_80109B90), 1);
    for (;;) {
        goto L9;
        return;
L9: ;
        osRecvMesg(((s32)&D_80133E40), ((s32)&sp10), 1);
        if ((*(s16 *)sp10) == 4) {
            if (D_800ACC2C == 0) {
                D_800ACC2C = 1;
                func_8004CDC8(3, 4);
            }
        }
    }
}
