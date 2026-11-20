#include "common.h"


void func_8002614C(s32 arg0) {
    s32 sp18;
    s32 pad0;
    s8 pad1;

    sp18 = arg0;
    if (D_800ACC2E == 0) {
        switch (D_8012EFD0) {
        case 2:
            if ((--((struct gd_4C_s16 *)sp18)->v) < 0) {
                ((struct gd_48_s32 *)sp18)->v = func_80017568((*(s32 *)((func_80020EB4(5) * 4) + ((s32)&D_80075C6C))));
                ((struct gd_4C_s16 *)sp18)->v = func_80020EB4(180) + 60;
            }
            break;
        case 19:
            if ((--((struct gd_4C_s16 *)sp18)->v) < 0) {
                ((struct gd_48_s32 *)sp18)->v = func_80017568((*(s32 *)((func_80020EB4(2) * 4) + ((s32)&D_80075CAC))));
                ((struct gd_4C_s16 *)sp18)->v = func_80020EB4(600) + 240;
            }
            break;
        case 15:
        case 16:
            if ((--((struct gd_4C_s16 *)sp18)->v) < 0) {
                ((struct gd_48_s32 *)sp18)->v = func_80017568((*(s32 *)((func_80020EB4(2) * 4) + ((s32)&D_80075C80))));
                ((struct gd_4C_s16 *)sp18)->v = func_80020EB4(420) + 180;
            }
            break;
        case 18:
            if ((--((struct gd_4C_s16 *)sp18)->v) < 0) {
                ((struct gd_48_s32 *)sp18)->v = func_80017568((*(s32 *)((func_80020EB4(4) * 4) + ((s32)&D_80075C88))));
                ((struct gd_4C_s16 *)sp18)->v = func_80020EB4(240) + 180;
            }
            break;
        case 17:
            if ((--((struct gd_4C_s16 *)sp18)->v) < 0) {
                ((struct gd_48_s32 *)sp18)->v = func_80017568((*(s32 *)((func_80020EB4(5) * 4) + ((s32)&D_80075C98))));
                ((struct gd_4C_s16 *)sp18)->v = func_80020EB4(240) + 180;
            }
            break;
        case 14:
            break;
        case 13:
            break;
        }
        return;
    }
    if (D_80109B8C >= 5) {
        if (D_80109B8C >= 8) {
            ((struct gd_C_s32 *)sp18)->v = ((struct gd_C_s32 *)sp18)->v | 1;
        }
        return;
    }
    if (D_80109B8C == 0) {
        if (((struct gd_24_s32 *)sp18)->v == 0) {
        } else {
            if (((struct gd_24_s32 *)sp18)->v >= 16) {
                D_80109B8C = 1;
            }
        }
    }
    addActorDL(((s32)&D_800264F4), 0, 3, 0, 0);
    ((struct gd_24_s32 *)sp18)->v++;
}
