/* osDestroyThread */
typedef struct OSThread_s {
    struct OSThread_s *next;
    s32 priority;
    struct OSThread_s **queue;
    struct OSThread_s *tlnext;
    u16 state;
    u16 flags;
    s32 id;
    int fp;
    u8 pad1C[4];
    struct {
        u64 at, v0, v1, a0, a1, a2, a3;
        u64 t0, t1, t2, t3, t4, t5, t6, t7;
        u64 s0, s1, s2, s3, s4, s5, s6, s7;
        u64 t8, t9, gp, sp, s8, ra;
        u64 lo, hi;
        u32 sr, pc, cause, badvaddr, rcp;
        u32 fpcsr;
    } context;
} OSThread;
extern OSThread *D_8007741C; /* __osActiveQueue */
extern OSThread *D_80077420; /* __osRunningThread */
void func_80057710(OSThread **, OSThread *); /* __osDequeueThread */
void func_800610BC(void); /* __osDispatchThread */
u32 func_800612F0(void); /* __osDisableInt */
void func_80061310(u32); /* __osRestoreInt */

void func_80061500(OSThread *t)
{
    register u32 saveMask;
    register OSThread *pred;
    register OSThread *succ;

    saveMask = func_800612F0();
    if (t == NULL) {
        t = D_80077420;
    } else if (t->state != 1) {
        func_80057710(t->queue, t);
    }
    if (D_8007741C == t) {
        D_8007741C = D_8007741C->tlnext;
    } else {
        pred = D_8007741C;
        succ = pred->tlnext;
        while (succ != NULL) {
            if (succ == t) {
                pred->tlnext = t->tlnext;
                break;
            }
            pred = succ;
            succ = pred->tlnext;
        }
    }
    if (t == D_80077420)
        func_800610BC();
    func_80061310(saveMask);
}
