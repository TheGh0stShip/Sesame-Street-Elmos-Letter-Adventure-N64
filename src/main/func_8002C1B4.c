typedef struct {
    f32 x, y, z;
} Vec3;
typedef struct {
    u8 unk_00[0x24];
    Vec3 pos;
    Vec3 at;
    Vec3 up;
} Camera;
typedef struct {
    u8 unk_00[0xFC];
    f32 angle;
} Target;
typedef struct {
    u8 unk_00[0x24];
    Vec3 pos;
    Vec3 dir;
    Vec3 up;
    Vec3 side;
    u8 unk_54[0x60 - 0x54];
    u8 unk_60[0x9C - 0x60];
    s32 unk_9C;
    u8 unk_A0[0xAC - 0xA0];
    f32 unk_AC;
    f32 unk_B0;
    f32 unk_B4;
    u8 unk_BC_pad[0xBC - 0xB8];
    u8 unk_BC[0xD0 - 0xBC];
    s32 unk_D0;
    u8 unk_D4[0xD8 - 0xD4];
    f32 unk_D8;
    f32 unk_DC;
    f32 unk_E0;
    u8 unk_E4[0x1AC - 0xE4];
    f32 moveX;
    f32 unk_1B0;
    f32 moveZ;
    Vec3 wantDir;
    u8 unk_1C4[0x1E4 - 0x1C4];
    f32 unk_1E4;
    u8 unk_1E8[0x1F4 - 0x1E8];
    f32 unk_1F4;
    u8 unk_1F8[0x1FC - 0x1F8];
    s32 unk_1FC;
    u32 ctrl;
    s32 moved;
} Player;
extern Player *D_80106888;
extern Camera *D_80075C20;
extern Target *D_80112CD0;
extern s8 D_801078BC;
extern s8 D_801078BD;
extern s32 D_800A7AAC;
extern u8 D_800ACC2D;
extern s16 D_800A7AA8;
extern f32 D_8012EFAC;
extern f32 D_8012EFB0;
extern f32 D_8012EFB4;
extern u8 D_80109C71;
extern f32 D_80106860;
extern f32 D_80106864;
extern f32 D_80106868;
extern f32 D_8013C5B0;
extern u32 D_800A7604;
extern u32 D_8012EFD4;
void func_8004C36C(s32, s32, s32);
f32 func_80054D20(f32);
f64 func_80068710(f64);
f64 func_80068630(f64);
f64 func_80067FB0(f64, f64);
f32 func_80054D30(f32);
f32 func_80056500(f32);
void func_8002BEF0(f32 *, f32 *);
void func_8002BCE4(Vec3 *);
s32 func_8001FFC0(void *a, void *b, Vec3 *pos, Vec3 *newPos, Vec3 *dir, s32 *flags);
void func_80035828(Player *, s32);

/* player movement from the control stick, relative to the camera */
void func_8002C1B4(void) {
    register Player *p;
    register f32 k;
    f32 sx;
    f32 sy;
    Vec3 cam;
    Vec3 side;
    Vec3 pos;
    Vec3 dir;
    f32 len;
    f32 t;
    s32 ret;
    s32 flags;
    s32 unused;
    s32 unk;
    f64 inv;

    p = D_80106888;
    if (p == NULL) {
        return;
    }
    k = 0.15f;
    p->moved = 0;
    sx = D_801078BC;
    sy = D_801078BD;
    func_8004C36C(D_800A7AAC, sx, sy);
    cam.x = D_80075C20->at.x - D_80075C20->pos.x;
    cam.y = D_80075C20->at.y - D_80075C20->pos.y;
    cam.z = D_80075C20->at.z - D_80075C20->pos.z;
    pos.x = p->pos.x;
    pos.y = p->pos.y;
    pos.z = p->pos.z;
    dir.x = p->wantDir.x;
    dir.y = p->wantDir.y;
    dir.z = p->wantDir.z;
    if (p->ctrl & 3) {
        register f64 a;

        if (sx >= 0.0f ? sx > 8.0f : -sx > 8.0f) {
            side.x = cam.y * D_80075C20->up.z - cam.z * D_80075C20->up.y;
            side.y = cam.z * D_80075C20->up.x - cam.x * D_80075C20->up.z;
            side.z = cam.x * D_80075C20->up.y - cam.y * D_80075C20->up.x;
            len = func_80054D20(side.x * side.x + side.z * side.z);
            side.x = side.x / len;
            side.z = side.z / len;
            sx = sx >= 0.0f ? sx * sx : sx * -sx;
            sx = sx * 0.01f;
            a = sx;
            t = a * func_80068710(D_80112CD0->angle + 1.570795) * k;
            pos.x = pos.x + t;
            dir.x = dir.x + t;
            a = sx;
            t = a * func_80068630(D_80112CD0->angle + 1.570795) * k;
            pos.z = pos.z + t;
            dir.z = dir.z + t;
            p->moved = 1;
        }
        if (sy >= 0.0f ? sy > 8.0f : -sy > 8.0f) {
            len = func_80054D20(cam.x * cam.x + cam.z * cam.z);
            cam.x = cam.x / len;
            cam.z = cam.z / len;
            sy = sy >= 0.0f ? sy * sy : sy * -sy;
            sy = sy * 0.01f;
            a = sy;
            t = a * func_80068710(D_80112CD0->angle) * k;
            pos.x = pos.x + t;
            dir.x = dir.x + t;
            a = sy;
            t = a * func_80068630(D_80112CD0->angle) * k;
            pos.z = pos.z + t;
            dir.z = dir.z + t;
            p->moved = 1;
        }
        if (p->moved == 0) {
            func_8002BEF0(&sx, &sy);
            if (p->moved == 1) {
                a = sx;
                t = a * func_80068710(D_80112CD0->angle + 1.570795) * k;
                pos.x = pos.x + t;
                dir.x = dir.x + t;
                a = sx;
                t = a * func_80068630(D_80112CD0->angle + 1.570795) * k;
                pos.z = pos.z + t;
                dir.z = dir.z + t;
                a = sy;
                t = a * func_80068710(D_80112CD0->angle) * k;
                pos.x = pos.x + t;
                dir.x = dir.x + t;
                a = sy;
                t = a * func_80068630(D_80112CD0->angle) * k;
                pos.z = pos.z + t;
                dir.z = dir.z + t;
            }
        }
    }
    if (!(p->ctrl & 1)) {
        pos.x = p->pos.x;
        pos.z = p->pos.z;
    }
    if (!(p->ctrl & 2)) {
        dir.x = p->dir.x;
        dir.y = p->dir.y;
        dir.z = p->dir.z;
    }
    if (p->moved != 0) {
        if (D_800ACC2D >= 3) {
            D_800ACC2D = 0;
            D_800A7AA8 = 0;
        }
        len = func_80054D20(dir.x * dir.x + dir.y * dir.y + dir.z * dir.z);
        if (len >= 1e-7f) {
            inv = 1.0 / len;
            dir.x = dir.x * inv;
            dir.y = dir.y * inv;
            dir.z = dir.z * inv;
        } else {
        }
        if (len > 1e-7f) {
            p->wantDir.x = dir.x;
            p->wantDir.y = dir.y;
            p->wantDir.z = dir.z;
        }
    }
    sx = func_80067FB0(p->dir.x, p->dir.z);
    sy = func_80067FB0(p->wantDir.x, p->wantDir.z);
    sy = sy - sx;
    if ((sy >= 0.0f ? sy : -sy) < 0.03) {
        p->dir.x = p->wantDir.x;
        p->dir.y = p->wantDir.y;
        p->dir.z = p->wantDir.z;
    } else {
        if (sy > 3.14159) {
            sy = sy - 6.2831853;
        } else if (sy < -3.14159) {
            sy = sy + 6.2831853;
        }
        sx = sx + sy * 0.2;
        p->dir.x = func_80056500(sx);
        p->dir.z = func_80054D30(sx);
        p->moved = 1;
    }
    p->side.x = p->dir.y * p->up.z - p->dir.z * p->up.y;
    p->side.y = p->dir.z * p->up.x - p->dir.x * p->up.z;
    p->side.z = p->dir.x * p->up.y - p->dir.y * p->up.x;
    pos.y = pos.y + p->unk_1E4;
    p->unk_D0 = 1;
    func_8002BCE4(&pos);
    flags = 0x22000010;
    D_8012EFAC = p->pos.x - pos.x;
    D_8012EFB0 = p->pos.y - pos.y;
    D_8012EFB4 = p->pos.z - pos.z;
    D_80109C71 = 1;
    ret = func_8001FFC0(p->unk_60, p->unk_BC, &p->pos, &pos, &dir, &flags);
    D_80109C71 = 0;
    p->unk_1FC = flags;
    if (ret == 2) {
        unk = p->unk_9C;
    }
    if (flags & 0x80000000) {
        D_80106860 = p->unk_AC;
        D_80106864 = p->unk_B4;
        D_80106868 = -p->unk_B0;
        if (D_80106864 >= 0.707) {
            p->unk_1E4 = 0.0f;
        } else {
            p->unk_1E4 = p->unk_1F4;
        }
    } else if (p->pos.y > D_8013C5B0 + 75.0 && p->pos.y - (D_8013C5B0 + 75.0) > 2.0) {
        p->unk_1E4 = p->unk_1F4;
    }
    p->moveX = pos.x - p->pos.x;
    p->moveZ = pos.z - p->pos.z;
    {
        register f32 b;

        b = D_800A7604;
        D_800A7604 = b + func_80054D20(p->moveX * p->moveX + p->moveZ * p->moveZ);
    }
    if (D_8012EFD4 != 0 && D_800A7604 > D_8012EFD4) {
        func_80035828(D_80106888, 0x22);
    }
    p->pos.x = pos.x;
    p->pos.y = pos.y;
    p->pos.z = pos.z;
    p->unk_D8 = pos.x;
    p->unk_DC = -pos.z;
    p->unk_E0 = pos.y;
}
