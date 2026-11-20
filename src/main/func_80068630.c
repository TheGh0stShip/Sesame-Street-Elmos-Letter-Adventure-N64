void func_80068410(f64, f64 *, f64 *);

/* reduce x by multiples of pi, then evaluate via func_80068410; sign flips on odd multiples */
f64 func_80068630(f64 x) {
    f64 r;
    f64 tmp;
    s32 n;
    n = (s32)(x / 3.141592653589793 + (x >= 0.0 ? 0.5 : -0.5));
    x = x - n * 3.141592653589793;
    if ((x < 1e-08) & (x > -1e-08)) {
        return x;
    }
    func_80068410(x, &r, &tmp);
    return (n & 1) ? -r : r;
}
