typedef struct {
    s32 unk_0;
    s32 unk_4;
    s32 unk_8;
    s32 unk_C;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
    u8 unk_1C;
    u8 pad1D[0xB];
} Cfg;
typedef struct {
    s32 unk_0;
    s32 unk_4;
    u8 pad8[0x4];
    s32 unk_C;
    u8 pad10[0x18];
    s32 unk_28;
    s32 unk_2C;
    s32 unk_30;
    s32 unk_34;
    s32 unk_38;
    s32 unk_3C;
} Params;
typedef struct { void *unk_0; s32 unk_4; } Pair;
extern void func_8004FE50(void *, Cfg *);
extern s32 func_800506A0(s32, s32);
extern void *func_80050FCC(s32);
extern s32 func_80051014(void);
extern s32 func_80051CB0(s32, s32, s32, s32);
extern void func_80056C70(void *, s32, void *, void *, void *, s32);
extern void func_80057530(void *);
extern s32 func_8005D8E0(s32);
extern void D_80050DD8(void *);
extern u8 D_800A0180[];
extern u8 *D_800A0330;
extern Pair *D_800A0334;
extern void *D_800A0338;
extern u8 D_8012FC68[];
/* audio setup: build config, allocate buffers, start audio thread */
void func_80050CA0(Params *p, s32 arg1, u8 arg2) {
    Cfg c;
    s32 n;
    u32 i;
    c.unk_0 = c.unk_4 = p->unk_4;
    c.unk_8 = p->unk_28;
    c.unk_10 = func_800506A0(p->unk_38, p->unk_3C);
    c.unk_1C = arg2;
    c.unk_18 = func_8005D8E0(p->unk_2C);
    c.unk_14 = func_80051014();
    func_8004FE50(D_8012FC68, &c);
    n = func_80051CB0(p->unk_34, c.unk_18, arg1, 0xF);
    D_800A0338 = func_80050FCC(p->unk_30 * 8);
    D_800A0334 = func_80050FCC(0x18);
    for (i = 0; i < 3; i++) {
        D_800A0334[i].unk_0 = func_80050FCC(n * 4);
    }
    D_800A0330 = func_80050FCC(0x2000);
    func_80056C70(D_800A0180, 3, D_80050DD8, NULL, D_800A0330 + 0x2000, p->unk_C);
    func_80057530(D_800A0180);
}
