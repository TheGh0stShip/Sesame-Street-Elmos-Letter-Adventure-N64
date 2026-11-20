/* printf-style debug output: through the sync-print hook if installed, else through another sink */
typedef char *va_list; /* gcc 2.7 va-mips.h */
#define va_start(ap, last) (ap = (va_list)__builtin_next_arg(last))
extern void *D_800A8B10;
void *func_8005F5D0(void *, const char *, u32);
void *func_8005F8B4(void *, const char *, u32);
s32 func_80065FA0(void *prout, void *arg, const char *fmt, va_list ap); /* _Printf */
void func_8005F808(const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    if (D_800A8B10 != NULL) {
        func_80065FA0(func_8005F5D0, NULL, fmt, ap);
    } else {
        func_80065FA0(func_8005F8B4, NULL, fmt, ap);
    }
}
