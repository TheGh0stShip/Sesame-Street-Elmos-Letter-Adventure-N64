typedef struct {
    /* 0x00 */ u8 letter[0x20];
    /* 0x20 */ s32 unk20[(0xA0 - 0x20) / 4];
} LetterSet;

extern u8 D_800745F4;
extern s32 D_800A75E8;
extern u8 D_800A7AB4;
extern s32 D_801068A0;
extern s32 D_80108B20;
extern s32 D_8012FD08;
extern s32 D_8013EB88;
s32 func_80020EB4();
s32 func_80040400();
s32 func_80068300();

LetterSet *func_800323F4(s32 arg0) {
    register LetterSet *reg_s0;
    s32 sp10;
    s32 sp14;
    s32 sp18;
    s32 pad0;
    s32 pad1;
    u8 sp24;

    D_8013EB88 = 0;
    D_80108B20 = arg0;
    D_800A7AB4 = *(u8 *)(D_80108B20 + ((s32)&D_8012FD08));
    reg_s0 = (LetterSet *)func_80040400(160);
    if (reg_s0 == NULL) {
        return NULL;
    }
    func_80068300(reg_s0, 0, 160);
    sp10 = 0;
    while (!(sp10 >= 20)) {
        reg_s0->letter[sp10] = 0;
        reg_s0->unk20[sp10] = -1;
        sp10++;
    }
    sp14 = func_80020EB4(7);
    if (sp14 == 7) {
        sp14 = 6;
    }
    reg_s0->letter[sp14 + 1] = D_800A7AB4;
    reg_s0->unk20[sp14 + 1] = 0;
    D_800A75E8 = 3;
    sp10 = 0;
    while (!(sp10 >= 8)) {
        if (reg_s0->letter[sp10] == 0) {
            sp14 = func_80020EB4(D_801068A0);
            sp24 = 0;
            while (!(sp24 >= sp10)) {
                sp18 = reg_s0->letter[sp24] - 65;
                if (D_800745F4 == 11) {
                    if ((sp18 == sp14) || ((sp14 == arg0) || ((sp14 == 2) || ((sp14 == 5) || (sp14 == 18))))) {
                        sp14 = func_80020EB4(D_801068A0);
                        sp24 = 0;
                    } else {
                        sp24++;
                    }
                } else {
                    if ((sp18 == sp14) || (sp14 == arg0)) {
                        sp14 = func_80020EB4(D_801068A0);
                        sp24 = 0;
                    } else {
                        sp24++;
                    }
                }
            }
            reg_s0->letter[sp10] = *(u8 *)(sp14 + ((s32)&D_8012FD08));
        }
        sp10++;
    }
    return reg_s0;
}
