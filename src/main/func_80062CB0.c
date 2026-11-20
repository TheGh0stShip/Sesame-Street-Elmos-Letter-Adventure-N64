/* returns D_80077738 when D_80077730 is set, else 0 */
extern s32 D_80077730;
extern s32 D_80077738;
s32 func_80062CB0(void)
{
    if (D_80077730 == 0)
        return 0;
    return D_80077738;
}
