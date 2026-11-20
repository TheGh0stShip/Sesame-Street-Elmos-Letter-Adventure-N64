#include "common.h"

typedef struct { u8 pad[0x24]; s32 arr[1]; } Sub;
typedef struct { u8 pad[0x34]; Sub *unk_34; } Obj;
extern Obj *D_800773B4;
void n_alFxNew(s32 *);
s32 func_80054C50(s16 idx) {
    n_alFxNew(&D_800773B4->unk_34->arr[idx]);
    return D_800773B4->unk_34->arr[idx];
}
