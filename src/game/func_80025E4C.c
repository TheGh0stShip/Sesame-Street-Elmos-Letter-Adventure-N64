#include "common.h"


void DrawWorld(s32 arg0) {
    s32 sp10;
    s32 stack[128];
    s32 sp218;
    s32 sp21C;
    s32 sp220;
    s32 sp224;
    s32 sp228;
    s32 sp22C;
    s32 pad2[2];
    s64 sp238;
    s32 sp240;

    sp218 = 1;
    sp21C = 0;
    sp224 = 0;
    sp228 = 0;
    sp22C = 0;
    D_80075C68 = 0;
    D_80075CB4 = 0;
    D_80075CB8 = 0;
    D_80075CBC = 0;
    D_80075C64 = 0;
    D_80075C60 = 0;
    sp240 = (s32)D_8013EB0C++;
    (*(s32 *)sp240) = 0xE7000000;
    ((struct gd_4_s32 *)sp240)->v = 0;
    stack[0] = arg0;
    for (;;) {
        if (sp218 <= 0) {
            break;
        }
        sp10 = stack[sp218 - 1];
        sp218--;
        if (func_80025504(sp10) != 0) {
            sp224++;
            if (((*(s32 *)sp10) & 1) != 0) {
                sp228++;
                if (D_80075C68 != 0) {
                    ((void (*)(s32, s64))func_80025C6C)(((struct gd_10_s32 *)sp10)->v, sp238);
                } else {
                    sp240 = (s32)D_8013EB0C++;
                    (*(s32 *)sp240) = 0x6000000;
                    ((struct gd_4_s32 *)sp240)->v = ((struct gd_10_s32 *)sp10)->v;
                }
            } else {
                if (((struct gd_20_s32 *)sp10)->v != 0) {
                    stack[sp218] = ((struct gd_20_s32 *)sp10)->v;
                    sp218++;
                    if (sp218 > sp22C) {
                        sp22C = sp218;
                    }
                }
                if (((struct gd_24_s32 *)sp10)->v != 0) {
                    stack[sp218] = ((struct gd_24_s32 *)sp10)->v;
                    sp218++;
                    if (sp218 > sp22C) {
                        sp22C = sp218;
                    }
                }
                if (sp22C >= 128) {
                    func_80001D38(((s32)&D_8007A0D8));
                    return;
                }
            }
        }
    }
    if (D_80075C68 != 0) {
        sp220 = D_80075C64;
        while (sp220 != 0) {
            if ((*(s32 *)sp220) != 0) {
                sp240 = (s32)D_8013EB0C++;
                (*(s32 *)sp240) = 0x6000000;
                ((struct gd_4_s32 *)sp240)->v = *(s32 *)sp220;
            }
            sp220 = ((struct gd_10_s32 *)sp220)->v;
        }
    }
}
