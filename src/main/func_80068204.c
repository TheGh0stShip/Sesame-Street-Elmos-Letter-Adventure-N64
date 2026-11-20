f64 func_80068120(f64);

/* rounds via 80068120 and adds 1.0 when x >= 0 and result != x (ceil-like) */
f64 func_80068204(f64 x) {
    f64 r = func_80068120(x);
    if ((x >= 0.0) & (r != x)) {
        return r + 1.0;
    }
    return r;
}
