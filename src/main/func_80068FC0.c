/* 64-bit unsigned divide/remainder dispatch: tail-calls the 32-bit-divisor path when the divisor high word is zero */
__asm__(
    ".set noreorder\n"
    ".set noat\n"
    ".globl func_80068FC0\n"
    "func_80068FC0:\n"
    "    bnez $6, 1f\n"
    "    nop\n"
    "    j func_80068D84\n"
    "    nop\n"
    "    1: j func_80068C88\n"
    "    nop\n"
    "    nop\n"
    "    nop\n"
    ".set at\n"
    ".set reorder\n"
);
