typedef struct { u8 pad[0x1C]; } Chan;
typedef struct { u8 pad[0xC9]; u8 unk_C9; u8 padCA[0x13C - 0xCA]; } Voice;
typedef struct { s16 unk_00; s16 unk_02; s8 unk_04; } ChanCfg;
typedef struct Evt { struct Evt *next; } Evt;
typedef struct {
    s32 unk_00; s32 unk_04; s32 unk_08; s32 unk_0C; s32 unk_10; s32 unk_14;
    s32 unk_18; s32 unk_1C; s32 unk_20; s32 unk_24; u8 pad28[0x18]; s32 unk_40;
} Config;
extern s32 D_80000300;
extern s32 D_800BD458;
extern s32 D_8012C278;
extern s32 D_800A00D4;
extern Chan *D_800A00D8;
extern Voice *D_800A00DC;
extern Voice *D_800A00E0;
extern s32 D_800A00E4;
extern s32 D_800A00E8;
extern s32 D_800A00F0;
extern s32 D_800A00F4;
extern s32 D_800A00F8;
extern s32 D_800A00FC;
extern s32 D_800A0104;
extern s32 D_800A0108;
extern s32 D_800A010C;
extern s32 D_800A0110;
extern Evt D_800A00C0;
extern Evt *D_800A00C4;
extern void (*D_800A00C8)(void);
void func_8004D76C(void);
void func_80050F80(s32, s32);
void func_80050AF0(s32);
void *func_80050FCC(s32);
void func_8004D5F0(s32);
void func_8004D274(s32, s32);
void func_8004D43C(s32);
void func_80050CA0(Config *, s32, s32);
void func_8004C984(s32, s32);
void func_800540E0(Evt *);
void func_8004EC0C(Voice *);
void func_80054130(Chan *, ChanCfg *);
void func_80050FFC(void);

/* audio system init from a config block */
void func_8004C6FC(Config *c) {
    ChanCfg cfg;
    s32 i;

    D_800BD458 = c->unk_40;
    D_8012C278 = c->unk_00;
    D_800A00D4 = c->unk_04 + 4;
    if (D_80000300 != 0) {
        D_800A00E4 = 60;
    } else {
        D_800A00E4 = 50;
    }
    D_800A00E8 = 1000000 / D_800A00E4;
    func_80050F80(c->unk_10, c->unk_14);
    func_80050AF0(c->unk_08);
    D_800A00D8 = func_80050FCC((D_800A00D4 - 4) * sizeof(Chan));
    D_800A00DC = func_80050FCC(D_800A00D4 * sizeof(Voice));
    D_800A00E0 = D_800A00DC + 4;
    func_8004D5F0(c->unk_24);
    D_800A00F8 = 0;
    D_800A00FC = 0;
    if (c->unk_18 != 0 && c->unk_1C != 0) {
        func_8004D274(c->unk_18, c->unk_1C);
    }
    D_800A010C = 0;
    D_800A0108 = 0;
    if (c->unk_20 != 0) {
        func_8004D43C(c->unk_20);
    }
    D_800A0110 = 0;
    D_800A0104 = 2;
    func_80050CA0(c, D_800A00E4, 2);
    func_8004C984(3, 0x7FFF);
    D_800A00F0 = 1;
    D_800A00F4 = 0x12345678;
    D_800A00C0.next = NULL;
    D_800A00C8 = func_8004D76C;
    D_800A00C4 = &D_800A00C0;
    func_800540E0(&D_800A00C0);
    for (i = 0; i < D_800A00D4; i++) {
        D_800A00DC[i].unk_C9 = 0;
        func_8004EC0C(&D_800A00DC[i]);
        cfg.unk_04 = 0;
        cfg.unk_00 = c->unk_0C;
        cfg.unk_02 = 0;
        if (i >= 4) {
            func_80054130(&D_800A00D8[i - 4], &cfg);
        }
    }
    func_80050FFC();
}
