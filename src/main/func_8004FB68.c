typedef struct { u8 pad[0xB9]; u8 unk_B9; } S;
u8 func_8004EB78(u8);
u8 *func_8004FB68(S *p, u8 *ptr) {
    p->unk_B9 = func_8004EB78(*ptr++);
    p->unk_B9 += *ptr++;
    return ptr;
}
