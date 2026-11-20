/* converts a fixed-point matrix to float, then runs a 6-float matrix routine on it */
typedef struct { s32 m[4][4]; } Mtx;
extern void func_80055628(f32 mf[4][4], Mtx *m);    /* guMtxL2F */
extern void func_800558EC(f32 mf[4][4], f32, f32, f32, s32, s32, s32);
void func_80055A14(Mtx *m, f32 a, f32 b, f32 c, s32 d, s32 e, s32 f)
{
    f32 mf[4][4];

    func_80055628(mf, m);
    func_800558EC(mf, a, b, c, d, e, f);
}
