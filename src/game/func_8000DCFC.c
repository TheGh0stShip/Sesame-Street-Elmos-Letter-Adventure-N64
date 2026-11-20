#include "common.h"

s32 func_8005D7FC();

void func_8000DCFC(s32 arg0) {
    s32 sp10;

    sp10 = arg0;
    func_8005D7FC(((s32)&sp10));
    arg0 = sp10 - 8;
}
