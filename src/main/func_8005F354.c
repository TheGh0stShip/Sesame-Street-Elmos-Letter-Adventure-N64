/* rmon/rdb thread loop: wait for the RDB event, process, acknowledge with a one-byte send */
typedef void *OSMesg;
typedef struct { u8 pad[0x18]; } OSMesgQueue;
extern OSMesgQueue D_800A1FD0;
extern OSMesg D_800A1FE8[1];
extern u8 D_801178A0[];
extern u8 *D_800A7A94;
void func_80056C40(OSMesgQueue *, OSMesg *, s32); /* osCreateMesgQueue */
void func_80057360(s32, OSMesgQueue *, OSMesg); /* osSetEventMesg */
s32 func_80057100(OSMesgQueue *, OSMesg *, s32); /* osRecvMesg */
void func_80063FA0(u8 *);
s32 func_80061AD0(char *, u32, u32); /* __osRdbSend */

void func_8005F354(void)
{
    char buf;
    int sent;

    func_80056C40(&D_800A1FD0, D_800A1FE8, 1);
    func_80057360(0x14, &D_800A1FD0, 0);
    D_800A7A94 = D_801178A0;
    for (;;) {
        func_80057100(&D_800A1FD0, NULL, 1);
        func_80063FA0(D_801178A0);
        D_800A7A94 = D_801178A0;
        sent = 0;
        while (sent <= 0)
            sent += func_80061AD0(&buf, 1, 11);
    }
}
