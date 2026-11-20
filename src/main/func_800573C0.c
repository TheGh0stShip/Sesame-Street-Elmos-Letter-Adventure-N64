/* osSetThreadPri: change a thread's priority and reschedule if needed */
typedef struct OSThread_s {
    struct OSThread_s *next;
    s32 priority;
    struct OSThread_s **queue;
    struct OSThread_s *tlnext;
    u16 state;
    u16 flags;
} OSThread;

extern OSThread *D_80077420; /* __osRunningThread */
extern OSThread *D_80077418; /* __osRunQueue */
u32 func_800612F0(void);                          /* __osDisableInt */
void func_80061310(u32);                          /* __osRestoreInt */
void func_80057710(OSThread **, OSThread *);      /* __osDequeueThread */
void func_80061064(OSThread **, OSThread *);      /* __osEnqueueThread */
void func_80060F5C(OSThread **);                  /* __osEnqueueAndYield */

void func_800573C0(OSThread *t, s32 pri) {
    register u32 saveMask = func_800612F0();

    if (t == NULL) {
        t = D_80077420;
    }
    if (t->priority != pri) {
        t->priority = pri;
        if (t != D_80077420 && t->state != 1) {
            func_80057710(t->queue, t);
            func_80061064(t->queue, t);
        }
        if (D_80077420->priority < D_80077418->priority) {
            D_80077420->state = 2;
            func_80060F5C(&D_80077418);
        }
    }
    func_80061310(saveMask);
}
