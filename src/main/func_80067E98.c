u64 func_80069020(f64);
void func_80067CE0(u64, u64, f64 *);

/* Signed wrapper: for |x| > 1e-7 calls func_80067CE0 on a 2^60 fixed-point ratio (x or 1/x), else returns x. */
f64 func_80067E98(f64 x) {
    f64 r;
    s32 sign;
    u64 n, d;
    f64 a;

    if (x < 0.0) {
        x = -x;
        sign = -1;
    } else {
        sign = 1;
    }
    if (x > 1e-7) {
        if (x >= 1.0) {
            f64 c;
            d = 0x1000000000000000ULL;
            a = 1.0 / x;
            c = 1152921504606846976.0;
            a *= c;
            n = func_80069020(a);
        } else {
            n = 0x1000000000000000ULL;
            d = func_80069020(x * 1152921504606846976.0);
        }
        func_80067CE0(n, d, &r);
    } else {
        r = x;
    }
    return (sign < 0) ? -r : r;
}
