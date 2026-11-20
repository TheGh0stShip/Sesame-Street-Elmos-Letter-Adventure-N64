#include "common.h"

extern void *D_800773B4;

s32 func_80054BA4(s32 arg0) {
    return (s32) (f32) (((f64) ((f32) arg0 * (f32) (*(s32 *)((s8 *)(D_800773B4) + (0x40)))) / D_8007B270) + D_8007B278) & ~0xF;
}
