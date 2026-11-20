#include "common.h"


void func_800301C8(s32 arg0) {
    s32 sp10;
    s32 sp18[26];
    s32 sp80;

    if (D_80075D53 != 0) {
        sp10 = func_8000DBC0();
        func_8000DE60(1);
        func_8000DDF4(255, 255, 255, 255);
        func_8000DD7C(70, 20);
        sprintf(((s32)&sp18), ((s32)&D_8007A868), ((D_80075D52 * 20) + ((s32)&D_80075D78)));
        func_8000DEBC(((s32)&sp18));
        sp80 = (s32)D_8013EB0C++;
        (*(s32 *)sp80) = 0x6000000;
        ((struct gd_4_s32 *)sp80)->v = (s32)&D_800749A0;
        func_8000DCFC(sp10);
    }
}
