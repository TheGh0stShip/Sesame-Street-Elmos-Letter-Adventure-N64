extern s32 D_8000BB84;
extern s32 D_8007D4F0;
extern s32 D_800816A0;
s32 func_80056C70();
s32 func_80056DD0();
s32 func_80057530();

void f(s32 arg0) {
    s32 pad0[16];
    s8 pad1;

    func_80056DD0();
    func_80056C70(((s32)&D_8007D4F0), 1, ((s32)&D_8000BB84), arg0, ((s32)&D_800816A0), 10);
    func_80057530(((s32)&D_8007D4F0));
}
