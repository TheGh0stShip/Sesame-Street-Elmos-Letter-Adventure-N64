#include "common.h"
#include "game_structs.h"

void func_8002BCE4(Vec3f *);
s32 func_8001FFC0(void *a, void *b, Vec3f *pos, Vec3f *newPos, Vec3f *dir, s32 *flags);

/* player movement from the control stick, relative to the camera */
void func_8002C1B4(void) {
    register Actor *p;
    register f32 k;
    f32 sx;
    f32 sy;
    Vec3f cam;
    Vec3f side;
    Vec3f pos;
    Vec3f dir;
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
    p->u.walker.turning = 0;
    sx = D_801078BC;
    sy = D_801078BD;
    func_8004C36C(D_800A7AAC, sx, sy);
    cam.x = (*(Actor *(*))&D_80075C20)->fwd.x - (*(Actor *(*))&D_80075C20)->pos.x;
    cam.y = (*(Actor *(*))&D_80075C20)->fwd.y - (*(Actor *(*))&D_80075C20)->pos.y;
    cam.z = (*(Actor *(*))&D_80075C20)->fwd.z - (*(Actor *(*))&D_80075C20)->pos.z;
    pos.x = p->pos.x;
    pos.y = p->pos.y;
    pos.z = p->pos.z;
    dir.x = p->u.walker.goalDir.x;
    dir.y = p->u.walker.goalDir.y;
    dir.z = p->u.walker.goalDir.z;
    if (p->u.walker.unk_200 & 3) {
        register f64 a;

        if (sx >= 0.0f ? sx > 8.0f : -sx > 8.0f) {
            side.x = cam.y * (*(Actor *(*))&D_80075C20)->up.z - cam.z * (*(Actor *(*))&D_80075C20)->up.y;
            side.y = cam.z * (*(Actor *(*))&D_80075C20)->up.x - cam.x * (*(Actor *(*))&D_80075C20)->up.z;
            side.z = cam.x * (*(Actor *(*))&D_80075C20)->up.y - cam.y * (*(Actor *(*))&D_80075C20)->up.x;
            len = sqrtf(side.x * side.x + side.z * side.z);
            side.x = side.x / len;
            side.z = side.z / len;
            sx = sx >= 0.0f ? sx * sx : sx * -sx;
            sx = sx * 0.01f;
            a = sx;
            t = a * func_80068710((*(View *(*))&D_80112CD0)->yaw + 1.570795) * k;
            pos.x = pos.x + t;
            dir.x = dir.x + t;
            a = sx;
            t = a * func_80068630((*(View *(*))&D_80112CD0)->yaw + 1.570795) * k;
            pos.z = pos.z + t;
            dir.z = dir.z + t;
            p->u.walker.turning = 1;
        }
        if (sy >= 0.0f ? sy > 8.0f : -sy > 8.0f) {
            len = sqrtf(cam.x * cam.x + cam.z * cam.z);
            cam.x = cam.x / len;
            cam.z = cam.z / len;
            sy = sy >= 0.0f ? sy * sy : sy * -sy;
            sy = sy * 0.01f;
            a = sy;
            t = a * func_80068710((*(View *(*))&D_80112CD0)->yaw) * k;
            pos.x = pos.x + t;
            dir.x = dir.x + t;
            a = sy;
            t = a * func_80068630((*(View *(*))&D_80112CD0)->yaw) * k;
            pos.z = pos.z + t;
            dir.z = dir.z + t;
            p->u.walker.turning = 1;
        }
        if (p->u.walker.turning == 0) {
            func_8002BEF0(&sx, &sy);
            if (p->u.walker.turning == 1) {
                a = sx;
                t = a * func_80068710((*(View *(*))&D_80112CD0)->yaw + 1.570795) * k;
                pos.x = pos.x + t;
                dir.x = dir.x + t;
                a = sx;
                t = a * func_80068630((*(View *(*))&D_80112CD0)->yaw + 1.570795) * k;
                pos.z = pos.z + t;
                dir.z = dir.z + t;
                a = sy;
                t = a * func_80068710((*(View *(*))&D_80112CD0)->yaw) * k;
                pos.x = pos.x + t;
                dir.x = dir.x + t;
                a = sy;
                t = a * func_80068630((*(View *(*))&D_80112CD0)->yaw) * k;
                pos.z = pos.z + t;
                dir.z = dir.z + t;
            }
        }
    }
    if (!(p->u.walker.unk_200 & 1)) {
        pos.x = p->pos.x;
        pos.z = p->pos.z;
    }
    if (!(p->u.walker.unk_200 & 2)) {
        dir.x = p->fwd.x;
        dir.y = p->fwd.y;
        dir.z = p->fwd.z;
    }
    if (p->u.walker.turning != 0) {
        if (D_800ACC2D >= 3) {
            D_800ACC2D = 0;
            D_800A7AA8 = 0;
        }
        len = sqrtf(dir.x * dir.x + dir.y * dir.y + dir.z * dir.z);
        if (len >= 1e-7f) {
            inv = 1.0 / len;
            dir.x = dir.x * inv;
            dir.y = dir.y * inv;
            dir.z = dir.z * inv;
        } else {
        }
        if (len > 1e-7f) {
            p->u.walker.goalDir.x = dir.x;
            p->u.walker.goalDir.y = dir.y;
            p->u.walker.goalDir.z = dir.z;
        }
    }
    sx = func_80067FB0(p->fwd.x, p->fwd.z);
    sy = func_80067FB0(p->u.walker.goalDir.x, p->u.walker.goalDir.z);
    sy = sy - sx;
    if ((sy >= 0.0f ? sy : -sy) < 0.03) {
        p->fwd.x = p->u.walker.goalDir.x;
        p->fwd.y = p->u.walker.goalDir.y;
        p->fwd.z = p->u.walker.goalDir.z;
    } else {
        if (sy > 3.14159) {
            sy = sy - 6.2831853;
        } else if (sy < -3.14159) {
            sy = sy + 6.2831853;
        }
        sx = sx + sy * 0.2;
        p->fwd.x = __sinf(sx);
        p->fwd.z = __cosf(sx);
        p->u.walker.turning = 1;
    }
    p->side.x = p->fwd.y * p->up.z - p->fwd.z * p->up.y;
    p->side.y = p->fwd.z * p->up.x - p->fwd.x * p->up.z;
    p->side.z = p->fwd.x * p->up.y - p->fwd.y * p->up.x;
    pos.y = pos.y + p->u.walker.unk_1E4;
    p->u.walker.unk_D0 = 1;
    func_8002BCE4(&pos);
    flags = 0x22000010;
    D_8012EFAC = p->pos.x - pos.x;
    D_8012EFB0 = p->pos.y - pos.y;
    D_8012EFB4 = p->pos.z - pos.z;
    D_80109C71 = 1;
    ret = func_8001FFC0((*(u8 (*)[0x9C-0x60])&p->u.walker.unk_60.x), p->u.walker.unk_BC.a, &p->pos, &pos, &dir, &flags);
    D_80109C71 = 0;
    p->u.walker.unk_1FC = flags;
    if (ret == 2) {
        unk = p->u.walker.unk_9C;
    }
    if (flags & 0x80000000) {
        D_80106860 = p->u.walker.unk_AC.x;
        D_80106864 = p->u.walker.unk_AC.z;
        D_80106868 = -p->u.walker.unk_AC.y;
        if (D_80106864 >= 0.707) {
            p->u.walker.unk_1E4 = 0.0f;
        } else {
            p->u.walker.unk_1E4 = p->u.walker.unk_1F4;
        }
    } else if (p->pos.y > D_8013C5B0 + 75.0 && p->pos.y - (D_8013C5B0 + 75.0) > 2.0) {
        p->u.walker.unk_1E4 = p->u.walker.unk_1F4;
    }
    p->u.walker.unk_1A8.l0.scale.y = pos.x - p->pos.x;
    p->u.walker.unk_1A8.l1.unk_1AC.z = pos.z - p->pos.z;
    {
        register f32 b;

        b = D_800A7604;
        D_800A7604 = b + sqrtf(p->u.walker.unk_1A8.l0.scale.y * p->u.walker.unk_1A8.l0.scale.y + p->u.walker.unk_1A8.l1.unk_1AC.z * p->u.walker.unk_1A8.l1.unk_1AC.z);
    }
    if (D_8012EFD4 != 0 && D_800A7604 > D_8012EFD4) {
        func_80035828(D_80106888, 0x22);
    }
    p->pos.x = pos.x;
    p->pos.y = pos.y;
    p->pos.z = pos.z;
    p->u.walker.unk_D8 = pos.x;
    p->u.walker.unk_DC = -pos.z;
    p->u.walker.unk_E0 = pos.y;
}
