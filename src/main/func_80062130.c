typedef struct { s32 unk_00; u32 unk_04; } Obj;
extern u32 func_80066AF0(void);
s32 func_80062130(Obj *o)
{
    u32 stat = func_80066AF0();
    s32 bit = (stat & 0x100) != 0;
    if (stat & 0x80) {
        o->unk_04 = (o->unk_04 | bit) & ~2;
    }
    return bit;
}
