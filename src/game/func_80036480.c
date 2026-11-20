#include "common.h"
#include "game_structs.h"

/* per-frame actor update: arms on a flag, reacts to buttons, then faces its target */
extern u16 D_801078BA;

void func_80036480(Actor *arg0) {
    register Actor *a;
    register f32 dx;
    register f32 dz;

    if (D_800B0C98 == 0) {
        if ((D_8006EDD8 & 2) && (D_80115374 == 0)) {
            D_800B0C98 = 1;
            arg0->u.walker.unk_200 = arg0->u.walker.unk_200 | 1;
            arg0->u.walker.unk_200 = arg0->u.walker.unk_200 | 2;
        }
    } else if ((arg0->u.walker.frame >= 50) && (D_801078BA & 0xC00F)) {
        if (D_80115374 != 0) {
            D_8013C650 = D_80109C3E >> 3;
            osStopTimer(&D_8012EF88);
        }
        D_8012FCE0 = 0x10;
        func_80035828(arg0, 0x23);
    }
    if (arg0->u.walker.frame >= 20) {
        if (arg0->u.walker.turning != 0) {
            if (D_80115374 != 0) {
                D_8013C650 = D_80109C3E >> 3;
                osStopTimer(&D_8012EF88);
            }
            func_80035828(arg0, 1);
            return;
        }
    } else {
        dx = arg0->u.walker.unk_1F0.l0.unk_1F0->pos.x - arg0->pos.x;
        dz = arg0->u.walker.unk_1F0.l0.unk_1F0->pos.z - arg0->pos.z;
        dz = func_80067FB0(dz, dx);
        a = arg0; a->u.walker.goalDir.x = __cosf(dz);
        a = arg0; a->u.walker.goalDir.z = __sinf(dz);
    }
}
