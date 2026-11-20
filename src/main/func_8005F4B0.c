/* strchr */
const u8 *func_8005F4B0(const u8 *s, s32 c) {
    const u8 ch = c;
    while (*s != ch) {
        if (*s++ == 0) return NULL;
    }
    return s;
}
