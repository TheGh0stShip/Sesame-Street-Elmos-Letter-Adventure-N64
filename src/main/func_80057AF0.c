u32 func_80061330(void *); /* __osProbeTLB */
/* osVirtualToPhysical */
u32 func_80057AF0(void *addr) {
    if ((u32)addr - 0x80000000 < 0x20000000) {
        return (u32)addr & 0x1FFFFFFF;
    } else if ((u32)addr - 0xA0000000 < 0x20000000) {
        return (u32)addr & 0x1FFFFFFF;
    } else {
        return func_80061330(addr);
    }
}
