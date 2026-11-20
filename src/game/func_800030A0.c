#include "common.h"
#include "game_structs.h"


extern Mtx D_8013C5C0[];
extern Vtx D_8006DD68[4];
extern Vtx D_8006DDA8[4];

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
    x = (*(Actor *(*))&D_80075C20)->pos.x;
    y = (*(Actor *(*))&D_80075C20)->pos.y;
    z = (*(Actor *(*))&D_80075C20)->pos.z;
    dx = (*(Actor *(*))&D_80075C20)->fwd.x - x;
    dz = (*(Actor *(*))&D_80075C20)->fwd.z - z;
    ang = func_80067FB0(dx, dz);
    D_8006DDE8 = ang * 57.2957;
    if (D_8006DDE8 < 0.0) {
        D_8006DDE8 += 360.0;
    }
    D_8006DDE8 += 180.0f;
    guPosition(&D_8013C5C0[D_80070760], D_8006DDEC, D_8006DDE8, 0.0f, 1.0f, x, y, z);
    g = D_8013EB0C++;
    g->words.w0 = 0x01020040;
    g->words.w1 = (u32)(D_80070760 * sizeof(Mtx) + (u8 *)D_8013C5C0 - 0x80000000);
    c = __sinf(-ang);
    s = __cosf(-ang);
    if (D_80070760 == 0) {
        D_8006DD68[0].v.tc[0] = -c * -4096.0f + s * -2048.0f + (f32)(D_80106894 >> 4);
        D_8006DD68[0].v.tc[1] = s * -4096.0f + c * -2048.0f + (f32)(D_800A7AB8 >> 4);
        D_8006DD68[1].v.tc[0] = -c * -4096.0f + s * 2048.0f + (f32)(D_80106894 >> 4);
        D_8006DD68[1].v.tc[1] = s * -4096.0f + c * 2048.0f + (f32)(D_800A7AB8 >> 4);
        D_8006DD68[2].v.tc[0] = -c * 0.0f + s * 2048.0f + (f32)(D_80106894 >> 4);
        D_8006DD68[2].v.tc[1] = s * 0.0f + c * 2048.0f + (f32)(D_800A7AB8 >> 4);
        D_8006DD68[3].v.tc[0] = -c * 0.0f + s * -2048.0f + (f32)(D_80106894 >> 4);
        D_8006DD68[3].v.tc[1] = s * 0.0f + c * -2048.0f + (f32)(D_800A7AB8 >> 4);
    } else {
        D_8006DDA8[0].v.tc[0] = -c * -4096.0f + s * -2048.0f + (f32)(D_80106894 >> 4);
        D_8006DDA8[0].v.tc[1] = s * -4096.0f + c * -2048.0f + (f32)(D_800A7AB8 >> 4);
        D_8006DDA8[1].v.tc[0] = -c * -4096.0f + s * 2048.0f + (f32)(D_80106894 >> 4);
        D_8006DDA8[1].v.tc[1] = s * -4096.0f + c * 2048.0f + (f32)(D_800A7AB8 >> 4);
        D_8006DDA8[2].v.tc[0] = -c * 0.0f + s * 2048.0f + (f32)(D_80106894 >> 4);
        D_8006DDA8[2].v.tc[1] = s * 0.0f + c * 2048.0f + (f32)(D_800A7AB8 >> 4);
        D_8006DDA8[3].v.tc[0] = -c * 0.0f + s * -2048.0f + (f32)(D_80106894 >> 4);
        D_8006DDA8[3].v.tc[1] = s * 0.0f + c * -2048.0f + (f32)(D_800A7AB8 >> 4);
    }
    g = D_8013EB0C++;
    g->words.w0 = 0xE7000000;
    g->words.w1 = 0;
    g = D_8013EB0C++;
    g->words.w0 = 0xBA001402;
    g->words.w1 = 0;
    g = D_8013EB0C++;
    g->words.w0 = 0xB6000000;
    g->words.w1 = 0x009F3207;
    g = D_8013EB0C++;
    g->words.w0 = 0xB900031D;
    g->words.w1 = 0x0F0A4000;
    g = D_8013EB0C++;
    g->words.w0 = 0xFCFFFFFF;
    g->words.w1 = 0xFFFCF87C;
    g = D_8013EB0C++;
    g->words.w0 = 0xBA000C02;
    g->words.w1 = 0x2000;
    g = D_8013EB0C++;
    g->words.w0 = 0xFD10001F;
    g->words.w1 = (u32)D_8006D518;
    g = D_8013EB0C++;
    g->words.w0 = 0xBB000001;
    g->words.w1 = 0xFFFFFFFF;
    g = D_8013EB0C++;
    g->words.w0 = 0xF5101000;
    g->words.w1 = 0x07000000;
    g = D_8013EB0C++;
    g->words.w0 = 0xE6000000;
    g->words.w1 = 0;
    g = D_8013EB0C++;
    g->words.w0 = 0xF3000000;
    g->words.w1 = 0x07400000;
    g = D_8013EB0C++;
    g->words.w0 = 0xF5101000;
    g->words.w1 = 0x00014050;
    g = D_8013EB0C++;
    g->words.w0 = 0xF2000000;
    g->words.w1 = 0x0007C07C;
    if (D_80070760 == 0) {
        g = D_8013EB0C++;
        g->words.w0 = 0x0400103F;
        g->words.w1 = (u32)D_8006DD68;
    } else {
        g = D_8013EB0C++;
        g->words.w0 = 0x0400103F;
        g->words.w1 = (u32)D_8006DDA8;
    }
    g = D_8013EB0C++;
    g->words.w0 = 0xB1000402;
    g->words.w1 = 0x604;
    g = D_8013EB0C++;
    g->words.w0 = 0xE7000000;
    g->words.w1 = 0;
}
