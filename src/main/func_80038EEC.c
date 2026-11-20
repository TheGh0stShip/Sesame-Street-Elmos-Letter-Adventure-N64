typedef struct {
    u8 pad0[0x24];
    f32 unk_24;
    f32 unk_28;
    f32 unk_2C;
    f32 unk_30;
    f32 unk_34;
    f32 unk_38;
    f32 unk_3C;
    f32 unk_40;
    f32 unk_44;
    f32 unk_48;
    f32 unk_4C;
    f32 unk_50;
} Obj;
extern void func_800229DC(void);
extern void func_80035828(Obj *, s32);
extern void func_8004A35C(s32, s32);
extern f32 func_80054D30(f32);
extern f32 func_80056500(f32);
extern f64 func_80067FB0(f64, f64);
extern f32 D_80109C38;
extern f32 D_80112CE0;
extern s32 D_8011537C;
extern s32 D_80133E3C;

/* turns obj toward a target point and rebuilds a cross product, or ends on negative state */
void func_80038EEC(Obj *obj) {
    register f32 a;
    register f32 b;

    if (D_8011537C == 0) {
        a = D_80112CE0 - obj->unk_24;
        b = D_80109C38 - obj->unk_2C;
        a = func_80067FB0(b, a);
        obj->unk_30 = (a = a, func_80054D30(a));
        obj->unk_38 = (a = a, func_80056500(a));
        obj->unk_48 = obj->unk_34 * obj->unk_44 - obj->unk_38 * obj->unk_40;
        obj->unk_4C = obj->unk_38 * obj->unk_3C - obj->unk_30 * obj->unk_44;
        obj->unk_50 = obj->unk_30 * obj->unk_40 - obj->unk_34 * obj->unk_3C;
    } else if (D_8011537C < 0) {
        func_80035828(obj, 0x13);
        func_800229DC();
        func_8004A35C(D_80133E3C, 0);
    }
}
