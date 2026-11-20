/* osCreatePiManager (libultra io/pimgr.c): start the PI device manager and ramrom threads */
typedef void *OSMesg;
typedef s32 OSPri;
typedef struct OSMesgQueue_s OSMesgQueue;
typedef struct OSThread_s OSThread;
typedef struct OSPiHandle_s OSPiHandle;

typedef struct {
    s32 active;
    OSThread *thread;
    OSMesgQueue *cmdQueue;
    OSMesgQueue *evtQueue;
    OSMesgQueue *acsQueue;
    s32 (*dma)(s32, u32, void *, u32);
    s32 (*edma)(OSPiHandle *, s32, u32, void *, u32);
} OSDevMgr;

extern OSDevMgr D_80077730;          /* __osPiDevMgr */
extern u32 D_80077760;               /* __osPiAccessQueueEnabled */
extern OSMesgQueue D_8010E4B8;       /* __osPiAccessQueue */
extern OSThread D_800A0380;          /* piThread */
extern u64 D_800A0530[0x1000 / 8];   /* piThreadStack */
extern OSThread D_800A1530;          /* ramromThread */
extern u64 D_800A16E0[0x400 / 8];    /* ramromThreadStack */
extern OSMesgQueue D_800A1B20;       /* piEventQueue */
extern OSMesg D_800A1B38[];          /* piEventBuf */

void func_80056C40(OSMesgQueue *, OSMesg *, s32);                 /* osCreateMesgQueue */
void func_8005ED20(void);                                          /* __osPiCreateAccessQueue */
void func_80057360(u32, OSMesgQueue *, OSMesg);                    /* osSetEventMesg */
OSPri func_800615D0(OSThread *);                                   /* osGetThreadPri */
void func_800573C0(OSThread *, OSPri);                             /* osSetThreadPri */
u32 func_800612F0(void);                                           /* __osDisableInt */
void func_80061310(u32);                                           /* __osRestoreInt */
void func_80056C70(OSThread *, s32, void (*)(void *), void *, void *, OSPri); /* osCreateThread */
void func_80057530(OSThread *);                                    /* osStartThread */
s32 func_80062BE0(s32, u32, void *, u32);                          /* __osPiRawStartDma */
s32 func_8005E510(OSPiHandle *, s32, u32, void *, u32);            /* __osEPiRawStartDma */
void func_8005E960(void *);                                        /* __osDevMgrMain */
void func_8005E42C(void *);                                        /* ramromMain */

void func_8005E260(OSPri pri, OSMesgQueue *cmdQ, OSMesg *cmdBuf, s32 cmdMsgCnt) {
    u32 savedMask;
    OSPri oldPri;
    OSPri myPri;

    if (D_80077730.active) {
        return;
    }
    func_80056C40(cmdQ, cmdBuf, cmdMsgCnt);
    func_80056C40(&D_800A1B20, D_800A1B38, 1);

    if (!D_80077760) {
        func_8005ED20();
    }

    func_80057360(8, &D_800A1B20, (OSMesg)0x22222222);
    oldPri = -1;
    myPri = func_800615D0(NULL);

    if (myPri < pri) {
        oldPri = myPri;
        func_800573C0(NULL, pri);
    }

    savedMask = func_800612F0();
    D_80077730.active = 1;
    D_80077730.thread = &D_800A0380;
    D_80077730.cmdQueue = cmdQ;
    D_80077730.evtQueue = &D_800A1B20;
    D_80077730.acsQueue = &D_8010E4B8;
    D_80077730.dma = func_80062BE0;
    D_80077730.edma = func_8005E510;
    func_80056C70(&D_800A0380, 0, func_8005E960, &D_80077730, (u8 *)D_800A0530 + sizeof(D_800A0530), pri);
    func_80057530(&D_800A0380);

    func_80056C70(&D_800A1530, 0, func_8005E42C, NULL, (u8 *)D_800A16E0 + sizeof(D_800A16E0), pri - 1);
    func_80057530(&D_800A1530);
    func_80061310(savedMask);

    if (oldPri != -1) {
        func_800573C0(NULL, oldPri);
    }
}
