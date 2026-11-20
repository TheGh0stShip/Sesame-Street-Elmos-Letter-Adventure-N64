/* pushes an 8-byte message onto a ring buffer; returns 0 when full */
typedef struct {
    u8 type;
    s32 arg;
} Msg;
extern s32 D_800A0114; /* head */
extern s32 D_800A0118; /* tail */
extern s32 D_800A011C; /* size */
extern Msg *D_800A0120; /* buffer */
void *func_8005104C(void *dst, const void *src, s32 n); /* memcpy */
s32 func_8004D6D4(Msg *m) {
    s32 next = (D_800A0118 + 1) % D_800A011C;
    if (next == D_800A0114) {
        return 0;
    }
    func_8005104C(&D_800A0120[D_800A0118], m, sizeof(Msg));
    D_800A0118 = next;
    return 1;
}
