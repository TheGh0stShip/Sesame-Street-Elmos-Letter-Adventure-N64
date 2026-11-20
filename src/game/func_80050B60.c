#include "common.h"

extern Sys *D_800A0174;
s32 osRecvMesg(void *mq, void *msg, s32 flag);
/* receive messages until one whose first halfword is 1 */
void func_80050B60(void) {
    s16 *msg;
    do {
        osRecvMesg(D_800A0174->mq, &msg, 1);
        osRecvMesg(D_800A0174->mq, NULL, 0);
    } while (*msg != 1);
}
