/* osPiRawReadIo */
s32 func_80062A30(void); /* __osPiDeviceBusy */
s32 func_8005DC80(u32 devAddr, u32 *data) {
    if (func_80062A30()) {
        return -1;
    }
    *data = *(volatile u32 *)(devAddr | 0xA0000000);
    return 0;
}
