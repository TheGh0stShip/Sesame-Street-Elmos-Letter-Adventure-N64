#include "common.h"
#include "game_structs.h"

extern u16 D_801078BA;

/* Actor state update: triggers on input/timers, otherwise turns to face its target. */
void func_80036B08(Actor *a) {
    register f32 dx;
    register f32 dz;
    register Actor *p;

    if (D_8012EFCD == 0) {
        if ((D_8006EDD8 & 2) && (D_80115374 == 0)) {
            D_8012EFCD = 1;
            a->u.walker.unk_200 = a->u.walker.unk_200 | 1;
            a->u.walker.unk_200 = a->u.walker.unk_200 | 2;
        }
    } else if ((a->u.walker.frame >= 50) && (u16)(D_801078BA & 0xC00F)) {
        if (D_80115374 != 0) {
            D_8013C650 = D_80109C3E >> 3;
            osStopTimer(D_8012EF88);
        }
        D_8012FCE0 = 0x11;
        func_80035828(a, 0x23);
    }
    if (a->u.walker.frame >= 20) {
        if (a->u.walker.turning != 0) {
            if (D_80115374 != 0) {
                D_8013C650 = D_80109C3E >> 3;
                osStopTimer(D_8012EF88);
            }
            func_80035828(a, 1);
            return;
        }
    } else {
        dx = a->u.walker.unk_1F0.l0.unk_1F0->pos.x - a->pos.x;
        dz = a->u.walker.unk_1F0.l0.unk_1F0->pos.z - a->pos.z;
        dz = func_80067FB0(dz, dx);
        p = a;
        p->u.walker.goalDir.x = __cosf(dz);
        p = a;
        p->u.walker.goalDir.z = __sinf(dz);
    }
}
