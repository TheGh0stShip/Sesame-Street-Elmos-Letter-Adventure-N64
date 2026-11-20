#include "common.h"


/* calls 8004E9E0, then latches arg into D_800A00FC if it is unset */
void MusPtrBankInitialize(s32 arg0) {
    ((void (*)(void))func_8004E9E0)();
    if (D_800A00FC == 0) {
        D_800A00FC = arg0;
    }
}
