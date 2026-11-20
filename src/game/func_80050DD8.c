#include "common.h"

typedef struct {
    s32 unk_0;
    s32 unk_4;
    void *unk_8;
    void *unk_C;
} Req;

typedef struct {
    void (*unk_0)(void *);
    void (*unk_4)(void);
    void (*unk_8)(Req *);
} Ops;

typedef struct {
    s32 unk_0;
    s32 unk_4;
} Slot;
s32 func_8005173C(s32, s32 *, s32, s32);
s32 func_80054910(s32, s32 *, s32, s32);
void osAiSetNextBuffer(s32, s32);
extern Ops *D_800770EC;
extern Slot *D_800770F0;
extern Slot *D_800A0334;
extern s32 D_800A0338;

/* main frame loop: waits for a frame, builds it into one of three slots and submits it */
void func_80050DD8(void) {
    Req req;
    s32 done;
    s32 ready;
    u32 len;
    u32 i;
    Slot *slot;
    s32 end;

    req.unk_8 = D_8006C890;
    req.unk_C = D_80079200;
    req.unk_0 = D_800A0338;
    i = 0;
    D_800770EC->unk_0(D_800770EC);
    for (;;) {
        do {
            D_800770EC->unk_4();
            ready = func_8005D8D0();
            len = func_8005D8C0() >> 2;
        } while (ready < 0);
        func_80050814();
        if ((D_800770F0 != NULL) & (done != 0)) {
            osAiSetNextBuffer(D_800770F0->unk_0, D_800770F0->unk_4 * 4);
        }
        slot = &D_800A0334[i];
        slot->unk_4 = func_80051D54(len);
        end = func_80054910(D_800A0338, &done, osVirtualToPhysical(slot->unk_0), slot->unk_4);
        func_800511D4();
        end = func_8005173C(end, &done, osVirtualToPhysical(slot->unk_0), slot->unk_4);
        if (done != 0) {
            req.unk_4 = ((end - D_800A0338) >> 3) * 8;
            D_800770EC->unk_8(&req);
            D_800770F0 = slot;
        }
        i = (i + 1) % 3;
    }
}
