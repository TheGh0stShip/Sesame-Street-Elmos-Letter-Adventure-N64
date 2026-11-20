/* guNormalize */
float sqrtf(float); /* func_80054D20 */
void func_800603C0(float *x, float *y, float *z)
{
    float m;

    m = 1 / sqrtf((*x) * (*x) + (*y) * (*y) + (*z) * (*z));
    *x *= m;
    *y *= m;
    *z *= m;
}
