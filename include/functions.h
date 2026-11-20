#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "structs.h"


void func_8000DD40(s32, s32);
extern void func_800013B0(void);
extern void func_800016C0(void);
extern void func_80001F60(void);
extern void func_80003D08(void);
extern void func_80004010(s32);
extern void func_80012164(s32);
extern void func_8001A318(void);
extern void func_80040304(s32);


void func_8000BC64(void *);
void func_80012FA0(void *arg);
void func_8000C164(void);
void func_80001000(void);

s32 func_800683D0(void);
void func_80068404(s32);







extern s32 func_80017084(u8);





void func_80047C00(s32);
void func_8001D9D0(s32);
void func_8001A12C(void);
void func_80012998(void);




s32 func_80047FB0(s32, s32, f32, f32);
s32 func_80049848(s32, s32, s32, s32, s32, f32);









f64 fabs(f64);


s32 player_text_329C();




extern void D_80050DD8(void *);
u32 func_8005D8C0(void);
s16 _getRate(f64 vol, f64 tgt, s32 count, u16 *ratel);




void func_80061238(void);
u32 func_80061260(void);
void __osSetSR(u32);
void __osSetFpcCsr(u32);
s32 __osSiRawReadIo(u32, u32 *);
s32 __osSiRawWriteIo(u32, u32);
void osMapTLBRdb(void);
void __osDispatchThread(void);
u32 __osProbeTLB(void *);
u32 func_80059460(void *);
f32 func_80059C7C(f32 ivol, s32 samples, s16 ratem, u16 ratel);

s32 alEnvmixerParam(void *f, s32 id, void *p);
void func_8005B6F0(void *, s32);
s32 func_80061DC0(void);
void __osSiGetAccess(void);
void func_80062BB0(void);
void __osPackReadData(void);
s32 __osSiRawStartDma(s32, void *);
void __osSiCreateAccessQueue(void);
void __osContGetInitData(u8 *, OSContStatus *);
void __osPackRequestData(u8);
OSTime func_800586B0(void);
s32 func_800643C0(s32, void *);
void func_80064460(void);
void func_8005FA0C(u8 *, OSContStatus *);
void __osPiCreateAccessQueue(void);
s32 func_80062BE0(s32, u32, void *, u32);
void __osDevMgrMain(void *);
void __osPiGetAccess(void);
void func_8005EDE0(void);
extern void __osSetGlobalIntMask(u32);
extern void osYieldThread(void);
extern void __rmonIOputw(u32 w);
extern void __rmonInit(void);
extern void __rmonHitBreak(void);
extern void __rmonHitSpBreak(void);
extern void __rmonHitCpuFault(void);
void osCreateViManager(OSPri pri);
void __scMain(void *arg);

#ifndef _ULTRA64_H_
void osSpTaskLoad(OSTask *);
#endif
s32 osDpSetNextBuffer(void *, u64);
void func_80062110(void);
extern u32 __osGetCause(void);
void send(u8 *, u32);

s32 func_80066AB0(void);
#ifndef _ULTRA64_H_
void bcopy(void *src, void *dst, s32 len);
#endif
s32 __osSpSetPc(u32 pc);
s32 __osSpRawStartDma(s32 dir, u32 devAddr, void *dramAddr, u32 size);
extern u32 func_80066AF0(void);
void __osViSwapContext(void);
void __osTimerServicesInit(void);
void __osViInit(void);
void viMgrMain(void *arg);
void __osTimerInterrupt(void);
void __osLeoAbnormalResume(void);
void __osLeoResume(void);
void func_80066DEC(int);
void func_80065708(void);

u32 func_800659E0(u32 *addr);
void func_800659A0(u32 *addr, u32 val);
void rmonFindFaultedThreads(void);
void __rmonMaskIdleThreadInts(void);
s32 __osSpRawWriteIo(u32 addr, u32 val);

void __rmonIdleRCP(void);

void __rmonRunRCP(void);
void *func_80060E7C(void *, const void *, size_t);
f64 __floatdidf(s64);
u64 __fixdfdi(f64);
f64 func_80067E98(f64 x);
void func_8006AE84(void *ctx, s16 a, s16 b, void *m);

/* unified declarations (work/ph_unify.py): one per name; files no longer declare these */
f32 __cosf(f32);
u32 __osDisableInt(void);
u32 __osGetCount(void);
void __osResetGlobalIntMask(s32);
void __osRestoreInt(u32);
void __osSetCompare(u32);
void __osSetTimerIntr(OSTime);
s32 __osSpRawReadIo(u32, u32 *);
void __rmonCopyWords(u32 *, u32 *, s32);
u32 __rmonGetBranchTarget(int, int, char *);
u32 __rmonGetRegisterContents(s32, s32, s32);
void __rmonIOflush(void);
void __rmonIOhandler(void);
s32 __rmonRCPrunning(void);
void __rmonSendData(char *const, unsigned int);
void __rmonSendFault(u8 *);
s32 __rmonSetSingleStep(s32, u32 *);
void __rmonStepRCP(void);
f32 __sinf(f32);
u64 __udivdi3(u64, u64);
s32 _getVol(s32, s32, s16, s32);
void addActorDL(s32, s32, s32, s32, f32);
void alCopy(void *, void *, s32);
s32 alFxParamHdl(void *, s32, void *);
s32 alLoadParam(void *, s32, void *);
s32 alResampleParam(void *, s32, void *);
#ifndef _ULTRA64_H_
void alUnlink(struct Struct_func_80054B1C_arg0 *);
#endif
#ifndef _ULTRA64_H_
void bzero(void *, s32);
#endif
void func_80000450(s32, s32, register s32, s32, s32);
s32 func_8000092C(s32, s32, s32, s32, f32, f32, f32, s32, s32);
void func_80000EDC(u32 *, u32 *, u32);
void func_80000F60(void);
void func_80001818(void *);
void func_80001AB4(s32);
void func_80001D38(s32);
void func_80001EE8(void);
void func_800030A0(void);
void func_80003F60(void);
void func_8000A7F0(s32);
void func_8000BA70(s32);
void func_8000C0E0(s32, s32, s32);
void func_8000CF50(void);
void func_8000D810(s32, s32, s32, s32, s32);
s32 func_8000DB30(s32, u8);
s32 func_8000DBC0(void);
void func_8000DCFC(s32);
void func_8000DD7C(s32, s32);
void func_8000DDF4(u8, u8, u8, u8);
void func_8000DE60(s32);
void func_8000DEBC(s32);
s32 func_8000E010(s32, s32);
void func_8000E7A0(u8);
void func_8000E940(s32);
void func_800110E4(Effect *);
void func_80011D50(s32, s32, s32);
s32 func_80012A08(void);
void func_80012AA4(s32);
s32 func_80012B60(s32);
void func_80012D30(void);
s32 func_8001375C(s32, s32, s32);
s32 func_8001384C(s32, s32, s32);
s32 func_80013AD8(struct IB *, struct ZS *, s32);
s32 func_80014E98(s32, s32, s32, s32);
s32 func_80014F10(s32, s32, s32);
s32 func_8001602C(uInt *, uInt, uInt, uInt *, uInt *, inflate_huft * *, uInt *, inflate_huft *, uInt *, uInt *);
s32 func_800168C4(s32, s32, s32, s32);
s32 func_8001694C(s32, s32, s32, s32, s32, s32, s32, s32);
s32 func_80016A74(s32, s32, s32, s32);
void func_800170B0(void);
void func_80017318(s32, s32, s32);
void func_80017448(s32);
void func_800174AC(void);
void func_80017520(s32, s32);
s32 func_80017568(s32);
void func_80017790(s32, s32);
void func_80017B28(s32);
void func_80018278(s32);
s32 func_80018530(s32, s32);
void func_80018840(void);
void func_8001892C(s32, s32, register s32, register s32);
void func_8001CAA8(s32, s32);
void func_8001D8E0(s32);
void func_8001DD10(s32, s32);
void func_8001DE6C(s32, s32, s32, s32, s32);
s32 func_8001E100(Seg *);
s32 func_8001E314(s32, f32, f32, f32);
s32 func_8001E7EC(s32, s32);
void func_8001F1C8(s32, s32, s32, s32, s32);
void func_8001F300(s32);
void func_8001F490(f32 (*)[4], AnimTrack *, u32);
void func_80020A24(s32, s32, s32, s32, s32);
s32 func_80020D30(void);
s32 func_80020EB4(s32);
void func_80021110(s32);
void func_800229DC(void);
void func_80022C6C(void *);
f64 func_80022D8C(s32);
void func_80023118(s32);
void func_800246EC(s32);
void func_80024C1C(s32);
void func_80024E20(s32);
void func_80025134(s32, s32, s32);
s32 func_80025504(s32);
s32 func_800258A4(s32, s32, s32, s32);
void func_80025C6C(s32, f64);
void func_80026920(s32);
void func_80026ABC(s32);
void func_80026AF8(s32);
void func_80026B34(s32);
void func_80026B70(s32, s32, s32);
s32 func_80029FB0(s32, f32, f32, f32);
void func_8002A120(s32);
void func_8002BADC(s32);
void func_8002BEF0(s32, s32);
void func_8002CF14(register f32);
void func_8002E140(void);
void func_800302B8(s32);
void func_80030A7C(s32);
void func_80030D8C(s32);
void func_800310D0(s32);
void func_800314C0(s32);
void func_80031744(s32, s32);
void func_800317C0(s32, s32);
void func_80031918(s32, s32, s32, s32);
Word *func_80031BB4(s32, s32, s32, s32);
LetterSet *func_800323F4(s32);
void func_800326E0(s32, s32);
void func_8003279C(s32);
void func_800327E0(s32);
s32 func_80032818(s32, register s32, s32);
void func_8003322C(s32, s32, s32);
void func_80034CD0(s32);
void func_800356D0(s32, s32);
void func_80035750(s32);
void func_80035788(s32);
void func_80035828(s32, s32);
void func_80035A28(void);
void func_8003A568(s32);
void func_8003BB00(s32);
void func_8003E220(s32);
void func_8003E3E0(s32, f32, f32, f32, s32);
void func_8003EF84(s32);
void func_8003FDD0(s32);
void func_8003FE00(s32, s32, s32, s32);
s32 func_8004002C(s32, u16, u16);
void func_80040190(s32, s32);
void func_80040284(s32);
void func_8004038C(s32);
s32 func_80040400(s32);
void func_80040680(s32);
void func_800409A0(void);
void func_800409C8(s32, s32);
f32 func_80040B00(s32, s32);
void func_80041230(s32, s32);
void func_800414F0(s32);
void func_8004166C(s32);
void func_80041810(s32);
void func_80041B4C(s32);
void func_80042398(s32, s32, s32);
void func_8004256C(s32, s32, s32);
void func_800426C8(s32);
void func_80042720(s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32);
void func_800445D0(s32, s32, s32, s32);
void func_80044910(s32, s32);
void func_80044B90(s32, s32);
void func_80044E3C(s32, s32, s32);
void func_80047CF8(s32, s32, s32, s32);
void func_80047ED4(s32);
void func_80047F60(s32);
void func_80048174(s32, s32);
void func_800483A0(s32);
void func_80048958(s32, s32);
void func_80048AB8(s32);
void func_80049A24(s32);
s32 func_80049C08(s32, s32);
void func_80049C6C(s32);
void func_80049CF8(s32, s32);
f32 func_80049E68(f32, f32);
void func_8004A294(s32, s32, s32);
void func_8004A32C(s32, f32);
void func_8004A35C(s32, f32);
s32 func_8004A6E4(s32);
s32 func_8004B0E0(s32, s32, s32, s32, s32, f32, f32, f32, f32);
s32 func_8004B234(s32);
void func_8004B470(s32, f32, f32, s32);
s32 func_8004B568(s32, f32, f32, f32);
s32 func_8004B980(s32, s32, s32, s32);
s32 func_8004C0B0(s32);
void func_8004C36C(s32, s32, s32);
void func_8004C490(s32, s32);
void func_8004C6FC(Config *);
s32 func_8004CC30(s32);
s32 func_8004CCB0(s32, s32, s32, s32, s32);
void func_8004CDC8(s32, s32);
s32 func_8004CF14(s32, s32);
s32 func_8004CFC8(s32);
s32 func_8004D020(s32, s16);
s32 func_8004D080(s32, s16);
s32 func_8004D0F0(s32, f32);
s32 func_8004D1EC(s32, s32);
void func_8004D274(s32);
void *func_8004D2B0(void *);
void func_8004D43C(RelHdr *);
s32 func_8004EB78(s32);
DmaBuf *func_8005095C(u32, s32);
void func_80050CA0(Params *, s32, u8);
void func_80057BD0(const char *, const char *, int);
s32 func_8005A4B4(s32 *, s32, s32);
void func_8005B6F8(struct Struct_func_8005B6F8_arg0 *, s32, s32);
u32 func_8005D8D0(void);
int func_80062A30(void);
s32 func_800669E0(void);
int func_80066AD0(void);
void func_80066B00(s32);
s32 func_80066C20(void);
f64 func_80067B60(f64);
f64 func_80067FB0(f64, f64);
f64 func_80068120(f64);
f64 func_800681A8(f64, f64);
void *func_80068300(void *, s32, u32);
f64 func_80068880(f64);
void guLookAtF(float (*)[4], float, float, float, float, float, float, float, float, float);
void guMtxCatF(float (*)[4], float (*)[4], float (*)[4]);
void guMtxXFMF(float (*)[4], float, float, float, float *, float *, float *);
void guNormalize(float *, float *, float *);
void guPerspectiveF(f32 (*)[4], u16 *, f32, f32, f32, f32, f32);
void *kmc_proutSyncPrintf(void *, const u8 *, int);
void *memcpy(void *, const void *, u32);
#ifndef _ULTRA64_H_
void osContGetReadData(OSContPad *);
#endif
#ifndef _ULTRA64_H_
void osCreateMesgQueue(struct Struct_func_80051C04_arg3_at_24 *, s32, s32);
#endif
u64 osGetTime(void);
#ifndef _ULTRA64_H_
void osInitRdb(u32, u32);
#endif
void osInitialize(void);
#ifndef _ULTRA64_H_
s32 osInvalDCache();
#endif
void osInvalICache(void *, s32);
s32 osPiGetCmdQueue(void);
s32 osPiRawReadIo(s32, s32 *);
#ifndef _ULTRA64_H_
void osSetEventMesg(s32, void *, void *);
#endif
OSIntMask osSetIntMask(OSIntMask);
#ifndef _ULTRA64_H_
void osSpTaskStartGo(void *);
#endif
void osViBlack(u8);
#ifndef _ULTRA64_H_
s32 osViGetCurrentFramebuffer(void);
#endif
#ifndef _ULTRA64_H_
s32 osViGetNextFramebuffer(void);
#endif
#ifndef _ULTRA64_H_
void osViSetEvent(s32, s32, s32);
#endif
#ifndef _ULTRA64_H_
void osViSetMode(void *);
#endif
void osViSetSpecialFeatures(u32);
#ifndef _ULTRA64_H_
void osViSwapBuffer(s32);
#endif
u32 osVirtualToPhysical(void *);
void osWritebackDCache(void *, s32);
void osWritebackDCacheAll(void);
s32 proutSyncPrintf(void *, u8 *, u32);
void ramromMain(void);
u32 rmonGetRcpRegister(int);
#ifndef _ULTRA64_H_
void rmonMain(void);
#endif
#ifndef _ULTRA64_H_
s32 sprintf(char *, const char *, ...);
#endif
f32 sqrtf(f32);
const u8 *strchr(const u8 *, s32);
u32 strlen(const u8 *);

#include "libmus/player.h" /* sm */
#include "codec/stream.h" /* sm */
extern double sin(double);
extern double cos(double);
#include "libc/libc.h" /* sm */
#endif
