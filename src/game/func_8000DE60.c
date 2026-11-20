#include "common.h"

s32 func_8005B640();
s32 func_8005B6E0();

void func_8000DE60(s32 arg0) {
    if (arg0 != 0) {
        func_8005B6E0(((s32)&D_80071D08), 3);
        return;
    }
    func_8005B640(((s32)&D_80071D08), 3);
}
