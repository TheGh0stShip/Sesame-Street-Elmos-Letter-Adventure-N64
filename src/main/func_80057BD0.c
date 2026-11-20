/* __assert: prints an assertion fault message */
extern char D_8007B420[]; /* "\nASSERTION FAULT: %s, %d: \"%s\"\n" */
void func_8005F808(const char *fmt, ...); /* osSyncPrintf */
void func_80059540(const char *exp, const char *filename, int line) {
    func_8005F808(D_8007B420, filename, line, exp);
}
