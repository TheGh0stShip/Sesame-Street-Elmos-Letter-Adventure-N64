/* Inserts an entry into a 256-slot list sorted by f64 key. */


struct gd_8_f64 { u8 pad[0x8]; f64 v; };
struct gd_10_s32 { u8 pad[0x10]; s32 v; };
struct gd_14_s32 { u8 pad[0x14]; s32 v; };
struct n64dk_e24 { u8 b[24]; };
extern s32 D_80075C60;
extern s32 D_80075C64;
extern s32 D_8009E8B0;

void f(s32 arg0, f64 arg2) {
    void *sp0;
    s32 sp4;

    if (D_80075C60 == 256) {
        return;
    }
    sp0 = (void *)&((struct n64dk_e24 *)&D_8009E8B0)[D_80075C60++];
    (*(s32 *)((s32)sp0)) = arg0;
    ((struct gd_8_f64 *)((s32)sp0))->v = arg2;
    ((struct gd_14_s32 *)((s32)sp0))->v = ((struct gd_10_s32 *)((s32)sp0))->v = 0;
    if ((sp4 = D_80075C64) == 0) {
        D_80075C64 = (s32)sp0;
        return;
    }
    if (arg2 == 0.0) {
        ((struct gd_10_s32 *)((s32)sp0))->v = D_80075C64;
        ((struct gd_14_s32 *)D_80075C64)->v = (s32)sp0;
        D_80075C64 = (s32)sp0;
    } else {
        while ((((struct gd_10_s32 *)sp4)->v != 0) && (((struct gd_8_f64 *)sp4)->v < arg2)) {
            sp4 = ((struct gd_10_s32 *)sp4)->v;
        }
        if (((struct gd_10_s32 *)sp4)->v == 0) {
            ((struct gd_14_s32 *)((s32)sp0))->v = sp4;
            ((struct gd_10_s32 *)sp4)->v = (s32)sp0;
            return;
        }
        ((struct gd_10_s32 *)((s32)sp0))->v = sp4;
        ((struct gd_14_s32 *)((s32)sp0))->v = ((struct gd_14_s32 *)sp4)->v;
        ((struct gd_14_s32 *)sp4)->v = (s32)sp0;
        if (((struct gd_14_s32 *)((s32)sp0))->v == 0) {
            D_80075C64 = (s32)sp0;
            return;
        }
        ((struct gd_10_s32 *)((struct gd_14_s32 *)((s32)sp0))->v)->v = (s32)sp0;
    }
}
