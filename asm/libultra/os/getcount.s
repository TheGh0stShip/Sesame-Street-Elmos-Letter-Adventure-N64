/* osGetCount: libultra 2.0F src/os/getcount.s. Reads CP0 Count with mfc0: no C construct emits a coprocessor-0 move. */
#define C0_COUNT $9
#define osGetCount func_80061250
#include "asm.h"

.text
.text
LEAF(osGetCount)
    MFC0($v0, C0_COUNT)
    jr      $ra
END(osGetCount)

/* known names (symbols.letter.tsv) */
#undef __osGetCount
.globl __osGetCount
__osGetCount = func_80061250
