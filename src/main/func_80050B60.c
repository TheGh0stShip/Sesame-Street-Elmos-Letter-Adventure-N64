typedef struct { u8 pad[8]; u8 mq[1]; } Sys;
extern Sys *D_800A0174;
s32 func_80057100(void *mq, void *msg, s32 flag);
/* receive messages until one whose first halfword is 1 */
void func_80050B60(void) {
    s16 *msg;
    do {
        func_80057100(D_800A0174->mq, &msg, 1);
        func_80057100(D_800A0174->mq, NULL, 0);
    } while (*msg != 1);
}
