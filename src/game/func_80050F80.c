#include "common.h"

/* Audio heap setup: clear a block, then alHeapInit on the global heap. */
typedef struct { u8 *base; u8 *cur; s32 len; s32 count; } ALHeap;
void alHeapInit(ALHeap *hp, u8 *base, s32 len); /* alHeapInit */
void func_80050F80(u8 *base, s32 len) {
    func_80051020(base, 0, len);
    alHeapInit(&D_800A0340, base, len);
}
