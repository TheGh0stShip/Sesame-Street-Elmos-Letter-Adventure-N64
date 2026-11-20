#include "common.h"

typedef struct Item {
    u8 pad0[4];
    s32 unk_4;
    u32 unk_8;
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
} Item;
extern void func_80049ABC(void *, f32 *, s32, s32, u32, f32);

/* Passes an item's position and split counter to func_80049ABC. */
void func_80022C6C(void *arg0) {
    Item *p;
    f32 pos[3];
    f32 a;
    u32 b;
    f32 c;

    p = arg0;
    pos[0] = p->unk_C;
    pos[1] = p->unk_10;
    pos[2] = p->unk_14;
    a = p->unk_4;
    b = p->unk_8 / 100000000;
    c = p->unk_8 % 10000;
    func_80049ABC(D_80112CD0, pos, 0, a, b, c);
}
