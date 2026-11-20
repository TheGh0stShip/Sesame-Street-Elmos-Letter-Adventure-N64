typedef struct Actor {
    u8 pad0[0x24];
    f32 unk_24;
    f32 unk_28;
    f32 unk_2C;
    f32 fwd[3]; /* 0x30 */
    f32 up[3];  /* 0x3C */
    f32 side[3]; /* 0x48 */
} Actor;

extern s32 D_8011537C;
extern f32 D_80112CE0;
extern f32 D_80109C38;
extern void *D_80133E3C;
extern f64 func_80067FB0(f64, f64);
extern f32 func_80054D30(f32);
extern f32 func_80056500(f32);
extern void func_80035828(Actor *, s32);
extern void func_800229DC(void);
extern void func_8004A35C(void *, s32);

/* Turns the actor to face a target point and rebuilds its side vector; otherwise handles a negative state. */
void func_80039F54(Actor *a) {
    register f32 dx;
    register f32 dz;
    register Actor *r;

    if (D_8011537C == 0) {
        dx = D_80112CE0 - a->unk_24;
        dz = D_80109C38 - a->unk_2C;
        dx = func_80067FB0(dz, dx);
        r = a;
        r->fwd[0] = func_80054D30(dx);
        r = a;
        r->fwd[2] = func_80056500(dx);
        a->side[0] = a->fwd[1] * a->up[2] - a->fwd[2] * a->up[1];
        a->side[1] = a->fwd[2] * a->up[0] - a->fwd[0] * a->up[2];
        a->side[2] = a->fwd[0] * a->up[1] - a->fwd[1] * a->up[0];
    } else if (D_8011537C < 0) {
        func_80035828(a, 0x1A);
        func_800229DC();
        func_8004A35C(D_80133E3C, 0);
    }
}
