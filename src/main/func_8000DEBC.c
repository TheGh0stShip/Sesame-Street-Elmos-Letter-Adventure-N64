struct gd_4_s16 { u8 pad[0x4]; s16 v; };
struct gd_4_s32 { u8 pad[0x4]; s32 v; };
struct gd_6_s16 { u8 pad[0x6]; s16 v; };
struct n64dk_e8 { u8 b[8]; };
extern s32 D_80071CFC;
extern s32 D_80071D08;
extern u8 D_80071E10;
extern u8 D_80071E11;
extern u8 D_80071E12;
extern u8 D_80071E13;
extern s32 D_80071E14;
extern s32 D_80071E18;
extern s32 D_80071E1C;
extern s32 D_80071E20;
extern f64 D_80071E28;
extern f64 D_80071E30;
extern struct n64dk_e8 *D_8013EB0C;
s32 func_8000D810();
s32 func_8005B620();
s32 func_8005B660(s32, f32, f32);
s32 func_8005B6F8();
s32 func_8005CB88();

void f(s32 arg0) {
    s32 sp18;
    s32 sp1C;
    s32 sp20;

    sp18 = (s32)&D_80071D08;
    ((struct gd_4_s16 *)sp18)->v = (D_80071E1C * 8) + 8;
    ((struct gd_6_s16 *)sp18)->v = (D_80071E20 * 16) + 8;
    func_8000D810(sp18, arg0, ((s32)&D_80071CFC), D_80071E1C, D_80071E20);
    func_8005B6F8(sp18, D_80071E14, D_80071E18);
    func_8005B620(sp18, D_80071E10, D_80071E11, D_80071E12, D_80071E13);
    func_8005B660(sp18, ((f32)D_80071E28), ((f32)D_80071E30));
    sp1C = func_8005CB88(sp18);
    sp20 = (s32)D_8013EB0C++;
    (*(s32 *)sp20) = 0x6000000;
    ((struct gd_4_s32 *)sp20)->v = sp1C;
}
