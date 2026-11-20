typedef struct {
    s32 cur;
    s32 slot[3];
    s32 val[3];
} Picks;

extern s32 func_80017084(u8);
extern s32 func_80020EB4(s32);
extern void func_80068300(Picks, s32, s32);
extern s32 D_801068A0;
extern s32 D_80108B20;
extern u8 D_8012FD08[];
extern Picks D_80133E58;

/* picks three distinct slots (avoiding ones rejected by func_80017084) and random values for them */
void func_80016D80(void) {
    s32 i;
    s32 n;

    func_80068300(D_80133E58, 0, 0x1C);
    for (i = 0; i < 3; i++) {
        D_80133E58.slot[i] = -1;
    }
    if (func_80017084(D_8012FD08[D_80108B20]) != 0) {
        D_80133E58.slot[func_80020EB4(3)] = D_80108B20;
    }
    for (i = 0; i < 3; i++) {
        if (D_80133E58.slot[i] == -1) {
            n = func_80020EB4(D_801068A0);
            while (n == D_80133E58.slot[0] || n == D_80133E58.slot[1] || n == D_80133E58.slot[2]) {
                n = (n + 1) % D_801068A0;
                while (func_80017084(D_8012FD08[n]) != 0) {
                    n = (n + 1) % D_801068A0;
                }
            }
            D_80133E58.slot[i] = n;
        }
        D_80133E58.val[i] = func_80020EB4(2);
    }
    D_80133E58.cur = -1;
}
