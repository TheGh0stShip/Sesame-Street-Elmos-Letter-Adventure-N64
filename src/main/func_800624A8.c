/* viMgrMain (vimgr.c) */
typedef void *OSMesg;
typedef struct OSMesgQueue_s OSMesgQueue;
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
    void *thread;
    OSMesgQueue *cmdQueue;
    OSMesgQueue *evtQueue;
    OSMesgQueue *acsQueue;
    s32 (*dma)();
    s32 (*edma)();
} OSDevMgr;
typedef struct {
    u16 state;
    u16 retraceCount;
    void *framep;
    void *modep;
    u32 control;
    OSMesgQueue *msgq;
    OSMesg msg;
} __OSViContext;

extern u16 D_800A2060; /* retrace */
extern u32 D_800BD45C; /* __osViIntrCount */
extern u64 D_80109C30; /* __osCurrentTime */
extern u32 D_800A7AB0; /* __osBaseCounter */
__OSViContext *func_80066C20(void);
s32 func_80057100(OSMesgQueue *mq, OSMesg *msg, s32 flag);
void func_80062740(void);
s32 func_80057230(OSMesgQueue *mq, OSMesg msg, s32 flag);
u32 func_80061250(void);
void func_800577A4(void);

void func_800624A8(void *arg)
{
    __OSViContext *vc;
    OSDevMgr *dm;
    OSIoMesg *mb;
    s32 first;
    u32 count;

    mb = NULL;
    first = 0;
    vc = func_80066C20();
    D_800A2060 = vc->retraceCount;
    if (D_800A2060 == 0) {
        D_800A2060 = 1;
    }
    dm = (OSDevMgr *)arg;

    while (1) {
        func_80057100(dm->evtQueue, (OSMesg *)&mb, 1);
        switch (mb->hdr.type) {
            case 13:
                func_80062740();
                D_800A2060--;
                if (D_800A2060 == 0) {
                    vc = func_80066C20();
                    if (vc->msgq != NULL) {
                        func_80057230(vc->msgq, vc->msg, 0);
                    }
                    D_800A2060 = vc->retraceCount;
                }
                D_800BD45C++;
                if (first) {
                    count = func_80061250();
                    D_80109C30 = count;
                    first = 0;
                }
                count = D_800A7AB0;
                D_800A7AB0 = func_80061250();
                count = D_800A7AB0 - count;
                D_80109C30 = D_80109C30 + count;
                break;
            case 14:
                func_800577A4();
                break;
            default:
                break;
        }
    }
}
