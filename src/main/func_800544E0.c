typedef struct { s32 unk_00; s32 unk_04; s16 unk_08; s16 pad0A; s32 unk_0C; s32 unk_10; } Ev;
typedef struct { s32 unk_00; s32 unk_04; f32 unk_08_dummy; } Dummy;
typedef struct { u8 pad[0x88]; s32 unk_88; } Tgt;
typedef struct { s32 unk_00; s32 unk_04; Tgt *unk_08; } Owner;
typedef struct { u8 pad[0x1C]; s32 unk_1C; } Ctx;
extern Ctx *D_800773B4;
Ev *func_80054A78(void);
void func_80052918(Tgt *, s32, Ev *);
s32 func_80054BA4(s32, s32);
/* Queues event type 11 for the owner's target. */
void func_800544E0(Owner *o, s16 a, s32 b) {
    Ev *e;
    if (o->unk_08 != NULL) {
        e = func_80054A78();
        if (e != NULL) {
            s32 t = D_800773B4->unk_1C + o->unk_08->unk_88;
            e->unk_08 = 11;
            e->unk_0C = a;
            e->unk_04 = t;
            e->unk_10 = func_80054BA4(b, t);
            e->unk_00 = 0;
            func_80052918(o->unk_08, 3, e);
        }
    }
}
