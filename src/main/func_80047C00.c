struct n64dk_m10_10 { u8 pad[0x10]; struct { u8 b[0x10]; } m[1]; };
struct n64dk_v0 { void *v; };
extern s32 D_800A00B0;
extern s32 D_800A00B4;
extern s32 D_800A00B8;
s32 func_80040400();

void f(s32 arg0) {
    s32 sp10;

    D_800A00B8 = arg0;
    D_800A00B4 = func_80040400((D_800A00B8 * 16));
    D_800A00B0 = D_800A00B4;
    sp10 = 0;
    while (!((u32)sp10 >= (u32)(D_800A00B8 - 1))) {
        ((struct n64dk_v0 *)((sp10 * 16) + D_800A00B4))->v = (void *)&((struct n64dk_m10_10 *)D_800A00B4)->m[sp10];
        sp10++;
    }
    (*(s32 *)((sp10 * 16) + D_800A00B4)) = 0;
    return;
}
