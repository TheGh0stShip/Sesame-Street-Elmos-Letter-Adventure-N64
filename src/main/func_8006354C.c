/* send a fixed event message to its queue without blocking (interrupt-side osSendMesg) */
typedef void *OSMesg;
typedef struct OSThread_s { struct OSThread_s *next; } OSThread;
typedef struct {
    OSThread *mtqueue;
    OSThread *fullqueue;
    s32 validCount;
    s32 first;
    s32 msgCount;
    OSMesg *msg;
} OSMesgQueue;
typedef struct {
    OSMesgQueue *messageQueue;
    OSMesg message;
} __OSEventState;
extern __OSEventState D_80133DB8;
extern OSThread *D_80077418; /* __osRunQueue */
OSThread *func_800610AC(OSThread **); /* __osPopThread */
void func_80061064(OSThread **, OSThread *); /* __osEnqueueThread */

void func_8006354C(void)
{
    OSMesgQueue *mq = D_80133DB8.messageQueue;

    if (mq != NULL && mq->validCount < mq->msgCount) {
        mq->msg[(mq->first + mq->validCount) % mq->msgCount] = D_80133DB8.message;
        mq->validCount++;
        if (mq->mtqueue->next != NULL)
            func_80061064(&D_80077418, func_800610AC(&mq->mtqueue));
    }
}
