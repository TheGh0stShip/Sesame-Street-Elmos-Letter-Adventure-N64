typedef struct {
    u8 pad[0x24];
    f32 unk_24; f32 unk_28; f32 unk_2C;
    f32 unk_30; f32 unk_34; f32 unk_38;
    f32 unk_3C; f32 unk_40; f32 unk_44;
    f32 unk_48; f32 unk_4C; f32 unk_50;
} Actor;
/* The trig calls were statement-expression macros: their results are stored after the target address is loaded. */
#define SINF(x) ({ func_80054D30(x); })
#define COSF(x) ({ func_80056500(x); })
extern f32 D_80109C38;
extern f32 D_80112CE0;
extern s32 D_8011537C;
extern s32 D_80133E3C;
f64 func_80067FB0(f64 y, f64 x);
f32 func_80054D30(f32 a);
f32 func_80056500(f32 a);
void func_80035828(Actor *a, s32 b);
void func_800229DC(void);
void func_8004A35C(s32 a, s32 b);

/* Turns the actor toward a fixed point and computes the cross product of two direction vectors. */
void func_80039714(Actor *arg0) {
    register f32 dx;
    register f32 dz;

    if (D_8011537C == 0) {
        dx = D_80112CE0 - arg0->unk_24;
        dz = D_80109C38 - arg0->unk_2C;
        dx = func_80067FB0(dz, dx);
        arg0->unk_30 = SINF(dx);
        arg0->unk_38 = COSF(dx);
        arg0->unk_48 = arg0->unk_34 * arg0->unk_44 - arg0->unk_38 * arg0->unk_40;
        arg0->unk_4C = arg0->unk_38 * arg0->unk_3C - arg0->unk_30 * arg0->unk_44;
        arg0->unk_50 = arg0->unk_30 * arg0->unk_40 - arg0->unk_34 * arg0->unk_3C;
    } else if (D_8011537C < 0) {
        func_80035828(arg0, 0x17);
        func_800229DC();
        func_8004A35C(D_80133E3C, 0);
    }
}
