struct gd_4_s32 { u8 pad[0x4]; s32 v; };
struct n64dk_e8 { u8 b[8]; };
struct n64dk_e64 { u8 b[64]; };
struct n64dk_v4 { u8 pad[0x4]; void *v; };
extern s32 D_800706E0;
extern s32 D_80070760;
extern u8 D_800761E0;
extern s32 D_8012EFD0;
extern struct n64dk_e8 *D_8013EB0C;
extern s32 D_80164C38;
extern s32 D_801977E8;
extern s32 D_801A9AC0;
extern s32 D_801ABBF0;
s32 func_80025E4C();

void f(s32 arg0) {
    s32 sp10;

    sp10 = (s32)D_8013EB0C++;
    (*(s32 *)sp10) = 0x1020040;
    ((struct n64dk_v4 *)sp10)->v = (void *)&((struct n64dk_e64 *)&D_800706E0)[D_80070760];
    if ((D_8012EFD0 == 15) || (D_8012EFD0 == 16)) {
        sp10 = (s32)D_8013EB0C++;
        (*(s32 *)sp10) = 0xBA000C02;
        ((struct gd_4_s32 *)sp10)->v = 0x3000;
        sp10 = (s32)D_8013EB0C++;
        (*(s32 *)sp10) = 0xB7000000;
        ((struct gd_4_s32 *)sp10)->v = 0x12204;
        sp10 = (s32)D_8013EB0C++;
        (*(s32 *)sp10) = 0xFC121824;
        ((struct gd_4_s32 *)sp10)->v = 0xFF33FFFF;
        sp10 = (s32)D_8013EB0C++;
        (*(s32 *)sp10) = 0xBA001402;
        ((struct gd_4_s32 *)sp10)->v = 0x100000;
        sp10 = (s32)D_8013EB0C++;
        (*(s32 *)sp10) = 0xF8000000;
        ((struct gd_4_s32 *)sp10)->v = 0x4F4FF6FF;
        sp10 = (s32)D_8013EB0C++;
        (*(s32 *)sp10) = 0xBC000008;
        ((struct gd_4_s32 *)sp10)->v = 0x2155DFAB;
        sp10 = (s32)D_8013EB0C++;
        (*(s32 *)sp10) = 0xB900031D;
        ((struct gd_4_s32 *)sp10)->v = 0xC8112038;
    } else {
        sp10 = (s32)D_8013EB0C++;
        (*(s32 *)sp10) = 0xBA000C02;
        ((struct gd_4_s32 *)sp10)->v = 0x3000;
        sp10 = (s32)D_8013EB0C++;
        (*(s32 *)sp10) = 0xB7000000;
        ((struct gd_4_s32 *)sp10)->v = 0x2204;
        sp10 = (s32)D_8013EB0C++;
        (*(s32 *)sp10) = 0xFC127E24;
        ((struct gd_4_s32 *)sp10)->v = -3079;
        sp10 = (s32)D_8013EB0C++;
        (*(s32 *)sp10) = 0xB900031D;
        ((struct gd_4_s32 *)sp10)->v = 0x553078;
    }
    sp10 = (s32)D_8013EB0C++;
    (*(s32 *)sp10) = 0xE7000000;
    ((struct gd_4_s32 *)sp10)->v = 0;
    switch (D_8012EFD0) {
    case 2:
        if (D_800761E0 != 1) {
            func_80025E4C(((s32)&D_801A9AC0));
        }
        return;
    case 19:
        if (D_800761E0 != 1) {
            func_80025E4C(((s32)&D_80164C38));
        }
        return;
    case 16:
        return;
    case 15:
        return;
    case 18:
        func_80025E4C(((s32)&D_801977E8));
        return;
    case 17:
        func_80025E4C(((s32)&D_801ABBF0));
        return;
    case 14:
        return;
    case 13:
        return;
    }
}
