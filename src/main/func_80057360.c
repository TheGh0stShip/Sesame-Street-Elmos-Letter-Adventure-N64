/* osSetEventMesg */
typedef struct { void *messageQueue; void *message; } __OSEventState;
extern __OSEventState D_80133D78[];
u32 func_800612F0(void); /* __osDisableInt */
void func_80061310(u32 mask); /* __osRestoreInt */
void func_80057360(s32 event, void *mq, void *msg) {
    register u32 saveMask = func_800612F0();
    __OSEventState *es = &D_80133D78[event];
    es->messageQueue = mq;
    es->message = msg;
    func_80061310(saveMask);
}
