#include "PRinternal/macros.h"
#include "PR/os_internal.h"
/* not in the SDK headers */
extern s32 D_80077760;
extern OSMesg D_800A1B40[1];
          /* __osPiAccessQueueEnabled */
extern OSMesgQueue D_8010E4B8;   /* osRecvMesg */
static void __osPiCreateAccessQueue(void) {
    D_80077760 = 1;
    osCreateMesgQueue(&D_8010E4B8, D_800A1B40, 1);
    osSendMesg(&D_8010E4B8, NULL, 0);
}
void __osPiGetAccess(void) {
    OSMesg dummyMesg;
    if (!D_80077760) {
        __osPiCreateAccessQueue();
    }
    osRecvMesg(&D_8010E4B8, &dummyMesg, 1);
}
