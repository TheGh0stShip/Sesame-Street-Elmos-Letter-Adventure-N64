

extern s32 D_800732C0;
extern s32 D_800732D0;
extern s32 D_800732E0;
extern s32 D_800745E0;
extern s32 D_800745E8;
extern u8 D_800745ED;
extern u8 D_800745EE;
extern s32 D_80074658;
extern u16 D_80109C3E;
extern s32 D_80115374;
extern s32 D_8012EF88;
extern s16 D_8013C650;
extern s32 D_8013ED88;
s32 func_80057230();
s32 func_80057650();

void f(void) {
    s8 pad0;

    if (D_800745ED == 1) {
        if (D_80115374 == 0) {
            switch (D_800745E0) {
            case 0:
                D_80115374 = (s32)&D_800732C0;
                break;
            case 1:
                D_80115374 = (s32)&D_800732D0;
                break;
            case 2:
                D_80115374 = (s32)&D_800732E0;
                break;
            default:
                D_80115374 = (s32)&D_800732C0;
                break;
            }
            func_80057230(((s32)&D_8013ED88), 0, 1);
        }
        D_800745E8++;
        if (D_800745E8 >= 2) {
            if ((D_800745EE >> 1) < (*(s32 *)((D_800745E0 * 4) + ((s32)&D_80074658)))) {
                D_800745EE = D_800745EE + 2;
                D_800745E8 = 0;
            }
        }
        if ((D_800745EE >> 1) == (*(s32 *)((D_800745E0 * 4) + ((s32)&D_80074658)))) {
            if (D_80115374 != 0) {
                D_8013C650 = (u32)D_80109C3E >> 3;
                func_80057650(((s32)&D_8012EF88));
            }
            D_800745ED = 0;
            D_800745EE = 0;
        }
    }
}
