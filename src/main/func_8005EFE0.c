/* __rmonSendData: send a block to the host word by word (RSP memory read via SP raw IO) */
extern s32 func_80061E80(u32 devAddr, u32 *data); /* __osSpRawReadIo */
extern void func_8005F2F8(u32 w);                 /* __rmonIOputw */
extern void func_800640B0(u8 *dst, u8 *src, u32 n); /* __rmonMemcpy */
extern void func_8005F2BC(void);                  /* __rmonIOflush */

void func_80060950(char *const block, unsigned int blockSize)
{
    int *blockPointer = (int *)block;
    unsigned int wordCount = (u32)(blockSize + 3) / 4;
    u32 data;
    union {
        char bufBytes[4];
        u32 bufWord;
    } buffer;

    if (((u32)block & 3) == 0) {
        while (wordCount--) {
            if ((u32)blockPointer >= 0x04000000 && (u32)blockPointer < 0x05000000) {
                func_80061E80((u32)blockPointer++, &data);
                func_8005F2F8(data);
            } else {
                func_8005F2F8(*(blockPointer++));
            }
        }
    } else
        while (wordCount--) {
            func_800640B0((u8 *)buffer.bufBytes, (u8 *)blockPointer, sizeof(buffer));
            func_8005F2F8(buffer.bufWord);
            blockPointer++;
        }
    func_8005F2BC();
}
