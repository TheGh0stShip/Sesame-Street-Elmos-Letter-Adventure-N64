#include "common.h"

typedef struct { u8 unk_00[0x28]; void (*unk_28)(void); } Node;
void *alHeapDBAlloc(s32, s32, s32, s32, s32);
extern void *D_8013C598[6];
/* creates the root node and six child nodes */
void func_80050178(Node **out, Arg1 *a, s32 parent) {
    Node *n = alHeapDBAlloc(0, 0, parent, 1, 0x2C);
    *out = n;
    n->unk_28 = alFxParamHdl;
    D_8013C598[0] = alHeapDBAlloc(0, 0, parent, func_800505B8(), 0x28);
    D_8013C598[1] = alHeapDBAlloc(0, 0, parent, func_800505FC(), 2);
    D_8013C598[2] = alHeapDBAlloc(0, 0, parent, 1, 0x34);
    D_8013C598[3] = alHeapDBAlloc(0, 0, parent, 1, 0x20);
    D_8013C598[4] = alHeapDBAlloc(0, 0, parent, 1, 0x30);
    D_8013C598[5] = alHeapDBAlloc(0, 0, parent, 1, 8);
    func_800502C0(a->unk_20);
}
