#include "common.h"
#include "codec/stream.h"

/* size 0x1200 */

extern stream_t *D_800A0350;

/* clears the first entry whose id equals the given id */
void func_80051418(u16 id) {
    s32 i;
    stream_t *e;

    if (id != 0xFFFF) {
        for (i = 0; i < D_800A0354; i++) {
            if (D_800A0350[i].id == id) {
                D_800A0350[i].id = 0xFFFF;
                return;
            }
        }
    }
}
