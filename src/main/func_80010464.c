typedef struct { u32 w0, w1; } Gfx;
typedef struct { s16 x, y, z, flag; s16 s, t; u8 cn[4]; } Vtx;
typedef struct {
    u8 pad[0xC];
    s32 x; s32 y; s32 z;
    u8 unk_18; s8 vx; s8 vy; s8 vz;
    s16 unk_1C; u8 pad2[0x24 - 0x1E];
    u16 unk_24;
} Obj;
#define GW(pkt, a, b) { Gfx *_g = (Gfx *)(pkt); _g->w0 = (a); _g->w1 = (b); }
extern s16 D_800BD47C;
extern s16 D_8010686E;
extern Vtx *D_801283E0;
extern Gfx *D_8013EB0C;
void func_80012AA4(Obj *);
f32 func_80054D20(f32);
/* moves a falling particle and draws it as a camera-facing triangle */
void func_80010464(register Obj *o) {
    register s16 x, y, z;
    register s32 dx, dz, d, e;
    register f32 len;

    o->x += o->vx << 13;
    o->y += o->vy << 16;
    o->z += o->vz << 13;
    if (o->vy >= -0x76) o->vy -= 8;
    x = *(s16 *)&o->x;
    y = *(s16 *)&o->y;
    z = *(s16 *)&o->z;
    if (o->unk_1C > y) {
        func_80012AA4(o);
        return;
    }
    dx = D_800BD47C;
    dx <<= 2;
    dx -= x;
    dz = D_8010686E;
    dz <<= 2;
    dz -= z;
    d = dx * dx;
    e = dz * dz;
    d += e;
    if (d < 0) return;
    len = func_80054D20(d);
    d = o->unk_24;
    if (len != 0.0f) {
    len = d / len;
    dx = dx * len;
    dz = dz * len;
    GW(D_8013EB0C++, 0x04000C2F, (u32)D_801283E0);
    D_801283E0->x = x;
    D_801283E0->y = y - d;
    D_801283E0->z = z;
    D_801283E0->s = 0x400;
    D_801283E0->t = 0xC00;
    d >>= 1;
    D_801283E0++;
    D_801283E0->x = x + dz;
    D_801283E0->y = y + d;
    D_801283E0->z = z - dx;
    D_801283E0->s = -0x400;
    D_801283E0->t = 0;
    D_801283E0++;
    D_801283E0->x = x - dz;
    D_801283E0->y = y + d;
    D_801283E0->z = z + dx;
    D_801283E0->s = 0xC00;
    D_801283E0->t = 0;
    D_801283E0++;
    GW(D_8013EB0C++, 0xE7000000, 0);
    dx = ++o->unk_18;
    dx <<= 3;
    dx += 0x30;
    if (dx > 0xFF) dx = 0xFF;
    GW(D_8013EB0C++, 0xFA000000, ((dx & 0xFF) << 24) | ((dx & 0xFF) << 16) | 0xFFFF);
    GW(D_8013EB0C++, 0xFB000000, 0xFFFFFF00);
    GW(D_8013EB0C++, 0xBB000001, 0x80008000);
    GW(D_8013EB0C++, 0xBF000000, 0x204);
    }
}
