/* osCartRomInit (pre-2.0J form) */
typedef struct { u8 data[0x60]; } __OSTranxInfo;
typedef struct OSPiHandle_s {
    struct OSPiHandle_s *next;
    u8 type, latency, pageSize, relDuration, pulse, domain;
    u32 baseAddress;
    u32 speed;
    __OSTranxInfo transferInfo;
} OSPiHandle;
extern OSPiHandle D_8013EA98;    /* CartRomHandle */
extern OSPiHandle *D_8007774C;   /* __osPiTable */
s32 func_8005E210(u32 devAddr, u32 *data);   /* osPiRawReadIo */
void func_8005F410(void *p, s32 len);        /* bzero */
u32 func_800612F0(void);                     /* __osDisableInt */
void func_80061310(u32 mask);                /* __osRestoreInt */

OSPiHandle *func_8005E780(void) {
    u32 domain = 0;
    u32 saveMask;

    if (D_8013EA98.baseAddress == 0xB0000000)
        return &D_8013EA98;

    D_8013EA98.type = 0;
    D_8013EA98.baseAddress = 0xB0000000;
    func_8005E210(0, &domain);
    D_8013EA98.latency = domain & 0xff;
    D_8013EA98.pulse = (domain >> 8) & 0xff;
    D_8013EA98.pageSize = (domain >> 0x10) & 0xf;
    D_8013EA98.relDuration = (domain >> 0x14) & 0xf;
    D_8013EA98.domain = 0;
    D_8013EA98.speed = 0;

    func_8005F410(&D_8013EA98.transferInfo, sizeof(__OSTranxInfo));

    saveMask = func_800612F0();
    D_8013EA98.next = D_8007774C;
    D_8007774C = &D_8013EA98;
    func_80061310(saveMask);

    return &D_8013EA98;
}
