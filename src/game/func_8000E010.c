#include "common.h"


/* seeds the RNG and fills tables of random integers and clamped random doubles */
s32 func_8000E010(s32 arg0, s32 arg1) {
    f64 a;
    f64 scale;
    s32 sum;
    s32 i;
    s32 k;

    D_80071E40 = 0x200;
    (*(s32 *(*))&D_80071E44) = D_8009D0A0;
    D_80071E48 = D_8009D8A0;
    D_80071E50 = 0;
    D_80071E4C = 0;
    D_80071E58 = 0;
    D_80071E54 = 0;
    func_80068404(arg0);
    for (i = 0; i < D_80071E40; i++) {
        (*(s32 *(*))&D_80071E44)[i] = abs(func_800683D0() % 32767);
    }
    a = func_80068880(D_80079880);
    scale = 2.0 * a / 983010.0;
    for (i = 0; i < D_80071E40; i++) {
        do {
            sum = 0;
            for (k = 0; k < 30; k++) {
                sum += abs(func_800683D0() % 32767);
            }
            D_80071E48[i] = sum * scale - a;
        } while (D_80071E48[i] < -0.95 || D_80071E48[i] > 0.95);
    }
    D_80071E5C = 1;
    return arg0;
}
