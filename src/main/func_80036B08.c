typedef struct { u8 unk_00[0x24]; f32 x; u8 unk_28[4]; f32 z; } Target;
typedef struct Actor {
    u8 unk_000[0x24]; f32 x; u8 unk_028[4]; f32 z;
    u8 unk_030[0x1B8 - 0x30]; f32 unk_1B8; u8 unk_1BC[4]; f32 unk_1C0;
    u8 unk_1C4[8]; s32 unk_1CC; u8 unk_1D0[0x20]; Target *unk_1F0;
    u8 unk_1F4[0xC]; s32 unk_200; s32 unk_204;
} Actor;

void func_80035828(Actor *, s32);
f32 func_80054D30(f32);
f32 func_80056500(f32);
void func_80057650(void *);
f64 func_80067FB0(f64, f64);
extern s32 D_8006EDD8;
extern u16 D_801078BA;
extern u16 D_80109C3E;
extern s32 D_80115374;
extern u8 D_8012EF88[];
extern u8 D_8012EFCD;
extern s32 D_8012FCE0;
extern s16 D_8013C650;

/* Actor state update: triggers on input/timers, otherwise turns to face its target. */
void func_80036B08(Actor *a) {
    register f32 dx;
    register f32 dz;
    register Actor *p;

    if (D_8012EFCD == 0) {
        if ((D_8006EDD8 & 2) && (D_80115374 == 0)) {
            D_8012EFCD = 1;
            a->unk_200 = a->unk_200 | 1;
            a->unk_200 = a->unk_200 | 2;
        }
    } else if ((a->unk_1CC >= 50) && (u16)(D_801078BA & 0xC00F)) {
        if (D_80115374 != 0) {
            D_8013C650 = D_80109C3E >> 3;
            func_80057650(D_8012EF88);
        }
        D_8012FCE0 = 0x11;
        func_80035828(a, 0x23);
    }
    if (a->unk_1CC >= 20) {
        if (a->unk_204 != 0) {
            if (D_80115374 != 0) {
                D_8013C650 = D_80109C3E >> 3;
                func_80057650(D_8012EF88);
            }
            func_80035828(a, 1);
            return;
        }
    } else {
        dx = a->unk_1F0->x - a->x;
        dz = a->unk_1F0->z - a->z;
        dz = func_80067FB0(dz, dx);
        p = a;
        p->unk_1B8 = func_80054D30(dz);
        p = a;
        p->unk_1C0 = func_80056500(dz);
    }
}
