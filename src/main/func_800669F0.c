/* osStopThread (libultra 2.0F src/os/stopthread.c) */
typedef struct OSThread {
    struct OSThread *next;
    s32 priority;
    struct OSThread **queue;
    struct OSThread *tlnext;
    u16 state;
    u16 flags;
} OSThread;
extern OSThread *D_80077420; /* __osRunningThread */
u32 func_800612F0(void); /* __osDisableInt */
void func_80061310(u32); /* __osRestoreInt */
void func_80060F5C(OSThread **); /* __osEnqueueAndYield */
void func_80057710(OSThread **, OSThread *); /* __osDequeueThread */

void func_800669F0(OSThread *t) {
    register u32 saveMask = func_800612F0();
    register u16 state;

    state = (t == NULL) ? 4 : t->state;

    switch (state) {
        case 4:
            D_80077420->state = 1;
            func_80060F5C(NULL);
            break;
        case 2:
        case 8:
            t->state = 1;
            func_80057710(t->queue, t);
            break;
    }
    func_80061310(saveMask);
}
