#include "common.h"

/* __osPiRelAccess: release the PI access queue */

typedef struct OSMesgQueue OSMesgQueue;
extern OSMesgQueue D_8013EF50; /* __osPiAccessQueue */
s32 osSendMesg(OSMesgQueue *mq, OSMesg msg, s32 flag); /* osSendMesg */
void func_80062BB0(void)
{
    osSendMesg(&D_8013EF50, NULL, 0);
}
