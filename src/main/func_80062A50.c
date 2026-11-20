/* __osSiRawStartDma */
s32 func_80062A30(void); /* __osSiDeviceBusy */
void func_80061420(void *, s32); /* osWritebackDCache */
void func_80056A60(void *, s32); /* osInvalDCache */
u32 func_80057AF0(void *); /* osVirtualToPhysical */
#define IO_WRITE(a,v) (*(volatile u32 *)(0xA0000000 | (a)) = (v))
s32 func_80062A50(s32 direction, void *dramAddr)
{
    if (func_80062A30())
        return -1;
    if (direction == 1)
        func_80061420(dramAddr, 64);
    IO_WRITE(0x04800000, func_80057AF0(dramAddr));
    if (direction == 0)
        IO_WRITE(0x04800004, 0x1FC007C0);
    else
        IO_WRITE(0x04800010, 0x1FC007C0);
    if (direction == 0)
        func_80056A60(dramAddr, 64);
    return 0;
}
