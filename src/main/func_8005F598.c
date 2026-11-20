/* proutSprintf: copies count bytes and returns the end of the destination */
void *func_8005F50C(void *dst, const void *src, u32 n); /* memcpy */
char *func_8005F598(char *dst, const char *src, u32 count) {
    func_8005F50C(dst, src, count);
    return dst + count;
}
