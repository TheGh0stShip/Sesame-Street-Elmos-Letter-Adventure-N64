#include "common.h"

/* arcsine: range check then atan2(x, sqrt(1-x*x)) */
f64 asin(f64 x) {
    if ((x > 1.0) | (x < -1.0)) {
        func_80068B70(1, D_8007B950, x, 0.0, 0.0);
        return;
    }
    return atan2(x, sqrt(1.0 - x * x));
}
