#include "common.h"


void func_8000E940(s32 arg0) {
    for (;;) {
        if ((*(u8 *)arg0) == 0) {
            return;
        }
        func_8000E7A0((*(u8 *)(arg0++)));
    }
}
