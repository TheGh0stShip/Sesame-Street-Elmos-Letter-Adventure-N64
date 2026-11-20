/* with interrupts disabled, OR a mask into D_80077400 */
u32 func_800612F0(void);   /* __osDisableInt */
void func_80061310(u32);   /* __osRestoreInt */
extern u32 D_80077400;
void func_80061A40(u32 mask)
{
    u32 saveMask = func_800612F0();
    D_80077400 |= mask;
    func_80061310(saveMask);
}
