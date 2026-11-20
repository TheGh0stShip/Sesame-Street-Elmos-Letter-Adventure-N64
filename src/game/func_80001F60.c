#include "common.h"
#include "game_structs.h"

extern char D_8007951C[], D_80079530[], D_80079548[], D_80079550[], D_80079558[], D_80079560[], D_80079568[], D_80079578[];
extern char D_80079584[], D_800795A0[], D_800795A8[], D_800795B0[], D_800795B8[], D_800795C0[];
extern char D_800795C8[], D_800795D4[], D_800795E0[], D_800795EC[], D_800795F8[], D_80079604[], D_80079610[], D_8007961C[], D_80079628[], D_80079634[], D_8007963C[];
extern f32 D_800ACBF0, D_801078B0, D_80109B94, D_8013C64C, D_800A8CC8, D_80133D6C;
extern f32 D_80106860, D_80106864, D_80106868, D_8012EFAC, D_8012EFB0, D_8012EFB4, D_80112CD4, D_80112CD8, D_80112CDC;
/* debug overlay: clears a texture buffer and prints one of four pages of debug values into it */
void func_80001F60(void) {
    char buf[0x20];
    Gfx *g;
    Gfx *g2;
    register u16 n;
    register u32 *p;
    register f32 a;
    register f32 b;
    register f32 c;

    if (D_8010686C != 0) {
        g = D_8013EB0C++; g->words.w0 = 0xE7000000; g->words.w1 = 0;
        g = D_8013EB0C++; g->words.w0 = 0xBA001402; g->words.w1 = 0;
        g = D_8013EB0C++; g->words.w0 = 0xB6000000; g->words.w1 = 0x009F3207;
        g = D_8013EB0C++; g->words.w0 = 0xB900031D; g->words.w1 = 0x0F0A4000;
        g = D_8013EB0C++; g->words.w0 = 0xBB000001; g->words.w1 = 0x80008000;
        g = D_8013EB0C++; g->words.w0 = 0xFCFFFFFF; g->words.w1 = 0xFFFCF279;
        g = D_8013EB0C++; g->words.w0 = 0xBA000C02; g->words.w1 = 0;
        g = D_8013EB0C++; g->words.w0 = 0xBA001301; g->words.w1 = 0;
        g = D_8013EB0C++; g->words.w0 = 0xBA000E02; g->words.w1 = 0;
        if (D_80070760 == 0) {
            g = D_8013EB0C++; g->words.w0 = 0xFD100000; g->words.w1 = (u32)D_80107B20;
            g = D_8013EB0C++; g->words.w0 = 0xF5100000; g->words.w1 = 0x07018060;
            g = D_8013EB0C++; g->words.w0 = 0xE6000000; g->words.w1 = 0;
            g = D_8013EB0C++; g->words.w0 = 0xF3000000; g->words.w1 = 0x077FF080;
            g = D_8013EB0C++; g->words.w0 = 0xE7000000; g->words.w1 = 0;
            g = D_8013EB0C++; g->words.w0 = 0xF5102000; g->words.w1 = 0x00018060;
            g = D_8013EB0C++; g->words.w0 = 0xF2000000; g->words.w1 = 0x000FC07C;
            D_800ACC1C = D_80107B20;
            p = D_80107B20;
        } else {
            g = D_8013EB0C++; g->words.w0 = 0xFD100000; g->words.w1 = (u32)D_801068B0;
            g = D_8013EB0C++; g->words.w0 = 0xF5100000; g->words.w1 = 0x07018060;
            g = D_8013EB0C++; g->words.w0 = 0xE6000000; g->words.w1 = 0;
            g = D_8013EB0C++; g->words.w0 = 0xF3000000; g->words.w1 = 0x077FF080;
            g = D_8013EB0C++; g->words.w0 = 0xE7000000; g->words.w1 = 0;
            g = D_8013EB0C++; g->words.w0 = 0xF5102000; g->words.w1 = 0x00018060;
            g = D_8013EB0C++; g->words.w0 = 0xF2000000; g->words.w1 = 0x000FC07C;
            D_800ACC1C = D_801068B0;
            p = D_801068B0;
        }
        for (n = 0x400; n != 0; n--, p++) {
            *p = 0;
        }
        switch (D_8010686C) {
        case 1:
            D_800A8CD0 = 0;
            D_8010791C = 0;
            sprintf(buf, D_8007951C);
            func_8000E940(buf);
            D_800A8CD0 = 1;
            D_8010791C = 0;
            a = (f32)(*(u64 (*))&D_801078E8) / 760625.0f;
            b = (f32)(*(u64 (*))&D_800A75F8) / 760625.0f;
            c = (f32)(*(u64 (*))&D_80140F98) / 760625.0f;
            sprintf(buf, D_80079530, a, b, c);
            func_8000E940(buf);
            D_800A8CD0 = 2;
            D_8010791C = 0;
            break;
        case 2:
            D_800A8CD0 = 0;
            D_8010791C = 0;
            sprintf(buf, D_80079548);
            func_8000E940(buf);
            if ((*(Actor *(*))&D_80106888) != NULL) {
                D_800A8CD0 = 0;
                D_8010791C = 5;
                sprintf(buf, D_80079550, (s32)(*(Actor *(*))&D_80106888)->pos.x);
                func_8000E940(buf);
                D_8010791C = 14;
                sprintf(buf, D_80079558, (s32)(*(Actor *(*))&D_80106888)->pos.y);
                func_8000E940(buf);
                D_8010791C = 23;
                sprintf(buf, D_80079560, (s32)(*(Actor *(*))&D_80106888)->pos.z);
                func_8000E940(buf);
                D_800A8CD0 = 1;
                D_8010791C = 0;
                a = func_80067FB0((*(Actor *(*))&D_80106888)->fwd.x, (*(Actor *(*))&D_80106888)->fwd.z) * 57.2957;
                if (a < 0.0) {
                    a = a + 360.0;
                }
                sprintf(buf, D_80079568, a);
                func_8000E940(buf);
                D_800A8CD0 = 2;
                D_8010791C = 0;
                sprintf(buf, D_80079578, (f32)(*(Actor *(*))&D_80106888)->u.model.unk_224 * 0.125);
                func_8000E940(buf);
            }
            break;
        case 3:
            D_800A8CD0 = 0;
            D_8010791C = 0;
            sprintf(buf, D_80079584);
            func_8000E940(buf);
            D_800A8CD0 = 1;
            D_8010791C = 0;
            sprintf(buf, D_800795A0);
            func_8000E940(buf);
            D_8010791C = 7;
            sprintf(buf, D_800795A8, D_800ACBF0);
            func_8000E940(buf);
            D_8010791C = 13;
            sprintf(buf, D_800795A8, D_801078B0);
            func_8000E940(buf);
            D_8010791C = 21;
            sprintf(buf, D_800795B0, D_800ACBF0 * D_800ACBF0 + D_801078B0 * D_801078B0);
            func_8000E940(buf);
            D_800A8CD0 = 2;
            D_8010791C = 0;
            sprintf(buf, D_800795B8);
            func_8000E940(buf);
            D_8010791C = 7;
            sprintf(buf, D_800795A8, D_80109B94);
            func_8000E940(buf);
            D_8010791C = 13;
            sprintf(buf, D_800795A8, D_8013C64C);
            func_8000E940(buf);
            D_8010791C = 21;
            sprintf(buf, D_800795B0, D_80109B94 * D_80109B94 + D_8013C64C * D_8013C64C);
            func_8000E940(buf);
            D_800A8CD0 = 3;
            D_8010791C = 0;
            sprintf(buf, D_800795C0);
            func_8000E940(buf);
            D_8010791C = 7;
            sprintf(buf, D_800795A8, D_800A8CC8);
            func_8000E940(buf);
            D_8010791C = 13;
            sprintf(buf, D_800795A8, D_80133D6C);
            func_8000E940(buf);
            D_8010791C = 21;
            sprintf(buf, D_800795B0, D_800A8CC8 * D_800A8CC8 + D_80133D6C * D_80133D6C);
            func_8000E940(buf);
            break;
        case 4:
            if ((*(Actor *(*))&D_80106888) != NULL) {
                D_800A8CD0 = 0;
                D_8010791C = 0;
                sprintf(buf, D_800795C8, D_80106860);
                func_8000E940(buf);
                D_8010791C = 12;
                sprintf(buf, D_800795D4, D_80106864);
                func_8000E940(buf);
                D_8010791C = 21;
                sprintf(buf, D_800795E0, D_80106868);
                func_8000E940(buf);
                D_800A8CD0 = 1;
                D_8010791C = 0;
                sprintf(buf, D_800795EC, D_8012EFAC);
                func_8000E940(buf);
                D_8010791C = 12;
                sprintf(buf, D_800795F8, D_8012EFB0);
                func_8000E940(buf);
                D_8010791C = 21;
                sprintf(buf, D_80079604, D_8012EFB4);
                func_8000E940(buf);
                D_800A8CD0 = 2;
                D_8010791C = 0;
                sprintf(buf, D_80079610, D_80112CD4);
                func_8000E940(buf);
                D_8010791C = 12;
                sprintf(buf, D_8007961C, D_80112CD8);
                func_8000E940(buf);
                D_8010791C = 21;
                sprintf(buf, D_80079628, D_80112CDC);
                func_8000E940(buf);
                D_800A8CD0 = 3;
                D_8010791C = 0;
                sprintf(buf, D_80079634, D_80115238);
                func_8000E940(buf);
                D_8010791C = 8;
                sprintf(buf, D_8007963C, D_80115378);
                func_8000E940(buf);
            }
            break;
        }
        g = D_8013EB0C++; g->words.w0 = 0xF5602000; g->words.w1 = 0;
        g = D_8013EB0C++; g->words.w0 = 0xF2000000; g->words.w1 = 0x003FC07C;
        g = D_8013EB0C++; g->words.w0 = 0xE44800F0; g->words.w1 = 0x00080070;
        g2 = D_8013EB0C++; g2->words.w0 = 0xB4000000; g2->words.w1 = 0;
        g2 = D_8013EB0C++; g2->words.w0 = 0xB3000000; g2->words.w1 = 0x04000400;
    }
}
