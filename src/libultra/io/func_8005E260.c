#include "PRinternal/macros.h"
#include "PR/os_internal.h"
#include "PR/ultraerror.h"
#include "PRinternal/piint.h"
#include "PR/rdb.h"
/* not in the SDK headers */
extern u64 D_800A16E0[0x400 / 8];
extern OSMesg D_800A1B38[];
void ramromMain(void);
s32 func_80062BE0(s32, u32, void *, u32);
extern u64 D_800A0530[0x1000 / 8];
       /* __osPiAccessQueue */
extern OSThread piThread;/* piThread */
   /* piThreadStack */
extern OSThread ramromThread;/* ramromThread */
    /* ramromThreadStack */
extern OSMesgQueue piEventQueue;/* piEventQueue */
          /* piEventBuf */

/* osCreateMesgQueue */
                                          /* __osPiCreateAccessQueue */
                    /* osSetEventMesg */
OSPri func_800615D0(OSThread *);/* __osEPiRawStartDma */
                                        /* __osDevMgrMain */
                                        /* ramromMain */

void osCreatePiManager(OSPri pri, OSMesgQueue *cmdQ, OSMesg *cmdBuf, s32 cmdMsgCnt) {
    u32 savedMask;
    OSPri oldPri;
    OSPri myPri;

    if (__osPiDevMgr.active) {
        return;
    }
    osCreateMesgQueue(cmdQ, cmdBuf, cmdMsgCnt);
    osCreateMesgQueue(&piEventQueue, D_800A1B38, 1);

    if (!__osPiAccessQueueEnabled) {
        __osPiCreateAccessQueue();
    }

    osSetEventMesg(8, &piEventQueue, (OSMesg)0x22222222);
    oldPri = -1;
    myPri = func_800615D0(NULL);

    if (myPri < pri) {
        oldPri = myPri;
        osSetThreadPri(NULL, pri);
    }

    savedMask = __osDisableInt();
    __osPiDevMgr.active = 1;
    __osPiDevMgr.thread = &piThread;
    __osPiDevMgr.cmdQueue = cmdQ;
    __osPiDevMgr.evtQueue = &piEventQueue;
    __osPiDevMgr.acsQueue = &__osPiAccessQueue;
    __osPiDevMgr.dma = func_80062BE0;
    __osPiDevMgr.edma = osEPiRawStartDma;
    osCreateThread(&piThread, 0, __osDevMgrMain, &__osPiDevMgr, (u8 *)D_800A0530 + sizeof(D_800A0530), pri);
    osStartThread(&piThread);

    osCreateThread(&ramromThread, 0, ramromMain, NULL, (u8 *)D_800A16E0 + sizeof(D_800A16E0), pri - 1);
    osStartThread(&ramromThread);
    __osRestoreInt(savedMask);

    if (oldPri != -1) {
        osSetThreadPri(NULL, oldPri);
    }
}
