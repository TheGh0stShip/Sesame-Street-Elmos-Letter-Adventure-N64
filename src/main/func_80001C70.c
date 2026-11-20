struct gd_4_s32 { u8 pad[0x4]; s32 v; };
struct n64dk_e8 { u8 b[8]; };
extern s32 D_800749A0;
extern struct n64dk_e8 *D_8013EB0C;

void f(s32 arg0) {
    s32 sp0;

    sp0 = (s32)D_8013EB0C++;
    (*(s32 *)sp0) = 0x6000000;
    ((struct gd_4_s32 *)sp0)->v = (s32)&D_800749A0;
}
