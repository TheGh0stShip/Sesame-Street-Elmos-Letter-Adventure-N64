typedef struct {
    s8 unk_0;
    s8 unk_1;
    union {
        u16 h;
        s8 b;
    } unk_2;
} Sub1D4;

typedef struct {
    u8 unk_00[0x40];
} Sub40;

typedef struct {
    f32 x, y, z;
} Vec3;

typedef struct {
    u8 pad0[0xC];
    s32 unk_0C;
    u8 pad10[0x24 - 0x10];
    f32 unk_24[3];
    u8 pad30[0xE8 - 0x30];
    Sub40 unk_E8[3];
    Vec3 unk_1A8;
    u8 pad1B4[0x1D4 - 0x1B4];
    Sub1D4 unk_1D4;
    u8 pad1D8[0x1F0 - 0x1D8];
    s32 unk_1F0;
} Obj;

extern void func_80001424(void (*)(), void *, s32, s32, f32);
extern s32 func_80012B60(f32 *);
extern void func_8001F1C8(Sub40 *, f32 *, Vec3);
extern f64 func_80022D8C(f32 *);
extern void func_800246EC(Sub1D4 *);
extern void func_80024C1C();
extern s32 D_80070760;
extern u8 D_800ACC2E;
extern s32 D_80109B8C;

/* per-frame update: applies offset, calls placement, then registers a callback */
void func_80024820(void *arg) {
    Obj *obj = arg;
    register f32 dx;
    register f32 dz;

    obj = arg;
    if (D_800ACC2E == 0) {
        if (obj->unk_1D4.unk_2.h != 0) {
            func_800246EC(&obj->unk_1D4);
        }
        return;
    }
    if (D_80109B8C >= 5) {
        if (D_80109B8C >= 8) {
            obj->unk_0C |= 1;
        }
        return;
    }
    if (func_80012B60(obj->unk_24) == 0) {
        return;
    }
    if (obj->unk_1D4.unk_2.h != 0) {
        dx = (f32)(obj->unk_1D4.unk_0 * obj->unk_1D4.unk_2.b) * 0.001;
        dz = (f32)(obj->unk_1D4.unk_1 * obj->unk_1D4.unk_2.b) * 0.001;
        obj->unk_24[0] += dx;
        obj->unk_24[2] += dz;
    }
    func_8001F1C8(&obj->unk_E8[D_80070760], obj->unk_24, obj->unk_1A8);
    if (obj->unk_1D4.unk_2.h != 0) {
        obj->unk_24[0] -= dx;
        obj->unk_24[2] -= dz;
    }
    func_80001424(func_80024C1C, obj, obj->unk_1F0, 1, func_80022D8C(obj->unk_24));
}
