typedef struct { u8 unk_00[0x28]; void (*unk_28)(void); } Node;
typedef struct { u8 unk_00[0x20]; s32 unk_20; } Arg1;
void *func_8005AEA0(s32, s32, s32, s32, s32);
s32 func_800505B8(void);
s32 func_800505FC(void);
void func_800502C0(s32);
void func_8005A4C8(void);
extern void *D_8013C598[6];
/* creates the root node and six child nodes */
void func_80050178(Node **out, Arg1 *a, s32 parent) {
    Node *n = func_8005AEA0(0, 0, parent, 1, 0x2C);
    *out = n;
    n->unk_28 = func_8005A4C8;
    D_8013C598[0] = func_8005AEA0(0, 0, parent, func_800505B8(), 0x28);
    D_8013C598[1] = func_8005AEA0(0, 0, parent, func_800505FC(), 2);
    D_8013C598[2] = func_8005AEA0(0, 0, parent, 1, 0x34);
    D_8013C598[3] = func_8005AEA0(0, 0, parent, 1, 0x20);
    D_8013C598[4] = func_8005AEA0(0, 0, parent, 1, 0x30);
    D_8013C598[5] = func_8005AEA0(0, 0, parent, 1, 8);
    func_800502C0(a->unk_20);
}
