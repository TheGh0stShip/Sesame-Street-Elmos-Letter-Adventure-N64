struct gd_4_s32 { u8 pad[0x4]; s32 v; };
struct n64dk_e8 { u8 b[8]; };
extern s32 D_80071D40;
extern s32 D_80071D44;
extern s32 D_80071D60;
extern s32 D_80071D88;
extern s8 D_80071E10;
extern s8 D_80071E11;
extern s8 D_80071E12;
extern s8 D_80071E13;
extern s32 D_80071E14;
extern s32 D_80071E18;
extern s32 D_80071E1C;
extern s32 D_80071E20;
extern f64 D_80071E28;
extern f64 D_80071E30;
extern f64 D_80079870;
extern f64 D_80079878;
extern struct n64dk_e8 *D_8013EB0C;
s32 func_8005C9D0();

s32 f(void) {
    s32 sp10;
    s32 sp14;

    sp10 = (s32)D_8013EB0C++;
    func_8005C9D0(((s32)&sp10));
    D_80071D44 = D_80071D40;
    (*(u8 *)&D_80071E10) = 255;
    (*(u8 *)&D_80071E11) = 255;
    (*(u8 *)&D_80071E12) = 255;
    (*(u8 *)&D_80071E13) = 255;
    D_80071E14 = 0;
    D_80071E18 = 0;
    D_80071E1C = 40;
    D_80071E20 = 1;
    D_80071E28 = D_80079870;
    D_80071E30 = D_80079878;
    sp14 = (s32)D_8013EB0C++;
    (*(s32 *)sp14) = 0x6000000;
    ((struct gd_4_s32 *)sp14)->v = (s32)&D_80071D88;
    sp14 = (s32)D_8013EB0C++;
    (*(s32 *)sp14) = 0x6000000;
    ((struct gd_4_s32 *)sp14)->v = (s32)&D_80071D60;
    return sp10;
}
