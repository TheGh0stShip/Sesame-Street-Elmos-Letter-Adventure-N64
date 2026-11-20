struct gd_4_f32 { u8 pad[0x4]; f32 v; };
struct gd_8_f32 { u8 pad[0x8]; f32 v; };
extern s32 D_80075C20;
extern f64 D_80079928;
extern f64 D_80079930;
extern f64 D_80079938;
extern f64 D_80079940;
extern f64 D_80079948;
extern f64 D_80079950;
extern f32 D_800ACC20;
extern f32 D_800ACC24;
extern f32 D_800ACC28;
extern f32 D_8012FD30;
extern f32 D_8012FD34;
extern f32 D_8012FD38;
f32 func_80054D20(f32);

void f(void) {
    f64 sp10;

    D_8012FD30 = *(f32 *)(D_80075C20 + 48);
    D_8012FD34 = ((struct gd_4_f32 *)(D_80075C20 + 48))->v;
    D_8012FD38 = ((struct gd_8_f32 *)(D_80075C20 + 48))->v;
    D_8012FD30 = D_8012FD30 - (*(f32 *)(D_80075C20 + 36));
    D_8012FD34 = D_8012FD34 - ((struct gd_4_f32 *)(D_80075C20 + 36))->v;
    D_8012FD38 = D_8012FD38 - ((struct gd_8_f32 *)(D_80075C20 + 36))->v;
    sp10 = (f64)func_80054D20((((D_8012FD30 * D_8012FD30) + (D_8012FD34 * D_8012FD34)) + (D_8012FD38 * D_8012FD38)));
    if (!(sp10 == 0.0)) {
        D_8012FD30 = (f32)(((f64)D_8012FD30) * (D_80079928 / sp10));
        D_8012FD34 = (f32)(((f64)D_8012FD34) * (D_80079930 / sp10));
        D_8012FD38 = (f32)(((f64)D_8012FD38) * (D_80079938 / sp10));
    }
    D_800ACC20 = D_8012FD30;
    D_800ACC24 = D_8012FD34;
    D_800ACC28 = D_8012FD38;
    D_800ACC20 = (f32)(((f64)D_800ACC20) * D_80079940);
    D_800ACC24 = (f32)(((f64)D_800ACC24) * D_80079948);
    D_800ACC28 = (f32)(((f64)D_800ACC28) * D_80079950);
}
