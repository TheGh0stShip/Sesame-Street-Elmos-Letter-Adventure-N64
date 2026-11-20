#include "common.h"

/* if idx is in range, act on entry idx of D_800770C4 and notify the player; 0 on success, 1 if out of range */

extern void *D_800770C4[];
extern U *D_8013C588;
s32 ChangeCustomEffect(s32 idx)
{
    s32 ret;
    if (idx < D_800770C0) {
        func_800502C0(D_800770C4[idx]);
        { T *t = D_8013C588->unk_34; func_8005A4B4(t->unk_20, 1, t); }
        ret = 0;
    } else {
        ret = 1;
    }
    return ret;
}
