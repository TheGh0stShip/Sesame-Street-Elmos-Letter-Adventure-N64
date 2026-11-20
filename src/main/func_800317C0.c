extern s8 D_800A7AB4;
extern s32 D_800ACC08;
extern s32 D_8010688C;
extern s32 D_801068A0;
extern s32 D_80108B20;
extern u8 D_80109BB0[][30];
extern s32 D_8012FD08;
s32 func_80031918();
s32 func_8005F4E8();
s32 func_8005F50C();
s32 func_80068300();

void f(s32 arg0, s32 arg1) {
    if (D_8010688C == 0) {
        func_80031918(9, 8, 9, 26);
        D_8010688C = 1;
    }
    D_801068A0 = func_8005F4E8(arg0);
    func_80068300(((s32)&D_8012FD08), 0, 30);
    func_8005F50C(((s32)&D_8012FD08), arg0, D_801068A0);
    if ((*(s32 *)((arg1 * 4) + ((s32)&D_800ACC08))) >= D_801068A0) {
        (*(s32 *)((arg1 * 4) + ((s32)&D_800ACC08))) = 0;
    }
    D_80108B20 = D_80109BB0[arg1][(*(s32 *)((arg1 * 4) + ((s32)&D_800ACC08)))++];
    D_800A7AB4 = *(u8 *)(D_80108B20 + ((s32)&D_8012FD08));
}
