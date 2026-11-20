#include "common.h"

extern s32 D_0050D000;

void func_8003A650(s32 arg0) {
    func_80035750(arg0);
    func_8003A568(arg0);
    ((struct gd_C_s32 *)arg0)->v = ((struct gd_C_s32 *)arg0)->v & -129;
    ((struct gd_1DC_f32 *)arg0)->v = 0.01f;
    ((struct gd_1E0_f32 *)arg0)->v = (f32)func_80067FB0(((f64)((struct gd_30_f32 *)arg0)->v), ((f64)((struct gd_38_f32 *)arg0)->v));
    ((struct gd_1E8_f32 *)arg0)->v = (f32)func_80067FB0(((f64)(((struct gd_24_f32 *)D_80075C20)->v - ((struct gd_24_f32 *)arg0)->v)), ((f64)(((struct gd_2C_f32 *)D_80075C20)->v - ((struct gd_2C_f32 *)arg0)->v)));
    ((struct gd_EC_s32 *)arg0)->v = (s32)&D_8002FEC4;
    func_8004A32C(D_80133E3C, 0);
    if (D_800A7ABC != 0) {
        func_8004CF14(D_800A7ABC, 0);
    }
    switch (D_8012EFD0) {
    case 16:
        func_8004CF14(D_800A7AFC, 0);
        func_8001892C(((s32)&D_00507070), ((s32)&D_00507890), 85, 20);
        if (D_800A7608 == D_800A75E8) {
            D_8012FCE0 = 16;
        } else {
            if (D_800ACBA0 == D_8010E488) {
                D_8012FCE0 = 19;
                D_80109C3C = 0;
            } else {
                D_8012FCE0 = 15;
            }
        }
        return;
    case 15:
        func_8004CF14(D_800A7AFC, 0);
        func_8001892C(((s32)&D_00501130), ((s32)&D_00501820), 85, 20);
        if (D_800A7608 == D_800A75E8) {
            D_8012FCE0 = 16;
        } else {
            if (D_800ACBA0 == D_8010E488) {
                D_8012FCE0 = 19;
                D_80109C3C = 0;
            } else {
                D_8012FCE0 = 16;
            }
        }
        return;
    case 17:
        func_8004CF14(D_800A7AFC, 0);
        func_8001892C(((s32)&D_004FA460), ((s32)&D_004FAC20), 85, 20);
        if (D_800A7608 == D_800A75E8) {
            D_8012FCE0 = 17;
        } else {
            if (D_800ACBA0 == D_8010E488) {
                D_8012FCE0 = 19;
                D_80109C3C = 2;
            } else {
                D_8012FCE0 = 18;
            }
        }
        return;
    case 18:
        func_8004CF14(D_800A7AFC, 0);
        func_8001892C(((s32)&D_004F1850), ((s32)&D_004F2030), 85, 20);
        if (D_800A7608 == D_800A75E8) {
            D_8012FCE0 = 17;
        } else {
            if (D_800ACBA0 == D_8010E488) {
                D_8012FCE0 = 19;
                D_80109C3C = 2;
            } else {
                D_8012FCE0 = 17;
            }
        }
        return;
    case 13:
        func_8004CF14(D_800A7AFC, 0);
        func_8001892C(((s32)&D_0050C970), ((s32)&D_0050D000), 85, 20);
        if (D_800A7608 == D_800A75E8) {
            D_8012FCE0 = 13;
        } else {
            if (D_800ACBA0 == D_8010E488) {
                D_8012FCE0 = 19;
                D_80109C3C = 1;
            } else {
                D_8012FCE0 = 14;
            }
        }
        return;
    case 14:
        func_8004CF14(D_800A7AFC, 0);
        func_8001892C(((s32)&D_0050C970), ((s32)&D_0050D000), 85, 20);
        if (D_800A7608 == D_800A75E8) {
            D_8012FCE0 = 13;
        } else {
            if (D_800ACBA0 == D_8010E488) {
                D_8012FCE0 = 19;
                D_80109C3C = 1;
            } else {
                D_8012FCE0 = 13;
            }
        }
        return;
    case 19:
        D_8012FCE0 = 2;
        return;
    default:
        D_8012FCE0 = 19;
        return;
    case 4:
    }
    D_8012FCE0 = 2;
    return;
}
