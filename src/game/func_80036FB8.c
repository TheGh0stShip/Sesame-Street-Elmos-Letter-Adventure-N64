#include "common.h"
#include "game_structs.h"


/* Turns the actor towards a fixed point; when aligned, switches state. */
void func_80036FB8(Actor *a) {
    f32 cur;
    f32 diff;
    f32 target[3];
    f32 v[3];
    f32 p[3];
    f64 len;
    register Actor *r;

    if (a->unk_C.l1.flags & 8) {
        target[0] = -453.0f;
        target[1] = 0.0f;
        target[2] = -1762.0f;
        v[0] = target[0];
        v[1] = target[1];
        v[2] = target[2];
        p[0] = (&a->pos)->x;
        p[1] = (&a->pos)->y;
        p[2] = (&a->pos)->z;
        v[0] = v[0] - p[0];
        v[1] = v[1] - p[1];
        v[2] = v[2] - p[2];
        len = sqrtf(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
        if (len != 0.0) {
            v[0] = v[0] * (1.0 / len);
            v[1] = v[1] * (1.0 / len);
            v[2] = v[2] * (1.0 / len);
        }
        (&a->u.walker.goalDir)->x = v[0];
        (&a->u.walker.goalDir)->y = v[1];
        (&a->u.walker.goalDir)->z = v[2];
        cur = func_80067FB0(a->fwd.x, a->fwd.z);
        diff = func_80067FB0(a->u.walker.goalDir.x, a->u.walker.goalDir.z);
        diff = diff - cur;
        if (diff > 3.14159) {
            diff = diff - 6.2831853;
        } else if (diff < -3.14159) {
            diff = diff + 6.2831853;
        }
        if (fabs(diff) < 0.03) {
            a->fwd.x = a->u.walker.goalDir.x;
            a->fwd.y = a->u.walker.goalDir.y;
            a->fwd.z = a->u.walker.goalDir.z;
            a->u.walker.unk_1F0.l2.unk_1F0 = 0;
            func_80035828(a, 0x1F);
        } else {
            cur = cur + diff * 0.2;
            r = a;
            r->fwd.x = __sinf(cur);
            r = a;
            r->fwd.z = __cosf(cur);
            a->u.walker.turning = 1;
        }
        a->side.x = a->fwd.y * a->up.z - a->fwd.z * a->up.y;
        a->side.y = a->fwd.z * a->up.x - a->fwd.x * a->up.z;
        a->side.z = a->fwd.x * a->up.y - a->fwd.y * a->up.x;
    }
}
