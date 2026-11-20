/* __osSiCreateAccessQueue */
typedef void *OSMesg;
typedef struct OSMesgQueue_s {
    void *mtqueue;
    void *fullqueue;
    s32 validCount;
    s32 first;
    s32 msgCount;
    OSMesg *msg;
} OSMesgQueue;
extern u32 D_800785A0;           /* __osSiAccessQueueEnabled */
extern OSMesgQueue D_8013EF50;   /* __osSiAccessQueue */
extern OSMesg D_800A3280[];      /* siAccessBuf */
void func_80056C40(OSMesgQueue *mq, OSMesg *msg, s32 count); /* osCreateMesgQueue */
s32 func_80057230(OSMesgQueue *mq, OSMesg msg, s32 flag);    /* osSendMesg */
void func_80062AF0(void) {
    D_800785A0 = 1;
    func_80056C40(&D_8013EF50, D_800A3280, 1);
    func_80057230(&D_8013EF50, NULL, 0);
}
