#include "common.h"

typedef struct { s32 unk_00; s32 unk_04; } Entry;
extern Entry *D_800770C4[];
/* Returns the largest unk_04 over the NULL-terminated table D_800770C4 (0 if empty). */
s32 func_800505FC(void) {
    s32 max = 0;
    s32 i;
    for (i = 0; D_800770C4[i] != NULL; i++) {
        if (max < D_800770C4[i]->unk_04) {
            max = D_800770C4[i]->unk_04;
        }
    }
    return max;
}
