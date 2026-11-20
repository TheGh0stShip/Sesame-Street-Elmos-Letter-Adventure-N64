extern char D_8007B950[];
double sqrt(double);
f64 func_80067FB0(f64, f64);
void func_80068B70(s32, char *, f64, f64, f64);
/* arcsine: range check then atan2(x, sqrt(1-x*x)) */
f64 func_80067B60(f64 x) {
    if ((x > 1.0) | (x < -1.0)) {
        func_80068B70(1, D_8007B950, x, 0.0, 0.0);
        return;
    }
    return func_80067FB0(x, sqrt(1.0 - x * x));
}
