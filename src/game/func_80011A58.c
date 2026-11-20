#include "common.h"


void func_80011A58(register s32 arg0) {
    register s32 reg_s1;
    register s32 reg_s2;
    register s32 reg_s3;
    register s32 reg_s4;
    register s8 reg_s5;
    s8 pad0;

    ((struct gd_C_s32 *)arg0)->v = (((struct gd_19_s8 *)arg0)->v << 14) + ((struct gd_C_s32 *)arg0)->v;
    ((struct gd_10_s32 *)arg0)->v = (((struct gd_1A_s8 *)arg0)->v << 16) + ((struct gd_10_s32 *)arg0)->v;
    ((struct gd_14_s32 *)arg0)->v = (((struct gd_1B_s8 *)arg0)->v << 14) + ((struct gd_14_s32 *)arg0)->v;
    if (((struct gd_1A_s8 *)arg0)->v >= -118) {
        ((struct gd_1A_s8 *)arg0)->v = ((struct gd_1A_u8 *)arg0)->v - 4;
    }
    if (--((struct gd_18_s8 *)arg0)->v == 0) {
        func_80012AA4(arg0);
        func_8004CC30(60);
        if (--(*(u8 (*))&D_8012FD40) == 0) {
            (*(u8 (*))&D_8012FD40) = (func_80020D30() & 3) + 7;
            if (D_800A7B04 == 0) {
                func_8004CC30(63);
                D_800A7B04 = 1;
            } else {
                func_8004CC30(64);
                D_800A7B04 = 0;
            }
        }
        if (((struct gd_21_u8 *)arg0)->v == 0) {
            D_800731E1 = 0;
        } else {
            D_800731E2 = 0;
        }
        reg_s5 = func_80020D30();
        reg_s5 &= 6;
        reg_s4 = 0;
        while (!(reg_s4 == 32)) {
            if ((reg_s1 = func_80012A08()) != 0) {
                ((struct gd_8_s32 *)reg_s1)->v = (s32)&D_8001185C;
                ((struct gd_C_s32 *)reg_s1)->v = ((struct gd_C_s32 *)arg0)->v;
                ((struct gd_10_s32 *)reg_s1)->v = ((struct gd_10_s32 *)arg0)->v;
                ((struct gd_14_s32 *)reg_s1)->v = ((struct gd_14_s32 *)arg0)->v;
                reg_s3 = func_80020D30();
                reg_s2 = reg_s3 & 127;
                reg_s2 = reg_s2 - 64;
                reg_s3 = (u32)reg_s3 >> 7;
                ((struct gd_19_s8 *)reg_s1)->v = reg_s2;
                reg_s2 = reg_s3 & 127;
                reg_s2 = reg_s2 - 64;
                reg_s3 = (u32)reg_s3 >> 7;
                ((struct gd_1A_s8 *)reg_s1)->v = reg_s2;
                reg_s2 = reg_s3 & 127;
                reg_s2 = reg_s2 - 64;
                reg_s3 = (u32)reg_s3 >> 7;
                ((struct gd_1B_s8 *)reg_s1)->v = reg_s2;
                ((struct gd_24_s16 *)reg_s1)->v = 35;
                reg_s2 = reg_s3 & 7;
                reg_s2 = reg_s2 + 15;
                reg_s3 = (u32)reg_s3 >> 4;
                ((struct gd_18_s8 *)reg_s1)->v = reg_s2;
                ((struct gd_23_s8 *)reg_s1)->v = reg_s5;
            }
            reg_s4 = reg_s4 + 1;
        }
        return;
    }
    for (reg_s4 = 0; !(reg_s4 == 4); reg_s4 = reg_s4 + 1) {
        if ((reg_s1 = func_80012A08()) != 0) {
            ((struct gd_8_s32 *)reg_s1)->v = (s32)&D_8001185C;
            ((struct gd_C_s32 *)reg_s1)->v = ((struct gd_C_s32 *)arg0)->v;
            ((struct gd_10_s32 *)reg_s1)->v = ((struct gd_10_s32 *)arg0)->v;
            ((struct gd_14_s32 *)reg_s1)->v = ((struct gd_14_s32 *)arg0)->v;
            reg_s3 = func_80020D30();
            reg_s2 = reg_s3 & 31;
            reg_s2 = reg_s2 - 16;
            reg_s3 = (u32)reg_s3 >> 5;
            ((struct gd_19_s8 *)reg_s1)->v = reg_s2;
            reg_s2 = reg_s3 & 31;
            reg_s2 = reg_s2 - 16;
            reg_s3 = (u32)reg_s3 >> 5;
            ((struct gd_1A_s8 *)reg_s1)->v = reg_s2;
            reg_s2 = reg_s3 & 31;
            reg_s2 = reg_s2 - 16;
            reg_s3 = (u32)reg_s3 >> 5;
            ((struct gd_1B_s8 *)reg_s1)->v = reg_s2;
            ((struct gd_24_s16 *)reg_s1)->v = 35;
            ((struct gd_18_s8 *)reg_s1)->v = 10;
            ((struct gd_23_s8 *)reg_s1)->v = 2;
        }
    }
}
