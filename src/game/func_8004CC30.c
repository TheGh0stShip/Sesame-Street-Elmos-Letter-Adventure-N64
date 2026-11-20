#include "common.h"

s32 MusStartEffect(s32 arg0) {
    Snd *p;
    s32 r;
    p = D_800A010C;
    if (p == NULL) {
        p = D_800A0108;
        if (p == NULL) { D_800A00F8 = 0; return 0; }
    } else {
        D_800A010C = NULL;
    }
    if (D_800A00F8 == 0) D_800A00F8 = p->unk_10;
    r = func_8004EFF8(p, arg0, 0x80, 0x80, -1);
    D_800A00F8 = 0;
    return r;
}
