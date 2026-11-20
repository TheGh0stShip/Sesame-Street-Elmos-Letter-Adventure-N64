typedef struct {
    s32 unk_0; s32 unk_4; s32 unk_8; u32 unk_C; s32 unk_10; u32 unk_14; u32 unk_18;
    u8 pad1C[0x30 - 0x1C]; f32 unk_30; s32 unk_34; s32 unk_38; u32 unk_3C; u32 unk_40; s32 unk_44;
    u8 pad48[0x74 - 0x48]; s32 unk_74; s32 unk_78;
    u8 pad7C[0x94 - 0x7C]; u32 unk_94; u8 pad98[2]; u16 unk_9A; u16 unk_9C;
    u8 pad9E[0xAA - 0x9E]; s16 unk_AA;
    u8 padAC[0xC3 - 0xAC]; u8 unk_C3; u8 padC4[0xC9 - 0xC4]; u8 unk_C9;
    u8 padCA[0xCE - 0xCA]; u8 unk_CE; u8 padCF[0xD4 - 0xCF]; u8 unk_D4; u8 unk_D5;
    u8 padD6[0x13C - 0xD6];
} Entry;
typedef struct { u8 pad[0x1C]; } Slot;
typedef struct { u8 pad[8]; } Event;
extern s32 D_800A00D4;
extern Slot *D_800A00D8;
extern Entry *D_800A00DC;
extern s32 D_800A00E8;
extern s32 D_800A0114;
extern s32 D_800A0118;
extern s32 D_800A011C;
extern Event *D_800A0120;
void func_8004D654(Event *);
void func_8004DA5C(Entry *, s32);
void func_8004DFA4(Entry *, s32);
void func_8004E020(Entry *, s32);
void func_8004E174(Entry *, s32, f32);
void func_8004E2F0(Entry *);
void func_8004E500(Entry *);
f32 func_8004E5B8(Entry *);
f32 func_8004E610(Entry *);
void func_8004E674(Entry *);
void func_8004E738(Entry *);
void func_80054620(Slot *);
/* drains the event queue, then advances every active entry by one tick */
s32 func_8004D76C(void) {
    s32 i;
    Entry *e;
    f32 f;

    while (D_800A0114 != D_800A0118) {
        func_8004D654(&D_800A0120[D_800A0114]);
        if (++D_800A0114 == D_800A011C) {
            D_800A0114 = 0;
        }
    }
    for (i = -4, e = D_800A00DC; i < D_800A00D4 - 4; i++, e++) {
        if (e->unk_4 == 0 || (e->unk_0 & 1)) {
            continue;
        }
        if (e->unk_8 != 0) {
            func_8004DFA4(e, i);
        }
        e->unk_C += e->unk_9C;
        if (e->unk_9A != 0x7FFF) {
            while ((s32)(e->unk_3C - e->unk_C) < 0) {
                if (e->unk_4 == 0) {
                    break;
                }
                func_8004DA5C(e, i);
            }
            if (e->unk_4 == 0) {
                continue;
            }
        }
        if (e->unk_38 != 0 && (s32)(e->unk_14 - e->unk_C) < 0) {
            func_8004E674(e);
        }
        if (e->unk_34 != 0 && (s32)(e->unk_18 - e->unk_C) < 0) {
            func_8004E738(e);
        }
        if (e->unk_10 != -1) {
            if (--e->unk_10 == -1) {
                e->unk_38 = 0;
                e->unk_34 = 0;
                e->unk_74 = 0;
                e->unk_78 = 0;
                e->unk_44 = 0;
                e->unk_8 = 0;
                e->unk_4 = 0;
                if (e->unk_C9 != 0) {
                    e->unk_C9 = 0;
                    func_80054620(&D_800A00D8[i]);
                }
            }
        }
        if (e->unk_C9 != 0) {
            if (e->unk_C3 != 0) {
                func_8004E2F0(e);
            }
            if (e->unk_D4 != 0 && (s32)(e->unk_94 - e->unk_C) < 0) {
                func_8004E500(e);
            }
            f = e->unk_30;
            if (e->unk_D5 != 0) {
                f += func_8004E610(e);
            }
            if (e->unk_CE != 0) {
                f += func_8004E5B8(e);
            }
            if (e->unk_8 == 0) {
                func_8004E174(e, i, f);
                func_8004E020(e, i);
            }
        }
        e->unk_AA = (e->unk_C - e->unk_40) >> 8;
    }
    return D_800A00E8;
}
