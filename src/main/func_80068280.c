f64 func_80068120(f64);
/* floor(): truncate, step down for negative non-integers */
f64 func_80068280(f64 x) {
    f64 t = func_80068120(x);
    if ((x < 0.0) & (t != x)) {
        return t - 1.0;
    }
    return t;
}
