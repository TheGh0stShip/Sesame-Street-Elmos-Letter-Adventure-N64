extern u32 func_80061AD0(u8 *, u32, s32);
void func_8005F260(u8 *buf)
{
    volatile s32 pad;
    u32 done;
    u8 *p;
    done = 0;
    pad = 0;
    p = buf;
    do {
        done += func_80061AD0(p + done, 0x1B0 - done, 2);
    } while (done < 0x1B0);
}
