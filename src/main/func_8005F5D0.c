/* kmc_proutSyncPrintf: printf sink that expands tabs and sends length-prefixed lines to the KMC debugger port */
extern volatile unsigned int *D_80077780; /* stat */
extern volatile unsigned int *D_80077784; /* wport */
extern volatile unsigned int *D_80077788; /* piok (PI_STATUS_REG) */
extern int D_8007778C;                    /* column */

static void rmonPutchar(u8 c) {
    while (*D_80077788 & (1 | 2)) {
    }

    while (!(*D_80077780 & 4)) {
    }

    *D_80077784 = c;
}

void *func_80060F40(void *str, const u8 *buf, int n) {
    int i;
    u8 c;
    u8 *p;
    u8 *q;
    u8 xbuf[128];

    p = xbuf;

    for (i = 0; i < n; i++) {
        c = *buf++;

        switch (c) {
            case '\n':
                *p++ = '\n';
                D_8007778C = 0;
                break;
            case '\t':
                do {
                    *p++ = ' ';
                } while (++D_8007778C % 8);
                break;
            default:
                D_8007778C++;
                *p++ = c;
                break;
        }

        if (c == '\n' || (p - xbuf) > 100) {
            rmonPutchar((p - xbuf) - 1);

            q = xbuf;
            while (q != p) {
                rmonPutchar(*q++);
            }
            p = xbuf;
        }
    }
    if (p != xbuf) {
        rmonPutchar((p - xbuf) - 1);

        q = xbuf;
        while (q != p) {
            rmonPutchar(*q++);
        }
    }
    return (void *)1;
}
