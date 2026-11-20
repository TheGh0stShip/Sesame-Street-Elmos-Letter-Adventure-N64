#include "common.h"


void func_80024A5C(s32 arg0) {
    s32 sp18;
    s32 pad0;
    s32 pad1[2];
    s8 pad2;

    sp18 = arg0;
    sp18 = arg0;
    if (D_800ACC2E == 0) {
        if (D_8011537C < 0) {
            ((struct gd_C_s32 *)sp18)->v = ((struct gd_C_s32 *)sp18)->v | 1;
        }
        return;
    }
    if (D_80109B8C >= 5) {
        if (D_80109B8C >= 8) {
            ((struct gd_C_s32 *)sp18)->v = ((struct gd_C_s32 *)sp18)->v | 1;
        }
        return;
    }
    D_80115370 = D_80115370 + 4;
    D_8010E48C = (f32)(((f64)(*(f32 *)(((((u32)D_80115370 >> 3) & 255) * 4) + ((s32)&D_80073160)))) * D_8007A050);
    ((struct gd_28_f32 *)sp18)->v = ((struct gd_28_f32 *)sp18)->v + D_8010E48C;
    ((s32 (*)())func_8001F1C8)(((s32)&((struct n64dk_mE8_40 *)sp18)->m[D_80070760]), (sp18 + 36), ((struct gd_1A8_t *)sp18)->v);
    ((struct gd_28_f32 *)sp18)->v = ((struct gd_28_f32 *)sp18)->v - D_8010E48C;
    addActorDL(((s32)&D_80024C1C), sp18, ((struct gd_1F0_s32 *)sp18)->v, 1, ((f32)func_80022D8C((sp18 + 36))));
}
