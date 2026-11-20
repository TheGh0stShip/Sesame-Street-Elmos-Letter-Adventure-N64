/* __rmonHitCpuFault: stop user threads and report faulted threads */
void func_800653B0(void);   /* __rmonMaskIdleThreadInts */
void func_8006547C(int);    /* __rmonStopUserThreads */
void func_80063D98(void);   /* rmonFindFaultedThreads */
void func_800656DC(void) {
    func_800653B0();
    func_8006547C(0);
    func_80063D98();
}
