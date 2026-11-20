#include "common.h"
#include "libmus/player.h"


void MusPtrBankSetCurrent(struct ptr_bank_s *arg0)
{
  if ((arg0 != NULL) && (arg0->flags < 0))
  {
    D_800A00FC = arg0;
  }
}
