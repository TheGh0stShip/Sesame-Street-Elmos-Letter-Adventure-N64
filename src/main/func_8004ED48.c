typedef struct {
    u8 unk_0[0xC];
    s32 *unk_C;
} Owner;

typedef struct {
    u8 unk_0[0x4];
    s32 unk_4;
    u8 unk_8[0x40];
    s32 unk_48;
    u8 unk_4C[0x28];
    Owner *unk_74;
    s32 unk_78;
    u8 unk_7C[0x4];
    s32 unk_80;
    u8 unk_84[0xB8];
} Obj; /* size 0x13C */

extern s32 D_800A00D4;
extern Obj *D_800A00DC;
extern Obj *D_800A00E0;

/* picks an object slot for an owner: a free slot, else the oldest, else one already tied to the owner */
s32 func_8004ED48(Owner *owner, s32 idx) {
    s32 i;
    s32 best;
    s32 sel;
    Obj *o;

    if (idx < 0) {
        o = D_800A00DC;
        for (i = 0; i < 4; i++, o++) {
            if (o->unk_4 == 0) {
                return i;
            }
        }
    }
    for (i = 4, o = D_800A00E0; i < D_800A00D4; i++, o++) {
        if (o->unk_4 == 0) {
            return i;
        }
    }
    i = 4;
    o = D_800A00E0;
    best = 0x7FFFFFFF;
    sel = 3;
    for (; i < D_800A00D4; i++, o++) {
        if (o->unk_78 != 0 && o->unk_48 <= best) {
            best = o->unk_48;
            sel = i;
        }
    }
    if (sel >= 4) {
        return sel;
    }
    for (i = 4, o = D_800A00E0; i < D_800A00D4; i++) {
        if (o->unk_78 == 0 && o->unk_74 != owner) {
            return i;
        }
    }
    for (i = 4, o = D_800A00E0; i < D_800A00D4; i++, o++) {
        if (o->unk_74 == owner && owner->unk_C[idx] == o->unk_80) {
            return i;
        }
    }
    return idx % (D_800A00D4 - 4) + 4;
}
