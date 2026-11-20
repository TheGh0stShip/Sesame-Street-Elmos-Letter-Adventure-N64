#include "common.h"
#include "codec/stream.h"

void *__MusIntMemMalloc(s32);
extern stream_t *D_800A0350;
/* allocate n voice blocks with buffers */
s32 func_800510C0(s32 n, s32 arg1, s32 arg2, void *cb) {
    s32 i;
    (*(s16 (*))&D_800A0354) = 0;
    (*(s16 (*))&D_800A0356) = 0;
    D_800A0358 = arg1;
    D_800A0350 = __MusIntMemMalloc(n * sizeof(stream_t));
    if (D_800A0350 == NULL) return 0;
    for (i = 0; i < n; i++) {
        D_800A0350[i].id = 0xFFFF;
        if ((D_800A0350[i].pcm = __MusIntMemMalloc(0x1400)) == NULL) return 0;
        if ((D_800A0350[i].rs_state = __MusIntMemMalloc(0x20)) == NULL) return 0;
    }
    (*(s16 (*))&D_800A0354) = n;
    D_800A035C = cb;
    if (cb == NULL) D_800A035C = D_80051C04;
    return 1;
}
