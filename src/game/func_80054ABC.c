#include "common.h"

/* extern */
                              /* extern */
extern void *D_800773B4;

void func_80054ABC(void) {
    s32 var_s0_10;

    var_s0_10 = (*(s32 *)((s8 *)(D_800773B4) + (0x14)));
    if (var_s0_10 != 0) {
        do {
            alUnlink(var_s0_10);
            alLink(var_s0_10, D_800773B4 + 4);
            var_s0_10 = (*(s32 *)((s8 *)(D_800773B4) + (0x14)));
        } while (var_s0_10 != 0);
    }
}
