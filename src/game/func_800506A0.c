#include "common.h"

typedef struct Node {
    struct Node *unk_00;
    struct Node *unk_04;
    s32 unk_08;
    s32 unk_0C;
    void *unk_10;
} Node;

void *__MusIntMemMalloc(s32);
s32 osCartRomInit(void);
extern Node *D_800A0134;
extern Node *D_800A0138;

/* Allocates a pool of count nodes, each with a size-byte buffer, links them and returns a callback. */
void *func_800506A0(s32 count, s32 size) {
    s32 i;

    D_800A0168 = osCartRomInit();
    D_800A013C = __MusIntMemMalloc(count * 0x30);
    D_800A0140 = __MusIntMemMalloc(count * 8);
    D_800A0138 = __MusIntMemMalloc(count * sizeof(Node));
    func_80051020(D_800A0138, 0, count * sizeof(Node));
    for (i = 0; i < count - 1; i++) {
        D_800A0138[i].unk_04 = &D_800A0138[i] + 1;
        D_800A0138[i].unk_04->unk_00 = &D_800A0138[i];
        D_800A0138[i].unk_10 = __MusIntMemMalloc(size);
        D_800A0138[i].unk_0C = -1;
    }
    D_800A0138[i].unk_10 = __MusIntMemMalloc(size);
    D_800A0138[i].unk_0C = -1;
    D_800A0144 = size;
    D_800A0148 = 0;
    D_800A0130 = 0;
    D_800A0134 = D_800A0138;
    osCreateMesgQueue(D_800A0150, D_800A0140, count * 2);
    return func_800508E4;
}
