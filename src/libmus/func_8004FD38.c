#include "common.h"

void *Fbendrange(void *arg0, u8 *arg1) {
    f32 temp_f0_14;

    temp_f0_14 = (f32) ((f64) (f32) *arg1 * D_8007B150);
    (*(f32 *)((s8 *)(arg0) + (0x6C))) = temp_f0_14;
    (*(f32 *)((s8 *)(arg0) + (0x24))) = (f32) ((*(f32 *)((s8 *)(arg0) + (0x70))) * temp_f0_14);
    return arg1 + 1;
}
