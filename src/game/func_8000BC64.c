#include "common.h"

typedef struct { u8 data[0x80D0]; } Frame;
typedef struct { s16 type; } Msg;

extern OSThread D_8013EBD8;
extern OSThread D_8013EDA0;
extern OSThread D_800A8DE8;
extern Frame D_80118100[];
void func_8000B470(Frame *f);

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
    osCreateThread(&D_8013EBD8, 0, func_80012FA0, NULL, (*(u8 (*)[])&D_800AEC40), 12);
    osStartThread(&D_8013EBD8);
    osCreateThread(&D_8013EDA0, 0, func_8000BA70, NULL, D_80107B20, 20);
    osStartThread(&D_8013EDA0);
    osCreateThread(&D_800A8DE8, 0, func_80026920, NULL, D_8013E660, 1);
    osStartThread(&D_800A8DE8);
    while (1) {
        osRecvMesg(&D_8010E490, &msg, 1);
        switch (msg->type) {
            case 1:
                if (D_800ACC2C == 0) {
                    if ((*(s32 (*))&D_8006D500) != 0 && flag == 0) {
                        flag = 1;
                        osContStartReadData(&D_8010E490);
                    }
                    D_80106880++;
                    D_800A7AA8++;
                    if ((*(u16 (*))&D_8013C650) != 0) {
                        D_80109C3E -= (*(u16 (*))&D_8013C650);
                        if (D_80109C3E < 100) {
                            (*(u16 (*))&D_8013C650) = 0;
                            func_80051418(D_800A7AF8);
                            D_80115374 = 0;
                        }
                    }
                    func_80020D30();
                    D_800ACC2E = 0;
                    t = osGetTime();
                    func_80040284(D_8011525C);
                    D_800A75F8 = osGetTime() - t;
                    if (count < 2) {
                        t = osGetTime();
                        func_8000B470(&D_80118100[D_80070760]);
                        D_80140F98 = osGetTime() - t;
                        count++;
                        D_80070760 ^= 1;
                        idle = 0;
                    } else {
                        idle++;
                    }
                } else if (D_800ACC2C == 1) {
                    D_800ACC2C = 2;
                    osStopTimer(&D_8012EF88);
                    osViBlack(1);
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
