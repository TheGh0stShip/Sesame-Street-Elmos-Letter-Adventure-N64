typedef struct DmaBuf {
    struct DmaBuf *prev;
    struct DmaBuf *next;
    s32 lastFrame;
    u32 startAddr;
    void *ptr;
} DmaBuf;
typedef struct {
    u16 type;
    u8 pri;
    u8 status;
    void *retQueue;
    void *dramAddr;
    u32 devAddr;
    u32 size;
    void *piHandle;
} IoMesg;
extern DmaBuf *D_800A0130; /* first used */
extern DmaBuf *D_800A0134; /* first free */
extern IoMesg *D_800A013C;
extern u32 D_800A0144;     /* buffer length */
extern s32 D_800A0148;     /* next message index */
extern u8 D_800A0150[];    /* message queue */
extern void *D_800A0168;
extern void *D_800BD458;
extern s32 D_8012C278;
s32 func_8005E6E0(void *handle, IoMesg *mb, s32 direction);

/* audio DMA: finds a cached buffer covering [addr, addr+len) or starts a PI DMA into a free one */
DmaBuf *func_8005095C(u32 addr, s32 len) {
    void *handle;
    DmaBuf *dma;
    DmaBuf *it;
    DmaBuf *nx;
    DmaBuf *last;
    IoMesg *m;
    s32 n;
    u32 end;

    if ((addr & 0xFF000000) == 0xFF000000) {
        handle = D_800BD458;
        addr &= 0xFFFFFF;
        addr += 0x140000;
    } else {
        if (D_8012C278 & 1) {
            return NULL;
        }
        handle = D_800A0168;
    }
    last = NULL;
    end = addr + len;
    for (it = D_800A0130; it != NULL; it = it->next) {
        if (addr < it->startAddr) {
            break;
        }
        if (end <= it->startAddr + D_800A0144) {
            return it;
        }
        last = it;
    }
    dma = D_800A0134;
    if (dma == NULL) {
        return D_800A0130;
    }
    D_800A0134 = dma->next;
    if (last != NULL) {
        nx = last->next;
        dma->next = nx;
        if (nx != NULL) {
            nx->prev = dma;
        }
        dma->prev = last;
        last->next = dma;
    } else {
        dma->prev = NULL;
        dma->next = D_800A0130;
        if (D_800A0130 != NULL) {
            D_800A0130->prev = dma;
        }
        D_800A0130 = dma;
    }
    n = D_800A0148;
    dma->startAddr = addr & ~1;
    dma->lastFrame = 2;
    D_800A0148 = n + 1;
    m = &D_800A013C[n];
    m->pri = 0;
    m->retQueue = D_800A0150;
    m->dramAddr = dma->ptr;
    m->devAddr = dma->startAddr;
    m->size = D_800A0144;
    func_8005E6E0(handle, m, 0);
    return dma;
}
