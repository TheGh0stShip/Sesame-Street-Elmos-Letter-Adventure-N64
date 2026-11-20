typedef struct Obj { u8 pad0[0x24]; f32 x; f32 pad28; f32 z; f32 unk_30; f32 unk_34; f32 unk_38; f32 unk_3C; f32 unk_40; f32 unk_44; f32 unk_48; f32 unk_4C; f32 unk_50; u8 pad54[0xEC-0x54]; void (*unk_EC)(struct Obj *); } Obj;
extern s32 D_8011537C;
extern f32 D_80112CE0;
extern f32 D_80109C38;
extern void *D_80133E3C;
f64 func_80067FB0(f64, f64);
f32 func_80056500(f32);
f32 func_80054D30(f32);
void func_8002E140(Obj *);
void func_80035828(Obj *, s32);
void func_800229DC(void);
void func_8004A35C(void *, s32);
/* faces the object toward a fixed point and computes a cross product, or switches its update handler */
void func_800386E0(Obj *o) {
    register f32 dx;
    register f32 dz;
    register Obj *p;
    if (D_8011537C == 0) {
        dx = D_80112CE0 - o->x;
        dz = D_80109C38 - o->z;
        dx = func_80067FB0(dz, dx);
        p = o; p->unk_30 = func_80054D30(dx);
        p = o; p->unk_38 = func_80056500(dx);
        o->unk_48 = o->unk_34 * o->unk_44 - o->unk_38 * o->unk_40;
        o->unk_4C = o->unk_38 * o->unk_3C - o->unk_30 * o->unk_44;
        o->unk_50 = o->unk_30 * o->unk_40 - o->unk_34 * o->unk_3C;
    } else {
        o->unk_EC = func_8002E140;
        if (D_8011537C < 0) {
            func_80035828(o, 0xF);
            func_800229DC();
            func_8004A35C(D_80133E3C, 0);
        }
    }
}
