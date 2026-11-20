/* Store two words and a halfword into the current VI context with interrupts off. */
typedef struct { u16 unk_00; u16 unk_02; s32 unk_04; s32 unk_08; s32 unk_0C; s32 unk_10; s32 unk_14; } ViCtx;
extern ViCtx *D_80077854;
u32 func_800612F0(void);   /* __osDisableInt */
void func_80061310(u32);   /* __osRestoreInt */
void func_80062640(s32 a, s32 b, s32 c) {
    u32 saveMask = func_800612F0();
    D_80077854->unk_10 = a;
    D_80077854->unk_14 = b;
    D_80077854->unk_02 = c;
    func_80061310(saveMask);
}
