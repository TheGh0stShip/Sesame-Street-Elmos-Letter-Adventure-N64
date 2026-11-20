/* __osRdbSend (os/rdbsend.c): send bytes to the debugger over the RDB port */
typedef struct {
    unsigned type : 6;
    unsigned length : 2;
    u8 buf[3];
} rdbPacket;

extern rdbPacket *D_8013C5B8;   /* __osRdb_IP6_Data */
extern u32 D_80107918;          /* __osRdb_IP6_Size */
extern u32 D_8013EB84;          /* __osRdb_IP6_Ct */
extern u32 D_800ACBF8;          /* __osRdb_IP6_CurWrite */
extern u32 D_800777D0;          /* __osRdb_IP6_Empty */

u32 func_800612F0(void);        /* __osDisableInt */
void func_80061310(u32 mask);   /* __osRestoreInt */

#define MIN(a, b) (((a) < (b)) ? (a) : (b))

u32 func_80061AD0(u8 *buf, u32 size, u32 type) {
    rdbPacket *pPtr;
    rdbPacket pkt;
    u32 len;
    u32 c;
    u32 inCt = 0;
    u32 needFirst = 0;
    u32 mask;
    u32 sent = 0;

    mask = func_800612F0();

    if (D_800777D0 != 0) {
        D_800777D0 = 0;
        pkt.type = type;

        len = MIN(size, sizeof(pkt.buf));

        pkt.length = len;

        c = 0;
        while (c < len) {
            pkt.buf[c++] = buf[inCt++];
        }

        size -= len;
        sent = len;
        needFirst = 1;
    }

    while (size != 0 && D_8013EB84 < D_80107918) {
        len = MIN(size, sizeof(pPtr->buf));

        pPtr = &D_8013C5B8[D_800ACBF8];

        pPtr->type = type;
        pPtr->length = len;

        c = 0;
        while (c < len) {
            pPtr->buf[c++] = buf[inCt++];
        }

        D_800ACBF8++;
        if (D_800ACBF8 >= D_80107918) {
            D_800ACBF8 = 0;
        }

        D_8013EB84++;
        size -= len;
        sent += len;
    }

    if (needFirst) {
        *(u32 *)0xC0000000 = *(u32 *)&pkt;
    }
    func_80061310(mask);

    return sent;
}
