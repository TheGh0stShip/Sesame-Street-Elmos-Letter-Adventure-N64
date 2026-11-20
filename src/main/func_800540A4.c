/* if active, shuts down via func_80054310 and clears the two state words */
extern s32 D_800773B0;
extern s32 D_800773B4;
void func_80054310(void);
void func_800540A4(void) {
    if (D_800773B0 != 0) {
        func_80054310();
        D_800773B0 = 0;
        D_800773B4 = 0;
    }
}
