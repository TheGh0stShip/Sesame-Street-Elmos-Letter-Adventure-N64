typedef struct { u8 pad[0x10]; u16 state; } OSThread;
extern OSThread *D_80077420; /* __osRunningThread */
extern OSThread *D_80077418; /* __osRunQueue */
s32 func_800612F0(void);
void func_80061310(s32);
void func_80060F5C(OSThread **);
/* osYieldThread */
void func_80061A80(void) {
    s32 mask = func_800612F0();
    D_80077420->state = 2;
    func_80060F5C(&D_80077418);
    func_80061310(mask);
}
