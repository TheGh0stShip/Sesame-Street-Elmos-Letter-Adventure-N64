#include "common.h"


void func_80030A7C(s32 arg0) {
    s32 sp10;

    sp10 = arg0;
    if ((*(s32 *)sp10) == 1) {
        goto L13;
    }
    func_80057BD0(((s32)&D_8007A370), ((s32)&D_8007A374), 3391);
L13: ;
    D_80109B00 = func_80040400(88);
    func_80068300(D_80109B00, 0, 88);
    D_80075C20 = D_80109B00;
    ((struct gd_8_s16 *)D_80109B00)->v = ((struct gd_2_u16 *)sp10)->v;
    ((struct gd_A_s16 *)D_80109B00)->v = ((struct gd_6_u16 *)sp10)->v;
    ((struct gd_C_s32 *)D_80109B00)->v = ((struct gd_8_s32 *)sp10)->v;
    ((struct gd_14_s32 *)D_80109B00)->v = (s32)&D_80022ADC;
    ((struct gd_18_s32 *)D_80109B00)->v = 0;
    ((struct gd_1C_s32 *)D_80109B00)->v = 0;
    ((struct gd_20_s32 *)D_80109B00)->v = 0;
    ((struct gd_10_s32 *)D_80109B00)->v = (s32)&D_80030348;
    ((struct gd_24_f32 *)D_80109B00)->v = ((struct gd_C_f32 *)sp10)->v;
    ((struct gd_28_f32 *)D_80109B00)->v = ((struct gd_10_f32 *)sp10)->v;
    ((struct gd_2C_f32 *)D_80109B00)->v = ((struct gd_14_f32 *)sp10)->v;
    ((struct gd_30_s32 *)D_80109B00)->v = 0;
    ((struct gd_34_s32 *)D_80109B00)->v = 0;
    ((struct gd_38_s32 *)D_80109B00)->v = 0;
    ((struct gd_3C_s32 *)D_80109B00)->v = 0;
    ((struct gd_40_f32 *)D_80109B00)->v = 1.0f;
    ((struct gd_44_s32 *)D_80109B00)->v = 0;
    func_8003FE00(D_80109B00, D_8011525C, 3, 0);
}
