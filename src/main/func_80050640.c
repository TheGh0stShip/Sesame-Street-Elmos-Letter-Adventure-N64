/* if idx is in range, act on entry idx of D_800770C4 and notify the player; 0 on success, 1 if out of range */
extern s32 D_800770C0;
extern void *D_800770C4[];
typedef struct { char pad0[0x20]; void *unk_20; } T;
typedef struct { char pad0[0x34]; T *unk_34; } U;
extern U *D_8013C588;
void func_800502C0(void *);
void func_8005A4B4(void *, s32, void *);
s32 func_80050640(s32 idx)
{
    s32 ret;
    if (idx < D_800770C0) {
        func_800502C0(D_800770C4[idx]);
        { T *t = D_8013C588->unk_34; func_8005A4B4(t->unk_20, 1, t); }
        ret = 0;
    } else {
        ret = 1;
    }
    return ret;
}
