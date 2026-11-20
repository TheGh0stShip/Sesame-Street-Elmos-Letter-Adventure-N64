#include "common.h"

typedef struct Node { struct Node *next; } Node;
typedef struct { u8 unk_00[0x2C]; Node *freeList; } Pool;
extern Pool *D_800773B4;

/* push a node onto the pool's free list */
void func_80054AA4(Node *n) {
    n->next = D_800773B4->freeList;
    D_800773B4->freeList = n;
}
