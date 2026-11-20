#include "common.h"
#include "codec/stream.h"

extern stream_t *D_800A0350;
/* per-voice update: restart voices in state 2, free voices in state 4 */
void func_800511D4(void) {
    s32 i;
    stream_t *p;
    for (i = 0; i < D_800A0354; i++) {
        if (D_800A0350[i].id != 0xFFFF) {
            func_80069504(&D_800A0350[i]);
            switch ((*(u8 *)&D_800A0350[i].state)) {
            case 2:
                p = &D_800A0350[i];
                p->first = 1;
                p->frac = 0;
                D_800A0350[i].pending = 0;
                D_800A0350[i].pitch = (f32)((D_800A0350[i].sample_rate << 15) / D_800A0358) / 32768.0f;
                func_800698E8(&D_800A0350[i]);
                break;
            case 4:
                D_800A0350[i].id = 0xFFFF;
                break;
            }
        }
    }
}
