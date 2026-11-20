/* osPiStartDma */
typedef void *OSMesg;
typedef struct OSMesgQueue_s OSMesgQueue;
typedef struct {
    u16 type;
    u8 pri;
    u8 status;
    OSMesgQueue *retQueue;
} OSIoMesgHdr;
typedef struct {
    OSIoMesgHdr hdr;
    void *dramAddr;
    u32 devAddr;
    u32 size;
    void *piHandle;
} OSIoMesg;
typedef struct {
    s32 active;
} OSDevMgr;
extern OSDevMgr D_80077730; /* __osPiDevMgr */
OSMesgQueue *func_80062CB0(void); /* osPiGetCmdQueue */
s32 func_800615F0(OSMesgQueue *, OSMesg, s32); /* osJamMesg */
s32 func_80057230(OSMesgQueue *, OSMesg, s32); /* osSendMesg */

s32 func_8005EE10(OSIoMesg *mb, s32 priority, s32 direction, u32 devAddr, void *dramAddr, u32 size, OSMesgQueue *mq)
{
    register s32 ret;

    if (!D_80077730.active)
        return -1;
    if (direction == 0)
        mb->hdr.type = 11;
    else
        mb->hdr.type = 12;
    mb->hdr.pri = priority;
    mb->hdr.retQueue = mq;
    mb->dramAddr = dramAddr;
    mb->devAddr = devAddr;
    mb->size = size;
    mb->piHandle = NULL;
    if (priority == 1)
        ret = func_800615F0(func_80062CB0(), (OSMesg)mb, 0);
    else
        ret = func_80057230(func_80062CB0(), (OSMesg)mb, 0);
    return ret;
}
