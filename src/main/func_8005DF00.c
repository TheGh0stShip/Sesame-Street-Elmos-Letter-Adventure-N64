/* osContInit (libultra io/controller.c) */
typedef void *OSMesg;
typedef u64 OSTime;
typedef struct OSThread_s OSThread;
typedef struct { OSThread *mtqueue; OSThread *fullqueue; s32 validCount; s32 first; s32 msgCount; OSMesg *msg; } OSMesgQueue;
typedef struct OSTimer_s { struct OSTimer_s *next, *prev; OSTime interval; OSTime value; OSMesgQueue *mq; OSMesg msg; } OSTimer;
typedef struct { u16 type; u8 status; u8 errno; } OSContStatus;
typedef struct { u32 ramarray[15]; u32 pifstatus; } OSPifRam;
typedef struct { u8 dummy, txsize, rxsize, cmd, typeh, typel, status, dummy1; } __OSContRequesFormat;
#define OS_USEC_TO_CYCLES(n) (((u64)(n)*(46875000LL/15625LL))/(1000000LL/15625LL))
#define CHNL_ERR(f) (((f).rxsize & 0xC0) >> 4)
extern OSPifRam D_800ACBB0;      /* __osContPifRam */
extern u8 D_801180A2;            /* __osContLastCmd */
extern u8 D_80109B88;            /* __osMaxControllers */
extern OSMesgQueue D_8013E668;   /* __osEepromTimerQ */
extern OSMesg D_801282A4;        /* __osEepromTimerMsg */
extern s32 D_80077720;           /* __osContinitialized */
OSTime func_80056D40(void);      /* osGetTime */
void func_80056C40(OSMesgQueue *, OSMesg *, s32); /* osCreateMesgQueue */
s32 func_80057490(OSTimer *, OSTime, OSTime, OSMesgQueue *, OSMesg); /* osSetTimer */
s32 func_80057100(OSMesgQueue *, OSMesg *, s32); /* osRecvMesg */
s32 func_80062A50(s32, void *);  /* __osSiRawStartDma */
void func_80062AF0(void);        /* __osSiCreateAccessQueue */
void func_8005E09C(u8 *, OSContStatus *); /* __osContGetInitData */
void func_8005E150(u8);          /* __osPackRequestData */
s32 func_8005DF00(OSMesgQueue *mq, u8 *bitpattern, OSContStatus *data) {
    OSMesg dummy;
    s32 ret = 0;
    OSTime t;
    OSTimer mytimer;
    OSMesgQueue timerMesgQueue;

    if (D_80077720) {
        return 0;
    }
    D_80077720 = 1;
    t = func_80056D40();
    if (t < OS_USEC_TO_CYCLES(500000)) {
        func_80056C40(&timerMesgQueue, &dummy, 1);
        func_80057490(&mytimer, OS_USEC_TO_CYCLES(500000) - t, 0, &timerMesgQueue, &dummy);
        func_80057100(&timerMesgQueue, &dummy, 1);
    }
    D_80109B88 = 4;
    func_8005E150(0);
    ret = func_80062A50(1, D_800ACBB0.ramarray);
    func_80057100(mq, &dummy, 1);
    ret = func_80062A50(0, D_800ACBB0.ramarray);
    func_80057100(mq, &dummy, 1);
    func_8005E09C(bitpattern, data);
    D_801180A2 = 0;
    func_80062AF0();
    func_80056C40(&D_8013E668, &D_801282A4, 1);
    return ret;
}
