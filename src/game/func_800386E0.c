#include "common.h"
#include "game_structs.h"

/* faces the object toward a fixed point and computes a cross product, or switches its update handler */
void func_800386E0(Actor *o) {
    register f32 dx;
    register f32 dz;
    register Actor *p;
    if (D_8011537C == 0) {
        dx = D_80112CE0 - o->pos.x;
        dz = D_80109C38 - o->pos.z;
        dx = func_80067FB0(dz, dx);
        p = o; p->fwd.x = __cosf(dx);
        p = o; p->fwd.z = __sinf(dx);
        o->side.x = o->fwd.y * o->up.z - o->fwd.z * o->up.y;
        o->side.y = o->fwd.z * o->up.x - o->fwd.x * o->up.z;
        o->side.z = o->fwd.x * o->up.y - o->fwd.y * o->up.x;
    } else {
        o->u.walker.unk_EC.fn = func_8002E140;
        if (D_8011537C < 0) {
            func_80035828(o, 0xF);
            func_800229DC();
            func_8004A35C(D_80133E3C, 0);
        }
    }
}
