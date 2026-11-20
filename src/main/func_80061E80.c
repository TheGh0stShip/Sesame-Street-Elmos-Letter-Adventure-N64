/* osPiRawReadIo */
s32 func_80066AD0(void); /* __osPiDeviceBusy */
s32 func_80061E80(u32 devAddr, u32 *data) {
    if (func_80066AD0()) {
        return -1;
    }
    *data = *(volatile u32 *)(devAddr | 0xA0000000);
    return 0;
}
