#include "PRinternal/macros.h"
#include "PR/os_internal.h"
#include "PR/ultraerror.h"
#include "PRinternal/piint.h"
#include "PR/rdb.h"
/* not in the SDK headers */
void func_8005EDE0(void);
extern char D_800A1B18[];
extern char D_800A1B00[];
extern char D_800A1AE0[];
extern char D_800A1AF8[];

void ramromMain(void)
{
    u8 buf[8];
    s32 n;

    osCreateMesgQueue(D_800A1AE0, D_800A1AF8, 1);
    osCreateMesgQueue(D_800A1B00, D_800A1B18, 1);
    osSetEventMesg(0x12, D_800A1AE0, 0);
    osSetEventMesg(0x13, D_800A1B00, 0);
    for (;;) {
        osRecvMesg(D_800A1AE0, 0, 1);
        __osPiGetAccess();
        n = 0;
        do {
            n += __osRdbSend(buf, 1, 9);
        } while (n == 0);
        osRecvMesg(D_800A1B00, 0, 1);
        func_8005EDE0();
    }
}
