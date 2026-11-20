/* osSendMesg */
typedef void *OSMesg;
typedef struct OSThread_s {
    struct OSThread_s *next;
    s32 priority;
    struct OSThread_s **queue;
    struct OSThread_s *tlnext;
    u16 state;
    u16 flags;
} OSThread;
typedef struct {
    OSThread *mtqueue;
    OSThread *fullqueue;
    s32 validCount;
    s32 first;
    s32 msgCount;
    OSMesg *msg;
} OSMesgQueue;
extern OSThread *D_80077420; /* __osRunningThread */
u32 func_800612F0(void);                        /* __osDisableInt */
void func_80061310(u32);                        /* __osRestoreInt */
OSThread *func_800610AC(OSThread **);           /* __osPopThread */
void func_80060F5C(OSThread **);                /* __osEnqueueAndYield */
void func_80057530(OSThread *);                 /* osStartThread */

s32 func_80057230(OSMesgQueue *mq, OSMesg msg, s32 flags)
{
    register u32 saveMask;
    register s32 last;

    saveMask = func_800612F0();
    while (mq->validCount >= mq->msgCount) {
        if (flags == 1) {
            D_80077420->state = 8;
            func_80060F5C(&mq->fullqueue);
        } else {
            func_80061310(saveMask);
            return -1;
        }
    }
    last = (mq->first + mq->validCount) % mq->msgCount;
    mq->msg[last] = msg;
    mq->validCount++;
    if (mq->mtqueue->next != NULL)
        func_80057530(func_800610AC(&mq->mtqueue));
    func_80061310(saveMask);
    return 0;
}
