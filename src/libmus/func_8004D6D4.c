#include "common.h"
#include "libmus/player.h"

/* pushes an 8-byte message onto a ring buffer; returns 0 when full */
/* head */
/* tail */
 /* size */
/* buffer */
 /* memcpy */
s32 func_8004D6D4(mus_msg_t *m) {
    s32 next = (D_800A0118 + 1) % D_800A011C;
    if (next == D_800A0114) {
        return 0;
    }
    func_8005104C(&D_800A0120[D_800A0118], m, sizeof(mus_msg_t));
    D_800A0118 = next;
    return 1;
}
