/* __osSpRawWriteIo */
int func_80066AD0(void); /* __osSpDeviceBusy */
s32 func_800684B0(u32 devAddr, u32 data) {
    if (func_80066AD0()) return -1;
    *(volatile u32 *)(devAddr | 0xA0000000) = data;
    return 0;
}
