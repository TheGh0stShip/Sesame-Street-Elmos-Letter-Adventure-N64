#include "common.h"

extern Vtx *D_801283E0;

/* Draws a camera-facing coloured triangle for an effect; frees it when its timer runs out. */
void func_800110E4(Effect *e) {
    Gfx *g;
    register s16 x;
    register s16 y;
    register s16 z;
    register s32 dx;
    register s32 dz;
    register s32 n;
    register s32 t;
    register f32 len;

    if (--e->unk_18 == 0) {
        func_80012AA4(e);
        return;
    }
    x = e->unk_C;
    y = e->unk_10;
    z = e->unk_14;
    dx = (D_800BD47C << 2) - x;
    dz = (D_8010686E << 2) - z;
    n = dx * dx;
    t = dz * dz;
    n = n + t;
    if (n < 0) {
        return;
    }
    len = sqrtf(n);
    n = e->unk_24;
    if (len != 0.0f) {
        len = n / len;
        dx = dx * len;
        dz = dz * len;

        g = D_8013EB0C++;
        g->words.w0 = 0x04000C2F;
        g->words.w1 = (u32)D_801283E0;
        D_801283E0->v.ob[0] = x;
        D_801283E0->v.ob[1] = y - n;
        D_801283E0->v.ob[2] = z;
        D_801283E0->v.tc[0] = 0x400;
        D_801283E0->v.tc[1] = 0xC00;
        n >>= 1;
        D_801283E0++;
        D_801283E0->v.ob[0] = x + dz;
        D_801283E0->v.ob[1] = y + n;
        D_801283E0->v.ob[2] = z - dx;
        D_801283E0->v.tc[0] = -0x400;
        D_801283E0->v.tc[1] = 0;
        D_801283E0++;
        D_801283E0->v.ob[0] = x - dz;
        D_801283E0->v.ob[1] = y + n;
        D_801283E0->v.ob[2] = z + dx;
        D_801283E0->v.tc[0] = 0xC00;
        D_801283E0->v.tc[1] = 0;
        D_801283E0++;
        g = D_8013EB0C++;
        g->words.w0 = 0xE7000000;
        g->words.w1 = 0;

        switch (e->unk_23) {
        case 0:
            t = func_80020D30();
            dx = t & 7;
            if (dx != 0) {
                dx = e->unk_18;
                if (dx >= 16) {
                    dx = 15;
                }
                dx = dx * 8 + 0x87;
                g = D_8013EB0C++;
                g->words.w0 = 0xFA000000;
                g->words.w1 = 0xFF000000 | ((dx & 0xFF) << 16) | 0xFF;
                g = D_8013EB0C++;
                g->words.w0 = 0xFB000000;
                g->words.w1 = 0xFFFF0000;
            } else {
                g = D_8013EB0C++;
                g->words.w0 = 0xFA000000;
                g->words.w1 = 0xFFFFFFFF;
                g = D_8013EB0C++;
                g->words.w0 = 0xFB000000;
                g->words.w1 = 0xFFFFFF00;
            }
            break;
        case 1:
            g = D_8013EB0C++;
            g->words.w0 = 0xFA000000;
            g->words.w1 = (e->unk_22 << 24) | (e->unk_22 << 16) | 0xFF00 | e->unk_22;
            g = D_8013EB0C++;
            g->words.w0 = 0xFB000000;
            g->words.w1 = 0xFF00;
            break;
        case 2:
            g = D_8013EB0C++;
            g->words.w0 = 0xFA000000;
            g->words.w1 = 0xFFFF80FF;
            g = D_8013EB0C++;
            g->words.w0 = 0xFB000000;
            g->words.w1 = 0xFFFFC800;
            break;
        case 3:
            g = D_8013EB0C++;
            g->words.w0 = 0xFA000000;
            g->words.w1 = 0xFFFF80FF;
            g = D_8013EB0C++;
            g->words.w0 = 0xFB000000;
            g->words.w1 = 0xFFFF0000;
            break;
        case 4:
            g = D_8013EB0C++;
            g->words.w0 = 0xFA000000;
            g->words.w1 = 0xFF8080FF;
            g = D_8013EB0C++;
            g->words.w0 = 0xFB000000;
            g->words.w1 = 0xFF000000;
            break;
        case 5:
            g = D_8013EB0C++;
            g->words.w0 = 0xFA000000;
            g->words.w1 = 0x80FF80FF;
            g = D_8013EB0C++;
            g->words.w0 = 0xFB000000;
            g->words.w1 = 0x00FF0000;
            break;
        case 6:
            g = D_8013EB0C++;
            g->words.w0 = 0xFA000000;
            g->words.w1 = 0x8080FFFF;
            g = D_8013EB0C++;
            g->words.w0 = 0xFB000000;
            g->words.w1 = 0x0000FF00;
            break;
        }
        g = D_8013EB0C++;
        g->words.w0 = 0xBB000001;
        g->words.w1 = 0x80008000;
        g = D_8013EB0C++;
        g->words.w0 = 0xBF000000;
        g->words.w1 = 0x204;
    }
}
