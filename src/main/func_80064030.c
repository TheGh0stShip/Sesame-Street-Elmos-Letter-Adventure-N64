s32 func_80066B40(u32 addr, u32 val); /* __osSpRawWriteIo */
/* __rmonWriteWordTo */
void func_800659A0(u32 *addr, u32 val) {
    while (func_80066B40((u32)addr, val) != 0) {
        ;
    }
}
