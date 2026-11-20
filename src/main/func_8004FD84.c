/* reads one byte from a stream, forwards it when mode 1 is active, returns the advanced pointer */
extern s32 D_800A0100;
void func_80050640(u8 c);
u8 *func_8004FD84(void *unused, u8 *p) {
    u8 c = *p++;
    if (D_800A0100 == 1) {
        func_80050640(c);
    }
    return p;
}
