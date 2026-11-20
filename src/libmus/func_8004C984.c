#include "common.h"


void MusSetMasterVolume(s32 arg0, s16 arg1) {
    if (arg0 & 1) {
        D_800A00EC = arg1;
    }
    if (arg0 & 2) {
        D_800A00EE = arg1;
    }
}
