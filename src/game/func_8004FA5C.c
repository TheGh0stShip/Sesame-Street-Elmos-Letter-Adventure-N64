#include "common.h"

void *func_8004FA5C(void *arg0, u8 *arg1)
{
  (*(u8 *)((s8 *)(arg0) + (0xD3))) = (u8) (*arg1);
  (*(s8 *)((s8 *)(arg0) + (0xD2))) = 0;
  return arg1 + 1;
}
