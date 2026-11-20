struct gd_1CC_s32 { u8 pad[0x1CC]; s32 v; };
struct gd_204_s32 { u8 pad[0x204]; s32 v; };
extern s16 D_800A7AFA;
extern u16 D_801078BA;
extern u8 D_801078F0;
extern s32 D_80109B8C;
extern s8 D_8012EFCC;
extern s32 D_8012EFD0;
s32 func_80035828();

void f(s32 arg0) {
    s32 pad0[2];
    s8 pad1;

    ((struct gd_1CC_s32 *)arg0)->v++;
    if (D_80109B8C == 0) {
        return;
    }
    if (((struct gd_204_s32 *)arg0)->v != 0) {
        func_80035828(arg0, 1);
    } else {
        if (((D_801078BA & 0xC00F) & 0xFFFF) != 0) {
            if (D_8012EFD0 != 11) {
                func_80035828(arg0, 6);
            }
        }
    }
    if (((D_801078BA & 0x1000) & 0xFFFF) != 0) {
        if (D_801078F0 != 0) {
            D_8012EFCC = 1;
            D_800A7AFA = 0;
        } else {
        }
    }
}
