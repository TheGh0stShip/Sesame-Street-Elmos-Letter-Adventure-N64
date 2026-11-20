struct gd_4_s32 { u8 pad[0x4]; s32 v; };
struct n64dk_e8 { u8 b[8]; };
extern u16 D_800A7A90;
extern struct n64dk_e8 *D_8013EB0C;
extern s32 D_8013EF68;

void f(s32 arg0) {
    s32 sp0;

    sp0 = (s32)D_8013EB0C++;
    (*(s32 *)sp0) = 0xBC00000E;
    ((struct gd_4_s32 *)sp0)->v = D_800A7A90;
    sp0 = (s32)D_8013EB0C++;
    (*(s32 *)sp0) = 0x1030040;
    ((struct gd_4_s32 *)sp0)->v = D_8013EF68;
}
