#include "common.h"

/* __osPiRelAccess: release the PI access queue */

typedef struct OSMesgQueue OSMesgQueue;
extern OSMesgQueue D_8010E4B8; /* __osPiAccessQueue */
s32 osSendMesg(OSMesgQueue *mq, OSMesg msg, s32 flag); /* osSendMesg */
void func_8005EDE0(void)
{
    osSendMesg(&D_8010E4B8, NULL, 0);
}
