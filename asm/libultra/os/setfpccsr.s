/* func_80061400: libultra src/os/setfpccsr.s */
#include "asm.h"

.text
LEAF(func_80061400)
    CFC1(   $v0, $31)
    CTC1(   $a0, $31)
    j       $ra
END(func_80061400)

/* known names (symbols.letter.tsv) */
#undef __osSetFpcCsr
.globl __osSetFpcCsr
__osSetFpcCsr = func_80061400
