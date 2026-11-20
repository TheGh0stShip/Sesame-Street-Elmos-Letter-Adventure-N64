extern char D_8007B9B8[];
f64 func_80067E98(f64 x);
f64 func_80068B70(s32 type, char *name, f64 a, f64 b, f64 ret);

/* atan2(y, x) on top of atan, with a domain-error report for (0, 0) */
f64 func_80067FB0(f64 y, f64 x) {
    f64 r;

    if ((x == 0.0) & (y == 0.0)) {
        return func_80068B70(1, D_8007B9B8, x, y, 0.0);
    }
    if (x == 0.0) {
        if (y > 0.0) {
            return 1.5707963267948966;
        }
        return -1.5707963267948966;
    }
    r = func_80067E98(y / x);
    if (x > 0.0) {
        return r;
    }
    if (y == 0.0) {
        return 3.141592653589793;
    }
    if (y > 0.0) {
        return r + 3.141592653589793;
    }
    return r - 3.141592653589793;
}
