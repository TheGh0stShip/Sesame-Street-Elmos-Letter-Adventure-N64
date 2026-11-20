struct gd_4_s32 { u8 pad[0x4]; s32 v; };
extern s32 D_800A7B00;
extern s32 D_801283A8;
extern s32 D_8013C5BC;

void f(s32 arg0) {
    if ((*(s32 *)arg0) != 0) {
        ((struct gd_4_s32 *)(*(s32 *)arg0))->v = ((struct gd_4_s32 *)arg0)->v;
    }
    if (((struct gd_4_s32 *)arg0)->v != 0) {
        (*(s32 *)((struct gd_4_s32 *)arg0)->v) = *(s32 *)arg0;
    } else {
        D_800A7B00 = *(s32 *)arg0;
    }
    (*(s32 *)arg0) = D_801283A8;
    D_801283A8 = arg0;
    D_8013C5BC--;
}
