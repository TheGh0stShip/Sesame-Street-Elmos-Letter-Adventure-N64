#include "common.h"

typedef struct { u8 pad[8]; Res *unk_08; u8 padC[0xE]; u16 unk_1A; } Obj;
typedef struct { s32 unk_00; s32 unk_04; s16 unk_08; u16 unk_0A; s32 unk_0C; } Msg;
typedef struct { u8 pad[0x1C]; s32 unk_1C; } Mgr;
extern Mgr *D_800773B4;
Msg *func_80054A78(void);
void n_alEnvmixerParam(Res *, s32, Msg *);
/* queue a type-0xE message for the object's resource */
void func_80054590(Obj *o, s32 arg) {
    Msg *m;
    s32 v;
    if (o->unk_08 != NULL) {
        m = func_80054A78();
        if (m != NULL) {
            v = D_800773B4->unk_1C + o->unk_08->unk_88;
            m->unk_08 = 0xE;
            m->unk_0C = arg;
            m->unk_00 = 0;
            m->unk_04 = v;
            m->unk_0A = o->unk_1A;
            n_alEnvmixerParam(o->unk_08, 3, m);
        }
    }
}
