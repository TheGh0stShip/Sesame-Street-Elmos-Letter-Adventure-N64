typedef struct { u8 pad[0x11E0]; void *unk_11E0; void *unk_11E4; u16 unk_11E8; u8 pad2[0x1200-0x11EA]; } Voice;
void *func_80050FCC(s32);
extern Voice *D_800A0350;
extern s16 D_800A0354;
extern s16 D_800A0356;
extern s32 D_800A0358;
extern void *D_800A035C;
extern u8 D_80051C04[];
/* allocate n voice blocks with buffers */
s32 func_800510C0(s32 n, s32 arg1, s32 arg2, void *cb) {
    s32 i;
    D_800A0354 = 0;
    D_800A0356 = 0;
    D_800A0358 = arg1;
    D_800A0350 = func_80050FCC(n * sizeof(Voice));
    if (D_800A0350 == NULL) return 0;
    for (i = 0; i < n; i++) {
        D_800A0350[i].unk_11E8 = 0xFFFF;
        if ((D_800A0350[i].unk_11E0 = func_80050FCC(0x1400)) == NULL) return 0;
        if ((D_800A0350[i].unk_11E4 = func_80050FCC(0x20)) == NULL) return 0;
    }
    D_800A0354 = n;
    D_800A035C = cb;
    if (cb == NULL) D_800A035C = D_80051C04;
    return 1;
}
