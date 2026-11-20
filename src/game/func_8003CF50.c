#include "common.h"

typedef struct { f32 x, y, z; } Vec3;
typedef struct {
    u8 unk_0[0x40];
} Elem40;
typedef struct {
    u8 pad0[0xA];
    u16 unk_A;
    s32 unk_C;
    u8 pad10[0x24 - 0x10];
    Vec3 unk_24;
    Vec3 unk_30;
    Vec3 unk_3C;
    Vec3 unk_48;
    u8 pad54[0x60 - 0x54];
    f32 unk_60;
    f32 unk_64;
    f32 unk_68;
    u8 pad6C[0xE8 - 0x6C];
    Elem40 unk_E8[3];
    u8 pad1A8_[0x1A8 - 0x1A8];
    Vec3 unk_1A8;
    u8 pad1B4[0x1BC - 0x1B4];
    Anim *unk_1BC;
    u8 pad1C0[0x1CC - 0x1C0];
    s32 unk_1CC;
    u8 pad1D0[0x1D8 - 0x1D0];
    u8 unk_1D8;
    u8 unk_1D9;
    u8 unk_1DA;
    u8 unk_1DB;
    u8 unk_1DC;
    u8 unk_1DD;
    u8 unk_1DE;
    u8 unk_1DF;
    f32 unk_1E0;
    u8 pad1E4[4];
    s32 unk_1E8;
    s32 unk_1EC;
    s32 unk_1F0;
    u8 unk_1F4[4];
} Obj;
extern Vec3 D_800768C8[];
extern Vec3 D_8007688C[];
extern Vec3 D_800765C8[];
extern Vec3 D_80076364[];

#define VDOT(a, b) ((a)->x * (b)->x + (a)->y * (b)->y + (a)->z * (b)->z)
#define ANIM_COUNT(a) ((&(a)->unk_4)->unk_0)
#define VSCALE(v, s) { (v)->x = (v)->x * (s); (v)->y = (v)->y * (s); (v)->z = (v)->z * (s); }
#define VCOPY(d, s) { (d)->x = (s)->x; (d)->y = (s)->y; (d)->z = (s)->z; }
#define VSUB(d, a, b) { (d)->x = (a)->x - (b)->x; (d)->y = (a)->y - (b)->y; (d)->z = (a)->z - (b)->z; }
#define ANIM_STEP(obj) \
    if ((obj)->unk_1BC != NULL) { \
        if (!(D_80106880 & 1)) { \
            (obj)->unk_1CC++; \
            if ((obj)->unk_1CC > ANIM_COUNT((obj)->unk_1BC)) { \
                (obj)->unk_C |= 8; \
                if (!((obj)->unk_C & 0x80)) { \
                    (obj)->unk_1CC = 0; \
                } \
            } \
        } \
    }

/* per-frame update of an animated scenery object: faces the camera, then runs its state machine */
void func_8003CF50(Obj *arg0) {
    Obj *obj;
    s32 pad2C;
    f32 mtx[16];
    f32 d2;
    f32 ang;
    f32 dx2;
    f32 dz2;
    f32 thr;
    Vec3 d;
    Vec3 pad98;
    Vec3 padA8;
    Vec3 e;
    Anim **tbl;
    Vec3 tgt;
    Vec3 cur;
    Vec3 padF0;
    Vec3 dir;
    f64 scale = 0;
    f64 len;
    register Obj *pl;

    obj = arg0;
    if (D_800ACC2E != 0) {
        ((void (*)(Elem40 *, Vec3 *, Vec3))func_8001F1C8)(&obj->unk_E8[D_80070760], &obj->unk_24, obj->unk_1A8);
        ((void (*)(s32, u8 *, Anim *, s32, Vec3, Vec3 *, Elem40 *, Obj *))func_8000092C)(obj->unk_1E8, obj->unk_1F4, obj->unk_1BC, obj->unk_1CC, obj->unk_24, &obj->unk_30,
                      &obj->unk_E8[D_80070760], obj);
        if (obj->unk_A == 0x2101 && obj->unk_A == 0x2109) {
            scale = 666666.666;
        }
        addActorDL(func_8003E220, obj, obj->unk_1F0, 1, scale);
        return;
    }
    if (D_80109B8C >= 5) {
        if (D_80109B8C >= 8) {
            obj->unk_C |= 1;
        }
        return;
    }
    if ((*(u8 (*))&D_8012EFCC) != 0) {
        return;
    }
    if (obj->unk_1D8 != 4) {
        e.x = (*(Obj *(*))&D_80112CD0)->unk_60 - obj->unk_24.x;
        e.z = (*(Obj *(*))&D_80112CD0)->unk_68 - obj->unk_24.z;
        ang = func_80067FB0(e.z, e.x);
        obj->unk_30.x = ({ __cosf(ang); });
        obj->unk_30.z = ({ __sinf(ang); });
        len = sqrtf(VDOT(&obj->unk_30, &obj->unk_30));
        if (len != 0.0) {
            VSCALE(&obj->unk_30, 1.0 / len);
        }
        obj->unk_48.x = obj->unk_30.y * obj->unk_3C.z - obj->unk_30.z * obj->unk_3C.y;
        obj->unk_48.y = obj->unk_30.z * obj->unk_3C.x - obj->unk_30.x * obj->unk_3C.z;
        obj->unk_48.z = obj->unk_30.x * obj->unk_3C.y - obj->unk_30.y * obj->unk_3C.x;
    }
    switch (obj->unk_1D8) {
    case 1:
        obj->unk_C |= 0x8000;
        obj->unk_C &= ~0x80;
        if (obj->unk_1BC != NULL) {
            if (!(D_80106880 & 1)) {
                obj->unk_1CC++;
                if (obj->unk_1CC > ANIM_COUNT(obj->unk_1BC)) {
                    obj->unk_C |= 8;
                    if (!(obj->unk_C & 0x80)) {
                        obj->unk_1CC = 0;
                    }
                }
            }
            switch (obj->unk_A) {
            case 0x2601:
                d.x = obj->unk_24.x - (*(Obj *(*))&D_80106888)->unk_24.x;
                d.z = obj->unk_24.z - (*(Obj *(*))&D_80106888)->unk_24.z;
                d2 = d.x * d.x + d.z * d.z;
                if (obj->unk_1DF == 0) {
                    if (d2 < 80000.0) {
                        obj->unk_1DF = 1;
                        func_80017568(0x26);
                    }
                } else if (d2 > 100000.0) {
                    obj->unk_1DF = 0;
                }
                break;
            }
        }
        break;
    case 2:
        switch (obj->unk_1D9) {
        case 1:
            pl = (*(Obj *(*))&D_80106888);
            if (pl == NULL) {
                return;
            }
            d.x = obj->unk_24.x - pl->unk_24.x;
            d.z = obj->unk_24.z - pl->unk_24.z;
            d2 = d.x * d.x + d.z * d.z;
            if (d2 < 160000.0) {
                obj->unk_1D9 = 2;
                obj->unk_1DA = 1;
                obj->unk_1CC = 0;
                obj->unk_C |= 8;
                tbl = D_80076B20[obj->unk_1DB];
                obj->unk_1BC = tbl[obj->unk_1DA];
                switch (obj->unk_A) {
                case 0x3103:
                    func_80017568(0x2C);
                    break;
                default:
                    break;
                }
            }
            break;
        case 2:
            break;
        }
        obj->unk_C |= 0x8000;
        obj->unk_C &= ~0x80;
        if (obj->unk_1BC != NULL && !(D_80106880 & 1)) {
            obj->unk_1CC++;
            if (obj->unk_1CC >= ANIM_COUNT(obj->unk_1BC)) {
                obj->unk_C |= 8;
                obj->unk_1CC = 0;
                obj->unk_1D9 = 1;
                obj->unk_1DA = 0;
                tbl = D_80076B20[obj->unk_1DB];
                obj->unk_1BC = tbl[obj->unk_1DA];
            }
        }
        break;
    case 3:
        switch (obj->unk_1D9) {
        case 1:
            pl = (*(Obj *(*))&D_80106888);
            if (pl == NULL) {
                return;
            }
            d.x = obj->unk_24.x - pl->unk_24.x;
            d.z = obj->unk_24.z - pl->unk_24.z;
            d2 = d.x * d.x + d.z * d.z;
            if (obj->unk_A == 0x4601) {
                thr = 810000.0f;
            } else {
                thr = 160000.0f;
            }
            if (d2 < thr) {
                if (1) {
                    if (obj->unk_A == 0x4601) {
                        obj->unk_1D9 = 4;
                        func_80017568(0x20);
                    } else {
                        obj->unk_1D9 = 2;
                    }
                } else {
                }
            } else {
            }
            break;
        case 2:
            obj->unk_C |= 0x8000;
            obj->unk_C |= 0x80;
            if (obj->unk_1BC != NULL && !(D_80106880 & 1)) {
                obj->unk_1CC++;
                if (obj->unk_1CC >= ANIM_COUNT(obj->unk_1BC)) {
                    obj->unk_1D9 = 3;
                }
            }
            break;
        case 3:
            break;
        case 4:
            obj->unk_C |= 0x8000;
            obj->unk_C &= ~0x80;
            ANIM_STEP(obj);
            if (obj->unk_1DE < 50) {
                if (obj->unk_1DF == 0) {
                    obj->unk_24.x = obj->unk_24.x + 10.0;
                    obj->unk_1DF = 1;
                } else {
                    obj->unk_24.x = obj->unk_24.x - 10.0;
                    obj->unk_1DF = 0;
                }
                obj->unk_1DE++;
            } else {
                D_80076B14 = D_80076B14 + 0.2;
                obj->unk_24.y = obj->unk_24.y + D_80076B14;
                if (obj->unk_24.y > obj->unk_1E0 + 1000.0) {
                    obj->unk_1D9 = 5;
                }
            }
            break;
        case 5:
            obj->unk_C |= 1;
            break;
        }
        break;
    case 4:
        obj->unk_C |= 0x8000;
        obj->unk_C &= ~0x80;
        ANIM_STEP(obj);
        switch (obj->unk_A) {
        case 0x2606:
            tgt.x = D_800768C8[obj->unk_1DC].x;
            tgt.y = D_800768C8[obj->unk_1DC].z;
            tgt.z = D_800768C8[obj->unk_1DC].y;
            break;
        case 0x4603:
            tgt.x = D_8007688C[obj->unk_1DC].x;
            tgt.y = D_8007688C[obj->unk_1DC].z;
            tgt.z = D_8007688C[obj->unk_1DC].y;
            break;
        case 0x2605:
            tgt.x = D_800765C8[obj->unk_1DC].x;
            tgt.y = D_800765C8[obj->unk_1DC].z;
            tgt.z = D_800765C8[obj->unk_1DC].y;
            break;
        case 0x4101:
            tgt.x = D_80076364[obj->unk_1DC].x;
            tgt.y = D_80076364[obj->unk_1DC].z;
            tgt.z = D_80076364[obj->unk_1DC].y;
            break;
        default:
            break;
        }
        VCOPY(&dir, &tgt);
        VCOPY(&cur, &obj->unk_24);
        VSUB(&dir, &dir, &cur);
        len = sqrtf(VDOT(&dir, &dir));
        if (len != 0.0) {
            VSCALE(&dir, 1.0 / len);
        }
        VCOPY(&obj->unk_30, &dir);
        obj->unk_48.x = obj->unk_30.y * obj->unk_3C.z - obj->unk_30.z * obj->unk_3C.y;
        obj->unk_48.y = obj->unk_30.z * obj->unk_3C.x - obj->unk_30.x * obj->unk_3C.z;
        obj->unk_48.z = obj->unk_30.x * obj->unk_3C.y - obj->unk_30.y * obj->unk_3C.x;
        obj->unk_24.x = obj->unk_24.x + dir.x * obj->unk_1E0;
        obj->unk_24.z = obj->unk_24.z + dir.z * obj->unk_1E0;
        dx2 = obj->unk_24.x - tgt.x;
        dx2 = dx2 * dx2;
        dz2 = obj->unk_24.z - tgt.z;
        dz2 = dz2 * dz2;
        if (dx2 + dz2 <= 400.0f) {
            obj->unk_1DC++;
            obj->unk_1DC = obj->unk_1DC % obj->unk_1DD;
        }
        break;
    default:
        break;
    }
}
