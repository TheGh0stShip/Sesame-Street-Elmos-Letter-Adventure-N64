#include "common.h"
#include "game_structs.h"

/* The trig calls were statement-expression macros: their results are stored after the target address is loaded. */
#define SINF(x) ({ __cosf(x); })
#define COSF(x) ({ __sinf(x); })
extern f32 D_80109C38;

/* Turns the actor toward a fixed point and computes the cross product of two direction vectors. */
void func_80039714(Actor *arg0) {
    register f32 dx;
    register f32 dz;

    if (D_8011537C == 0) {
        dx = D_80112CE0 - arg0->pos.x;
        dz = D_80109C38 - arg0->pos.z;
        dx = func_80067FB0(dz, dx);
        arg0->fwd.x = SINF(dx);
        arg0->fwd.z = COSF(dx);
        arg0->side.x = arg0->fwd.y * arg0->up.z - arg0->fwd.z * arg0->up.y;
        arg0->side.y = arg0->fwd.z * arg0->up.x - arg0->fwd.x * arg0->up.z;
        arg0->side.z = arg0->fwd.x * arg0->up.y - arg0->fwd.y * arg0->up.x;
    } else if (D_8011537C < 0) {
        func_80035828(arg0, 0x17);
        func_800229DC();
        func_8004A35C(D_80133E3C, 0);
    }
}
