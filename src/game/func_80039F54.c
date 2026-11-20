#include "common.h"
#include "game_structs.h"


/* Turns the actor to face a target point and rebuilds its side vector; otherwise handles a negative state. */
void func_80039F54(Actor *a) {
    register f32 dx;
    register f32 dz;
    register Actor *r;

    if (D_8011537C == 0) {
        dx = D_80112CE0 - a->pos.x;
        dz = D_80109C38 - a->pos.z;
        dx = func_80067FB0(dz, dx);
        r = a;
        r->fwd.x = __cosf(dx);
        r = a;
        r->fwd.z = __sinf(dx);
        a->side.x = a->fwd.y * a->up.z - a->fwd.z * a->up.y;
        a->side.y = a->fwd.z * a->up.x - a->fwd.x * a->up.z;
        a->side.z = a->fwd.x * a->up.y - a->fwd.y * a->up.x;
    } else if (D_8011537C < 0) {
        func_80035828(a, 0x1A);
        func_800229DC();
        func_8004A35C(D_80133E3C, 0);
    }
}
