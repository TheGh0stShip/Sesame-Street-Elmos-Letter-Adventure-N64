struct gd_1C_s32 { u8 pad[0x1C]; s32 v; };
extern s32 D_8007AF4C;
extern s32 D_800A00B0;
s32 func_80047F60();

void f(s32 arg0) {
    s32 sp10;

    if (((struct gd_1C_s32 *)arg0)->v == 0) {
        func_80047F60(((s32)&D_8007AF4C));
        return;
    }
    sp10 = ((struct gd_1C_s32 *)arg0)->v;
    ((struct gd_1C_s32 *)arg0)->v = *(s32 *)sp10;
    (*(s32 *)sp10) = D_800A00B0;
    D_800A00B0 = sp10;
    return;
}
