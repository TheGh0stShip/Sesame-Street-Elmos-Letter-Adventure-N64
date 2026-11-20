/* guRotateF */
extern f32 D_800773C0; /* dtor */
void func_800603C0(f32 *x, f32 *y, f32 *z); /* guNormalize */
f32 func_80056500(f32); /* sinf */
f32 func_80054D30(f32); /* cosf */
void func_800556D0(f32 mf[4][4]); /* guMtxIdentF */

void func_80055E20(f32 mf[4][4], f32 a, f32 x, f32 y, f32 z)
{
    f32 sine, cosine, ab, bc, ca, t;

    func_800603C0(&x, &y, &z);
    a *= D_800773C0;
    sine = func_80056500(a);
    cosine = func_80054D30(a);
    t = (1 - cosine);
    ab = x * y * t;
    bc = y * z * t;
    ca = z * x * t;
    func_800556D0(mf);
    t = x * x;
    mf[0][0] = t + cosine * (1 - t);
    mf[2][1] = bc - x * sine;
    mf[1][2] = bc + x * sine;
    t = y * y;
    mf[1][1] = t + cosine * (1 - t);
    mf[2][0] = ca + y * sine;
    mf[0][2] = ca - y * sine;
    t = z * z;
    mf[2][2] = t + cosine * (1 - t);
    mf[1][0] = ab - z * sine;
    mf[0][1] = ab + z * sine;
}
