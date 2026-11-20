#include "common.h"
#include "libmus/player.h"

void MusSetSongFxChange(s32 arg0) {
    mus_msg_t m;
    s32 ok = 1;
    if (arg0 == 0) {
        m.type = 2;
        m.data = D_800A0104;
        D_800A0104 = m.data;
        ok = func_8004D6D4(&m);
    }
    if (ok) {
        D_800A0100 = arg0;
    }
    return;
}
