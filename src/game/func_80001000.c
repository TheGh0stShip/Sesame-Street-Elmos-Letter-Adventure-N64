#include "common.h"

extern struct n64dk_a801078B8 D_801078B8[];

void func_80001000(void) {
    void *sp10;
    u16 sp14;

    osContGetReadData(((s32)&D_8007BAF0));
    if ((*(u8 (*))&D_800A8D3E) != 0) {
        (*(u8 (*))&D_800A8D3E)--;
        D_8007BAF0 = 0;
        D_8007BAF6 = 0;
        D_8007BAFC = 0;
        D_8007BB02 = 0;
    }
    for (sp14 = 0; !((u32)sp14 >= 4); sp14++) {
        if (((D_8006D500 >> sp14) % 2) != 0) {
            sp10 = (void *)&((struct n64dk_e6 *)&D_8007BAF0)[sp14];
            switch (((struct gd_4_u8 *)((s32)sp10))->v) {
            case 0:
                D_801078B8[sp14].m2 = (*(u16 *)((s32)sp10)) ^ (*(u16 *)((sp14 * 2) + ((s32)&D_8006D504)));
                D_801078B8[sp14].m2 = D_801078B8[sp14].m2 & (*(u16 *)((s32)sp10));
                D_801078B8[sp14].m0 = *(u16 *)((s32)sp10);
                (*(s16 *)((sp14 * 2) + ((s32)&D_8006D504))) = *(u16 *)((s32)sp10);
                D_801078B8[sp14].m0 = *(u16 *)((s32)sp10);
                D_801078B8[sp14].m4 = ((struct gd_2_u8 *)((s32)sp10))->v;
                D_801078B8[sp14].m5 = ((struct gd_3_u8 *)((s32)sp10))->v;
            }
        }
    }
}
