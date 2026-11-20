/* set D_80077760, then call two setup routines on D_8010E4B8 */
extern s32 D_80077760;
extern s32 D_8010E4B8[];
extern s32 D_800A1B40[];
void func_80056C40(void *, void *, s32);
void func_80057230(void *, s32, s32);
void func_8005ED20(void)
{
    D_80077760 = 1;
    func_80056C40(D_8010E4B8, D_800A1B40, 1);
    func_80057230(D_8010E4B8, 0, 0);
}
