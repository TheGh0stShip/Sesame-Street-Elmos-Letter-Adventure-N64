#include "common.h"
#include "game_structs.h"

typedef struct {
    u32 flags;
    s32 unk_04;
    s32 unk_08;
} Entry;
extern u8 D_0050D000[], D_0050F9E0[], D_004D9D80[], D_004DB3E0[], D_004EA530[], D_004EADF0[];
extern u16 D_801078BA;
extern Entry D_8013EB38[];

/* timed scene script: plays sounds/music and changes state at fixed frame counts */
void func_8003AB7C(Actor *arg0) {
    if (D_8012FCE0 == 0x13) {
        if (arg0->u.walker.frame == 150 && D_80115374 == NULL) {
            D_80115374 = D_80074480;
            osSendMesg(D_8013ED88, 0, 1);
        }
        if (arg0->u.walker.frame == 400) {
            func_80035828(arg0, 0x23);
        }
        return;
    }
    if (D_800A7608 == D_800A75E8 && !(D_8013EB38[D_800A7608 - 1].flags & 2)) {
        arg0->u.walker.frame = 0;
        return;
    }
    if (D_8012EFD0 != 0xB && D_8012EFD0 != 0x13 && arg0->u.walker.frame == 270) {
        func_8004CF14(D_800A7AFC, 0);
        func_8001892C(D_0050D000, D_0050F9E0, 0x40, 0x14);
    }
    switch (D_8012EFD0) {
    case 15:
    case 16:
        if (arg0->u.walker.frame == 300) {
            D_8006EDD8 &= ~0x10;
            D_8006EDD8 |= 0x60A;
            if (D_80115374 == NULL) {
                D_80115374 = D_800733D8;
                osSendMesg(D_8013ED88, 0, 1);
            }
        } else if (arg0->u.walker.frame == 900) {
            D_8006EDD8 &= ~0x608;
            D_8006EDD8 |= 4;
            if (D_80115374 == NULL) {
                D_80115374 = D_800733E8;
                osSendMesg(D_8013ED88, 0, 1);
            }
        }
        break;
    case 17:
    case 18:
        if (arg0->u.walker.frame == 300) {
            D_8006EDD8 &= ~0x10;
            D_8006EDD8 |= 0x60A;
            if (D_80115374 == NULL) {
                D_80115374 = D_80073418;
                osSendMesg(D_8013ED88, 0, 1);
            }
        } else if (arg0->u.walker.frame == 900) {
            D_8006EDD8 &= ~0x608;
            D_8006EDD8 |= 4;
            if (D_80115374 == NULL) {
                D_80115374 = D_80073428;
                osSendMesg(D_8013ED88, 0, 1);
            }
        }
        break;
    case 13:
    case 14:
        if (arg0->u.walker.frame == 300) {
            D_8006EDD8 &= ~0x10;
            D_8006EDD8 |= 0x60A;
            if (D_80115374 == NULL) {
                D_80115374 = D_800733F8;
                osSendMesg(D_8013ED88, 0, 1);
            }
        } else if (arg0->u.walker.frame == 900) {
            D_8006EDD8 &= ~0x608;
            D_8006EDD8 |= 4;
            if (D_80115374 == NULL) {
                D_80115374 = D_80073408;
                osSendMesg(D_8013ED88, 0, 1);
            }
        }
        break;
    case 19:
        if ((D_8006EDD8 & 0x200000) && (D_8006EDD8 & 0x100000) && (D_8006EDD8 & 0x400000)) {
            if (arg0->u.walker.frame == 100) {
                func_80017568(0x10);
            }
            if (arg0->u.walker.frame == 280 && D_80115374 == NULL) {
                D_80115374 = D_800732F0;
                osSendMesg(D_8013ED88, 0, 1);
            }
            if (arg0->u.walker.frame == 300) {
                func_8004CF14(D_800A7AFC, 0);
                func_8001892C(D_004D9D80, D_004DB3E0, 0x46, 0x14);
                D_801282A3 = 0;
                D_800761E0 = 1;
                D_80075C30 = 0;
            }
            if (arg0->u.walker.frame >= 351 && D_800761E0 == 0) {
                func_8004CF14(D_800A7AFC, 0);
                func_80035828(arg0, 0x23);
                D_8006EDD8 &= ~0x400000;
                D_8006EDD8 &= ~0x200000;
                D_8006EDD8 &= ~0x100000;
            }
        } else {
            if (arg0->u.walker.frame == 100) {
                func_80017568(0x10);
            }
            if (arg0->u.walker.frame == 370) {
                func_8004CF14(D_800A7AFC, 0);
                func_8001892C(D_004EA530, D_004EADF0, 0x55, 0x14);
            }
            if (arg0->u.walker.frame == 630) {
                func_80035828(arg0, 0x23);
            }
        }
        break;
    }
    if (D_8012EFD0 == 0xB || D_8012EFD0 == 0x13) {
        return;
    }
    if (((u16)(D_801078BA & 0xC00F) && arg0->u.walker.frame >= 601) || arg0->u.walker.frame >= 1801) {
        if (D_800A7608 == D_800A75E8) {
            D_800ACBA0 = 0;
            D_800A7608 = 0;
            func_80003F60();
        }
        if (D_80115374 != NULL) {
            D_8013C650 = D_80109C3E >> 3;
            osStopTimer(D_8012EF88);
        }
        D_8006EDD8 &= ~0x60E;
        func_80035828(arg0, 0x23);
    }
    if ((u16)(D_801078BA & 0x1000) && arg0->u.walker.frame >= 1201) {
        D_800ACBA0 = 0;
        D_800A7608 = 0;
        D_8012FCE0 = 2;
        if (D_80115374 != NULL) {
            D_8013C650 = D_80109C3E >> 3;
            osStopTimer(D_8012EF88);
        }
        D_8006EDD8 &= ~0x60E;
        func_80035828(arg0, 0x23);
    }
}
