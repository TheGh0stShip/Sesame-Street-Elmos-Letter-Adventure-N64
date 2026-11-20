/* arena init under disabled interrupts: store base and word count, clear three counters */
u32 func_800612F0(void);
void func_80061310(u32 m);
extern u32 D_8013C5B8;
extern u32 D_80107918;
extern s32 D_8013EB84;
extern s32 D_800ACBF8;
extern s32 D_801283D4;
void func_80057B50(u32 base, u32 size)
{
    u32 m;
    size >>= 2;
    if (base & 3) {
        base = (base & 3) + 4;
        size--;
    }
    m = func_800612F0();
    D_8013C5B8 = base;
    D_80107918 = size;
    D_8013EB84 = 0;
    D_800ACBF8 = 0;
    D_801283D4 = 0;
    func_80061310(m);
}
