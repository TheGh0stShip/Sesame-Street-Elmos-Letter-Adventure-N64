typedef s32 Mtx[16];
void func_80055628(f32 mf[4][4], Mtx *m);  /* guMtxL2F */
void func_80055810(f32 a[4][4], f32 b[4][4], f32 r[4][4]); /* guMtxCatF */
void func_80055590(f32 mf[4][4], Mtx *m);  /* guMtxF2L */
/* guMtxCatL */
void func_800559A0(Mtx *m, Mtx *n, Mtx *res) {
    f32 mf[4][4], nf[4][4], resf[4][4];
    func_80055628(mf, m);
    func_80055628(nf, n);
    func_80055810(mf, nf, resf);
    func_80055590(resf, res);
}
