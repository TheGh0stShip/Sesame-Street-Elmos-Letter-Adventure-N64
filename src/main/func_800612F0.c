/* hand-written assembly routine (SDK) */
__asm__(
    ".set noreorder\n"
    ".set noat\n"
    ".globl func_800612F0\n"
    "func_800612F0:\n"
    "    mfc0 $8, $12\n"
    "    addiu $1, $0, -0x2\n"
    "    and $9, $8, $1\n"
    "    mtc0 $9, $12\n"
    "    andi $2, $8, 0x1\n"
    "    nop\n"
    "    jr $31\n"
    "    nop\n"
    ".set at\n"
    ".set reorder\n"
);
