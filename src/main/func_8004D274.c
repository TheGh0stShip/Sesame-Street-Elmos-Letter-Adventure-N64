void func_8004E9E0(void);
extern s32 D_800A00FC;

/* calls 8004E9E0, then latches arg into D_800A00FC if it is unset */
void func_8004D274(s32 arg0) {
    func_8004E9E0();
    if (D_800A00FC == 0) {
        D_800A00FC = arg0;
    }
}
