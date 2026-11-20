#include "common.h"
/* Draws an 8x8 font glyph for a character into a framebuffer row; CR/LF move the cursor. */





void func_8000E7A0(u8 arg0) {
    register u8 *reg_v1;
    register u8 *reg_a0;
    register s32 reg_a1;
    register s32 reg_a2;
    register s32 reg_a3;

    if (((u32)arg0 >= 32) && ((u32)arg0 < 128)) {
        reg_a3 = 8;
        reg_a0 = ((arg0 - 32) << 3) + D_80071E60;
        reg_v1 = (((*(u8 (*))&D_800A8CD0) << 10) + (*(u8 *(*))&D_800ACC1C)) + ((*(u8 (*))&D_8010791C) << 2);
        reg_a2 = 0;
        while (!(reg_a2 == reg_a3)) {
            reg_a1 = 0;
            while (!(reg_a1 == reg_a3)) {
                if ((((*reg_a0) >> reg_a1) & 1) != 0) {
                    if ((reg_a1 % 2) == 0) {
                        (*reg_v1) = (*reg_v1) | 11;
                    } else {
                        (*reg_v1) = (*reg_v1) | 176;
                    }
                }
                if ((reg_a1 % 2) == 0) {
                    reg_v1 = reg_v1 + 1;
                }
                reg_a1 = reg_a1 + 1;
            }
            reg_v1 = reg_v1 + 124;
            reg_a0 = reg_a0 + 1;
            reg_a2 = reg_a2 + 1;
        }
        (*(u8 (*))&D_8010791C)++;
        return;
    }
    switch (arg0) {
    case 13:
        (*(u8 (*))&D_8010791C) = 0;
        return;
    case 10:
        if ((*(u8 (*))&D_800A8CD0) < (D_8012EFB8 - 1)) {
            (*(u8 (*))&D_800A8CD0)++;
        }
        return;
    }
}
