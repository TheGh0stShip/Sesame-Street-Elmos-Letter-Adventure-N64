typedef struct {
    s32 size;      /* 0x00 */
    u8 type;       /* 0x04 */
    u8 pad5;
    u16 unk_06;
    u8 pad8[4];
    s32 unk_0C;
    u16 unk_10;
    u16 unk_12;
    u8 pad14[0x10];
    u16 unk_24;
    u16 unk_26;
    u8 pad28[8];
    s32 unk_30;
    u8 pad34[0x18];
} Msg; /* 0x4C */
u32 func_80064070(u32);
void func_80064030(u32, u32);
void func_80065660(s32, s32, Msg *);
void func_8005EF28(void *, s32, s32);
extern u8 D_8013EB10;
void func_80063CE0(void) {
    Msg m;
    func_80064030(0x04080000, func_80064070(0x04080000) - 4);
    func_80065660(1, 1000, &m);
    m.unk_0C = 1;
    m.unk_10 = 2;
    m.unk_24 = 2;
    m.unk_26 = 4;
    m.type = 4;
    m.unk_12 = 0;
    m.unk_30 = 0;
    m.unk_06 = 0;
    m.size = 0x4C;
    func_8005EF28(&m, 0x4C, 2);
    D_8013EB10 = 1;
}
