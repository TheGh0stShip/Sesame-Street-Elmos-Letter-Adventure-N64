#include "PR/os_internal.h"
#include "PR/ultraerror.h"
#include "PR/rcp.h"
#include "PRinternal/osint.h"
/* not in the SDK headers */
extern u8 D_80077710;
s32 func_80061DC0(void);

/* osAiSetNextBuffer */
/* hdwrBugFlag */
 /* __osAiDeviceBusy */
 /* osVirtualToPhysical */
s32 osAiSetNextBuffer(void *bufPtr, u32 size)
{
    char *bptr = bufPtr;
    if (D_80077710 != 0)
        bptr -= 0x2000;
    if ((((u32)bufPtr + size) & 0x1fff) == 0)
        D_80077710 = 1;
    else
        D_80077710 = 0;
    if (func_80061DC0())
        return -1;
    IO_WRITE(0x04500000, osVirtualToPhysical(bptr));
    IO_WRITE(0x04500004, size);
    return 0;
}
