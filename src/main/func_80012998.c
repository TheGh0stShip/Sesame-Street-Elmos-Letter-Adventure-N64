extern s32 D_800A7B00;
extern s32 D_800A8FA0;
extern s32 D_801283A8;
extern s32 D_8013C5BC;

void f(void) {
    register s32 reg_v0;
    register s32 reg_v1;
    register s32 reg_a0;

    reg_v0 = (s32)&D_800A8FA0;
    reg_a0 = 383;
    while (!(reg_a0 == 0)) {
        reg_v1 = reg_v0 + 40;
        (*(s32 *)reg_v0) = reg_v1;
        reg_v0 = reg_v1;
        reg_a0 = reg_a0 - 1;
    }
    (*(s32 *)reg_v0) = 0;
    D_801283A8 = (s32)&D_800A8FA0;
    D_800A7B00 = 0;
    D_8013C5BC = 0;
}
