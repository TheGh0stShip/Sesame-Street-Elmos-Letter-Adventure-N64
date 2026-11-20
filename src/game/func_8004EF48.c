#include "common.h"
#include "libmus/player.h"

typedef struct {
    u8 unk_0[0x10];
    s32 unk_10;
    u8 unk_14[0x4];
    struct { s32 unk_0; s32 unk_4; } unk_18[1];
} Def;

void func_8004EC0C(void);

/* initialises an object from a definition and assigns it the next serial id, which it returns */
s32 func_8004EF48(channel_t *o, Def *d, s32 idx, s32 a3, s32 a4, s32 a5) {
    func_8004EC0C();
    o->fx_number = idx;
    o->fx_addr = d;
    o->volscale = a3;
    o->panscale = a4;
    o->handle = D_800A00F0++;
    o->priority = a5;
    if (d->unk_10 != 0) {
        o->sample_bank = d->unk_10;
    }
    o->pdata = o->pbase = d->unk_18[idx].unk_0;
    return o->handle;
}
