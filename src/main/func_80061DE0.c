/* osDpSetNextBuffer */
s32 func_80066AB0(void); /* __osDpDeviceBusy */
u32 func_80057AF0(void *); /* osVirtualToPhysical */
#define IO_WRITE(a,v) (*(volatile u32 *)(0xA0000000 | (a)) = (v))
#define IO_READ(a) (*(volatile u32 *)(0xA0000000 | (a)))
s32 func_80061DE0(void *buf, u64 size)
{
    if (func_80066AB0())
        return -1;
    IO_WRITE(0x0410000C, 1);
    do {
    } while (IO_READ(0x0410000C) & 1);
    IO_WRITE(0x04100000, func_80057AF0(buf));
    IO_WRITE(0x04100004, func_80057AF0(buf) + size);
    return 0;
}
