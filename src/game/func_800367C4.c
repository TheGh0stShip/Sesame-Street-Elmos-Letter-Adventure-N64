#include "common.h"
#include "game_structs.h"

extern u16 D_801078BA;

void func_800367C4(Actor *p) {
    register f32 dx;
    register f32 dz;

    if (D_800A75EC == 0) {
        if ((D_8006EDD8 & 2) && D_80115374 == 0) {
            D_800A75EC = 1;
            p->u.walker.unk_200 = p->u.walker.unk_200 | 1;
            p->u.walker.unk_200 = p->u.walker.unk_200 | 2;
        }
    } else if (p->u.walker.frame >= 50 && (D_801078BA & 0xC00F)) {
        if (D_80115374 != 0) {
            D_8013C650 = D_80109C3E >> 3;
            osStopTimer(&D_8012EF88);
        }
        D_8012FCE0 = 13;
        func_80035828(p, 0x23);
    }
    if (p->u.walker.frame >= 20) {
        if (p->u.walker.turning != 0) {
            if (D_80115374 != 0) {
                D_8013C650 = D_80109C3E >> 3;
                osStopTimer(&D_8012EF88);
            }
            func_80035828(p, 1);
            return;
        }
        return;
    }
    dx = p->u.walker.unk_1F0.l0.unk_1F0->pos.x - p->pos.x;
    dz = p->u.walker.unk_1F0.l0.unk_1F0->pos.z - p->pos.z;
    dz = func_80067FB0(dz, dx);
    { register Actor *q = p; q->u.walker.goalDir.x = __cosf(dz); }
    { register Actor *q = p; q->u.walker.goalDir.z = __sinf(dz); }
}
