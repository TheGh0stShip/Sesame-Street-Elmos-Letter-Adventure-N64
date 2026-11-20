/* per-frame actor update: arms on a flag, reacts to buttons, then faces its target */
typedef struct { u8 pad[0x24]; f32 unk_24; u8 pad28[4]; f32 unk_2C; } Target;
typedef struct {
    u8 pad0[0x24]; f32 unk_24; u8 pad28[4]; f32 unk_2C;
    u8 pad30[0x1B8 - 0x30]; f32 unk_1B8; u8 pad1BC[4]; f32 unk_1C0;
    u8 pad1C4[8]; s32 unk_1CC; u8 pad1D0[0x20]; Target *unk_1F0;
    u8 pad1F4[0xC]; s32 unk_200; s32 unk_204;
} Actor;
void func_80035828(Actor *, s32);
f32 func_80054D30(f32);
f32 func_80056500(f32);
void func_80057650(void *);
f64 func_80067FB0(f64, f64);
extern s32 D_8006EDD8;
extern u8 D_800B0C98;
extern u16 D_801078BA;
extern u16 D_80109C3E;
extern s32 D_80115374;
extern s32 D_8012EF88;
extern s32 D_8012FCE0;
extern u16 D_8013C650;

void func_80036480(Actor *arg0) {
    register Actor *a;
    register f32 dx;
    register f32 dz;

    if (D_800B0C98 == 0) {
        if ((D_8006EDD8 & 2) && (D_80115374 == 0)) {
            D_800B0C98 = 1;
            arg0->unk_200 = arg0->unk_200 | 1;
            arg0->unk_200 = arg0->unk_200 | 2;
        }
    } else if ((arg0->unk_1CC >= 50) && (D_801078BA & 0xC00F)) {
        if (D_80115374 != 0) {
            D_8013C650 = D_80109C3E >> 3;
            func_80057650(&D_8012EF88);
        }
        D_8012FCE0 = 0x10;
        func_80035828(arg0, 0x23);
    }
    if (arg0->unk_1CC >= 20) {
        if (arg0->unk_204 != 0) {
            if (D_80115374 != 0) {
                D_8013C650 = D_80109C3E >> 3;
                func_80057650(&D_8012EF88);
            }
            func_80035828(arg0, 1);
            return;
        }
    } else {
        dx = arg0->unk_1F0->unk_24 - arg0->unk_24;
        dz = arg0->unk_1F0->unk_2C - arg0->unk_2C;
        dz = func_80067FB0(dz, dx);
        a = arg0; a->unk_1B8 = func_80054D30(dz);
        a = arg0; a->unk_1C0 = func_80056500(dz);
    }
}
