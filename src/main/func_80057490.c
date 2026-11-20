/* osSetTimer */
typedef u64 OSTime;
typedef void *OSMesg;
typedef struct OSMesgQueue_s OSMesgQueue;
typedef struct OSTimer_s {
    struct OSTimer_s *next;
    struct OSTimer_s *prev;
    OSTime interval;
    OSTime value;
    OSMesgQueue *mq;
    OSMesg msg;
} OSTimer;
extern OSTimer *D_80077430; /* __osTimerList */
OSTime func_800579E8(OSTimer *t); /* __osInsertTimer */
void func_80057988(OSTime t); /* __osSetTimerIntr */

int func_80057490(OSTimer *t, OSTime value, OSTime interval, OSMesgQueue *mq, OSMesg msg)
{
    OSTime time;
    t->next = NULL;
    t->prev = NULL;
    t->interval = interval;
    t->value = value;
    if (value == 0)
        t->value = interval;
    t->mq = mq;
    t->msg = msg;
    time = func_800579E8(t);
    if (D_80077430->next == t)
        func_80057988(time);
    return 0;
}
