#include "PR/os_internal.h"
#include "PR/rcp.h"
#include "PR/rdb.h"
/* not in the SDK headers */
extern u8 D_800A1FF0[];
extern u32 D_800777C0;
void send(u8 *, u32);
/* numChars */
         /* debug_buffer */
extern OSThread *D_80077420;/* __osRunningThread */
  /* send */

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
    send((u8 *)addr, length);
}

static void process_command_register(void)
{
    send((u8 *)&D_80077420->context, 0x190);
}

void kdebugserver(rdbPacket packet)
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
