/* reads a field of the running thread with interrupts disabled */
typedef struct { struct OSThread_s *next; s32 priority; } OSThread;
extern u32 func_800612F0(void);        /* __osDisableInt */
extern void func_80061310(u32);        /* __osRestoreInt */
extern OSThread *D_80077850;           /* __osRunningThread */
s32 func_80062290(void)
{
    u32 mask = func_800612F0();
    s32 pri = D_80077850->priority;
    func_80061310(mask);
    return pri;
}
