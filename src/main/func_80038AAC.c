

struct gd_1AC_f32 { u8 pad[0x1AC]; f32 v; };
struct gd_1B4_f32 { u8 pad[0x1B4]; f32 v; };
struct gd_224_u16 { u8 pad[0x224]; u16 v; };
extern f64 D_8007AB50;
extern f64 D_8007AB58;
extern f64 D_8007AB60;
extern s32 D_800A7ABC;
extern s16 D_800A7AFA;
extern u16 D_801078BA;
extern u8 D_801078F0;
extern u32 D_8012EFA8;
extern u8 D_8012EFAB;
extern s8 D_8012EFCC;
extern s8 D_80140F90;
s32 func_80017568();
s32 func_8004D020();
f32 func_80054D20(f32);

void f(s32 arg0) {
    f32 sp10;
    f32 sp14;
    f32 sp18;
    s32 pad0;
    f32 sp20;
    f64 sp28;

    sp10 = ((struct gd_1AC_f32 *)arg0)->v;
    sp14 = 0;
    sp18 = ((struct gd_1B4_f32 *)arg0)->v;
    sp20 = func_80054D20((((sp10 * sp10) + (sp14 * sp14)) + (sp18 * sp18)));
    if (sp20 >= 1e-07f) {
        sp28 = D_8007AB50 / ((f64)sp20);
        sp10 = (f32)(((f64)sp10) * sp28);
        sp14 = (f32)(((f64)sp14) * sp28);
        sp18 = (f32)(((f64)sp18) * sp28);
    } else {
    }
    D_8012EFA8 = (((f64)sp20) * D_8007AB58);
    if ((u32)D_8012EFA8 >= 129) {
        D_8012EFA8 = 128;
    }
    D_80140F90 = D_8012EFAB;
    func_8004D020(D_800A7ABC, D_8012EFA8);
    if (((struct gd_224_u16 *)arg0)->v == 0) {
        func_80017568(37);
    }
    if (((D_801078BA & 0x1000) & 0xFFFF) != 0) {
        if (D_801078F0 != 0) {
            D_8012EFCC = 1;
            D_800A7AFA = 0;
        } else {
        }
    }
}
