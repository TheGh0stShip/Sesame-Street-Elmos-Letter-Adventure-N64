/* Set or clear bit 0x20 of the current VI context's control halfword, interrupts off. */
typedef struct { u16 unk_00; } ViCtx;
extern ViCtx *D_80077854;
u32 func_800612F0(void);
void func_80061310(u32);
void func_8005DC20(u8 on) {
    u32 saveMask = func_800612F0();
    if (on) {
        D_80077854->unk_00 |= 0x20;
    } else {
        D_80077854->unk_00 &= ~0x20;
    }
    func_80061310(saveMask);
}
