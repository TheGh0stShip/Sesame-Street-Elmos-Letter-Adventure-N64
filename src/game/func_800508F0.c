#include "common.h"

typedef struct { u8 pad[0xC]; s32 unk_C; s32 unk_10; } Obj;
void func_800508F0(s32 a) {
    Obj *o = ((Obj *(*)(s32))func_8005095C)(a);
    s32 v;
    if (o == NULL) {
        v = a;
    } else {
        if ((a & 0xFF000000) == 0xFF000000) { a &= 0xFFFFFF; a += 0x140000; }
        v = o->unk_10; v += a; v -= o->unk_C;
    }
    ((void (*)(s32, Obj *))osVirtualToPhysical)(v, o);
}
