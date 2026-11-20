#include "common.h"


void func_800186A8(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    f32 sp18;
    f32 sp1C;
    f32 sp20;
    s32 pad0;
    f32 sp28;
    f32 sp2C;
    f32 sp30;
    s32 pad1;
    f32 sp38;
    f32 sp3C;
    f32 sp40;

    sp18 = (((struct gd_40_f32 *)D_80075C20)->v * ((struct gd_50_f32 *)D_80075C20)->v) - (((struct gd_44_f32 *)D_80075C20)->v * ((struct gd_4C_f32 *)D_80075C20)->v);
    sp1C = (((struct gd_44_f32 *)D_80075C20)->v * ((struct gd_48_f32 *)D_80075C20)->v) - (((struct gd_3C_f32 *)D_80075C20)->v * ((struct gd_50_f32 *)D_80075C20)->v);
    sp20 = (((struct gd_3C_f32 *)D_80075C20)->v * ((struct gd_4C_f32 *)D_80075C20)->v) - (((struct gd_40_f32 *)D_80075C20)->v * ((struct gd_48_f32 *)D_80075C20)->v);
    sp28 = -((struct gd_48_f32 *)D_80075C20)->v;
    sp2C = -((struct gd_4C_f32 *)D_80075C20)->v;
    sp30 = -((struct gd_50_f32 *)D_80075C20)->v;
    sp38 = -((struct gd_3C_f32 *)D_80075C20)->v;
    sp3C = -((struct gd_40_f32 *)D_80075C20)->v;
    sp40 = -((struct gd_44_f32 *)D_80075C20)->v;
    func_8001DE6C(arg3, ((s32)&arg0), ((s32)&sp38), ((s32)&sp18), ((s32)&sp28));
}
