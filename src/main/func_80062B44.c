/* __osPiGetAccess (with __osPiCreateAccessQueue inlined) */
typedef void *OSMesg;
typedef struct { void *mtqueue; void *fullqueue; s32 validCount; s32 first; s32 msgCount; OSMesg *msg; } OSMesgQueue;
extern s32 D_800785A0;          /* __osPiAccessQueueEnabled */
extern OSMesgQueue D_8013EF50;  /* __osPiAccessQueue */
extern OSMesg D_800A3280[1];    /* piAccessBuf */
void func_80056C40(OSMesgQueue *mq, OSMesg *msg, s32 count); /* osCreateMesgQueue */
s32 func_80057230(OSMesgQueue *mq, OSMesg msg, s32 flag);    /* osSendMesg */
s32 func_80057100(OSMesgQueue *mq, OSMesg *msg, s32 flag);   /* osRecvMesg */
static void __osPiCreateAccessQueue(void) {
    D_800785A0 = 1;
    func_80056C40(&D_8013EF50, D_800A3280, 1);
    func_80057230(&D_8013EF50, NULL, 0);
}
void func_80062B44(void) {
    OSMesg dummyMesg;
    if (!D_800785A0) {
        __osPiCreateAccessQueue();
    }
    func_80057100(&D_8013EF50, &dummyMesg, 1);
}
