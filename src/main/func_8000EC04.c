typedef struct { u32 w0, w1; } Gfx;
typedef struct { s16 ob[3]; u16 flag; s16 tc[2]; u8 cn[4]; } Vtx;
typedef union { s32 w; u16 h; } Fix;
typedef struct {
    u8 pad0[0xC];
    Fix x;
    Fix y;
    Fix z;
    u8 pad18;
    s8 vx;
    u8 vy;
    s8 vz;
    u8 color;
    u8 flicker;
    u8 pad1E[0x24 - 0x1E];
    u16 life;
} Spark;
extern s32 D_80106880;
extern s16 D_800BD47C;
extern s16 D_8010686E;
extern Gfx *D_8013EB0C;
extern Vtx *D_801283E0;
void func_80012AA4(Spark *p);
s32 func_80020D30(void);
f32 func_80054D20(f32);

#define _SHIFTL(v, s, w) ((u32)(((u32)(v) & ((0x01 << (w)) - 1)) << (s)))
#define gDPSetColor(pkt, cmd, r, g, b, a) \
    { Gfx *_g = (Gfx *)(pkt); _g->w0 = (cmd); \
      _g->w1 = (_SHIFTL(r, 24, 8) | _SHIFTL(g, 16, 8) | _SHIFTL(b, 8, 8) | _SHIFTL(a, 0, 8)); }
#define gDPSetPrimColor(pkt, r, g, b, a) gDPSetColor(pkt, 0xFA000000, r, g, b, a)
#define gDPSetEnvColor(pkt, r, g, b, a) gDPSetColor(pkt, 0xFB000000, r, g, b, a)
#define gDPWords(pkt, a, b) { Gfx *_g = (Gfx *)(pkt); _g->w0 = (a); _g->w1 = (b); }

/* moves a spark particle and draws it as a camera-facing triangle with a colour chosen by p->color */
void func_8000EC04(register Spark *p) {
    register u16 x;
    register u16 y;
    register u16 z;
    register s32 dx;
    register s32 dz;
    register s32 d;
    register s32 t;
    register f32 len;

    if (!(D_80106880 & 1)) {
        if (--p->life < 20) {
            func_80012AA4(p);
        }
    }
    p->x.w += p->vx << 9;
    p->y.w -= p->vy << 11;
    p->z.w += p->vz << 9;
    x = p->x.h;
    z = p->z.h;
    y = p->y.h;
    dx = (D_800BD47C << 2) - (s16)x;
    dz = (D_8010686E << 2) - (s16)z;
    d = dx * dx;
    t = dz * dz;
    d = d + t;
    if (d < 0) {
        return;
    }
    len = func_80054D20(d);
    d = p->life;
    if (len != 0.0f) {
    len = d / len;
    dx = dx * len;
    dz = dz * len;
    gDPWords(D_8013EB0C++, 0x04000C2F, (u32)D_801283E0);
    D_801283E0->ob[0] = x;
    D_801283E0->ob[1] = y - d;
    D_801283E0->ob[2] = z;
    D_801283E0->tc[0] = 0x400;
    D_801283E0->tc[1] = 0xC00;
    d = d >> 1;
    D_801283E0++;
    D_801283E0->ob[0] = x + dz;
    D_801283E0->ob[1] = y + d;
    D_801283E0->ob[2] = z - dx;
    D_801283E0->tc[0] = -0x400;
    D_801283E0->tc[1] = 0;
    D_801283E0++;
    D_801283E0->ob[0] = x - dz;
    D_801283E0->ob[1] = y + d;
    D_801283E0->ob[2] = z + dx;
    D_801283E0->tc[0] = 0xC00;
    D_801283E0->tc[1] = 0;
    D_801283E0++;
    gDPWords(D_8013EB0C++, 0xE7000000, 0);
    if (--p->flicker == 0) {
        dx = func_80020D30();
        dz = (dx & 7) + 4;
        p->flicker = dz;
        dx = 0xFF;
    } else {
        dx = 0xC8;
    }
    switch (p->color) {
        case 0:
            gDPSetPrimColor(D_8013EB0C++, dx, 0, 0, 0xFF);
            gDPSetEnvColor(D_8013EB0C++, dx, 0, 0, 0);
            break;
        case 1:
            gDPSetPrimColor(D_8013EB0C++, 0, dx, 0, 0xFF);
            gDPSetEnvColor(D_8013EB0C++, 0, dx, 0, 0);
            break;
        case 2:
            gDPSetPrimColor(D_8013EB0C++, 0, 0, dx, 0xFF);
            gDPSetEnvColor(D_8013EB0C++, 0, 0, dx, 0);
            break;
        case 3:
            gDPSetPrimColor(D_8013EB0C++, dx, dx, 0, 0xFF);
            gDPSetEnvColor(D_8013EB0C++, dx, dx, 0, 0);
            break;
        case 4:
            gDPSetPrimColor(D_8013EB0C++, 0, dx, dx, 0xFF);
            gDPSetEnvColor(D_8013EB0C++, 0, dx, dx, 0);
            break;
        case 5:
            gDPSetPrimColor(D_8013EB0C++, dx, 0, dx, 0xFF);
            gDPSetEnvColor(D_8013EB0C++, dx, 0, dx, 0);
            break;
        case 6:
            gDPSetPrimColor(D_8013EB0C++, dx, dx, dx, 0xFF);
            gDPSetEnvColor(D_8013EB0C++, dx, dx, dx, 0);
            break;
        case 7:
            gDPSetPrimColor(D_8013EB0C++, dx, 0x80, 0x80, 0xFF);
            gDPSetEnvColor(D_8013EB0C++, dx, dx >> 1, dx >> 1, 0);
            break;
    }
    gDPWords(D_8013EB0C++, 0xBB000501, 0x80008000);
    gDPWords(D_8013EB0C++, 0xBF000000, 0x204);
    }
}
