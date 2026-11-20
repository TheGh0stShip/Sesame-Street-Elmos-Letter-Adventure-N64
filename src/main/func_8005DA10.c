/* osAiSetNextBuffer */
extern u8 D_80077710; /* hdwrBugFlag */
s32 func_80061DC0(void); /* __osAiDeviceBusy */
u32 func_80057AF0(void *); /* osVirtualToPhysical */
#define IO_WRITE(a,v) (*(volatile u32 *)(0xA0000000 | (a)) = (v))
s32 func_8005DA10(void *bufPtr, u32 size)
{
    char *bptr = bufPtr;
    if (D_80077710 != 0)
        bptr -= 0x2000;
    if ((((u32)bufPtr + size) & 0x1fff) == 0)
        D_80077710 = 1;
    else
        D_80077710 = 0;
    if (func_80061DC0())
        return -1;
    IO_WRITE(0x04500000, func_80057AF0(bptr));
    IO_WRITE(0x04500004, size);
    return 0;
}
