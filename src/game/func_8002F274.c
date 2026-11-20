#include "common.h"

typedef struct { f32 x, y, z; } Vec3;
typedef struct {
    u8 pad0[0x24];
    Vec3 pos;      /* 0x24 */
    Vec3 fwd;      /* 0x30 */
    Vec3 up;       /* 0x3C */
    Vec3 side;     /* 0x48 */
    u8 pad54[0x1B8 - 0x54];
    Vec3 goalDir;  /* 0x1B8 */
    u8 pad1C4[0x1F0 - 0x1C4];
    u8 state;      /* 0x1F0 */
    u8 slot;       /* 0x1F1 */
    u8 pad1F2[0x200 - 0x1F2];
    s32 flags;     /* 0x200 */
    s32 turning;   /* 0x204 */
} Actor;
typedef struct {
    u8 pad0[0x10];
    void (*func)(void);  /* 0x10 */
    u8 pad14[0x30 - 0x14];
    Vec3 pos;      /* 0x30 */
    u8 pad3C[0x48 - 0x3C];
    Vec3 vel;      /* 0x48 */
    u8 unk_54;
} Camera;
extern Vec3 D_80075E34[7];
extern Vec3 D_80075E88[7];
extern Vec3 D_80075EDC[7];
extern u64 D_80073EE0[];
extern u64 D_80073FF0[];
extern u64 D_80074100[];
extern u64 D_800742A8[];
extern u16 D_801078B8;

#define ABSF(x) ((x) >= 0.0f ? (x) : -(x))

/* Player slot-select update: steps the selector with the stick, walks to the chosen slot and turns to face it. */
void func_8002F274(void) {
    f32 angle;
    f32 diff;
    s32 unused[22];
    f32 dx;
    f32 dz;
    s32 unused2[2];
    Vec3 target;
    Vec3 dir;
    Vec3 pos;
    Vec3 dir2;
    Vec3 target2;
    Vec3 pos2;
    s32 unused3[2];
    f64 len;
    register Actor *p = D_80106888;
    register f32 speed;

    if (p == NULL) {
        return;
    }
    speed = 0.15f;
    p->turning = 0;
    if (D_80075E2C == 1) {
        (*(Camera *(*))&D_801078E0)->unk_54 = D_80075F30[p->slot];
        (*(Camera *(*))&D_801078E0)->vel.x = (D_80075EDC[p->slot].x - (*(Camera *(*))&D_801078E0)->pos.x) * 0.0078125;
        (*(Camera *(*))&D_801078E0)->vel.y = (D_80075EDC[p->slot].y - (*(Camera *(*))&D_801078E0)->pos.y) * 0.0078125;
        (*(Camera *(*))&D_801078E0)->vel.z = (D_80075EDC[p->slot].z - (*(Camera *(*))&D_801078E0)->pos.z) * 0.0078125;
        (*(Camera *(*))&D_801078E0)->func = func_800310D0;
        D_80075E2C = 2;
    }
    if (D_80075E2C == 2 && (*(Camera *(*))&D_801078E0)->unk_54 == 0) {
        (*(Camera *(*))&D_801078E0)->unk_54 = 0x80;
        (*(Camera *(*))&D_801078E0)->vel.x = (-1045.0 - (*(Camera *(*))&D_801078E0)->pos.x) * 0.0078125;
        (*(Camera *(*))&D_801078E0)->vel.y = (150.0 - (*(Camera *(*))&D_801078E0)->pos.y) * 0.0078125;
        (*(Camera *(*))&D_801078E0)->vel.z = (236.0 - (*(Camera *(*))&D_801078E0)->pos.z) * 0.0078125;
        (*(Camera *(*))&D_801078E0)->func = func_800310D0;
        D_80075E2C = 3;
    }
    if ((*(u8 (*))&D_80075E2D) != 0 && D_80115374 == NULL && p->state == 0) {
        D_8006EDE2 = 1;
        (*(u8 (*))&D_80075E2D) = 0;
    }
    if ((*(u8 (*))&D_80075E2E) != 0 && D_80115374 == NULL && p->state == 0) {
        if (D_80106870 == 0) {
            D_80115374 = D_80073760;
            D_80115258 = &D_80073EE0[D_800745F4];
            D_8013E680 = &D_80073FF0[D_800745F5];
        } else {
            D_80115374 = D_800737B8;
            D_80115258 = &D_80074100[D_800745F4];
            D_8013E680 = &D_800742A8[D_800745F5];
        }
        osSendMesg(D_8013ED88, 0, 1);
        (*(u8 (*))&D_80075E2E) = 0;
    }
    if ((p->flags & 2) && (p->flags & 1)) {
        if (p->state == 0) {
            (*(u8 (*))&D_80140F70) = 1;
            if (ABSF(D_801078BC) >= 9 || (u16)(D_801078B8 & 0x300)) {
                if (D_801078BC >= 9 || (u16)(D_801078B8 & 0x100)) {
                    if (p->slot != 6) {
                        p->slot++;
                        p->state = 1;
                        func_800356D0(p, 4);
                    }
                } else {
                    if (p->slot != 0) {
                        p->slot--;
                        p->state = 1;
                        func_800356D0(p, 4);
                    }
                }
            }
        }
        if (p->state == 1) {
            if (--(*(u8 (*))&D_80140F70) == 0) {
                (*(u8 (*))&D_80140F70) = 30;
                func_8004D020(func_8004CC30(0x15), 0xAF);
            }
            target.x = D_80075E34[p->slot].x;
            target.y = D_80075E34[p->slot].y;
            target.z = D_80075E34[p->slot].z;
            dir.x = target.x;
            dir.y = target.y;
            dir.z = target.z;
            pos.x = p->pos.x;
            pos.y = p->pos.y;
            pos.z = p->pos.z;
            dir.x = dir.x - pos.x;
            dir.y = dir.y - pos.y;
            dir.z = dir.z - pos.z;
            len = sqrtf(dir.x * dir.x + dir.y * dir.y + dir.z * dir.z);
            if (len != 0.0) {
                dir.x = dir.x * (1.0 / len);
                dir.y = dir.y * (1.0 / len);
                dir.z = dir.z * (1.0 / len);
            }
            p->fwd.x = dir.x;
            p->fwd.y = dir.y;
            p->fwd.z = dir.z;
            p->side.x = p->fwd.y * p->up.z - p->fwd.z * p->up.y;
            p->side.y = p->fwd.z * p->up.x - p->fwd.x * p->up.z;
            p->side.z = p->fwd.x * p->up.y - p->fwd.y * p->up.x;
            p->pos.x = p->pos.x + dir.x * 5.0;
            p->pos.z = p->pos.z + dir.z * 5.0;
            dx = p->pos.x - target.x;
            dx = dx * dx;
            dz = p->pos.z - target.z;
            dz = dz * dz;
            if (dx + dz <= 100.0f) {
                p->state = 2;
                p->flags |= 2;
                target2.x = D_80075E88[p->slot].x;
                target2.y = D_80075E88[p->slot].y;
                target2.z = D_80075E88[p->slot].z;
                dir2.x = target2.x;
                dir2.y = target2.y;
                dir2.z = target2.z;
                pos2.x = p->pos.x;
                pos2.y = p->pos.y;
                pos2.z = p->pos.z;
                dir2.x = dir2.x - pos2.x;
                dir2.y = dir2.y - pos2.y;
                dir2.z = dir2.z - pos2.z;
                len = sqrtf(dir2.x * dir2.x + dir2.y * dir2.y + dir2.z * dir2.z);
                if (len != 0.0) {
                    dir2.x = dir2.x * (1.0 / len);
                    dir2.y = dir2.y * (1.0 / len);
                    dir2.z = dir2.z * (1.0 / len);
                }
                p->goalDir.x = dir2.x;
                p->goalDir.y = dir2.y;
                p->goalDir.z = dir2.z;
            }
        }
    }
    if (p->state == 2) {
        angle = func_80067FB0(p->fwd.x, p->fwd.z);
        diff = func_80067FB0(p->goalDir.x, p->goalDir.z);
        diff = diff - angle;
        if (diff > 3.14159) {
            diff = diff - 6.2831853;
        } else if (diff < -3.14159) {
            diff = diff + 6.2831853;
        }
        if (fabs(diff) < 0.03) {
            p->fwd.x = p->goalDir.x;
            p->fwd.y = p->goalDir.y;
            p->fwd.z = p->goalDir.z;
            p->state = 0;
            func_80035828(p, 0x1F);
        } else {
            angle = angle + diff * 0.2;
            p->fwd.x = __sinf(angle);
            p->fwd.z = __cosf(angle);
            p->turning = 1;
        }
        p->side.x = p->fwd.y * p->up.z - p->fwd.z * p->up.y;
        p->side.y = p->fwd.z * p->up.x - p->fwd.x * p->up.z;
        p->side.z = p->fwd.x * p->up.y - p->fwd.y * p->up.x;
    }
}
