/* osEPiStartDma (libultra 2.0F src/io/epidma.c) */
typedef struct OSMesgQueue OSMesgQueue;
typedef void *OSMesg;
typedef struct { u16 type; u8 pri; u8 status; OSMesgQueue *retQueue; } OSIoMesgHdr;
typedef struct OSPiHandle OSPiHandle;
typedef struct { OSIoMesgHdr hdr; void *dramAddr; u32 devAddr; u32 size; OSPiHandle *piHandle; } OSIoMesg;
typedef struct { s32 active; } OSDevMgr;
extern OSDevMgr D_80077730; /* __osPiDevMgr */
OSMesgQueue *func_80062CB0(void); /* osPiGetCmdQueue */
s32 func_800615F0(OSMesgQueue *, OSMesg, s32); /* osJamMesg */
s32 func_80057230(OSMesgQueue *, OSMesg, s32); /* osSendMesg */

s32 func_8005E6E0(OSPiHandle *pihandle, OSIoMesg *mb, s32 direction) {
    register s32 ret;

    if (!D_80077730.active) {
        return -1;
    }
    mb->piHandle = pihandle;
    if (direction == 0) {
        mb->hdr.type = 15;
    } else {
        mb->hdr.type = 16;
    }
    if (mb->hdr.pri == 1) {
        ret = func_800615F0(func_80062CB0(), (OSMesg)mb, 0);
    } else {
        ret = func_80057230(func_80062CB0(), (OSMesg)mb, 0);
    }
    return ret;
}
