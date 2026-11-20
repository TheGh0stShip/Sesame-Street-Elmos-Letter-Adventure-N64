typedef struct Camera {
    u8 pad0[0x24];
    f32 eyeX;  /* 0x24 */
    f32 eyeY;  /* 0x28 */
    f32 eyeZ;  /* 0x2C */
    f32 atX;   /* 0x30 */
    f32 atY;   /* 0x34 */
    f32 atZ;   /* 0x38 */
    f32 upX;   /* 0x3C */
    f32 upY;   /* 0x40 */
    f32 upZ;   /* 0x44 */
} Camera;

typedef struct View {
    u8 pad0[0xFC];
    f32 yaw; /* 0xFC */
} View;

typedef struct Player {
    u8 pad0[0x24];
    f32 pos[3];    /* 0x24 */
    f32 fwd[3];    /* 0x30 */
    f32 up[3];     /* 0x3C */
    f32 side[3];   /* 0x48 */
    u8 pad54[0xC];
    u8 unk_60[0x1C]; /* 0x60 */
    f32 unk_7C;
    f32 unk_80;
    f32 unk_84;
    u8 pad88[0x24];
    f32 unk_AC;
    f32 unk_B0;
    f32 unk_B4;
    u8 unk_B8[4];
    u8 unk_BC[0x14]; /* 0xBC */
    s32 unk_D0;
    u8 padD4[4];
    f32 unk_D8;
    f32 unk_DC;
    f32 unk_E0;
    u8 padE4[0x1AC - 0xE4];
    f32 unk_1AC;
    f32 unk_1B0;
    f32 unk_1B4;
    f32 unk_1B8;
    f32 unk_1BC;
    f32 unk_1C0;
    f32 unk_1C4;
    u8 pad1C8[0x1D4 - 0x1C8];
    s8 unk_1D4;
    s8 unk_1D5;
    s8 unk_1D6;
    s8 unk_1D7;
    f32 unk_1D8;
    f32 unk_1DC;
    f32 unk_1E0;
    f32 unk_1E4;
    f32 unk_1E8;
    u8 pad1EC[0x1F4 - 0x1EC];
    f32 unk_1F4;
    u8 pad1F8[4];
    u32 unk_1FC;
    s32 unk_200;
    s32 unk_204;
} Player;

extern Player *D_80106888;
extern s8 D_801078BC;
extern s8 D_801078BD;
extern void *D_800A7AAC;
extern Camera *D_80075C20;
extern View *D_80112CD0;
extern u8 D_800ACC2D;
extern s16 D_800A7AA8;
extern f32 D_80106860;
extern f32 D_80106864;
extern f32 D_80106868;
extern s8 D_80109C44;
extern s8 D_80109C45;
extern s8 D_80109C46;
extern u32 D_800A7604;
extern u32 D_8012EFD4;

extern void func_8004C36C(void *, s32, s32);
extern void func_8002BEF0(f32 *, f32 *);
extern f32 sqrtf(f32);     /* func_80054D20; must keep the builtin name: call order depends on it */
extern double sin(double);  /* func_80068710 */
extern double cos(double);  /* func_80068630 */
extern f64 func_80067FB0(f64, f64);
extern f32 func_80056500(f32);
extern f32 func_80054D30(f32);
extern s32 func_8001FFC0(void *, void *, f32 *, f32 *, f32 *, u32 *);
extern void func_8002CF14(f32);
extern Player *func_8002BCE4(f32 *);
extern void func_80017568(s32);
extern void func_80035828(Player *, s32);

#define ABS(x) ((x) >= 0.0f ? (x) : -(x))

/* Player movement: stick input relative to the camera, turning, gravity, collision and contact with others. */
void func_8002E140(void) {
    f32 ix;
    f32 iy;
    f32 n[3];
    f32 d[3];
    f32 c[3];
    f32 pos[3];
    f32 vel[3];
    s32 ret;
    u32 flags;
    f32 dot;
    f64 inv;
    register Player *a;
    register Player *o;
    register f32 len;
    register f32 t;

    a = D_80106888;
    if (a == NULL) {
        return;
    }
    a->unk_204 = 0;
    ix = D_801078BC;
    iy = D_801078BD;
    func_8004C36C(D_800A7AAC, ix, iy);
    d[0] = D_80075C20->atX - D_80075C20->eyeX;
    d[1] = D_80075C20->atY - D_80075C20->eyeY;
    d[2] = D_80075C20->atZ - D_80075C20->eyeZ;
    pos[0] = a->pos[0];
    pos[1] = a->pos[1];
    pos[2] = a->pos[2];
    vel[0] = a->unk_1B8;
    vel[1] = a->unk_1BC;
    vel[2] = a->unk_1C0;
    if (a->unk_200 & 3) {
        if (ABS(ix) > 8.0f) {
            c[0] = d[1] * D_80075C20->upZ - d[2] * D_80075C20->upY;
            c[1] = d[2] * D_80075C20->upX - d[0] * D_80075C20->upZ;
            c[2] = d[0] * D_80075C20->upY - d[1] * D_80075C20->upX;
            len = sqrtf(c[0] * c[0] + c[2] * c[2]);
            c[0] = c[0] / len;
            c[2] = c[2] / len;
            ix = ix * ABS(ix);
            ix = ix * 0.01f;
            t = ix * c[0] * 0.5;
            vel[0] = vel[0] + t;
            t = ix * c[2] * 0.5;
            vel[2] = vel[2] + t;
            a->unk_204 = 1;
        }
        if (ABS(iy) > 8.0f) {
            len = sqrtf(d[0] * d[0] + d[2] * d[2]);
            d[0] = d[0] / len;
            d[2] = d[2] / len;
            iy = iy * ABS(iy);
            iy = iy * 0.01f;
            t = iy * d[0] * 0.5;
            vel[0] = vel[0] + t;
            t = iy * d[2] * 0.5;
            vel[2] = vel[2] + t;
            a->unk_204 = 1;
        }
        if (a->unk_204 == 0) {
            func_8002BEF0(&ix, &iy);
            if (a->unk_204 == 1) {
                t = ix * sin(D_80112CD0->yaw + 1.570795) * 0.5;
                vel[0] = vel[0] + t;
                t = ix * cos(D_80112CD0->yaw + 1.570795) * 0.5;
                vel[2] = vel[2] + t;
                t = iy * sin(D_80112CD0->yaw) * 0.5;
                vel[0] = vel[0] + t;
                t = iy * cos(D_80112CD0->yaw) * 0.5;
                vel[2] = vel[2] + t;
            }
        }
    }
    if (!(a->unk_200 & 1)) {
        pos[0] = a->pos[0];
        pos[2] = a->pos[2];
    }
    if (!(a->unk_200 & 2)) {
        vel[0] = a->fwd[0];
        vel[1] = a->fwd[1];
        vel[2] = a->fwd[2];
    }
    if (a->unk_204 != 0) {
        if (D_800ACC2D >= 3) {
            D_800ACC2D = 0;
            D_800A7AA8 = 0;
        }
        if ((len = sqrtf(vel[0] * vel[0] + vel[1] * vel[1] + vel[2] * vel[2])) >= 1e-7f) {
            inv = 1.0 / len;
            vel[0] = vel[0] * inv;
            vel[1] = vel[1] * inv;
            vel[2] = vel[2] * inv;
        } else {
        }
        if (len > 1e-7f) {
            a->unk_1B8 = vel[0];
            a->unk_1BC = vel[1];
            a->unk_1C0 = vel[2];
        }
    }
    if (a->unk_200 & 1) {
        len = sqrtf(ix * ix + iy * iy);
        if (a->unk_1C4 < len) {
            len = a->unk_1C4;
        } else if (len < 5.0) {
            len = 0.0f;
        }
        if (a->unk_1D8 < len) {
            a->unk_1D8 = a->unk_1D8 + (len - a->unk_1D8) * 0.05;
        } else if (len < a->unk_1D8) {
            a->unk_1D8 = a->unk_1D8 - (a->unk_1D8 - len) * 0.1;
        }
    } else {
        a->unk_1D8 = 0.0f;
    }
    ix = func_80067FB0(a->fwd[0], a->fwd[2]);
    iy = func_80067FB0(a->unk_1B8, a->unk_1C0);
    iy = iy - ix;
    if (iy > 3.14159) {
        iy = iy - 6.2831853;
    } else if (iy < -3.14159) {
        iy = iy + 6.2831853;
    }
    if (ABS(iy) < 0.03) {
        a->fwd[0] = a->unk_1B8;
        a->fwd[1] = a->unk_1BC;
        a->fwd[2] = a->unk_1C0;
    } else {
        ix = ix + iy * 0.1;
        ix = ix + a->unk_1DC;
        a->unk_1DC = a->unk_1DC * 0.85;
        if (ABS(a->unk_1DC) < 0.01) {
            a->unk_1DC = 0.0f;
        }
        a->fwd[0] = func_80056500(ix);
        a->fwd[2] = func_80054D30(ix);
        a->unk_204 = 1;
    }
    a->side[0] = a->fwd[1] * a->up[2] - a->fwd[2] * a->up[1];
    a->side[1] = a->fwd[2] * a->up[0] - a->fwd[0] * a->up[2];
    a->side[2] = a->fwd[0] * a->up[1] - a->fwd[1] * a->up[0];
    pos[0] = pos[0] + a->fwd[0] * a->unk_1D8 * 0.5;
    pos[2] = pos[2] + a->fwd[2] * a->unk_1D8 * 0.5;
    pos[0] = pos[0] + a->unk_1E0 * 0.5;
    pos[2] = pos[2] + a->unk_1E8 * 0.5;
    a->unk_1E0 = a->unk_1E0 * 0.85;
    a->unk_1E8 = a->unk_1E8 * 0.85;
    if (a->unk_1E0 < 1.0 && a->unk_1E8 < 1.0) {
        a->unk_1E0 = 0.0f;
        a->unk_1E8 = 0.0f;
    }
    a->unk_1E4 = a->unk_1E4 + a->unk_1F4;
    if (a->unk_1E4 < -60.0) {
        a->unk_1E4 = -60.0f;
    }
    pos[1] = pos[1] + a->unk_1E4;
    a->unk_D0 = 1;
    flags = 0x22000010;
    ret = func_8001FFC0(a->unk_60, a->unk_BC, a->pos, pos, vel, &flags);
    a->unk_1FC = flags;
    if (flags & 0x80000000) {
        D_80106860 = a->unk_AC;
        D_80106864 = a->unk_B4;
        D_80106868 = -a->unk_B0;
        dot = D_80106860 * a->unk_7C + D_80106864 * a->unk_80 + D_80106868 * a->unk_84;
        D_80109C44 = D_80106860 * 127.0f;
        D_80109C45 = D_80106864 * 127.0f;
        D_80109C46 = D_80106868 * 127.0f;
        if (D_80106864 == 0.0f) {
            func_8002CF14(func_80067FB0(D_80106860, D_80106868));
        }
        if (D_80106864 >= 0.707) {
            a->unk_1E4 = 0.0f;
            a->unk_200 &= ~0x10000;
        }
        if (D_80106864 < 0.0) {
            a->unk_1E4 = a->unk_1F4;
        }
    }
    o = func_8002BCE4(pos);
    if (o != NULL) {
        n[0] = a->unk_1AC;
        n[1] = 0.0f;
        n[2] = a->unk_1B4;
        if ((len = sqrtf(n[0] * n[0] + n[1] * n[1] + n[2] * n[2])) >= 1e-7f) {
            inv = 1.0 / len;
            n[0] = n[0] * inv;
            n[1] = n[1] * inv;
            n[2] = n[2] * inv;
        } else {
        }
        if (len > 3.0) {
            if (len > 15.0) {
                func_80017568(0x39);
            }
            ix = func_80067FB0(a->pos[0] - o->pos[0], a->pos[2] - o->pos[2]);
            func_8002CF14(ix);
            o->unk_1D4 = func_80056500(ix) * -127.0;
            o->unk_1D5 = func_80054D30(ix) * -127.0;
            o->unk_1D6 = 0;
            o->unk_1D7 = 14;
        }
    }
    a->unk_1AC = pos[0] - a->pos[0];
    a->unk_1B4 = pos[2] - a->pos[2];
    D_800A7604 += sqrtf(a->unk_1AC * a->unk_1AC + a->unk_1B4 * a->unk_1B4);
    if (D_8012EFD4 != 0 && D_800A7604 > D_8012EFD4) {
        func_80035828(D_80106888, 0x22);
    }
    a->pos[0] = pos[0];
    a->pos[1] = pos[1];
    a->pos[2] = pos[2];
    a->unk_D8 = pos[0];
    a->unk_DC = -pos[2];
    a->unk_E0 = pos[1];
}
