/* stores two scale factors; picks func_8005B640 when both are 1.0, else func_8005B6E0 */
typedef struct {
    s32 unk_0;
    s32 unk_4;
    f32 unk_8;
    f32 unk_C;
} S;
void func_8005B640(S *s, s32 n);
void func_8005B6E0(S *s, s32 n);
void func_8005B660(S *s, f32 a, f32 b) {
    s->unk_8 = a;
    s->unk_C = b;
    if ((a == 1.0f) & (b == 1.0f)) {
        func_8005B640(s, 0x10);
    } else {
        func_8005B6E0(s, 0x10);
    }
}
