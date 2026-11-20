
struct gd_8_s32 { u8 pad[0x8]; s32 v; };
struct gd_C_s16 { u8 pad[0xC]; s16 v; };
struct gd_10_s16 { u8 pad[0x10]; s16 v; };
struct gd_14_s16 { u8 pad[0x14]; s16 v; };
struct gd_18_s8 { u8 pad[0x18]; s8 v; };
struct gd_19_s8 { u8 pad[0x19]; s8 v; };
struct gd_1A_s8 { u8 pad[0x1A]; s8 v; };
struct gd_1B_s8 { u8 pad[0x1B]; s8 v; };
struct gd_21_s8 { u8 pad[0x21]; s8 v; };
struct gd_23_s8 { u8 pad[0x23]; s8 v; };
struct gd_24_s16 { u8 pad[0x24]; s16 v; };
extern s32 D_8001185C;
extern s32 D_800118EC;
extern s32 D_80011A58;
extern s8 D_800731E0;
extern s8 D_800731E1;
extern s8 D_800731E2;
extern s8 D_80109C70;
extern u8 D_801282A3;
s32 func_80012A08();
s32 func_80020D30();

void func_80011D50(s32 arg0, s32 arg1, s32 arg2) {
    register s32 reg_s0;
    register s32 reg_s1;
    register s32 reg_s2;
    register s32 reg_s3;

    D_80109C70 = 1;
    if ((u32)D_801282A3 < 128) {
        D_801282A3++;
    }
    reg_s2 = func_80020D30();
    reg_s3 = reg_s2 & 255;
    reg_s2 = (u32)reg_s2 >> 8;
    if (reg_s3 == 0) {
    }
    reg_s3 = reg_s2 & 15;
    reg_s2 = (u32)reg_s2 >> 4;
    if (D_800731E1 == 0) {
        if (reg_s3 == 0) {
            if ((reg_s0 = func_80012A08()) != 0) {
                ((struct gd_21_s8 *)reg_s0)->v = 0;
                D_800731E1 = 1;
                ((struct gd_8_s32 *)reg_s0)->v = (s32)&D_80011A58;
                ((struct gd_C_s16 *)reg_s0)->v = ((u16)arg0) << 2;
                ((struct gd_10_s16 *)reg_s0)->v = ((u16)arg1) << 2;
                ((struct gd_14_s16 *)reg_s0)->v = ((u16)arg2) << 2;
                reg_s2 = func_80020D30();
                reg_s3 = reg_s2 & 7;
                reg_s3 = reg_s3 + 30;
                reg_s2 = (u32)reg_s2 >> 3;
                ((struct gd_24_s16 *)reg_s0)->v = reg_s3;
                reg_s3 = reg_s2 & 7;
                reg_s3 = reg_s3 + 20;
                reg_s2 = (u32)reg_s2 >> 4;
                ((struct gd_18_s8 *)reg_s0)->v = reg_s3;
                reg_s3 = reg_s2 & 127;
                reg_s3 = reg_s3 - 64;
                reg_s2 = (u32)reg_s2 >> 7;
                ((struct gd_19_s8 *)reg_s0)->v = reg_s3;
                reg_s3 = reg_s2 & 15;
                reg_s3 = reg_s3 + 112;
                reg_s2 = (u32)reg_s2 >> 7;
                ((struct gd_1A_s8 *)reg_s0)->v = reg_s3;
                reg_s3 = reg_s2 & 127;
                reg_s3 = reg_s3 - 64;
                reg_s2 = (u32)reg_s2 >> 7;
                ((struct gd_1B_s8 *)reg_s0)->v = reg_s3;
                ((struct gd_23_s8 *)reg_s0)->v = 1;
            }
        }
    }
    reg_s3 = reg_s2 & 15;
    reg_s2 = (u32)reg_s2 >> 4;
    if (D_800731E2 == 0) {
        if (reg_s3 == 0) {
            if ((reg_s0 = func_80012A08()) != 0) {
                ((struct gd_21_s8 *)reg_s0)->v = 1;
                D_800731E2 = 1;
                ((struct gd_8_s32 *)reg_s0)->v = (s32)&D_80011A58;
                ((struct gd_C_s16 *)reg_s0)->v = ((u16)arg0) << 2;
                ((struct gd_10_s16 *)reg_s0)->v = ((u16)arg1) << 2;
                ((struct gd_14_s16 *)reg_s0)->v = ((u16)arg2) << 2;
                reg_s2 = func_80020D30();
                reg_s3 = reg_s2 & 7;
                reg_s3 = reg_s3 + 30;
                reg_s2 = (u32)reg_s2 >> 3;
                ((struct gd_24_s16 *)reg_s0)->v = reg_s3;
                reg_s3 = reg_s2 & 7;
                reg_s3 = reg_s3 + 20;
                reg_s2 = (u32)reg_s2 >> 4;
                ((struct gd_18_s8 *)reg_s0)->v = reg_s3;
                reg_s3 = reg_s2 & 127;
                reg_s3 = reg_s3 - 64;
                reg_s2 = (u32)reg_s2 >> 7;
                ((struct gd_19_s8 *)reg_s0)->v = reg_s3;
                reg_s3 = reg_s2 & 15;
                reg_s3 = reg_s3 + 112;
                reg_s2 = (u32)reg_s2 >> 7;
                ((struct gd_1A_s8 *)reg_s0)->v = reg_s3;
                reg_s3 = reg_s2 & 127;
                reg_s3 = reg_s3 - 64;
                reg_s2 = (u32)reg_s2 >> 7;
                ((struct gd_1B_s8 *)reg_s0)->v = reg_s3;
                ((struct gd_23_s8 *)reg_s0)->v = 1;
            }
        }
    }
    if ((--D_800731E0) < 0) {
        reg_s3 = reg_s2 & 15;
        reg_s2 = (u32)reg_s2 >> 4;
        D_800731E0 = reg_s3 + 20;
        if ((reg_s0 = func_80012A08()) != 0) {
            ((struct gd_8_s32 *)reg_s0)->v = (s32)&D_800118EC;
            ((struct gd_C_s16 *)reg_s0)->v = ((u16)arg0) << 2;
            ((struct gd_10_s16 *)reg_s0)->v = ((u16)arg1) << 2;
            ((struct gd_14_s16 *)reg_s0)->v = ((u16)arg2) << 2;
            reg_s2 = func_80020D30();
            reg_s3 = reg_s2 & 15;
            reg_s3 = reg_s3 + 70;
            reg_s2 = (u32)reg_s2 >> 4;
            ((struct gd_24_s16 *)reg_s0)->v = reg_s3;
            reg_s3 = reg_s2 & 7;
            reg_s3 = reg_s3 + 15;
            reg_s2 = (u32)reg_s2 >> 3;
            ((struct gd_18_s8 *)reg_s0)->v = reg_s3;
            reg_s3 = reg_s2 & 127;
            reg_s3 = reg_s3 - 64;
            reg_s2 = (u32)reg_s2 >> 7;
            reg_s3 = reg_s3 & 248;
            ((struct gd_19_s8 *)reg_s0)->v = reg_s3;
            reg_s3 = reg_s2 & 31;
            reg_s3 = reg_s3 + 40;
            reg_s2 = (u32)reg_s2 >> 6;
            ((struct gd_1A_s8 *)reg_s0)->v = reg_s3;
            reg_s3 = reg_s2 & 127;
            reg_s3 = reg_s3 - 64;
            reg_s2 = (u32)reg_s2 >> 7;
            reg_s3 = reg_s3 & 248;
            ((struct gd_1B_s8 *)reg_s0)->v = reg_s3;
            ((struct gd_23_s8 *)reg_s0)->v = 1;
        }
    }
    reg_s3 = reg_s2 & 1;
    reg_s2 = (u32)reg_s2 >> 1;
    reg_s1 = reg_s3 + 2;
    for (;;) {
        if ((reg_s0 = func_80012A08()) != 0) {
            ((struct gd_8_s32 *)reg_s0)->v = (s32)&D_8001185C;
            ((struct gd_C_s16 *)reg_s0)->v = ((u16)arg0) << 2;
            ((struct gd_10_s16 *)reg_s0)->v = ((u16)arg1) << 2;
            ((struct gd_14_s16 *)reg_s0)->v = ((u16)arg2) << 2;
            reg_s2 = func_80020D30();
            reg_s3 = reg_s2 & 7;
            reg_s3 = reg_s3 + 20;
            reg_s2 = (u32)reg_s2 >> 3;
            ((struct gd_24_s16 *)reg_s0)->v = reg_s3;
            reg_s3 = reg_s2 & 15;
            reg_s3 = reg_s3 + 7;
            reg_s2 = (u32)reg_s2 >> 4;
            ((struct gd_18_s8 *)reg_s0)->v = reg_s3;
            reg_s3 = reg_s2 & 127;
            reg_s3 = reg_s3 - 64;
            reg_s2 = (u32)reg_s2 >> 7;
            reg_s3 = reg_s3 & 248;
            ((struct gd_19_s8 *)reg_s0)->v = reg_s3;
            reg_s3 = reg_s2 & 63;
            reg_s3 = reg_s3 + 64;
            reg_s2 = (u32)reg_s2 >> 7;
            ((struct gd_1A_s8 *)reg_s0)->v = reg_s3;
            reg_s3 = reg_s2 & 127;
            reg_s3 = reg_s3 - 64;
            reg_s2 = (u32)reg_s2 >> 7;
            reg_s3 = reg_s3 & 248;
            ((struct gd_1B_s8 *)reg_s0)->v = reg_s3;
            ((struct gd_23_s8 *)reg_s0)->v = 0;
        }
        reg_s1 = reg_s1 - 1;
        if (reg_s1 == 0) {
            return;
        }
    }
}
