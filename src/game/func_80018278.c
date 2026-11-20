#include "common.h"


void func_80018278(s32 arg0) {
    s32 sp10;
    s32 sp14;

    sp10 = arg0;
    func_80017B28(sp10);
    sp14 = (s32)D_8013EB0C++;
    (*(s32 *)sp14) = 0x6000000;
    ((struct gd_4_s32 *)sp14)->v = (s32)&D_800744F0;
    sp14 = (s32)D_8013EB0C++;
    (*(s32 *)sp14) = 0xFD180000;
    ((struct gd_4_s32 *)sp14)->v = (s32)&D_8024B008;
    sp14 = (s32)D_8013EB0C++;
    (*(s32 *)sp14) = 0xF5180000;
    ((struct gd_4_s32 *)sp14)->v = 0x7080200;
    sp14 = (s32)D_8013EB0C++;
    (*(s32 *)sp14) = 0xE6000000;
    ((struct gd_4_s32 *)sp14)->v = 0;
    sp14 = (s32)D_8013EB0C++;
    (*(s32 *)sp14) = 0xF3000000;
    ((struct gd_4_s32 *)sp14)->v = 0x73FF080;
    sp14 = (s32)D_8013EB0C++;
    (*(s32 *)sp14) = 0xE7000000;
    ((struct gd_4_s32 *)sp14)->v = 0;
    sp14 = (s32)D_8013EB0C++;
    (*(s32 *)sp14) = 0xF5181000;
    ((struct gd_4_s32 *)sp14)->v = 0x80200;
    sp14 = (s32)D_8013EB0C++;
    (*(s32 *)sp14) = 0xF2000000;
    ((struct gd_4_s32 *)sp14)->v = 0x7C07C;
    sp14 = (s32)D_8013EB0C++;
    (*(s32 *)sp14) = 0x6000000;
    ((struct gd_4_s32 *)sp14)->v = (s32)&D_80074560;
    sp14 = (s32)D_8013EB0C++;
    (*(s32 *)sp14) = 0x6000000;
    ((struct gd_4_s32 *)sp14)->v = (s32)&D_80074508;
}
