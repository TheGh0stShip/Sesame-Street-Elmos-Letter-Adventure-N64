s32 func_80061AD0(void *, s32, s32);
/* writes the 4 bytes of value through a partial-write routine until done */
void func_8005F2F8(u32 value) {
    s32 n = 0;
    u8 *p = (u8 *)&value;
    do {
        n += func_80061AD0(p + n, 4 - n, 8);
    } while (n < 4);
}
