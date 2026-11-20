#include "common.h"
#include "game_structs.h"

extern Unk8 D_80073EE0[];
extern Unk8 D_80073FF0[];
extern Unk8 D_80074100[];
extern Unk8 D_800742A8[];

/* Turns the actor towards a fixed point, then starts the next sequence. */
void func_800377FC(Actor *a) {
    f32 target[3];
    f32 p[3];
    f32 v[3];
    f32 cur;
    f32 diff;
    f64 len;
    register Actor *r;

    if (D_800745F8 != 0 && D_80076220 == 0) {
        target[0] = 8.9f;
        target[1] = 84.2f;
        target[2] = -208.3f;
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
        D_80076220 = 1;
    } else if (a->u.walker.unk_1F0.l2.unk_1F0 != 4) {
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
            a->u.walker.unk_1F0.l2.unk_1F0 = 4;
            func_800356D0(a, 0x12);
            a->unk_C.l1.flags = a->unk_C.l1.flags & ~0x80;
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
    } else if (D_80115374 == NULL) {
        if (D_80106870 == 0) {
            D_80115374 = D_80073790;
            D_80115258 = &D_80073EE0[D_800745F4];
            D_8013E680 = &D_80073FF0[D_800745F5];
            func_80035828(a, 0x21);
            D_80076220 = 0;
        } else {
            D_80115374 = D_80073790;
            D_80115258 = &D_80074100[D_800745F4];
            D_8013E680 = &D_800742A8[D_800745F5];
            func_80035828(a, 0x21);
            D_80076220 = 0;
        }
        osSendMesg(D_8013ED88, 0, 1);
    }
}
