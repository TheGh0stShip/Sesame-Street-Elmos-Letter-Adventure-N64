#include "PRinternal/macros.h"
#include "PR/os_internal.h"
/* not in the SDK headers */
extern OSMesg D_800A3280[1];
extern s32 D_800785A0;
          /* __osPiAccessQueueEnabled */
extern OSMesgQueue D_8013EF50;   /* osRecvMesg */
static void __osPiCreateAccessQueue(void) {
    D_800785A0 = 1;
    osCreateMesgQueue(&D_8013EF50, D_800A3280, 1);
    osSendMesg(&D_8013EF50, NULL, 0);
}
void __osSiGetAccess(void) {
    OSMesg dummyMesg;
    if (!D_800785A0) {
        __osPiCreateAccessQueue();
    }
    osRecvMesg(&D_8013EF50, &dummyMesg, 1);
}
