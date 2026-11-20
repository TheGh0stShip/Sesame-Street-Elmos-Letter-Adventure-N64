#include "common.h"

/* osAiGetLength: read AI_LEN_REG */
u32 func_8005D8C0(void) { return *(volatile u32 *)0xA4500004; }
