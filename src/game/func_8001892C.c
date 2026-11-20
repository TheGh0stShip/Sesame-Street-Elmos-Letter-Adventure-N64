#include "common.h"


void func_8001892C(s32 arg0, s32 arg1, register s32 arg2, register s32 arg3) {
    u16 sp10;
    u16 sp12;

    sp10 = arg2;
    sp12 = arg3;
    D_80133D70 = func_80040400((((s32)&D_003EA160) - ((s32)&D_003E4830)));
    func_80017318(((s32)&D_003E4830), D_80133D70, (((s32)&D_003EA160) - ((s32)&D_003E4830)));
    D_800AEC88 = func_80040400((arg1 - arg0));
    func_80017318(arg0, D_800AEC88, (arg1 - arg0));
    ((s32 (*)())func_8004D274)(D_80133D70, ((s32)&D_003EA160));
    func_8004D2B0(D_80133D70);
    D_800A7AFC = ((s32 (*)())MusStartSong)(D_800AEC88);
    func_8004D1EC(D_800A7AFC, sp12);
    ((s32 (*)())func_8004D020)(D_800A7AFC, sp10);
}
