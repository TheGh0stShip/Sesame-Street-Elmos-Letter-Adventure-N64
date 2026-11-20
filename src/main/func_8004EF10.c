/* adds arg1 to every nonzero word in an array of n words */
void func_8004EF10(s32 *p, s32 add, s32 n) {
    s32 i;
    for (i = 0; i < n; i++, p++) {
        if (*p != 0) {
            *p += add;
        }
    }
}
