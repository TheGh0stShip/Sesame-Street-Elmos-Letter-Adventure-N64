typedef struct { f32 x, y, z; } Vec3;
typedef struct { s32 unk_0; s32 unk_4; } Entry;
typedef struct Actor {
    u8 unk_000[0xC]; s32 flags; u8 unk_010[0x14];
    Vec3 pos; f32 fwd[3]; f32 up[3]; f32 side[3];
    u8 unk_054[0x1B8 - 0x54]; Vec3 dir;
    u8 unk_1C4[0x1F0 - 0x1C4]; u8 unk_1F0; u8 unk_1F1[0x204 - 0x1F1]; s32 unk_204;
} Actor;

void func_800356D0(Actor *, s32);
void func_80035828(Actor *, s32);
f32 func_80054D20(f32);
f32 func_80054D30(f32);
f32 func_80056500(f32);
void func_80057230(void *, s32, s32);
f64 func_80067FB0(f64, f64);
f64 fabs(f64);
extern u8 D_80073790[];
extern Entry D_80073EE0[];
extern Entry D_80073FF0[];
extern Entry D_80074100[];
extern Entry D_800742A8[];
extern u8 D_800745F4;
extern u8 D_800745F5;
extern u8 D_800745F8;
extern u8 D_80076220;
extern u8 D_80106870;
extern Entry *D_80115258;
extern void *D_80115374;
extern Entry *D_8013E680;
extern u8 D_8013ED88[];

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
        len = func_80054D20(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
        if (len != 0.0) {
            v[0] = v[0] * (1.0 / len);
            v[1] = v[1] * (1.0 / len);
            v[2] = v[2] * (1.0 / len);
        }
        (&a->dir)->x = v[0];
        (&a->dir)->y = v[1];
        (&a->dir)->z = v[2];
        D_80076220 = 1;
    } else if (a->unk_1F0 != 4) {
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
            a->unk_1F0 = 4;
            func_800356D0(a, 0x12);
            a->flags = a->flags & ~0x80;
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
        func_80057230(D_8013ED88, 0, 1);
    }
}
