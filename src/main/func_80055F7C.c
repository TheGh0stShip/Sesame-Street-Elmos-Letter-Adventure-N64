/* guRotate: build a rotation matrix (float, inlined guRotateF) and convert to fixed point */
typedef float Matrix[4][4];
typedef union { s32 m[4][4]; long long force_structure_alignment; } Mtx;
void func_800603C0(float *x, float *y, float *z); /* guNormalize */
float func_80056500(float); /* sinf */
float func_80054D30(float); /* cosf */
void func_800556D0(float mf[4][4]); /* guMtxIdentF */
void func_80055590(float mf[4][4], Mtx *m); /* guMtxF2L */

static void guRotateF(float mf[4][4], float a, float x, float y, float z)
{
    static float dtor = 3.1415926 / 180.0;
    float sine;
    float cosine;
    float ab, bc, ca, t;

    func_800603C0(&x, &y, &z);
    a *= dtor;
    sine = func_80056500(a);
    cosine = func_80054D30(a);
    t = (1-cosine);
    ab = x*y*t;
    bc = y*z*t;
    ca = z*x*t;

    func_800556D0(mf);

    t = x*x;
    mf[0][0] = t+cosine*(1-t);
    mf[2][1] = bc-(x * sine);
    mf[1][2] = bc+(x * sine);

    t = y*y;
    mf[1][1] = t+cosine*(1-t);
    mf[2][0] = ca+(y * sine);
    mf[0][2] = ca-(y * sine);

    t = z*z;
    mf[2][2] = t+cosine*(1-t);
    mf[1][0] = ab-(z * sine);
    mf[0][1] = ab+(z * sine);
}

void func_800578EC(Mtx *m, float a, float x, float y, float z)
{
    Matrix mf;

    guRotateF(mf, a, x, y, z);

    func_80055590(mf, m);
}
