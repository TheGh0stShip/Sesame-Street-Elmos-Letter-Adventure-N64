/* osStartThread */
typedef struct OSThread_s {
    struct OSThread_s *next;
    s32 priority;
    struct OSThread_s **queue;
    struct OSThread_s *tlnext;
    u16 state;
    u16 flags;
} OSThread;
extern OSThread *D_80077418; /* __osRunQueue */
extern OSThread *D_80077420; /* __osRunningThread */
u32 func_800612F0(void);                        /* __osDisableInt */
void func_80061310(u32);                        /* __osRestoreInt */
void func_80061064(OSThread **, OSThread *);    /* __osEnqueueThread */
OSThread *func_800610AC(OSThread **);           /* __osPopThread */
void func_800610BC(void);                       /* __osDispatchThread */
void func_80060F5C(OSThread **);                /* __osEnqueueAndYield */

void func_80057530(OSThread *t)
{
    register u32 saveMask = func_800612F0();

    switch (t->state) {
    case 8:
        t->state = 2;
        func_80061064(&D_80077418, t);
        break;
    case 1:
        if (t->queue == NULL || t->queue == &D_80077418) {
            t->state = 2;
            func_80061064(&D_80077418, t);
        } else {
            t->state = 8;
            func_80061064(t->queue, t);
            func_80061064(&D_80077418, func_800610AC(t->queue));
        }
        break;
    }
    if (D_80077420 == NULL) {
        func_800610BC();
    } else if (D_80077420->priority < D_80077418->priority) {
        D_80077420->state = 2;
        func_80060F5C(&D_80077418);
    }
    func_80061310(saveMask);
}
