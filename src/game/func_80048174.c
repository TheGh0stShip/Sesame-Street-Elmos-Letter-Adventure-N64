#include "common.h"

s32 func_80048690();

void func_80048174(s32 arg0, s32 arg1) {
    register s32 reg_s0;
    s32 pad0[12];
    s32 sp48;

    if (arg0 == 0) {
        return;
    }
    memcpy((arg0 + 56), (arg0 + 16), 40);
    reg_s0 = ((struct gd_8_s32 *)arg0)->v;
    while (!(reg_s0 == 0)) {
        if (((struct gd_44_s32 *)reg_s0)->v != 0) {
            ((s32 (*)())((struct gd_44_s32 *)reg_s0)->v)(((struct gd_14_s32 *)reg_s0)->v, (arg0 + 16), (reg_s0 + 28));
        }
        memcpy((arg0 + 16), (reg_s0 + 28), 40);
        reg_s0 = ((struct gd_18_s32 *)reg_s0)->v;
    }
    if ((((struct gd_34_s32 *)arg0)->v & 32) != 0) {
        ((struct gd_FC_f32 *)arg0)->v = ((struct gd_30_f32 *)arg0)->v;
    } else {
        ((struct gd_FC_f32 *)arg0)->v = ((struct gd_1C_f32 *)arg0)->v;
        ((struct gd_30_f32 *)arg0)->v = ((struct gd_1C_f32 *)arg0)->v;
    }
    if (((struct gd_20_f32 *)arg0)->v > 0.55f) {
        ((struct gd_20_f32 *)arg0)->v = 0.55f;
    }
    if (((struct gd_28_f32 *)arg0)->v < 4e+02f) {
        ((struct gd_28_f32 *)arg0)->v = 4e+02f;
    }
    func_80048690(arg0);
    func_80048958(arg0, arg1);
    func_80048AB8(arg0);
    if (D_80075C20 != 0) {
        func_800483A0(arg0);
    }
    addActorDL(((s32)&D_80049CD8), 0, 6, 0, 0);
    func_80049CF8(((s32)&D_8013EB90), D_8013EF68);
    sp48 = (s32)D_8013EB0C++;
    (*(s32 *)sp48) = 0x1030040;
    ((struct gd_4_s32 *)sp48)->v = D_8013EF68;
}
