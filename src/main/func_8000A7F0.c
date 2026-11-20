typedef struct { u32 w0; u32 w1; } Gfx;
typedef struct { s32 x; s32 y; char text[0x28]; } CreditLine;
extern u8 D_800706D8;
extern s32 D_800706CC;
extern s32 D_800706D0;
extern u8 D_800706D3;
extern u32 D_800706D4;
extern s8 D_800706D9;
extern u8 D_800706DA;
extern u8 D_800706DB;
extern u8 D_801282A3;
extern s8 D_800761E0;
extern s8 D_800A75EE;
extern Gfx *D_8013EB0C;
extern CreditLine D_8006EE6C[];
extern u8 D_8006EDE8[];
extern char D_800796F8[];
extern Gfx D_800749A0[];
s32 func_8000DBC0(void);
void func_8000DCFC(s32);
void func_8000DE60(s32);
void func_8000DD40(s32, s32);
void func_8000DD7C(s32, s32);
void func_8000DDF4(s32, s32, s32, s32);
void func_8000DEBC(char *);
void func_80068AA0(char *, char *);
s32 func_8005F4E8(char *);
void func_80068300(char *, s32, s32);
/* credits screen: advances the visible line range with a fade, then draws the title and lines */
void func_8000A7F0(s32 arg0) {
    char buf[0x50];
    s32 pad;
    s32 i;
    s32 len;
    s32 saved;
    s32 x;
    s32 y;
    s32 unused;
    Gfx *g;
    Gfx *g2;

    y = 10;
    unused = 0;
    if (D_800706D8 != 0 && D_800706CC >= 100) {
        D_801282A3 = 0xFF;
        D_800706D9 = 0;
        D_800706D0 = 0xFF;
        D_800706DA = 1;
        D_800706DB = 8;
        D_800706D4 = 0;
        D_800761E0 = 0;
        D_800706D8 = 0;
        D_800706CC = 0;
        D_800A75EE = 0;
        return;
    }
    if (D_800706CC >= 101) {
        D_800706D0 -= 5;
        if (D_800706D0 <= 0) {
            switch (D_800706D4) {
            case 0:
                D_800706DA = 0x8;
                D_800706DB = 0xF;
                D_800706D0 = 0xFF;
                D_800706CC = 0;
                D_800706D4 = 1;
                break;
            case 1:
                D_800706DA = 0xF;
                D_800706DB = 0x15;
                D_800706D0 = 0xFF;
                D_800706CC = 0;
                D_800706D4 = 2;
                break;
            case 2:
                D_800706DA = 0x15;
                D_800706DB = 0x1B;
                D_800706D0 = 0xFF;
                D_800706CC = 0;
                D_800706D4 = 3;
                break;
            case 3:
                D_800706DA = 0x1B;
                D_800706DB = 0x1E;
                D_800706D0 = 0xFF;
                D_800706CC = 0;
                D_800706D4 = 4;
                break;
            case 4:
                D_800706DA = 0x1E;
                D_800706DB = 0x23;
                D_800706D0 = 0xFF;
                D_800706CC = 0;
                D_800706D4 = 5;
                break;
            case 5:
                D_800706DA = 0x23;
                D_800706DB = 0x29;
                D_800706D0 = 0xFF;
                D_800706CC = 0;
                D_800706D4 = 6;
                break;
            case 6:
                D_800706DA = 0x29;
                D_800706DB = 0x2C;
                D_800706D0 = 0xFF;
                D_800706CC = 0;
                D_800706D4 = 7;
                break;
            case 7:
                D_800706DA = 0x2C;
                D_800706DB = 0x30;
                D_800706D0 = 0xFF;
                D_800706CC = 0;
                D_800706D4 = 8;
                break;
            case 8:
                D_800706DA = 0x30;
                D_800706DB = 0x35;
                D_800706D0 = 0xFF;
                D_800706CC = 0;
                D_800706D4 = 9;
                break;
            case 9:
                D_800706DA = 0x35;
                D_800706DB = 0x3B;
                D_800706D0 = 0xFF;
                D_800706CC = 0;
                D_800706D4 = 10;
                break;
            case 10:
                D_800706DA = 0x3B;
                D_800706DB = 0x41;
                D_800706D0 = 0xFF;
                D_800706CC = 0;
                D_800706D4 = 11;
                break;
            case 11:
                D_800706DA = 0x41;
                D_800706DB = 0x46;
                D_800706D0 = 0xFF;
                D_800706CC = 0;
                D_800706D4 = 12;
                break;
            case 12:
                D_800706DA = 0x46;
                D_800706DB = 0x4C;
                D_800706D0 = 0xFF;
                D_800706CC = 0;
                D_800706D4 = 13;
                break;
            case 13:
                D_800706DA = 0x4C;
                D_800706DB = 0x52;
                D_800706D0 = 0xFF;
                D_800706CC = 0;
                D_800706D4 = 14;
                break;
            case 14:
                D_800706DA = 0x52;
                D_800706DB = 0x55;
                D_800706D0 = 0xFF;
                D_800706CC = 0;
                D_800706D4 = 15;
                break;
            case 15:
                D_800706DA = 0x55;
                D_800706DB = 0x59;
                D_800706D0 = 0xFF;
                D_800706CC = 0;
                D_800706D4 = 16;
                break;
            case 16:
                D_800706DA = 0x59;
                D_800706DB = 0x5C;
                D_800706D0 = 0xFF;
                D_800706CC = 0;
                D_800706D4 = 17;
                break;
            case 17:
                D_800706DA = 0x5C;
                D_800706DB = 0x60;
                D_800706D0 = 0xFF;
                D_800706CC = 0;
                D_800706D4 = 18;
                break;
            case 18:
                D_800706DA = 0x60;
                D_800706DB = 0x65;
                D_800706D0 = 0xFF;
                D_800706CC = 0;
                D_800706D4 = 19;
                break;
            case 19:
                D_800706DA = 0x65;
                D_800706DB = 0x6A;
                D_800706D0 = 0xFF;
                D_800706CC = 0;
                D_800706D4 = 20;
                break;
            case 20:
                D_800706DA = 0x6A;
                D_800706DB = 0x6D;
                D_800706D0 = 0xFF;
                D_800706CC = 0;
                D_800706D4 = 21;
                break;
            case 21:
                D_800706DA = 0x6D;
                D_800706DB = 0x70;
                D_800706D0 = 0xFF;
                D_800706CC = 0;
                D_800706D4 = 22;
                break;
            case 22:
                D_800706DA = 0x70;
                D_800706DB = 0x76;
                D_800706D0 = 0xFF;
                D_800706CC = 0;
                D_800706D4 = 23;
                break;
            case 23:
                D_800706DA = 0x76;
                D_800706DB = 0x7C;
                D_800706D0 = 0xFF;
                D_800706CC = 0;
                D_800706D4 = 24;
                break;
            case 24:
                D_800706DA = 0x7C;
                D_800706DB = 0x7F;
                D_800706D0 = 0xFF;
                D_800706CC = 0;
                D_800706D4 = 25;
                break;
            case 25:
                D_800706DA = 0x7F;
                D_800706DB = 0x82;
                D_800706D0 = 0xFF;
                D_800706CC = 0;
                D_800706D4 = 0;
                D_800706D8 = 1;
                break;
            default:
                break;
            }
        }
    } else {
        D_800706CC++;
    }
    g = D_8013EB0C++; g->w0 = 0xB900031D; g->w1 = 0x00504240;
    g = D_8013EB0C++; g->w0 = 0xFCFFFFFF; g->w1 = 0xFFFEFB7D;
    g = D_8013EB0C++; g->w0 = 0xBA000E02; g->w1 = 0;
    g = D_8013EB0C++; g->w0 = 0xBB000000; g->w1 = 0x80008000;
    g = D_8013EB0C++; g->w0 = 0xFB000000; g->w1 = 0xFF;
    g = D_8013EB0C++; g->w0 = 0xE45003C0; g->w1 = 0;
    g2 = D_8013EB0C++; g2->w0 = 0xB4000000; g2->w1 = 0;
    g2 = D_8013EB0C++; g2->w0 = 0xB3000000; g2->w1 = 0x04000400;
    saved = func_8000DBC0();
    func_8000DE60(1);
    func_8000DD40(0x50, 1);
    y += 15;
    func_80068AA0(buf, D_800796F8);
    len = func_8005F4E8(buf);
    x = len * 8;
    x = (0x140 - x) >> 1;
    func_8000DD7C(x, y);
    func_8000DDF4(0xFF, 0xFF, 0xFF, 0xFF);
    func_8000DEBC(buf);
    for (i = D_800706DA; i < D_800706DB; i++) {
        y += 15;
        func_80068300(buf, 0, 0x28);
        func_80068AA0(buf, D_8006EE6C[i].text);
        len = func_8005F4E8(D_8006EE6C[i].text);
        x = len << 3;
        D_8006EE6C[i].x = (0x140 - x) >> 1;
        y = D_8006EE6C[i].y + i * 24;
        func_8000DD7C(D_8006EE6C[i].x, D_8006EE6C[i].y);
        switch (D_8006EDE8[i]) {
        case 0:
            func_8000DDF4(0xFF, 0xFF, 0xFF, D_800706D3);
            break;
        case 1:
            func_8000DDF4(0, 0xFF, 0, D_800706D3);
            break;
        case 2:
            func_8000DDF4(0xFF, 0xFF, 0, D_800706D3);
            break;
        case 3:
            func_8000DDF4(0, 0x64, 0xC8, D_800706D3);
            break;
        default:
            func_8000DDF4(0xFF, 0xFF, 0xFF, D_800706D3);
            break;
        }
        func_8000DEBC(D_8006EE6C[i].text);
    }
    func_8000DCFC(saved);
    g2 = D_8013EB0C++; g2->w0 = 0x06000000; g2->w1 = (u32)D_800749A0;
}
