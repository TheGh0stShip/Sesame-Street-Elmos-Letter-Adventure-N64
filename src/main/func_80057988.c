/* __osSetTimerIntr */
typedef u64 OSTime;
extern u32 func_800612F0(void);      /* __osDisableInt */
extern void func_80061310(u32);      /* __osRestoreInt */
extern u32 func_80061250(void);      /* osGetCount */
extern void func_800613F0(u32);      /* __osSetCompare */
extern u32 D_8012C274;               /* __osTimerCounter */
void func_80057988(OSTime tim)
{
    OSTime NewTime;
    u32 savedMask;

    savedMask = func_800612F0();
    D_8012C274 = func_80061250();
    NewTime = D_8012C274 + tim;
    func_800613F0((u32)NewTime);
    func_80061310(savedMask);
}
