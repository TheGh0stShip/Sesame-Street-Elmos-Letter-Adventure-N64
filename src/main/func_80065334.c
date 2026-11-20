/* __rmonGetRegisterContents */
typedef struct { u8 pad[0x20]; u32 context[1]; } OSThread;
OSThread *func_80065418(s32 threadNumber); /* __rmonGetTCB */
u32 func_80064BD0(s32 regNumber); /* __rmonGetRCPRegister */
u32 func_80065334(s32 method, s32 threadNumber, s32 regNumber) {
    if (method == 0) {
        u32 *regPointer;
        OSThread *tptr;
        if (regNumber >= 1 && regNumber <= 25) {
            regNumber -= 1;
        } else if (regNumber >= 28 && regNumber <= 31) {
            regNumber -= 3;
        } else {
            return 0;
        }
        tptr = func_80065418(threadNumber);
        if (tptr == NULL) {
            return 0;
        }
        regPointer = (u32 *)&tptr->context;
        regPointer += regNumber;
        return *regPointer;
    } else {
        return func_80064BD0(regNumber);
    }
}
