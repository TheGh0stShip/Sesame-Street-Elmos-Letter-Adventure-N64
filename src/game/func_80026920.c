#include "common.h"
/* Loop: streams data from D_800A75E0 in 0x4000-byte chunks via osPiStartDma. */





void func_80026920(s32 arg0) {
    s32 sp20[6];
    s32 sp38;
    s32 sp3C;
    s8 pad0;

    osCreateMesgQueue(((s32)&D_80140F78), ((s32)&D_8010E4A8), 1);
    while (1) {
        osRecvMesg(((s32)&D_80140F78), 0, 1);
        sp38 = func_80040400(D_800A75E0);
        D_801180A4 = sp38;
        switch (D_801180A4) {
        case 0:
            func_80057BD0(((s32)&D_8007A190), ((s32)&D_8007A194), 217);
        }
        for (; !(D_800A75E0 == 0); D_800A75E0 = D_800A75E0 - sp3C) {
            if ((u32)D_800A75E0 >= 0x4001) {
                sp3C = 0x4000;
            } else {
                sp3C = D_800A75E0;
            }
            osInvalDCache(sp38, sp3C);
            osPiStartDma(((s32)&sp20), 0, 0, D_80106874, sp38, sp3C, ((s32)&D_80140F78));
            osRecvMesg(((s32)&D_80140F78), 0, 1);
            D_80106874 = D_80106874 + sp3C;
            sp38 = sp38 + sp3C;
        }
        D_80106874 = 0;
    }
}
