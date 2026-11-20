#include "common.h"


s32 func_80051D54(u8 *p) {
    if (D_800A036C + 0xB8 < p) {
        if (D_80077100 != 0) { D_80077100 = 0; return D_800A0364; }
    } else if (p < D_800A036C) {
        if (D_80077100 != 0) { D_80077100 = 0; return D_800A0368; }
    } else {
        D_80077100 = 1;
    }
    return D_800A0360;
}
