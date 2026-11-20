typedef struct Obj {
    u8 pad0[0xC];
    s32 flags; /* 0xC */
    u8 pad10[0x1B4 - 0x10];
    s32 unk_1B4;
    u8 pad1B8[4];
    s32 unk_1BC;
    u8 pad1C0[0xC];
    s32 unk_1CC;
} Obj;

/* Sets two fields of an object, clears 0x1CC, sets flag 0x80 and clears flag 0x8. */
void func_8002A0C8(register Obj *obj, s32 arg1, s32 arg2) {
    obj->unk_1B4 = arg2;
    obj->unk_1CC = 0;
    obj->unk_1BC = arg1;
    obj->flags |= 0x80;
    obj->flags &= ~8;
}
