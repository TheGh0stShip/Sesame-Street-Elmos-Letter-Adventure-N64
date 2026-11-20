#include "common.h"

                      /* extern */
struct Fields_var_arg0
{
  void *unk_0;
  char pad_4[0xc];
  s32 unk_10;
};
extern struct Fields_global_D_800773B4 *D_800773B4;

void func_800540E0(struct Fields_var_arg0 *arg0)
{
  s32 temp_v0_9;
  temp_v0_9 = ((s32 (*)())osSetIntMask)(1);
  arg0->unk_10 = (s32) D_800773B4->unk_20;
  arg0->unk_0 = (void *) D_800773B4->unk_0;
  D_800773B4->unk_0 = arg0;
  ((s32 (*)())osSetIntMask)(temp_v0_9, D_800773B4);
}
