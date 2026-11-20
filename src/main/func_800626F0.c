/* with interrupts disabled, store a value at +4 of *D_80077854 and set flag 0x10 */
u32 func_800612F0(void);
void func_80061310(u32);
typedef struct { u16 flags; u16 pad2; s32 unk_4; } S;
extern S *D_80077854;
void func_800626F0(s32 v)
{
    u32 saveMask = func_800612F0();
    D_80077854->unk_4 = v;
    D_80077854->flags |= 0x10;
    func_80061310(saveMask);
}
