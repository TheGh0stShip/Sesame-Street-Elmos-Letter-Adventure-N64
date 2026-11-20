/* Loop: streams data from D_800A75E0 in 0x4000-byte chunks via func_8005EE10. */


extern s32 D_8007A190;
extern s32 D_8007A194;
extern s32 D_800A75E0;
extern s32 D_80106874;
extern s32 D_8010E4A8;
extern s32 D_801180A4;
extern s32 D_80140F78;
s32 func_80040400();
s32 func_80056A60();
s32 func_80056C40();
s32 func_80057100();
s32 func_80057BD0();
s32 func_8005EE10();

void f(s32 arg0) {
    s32 sp20[6];
    s32 sp38;
    s32 sp3C;
    s8 pad0;

    func_80056C40(((s32)&D_80140F78), ((s32)&D_8010E4A8), 1);
    while (1) {
        func_80057100(((s32)&D_80140F78), 0, 1);
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
            func_80056A60(sp38, sp3C);
            func_8005EE10(((s32)&sp20), 0, 0, D_80106874, sp38, sp3C, ((s32)&D_80140F78));
            func_80057100(((s32)&D_80140F78), 0, 1);
            D_80106874 = D_80106874 + sp3C;
            sp38 = sp38 + sp3C;
        }
        D_80106874 = 0;
    }
}
