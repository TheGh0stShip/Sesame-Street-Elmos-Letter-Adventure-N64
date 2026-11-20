/* func_80054D20: libultra src/gu/func_80054D20.s */
#include "asm.h"

.text
LEAF(func_80054D20)
    sqrt.s  $f0, $f12
    j       $ra
END(func_80054D20)

/* known names (symbols.letter.tsv) */
#undef sqrtf
.globl sqrtf
sqrtf = func_80054D20
