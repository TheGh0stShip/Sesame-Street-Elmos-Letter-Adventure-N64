#include "common.h"

typedef struct Node { struct Node *next; } Node;
typedef struct { u8 unk_00[0x2C]; Node *freeList; } Pool;
extern Pool *D_800776F0;

/* push a node onto the pool's free list */
void func_8005B3D8(Node *n) {
    n->next = D_800776F0->freeList;
    D_800776F0->freeList = n;
}
