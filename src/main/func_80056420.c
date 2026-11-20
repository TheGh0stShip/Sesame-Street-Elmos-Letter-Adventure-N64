/* guScaleF */
void func_800556D0(float mf[4][4]); /* guMtxIdentF */
void func_80056420(float mf[4][4], float x, float y, float z) {
    func_800556D0(mf);
    mf[0][0] = x;
    mf[1][1] = y;
    mf[2][2] = z;
    mf[3][3] = 1;
}
