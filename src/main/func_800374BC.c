extern s8 D_8006EDE1;
extern u8 D_800745F8;
extern u8 D_80075E30;
extern u8 D_80076221;
extern s32 D_800A75E8;
extern s32 D_800A7608;
extern s32 D_80115374;
extern s32 D_8012FCE0;
s32 func_80035828();

void f(s32 arg0) {
    if (D_80115374 == 0) {
        if ((D_800A7608 == D_800A75E8) && ((u32)D_80075E30 < 2)) {
            D_8006EDE1 = 0;
            D_80076221++;
            D_80075E30++;
            D_8012FCE0 = 19;
            func_80035828(arg0, 35);
            return;
        }
        if ((D_800A7608 == D_800A75E8) || (D_800745F8 != 0)) {
            if ((u32)D_80075E30 >= 2) {
                D_8006EDE1 = 0;
                D_80076221 = 0;
                D_800745F8 = 0;
                D_80075E30 = 0;
                D_8012FCE0 = 2;
                func_80035828(arg0, 35);
                return;
            }
        }
        func_80035828(arg0, 31);
    }
}
