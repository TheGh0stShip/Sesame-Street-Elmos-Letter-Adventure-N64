/* kdebugserver: collect rdb packet bytes, run register/memory commands */
typedef struct { unsigned type : 6; unsigned length : 2; char buf[3]; } rdbPacket;
typedef struct { u8 unk_00[0x20]; u8 context[0x190]; } OSThread;
extern u32 D_800777C0;          /* numChars */
extern u8 D_800A1FF0[];         /* debug_buffer */
extern OSThread *D_80077420;    /* __osRunningThread */
void func_80061730(u8 *, u32);  /* send */

static u32 string_to_u32(u8 *s)
{
    u32 k;
    k = ((s[0] & 0xFF) << 24);
    k |= ((s[1] & 0xFF) << 16);
    k |= ((s[2] & 0xFF) << 8);
    k |= (s[3] & 0xFF);
    return k;
}

static void process_command_memory(void)
{
    u32 addr = string_to_u32(&D_800A1FF0[1]);
    u32 length = string_to_u32(&D_800A1FF0[5]);
    func_80061730((u8 *)addr, length);
}

static void process_command_register(void)
{
    func_80061730((u8 *)&D_80077420->context, 0x190);
}

void func_800618D8(rdbPacket packet)
{
    u32 i;

    for (i = 0; i < 3; i++) {
        D_800A1FF0[D_800777C0++] = packet.buf[i];
    }
    if (D_800A1FF0[0] == 2) {
        process_command_register();
        D_800777C0 = 0;
    } else if (D_800777C0 >= 9 && D_800A1FF0[0] == 1) {
        process_command_memory();
        D_800777C0 = 0;
    }
}
