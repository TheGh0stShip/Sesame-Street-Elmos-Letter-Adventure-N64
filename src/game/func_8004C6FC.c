#include "common.h"
#include "libmus/player.h"

typedef struct { u8 pad[0x1C]; } Chan;
extern Chan *D_800A00D8;
extern channel_t *D_800A00E0;
void *__MusIntMemMalloc(s32);
void func_800540E0(Evt *);
void func_8004EC0C(channel_t *);
void func_80054130(Chan *, ChanCfg *);

/* audio system init from a config block */
void MusInitialize(Config *c) {
    ChanCfg cfg;
    s32 i;

    D_800BD458 = c->unk_40;
    D_8012C278 = c->unk_00;
    max_channels = c->unk_04 + 4;
    if (D_80000300 != 0) {
        D_800A00E4 = 60;
    } else {
        D_800A00E4 = 50;
    }
    D_800A00E8 = 1000000 / D_800A00E4;
    func_80050F80(c->unk_10, c->unk_14);
    func_80050AF0(c->unk_08);
    D_800A00D8 = __MusIntMemMalloc((max_channels - 4) * sizeof(Chan));
    mus_channels = __MusIntMemMalloc(max_channels * sizeof(channel_t));
    D_800A00E0 = mus_channels + 4;
    func_8004D5F0(c->unk_24);
    D_800A00F8 = 0;
    D_800A00FC = 0;
    if (c->unk_18 != 0 && c->unk_1C != 0) {
        ((void (*)(s32, s32))MusPtrBankInitialize)(c->unk_18, c->unk_1C);
    }
    D_800A010C = 0;
    D_800A0108 = 0;
    if (c->unk_20 != 0) {
        MusFxBankInitialize(c->unk_20);
    }
    D_800A0110 = 0;
    D_800A0104 = 2;
    func_80050CA0(c, D_800A00E4, 2);
    MusSetMasterVolume(3, 0x7FFF);
    D_800A00F0 = 1;
    D_800A00F4 = 0x12345678;
    D_800A00C0.next = NULL;
    D_800A00C8 = func_8004D76C;
    D_800A00C4 = &D_800A00C0;
    func_800540E0(&D_800A00C0);
    for (i = 0; i < max_channels; i++) {
        mus_channels[i].playing = 0;
        func_8004EC0C(&mus_channels[i]);
        cfg.unk_04 = 0;
        cfg.unk_00 = c->unk_0C;
        cfg.unk_02 = 0;
        if (i >= 4) {
            func_80054130(&D_800A00D8[i - 4], &cfg);
        }
    }
    func_80050FFC();
}
