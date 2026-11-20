typedef struct {
    u8 s[0x20];
    s32 idx[0x20];
} Word;

extern s32 D_8013EB88;
extern s32 D_80108B20;
extern u8 D_800A7AB4;
extern u8 D_8012FD08[];
extern u8 D_80106870;
extern s32 D_800A8D48;
extern s32 D_800A8F9C;
extern u8 D_800BD468[];
extern s32 D_800760F0[][20];
extern s32 D_801068A0;
u32 func_80020EB4(s32 n);
Word *func_80040400(s32 size);
void func_80068300(void *dst, s32 val, s32 size);

/* builds a random letter grid: places the target letter, spaced copies, and random fill letters */
Word *func_80031BB4(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 i;
    s32 j;
    s32 r;
    s32 unused;
    s32 c;
    s32 upper;
    register Word *p;

    D_8013EB88 = 0;
    D_80108B20 = arg3;
    D_800A7AB4 = D_8012FD08[D_80108B20];
    upper = 0;
    if (D_80106870 != 0 && func_80020EB4(10) < 5) {
        upper = 1;
    }
    p = func_80040400(0xA0);
    if (p == NULL) {
        return NULL;
    }
    func_80068300(p, 0, 0xA0);
    for (i = 0; i < arg0 + 2; i++) {
        p->s[i] = 0;
        p->idx[i] = -1;
    }
    if (D_80106870 == 2) {
        if (upper) {
            p->s[arg0] = D_800A7AB4;
        } else {
            p->s[arg0] = D_800A7AB4 + 0x20;
        }
    } else if (D_80106870 == 1) {
        if (func_80020EB4(10) < 5) {
            p->s[arg0] = D_800A7AB4;
        } else {
            p->s[arg0] = D_800A7AB4 + 0x20;
        }
    } else {
        p->s[arg0] = D_800A7AB4;
    }
    D_800A8D48 = arg1;
    D_800A8F9C = 0;
    arg2 = 0;
    if (arg2 == 0) {
        for (i = 0; i < 20; i++) {
            D_800BD468[i] = 0;
        }
    }
    r = func_80020EB4(20);
    i = 0;
    j = 1;
    for (; i < D_800A8D48 - 1; i++) {
        if (r >= 20) {
            r = 0;
        }
        j += D_800760F0[D_80106870][r++];
        if (j >= arg0) {
            j = 1;
        }
        while (p->s[j - 1] != 0 || p->s[j] != 0 || p->s[j + 1] != 0) {
            j++;
            if (j >= arg0) {
                j = 1;
            }
        }
        if (D_80106870 == 2) {
            if (upper) {
                p->s[j] = D_800A7AB4;
            } else {
                p->s[j] = D_800A7AB4 + 0x20;
            }
        } else if (D_80106870 == 1) {
            if (func_80020EB4(10) < 5) {
                p->s[j] = D_800A7AB4;
            } else {
                p->s[j] = D_800A7AB4 + 0x20;
            }
        } else {
            p->s[j] = D_800A7AB4;
        }
    }
    j = 0;
    for (i = 1; i <= arg0; i++) {
        if (p->s[i] == 0) {
            c = func_80020EB4(D_801068A0);
            if (c == D_80108B20) {
                c = (c + 1) % D_801068A0;
            }
            if (p->s[i - 1] == D_8012FD08[c]) {
                c = (c + 1) % D_801068A0;
                if (c == D_80108B20) {
                    c = (c + 1) % D_801068A0;
                }
            }
            if (p->s[i + 1] == D_8012FD08[c]) {
                c = (c + 1) % D_801068A0;
                if (c == D_80108B20) {
                    c = (c + 1) % D_801068A0;
                }
            }
            if (D_80106870 == 2) {
                if (upper) {
                    p->s[i] = D_8012FD08[c];
                } else {
                    p->s[i] = D_8012FD08[c] + 0x20;
                }
            } else if (D_80106870 == 1) {
                if (func_80020EB4(10) < 5) {
                    p->s[i] = D_8012FD08[c];
                } else {
                    p->s[i] = D_8012FD08[c] + 0x20;
                }
            } else {
                p->s[i] = D_8012FD08[c];
            }
        } else {
            p->idx[i] = arg2 + j++;
        }
    }
    if (D_80106870 == 2 || D_80106870 == 1) {
        if (upper) {
            D_800A7AB4 += 0x20;
        }
    }
    return p;
}
