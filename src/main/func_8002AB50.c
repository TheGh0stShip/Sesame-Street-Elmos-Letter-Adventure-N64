typedef struct Vec3f {
    f32 x;
    f32 y;
    f32 z;
} Vec3f;
typedef struct SndCmd {
    s32 unk_00;
    s16 unk_04;
} SndCmd;
typedef struct Elem40 {
    u8 unk_00[0x40];
} Elem40;
typedef struct Pair8 {
    s32 unk_00;
    s32 unk_04;
} Pair8;
typedef struct Actor Actor;
struct Actor {
    u8 pad0[0xC];
    s32 unk_0C;
    u8 pad10[0x8];
    void (*unk_18)(Actor *, s32);
    s32 unk_1C;
    u8 pad20[0x4];
    Vec3f unk_24;
    Vec3f unk_30;
    u8 pad3C[0x18];
    Vec3f unk_54;
    u8 pad60[0x8C];
    void (*unk_EC)(void);
    s32 unk_F0;
    u8 padF4[0x4];
    Elem40 unk_F8[2];
    u8 unk_178[0x50];
    s32 unk_1C8;
    u8 pad1CC[0x8];
    s32 unk_1D4;
    u8 pad1D8[0x14];
    s8 unk_1EC;
    u8 pad1ED[0x37];
    u16 unk_224;
    u16 unk_226;
};
typedef f32 Mtx44[4][4];

extern u8 *D_80075D00[];
extern u8 D_800ACC2E;
extern u8 D_800ACC2D;
extern s32 D_80070760;
extern s32 D_8012EFD0;
extern u8 D_8012EFCC;
extern SndCmd *D_80115374;
extern u16 D_80109C3E;
extern s16 D_8013C650;
extern u8 D_8012EF88[];
extern u8 D_8013ED88[];
extern s32 D_80133E3C;
extern u8 D_800A8DDC;
extern u8 D_801282A3;
extern u16 D_800A7AFA;
extern u16 D_800A7AA8;
extern s32 D_8006EDD8;
extern SndCmd D_800733C8[];
extern SndCmd D_800733D8[];
extern SndCmd D_800733E8[];
extern SndCmd D_800733F8[];
extern SndCmd D_80073408[];
extern SndCmd D_80073418[];
extern SndCmd D_80073428[];
extern u16 D_801078BA;
extern s32 D_8012FCE0;
extern u8 D_801078F0;
extern s32 D_80109B8C;
extern Actor *D_80106888;
extern s32 D_8012EF80;
extern s32 D_80073520[];
extern s32 D_800734A0[];
extern s32 D_80073590[];
extern s32 D_8007360C[];
extern s32 D_80073650[];
extern s32 D_80073690[];
extern Pair8 D_80073AD0[];
extern Pair8 D_80073860[];
extern Pair8 D_80073930[];
extern Pair8 D_80073A00[];
extern s32 D_80115380;

void func_8002BADC(void);
void func_80001424(void (*)(void), Actor *, s32, s32, s32);
void func_8000092C(s32, u8 *, u8 *, u16, Vec3f, Vec3f *, Elem40 *, Actor *);
void func_8001F1C8(Elem40 *, Vec3f *, Vec3f);
s32 func_80020EB4(s32);
void func_80031744(s32, Pair8 *);
void func_80035788(Actor *);
void func_80035828(Actor *, s32);
void func_80047ED4(Actor *);
void func_8004A294(s32, Vec3f *, Vec3f *);
void func_8004B470(s32, s32, s32, s32);
void func_8004CDC8(s32, s32);
void func_800559A0(Mtx44 *, Elem40 *, Elem40 *);
void func_80056288(Mtx44 *, s32, f32, s32);
void func_80057230(void *, void *, s32);
void func_80057650(void *);

void func_8002AB50(Actor *arg0) {
    Actor *o;
    s32 pad2C[32];
    Actor *it;
    f32 scale;
    s32 padB8;
    s32 padBC;
    s32 padC0;
    u8 *anim;
    s32 padC8[28];
    s32 a;
    s32 b;
    s32 c;
    s32 pad144;
    s32 pad148[26];
    Mtx44 m;
    s32 pad1F0[4];

    scale = 1.0f;
    a = 0;
    b = 0;
    c = 0;
    o = arg0;
    anim = D_80075D00[o->unk_1D4];
    if (D_800ACC2E != 0) {
        func_8001F1C8(&o->unk_F8[D_80070760], &o->unk_24, o->unk_54);
        if (D_8012EFD0 == 6 && o->unk_1EC != 0) {
            func_80056288(&m, 0, (f32)o->unk_1EC * 1.40625, 0);
            func_800559A0(&m, &o->unk_F8[D_80070760], &o->unk_F8[D_80070760]);
        }
        func_8000092C(o->unk_F0, o->unk_178, anim, o->unk_224 >> 4, o->unk_24, &o->unk_30, &o->unk_F8[D_80070760], o);
        func_80001424(func_8002BADC, o, 4, 1, 0);
    } else if (D_8012EFCC != 0) {
        if (D_8012EFCC == 1) {
            func_8004CDC8(1, 0);
            if (D_80115374 != NULL) {
                D_8013C650 = D_80109C3E >> 3;
                func_80057650(D_8012EF88);
            }
            D_8012EFCC = 2;
        }
        if (D_8012EFD0 != 11 && D_8012EFD0 != 19) {
            func_8004A294(D_80133E3C, &o->unk_24, &o->unk_30);
        }
        D_800A8DDC = 1;
        D_801282A3 = 0x80;
        switch (D_8012EFD0) {
            case 1:
            case 2:
                if ((u16)(D_800A7AFA % 1800) == 30) {
                    D_8006EDD8 &= ~0x70;
                    D_8006EDD8 |= 0x60A;
                    if (D_80115374 == NULL) {
                        D_80115374 = D_800733C8;
                        func_80057230(D_8013ED88, NULL, 1);
                    }
                }
                break;
            case 15:
            case 16:
                if ((u16)(D_800A7AFA % 1800) == 30) {
                    D_8006EDD8 &= ~0x70;
                    D_8006EDD8 &= ~0x10;
                    D_8006EDD8 |= 0x60A;
                    D_8006EDD8 &= ~4;
                    if (D_80115374 == NULL) {
                        D_80115374 = D_800733D8;
                        func_80057230(D_8013ED88, NULL, 1);
                    }
                } else if ((u16)(D_800A7AFA % 1800) == 600) {
                    D_8006EDD8 &= ~0x608;
                    D_8006EDD8 |= 4;
                    if (D_80115374 == NULL) {
                        D_80115374 = D_800733E8;
                        func_80057230(D_8013ED88, NULL, 1);
                    }
                }
                break;
            case 17:
            case 18:
                if ((u16)(D_800A7AFA % 1800) == 30) {
                    D_8006EDD8 &= ~0x70;
                    D_8006EDD8 &= ~0x10;
                    D_8006EDD8 |= 0x60A;
                    D_8006EDD8 &= ~4;
                    if (D_80115374 == NULL) {
                        D_80115374 = D_80073418;
                        func_80057230(D_8013ED88, NULL, 1);
                    }
                } else if ((u16)(D_800A7AFA % 1800) == 600) {
                    D_8006EDD8 &= ~0x608;
                    D_8006EDD8 |= 4;
                    if (D_80115374 == NULL) {
                        D_80115374 = D_80073428;
                        func_80057230(D_8013ED88, NULL, 1);
                    }
                }
                break;
            case 13:
            case 14:
                if ((u16)(D_800A7AFA % 1800) == 30) {
                    D_8006EDD8 &= ~0x70;
                    D_8006EDD8 &= ~0x10;
                    D_8006EDD8 |= 0x60A;
                    D_8006EDD8 &= ~4;
                    if (D_80115374 == NULL) {
                        D_80115374 = D_800733F8;
                        func_80057230(D_8013ED88, NULL, 1);
                    }
                } else if ((u16)(D_800A7AFA % 1800) == 600) {
                    D_8006EDD8 &= ~0x608;
                    D_8006EDD8 |= 4;
                    if (D_80115374 == NULL) {
                        D_80115374 = D_80073408;
                        func_80057230(D_8013ED88, NULL, 1);
                    }
                }
                break;
        }
        if (D_800A7AFA < 7198) {
            D_800A7AFA++;
        }
        if (D_8012EFD0 == 1 || D_8012EFD0 == 2) {
            if (D_800A7AFA >= 331 && (u16)(D_801078BA & 0xC00F)) {
                D_800A7AA8 = 0;
                D_800A8DDC = 0;
                D_801282A3 = 0;
                D_8012EFCC = 0;
                D_8006EDD8 |= 0x70;
                D_8006EDD8 &= ~0x60E;
                if (D_80115374 != NULL) {
                    D_8013C650 = D_80109C3E >> 3;
                    func_80057650(D_8012EF88);
                }
                return;
            }
        } else {
            if (D_800A7AFA >= 901 && D_80115374 == NULL && (u16)(D_801078BA & 0x1000)) {
                D_8012FCE0 = 2;
                D_800A7AA8 = 0;
                D_800A8DDC = 0;
                D_801282A3 = 0;
                D_8012EFCC = 0;
                D_801078F0 = 0;
                D_8006EDD8 |= 0x70;
                D_8006EDD8 &= ~0x60E;
                if (D_80115374 != NULL) {
                    D_8013C650 = D_80109C3E >> 3;
                    func_80057650(D_8012EF88);
                }
                func_80035828(o, 0x23);
                return;
            }
            if (D_800A7AFA >= 331 && D_80115374 == NULL && (u16)(D_801078BA & 0xC00F)) {
                D_800A8DDC = 0;
                D_801282A3 = 0;
                D_8012EFCC = 0;
                D_8006EDD8 |= 0x70;
                D_8006EDD8 &= ~0x60E;
                if (D_80115374 != NULL) {
                    D_8013C650 = D_80109C3E >> 3;
                    func_80057650(D_8012EF88);
                }
                return;
            }
        }
    } else {
        o->unk_224 = o->unk_224 + o->unk_226;
        if (o->unk_224 >= anim[4] << 4) {
            o->unk_0C = o->unk_0C | 8;
            if (o->unk_0C & 0x80) {
                o->unk_224 = anim[4] << 4;
            } else {
                o->unk_224 = 0;
            }
        }
        if (D_80109B8C >= 5) {
            if (D_80109B8C >= 8) {
                o->unk_0C = o->unk_0C | 1;
            }
            return;
        }
        o->unk_0C = o->unk_0C | 0x8000;
        if (D_80106888->unk_1C8 != 0x22 && D_80106888->unk_1C8 != 0x23 && D_800A7AA8 >= 3601 &&
            D_800ACC2D < 3 && D_80115374 == NULL) {
            switch (D_8012EFD0) {
                case 16:
                    func_80031744(D_80073520[func_80020EB4(4)], &D_80073AD0[D_8012EF80]);
                    break;
                case 15:
                    func_80031744(D_800734A0[func_80020EB4(4)], &D_80073860[D_8012EF80]);
                    break;
                case 13:
                    func_80031744(D_80073590[func_80020EB4(3)], &D_80073930[D_8012EF80]);
                    break;
                case 14:
                    func_80031744(D_8007360C[func_80020EB4(3)], &D_80073930[D_8012EF80]);
                    break;
                case 17:
                    func_80031744(D_80073650[func_80020EB4(2)], &D_80073A00[D_8012EF80]);
                    break;
                case 18:
                    func_80031744(D_80073690[func_80020EB4(2)], &D_80073A00[D_8012EF80]);
                    break;
            }
        }
        it = o;
        if (it->unk_18 != NULL) {
            while (it->unk_1C != 0) {
                it->unk_18(it, it->unk_1C);
                func_80047ED4(it);
            }
        }
        if (o->unk_EC != NULL) {
            o->unk_EC();
        }
        func_80035788(o);
        if (D_8012EFD0 != 11 && D_8012EFD0 != 19) {
            func_8004A294(D_80133E3C, &o->unk_24, &o->unk_30);
        }
        if (D_8012EFD0 != 11 && D_8012EFD0 != 19) {
            func_8004B470(D_80115380, a, b, c);
        }
    }
}
