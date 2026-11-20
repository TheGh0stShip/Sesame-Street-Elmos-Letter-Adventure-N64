#include "common.h"
#include "game_structs.h"


/* aims the object at a target point and rebuilds its cross-product vector */
void func_800382F0(Actor *arg0) {
    register f32 dx;
    register f32 dz;
    register Actor *o;

    if (D_8011537C == 0) {
        dx = D_80112CE0 - arg0->pos.x;
        dz = D_80109C38 - arg0->pos.z;
        dx = func_80067FB0(dz, dx);
        o = arg0;
        o->fwd.x = __cosf(dx);
        o = arg0;
        o->fwd.z = __sinf(dx);
        arg0->side.x = arg0->fwd.y * arg0->up.z - arg0->fwd.z * arg0->up.y;
        arg0->side.y = arg0->fwd.z * arg0->up.x - arg0->fwd.x * arg0->up.z;
        arg0->side.z = arg0->fwd.x * arg0->up.y - arg0->fwd.y * arg0->up.x;
    } else if (D_8011537C < 0) {
        func_80035828(arg0, 0);
        func_800229DC();
        func_8004A35C(D_80133E3C, 0);
    }
}
