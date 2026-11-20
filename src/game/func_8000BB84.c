#include "common.h"

 /* osInitRdb */
/* rmonMain */

extern OSThread D_800816A0;
extern OSThread D_8007D340;
void func_8000BB84(void *arg) {
    osCreatePiManager(150, D_80082B70, D_80082850, 200);
    osInitRdb(D_801282A8, 0x100);
    osCreateThread(&D_800816A0, 0, rmonMain, 0, D_80082850, 250);
    osStartThread(&D_800816A0);
    osCreateThread(&D_8007D340, 6, func_8000BC64, arg, D_8007F6A0, 10);
    osStartThread(&D_8007D340);
    osSetThreadPri(0, 0);
    for (;;) {
    }
}
