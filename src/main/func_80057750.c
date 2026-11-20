typedef struct OSTimer_s {
    struct OSTimer_s *next;
    struct OSTimer_s *prev;
    u64 interval;
    u64 remaining;
    void *mq;
    void *msg;
} OSTimer;
extern u64 D_80109C30;   /* __osCurrentTime */
extern u32 D_800A7AB0;   /* __osBaseCounter */
extern u32 D_800BD45C;   /* __osViIntrCount */
extern OSTimer *D_80077430; /* __osTimerList */
/* __osTimerServicesInit */
void func_80057750(void) {
    D_80109C30 = 0;
    D_800A7AB0 = 0;
    D_800BD45C = 0;
    D_80077430->prev = D_80077430;
    D_80077430->next = D_80077430->prev;
    D_80077430->remaining = D_80109C30;
    D_80077430->interval = D_80077430->remaining;
    D_80077430->mq = NULL;
    D_80077430->msg = 0;
}
