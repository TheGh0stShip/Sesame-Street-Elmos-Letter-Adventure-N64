typedef struct { f32 x, y, z; } Vec3;
typedef struct Actor {
    u8 unk_000[0xC]; s32 flags; u8 unk_010[0x14];
    Vec3 pos; f32 fwd[3]; f32 up[3]; f32 side[3];
    u8 unk_054[0x1B8 - 0x54]; Vec3 dir;
    u8 unk_1C4[0x1F0 - 0x1C4]; s8 unk_1F0; u8 unk_1F1[0x204 - 0x1F1]; s32 unk_204;
} Actor;

void func_80035828(Actor *, s32);
f32 func_80054D20(f32);
f32 func_80054D30(f32);
f32 func_80056500(f32);
f64 func_80067FB0(f64, f64);
f64 fabs(f64);

/* Turns the actor towards a fixed point; when aligned, switches state. */
void func_80036FB8(Actor *a) {
    f32 cur;
    f32 diff;
    f32 target[3];
    f32 v[3];
    f32 p[3];
    f64 len;
    register Actor *r;

    if (a->flags & 8) {
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
        len = func_80054D20(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
        if (len != 0.0) {
            v[0] = v[0] * (1.0 / len);
            v[1] = v[1] * (1.0 / len);
            v[2] = v[2] * (1.0 / len);
        }
        (&a->dir)->x = v[0];
        (&a->dir)->y = v[1];
        (&a->dir)->z = v[2];
        cur = func_80067FB0(a->fwd[0], a->fwd[2]);
        diff = func_80067FB0(a->dir.x, a->dir.z);
        diff = diff - cur;
        if (diff > 3.14159) {
            diff = diff - 6.2831853;
        } else if (diff < -3.14159) {
            diff = diff + 6.2831853;
        }
        if (fabs(diff) < 0.03) {
            a->fwd[0] = a->dir.x;
            a->fwd[1] = a->dir.y;
            a->fwd[2] = a->dir.z;
            a->unk_1F0 = 0;
            func_80035828(a, 0x1F);
        } else {
            cur = cur + diff * 0.2;
            r = a;
            r->fwd[0] = func_80056500(cur);
            r = a;
            r->fwd[2] = func_80054D30(cur);
            a->unk_204 = 1;
        }
        a->side[0] = a->fwd[1] * a->up[2] - a->fwd[2] * a->up[1];
        a->side[1] = a->fwd[2] * a->up[0] - a->fwd[0] * a->up[2];
        a->side[2] = a->fwd[0] * a->up[1] - a->fwd[1] * a->up[0];
    }
}
