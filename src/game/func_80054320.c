#include "common.h"

typedef struct { s32 unk_0; s32 unk_4; s16 unk_8; s16 pad; s32 unk_C; } Msg;
typedef struct { u8 pad[0x88]; s32 unk_88; } Chan;
typedef struct { s32 unk_0; s32 unk_4; Chan *unk_8; } Voice;
extern Glob *D_800773B4;
Msg *func_80054A78(void);
void n_alEnvmixerParam(Chan *, s32, Msg *);
/* queues a type-0x10 message with a clamped 7-bit value for the voice's channel */
void func_80054320(Voice *v, s32 val) {
    Msg *m;
    s32 t;
    if (v->unk_8 != NULL) {
        m = func_80054A78();
        if (m != NULL) {
            t = D_800773B4->unk_1C + v->unk_8->unk_88;
            m->unk_8 = 0x10;
            m->unk_4 = t;
            if ((u32)(val & 0xFF) >= 0x80) val = 0x7F;
            m->unk_C = val & 0xFF;
            m->unk_0 = 0;
            n_alEnvmixerParam(v->unk_8, 3, m);
        }
    }
}
