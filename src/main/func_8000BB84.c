/* Boot thread body: start PI manager, rdb, rmon and main threads, then idle forever. */
typedef struct { s32 unk[0x1B0 / 4]; } OSThread;
void func_8005E260(s32 pri, void *cmdQ, void *cmdBuf, s32 cmdMsgCnt); /* osCreatePiManager */
void func_80057B50(void *buf, u32 size); /* osInitRdb */
void func_80056C70(OSThread *t, s32 id, void (*entry)(void *), void *arg, void *sp, s32 pri); /* osCreateThread */
void func_80057530(OSThread *t); /* osStartThread */
void func_800573C0(OSThread *t, s32 pri); /* osSetThreadPri */
void func_8005F0D0(void *); /* rmonMain */
void func_8000BC64(void *);
extern u8 D_80082B70[];
extern u8 D_80082850[];
extern u8 D_801282A8[];
extern OSThread D_800816A0;
extern OSThread D_8007D340;
extern u8 D_8007F6A0[];
void func_8000BB84(void *arg) {
    func_8005E260(150, D_80082B70, D_80082850, 200);
    func_80057B50(D_801282A8, 0x100);
    func_80056C70(&D_800816A0, 0, func_8005F0D0, 0, D_80082850, 250);
    func_80057530(&D_800816A0);
    func_80056C70(&D_8007D340, 6, func_8000BC64, arg, D_8007F6A0, 10);
    func_80057530(&D_8007D340);
    func_800573C0(0, 0);
    for (;;) {
    }
}
