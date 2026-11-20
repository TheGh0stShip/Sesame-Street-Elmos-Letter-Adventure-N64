/* one-time creates a queue bound to OS event 15, stores two values, polls func_80061AD0 until it succeeds, then waits for the event */
typedef void *OSMesg;
typedef struct OSMesgQueue_s {
    void *mtqueue;
    void *fullqueue;
    s32 validCount;
    s32 first;
    s32 msgCount;
    OSMesg *msg;
} OSMesgQueue;
extern s32 D_800777E0;
extern OSMesgQueue D_800A2000;
extern OSMesg D_800A2018[];
extern s32 D_8012FD2C;
extern s32 D_8010689C;
void func_80056C40(OSMesgQueue *mq, OSMesg *msg, s32 count);  /* osCreateMesgQueue */
void func_80057360(s32 event, OSMesgQueue *mq, OSMesg msg);   /* osSetEventMesg */
s32 func_80057100(OSMesgQueue *mq, OSMesg *msg, s32 flag);    /* osRecvMesg */
s32 func_80061AD0(void *buf, s32 a, s32 b);
void func_80061CF0(s32 a, s32 b) {
    s32 buf[2];
    s32 done = 0;
    if (D_800777E0 == 0) {
        func_80056C40(&D_800A2000, D_800A2018, 1);
        func_80057360(15, &D_800A2000, NULL);
        D_800777E0 = 1;
    }
    D_8012FD2C = a;
    D_8010689C = b;
    do {
        done += func_80061AD0(buf, 1, 5);
    } while (done == 0);
    func_80057100(&D_800A2000, NULL, 1);
}
