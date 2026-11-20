#include "common.h"

s32 func_8005B620();
s32 func_8005CB88();

void func_8000DEBC(s32 arg0) {
    s32 sp18;
    s32 sp1C;
    s32 sp20;

    sp18 = (s32)&D_80071D08;
    ((struct gd_4_s16 *)sp18)->v = (D_80071E1C * 8) + 8;
    ((struct gd_6_s16 *)sp18)->v = (D_80071E20 * 16) + 8;
    func_8000D810(sp18, arg0, ((s32)&D_80071CFC), D_80071E1C, D_80071E20);
    func_8005B6F8(sp18, D_80071E14, D_80071E18);
    func_8005B620(sp18, (*(u8 (*))&D_80071E10), (*(u8 (*))&D_80071E11), (*(u8 (*))&D_80071E12), (*(u8 (*))&D_80071E13));
    spScale(sp18, ((f32)D_80071E28), ((f32)D_80071E30));
    sp1C = func_8005CB88(sp18);
    sp20 = (s32)D_8013EB0C++;
    (*(s32 *)sp20) = 0x6000000;
    ((struct gd_4_s32 *)sp20)->v = sp1C;
}
