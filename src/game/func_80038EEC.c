#include "common.h"
#include "game_structs.h"


/* turns obj toward a target point and rebuilds a cross product, or ends on negative state */
void func_80038EEC(Actor *obj) {
    register f32 a;
    register f32 b;

    if (D_8011537C == 0) {
        a = D_80112CE0 - obj->pos.x;
        b = D_80109C38 - obj->pos.z;
        a = func_80067FB0(b, a);
        obj->fwd.x = (a = a, __cosf(a));
        obj->fwd.z = (a = a, __sinf(a));
        obj->side.x = obj->fwd.y * obj->up.z - obj->fwd.z * obj->up.y;
        obj->side.y = obj->fwd.z * obj->up.x - obj->fwd.x * obj->up.z;
        obj->side.z = obj->fwd.x * obj->up.y - obj->fwd.y * obj->up.x;
    } else if (D_8011537C < 0) {
        func_80035828(obj, 0x13);
        func_800229DC();
        func_8004A35C(D_80133E3C, 0);
    }
}
