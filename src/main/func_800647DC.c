/* Creates a message queue, binds events 10-13 to it, then creates and starts a manager thread (priority 150) */
typedef void *OSMesg;
typedef struct { s32 data[6]; } OSMesgQueue;
typedef struct { u8 data[0x1B0]; } OSThread;
extern OSMesgQueue D_8013EB18;
extern OSMesg D_800A3550[8];
extern OSThread D_800A33A0;
extern u8 D_800A7570[];
extern u64 D_800A7370[0x40];
extern OSMesg D_800A7590[];
void func_80056C40(OSMesgQueue *mq, OSMesg *msg, s32 count); /* osCreateMesgQueue */
void func_80057360(s32 event, OSMesgQueue *mq, OSMesg msg);  /* osSetEventMesg */
void func_80056C70(OSThread *t, s32 id, void (*entry)(void *), void *arg, void *sp, s32 pri); /* osCreateThread */
void func_8005E260(s32 pri, OSMesg *cmdBuf, void *evtQ, s32 cmdMsgCnt);
void func_80057530(OSThread *t); /* osStartThread */
void func_8005F354(void *);

void func_800647DC(void) {
    func_80056C40(&D_8013EB18, D_800A3550, 8);
    func_80057360(10, &D_8013EB18, (OSMesg)2);
    func_80057360(11, &D_8013EB18, (OSMesg)4);
    func_80057360(12, &D_8013EB18, (OSMesg)8);
    func_80057360(13, &D_8013EB18, (OSMesg)0);
    func_80056C70(&D_800A33A0, 0, func_8005F354, NULL, D_800A7370 + 0x40, 255);
    func_8005E260(150, D_800A7590, D_800A7570, 8);
    func_80057530(&D_800A33A0);
}
