/* osLeoDiskInit */
typedef struct { u8 data[0x60]; } __OSTranxInfo;
typedef struct OSPiHandle_s {
    struct OSPiHandle_s *next;
    u8 type, latency, pageSize, relDuration, pulse, domain;
    u32 baseAddress;
    u32 speed;
    __OSTranxInfo transferInfo;
} OSPiHandle;
extern OSPiHandle D_8012EFE0;    /* LeoDiskHandle */
extern OSPiHandle *D_801068A4;   /* __osDiskHandle */
extern OSPiHandle *D_8007774C;   /* __osPiTable */
void func_8005F410(void *p, s32 len);        /* bzero */
u32 func_800612F0(void);                     /* __osDisableInt */
void func_80061310(u32 mask);                /* __osRestoreInt */

#define IO_WRITE(a, v) (*(volatile u32 *)(a) = (v))

OSPiHandle *func_8005E860(void) {
    u32 saveMask;

    D_8012EFE0.type = 2;
    D_8012EFE0.baseAddress = 0xA5000000;
    D_8012EFE0.latency = 3;
    D_8012EFE0.pulse = 6;
    D_8012EFE0.pageSize = 6;
    D_8012EFE0.relDuration = 2;
    D_8012EFE0.domain = 1;

    IO_WRITE(0xA4600024, D_8012EFE0.latency);
    IO_WRITE(0xA4600028, D_8012EFE0.pulse);
    IO_WRITE(0xA460002C, D_8012EFE0.pageSize);
    IO_WRITE(0xA4600030, D_8012EFE0.relDuration);
    D_8012EFE0.speed = 0;

    func_8005F410(&D_8012EFE0.transferInfo, sizeof(__OSTranxInfo));

    saveMask = func_800612F0();
    D_8012EFE0.next = D_8007774C;
    D_8007774C = &D_8012EFE0;
    D_801068A4 = &D_8012EFE0;
    func_80061310(saveMask);

    return &D_8012EFE0;
}
