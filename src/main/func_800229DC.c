extern s32 D_8004BAE0;
extern s32 D_8004C06C;
extern s32 D_800AEC40;
extern s32 D_80112CD0;
s32 func_80049848(s32, s32, s32, s32, s32, f32);

void f(void) {
    s32 sp18;

    sp18 = func_80049848(D_80112CD0, D_800AEC40, ((s32)&D_8004BAE0), ((s32)&D_8004C06C), 48, 1.0f);
}
