#include "common.h"
#include "game_structs.h"

/* distance check against player object; triggers on close approach */
void func_80030C80(Actor *arg0) {
    register Actor *o = arg0;
    register f32 dx;
    register f32 dz;
    s32 pad;
    if (D_800ACC2E != 0) return;
    if (D_80109B8C >= 5) {
        if (D_80109B8C >= 8) o->unk_C.l1.flags |= 1;
        return;
    }
    dx = o->pos.x - (*(Actor *(*))&D_80106888)->pos.x;
    dz = o->pos.z - (*(Actor *(*))&D_80106888)->pos.z;
    dx = dx * dx;
    dz = dz * dz;
    dz = dz + dx;
    if (dz < 300000.0) {
        func_80035828((*(Actor *(*))&D_80106888), 0x22);
        o->unk_C.l1.flags |= 1;
        o->unk_C.l1.update = 0;
    }
}
