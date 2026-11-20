#include "common.h"
#include "libmus/player.h"

extern channel_t *D_800A00E0;
s32 func_8004EF48(channel_t *, fx_t *, s32, s32, s32, s32);

/* play/queue on the pending object, reusing a matching active entry when search is set */
s32 MusStartEffect2(s32 idx, s32 arg1, s32 arg2, s32 search, s32 arg4) {
    fx_t *obj;
    channel_t *e;
    s32 i;
    s32 ret;

    if (D_800A010C == NULL) {
        obj = D_800A0108;
        if (obj == NULL) {
            D_800A00F8 = 0;
            return 0;
        }
    } else {
        obj = D_800A010C;
        D_800A010C = NULL;
    }
    if (D_800A00F8 == 0) {
        D_800A00F8 = (*(s32 *)&obj->ptr_addr);
    }
    if (search != 0) {
        e = D_800A00E0;
        for (i = 4; i < max_channels; i++, e++) {
            if ((*(u16 *)&e->fx_number) == idx && e->fx_addr == obj) {
                if (arg4 == -1) arg4 = obj->effects[idx].priority;
                ret = func_8004EF48(e, obj, idx, arg1, arg2, arg4);
                D_800A00F8 = 0;
                return ret;
            }
        }
    }
    ret = func_8004EFF8(obj, idx, arg1, arg2, arg4);
    D_800A00F8 = 0;
    return ret;
}
