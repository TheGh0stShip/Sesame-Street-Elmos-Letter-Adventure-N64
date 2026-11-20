/* osCreateScheduler (libultra sched/sched.c) */
typedef s32 OSPri;
typedef void *OSMesg;
typedef struct { void *mtqueue; void *fullqueue; s32 validCount; s32 first; s32 msgCount; OSMesg *msg; } OSMesgQueue;
typedef struct { u8 data[0x1B0]; } OSThread;
typedef struct { u8 data[0x50]; } OSViMode;
typedef struct { short type; char misc[30]; } OSScMsg;
typedef struct OSScTask_s OSScTask;
typedef struct OSScClient_s OSScClient;
typedef struct {
    OSScMsg     retraceMsg;
    OSScMsg     prenmiMsg;
    OSMesgQueue interruptQ;
    OSMesg      intBuf[8];
    OSMesgQueue cmdQ;
    OSMesg      cmdMsgBuf[8];
    OSThread    thread;
    OSScClient  *clientList;
    OSScTask    *audioListHead;
    OSScTask    *gfxListHead;
    OSScTask    *audioListTail;
    OSScTask    *gfxListTail;
    OSScTask    *curRSPTask;
    OSScTask    *curRDPTask;
    u32         frameCount;
    s32         doAudio;
} OSSched;
void func_80056C40(OSMesgQueue *mq, OSMesg *msg, s32 count);   /* osCreateMesgQueue */
void func_80062310(OSPri pri);                                 /* osCreateViManager */
void func_800626A0(OSViMode *mode);                            /* osViSetMode */
void func_8005DC20(u32 active);                                /* osViBlack */
void func_80057360(u32 event, OSMesgQueue *mq, OSMesg msg);    /* osSetEventMesg */
void func_80062640(OSMesgQueue *mq, OSMesg msg, u32 retraceCount); /* osViSetEvent */
void func_80056C70(OSThread *t, s32 id, void (*entry)(void *), void *arg, void *sp, OSPri pri); /* osCreateThread */
void func_80057530(OSThread *t);                               /* osStartThread */
void func_8005FB58(void *arg);                                 /* __scMain */
extern OSViMode D_80077880[];                                  /* osViModeTable */
void func_8005F920(OSSched *sc, void *stack, OSPri priority, u8 mode, u8 numFields)
{
    sc->curRSPTask      = 0;
    sc->curRDPTask      = 0;
    sc->clientList      = 0;
    sc->frameCount      = 0;
    sc->audioListHead   = 0;
    sc->gfxListHead     = 0;
    sc->audioListTail   = 0;
    sc->gfxListTail     = 0;
    sc->retraceMsg.type = 1;
    sc->prenmiMsg.type  = 4;
    func_80056C40(&sc->interruptQ, sc->intBuf, 8);
    func_80056C40(&sc->cmdQ, sc->cmdMsgBuf, 8);
    func_80062310(254);
    func_800626A0(&D_80077880[mode]);
    func_8005DC20(1);
    func_80057360(4, &sc->interruptQ, (OSMesg)0x29B);
    func_80057360(9, &sc->interruptQ, (OSMesg)0x29C);
    func_80057360(14, &sc->interruptQ, (OSMesg)0x29D);
    func_80062640(&sc->interruptQ, (OSMesg)0x29A, numFields);
    func_80056C70(&sc->thread, 4, func_8005FB58, (void *)sc, stack, priority);
    func_80057530(&sc->thread);
}
