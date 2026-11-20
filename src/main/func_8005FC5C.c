/* __scHandleRetrace: per-retrace scheduling and client notification */
typedef void *OSMesg;
typedef s32 OSPri;
typedef u32 OSIntMask;
typedef u64 OSTime;
typedef struct { void *mtqueue; void *fullqueue; s32 validCount; s32 first; s32 msgCount; OSMesg *msg; } OSMesgQueue;
typedef struct {
    u32 type; u32 flags;
    u64 *ucode_boot; u32 ucode_boot_size;
    u64 *ucode; u32 ucode_size;
    u64 *ucode_data; u32 ucode_data_size;
    u64 *dram_stack; u32 dram_stack_size;
    u64 *output_buff; u64 *output_buff_size;
    u64 *data_ptr; u32 data_size;
    u64 *yield_data_ptr; u32 yield_data_size;
} OSTask_t;
typedef union { OSTask_t t; long long force_structure_alignment; } OSTask;
typedef struct { s16 type; s8 misc[30]; } OSScMsg;
typedef struct OSScTask_s {
    struct OSScTask_s *next;
    u32 state;
    u32 flags;
    void *framebuffer;
    OSTask list;
    OSMesgQueue *msgQ;
    OSMesg msg;
    OSTime startTime;
    OSTime totalTime;
} OSScTask;
typedef struct SCClient_s { struct SCClient_s *next; OSMesgQueue *msgQ; } OSScClient;
typedef struct {
    OSScMsg retraceMsg;
    OSScMsg prenmiMsg;
    OSMesgQueue interruptQ;
    OSMesg intBuf[8];
    OSMesgQueue cmdQ;
    OSMesg cmdMsgBuf[8];
    u8 thread[0x1B0]; /* OSThread */
    OSScClient *clientList;
    OSScTask *audioListHead;
    OSScTask *gfxListHead;
    OSScTask *audioListTail;
    OSScTask *gfxListTail;
    OSScTask *curRSPTask;
    OSScTask *curRDPTask;
    u32 frameCount;
    s32 doAudio;
} OSSched;
s32 func_80057100(OSMesgQueue *, OSMesg *, s32); /* osRecvMesg */
s32 func_80057230(OSMesgQueue *, OSMesg, s32); /* osSendMesg */
void func_80060034(OSSched *, OSScTask *); /* __scAppendList */
void func_80060168(OSSched *); /* __scYield */
s32 func_800601A0(OSSched *, OSScTask **, OSScTask **, s32); /* __scSchedule */
void func_8006008C(OSSched *, OSScTask *, OSScTask *); /* __scExec */
void func_800615CC(OSSched *sc)
{
    OSScTask *rspTask;
    OSScClient *client;
    s32 i;
    s32 state;
    OSScTask *sp = 0;
    OSScTask *dp = 0;
    sc->frameCount++;
    while (func_80057100(&sc->cmdQ, (OSMesg *)&rspTask, 0) != -1) {
        func_80060034(sc, rspTask);
    }
    if (sc->doAudio && sc->curRSPTask) {
        func_80060168(sc);
    } else {
        state = (sc->curRSPTask == 0) << 1; if (sc->curRDPTask == 0) state |= 1;
        if (func_800601A0(sc, &sp, &dp, state) != state)
            func_8006008C(sc, sp, dp);
    }
    for (client = sc->clientList; client != 0; client = client->next) {
        func_80057230(client->msgQ, (OSMesg)&sc->retraceMsg, 0);
    }
}
