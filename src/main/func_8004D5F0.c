extern s32 D_800A0114;
extern s32 D_800A0118;
extern s32 D_800A011C;
extern void *D_800A0120;
void *func_80050FCC(s32);
/* allocates a table of n (clamped 64..1024) 8-byte entries */
void func_8004D5F0(s32 n) {
    if (n < 0x40) {
        n = 0x40;
    } else if (n > 0x400) {
        n = 0x400;
    }
    D_800A0120 = func_80050FCC(n * 8);
    D_800A011C = n;
    D_800A0118 = 0;
    D_800A0114 = 0;
}
