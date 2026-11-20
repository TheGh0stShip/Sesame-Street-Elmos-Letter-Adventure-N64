#include "common.h"

void *func_8004F854(void *arg0, u8 *arg1) {
    (*(u8 *)((s8 *)(arg0) + (0xB9))) = (u8) *arg1;
    return arg1 + 1;
}
