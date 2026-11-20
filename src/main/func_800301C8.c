struct gd_4_s32 { u8 pad[0x4]; s32 v; };
struct n64dk_e8 { u8 b[8]; };
extern s32 D_800749A0;
extern s8 D_80075D52;
extern u8 D_80075D53;
extern s32 D_80075D78;
extern s32 D_8007A868;
extern struct n64dk_e8 *D_8013EB0C;
s32 func_8000DBC0();
s32 func_8000DCFC();
s32 func_8000DD7C();
s32 func_8000DDF4();
s32 func_8000DE60();
s32 func_8000DEBC();
s32 func_8005F540();

void f(s32 arg0) {
    s32 sp10;
    s32 sp18[26];
    s32 sp80;

    if (D_80075D53 != 0) {
        sp10 = func_8000DBC0();
        func_8000DE60(1);
        func_8000DDF4(255, 255, 255, 255);
        func_8000DD7C(70, 20);
        func_8005F540(((s32)&sp18), ((s32)&D_8007A868), ((D_80075D52 * 20) + ((s32)&D_80075D78)));
        func_8000DEBC(((s32)&sp18));
        sp80 = (s32)D_8013EB0C++;
        (*(s32 *)sp80) = 0x6000000;
        ((struct gd_4_s32 *)sp80)->v = (s32)&D_800749A0;
        func_8000DCFC(sp10);
    }
}
