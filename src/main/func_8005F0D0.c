/* rmonMain: rmon thread loop dispatching break/fault messages */
typedef void *OSMesg;
typedef struct OSMesgQueue_s OSMesgQueue;
extern s32 func_80057100(OSMesgQueue *, OSMesg *, s32); /* osRecvMesg */
extern void func_800647DC(void); /* __rmonInit */
extern void func_80063C04(void); /* __rmonHitBreak */
extern void func_80063CE0(void); /* __rmonHitSpBreak */
extern void func_80063D6C(void); /* __rmonHitCpuFault */
extern OSMesgQueue D_8013EB18;   /* __rmonMQ */
extern int D_80077770;           /* __rmonActive */
extern volatile u32 D_800A1B50;  /* somethingToDo */
extern u32 D_800A1B60[280];      /* inbuffer */
extern u8 D_800A1FC0;            /* cmdinptr */
extern u8 D_800A1FC1;            /* cmdoutptr */
extern int D_800A1FC4;           /* state */
extern char *D_800A1FC8;         /* inPointer */

void func_80060A40(void)
{
    register int newChars;

    D_800A1B50 = 0;
    D_800A1FC1 = 0;
    D_800A1FC0 = 0;

    func_800647DC();
    D_80077770 = 1;

    D_800A1FC4 = 0, newChars = 0, D_800A1FC8 = (void *)&D_800A1B60;
    for (;;) {
        OSMesg work;

        func_80057100(&D_8013EB18, &work, 1);

        D_800A1B50 |= (u32)work;

        if (D_800A1B50 & 2) {
            D_800A1B50 &= ~2;
            func_80063C04();
        }
        if (D_800A1B50 & 4) {
            D_800A1B50 &= ~4;
            func_80063CE0();
        }
        if (D_800A1B50 & 8) {
            D_800A1B50 &= ~8;
            func_80063D6C();
        }
        if (D_800A1B50 & 0x10) {
            D_800A1B50;
            D_800A1B50 &= (u8)~0x10;
        }
        if (D_800A1B50 & 0x20) {
            D_800A1B50;
            D_800A1B50 &= (u8)~0x20;
        }
    }
}
