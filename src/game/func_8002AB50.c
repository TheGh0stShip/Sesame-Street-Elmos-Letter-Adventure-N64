#include "common.h"
#include "game_structs.h"

extern u16 D_801078BA;

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
    anim = D_80075D00[o->u.model.animIndex.s];
    if (D_800ACC2E != 0) {
        ((void (*)(Sub40 *, Vec3f *, Vec3f))func_8001F1C8)(&o->u.model.unk_E8.l2.unk_F8[D_80070760], &o->pos, o->u.model.unk_54);
        if (D_8012EFD0 == 6 && o->u.model.unk_1EC != 0) {
            guRotateRPY(&m, 0, (f32)o->u.model.unk_1EC * 1.40625, 0);
            guMtxCatL(&m, &o->u.model.unk_E8.l2.unk_F8[D_80070760], &o->u.model.unk_E8.l2.unk_F8[D_80070760]);
        }
        ((void (*)(s32, u8 *, u8 *, u16, Vec3f, Vec3f *, Sub40 *, Actor *))func_8000092C)(o->u.model.unk_E8.l2.unk_F0, (*(u8 (*)[0x50])((u8 *)&o->u.model.unk_E8.l0.unk_E8 + 144)), anim, o->u.model.unk_224 >> 4, o->pos, &o->fwd, &o->u.model.unk_E8.l2.unk_F8[D_80070760], o);
        addActorDL(func_8002BADC, o, 4, 1, 0);
    } else if ((*(u8 (*))&D_8012EFCC) != 0) {
        if ((*(u8 (*))&D_8012EFCC) == 1) {
            func_8004CDC8(1, 0);
            if (D_80115374 != NULL) {
                D_8013C650 = D_80109C3E >> 3;
                osStopTimer(D_8012EF88);
            }
            (*(u8 (*))&D_8012EFCC) = 2;
        }
        if (D_8012EFD0 != 11 && D_8012EFD0 != 19) {
            func_8004A294(D_80133E3C, &o->pos, &o->fwd);
        }
        D_800A8DDC = 1;
        D_801282A3 = 0x80;
        switch (D_8012EFD0) {
            case 1:
            case 2:
                if ((u16)((*(u16 (*))&D_800A7AFA) % 1800) == 30) {
                    D_8006EDD8 &= ~0x70;
                    D_8006EDD8 |= 0x60A;
                    if (D_80115374 == NULL) {
                        D_80115374 = D_800733C8;
                        osSendMesg(D_8013ED88, NULL, 1);
                    }
                }
                break;
            case 15:
            case 16:
                if ((u16)((*(u16 (*))&D_800A7AFA) % 1800) == 30) {
                    D_8006EDD8 &= ~0x70;
                    D_8006EDD8 &= ~0x10;
                    D_8006EDD8 |= 0x60A;
                    D_8006EDD8 &= ~4;
                    if (D_80115374 == NULL) {
                        D_80115374 = D_800733D8;
                        osSendMesg(D_8013ED88, NULL, 1);
                    }
                } else if ((u16)((*(u16 (*))&D_800A7AFA) % 1800) == 600) {
                    D_8006EDD8 &= ~0x608;
                    D_8006EDD8 |= 4;
                    if (D_80115374 == NULL) {
                        D_80115374 = D_800733E8;
                        osSendMesg(D_8013ED88, NULL, 1);
                    }
                }
                break;
            case 17:
            case 18:
                if ((u16)((*(u16 (*))&D_800A7AFA) % 1800) == 30) {
                    D_8006EDD8 &= ~0x70;
                    D_8006EDD8 &= ~0x10;
                    D_8006EDD8 |= 0x60A;
                    D_8006EDD8 &= ~4;
                    if (D_80115374 == NULL) {
                        D_80115374 = D_80073418;
                        osSendMesg(D_8013ED88, NULL, 1);
                    }
                } else if ((u16)((*(u16 (*))&D_800A7AFA) % 1800) == 600) {
                    D_8006EDD8 &= ~0x608;
                    D_8006EDD8 |= 4;
                    if (D_80115374 == NULL) {
                        D_80115374 = D_80073428;
                        osSendMesg(D_8013ED88, NULL, 1);
                    }
                }
                break;
            case 13:
            case 14:
                if ((u16)((*(u16 (*))&D_800A7AFA) % 1800) == 30) {
                    D_8006EDD8 &= ~0x70;
                    D_8006EDD8 &= ~0x10;
                    D_8006EDD8 |= 0x60A;
                    D_8006EDD8 &= ~4;
                    if (D_80115374 == NULL) {
                        D_80115374 = D_800733F8;
                        osSendMesg(D_8013ED88, NULL, 1);
                    }
                } else if ((u16)((*(u16 (*))&D_800A7AFA) % 1800) == 600) {
                    D_8006EDD8 &= ~0x608;
                    D_8006EDD8 |= 4;
                    if (D_80115374 == NULL) {
                        D_80115374 = D_80073408;
                        osSendMesg(D_8013ED88, NULL, 1);
                    }
                }
                break;
        }
        if ((*(u16 (*))&D_800A7AFA) < 7198) {
            (*(u16 (*))&D_800A7AFA)++;
        }
        if (D_8012EFD0 == 1 || D_8012EFD0 == 2) {
            if ((*(u16 (*))&D_800A7AFA) >= 331 && (u16)(D_801078BA & 0xC00F)) {
                (*(u16 (*))&D_800A7AA8) = 0;
                D_800A8DDC = 0;
                D_801282A3 = 0;
                (*(u8 (*))&D_8012EFCC) = 0;
                D_8006EDD8 |= 0x70;
                D_8006EDD8 &= ~0x60E;
                if (D_80115374 != NULL) {
                    D_8013C650 = D_80109C3E >> 3;
                    osStopTimer(D_8012EF88);
                }
                return;
            }
        } else {
            if ((*(u16 (*))&D_800A7AFA) >= 901 && D_80115374 == NULL && (u16)(D_801078BA & 0x1000)) {
                D_8012FCE0 = 2;
                (*(u16 (*))&D_800A7AA8) = 0;
                D_800A8DDC = 0;
                D_801282A3 = 0;
                (*(u8 (*))&D_8012EFCC) = 0;
                D_801078F0 = 0;
                D_8006EDD8 |= 0x70;
                D_8006EDD8 &= ~0x60E;
                if (D_80115374 != NULL) {
                    D_8013C650 = D_80109C3E >> 3;
                    osStopTimer(D_8012EF88);
                }
                func_80035828(o, 0x23);
                return;
            }
            if ((*(u16 (*))&D_800A7AFA) >= 331 && D_80115374 == NULL && (u16)(D_801078BA & 0xC00F)) {
                D_800A8DDC = 0;
                D_801282A3 = 0;
                (*(u8 (*))&D_8012EFCC) = 0;
                D_8006EDD8 |= 0x70;
                D_8006EDD8 &= ~0x60E;
                if (D_80115374 != NULL) {
                    D_8013C650 = D_80109C3E >> 3;
                    osStopTimer(D_8012EF88);
                }
                return;
            }
        }
    } else {
        o->u.model.unk_224 = o->u.model.unk_224 + o->u.model.unk_226;
        if (o->u.model.unk_224 >= anim[4] << 4) {
            o->unk_C.l1.flags = o->unk_C.l1.flags | 8;
            if (o->unk_C.l1.flags & 0x80) {
                o->u.model.unk_224 = anim[4] << 4;
            } else {
                o->u.model.unk_224 = 0;
            }
        }
        if (D_80109B8C >= 5) {
            if (D_80109B8C >= 8) {
                o->unk_C.l1.flags = o->unk_C.l1.flags | 1;
            }
            return;
        }
        o->unk_C.l1.flags = o->unk_C.l1.flags | 0x8000;
        if ((*(Actor *(*))&D_80106888)->u.model.unk_1C8 != 0x22 && (*(Actor *(*))&D_80106888)->u.model.unk_1C8 != 0x23 && (*(u16 (*))&D_800A7AA8) >= 3601 &&
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
        if (it->unk_18.l1.unk_18 != NULL) {
            while (it->unk_18.l1.unk_1C != 0) {
                it->unk_18.l1.unk_18(it, it->unk_18.l1.unk_1C);
                func_80047ED4(it);
            }
        }
        if (o->u.model.unk_E8.l2.unk_EC != NULL) {
            o->u.model.unk_E8.l2.unk_EC();
        }
        func_80035788(o);
        if (D_8012EFD0 != 11 && D_8012EFD0 != 19) {
            func_8004A294(D_80133E3C, &o->pos, &o->fwd);
        }
        if (D_8012EFD0 != 11 && D_8012EFD0 != 19) {
            ((void (*)(s32, s32, s32, s32))func_8004B470)(D_80115380, a, b, c);
        }
    }
}
