/* osStopTimer */
typedef u64 OSTime;
typedef struct OSTimer_s {
    struct OSTimer_s *next;
    struct OSTimer_s *prev;
    OSTime interval;
    OSTime value;
    void *mq;
    void *msg;
} OSTimer;
extern OSTimer *D_80077430; /* __osTimerList */
u32 func_800612F0(void); /* __osDisableInt */
void func_80061310(u32); /* __osRestoreInt */
void func_800613F0(u32); /* __osSetCompare */

int func_80057650(OSTimer *t)
{
    register u32 savedMask;
    OSTimer *timep;

    if (t->next == NULL)
        return -1;
    savedMask = func_800612F0();
    timep = t->next;
    if (timep != D_80077430)
        timep->value += t->value;
    t->prev->next = t->next;
    t->next->prev = t->prev;
    t->next = NULL;
    t->prev = NULL;
    if (D_80077430->next == D_80077430)
        func_800613F0(0);
    func_80061310(savedMask);
    return 0;
}
