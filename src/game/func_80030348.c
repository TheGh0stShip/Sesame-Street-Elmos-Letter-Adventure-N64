#include "common.h"
#include "game_structs.h"


/* builds the object's view matrix, or places it 1100 units from the player at height 225 */
void func_80030348(Actor *arg0) {
    Mtx44 m0;
    Mtx44 m1;
    Mtx44 m2;
    register Actor *o = arg0;
    register f32 dx;
    register f32 dz;
    register f32 s;

    if (D_800ACC2E != 0) {
        ((void (*)(Mtx44 *, u8 *, s32, f32, f32, f32, f32))guPerspectiveF)(&m0, (*(u8 (*)[])&D_800A7A90), D_80108DB4, 320.0 / D_800B0C92, 50.0f, 10000.0f, 1.0f);
        guLookAtF(&m1, o->pos.x, o->pos.y, o->pos.z, o->fwd.x, o->fwd.y, o->fwd.z, o->up.x, o->up.y, o->up.z);
        guMtxCatF(&m1, &m0, &m2);
        guMtxF2L(&m2, D_8013EF68);
        addActorDL(func_800302B8, o, 1, 0, 0);
    } else {
        dx = (*(Actor *(*))&D_80106888)->pos.x - o->fwd.x;
        dz = (*(Actor *(*))&D_80106888)->pos.z - o->fwd.z;
        s = 1100.0 / sqrtf(dx * dx + dz * dz);
        dx = dx * s;
        dz = dz * s;
        o->pos.x = (*(Actor *(*))&D_80106888)->pos.x + dx;
        o->pos.y = 225.0f;
        o->pos.z = (*(Actor *(*))&D_80106888)->pos.z + dz;
    }
}
