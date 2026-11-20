/* __osTimerInterrupt (libultra os/timerintr.c): expire due timers, with the debug profiler sampling */
typedef void *OSMesg;
typedef struct OSMesgQueue_s OSMesgQueue;

typedef struct OSTimer_s {
    struct OSTimer_s *next;
    struct OSTimer_s *prev;
    u64 interval;
    u64 value;
    OSMesgQueue *mq;
    OSMesg msg;
} OSTimer;

typedef struct {
    u8 unk_00[0x11C];
    u32 pc;              /* context.pc */
} OSThread;

typedef struct {
    u16 *histo_base;
    u32 histo_size;
    u32 *text_start;
    u32 *text_end;
} OSProf;

extern OSTimer *D_80077430;      /* __osTimerList */
extern u32 D_8012C274;           /* __osTimerCounter */
extern OSMesgQueue D_8012FCC8;   /* __osProfTimerQ */
extern OSProf *D_800ACC30;       /* __osProfileList */
extern OSProf *D_8012FCB8;       /* __osProfileListEnd */
extern u32 D_800A8D40;           /* __osProfileOverflowBin */
extern OSThread *D_80077418;     /* __osRunQueue */

void func_800613F0(u32);                        /* __osSetCompare */
u32 func_80061250(void);                        /* osGetCount */
void func_80057988(u64);                        /* __osSetTimerIntr */
s32 func_80057230(OSMesgQueue *, OSMesg, s32);  /* osSendMesg */
u64 func_800579E8(OSTimer *);                   /* __osInsertTimer */

void func_800577A4(void) {
    OSTimer *t;
    u32 count;
    u32 elapsed_cycles;
    u32 pc;
    s32 offset;
    OSProf *prof = D_800ACC30;

    if (D_80077430->next == D_80077430) {
        return;
    }
    for (;;) {
        t = D_80077430->next;

        if (t == D_80077430) {
            func_800613F0(0);
            D_8012C274 = 0;
            break;
        }

        count = func_80061250();
        elapsed_cycles = count - D_8012C274;
        D_8012C274 = count;

        if (elapsed_cycles < t->value) {
            t->value -= elapsed_cycles;
            func_80057988(t->value);
            break;
        }

        t->prev->next = t->next;
        t->next->prev = t->prev;
        t->next = NULL;
        t->prev = NULL;

        if (t->mq != NULL) {
            if (t->mq != &D_8012FCC8) {
                func_80057230(t->mq, t->msg, 0);
            } else {
                pc = D_80077418->pc;
                for (prof = D_800ACC30; prof < D_8012FCB8; prof++) {
                    offset = pc - (u32)prof->text_start;

                    if (offset >= 0) {
                        if ((s32)prof->text_end - (s32)pc > 0) {
                            (*(u16 *)(u32)((offset >> 2) + prof->histo_base))++;
                            goto __ProfDone;
                        }
                    }
                }

                D_800A8D40++;
            }
        }

    __ProfDone:

        if (t->interval != 0) {
            t->value = t->interval;
            func_800579E8(t);
        }
    }
}
