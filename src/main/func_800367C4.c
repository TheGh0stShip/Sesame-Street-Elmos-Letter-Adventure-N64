typedef struct Obj {
    u8 pad0[0x24];
    f32 unk_24;
    u8 pad28[4];
    f32 unk_2C;
    u8 pad30[0x1B8 - 0x30];
    f32 unk_1B8;
    u8 pad1BC[4];
    f32 unk_1C0;
    u8 pad1C4[0x1CC - 0x1C4];
    s32 unk_1CC;
    u8 pad1D0[0x1F0 - 0x1D0];
    struct Obj *unk_1F0;
    u8 pad1F4[0x200 - 0x1F4];
    s32 unk_200;
    s32 unk_204;
} Obj;
extern u8 D_800A75EC;
extern s32 D_8006EDD8;
extern s32 D_80115374;
extern u16 D_801078BA;
extern u16 D_80109C3E;
extern u16 D_8013C650;
extern s32 D_8012EF88;
extern s32 D_8012FCE0;
void func_80057650(void *);
void func_80035828(Obj *, s32);
f64 func_80067FB0(f64, f64);
f32 func_80054D30(f32);
f32 func_80056500(f32);

void func_800367C4(Obj *p) {
    register f32 dx;
    register f32 dz;

    if (D_800A75EC == 0) {
        if ((D_8006EDD8 & 2) && D_80115374 == 0) {
            D_800A75EC = 1;
            p->unk_200 = p->unk_200 | 1;
            p->unk_200 = p->unk_200 | 2;
        }
    } else if (p->unk_1CC >= 50 && (D_801078BA & 0xC00F)) {
        if (D_80115374 != 0) {
            D_8013C650 = D_80109C3E >> 3;
            func_80057650(&D_8012EF88);
        }
        D_8012FCE0 = 13;
        func_80035828(p, 0x23);
    }
    if (p->unk_1CC >= 20) {
        if (p->unk_204 != 0) {
            if (D_80115374 != 0) {
                D_8013C650 = D_80109C3E >> 3;
                func_80057650(&D_8012EF88);
            }
            func_80035828(p, 1);
            return;
        }
        return;
    }
    dx = p->unk_1F0->unk_24 - p->unk_24;
    dz = p->unk_1F0->unk_2C - p->unk_2C;
    dz = func_80067FB0(dz, dx);
    { register Obj *q = p; q->unk_1B8 = func_80054D30(dz); }
    { register Obj *q = p; q->unk_1C0 = func_80056500(dz); }
}
