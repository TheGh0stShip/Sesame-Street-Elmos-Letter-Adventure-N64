struct gd_1C8_s32 { u8 pad[0x1C8]; s32 v; };
struct gd_1CC_s32 { u8 pad[0x1CC]; s32 v; };
extern s32 D_800762C0;
extern s32 D_8007AA60;
extern s32 D_8007AA64;
s32 func_80057BD0();

void f(s32 arg0) {
    if ((u32)((struct gd_1C8_s32 *)arg0)->v < 39) {
        goto L11;
    }
    func_80057BD0(((s32)&D_8007AA60), ((s32)&D_8007AA64), 524);
L11: ;
    ((s32 (*)())(*(s32 *)((((struct gd_1C8_s32 *)arg0)->v * 4) + ((s32)&D_800762C0))))(arg0);
    ((struct gd_1CC_s32 *)arg0)->v++;
}
