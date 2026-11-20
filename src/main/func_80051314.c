typedef struct {
    u8 pad0[0x11A2]; u16 unk_11A2;
    u8 pad11A4[0x11DD - 0x11A4]; u8 unk_11DD; u8 unk_11DE; u8 pad11DF;
    void *unk_11E0; u8 pad11E4[4];
    u16 unk_11E8; u8 unk_11EA; u8 pad11EB;
    s32 unk_11EC; f32 unk_11F0; s32 unk_11F4;
    u8 pad11F8[0x1200 - 0x11F8];
} Voice;
extern Voice *D_800A0350;
extern u16 D_800A0354;
extern u16 D_800A0356;
extern s32 D_800A0358;
extern s32 D_800A035C;
void func_80069440(Voice *, s32, void *, s32, s32);
void func_800514D4(u16, s8, u16);
/* allocates a free voice, starts it and returns its handle (0xFFFF if none) */
u16 func_80051314(s32 arg0, s8 arg1, u16 arg2) {
    s32 i;
    Voice *p;
    for (i = 0; i < D_800A0354; i++) {
        if (D_800A0350[i].unk_11E8 == 0xFFFF) {
            p = &D_800A0350[i];
            p->unk_11E8 = D_800A0356 & 0xFFF; D_800A0356++;
            func_80069440(p, arg0, p->unk_11E0, 0xA00, D_800A035C);
            func_800514D4(D_800A0350[i].unk_11E8, arg1, arg2);
            D_800A0350[i].unk_11DE = 4;
            return D_800A0350[i].unk_11E8;
        }
    }
    return 0xFFFF;
}
