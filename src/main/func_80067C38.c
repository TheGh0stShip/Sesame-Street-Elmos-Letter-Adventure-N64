extern char D_8007B970[];
f64 func_80067B60(f64);
f64 func_80068B70(s32, char *, f64, f64, f64);
/* acos */
f64 func_80067C38(f64 x) {
    if (x > 1.0 || x < -1.0) {
        return func_80068B70(1, D_8007B970, x, 0.0, 0.0);
    }
    return 1.5707963267948966 - func_80067B60(x);
}
