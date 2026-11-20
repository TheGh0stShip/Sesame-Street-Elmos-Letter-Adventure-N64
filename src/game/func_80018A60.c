#include "common.h"

extern u16 D_801078BA;

/* Title / attract-mode state machine: fades, menu selection and level start setup. */
void func_80018A60(void *arg) {
    GameState *s;
    f64 unused;
    register f32 sx;
    register f32 sy;

    s = arg;
    if (D_800ACC2E == 0) {
        return;
    }
    s->unk_24++;
    switch (s->unk_28) {
    case 12:
        if (s->unk_24 >= s->unk_2C) {
            func_800409A0();
            func_800409C8(D_802FD600, D_80000318 - (s32)D_002FD600);
            func_80047C00(0x32);
            s->unk_24 = 0;
            D_80109B8C = 0;
            s->unk_28 = 10;
            D_80108B24 = 1;
            D_8012EFD0 = D_8012FCE0;
        }
        break;
    case 18:
        D_801282A3 = 0xFF;
        s->unk_28 = 19;
        D_80108B24 = 1;
        break;
    case 0:
        if (s->unk_24 >= s->unk_2C) {
            if (!(D_8006D500 & 1)) {
                D_80109C78 = 1;
            } else {
                func_8001892C(D_004D9D80, D_004DB3E0, 0x46, 0x14);
                func_8001D9D0(0x15);
                s->unk_24 = 0;
                s->unk_28 = 1;
                D_801282A3 = 0;
                D_80109B8C = 0;
                D_8012EFD0 = 0x15;
            }
        }
        break;
    case 1:
        if (D_800745E4 == 0) {
            if (s->unk_24 >= 330) {
                s->unk_28 = 19;
                s->unk_24 = 0;
            }
        } else if (D_800745E4 == 4) {
            if (D_801078BA & 0x1000) {
                s->unk_28 = 19;
                s->unk_24 = 0;
            }
        } else if (s->unk_24 >= 330 || (D_801078BA & 0x1000)) {
            s->unk_28 = 19;
            s->unk_24 = 0;
        }
        break;
    case 4:
        if (s->unk_24 >= s->unk_2C) {
            func_8004CF14(D_800A7AFC, 0);
            func_8001D9D0(0x16);
            s->unk_24 = 0;
            D_800A7AA0 = 0;
            D_80108DB0 = 0;
            D_8006DDEC = 0;
            D_801282A3 = 0xFF;
            osViBlack(0);
            D_8012EFD0 = 0x16;
            s->unk_28 = 17;
            D_800A8DDC = 0;
            D_8006EDD8 |= 1;
            D_8006EDD8 |= 0x10;
            D_8006EDD8 |= 0x20;
            D_8006EDD8 |= 0x40;
        }
        break;
    case 14:
        func_8001A12C();
        sx = D_801078BC;
        sy = D_801078BD;
        D_800745EC++;
        if (D_800745ED == 0) {
            if ((D_801078BA & 0x100) || (sx > 8.0f && D_800745EC >= 16)) {
                func_8004CC30(8);
                D_800745ED = 1;
                D_800745E0++;
                D_800745EC = 0;
                if (D_800745E0 >= 3) {
                    D_800745E0 = 2;
                }
            }
            if ((D_801078BA & 0x200) || (sx < -8.0f && D_800745EC >= 16)) {
                func_8004CC30(8);
                D_800745ED = 1;
                D_800745E0--;
                D_800745EC = 0;
                if (D_800745E0 < 0) {
                    D_800745E0 = 0;
                }
            }
        }
        switch (D_800745E0) {
        case 0:
            D_80106870 = 0;
            D_800A75E8 = 6;
            D_8010E488 = 12;
            break;
        case 1:
            D_80106870 = 1;
            D_800A75E8 = 4;
            D_8010E488 = 16;
            break;
        case 2:
            D_80106870 = 2;
            D_800A75E8 = 2;
            D_8010E488 = 20;
            break;
        default:
            D_80106870 = 0;
            D_800A75E8 = 6;
            D_8010E488 = 12;
            break;
        }
        if (((D_801078BA & 0x8000) && D_80115374 == 0) || (s->unk_24 >= 800 && D_80115374 == 0)) {
            s->unk_28 = 16;
            s->unk_24 = 0;
        }
        break;
    case 16:
        if ((D_801282A3 += 0x10) < 0x10) {
            D_801282A3 = 0xFF;
            osViBlack(1);
            func_8004CF14(D_800A7AFC, 0);
            func_800409A0();
            func_800409C8(D_802FD600, D_80000318 - (s32)D_002FD600);
            func_80047C00(0x32);
            s->unk_24 = 0;
            D_80109B8C = 0;
            s->unk_28 = 10;
            D_8012EFD0 = 2;
        }
        break;
    case 10:
        D_80109C40 = 1;
        if (D_800ACC2C != 0) {
            break;
        }
        if (s->unk_24 >= 6) {
            s->unk_28 = 13;
            func_8001D9D0(D_8012EFD0);
            D_800A8DDC = 0;
            D_80115268 = D_80074580[D_8012EFD0] * 0.375;
            D_8013EB30 = D_80115268 * 1.3333334f;
            D_80109C48 = 0;
            D_80106888 = 0;
            D_80075C20 = 0;
            D_8012EFCC = 0;
            D_801078F0 = 1;
            D_800A7604 = 0;
            D_800A7AA8 = 0;
            D_800ACC2D = 0;
            D_80109C70 = 0;
            func_80012998();
            if (D_8012EFD0 == 1 || D_8012EFD0 == 2 || D_8012EFD0 == 11 || D_8012EFD0 == 19) {
                D_8006EDE0 = 0;
                func_80003F60();
            }
            D_800A7AFC = 0;
            D_8010E48C = 0;
            D_80115370 = 0;
            switch (D_8012EFD0) {
            case 2:
                switch (D_800745E0) {
                case 0:
                    D_80106870 = 0;
                    D_800A75E8 = 6;
                    D_8010E488 = 12;
                    break;
                case 1:
                    D_80106870 = 1;
                    D_800A75E8 = 4;
                    D_8010E488 = 16;
                    break;
                case 2:
                    D_80106870 = 2;
                    D_800A75E8 = 2;
                    D_8010E488 = 20;
                    break;
                default:
                    D_80106870 = 0;
                    D_800A75E8 = 6;
                    D_8010E488 = 12;
                    break;
                }
                D_800A7608 = 0;
                D_800ACBA0 = 0;
                D_80109C3C = -1;
                D_8012EFD4 = 0;
                (*(u8 (*))&D_800745F7) = 0;
                D_80108B20 = -1;
                D_800A7AA0 = 0;
                func_8001F300(&D_801A9F5C);
                D_80108DB0 = 1;
                D_8006DDEC = 0;
                D_80107910 = 0x4A534A53;
                D_8006EDD8 &= ~1;
                D_8006EDD8 &= ~0x100;
                D_8006EDD8 &= ~2;
                D_8006EDD8 &= ~0x10;
                D_8006EDD8 &= ~0x20;
                D_8006EDD8 &= ~0x40;
                break;
            case 16:
                D_8012EFD4 = 0x19E10;
                func_8001892C(D_00501820, D_00507070, 0x4B, 0x14);
                if (D_80108B20 == -1) {
                    func_800317C0(&D_80079C60, 0);
                }
                D_800A7AA0 = func_80031BB4(0x1E, D_800745DC[D_800745E0], 0, D_80108B20);
                func_8001F300(&D_801934D4);
                D_80108DB0 = 0;
                D_8006DDEC = 0;
                D_80107910 = 0x01FD01FD;
                D_8006EDD8 |= 1;
                D_8006EDD8 &= ~0x100;
                D_8006EDD8 &= ~2;
                D_8006EDD8 |= 0x10;
                D_8006EDD8 |= 0x20;
                D_8006EDD8 |= 0x40;
                break;
            case 15:
                D_8012EFD4 = 0x17ED0;
                func_8001892C(D_004FAC20, D_00501130, 0x4B, 0x14);
                if (D_80108B20 == -1) {
                    func_800317C0(&D_80079C60, 0);
                }
                D_800A7AA0 = func_80031BB4(0x1E, D_800745DC[D_800745E0], 0, D_80108B20);
                func_8001F300(&D_8019411C);
                D_80108DB0 = 0;
                D_8006DDEC = 0;
                D_80107910 = 0x4A7D4A7D;
                D_8006EDD8 |= 1;
                D_8006EDD8 &= ~0x100;
                D_8006EDD8 &= ~2;
                D_8006EDD8 |= 0x10;
                D_8006EDD8 |= 0x20;
                D_8006EDD8 |= 0x40;
                break;
            case 18:
                D_8012EFD4 = 0;
                func_8001892C(D_004EADF0, D_004F1850, 0x4B, 0x14);
                if (D_80108B20 == -1) {
                    func_800317C0(&D_80079C6C, 1);
                }
                D_800A7AA0 = func_80031BB4(0x1E, D_800745DC[D_800745E0], 0, D_80108B20);
                func_8001F300(&D_8019906C);
                D_80108DB0 = 1;
                D_8006DDEC = 0;
                D_80107910 = 0x4A534A53;
                D_8006EDD8 |= 1;
                D_8006EDD8 &= ~0x100;
                D_8006EDD8 &= ~2;
                D_8006EDD8 |= 0x10;
                D_8006EDD8 |= 0x20;
                D_8006EDD8 |= 0x40;
                break;
            case 17:
                D_8012EFD4 = 0;
                func_8001892C(D_004F2030, D_004FA460, 0x4B, 0x14);
                if (D_80108B20 == -1) {
                    func_800317C0(&D_80079C6C, 1);
                }
                D_800A7AA0 = func_80031BB4(0x1E, D_800745DC[D_800745E0], 0, D_80108B20);
                func_8001F300(&D_801AC70C);
                D_80108DB0 = 1;
                D_8006DDEC = 0;
                D_80107910 = 0x03010301;
                D_8006EDD8 |= 1;
                D_8006EDD8 &= ~0x100;
                D_8006EDD8 &= ~2;
                D_8006EDD8 |= 0x10;
                D_8006EDD8 |= 0x20;
                D_8006EDD8 |= 0x40;
                break;
            case 14:
                D_8012EFD4 = 0x2C6F0;
                func_8001892C(D_00507890, D_0050C970, 0x40, 0x14);
                if (D_80108B20 == -1) {
                    func_800317C0(&D_80079C78, 2);
                }
                D_800A7AA0 = func_80031BB4(0x1E, D_800745DC[D_800745E0], 0, D_80108B20);
                func_8001F300(&D_8018FD80);
                D_80108DB0 = 0;
                D_8006DDEC = 0;
                D_80107910 = 0x10001;
                D_8006EDD8 |= 1;
                D_8006EDD8 &= ~0x100;
                D_8006EDD8 &= ~2;
                D_8006EDD8 |= 0x10;
                D_8006EDD8 |= 0x20;
                D_8006EDD8 |= 0x40;
                break;
            case 13:
                D_8012EFD4 = 0x17700;
                func_8001892C(D_00507890, D_0050C970, 0x40, 0x14);
                if (D_80108B20 == -1) {
                    func_800317C0(&D_80079C78, 2);
                }
                D_800A7AA0 = func_80031BB4(0x1E, D_800745DC[D_800745E0], 0, D_80108B20);
                func_8001F300(&D_801A87FC);
                D_80108DB0 = 0;
                D_8006DDEC = 0;
                D_80107910 = 0x10001;
                D_8006EDD8 |= 1;
                D_8006EDD8 &= ~0x100;
                D_8006EDD8 &= ~2;
                D_8006EDD8 |= 0x10;
                D_8006EDD8 |= 0x20;
                D_8006EDD8 |= 0x40;
                break;
            case 19:
                D_800A7608 = 0;
                D_8006EDE2 = 0;
                D_80075E2C = 0;
                func_800317C0(&D_80079C84, 3);
                D_8012EFD4 = 0;
                func_8001892C(D_004E32C0, D_004EA530, 0x40, 0x14);
                if ((*(u8 (*))&D_800745F7) == 0) {
                    D_800745F4 = D_800745F6 + (func_80020EB4(11) + 2);
                    D_800745F4 %= 34;
                    D_800745F6 = D_800745F4;
                } else {
                    D_800745F4 = D_800745F6;
                }
                D_800745F5 = D_800745F4;
                if (D_80106870 == 0) {
                    D_80108B20 = D_800745FC[D_800745F4];
                } else {
                    D_80108B20 = D_80074620[D_800745F4];
                }
                D_800745F0 = D_800745F4;
                D_800A7AA0 = func_800323F4(D_80108B20);
                func_8001F300(&D_801650D4);
                D_80108DB0 = 1;
                D_8006DDEC = 0;
                D_80107910 = 0x10001;
                D_8006EDD8 &= ~1;
                D_8006EDD8 |= 0x100;
                D_8006EDD8 &= ~2;
                D_8006EDD8 &= ~0x10;
                D_8006EDD8 &= ~0x20;
                D_8006EDD8 &= ~0x40;
                break;
            default:
                return;
            }
            osViBlack(0);
        }
        break;
    case 13:
        if ((u8)(D_801282A3 -= 0x10) > 0xF0) {
            D_801282A3 = 0;
            s->unk_28 = 11;
            s->unk_C |= 1;
        }
        break;
    case 17:
        if ((u8)(D_801282A3 -= 0x10) > 0xF0) {
            D_801282A3 = 0;
            s->unk_28 = 14;
        }
        break;
    case 19:
        if ((D_801282A3 += 0x10) < 0x10) {
            D_800745E4++;
            D_801282A3 = 0xFF;
            if (D_800745E4 >= 5) {
                osViBlack(1);
                D_80109B8C = 0;
                func_8001D9D0(0x16);
                s->unk_24 = 0;
                D_800A7AA0 = 0;
                D_80108DB0 = 0;
                D_8006DDEC = 0;
                D_8012EFD0 = 0x16;
                s->unk_28 = 17;
                D_800A8DDC = 0;
                D_8006EDD8 |= 1;
                D_8006EDD8 |= 0x10;
                D_8006EDD8 |= 0x20;
                D_8006EDD8 |= 0x40;
                func_8004CF14(D_800A7AFC, 0);
                func_8001892C(D_004DB3E0, D_004DD320, 0x55, 0x14);
                D_80107910 = 0xD000D;
                D_800745ED = 1;
                D_800745E4 = 5;
                osViBlack(0);
            } else {
                s->unk_28 = 20;
            }
        }
        break;
    case 20:
        if ((u8)(D_801282A3 -= 0x10) > 0xF0) {
            D_801282A3 = 0;
            s->unk_28 = 1;
        }
        break;
    }
}
