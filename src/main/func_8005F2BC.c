/* Wait until one byte has been sent over rdb (__osRdbSend). */
s32 func_80061AD0(u8 *buf, u32 size, u32 type); /* __osRdbSend */
void func_8005F2BC(void) {
    u8 buf[4];
    s32 sent = 0;
    do {
        sent += func_80061AD0(buf, 1, 10);
    } while (sent <= 0);
}
