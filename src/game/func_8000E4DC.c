#include "common.h"

/* Returns a + b * next entry of a cyclic table, or a constant when disabled. */
f64 func_8000E4DC(f64 a, f64 b) {
    f64 v;

    if (D_80071E5C == 0) {
        return -1.0;
    }
    v = D_80071E48[D_80071E50];
    v = v * b;
    v = v + a;
    D_80071E50++;
    D_80071E50 %= D_80071E40;
    return v;
}
