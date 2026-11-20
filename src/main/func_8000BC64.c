typedef struct { u8 data[0x1B0]; } OSThread;
typedef struct { u8 data[0x18]; } OSMesgQueue;
typedef struct { u8 data[0x80D0]; } Frame;
typedef struct { s16 type; } Msg;

extern OSThread D_8013EBD8;
extern OSThread D_8013EDA0;
extern OSThread D_800A8DE8;
extern u8 D_800AEC40[];
extern u8 D_80107B20[];
extern u8 D_8013E660[];
extern OSMesgQueue D_8010E490;
extern OSMesgQueue D_8012EF88;
extern u8 D_800ACC2C;
extern u8 D_800ACC2E;
extern s32 D_8006D500;
extern s32 D_80106880;
extern u16 D_800A7AA8;
extern u16 D_8013C650;
extern u16 D_80109C3E;
extern u16 D_800A7AF8;
extern s32 D_80115374;
extern s32 D_8011525C;
extern s64 D_800A75F8;
extern s64 D_80140F98;
extern s32 D_80070760;
extern Frame D_80118100[];
extern s64 D_801078E8;
extern s64 D_80118160;
extern s64 D_80120230;

void func_80012FA0(void *arg);
void func_8000BA70(void *arg);
void func_80026920(void *arg);
void func_8000C164(void);
void func_80056C70(OSThread *t, s32 id, void (*entry)(void *), void *arg, void *sp, s32 pri);
void func_80057530(OSThread *t);
s32 func_80057100(OSMesgQueue *q, Msg **msg, s32 flag);
void func_8005DD20(OSMesgQueue *q);
void func_80051418(u16 a);
void func_80020D30(void);
s64 func_80056D40(void);
void func_80040284(s32 a);
void func_8000B470(Frame *f);
void func_80057650(OSMesgQueue *q);
void func_8005DC20(s32 a);
void func_8004CDC8(s32 a, s32 b);
void func_80001000(void);

/* Main game thread: starts the worker threads, then dispatches messages forever. */
void func_8000BC64(void *arg) {
    volatile u32 count;
    s32 flag;
    Msg *msg;
    volatile s32 idle;
    s64 t;
    s32 unk_30;
    s32 unk_34;
    s32 unk_38[2];

    count = 0;
    flag = 0;
    msg = NULL;
    idle = 0;
    D_800ACC2C = 0;
    unk_30 = 0;
    unk_34 = 0;
    func_8000C164();
    func_80056C70(&D_8013EBD8, 0, func_80012FA0, NULL, D_800AEC40, 12);
    func_80057530(&D_8013EBD8);
    func_80056C70(&D_8013EDA0, 0, func_8000BA70, NULL, D_80107B20, 20);
    func_80057530(&D_8013EDA0);
    func_80056C70(&D_800A8DE8, 0, func_80026920, NULL, D_8013E660, 1);
    func_80057530(&D_800A8DE8);
    while (1) {
        func_80057100(&D_8010E490, &msg, 1);
        switch (msg->type) {
            case 1:
                if (D_800ACC2C == 0) {
                    if (D_8006D500 != 0 && flag == 0) {
                        flag = 1;
                        func_8005DD20(&D_8010E490);
                    }
                    D_80106880++;
                    D_800A7AA8++;
                    if (D_8013C650 != 0) {
                        D_80109C3E -= D_8013C650;
                        if (D_80109C3E < 100) {
                            D_8013C650 = 0;
                            func_80051418(D_800A7AF8);
                            D_80115374 = 0;
                        }
                    }
                    func_80020D30();
                    D_800ACC2E = 0;
                    t = func_80056D40();
                    func_80040284(D_8011525C);
                    D_800A75F8 = func_80056D40() - t;
                    if (count < 2) {
                        t = func_80056D40();
                        func_8000B470(&D_80118100[D_80070760]);
                        D_80140F98 = func_80056D40() - t;
                        count++;
                        D_80070760 ^= 1;
                        idle = 0;
                    } else {
                        idle++;
                    }
                } else if (D_800ACC2C == 1) {
                    D_800ACC2C = 2;
                    func_80057650(&D_8012EF88);
                    func_8005DC20(1);
                    D_80115374 = 0;
                    func_80051418(D_800A7AF8);
                    func_8004CDC8(3, 0);
                }
                break;
            case 6:
                D_801078E8 = D_80118160;
                count--;
                break;
            case 7:
                D_801078E8 = D_80120230;
                count--;
                break;
            case 5:
                func_80001000();
                flag = 0;
                break;
            case 4:
                if (D_800ACC2C == 0) {
                    D_800ACC2C = 1;
                    func_8004CDC8(3, 4);
                }
                break;
        }
    }
}
