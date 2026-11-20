extern s32 D_80082B88;
s32 func_80056A60();
s32 func_80057100();
s32 func_8005EE10();

void f(s32 arg0, s32 arg1, s32 arg2) {
    s32 sp20[6];
    s32 sp38[2];

    func_80056A60(arg1, arg2);
    func_8005EE10(((s32)&sp20), 0, 0, arg0, arg1, arg2, ((s32)&D_80082B88));
    func_80057100(((s32)&D_80082B88), ((s32)&sp38), 1);
}
