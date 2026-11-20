/* osSpTaskStartGo: wait for SP not busy, then clear halt/sstep and set intr-break */
extern u32 func_80066AD0(void);   /* __osSpDeviceBusy */
extern void func_80066B00(u32);   /* __osSpSetStatus */
void func_80063A4C(void *tp)
{
    while (func_80066AD0())
        ;
    func_80066B00(0x125);
}
