#include "common.h"

/* 2^x by ln2 power series; 1/2^-x for negative x */
f32 func_8004E84C(f32 x) {
    f32 x2, x4, y4;
    f64 r;
    if (x == 0.0f) return 1.0f;
    if (x > 0.0f) {
        x2 = x * x;
        return (f64)x * D_8007B0E0 + D_8007B100 + (f64)x2 * D_8007B0E8 + (f64)(x2 * x) * D_8007B0F0
          + (f64)(x2 * x2) * D_8007B0F8 + (f64)(x2 * x2 * x) * D_8007B108 + (f64)(x2 * x2 * x2) * D_8007B110;

    } else {
        x = -x;
        x2 = x * x;
        y4 = x2 * x2;
        return D_8007B0C8 / ((f64)x * D_8007B0A8 + D_8007B0C8 + (f64)x2 * D_8007B0B0 + (f64)(x2 * x) * D_8007B0B8
          + (f64)y4 * D_8007B0C0 + (f64)(y4 * x) * D_8007B0D0 + (f64)(y4 * x2) * D_8007B0D8);
    }
}
