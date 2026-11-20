#include "common.h"

typedef struct { f32 x, y, z; } Vec3;
typedef struct Actor {
    u8 pad00[0xC];
    u32 unk_0C;
    u8 pad10[0x14];
    Vec3 pos;
    f32 unk_30;
    f32 unk_34;
    f32 unk_38;
    f32 unk_3C;
    f32 unk_40;
    f32 unk_44;
    f32 unk_48;
    f32 unk_4C;
    f32 unk_50;
    f32 unk_54;
    u8 pad58[0xE8 - 0x58];
    Unk40 unk_E8[(0x1A8 - 0xE8) / 0x40];
    Unk1A8 unk_1A8;
    s32 unk_1B4;
    s32 unk_1B8;
    u8 *unk_1BC;
    u8 pad1C0[8];
    s32 unk_1C8;
    s32 unk_1CC;
    u8 pad1D0[4];
    union { u8 *p; u8 b[4]; } unk_1D4;
    u8 pad1D8[0x1E0 - 0x1D8];
    u8 unk_1E0;
    u8 pad1E1[7];
    Unk1E8 *unk_1E8;
    u8 pad1EC[8];
    Unk1F4 unk_1F4;
} Actor;

/* Per-frame update for a scripted cutscene/NPC actor: draws it, then steps a state machine (unk_1B4) that loads ROM segments and queues dialogue. */
void func_800272C8(Actor *arg0) {
    s32 sp28;
    f32 sp2C;
    Unk1F4 *sp30;
    register Actor *a;
    register f32 dx;
    register f32 dz;

    sp2C = 1.0f;
    a = arg0;
    a->unk_0C |= 0x8000;
    if (D_800ACC2E != 0) {
        if (a->unk_1E0 == 0) {
            if (a->unk_1B4 == 0x3E9 || a->unk_1B4 == 0x3EA) {
                guPosition(&a->unk_E8[D_80070760], -(a->unk_1B8 * 9),
                              func_80067FB0((*(Actor *(*))&D_80106888)->unk_30, (*(Actor *(*))&D_80106888)->unk_38) * 57.2957,
                              0, 1.0f, (*(Actor *(*))&D_80106888)->pos.x - (*(Actor *(*))&D_80106888)->unk_30 * 75.0f, 10.0f,
                              (*(Actor *(*))&D_80106888)->pos.z - (*(Actor *(*))&D_80106888)->unk_38 * 75.0f);
            } else {
                a->pos.y += D_8010E48C;
                ((void (*)(Unk40 *, Vec3 *, Unk1A8))func_8001F1C8)(&a->unk_E8[D_80070760], &a->pos, a->unk_1A8);
                a->pos.y -= D_8010E48C;
            }
            if (a->unk_1BC != NULL) {
                ((void (*)(Unk1E8 *, Unk1F4 *, u8 *, s32, Vec3, f32 *, Unk40 *, Actor *))func_8000092C)(a->unk_1E8, &a->unk_1F4, a->unk_1BC, a->unk_1CC, a->pos, &a->unk_30,
                              &a->unk_E8[D_80070760], a);
            } else {
                sp30 = &a->unk_1F4;
                sp30->unk_14 = &a->unk_E8[D_80070760];
                sp30->unk_0C = a->unk_1E8->unk_0C;
                sp30->unk_10 = a->unk_1E8->unk_08;
                sp30->unk_18 = a->unk_1E8->unk_1C;
                sp30->unk_20 = a->unk_1E8->unk_00;
            }
            addActorDL(D_80029D48, a, 4, 1, func_80022D8C(&a->pos));
        }
        return;
    }
    if ((*(u8 (*))&D_8012EFCC) != 0) {
        return;
    }
    if (a->unk_1E0 == 0 && a->unk_1BC != NULL && !(D_80106880 & 1)) {
        a->unk_1CC++;
        if (a->unk_1CC >= a->unk_1BC[4]) {
            a->unk_0C |= 8;
            if (a->unk_0C & 0x80) {
                a->unk_1CC = a->unk_1BC[4];
            } else {
                a->unk_1CC = 0;
            }
        }
    }
    if (D_80109B8C >= 5) {
        if (D_80109B8C >= 8) {
            a->unk_0C |= 1;
        }
        return;
    }
    switch (a->unk_1B4) {
    case 0x1:
        if (--a->unk_1B8 == 0) {
            a->unk_1B4 = 2;
            a->unk_1B8 = 0x3C;
        }
        break;
    case 0x2:
        a->unk_1B4 = 0;
        break;
    case 0x3:
        if (func_80012B60(&a->pos) == 0) {
            a->unk_0C |= 1;
            a->unk_1E0 = 1;
            D_8011537C = -1;
        }
        break;
    case 0xF:
        if (D_80106874 == 0) {
            D_80106874 = (s32)D_0061AFB0;
            D_800A75E0 = D_00620ED0 - D_0061AFB0;
            osSendMesg((*(u8 (*)[])&D_80140F78), 0, 1);
            a->unk_1B4 = 0x10;
        }
        break;
    case 0x10:
        if (D_80106874 == 0) {
            a->unk_1BC = D_801180A4;
            a->unk_0C &= ~0x80;
            a->unk_1CC = 0;
            a->unk_1B4 = 0x11;
        }
        break;
    case 0x11:
        if (a->unk_1D4.b[1] != 0) {
            a->unk_1D4.b[1]--;
        }
        D_800ACBF0 = a->pos.x - (*(Actor *(*))&D_80106888)->pos.x;
        D_801078B0 = a->pos.z - (*(Actor *(*))&D_80106888)->pos.z;
        if ((func_80029FB0(a, -231.0f, 67.0f, 75000.0f) != 0) && ((*(Actor *(*))&D_80106888)->unk_1C8 == 0) && (a->unk_1D4.b[1] == 0)) {
            D_80106874 = (s32)D_00633220;
            D_800A75E0 = D_00644970 - D_00633220;
            osSendMesg((*(u8 (*)[])&D_80140F78), 0, 1);
            a->unk_1B4 = 0x12;
            func_80047CF8(a, (*(Actor *(*))&D_80106888), 2, 0);
        }
        break;
    case 0x12:
        if ((*(Actor *(*))&D_80106888)->unk_1C8 != 0x24) {
            if (D_80106874 == 0) {
                func_80040680(D_801180A4);
                a->unk_1B4 = 0x11;
                a->unk_1D4.b[1] = 0x78;
            }
            break;
        }
        if ((D_80115374 == NULL) && ((*(Actor *(*))&D_80106888)->unk_1CC >= 0x15)) {
            D_80115374 = D_80073368;
            osSendMesg(D_8013ED88, 0, 1);
            func_80040680(a->unk_1BC);
            a->unk_1BC = D_801180A4;
            a->unk_0C |= 0x80;
            a->unk_0C &= ~8;
            a->unk_1CC = 0;
            a->unk_1B4 = 0x13;
            D_80106874 = (s32)D_0061AFB0;
            D_800A75E0 = D_00620ED0 - D_0061AFB0;
            osSendMesg((*(u8 (*)[])&D_80140F78), 0, 1);
        }
        break;
    case 0x13:
        if ((*(Actor *(*))&D_80106888)->unk_1C8 != 0x24) {
            if (D_80106874 == 0) {
                func_80040680(a->unk_1BC);
                a->unk_1BC = D_801180A4;
                a->unk_0C &= ~0x80;
                a->unk_1CC = 0;
                a->unk_1B4 = 0x11;
                a->unk_1D4.b[1] = 0x78;
            }
            break;
        }
        if (a->unk_0C & 8) {
            func_80040680(a->unk_1BC);
            a->unk_1BC = D_801180A4;
            a->unk_0C &= ~0x80;
            a->unk_1CC = 0;
            a->unk_1B4 = 0x14;
            D_80106874 = (s32)D_00644970;
            D_800A75E0 = D_00657E70 - D_00644970;
            osSendMesg((*(u8 (*)[])&D_80140F78), 0, 1);
        }
        break;
    case 0x14:
        if ((*(Actor *(*))&D_80106888)->unk_1C8 != 0x24) {
            if (D_80106874 == 0) {
                func_80040680(D_801180A4);
                a->unk_1B4 = 0x11;
                a->unk_1D4.b[1] = 0x78;
            }
            break;
        }
        if (D_80115374 == NULL) {
            D_80115374 = D_80073378;
            osSendMesg(D_8013ED88, 0, 1);
            a->unk_1B4 = 0x15;
        }
    case 0x15:
        if ((*(Actor *(*))&D_80106888)->unk_1C8 != 0x24) {
            if (D_80106874 == 0) {
                func_80040680(D_801180A4);
                a->unk_1B4 = 0x11;
                a->unk_1D4.b[1] = 0x78;
            }
            break;
        }
        if (D_80115374 == NULL) {
            D_8006EDD8 |= 0x60A;
            func_80040680(a->unk_1BC);
            a->unk_1BC = D_801180A4;
            a->unk_0C |= 0x80;
            a->unk_0C &= ~8;
            a->unk_1CC = 0;
            a->unk_1B4 = 0x16;
            D_80106874 = (s32)D_0061AFB0;
            D_800A75E0 = D_00620ED0 - D_0061AFB0;
            osSendMesg((*(u8 (*)[])&D_80140F78), 0, 1);
            D_80115374 = D_80073388;
            osSendMesg(D_8013ED88, 0, 1);
        }
        break;
    case 0x16:
        if ((*(Actor *(*))&D_80106888)->unk_1C8 != 0x24) {
            if (D_80106874 == 0) {
                D_8006EDD8 &= ~0x60A;
                func_80040680(a->unk_1BC);
                a->unk_1BC = D_801180A4;
                a->unk_0C &= ~0x80;
                a->unk_1CC = 0;
                a->unk_1B4 = 0x11;
                a->unk_1D4.b[1] = 0x78;
            }
            break;
        }
        if (a->unk_0C & 8) {
            func_80040680(a->unk_1BC);
            a->unk_1BC = D_801180A4;
            a->unk_0C &= ~0x80;
            a->unk_1CC = 0;
            a->unk_1B4 = 0x17;
        }
        break;
    case 0x17:
        if ((*(Actor *(*))&D_80106888)->unk_1C8 != 0x24) {
            D_8006EDD8 &= ~0x60A;
            a->unk_1B4 = 0x11;
        }
        break;
    case 0x18:
        if (D_80106874 == 0) {
            if (D_80115374 == NULL) {
                D_80115258 = &D_80073860[D_8012EF80];
                D_80115374 = D_80073698;
                osSendMesg(D_8013ED88, 0, 1);
            }
            a->unk_1BC = D_801180A4;
            a->unk_0C |= 0x80;
            a->unk_0C &= ~8;
            a->unk_1CC = 0;
            a->unk_1B4 = 0x19;
        }
        break;
    case 0x19:
        if (a->unk_0C & 8) {
            func_80040680(a->unk_1BC);
            a->unk_1BC = NULL;
            D_8011537C = 1;
            a->unk_54 = 50.0f;
            a->unk_1B4 = 3;
        }
        break;
    case 0x1A:
        if (D_80106874 == 0) {
            if (D_80115374 == NULL) {
                D_80115258 = &D_80073AD0[D_8012EF80];
                D_80115374 = D_800736B0;
                osSendMesg(D_8013ED88, 0, 1);
            }
            a->unk_1BC = D_801180A4;
            a->unk_0C |= 0x80;
            a->unk_0C &= ~8;
            a->unk_1CC = 0;
            a->unk_1B4 = 0x1B;
        }
        break;
    case 0x1B:
        if (a->unk_0C & 8) {
            func_80040680(a->unk_1BC);
            a->unk_1BC = NULL;
            D_8011537C = 1;
            a->unk_54 = 50.0f;
            a->unk_1B4 = 3;
        }
        break;
    case 0x1C:
        if (D_80106874 == 0) {
            D_80106874 = (s32)D_00620ED0;
            D_800A75E0 = D_00624460 - D_00620ED0;
            osSendMesg((*(u8 (*)[])&D_80140F78), 0, 1);
            a->unk_1B4 = 0x1D;
        }
        break;
    case 0x1D:
        if (D_80106874 == 0) {
            a->unk_1BC = D_801180A4;
            a->unk_0C &= ~0x80;
            a->unk_1CC = 0;
            a->unk_1B4 = 0x1E;
        }
        break;
    case 0x1E:
        if (D_801078E0->unk_10 == D_800310D0) {
            a->unk_1E0 = 0;
            a->unk_1B4 = 0;
            if (D_80109C3C == 0) {
                D_80106874 = (s32)D_00624460;
                D_800A75E0 = D_00633220 - D_00624460;
                osSendMesg((*(u8 (*)[])&D_80140F78), 0, 1);
                a->unk_1B4 = 0x1F;
            }
        }
        break;
    case 0x1F:
        if (D_80075E2C == 4) {
            a->unk_1D4.p = a->unk_1BC;
            a->unk_1BC = D_801180A4;
            a->unk_0C |= 0x80;
            a->unk_0C &= ~8;
            a->unk_1CC = 0;
            a->unk_1B4 = 0x20;
            D_80115374 = D_80074450;
            osSendMesg(D_8013ED88, 0, 1);
        }
        break;
    case 0x20:
        if (a->unk_0C & 8) {
            func_80017568(0x10);
            a->unk_1BC = a->unk_1D4.p;
            a->unk_0C &= ~0x80;
            a->unk_1CC = 0;
            a->unk_1B4 = 0;
            a->unk_1B4 = 0x4B;
            D_8006EDD8 |= 0x400000;
            a->unk_1D4.b[0] = 0x1E;
        }
        break;
    case 0x21:
        if (D_80106874 == 0) {
            D_80106874 = (s32)D_0073F930;
            D_800A75E0 = D_00741920 - D_0073F930;
            osSendMesg((*(u8 (*)[])&D_80140F78), 0, 1);
            a->unk_1B4 = 0x22;
        }
        break;
    case 0x22:
        if (D_80106874 == 0) {
            a->unk_1BC = D_801180A4;
            a->unk_0C &= ~0x80;
            a->unk_1CC = 0;
            a->unk_1B4 = 0x23;
        }
        break;
    case 0x23:
        if (a->unk_1D4.b[1] != 0) {
            a->unk_1D4.b[1]--;
        }
        D_80109B94 = a->pos.x - (*(Actor *(*))&D_80106888)->pos.x;
        D_8013C64C = a->pos.z - (*(Actor *(*))&D_80106888)->pos.z;
        if ((func_80029FB0(a, 6.0f, 266.0f, 20000.0f) != 0) && ((*(Actor *(*))&D_80106888)->unk_1C8 == 0) && (a->unk_1D4.b[1] == 0)) {
            D_80106874 = (s32)D_0070A5D0;
            D_800A75E0 = D_00718E00 - D_0070A5D0;
            osSendMesg((*(u8 (*)[])&D_80140F78), 0, 1);
            a->unk_1B4 = 0x24;
            func_80047CF8(a, (*(Actor *(*))&D_80106888), 3, 0);
        } else {
            dx = (*(Actor *(*))&D_80106888)->pos.x - a->pos.x;
            dz = (*(Actor *(*))&D_80106888)->pos.z - a->pos.z;
            dx = func_80067FB0(dz, dx);
            a->unk_30 = __cosf(dx);
            a->unk_38 = __sinf(dx);
            a->unk_48 = a->unk_34 * a->unk_44 - a->unk_38 * a->unk_40;
            a->unk_4C = a->unk_38 * a->unk_3C - a->unk_30 * a->unk_44;
            a->unk_50 = a->unk_30 * a->unk_40 - a->unk_34 * a->unk_3C;
        }
        break;
    case 0x24:
        if ((*(Actor *(*))&D_80106888)->unk_1C8 != 0x25) {
            if (D_80106874 == 0) {
                func_80040680(D_801180A4);
                a->unk_1B4 = 0x23;
                a->unk_1D4.b[1] = 0x78;
            }
            break;
        }
        if ((D_80115374 == NULL) && (D_80106874 == 0) && ((*(Actor *(*))&D_80106888)->unk_1CC >= 0x15)) {
            D_80115374 = D_80073398;
            osSendMesg(D_8013ED88, 0, 1);
            func_80040680(a->unk_1BC);
            a->unk_1BC = D_801180A4;
            a->unk_0C |= 0x80;
            a->unk_0C &= ~8;
            a->unk_1CC = 0;
            a->unk_1B4 = 0x25;
            D_80106874 = (s32)D_00718E00;
            D_800A75E0 = D_0071F230 - D_00718E00;
            osSendMesg((*(u8 (*)[])&D_80140F78), 0, 1);
        }
        break;
    case 0x25:
        if ((*(Actor *(*))&D_80106888)->unk_1C8 != 0x25) {
            if (D_80106874 == 0) {
                func_80040680(D_801180A4);
                a->unk_1B4 = 0x21;
                a->unk_1D4.b[1] = 0x78;
            }
            break;
        }
        if (a->unk_0C & 8) {
            func_80040680(a->unk_1BC);
            a->unk_1BC = D_801180A4;
            a->unk_0C &= ~8;
            a->unk_1CC = 0;
            a->unk_1B4 = 0x26;
            D_80106874 = (s32)D_0073F930;
            D_800A75E0 = D_00741920 - D_0073F930;
            osSendMesg((*(u8 (*)[])&D_80140F78), 0, 1);
        }
        break;
    case 0x26:
        if ((*(Actor *(*))&D_80106888)->unk_1C8 != 0x25) {
            if (D_80106874 == 0) {
                func_80040680(D_801180A4);
                a->unk_1B4 = 0x21;
                a->unk_1D4.b[1] = 0x78;
            }
            break;
        }
        if (a->unk_0C & 8) {
            func_80040680(a->unk_1BC);
            a->unk_1BC = D_801180A4;
            a->unk_0C &= ~8;
            a->unk_0C &= ~0x80;
            a->unk_1CC = 0;
            a->unk_1B4 = 0x27;
        }
        break;
    case 0x27:
        if ((*(Actor *(*))&D_80106888)->unk_1C8 != 0x25) {
            if (D_80106874 == 0) {
                func_80040680(D_801180A4);
                a->unk_0C &= ~0x80;
                a->unk_1B4 = 0x23;
                a->unk_1D4.b[1] = 0x78;
            }
            break;
        }
        if (D_80115374 == NULL) {
            D_80115374 = D_800733A8;
            osSendMesg(D_8013ED88, 0, 1);
            a->unk_1B4 = 0x28;
        }
        break;
    case 0x28:
        if ((*(Actor *(*))&D_80106888)->unk_1C8 != 0x25) {
            if (D_80106874 == 0) {
                func_80040680(D_801180A4);
                a->unk_1B4 = 0x23;
                a->unk_1D4.b[1] = 0x78;
            }
            break;
        }
        if (D_80115374 == NULL) {
            D_80115374 = D_800733B8;
            a->unk_0C |= 0x80;
            a->unk_0C &= ~8;
            a->unk_1CC = 0;
            a->unk_1B4 = 0x29;
            D_80106874 = (s32)D_0071F230;
            D_800A75E0 = D_007307E0 - D_0071F230;
            osSendMesg((*(u8 (*)[])&D_80140F78), 0, 1);
        }
        break;
    case 0x29:
        if ((*(Actor *(*))&D_80106888)->unk_1C8 != 0x25) {
            if (D_80106874 == 0) {
                func_80040680(D_801180A4);
                a->unk_1B4 = 0x21;
                a->unk_1D4.b[1] = 0x78;
            }
            break;
        }
        if (a->unk_0C & 8) {
            D_8006EDD8 |= 0x60A;
            func_80040680(a->unk_1BC);
            a->unk_1BC = D_801180A4;
            a->unk_0C &= ~8;
            a->unk_1CC = 0;
            a->unk_1B4 = 0x2A;
            D_80106874 = (s32)D_0073F930;
            D_800A75E0 = D_00741920 - D_0073F930;
            osSendMesg((*(u8 (*)[])&D_80140F78), 0, 1);
            osSendMesg(D_8013ED88, 0, 1);
        }
        break;
    case 0x2A:
        if ((*(Actor *(*))&D_80106888)->unk_1C8 != 0x25) {
            if (D_80106874 == 0) {
                D_8006EDD8 &= ~0x60A;
                func_80040680(a->unk_1BC);
                a->unk_1BC = D_801180A4;
                a->unk_0C &= ~0x80;
                a->unk_1CC = 0;
                a->unk_1B4 = 0x23;
                a->unk_1D4.b[1] = 0x78;
            }
            break;
        }
        if (a->unk_0C & 8) {
            func_80040680(a->unk_1BC);
            a->unk_1BC = D_801180A4;
            a->unk_0C &= ~0x80;
            a->unk_1CC = 0;
            a->unk_1B4 = 0x2B;
        }
        break;
    case 0x2B:
        if ((*(Actor *(*))&D_80106888)->unk_1C8 != 0x25) {
            D_8006EDD8 &= ~0x60A;
            a->unk_1B4 = 0x23;
        }
        break;
    case 0x2C:
        if (D_80106874 == 0) {
            if (D_80115374 == NULL) {
                D_80115258 = &D_80073BA0[D_8012EF80];
                D_80115374 = D_800736F0;
                osSendMesg(D_8013ED88, 0, 1);
            }
            a->unk_1BC = D_801180A4;
            a->unk_0C |= 0x80;
            a->unk_0C &= ~8;
            a->unk_1CC = 0;
            a->unk_1B4 = 0x2E;
        }
        break;
    case 0x2D:
        if (a->unk_0C & 8) {
            func_80040680(a->unk_1BC);
            a->unk_1BC = D_801180A4;
            a->unk_0C &= ~8;
            a->unk_1CC = 0;
            a->unk_1B4 = 0x2E;
        }
        break;
    case 0x2E:
        if (a->unk_0C & 8) {
            func_80040680(a->unk_1BC);
            a->unk_1BC = NULL;
            D_8011537C = 1;
            a->unk_54 = 50.0f;
            a->unk_1B4 = 3;
        }
        break;
    case 0x2F:
        if (D_80106874 == 0) {
            if (D_80115374 == NULL) {
                D_80115258 = &D_80073BA0[D_8012EF80];
                D_80115374 = D_800736D0;
                osSendMesg(D_8013ED88, 0, 1);
            }
            a->unk_1BC = D_801180A4;
            a->unk_0C |= 0x80;
            a->unk_0C &= ~8;
            a->unk_1CC = 0;
            D_80106874 = (s32)D_006F19C0;
            D_800A75E0 = D_006F9020 - D_006F19C0;
            osSendMesg((*(u8 (*)[])&D_80140F78), 0, 1);
            a->unk_1B4 = 0x30;
        }
        break;
    case 0x30:
        if (a->unk_0C & 8) {
            func_80040680(a->unk_1BC);
            a->unk_1BC = D_801180A4;
            a->unk_0C &= ~8;
            a->unk_1CC = 0;
            a->unk_1B4 = 0x31;
        }
        break;
    case 0x31:
        if (a->unk_0C & 8) {
            func_80040680(a->unk_1BC);
            a->unk_1BC = NULL;
            D_8011537C = 1;
            a->unk_54 = 50.0f;
            a->unk_1B4 = 3;
        }
        break;
    case 0x32:
        if (D_80106874 == 0) {
            D_80106874 = (s32)D_0073CBA0;
            D_800A75E0 = D_0073F930 - D_0073CBA0;
            osSendMesg((*(u8 (*)[])&D_80140F78), 0, 1);
            a->unk_1B4 = 0x33;
        }
        break;
    case 0x33:
        if (D_80106874 == 0) {
            a->unk_1BC = D_801180A4;
            a->unk_0C &= ~0x80;
            a->unk_1CC = 0;
            a->unk_1B4 = 0x34;
        }
        break;
    case 0x34:
        if (D_801078E0->unk_10 == D_800310D0) {
            a->unk_1E0 = 0;
            a->unk_1B4 = 0;
            if (D_80109C3C == 1) {
                D_80106874 = (s32)D_007307E0;
                D_800A75E0 = D_0073CBA0 - D_007307E0;
                osSendMesg((*(u8 (*)[])&D_80140F78), 0, 1);
                a->unk_1B4 = 0x35;
            }
        }
        break;
    case 0x35:
        if (D_80075E2C == 4) {
            a->unk_1D4.p = a->unk_1BC;
            a->unk_1BC = D_801180A4;
            a->unk_0C |= 0x80;
            a->unk_0C &= ~8;
            a->unk_1CC = 0;
            a->unk_1B4 = 0x36;
            D_80115374 = D_80074460;
            osSendMesg(D_8013ED88, 0, 1);
        }
        break;
    case 0x36:
        if (a->unk_0C & 8) {
            func_80017568(0x10);
            a->unk_1BC = a->unk_1D4.p;
            a->unk_0C &= ~0x80;
            a->unk_1CC = 0;
            a->unk_1B4 = 0;
            a->unk_1B4 = 0x4B;
            D_8006EDD8 |= 0x100000;
            a->unk_1D4.b[0] = 0x1E;
        }
        break;
    case 0x37:
        if (D_80106874 == 0) {
            D_80106874 = (s32)D_006A0760;
            D_800A75E0 = D_006A2D50 - D_006A0760;
            osSendMesg((*(u8 (*)[])&D_80140F78), 0, 1);
            a->unk_1B4 = 0x38;
        }
        break;
    case 0x38:
        if (D_80106874 == 0) {
            a->unk_1BC = D_801180A4;
            a->unk_0C &= ~0x80;
            a->unk_1CC = 0;
            a->unk_1B4 = 0x39;
        }
        break;
    case 0x39:
        if (a->unk_1D4.b[1] != 0) {
            a->unk_1D4.b[1]--;
        }
        D_800A8CC8 = a->pos.x - (*(Actor *(*))&D_80106888)->pos.x;
        D_80133D6C = a->pos.z - (*(Actor *(*))&D_80106888)->pos.z;
        if ((func_80029FB0(a, -95.0f, 175.0f, 50000.0f) != 0) && ((*(Actor *(*))&D_80106888)->unk_1C8 == 0) && (a->unk_1D4.b[1] == 0)) {
            D_80106874 = (s32)D_0067BEE0;
            D_800A75E0 = D_0068B260 - D_0067BEE0;
            osSendMesg((*(u8 (*)[])&D_80140F78), 0, 1);
            a->unk_1B4 = 0x3A;
            func_80047CF8(a, (*(Actor *(*))&D_80106888), 4, 0);
        } else {
            dx = (*(Actor *(*))&D_80106888)->pos.x - a->pos.x;
            dz = (*(Actor *(*))&D_80106888)->pos.z - a->pos.z;
            dx = func_80067FB0(dz, dx);
            a->unk_30 = __cosf(dx);
            a->unk_38 = __sinf(dx);
            a->unk_48 = a->unk_34 * a->unk_44 - a->unk_38 * a->unk_40;
            a->unk_4C = a->unk_38 * a->unk_3C - a->unk_30 * a->unk_44;
            a->unk_50 = a->unk_30 * a->unk_40 - a->unk_34 * a->unk_3C;
        }
        break;
    case 0x3A:
        if ((*(Actor *(*))&D_80106888)->unk_1C8 != 0x26) {
            if (D_80106874 == 0) {
                func_80040680(D_801180A4);
                a->unk_1B4 = 0x39;
                a->unk_1D4.b[1] = 0x78;
            }
            break;
        }
        if ((D_80115374 == NULL) && ((*(Actor *(*))&D_80106888)->unk_1CC >= 0x15)) {
            D_80115374 = D_80073338;
            osSendMesg(D_8013ED88, 0, 1);
            func_80040680(a->unk_1BC);
            a->unk_1BC = D_801180A4;
            a->unk_0C |= 0x80;
            a->unk_0C &= ~8;
            a->unk_1CC = 0;
            a->unk_1B4 = 0x3B;
            D_80106874 = (s32)D_006A0760;
            D_800A75E0 = D_006A2D50 - D_006A0760;
            osSendMesg((*(u8 (*)[])&D_80140F78), 0, 1);
        }
        break;
    case 0x3B:
        if ((*(Actor *(*))&D_80106888)->unk_1C8 != 0x26) {
            if (D_80106874 == 0) {
                func_80040680(a->unk_1BC);
                a->unk_1BC = D_801180A4;
                a->unk_0C &= ~0x80;
                a->unk_1CC = 0;
                a->unk_1B4 = 0x39;
                a->unk_1D4.b[1] = 0x78;
            }
            break;
        }
        if (a->unk_0C & 8) {
            func_80040680(a->unk_1BC);
            a->unk_1BC = D_801180A4;
            a->unk_0C &= ~0x80;
            a->unk_1CC = 0;
            a->unk_1B4 = 0x3C;
            D_80106874 = (s32)D_0068B260;
            D_800A75E0 = D_00698AE0 - D_0068B260;
            osSendMesg((*(u8 (*)[])&D_80140F78), 0, 1);
        }
        break;
    case 0x3C:
        if ((*(Actor *(*))&D_80106888)->unk_1C8 != 0x26) {
            if (D_80106874 == 0) {
                func_80040680(D_801180A4);
                a->unk_1B4 = 0x39;
                a->unk_1D4.b[1] = 0x78;
            }
            break;
        }
        if (D_80115374 == NULL) {
            D_80115374 = D_80073348;
            osSendMesg(D_8013ED88, 0, 1);
            a->unk_1B4 = 0x3D;
        }
    case 0x3D:
        if ((*(Actor *(*))&D_80106888)->unk_1C8 != 0x26) {
            if (D_80106874 == 0) {
                func_80040680(D_801180A4);
                a->unk_1B4 = 0x39;
                a->unk_1D4.b[1] = 0x78;
            }
            break;
        }
        if (D_80115374 == NULL) {
            D_8006EDD8 |= 0x60A;
            func_80040680(a->unk_1BC);
            a->unk_1BC = D_801180A4;
            a->unk_0C |= 0x80;
            a->unk_0C &= ~8;
            a->unk_1CC = 0;
            a->unk_1B4 = 0x3E;
            D_80106874 = (s32)D_006A0760;
            D_800A75E0 = D_006A2D50 - D_006A0760;
            osSendMesg((*(u8 (*)[])&D_80140F78), 0, 1);
            D_80115374 = D_80073358;
            osSendMesg(D_8013ED88, 0, 1);
        }
        break;
    case 0x3E:
        if ((*(Actor *(*))&D_80106888)->unk_1C8 != 0x26) {
            if (D_80106874 == 0) {
                D_8006EDD8 &= ~0x60A;
                func_80040680(a->unk_1BC);
                a->unk_1BC = D_801180A4;
                a->unk_0C &= ~0x80;
                a->unk_1CC = 0;
                a->unk_1B4 = 0x39;
                a->unk_1D4.b[1] = 0x78;
            }
            break;
        }
        if (a->unk_0C & 8) {
            func_80040680(a->unk_1BC);
            a->unk_1BC = D_801180A4;
            a->unk_0C &= ~0x80;
            a->unk_1CC = 0;
            a->unk_1B4 = 0x3F;
        }
        break;
    case 0x3F:
        if ((*(Actor *(*))&D_80106888)->unk_1C8 != 0x26) {
            D_8006EDD8 &= ~0x60A;
            a->unk_1B4 = 0x39;
        }
        break;
    case 0x40:
        if (D_80106874 == 0) {
            if (D_80115374 == NULL) {
                D_80115258 = &D_80073A00[D_8012EF80];
                D_80115374 = D_800737F8;
                osSendMesg(D_8013ED88, 0, 1);
            }
            a->unk_1BC = D_801180A4;
            a->unk_0C |= 0x80;
            a->unk_0C &= ~8;
            a->unk_1CC = 0;
            D_80106874 = (s32)D_006B4150;
            D_800A75E0 = D_006C4A80 - D_006B4150;
            osSendMesg((*(u8 (*)[])&D_80140F78), 0, 1);
            a->unk_1B4 = 0x41;
        }
        break;
    case 0x41:
        if (a->unk_0C & 8) {
            func_80040680(a->unk_1BC);
            a->unk_1BC = D_801180A4;
            a->unk_0C &= ~8;
            a->unk_1CC = 0;
            a->unk_1B4 = 0x42;
        }
        break;
    case 0x42:
        if (a->unk_0C & 8) {
            func_80040680(a->unk_1BC);
            a->unk_1BC = NULL;
            D_8011537C = 1;
            a->unk_54 = 50.0f;
            a->unk_1B4 = 3;
        }
        break;
    case 0x43:
        if (D_80106874 == 0) {
            if (D_80115374 == NULL) {
                D_80115258 = &D_80073A00[D_8012EF80];
                D_80115374 = D_80073830;
                osSendMesg(D_8013ED88, 0, 1);
            }
            a->unk_1BC = D_801180A4;
            a->unk_0C |= 0x80;
            a->unk_0C &= ~8;
            a->unk_1CC = 0;
            D_80106874 = (s32)D_006D5E80;
            D_800A75E0 = D_006E3190 - D_006D5E80;
            osSendMesg((*(u8 (*)[])&D_80140F78), 0, 1);
            a->unk_1B4 = 0x44;
        }
        break;
    case 0x44:
        if (a->unk_0C & 8) {
            func_80040680(a->unk_1BC);
            a->unk_1BC = D_801180A4;
            a->unk_0C &= ~8;
            a->unk_1CC = 0;
            a->unk_1B4 = 0x45;
        }
        break;
    case 0x45:
        if (a->unk_0C & 8) {
            func_80040680(a->unk_1BC);
            a->unk_1BC = NULL;
            D_8011537C = 1;
            a->unk_54 = 50.0f;
            a->unk_1B4 = 3;
        }
        break;
    case 0x46:
        if (D_80106874 == 0) {
            D_80106874 = (s32)D_006A0760;
            D_800A75E0 = D_006A2D50 - D_006A0760;
            osSendMesg((*(u8 (*)[])&D_80140F78), 0, 1);
            a->unk_1B4 = 0x47;
        }
        break;
    case 0x47:
        if (D_80106874 == 0) {
            a->unk_1BC = D_801180A4;
            a->unk_0C &= ~0x80;
            a->unk_1CC = 0;
            a->unk_1B4 = 0x48;
        }
        break;
    case 0x48:
        if (D_801078E0->unk_10 == D_800310D0) {
            a->unk_1E0 = 0;
            a->unk_1B4 = 0;
            if (D_80109C3C == 2) {
                D_80106874 = (s32)D_00698AE0;
                D_800A75E0 = D_006A0760 - D_00698AE0;
                osSendMesg((*(u8 (*)[])&D_80140F78), 0, 1);
                a->unk_1B4 = 0x49;
            }
        }
        break;
    case 0x49:
        if (D_80075E2C == 4) {
            a->unk_1D4.p = a->unk_1BC;
            a->unk_1BC = D_801180A4;
            a->unk_0C |= 0x80;
            a->unk_0C &= ~8;
            a->unk_1CC = 0;
            a->unk_1B4 = 0x4A;
            D_80115374 = D_80074470;
            osSendMesg(D_8013ED88, 0, 1);
        }
        break;
    case 0x4A:
        if (a->unk_0C & 8) {
            func_80017568(0x10);
            a->unk_1BC = a->unk_1D4.p;
            a->unk_0C &= ~0x80;
            a->unk_1CC = 0;
            a->unk_1B4 = 0;
            a->unk_1B4 = 0x4B;
            D_8006EDD8 |= 0x200000;
            a->unk_1D4.b[0] = 0x1E;
        }
        break;
    case 0x4B:
        if (--a->unk_1D4.b[0] == 0) {
            D_8006EDE1 = 0;
            D_800745F8 = 0;
            D_80075E30 = 0;
            a->unk_1B4 = 0;
            if ((D_8006EDD8 & 0x200000) && (D_8006EDD8 & 0x100000) && (D_8006EDD8 & 0x400000) && D_80075E2C == 4 && D_80075C30 == 0) {
                D_801078E0->unk_54 = 0x80;
                D_801078E0->unk_48 = (-550.0 - D_801078E0->unk_30) * 0.0078125;
                D_801078E0->unk_4C = (280.0 - D_801078E0->unk_34) * 0.0078125;
                D_801078E0->unk_50 = (1000.0 - D_801078E0->unk_38) * 0.0078125;
                D_801078E0->unk_10 = D_80031274;
                a->unk_1B4 = 0x4C;
                D_8006EDD8 &= ~0x100;
                D_80075C30 = 1;
            } else {
                func_80035828((*(Actor *(*))&D_80106888), 0x22);
            }
        }
        break;
    case 0x4C:
        if (D_80075E2C == 6) {
            func_80035828((*(Actor *(*))&D_80106888), 0x22);
            D_80075E2C = 0;
            a->unk_1B4 = 0x4D;
        }
        break;
    case 0x4D:
        if (D_800761E0 == 1) {
            a->unk_0C |= 1;
            a->unk_1B4 = 0;
        }
        break;
    }
}
