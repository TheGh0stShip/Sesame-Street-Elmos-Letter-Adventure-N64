extern u32 D_800A7AB0; /* __osBaseCounter */
extern u64 D_80109C30; /* __osCurrentTime */
s32 func_800612F0(void);
void func_80061310(s32);
u32 func_80061250(void); /* osGetCount */
/* osGetTime */
u64 func_80056D40(void) {
    u32 tmptime;
    u32 elapseCount;
    u64 currentCount;
    register u32 saveMask;
    saveMask = func_800612F0();
    tmptime = func_80061250();
    elapseCount = tmptime - D_800A7AB0;
    currentCount = D_80109C30;
    func_80061310(saveMask);
    return currentCount + elapseCount;
}
