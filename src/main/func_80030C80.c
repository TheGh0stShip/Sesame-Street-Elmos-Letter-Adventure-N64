typedef struct Obj { u8 pad0[0xC]; s32 unk_0C; s32 unk_10; u8 pad14[0x10]; f32 unk_24; f32 unk_28; f32 unk_2C; } Obj;
extern u8 D_800ACC2E;
extern s32 D_80109B8C;
extern Obj *D_80106888;
void func_80035828(Obj *, s32);
/* distance check against player object; triggers on close approach */
void func_80030C80(Obj *arg0) {
    register Obj *o = arg0;
    register f32 dx;
    register f32 dz;
    s32 pad;
    if (D_800ACC2E != 0) return;
    if (D_80109B8C >= 5) {
        if (D_80109B8C >= 8) o->unk_0C |= 1;
        return;
    }
    dx = o->unk_24 - D_80106888->unk_24;
    dz = o->unk_2C - D_80106888->unk_2C;
    dx = dx * dx;
    dz = dz * dz;
    dz = dz + dx;
    if (dz < 300000.0) {
        func_80035828(D_80106888, 0x22);
        o->unk_0C |= 1;
        o->unk_10 = 0;
    }
}
