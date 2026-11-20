#include "common.h"

typedef struct { s32 unk_00; s32 unk_04; Tgt *unk_08; } Owner;
typedef struct { u8 pad[0x1C]; s32 unk_1C; } Ctx;
extern Ctx *D_800773B4;
Ev *func_80054A78(void);
void n_alEnvmixerParam(Tgt *, s32, Ev *);
/* Queues event type 7 carrying a float for the owner's target. */
void func_80054450(Owner *o, f32 val) {
    Ev *e;
    if (o->unk_08 != NULL) {
        e = func_80054A78();
        if (e != NULL) {
            s32 t = D_800773B4->unk_1C + o->unk_08->unk_88;
            e->unk_08 = 7;
            *(f32 *)&e->unk_0C = val;
            e->unk_00 = 0;
            e->unk_04 = t;
            n_alEnvmixerParam(o->unk_08, 3, e);
        }
    }
}
