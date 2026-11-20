#include "common.h"

/* __osSiDeviceBusy */
int func_80062A30(void) {
    register u32 stat = *(volatile u32 *)0xA4800018;
    if (stat & 3) {
        return 1;
    } else {
        return 0;
    }
}
