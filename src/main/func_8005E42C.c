/* thread loop: create two queues bound to events 0x12/0x13, then forever wait on the first, poll until ready, wait on the second */
extern char D_800A1AE0[];
extern char D_800A1AF8[];
extern char D_800A1B00[];
extern char D_800A1B18[];
void func_80056C40(void *mq, void *msg, s32 count);  /* osCreateMesgQueue */
void func_80057360(s32 ev, void *mq, s32 msg);       /* osSetEventMesg */
s32 func_80057100(void *mq, void *msg, s32 flag);    /* osRecvMesg */
void func_8005ED74(void);
s32 func_80061AD0(void *buf, s32, s32);
void func_8005EDE0(void);
void func_8005E42C(void)
{
    u8 buf[8];
    s32 n;

    func_80056C40(D_800A1AE0, D_800A1AF8, 1);
    func_80056C40(D_800A1B00, D_800A1B18, 1);
    func_80057360(0x12, D_800A1AE0, 0);
    func_80057360(0x13, D_800A1B00, 0);
    for (;;) {
        func_80057100(D_800A1AE0, 0, 1);
        func_8005ED74();
        n = 0;
        do {
            n += func_80061AD0(buf, 1, 9);
        } while (n == 0);
        func_80057100(D_800A1B00, 0, 1);
        func_8005EDE0();
    }
}
