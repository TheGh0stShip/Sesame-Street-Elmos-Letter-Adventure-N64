/* osCreateViManager (vimgr.c) */
typedef s32 OSPri;
typedef void *OSMesg;
typedef struct OSMesgQueue_s { u8 data[0x18]; } OSMesgQueue;
typedef struct { u8 data[0x1B0]; } OSThread;
typedef struct {
    u16 type;
    u8 pri;
    u8 status;
    OSMesgQueue *retQueue;
} OSIoMesgHdr;
typedef struct {
    OSIoMesgHdr hdr;
    void *dramAddr;
    u32 devAddr;
    u32 size;
    void *piHandle;
} OSIoMesg;
typedef struct {
    s32 active;
    OSThread *thread;
    OSMesgQueue *cmdQueue;
    OSMesgQueue *evtQueue;
    OSMesgQueue *acsQueue;
    s32 (*dma)();
    s32 (*edma)();
} OSDevMgr;

extern OSDevMgr D_80077860;        /* __osViDevMgr */
extern OSThread D_800A2068;        /* viThread */
extern u64 D_800A2220[0x1000 / 8]; /* viThreadStack */
extern OSMesgQueue D_800A3220;     /* viEventQueue */
extern OSMesg D_800A3238[5];       /* viEventBuf */
extern OSIoMesg D_800A3250;        /* viRetraceMsg */
extern OSIoMesg D_800A3268;        /* viCounterMsg */

void func_80057750(void);
void func_80056C40(OSMesgQueue *mq, OSMesg *msg, s32 count);
void func_80057360(u32 e, OSMesgQueue *mq, OSMesg m);
OSPri func_800615D0(OSThread *t);
void func_800573C0(OSThread *t, OSPri p);
u32 func_800612F0(void);
void func_80056C70(OSThread *t, s32 id, void (*entry)(void *), void *arg, void *sp, OSPri p);
void func_80062180(void);
void func_80057530(OSThread *t);
void func_80061310(u32);
void func_800624A8(void *arg); /* viMgrMain */

void func_80062310(OSPri pri)
{
    u32 savedMask;
    OSPri oldPri;
    OSPri myPri;

    if (D_80077860.active) {
        return;
    }
    func_80057750();
    func_80056C40(&D_800A3220, D_800A3238, 5);
    D_800A3250.hdr.type = 13;
    D_800A3250.hdr.pri = 0;
    D_800A3250.hdr.retQueue = NULL;
    D_800A3268.hdr.type = 14;
    D_800A3268.hdr.pri = 0;
    D_800A3268.hdr.retQueue = NULL;
    func_80057360(7, &D_800A3220, &D_800A3250);
    func_80057360(3, &D_800A3220, &D_800A3268);
    oldPri = -1;
    myPri = func_800615D0(NULL);
    if (myPri < pri) {
        oldPri = myPri;
        func_800573C0(NULL, pri);
    }
    savedMask = func_800612F0();
    D_80077860.active = 1;
    D_80077860.thread = &D_800A2068;
    D_80077860.cmdQueue = &D_800A3220;
    D_80077860.evtQueue = &D_800A3220;
    D_80077860.acsQueue = NULL;
    D_80077860.dma = NULL;
    D_80077860.edma = NULL;
    func_80056C70(&D_800A2068, 0, func_800624A8, &D_80077860, (u8 *)D_800A2220 + 0x1000, pri);
    func_80062180();
    func_80057530(&D_800A2068);
    func_80061310(savedMask);
    if (oldPri != -1) {
        func_800573C0(NULL, oldPri);
    }
}
