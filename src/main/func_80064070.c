/* reads a word from a PI-domain address via func_80061E80; returns 0 when out of range */
s32 func_80061E80(u32 addr, u32 *data);
u32 func_80064070(u32 addr) {
    u32 data;
    if (addr - 0x04000000 < 0x1000000) {
        func_80061E80(addr, &data);
        return data;
    }
    return 0;
}
