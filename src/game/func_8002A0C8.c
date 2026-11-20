#include "common.h"
#include "game_structs.h"


/* Sets two fields of an object, clears 0x1CC, sets flag 0x80 and clears flag 0x8. */
void func_8002A0C8(register Actor *obj, s32 arg1, s32 arg2) {
    obj->u.model.unk_1B4 = arg2;
    obj->u.model.animTick = 0;
    obj->u.model.anim = arg1;
    obj->unk_C.l1.flags |= 0x80;
    obj->unk_C.l1.flags &= ~8;
}
