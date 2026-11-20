#include "common.h"
#include "game_structs.h"


/* clears flag 0x10000 of unk_200 when the actor's unk_B4 exceeds a threshold */
void func_8003B5D8(Actor *actor) {
    f32 sp10;
    f32 sp14;
    f32 sp18;

    if ((actor->u.walker.unk_1FC & 0x80000000) != 0) {
        if (D_80109B8C == 0) {
            return;
        }
        sp10 = actor->u.walker.unk_AC.x;
        sp14 = actor->u.walker.unk_AC.z;
        sp18 = -actor->u.walker.unk_AC.y;
        if (sp14 > D_8007AC78) {
            actor->u.walker.unk_200 = actor->u.walker.unk_200 & 0xFFFEFFFF;
            func_80035828(actor, 3);
        } else {
        }
        if (sp14 > D_8007AC80) {
            actor->u.walker.unk_200 = actor->u.walker.unk_200 & 0xFFFEFFFF;
        }
    }
}
