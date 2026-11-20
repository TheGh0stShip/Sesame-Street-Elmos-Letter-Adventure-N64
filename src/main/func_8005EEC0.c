s32 func_80061AD0(void *, u32, s32);
void func_8005EEC0(u8 *buf, u32 len, u8 b) {
    u32 n = 0;
    u8 *p = buf;
    p[8] = 2;
    p[5] = b;
    while (n < len) {
        n += func_80061AD0(p + n, len - n, 8);
    }
}
