/* calls func_80050178 on entry i of the table at D_800773B4->unk_34 and returns it */
typedef struct { u8 pad[0x24]; s32 unk_24[1]; } Mgr2;
typedef struct { u8 pad[0x34]; Mgr2 *unk_34; } Mgr;
extern Mgr *D_800773B4;
void func_80050178(void *);
s32 func_80050128(s16 i) {
    func_80050178(&D_800773B4->unk_34->unk_24[i]);
    return D_800773B4->unk_34->unk_24[i];
}
