/* __osPiRelAccess: release the PI access queue */
typedef void *OSMesg;
typedef struct OSMesgQueue OSMesgQueue;
extern OSMesgQueue D_8010E4B8; /* __osPiAccessQueue */
s32 func_80057230(OSMesgQueue *mq, OSMesg msg, s32 flag); /* osSendMesg */
void func_80060750(void)
{
    func_80057230(&D_8010E4B8, NULL, 0);
}
