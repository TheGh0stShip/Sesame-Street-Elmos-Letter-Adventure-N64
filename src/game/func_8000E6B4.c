#include "common.h"

/* Returns base + scale * next value from a cyclic table, or a default when disabled. */
f64 func_8000E6B4(f64 base, f64 scale) {
    f64 v;

    if (D_80071E5C == 0) {
        return D_800798A8;
    }
    v = D_80071E48[D_80071E58];
    v = v * scale;
    v = v + base;
    D_80071E58++;
    D_80071E58 = D_80071E58 % D_80071E40;
    return v;
}
