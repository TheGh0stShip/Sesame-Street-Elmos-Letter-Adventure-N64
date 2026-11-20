typedef struct Gfx {
    u32 w0;
    u32 w1;
} Gfx;

typedef struct Vtx {
    s16 ob[3];
    u16 flag;
    s16 tc[2];
    u8 cn[4];
} Vtx;

typedef struct Mtx {
    s32 m[4][4];
} Mtx;

typedef struct Camera {
    u8 pad0[0x24];
    f32 eyeX;  /* 0x24 */
    f32 eyeY;  /* 0x28 */
    f32 eyeZ;  /* 0x2C */
    f32 atX;   /* 0x30 */
    f32 atY;   /* 0x34 */
    f32 atZ;   /* 0x38 */
} Camera;

extern u32 D_80106894;
extern u32 D_800A7AB8;
extern u32 D_8006D510;
extern u32 D_8006D514;
extern u8 D_8006D518[];
extern Camera *D_80075C20;
extern f32 D_8006DDE8;
extern f32 D_8006DDEC;
extern s32 D_80070760;
extern Mtx D_8013C5C0[];
extern Gfx *D_8013EB0C;
extern Vtx D_8006DD68[4];
extern Vtx D_8006DDA8[4];
extern f64 func_80067FB0(f64, f64);
extern void func_80056878(Mtx *, f32, f32, f32, f32, f32, f32, f32);
extern f32 func_80056500(f32);
extern f32 func_80054D30(f32);

/* Draws the scrolling sky/backdrop quad, rotated to follow the camera's heading. */
void func_800030A0(void) {
    Gfx *g;
    s32 unused[4];
    register f32 c;
    register f32 s;
    register f32 x;
    register f32 y;
    register f32 z;
    register f32 dx;
    register f32 dz;
    register f32 ang;

    D_80106894 += D_8006D510;
    D_800A7AB8 += D_8006D514;
    D_80106894 &= 0x7FFF;
    D_800A7AB8 &= 0x7FFF;
    x = D_80075C20->eyeX;
    y = D_80075C20->eyeY;
    z = D_80075C20->eyeZ;
    dx = D_80075C20->atX - x;
    dz = D_80075C20->atZ - z;
    ang = func_80067FB0(dx, dz);
    D_8006DDE8 = ang * 57.2957;
    if (D_8006DDE8 < 0.0) {
        D_8006DDE8 += 360.0;
    }
    D_8006DDE8 += 180.0f;
    func_80056878(&D_8013C5C0[D_80070760], D_8006DDEC, D_8006DDE8, 0.0f, 1.0f, x, y, z);
    g = D_8013EB0C++;
    g->w0 = 0x01020040;
    g->w1 = (u32)(D_80070760 * sizeof(Mtx) + (u8 *)D_8013C5C0 - 0x80000000);
    c = func_80056500(-ang);
    s = func_80054D30(-ang);
    if (D_80070760 == 0) {
        D_8006DD68[0].tc[0] = -c * -4096.0f + s * -2048.0f + (f32)(D_80106894 >> 4);
        D_8006DD68[0].tc[1] = s * -4096.0f + c * -2048.0f + (f32)(D_800A7AB8 >> 4);
        D_8006DD68[1].tc[0] = -c * -4096.0f + s * 2048.0f + (f32)(D_80106894 >> 4);
        D_8006DD68[1].tc[1] = s * -4096.0f + c * 2048.0f + (f32)(D_800A7AB8 >> 4);
        D_8006DD68[2].tc[0] = -c * 0.0f + s * 2048.0f + (f32)(D_80106894 >> 4);
        D_8006DD68[2].tc[1] = s * 0.0f + c * 2048.0f + (f32)(D_800A7AB8 >> 4);
        D_8006DD68[3].tc[0] = -c * 0.0f + s * -2048.0f + (f32)(D_80106894 >> 4);
        D_8006DD68[3].tc[1] = s * 0.0f + c * -2048.0f + (f32)(D_800A7AB8 >> 4);
    } else {
        D_8006DDA8[0].tc[0] = -c * -4096.0f + s * -2048.0f + (f32)(D_80106894 >> 4);
        D_8006DDA8[0].tc[1] = s * -4096.0f + c * -2048.0f + (f32)(D_800A7AB8 >> 4);
        D_8006DDA8[1].tc[0] = -c * -4096.0f + s * 2048.0f + (f32)(D_80106894 >> 4);
        D_8006DDA8[1].tc[1] = s * -4096.0f + c * 2048.0f + (f32)(D_800A7AB8 >> 4);
        D_8006DDA8[2].tc[0] = -c * 0.0f + s * 2048.0f + (f32)(D_80106894 >> 4);
        D_8006DDA8[2].tc[1] = s * 0.0f + c * 2048.0f + (f32)(D_800A7AB8 >> 4);
        D_8006DDA8[3].tc[0] = -c * 0.0f + s * -2048.0f + (f32)(D_80106894 >> 4);
        D_8006DDA8[3].tc[1] = s * 0.0f + c * -2048.0f + (f32)(D_800A7AB8 >> 4);
    }
    g = D_8013EB0C++;
    g->w0 = 0xE7000000;
    g->w1 = 0;
    g = D_8013EB0C++;
    g->w0 = 0xBA001402;
    g->w1 = 0;
    g = D_8013EB0C++;
    g->w0 = 0xB6000000;
    g->w1 = 0x009F3207;
    g = D_8013EB0C++;
    g->w0 = 0xB900031D;
    g->w1 = 0x0F0A4000;
    g = D_8013EB0C++;
    g->w0 = 0xFCFFFFFF;
    g->w1 = 0xFFFCF87C;
    g = D_8013EB0C++;
    g->w0 = 0xBA000C02;
    g->w1 = 0x2000;
    g = D_8013EB0C++;
    g->w0 = 0xFD10001F;
    g->w1 = (u32)D_8006D518;
    g = D_8013EB0C++;
    g->w0 = 0xBB000001;
    g->w1 = 0xFFFFFFFF;
    g = D_8013EB0C++;
    g->w0 = 0xF5101000;
    g->w1 = 0x07000000;
    g = D_8013EB0C++;
    g->w0 = 0xE6000000;
    g->w1 = 0;
    g = D_8013EB0C++;
    g->w0 = 0xF3000000;
    g->w1 = 0x07400000;
    g = D_8013EB0C++;
    g->w0 = 0xF5101000;
    g->w1 = 0x00014050;
    g = D_8013EB0C++;
    g->w0 = 0xF2000000;
    g->w1 = 0x0007C07C;
    if (D_80070760 == 0) {
        g = D_8013EB0C++;
        g->w0 = 0x0400103F;
        g->w1 = (u32)D_8006DD68;
    } else {
        g = D_8013EB0C++;
        g->w0 = 0x0400103F;
        g->w1 = (u32)D_8006DDA8;
    }
    g = D_8013EB0C++;
    g->w0 = 0xB1000402;
    g->w1 = 0x604;
    g = D_8013EB0C++;
    g->w0 = 0xE7000000;
    g->w1 = 0;
}
