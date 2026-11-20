typedef struct SndCmd {
    s32 unk_00;
    s16 unk_04;
} SndCmd;
extern u8 D_8013ED88[];
extern u8 D_80109BA8[];
extern u8 D_8012EF88[];
extern SndCmd *D_80115374;
extern SndCmd *D_80115258;
extern SndCmd *D_8013E680;
extern u16 D_800A7AF8;
extern s16 D_80109C3E;
void func_80056C40(void *, void *, s32);
s32 func_80057100(void *, void *, s32);
void func_80057490(void *, u64, u64, void *, void *);
void func_80051418(u16);
u16 func_80051314(s32, s32, s32);

/* sound sequencing thread: plays a command list, waiting on a timer between entries */
void func_80012FA0(void *arg0) {
    void *msg;

    func_80056C40(D_8013ED88, D_80109BA8, 1);
    D_80115374 = NULL;
    while (1) {
        func_80057100(D_8013ED88, NULL, 1);
        if (D_80115374 != NULL) {
            if (D_80115374->unk_04 == 0) {
                D_80115374 = NULL;
            } else {
                if (D_80115374->unk_00 == -1) {
                    func_80057490(D_8012EF88, (s64)D_80115374->unk_04 * 46875, 0, D_8013ED88, NULL);
                } else if (D_80115374->unk_04 == -1) {
                    if (D_80115258 != NULL) {
                        func_80051418(D_800A7AF8);
                        D_800A7AF8 = func_80051314(D_80115258->unk_00, 0x40, 0x7FFF);
                        D_80109C3E = 0x7FFF;
                        func_80057490(D_8012EF88, (s64)D_80115258->unk_04 * 46875, 0, D_8013ED88, NULL);
                    }
                } else if (D_80115374->unk_04 == -2) {
                    if (D_8013E680 != NULL) {
                        func_80051418(D_800A7AF8);
                        D_800A7AF8 = func_80051314(D_8013E680->unk_00, 0x40, 0x7FFF);
                        D_80109C3E = 0x7FFF;
                        func_80057490(D_8012EF88, (s64)D_8013E680->unk_04 * 46875, 0, D_8013ED88, NULL);
                    }
                } else {
                    func_80051418(D_800A7AF8);
                    D_800A7AF8 = func_80051314(D_80115374->unk_00, 0x40, 0x7FFF);
                    D_80109C3E = 0x7FFF;
                    func_80057490(D_8012EF88, (s64)D_80115374->unk_04 * 46875, 0, D_8013ED88, NULL);
                }
                D_80115374++;
            }
        }
    }
}
