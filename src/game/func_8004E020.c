#include "common.h"
#include "libmus/player.h"

extern Syn *D_800A00D8;
void func_800544E0(Syn *, s16, s32);
void func_800543C0(Syn *, u8);
/* update channel volume and pan */
void func_8004E020(channel_t *c, s32 idx) {
    u32 v;
    v = (u32)(c->volume * c->env_current * c->velocity * c->volscale) >> 13;
    if (v > 0x7FFF) v = 0x7FFF;
    if (c->fx_addr == 0) v *= (*(u16 (*))&D_800A00EE); else v *= (*(u16 (*))&D_800A00EC);
    v >>= 15;
    if (c->stopping != -1) v = v * c->stopping / c->stopping_speed;
    if (v != c->old_volume) {
        c->old_volume = v;
        func_800544E0(&D_800A00D8[idx], v, D_800A00E8);
    }
    v = ((c->pan * c->panscale) >> 7) & 0x7F;
    if (v != c->old_pan) {
        c->old_pan = v;
        func_800543C0(&D_800A00D8[idx], v);
    }
}
