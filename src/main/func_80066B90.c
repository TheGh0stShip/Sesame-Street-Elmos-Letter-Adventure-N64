/* __osSpRawStartDma */
extern s32 func_80066AD0(void);        /* __osSpDeviceBusy */
extern u32 func_80057AF0(void *);      /* osVirtualToPhysical */
#define IO_WRITE(a, v) (*(vu32 *)(a) = (v))
typedef volatile u32 vu32;
s32 func_80066B90(s32 direction, u32 devAddr, void *dramAddr, u32 size)
{
    if (func_80066AD0()) {
        return -1;
    }
    IO_WRITE(0xA4040000, devAddr);
    IO_WRITE(0xA4040004, func_80057AF0(dramAddr));
    if (direction == 0) {
        IO_WRITE(0xA404000C, size - 1);
    } else {
        IO_WRITE(0xA4040008, size - 1);
    }
    return 0;
}
