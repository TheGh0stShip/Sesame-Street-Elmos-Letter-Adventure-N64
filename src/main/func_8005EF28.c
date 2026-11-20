/* __rmonSendReply (with __rmonSendHeader inlined) */
typedef struct {
    s32 length;
    u8 unk_4;
    u8 type;
    u8 unk_6;
    u8 unk_7;
    u8 rev;
} KKHeader;
s32 func_80061AD0(char *, u32, u32); /* __osRdbSend */
void func_8005F2BC(void); /* __rmonIOflush */

static inline void __rmonSendHeader(KKHeader *const block, u32 blockSize, u32 type)
{
    int sent;
    char *cPtr = (char *)block;

    block->rev = 2;
    block->type = type;
    sent = 0;
    while (sent < blockSize)
        sent += func_80061AD0(cPtr + sent, blockSize - sent, 8);
}

void func_8005EF28(KKHeader *const block, u32 blockSize, u32 replyType)
{
    char *cPtr;
    int sent = 0;

    block->length = blockSize;
    cPtr = (char *)&blockSize;
    while (sent < (int)sizeof(blockSize))
        sent += func_80061AD0(cPtr + sent, sizeof(blockSize) - sent, 8);
    __rmonSendHeader(block, blockSize, replyType);
    func_8005F2BC();
}
