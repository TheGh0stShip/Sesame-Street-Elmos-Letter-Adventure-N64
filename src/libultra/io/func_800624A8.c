#include "PRinternal/macros.h"
#include "PR/os_internal.h"
#include "PR/ultraerror.h"
#include "PR/rcp.h"
#include "PRinternal/viint.h"
#include "PRinternal/osint.h"
/* not in the SDK headers */
u32 __osGetCount(void);
extern u16 D_800A2060;
s32 func_80066C20(void);


void viMgrMain(void *arg)
{
    __OSViContext *vc;
    OSDevMgr *dm;
    OSIoMesg *mb;
    s32 first;
    u32 count;

    mb = NULL;
    first = 0;
    vc = func_80066C20();
    D_800A2060 = vc->retraceCount;
    if (D_800A2060 == 0) {
        D_800A2060 = 1;
    }
    dm = (OSDevMgr *)arg;

    while (1) {
        osRecvMesg(dm->evtQueue, (OSMesg *)&mb, 1);
        switch (mb->hdr.type) {
            case 13:
                __osViSwapContext();
                D_800A2060--;
                if (D_800A2060 == 0) {
                    vc = func_80066C20();
                    if (vc->msgq != NULL) {
                        osSendMesg(vc->msgq, vc->msg, 0);
                    }
                    D_800A2060 = vc->retraceCount;
                }
                __osViIntrCount++;
                if (first) {
                    count = __osGetCount();
                    __osCurrentTime = count;
                    first = 0;
                }
                count = __osBaseCounter;
                __osBaseCounter = __osGetCount();
                count = __osBaseCounter - count;
                __osCurrentTime = __osCurrentTime + count;
                break;
            case 14:
                __osTimerInterrupt();
                break;
            default:
                break;
        }
    }
}
