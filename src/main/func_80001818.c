typedef struct { u32 w0; u32 w1; } Gfx;
typedef struct { u8 pad[0x80C8]; void *unk_80C8; } GfxCtx;
extern Gfx *D_8013EB0C;
extern void *D_8013EF68;
extern Gfx D_80076DE0[];
extern Gfx D_80076CE0[];
extern Gfx D_80076DC8[];
extern s32 D_8006DD64;
extern u16 D_801DA800[];
u32 func_80057AF0(void *);

/* Emits the frame's setup display list: segments, depth buffer, clears and colour image. */
void func_80001818(void *arg) {
    GfxCtx *ctx;
    Gfx *g;

    ctx = arg;
    g = D_8013EB0C++;
    g->w0 = 0xBC000006;
    g->w1 = 0;
    g = D_8013EB0C++;
    g->w0 = 0xBC000806;
    g->w1 = func_80057AF0(D_8013EF68);
    g = D_8013EB0C++;
    g->w0 = 0x06000000;
    g->w1 = (u32)D_80076DE0;
    if (D_8006DD64 != 0) {
        g = D_8013EB0C++;
        g->w0 = 0x06000000;
        g->w1 = (u32)D_80076CE0;
        D_8006DD64 = 0;
    }
    g = D_8013EB0C++;
    g->w0 = 0x06000000;
    g->w1 = (u32)D_80076DC8;
    g = D_8013EB0C++;
    g->w0 = 0xFE000000;
    g->w1 = func_80057AF0(D_801DA800);
    g = D_8013EB0C++;
    g->w0 = 0xBA001402;
    g->w1 = 0x300000;
    g = D_8013EB0C++;
    g->w0 = 0xFF10013F;
    g->w1 = func_80057AF0(D_801DA800);
    g = D_8013EB0C++;
    g->w0 = 0xF7000000;
    g->w1 = -1;
    g = D_8013EB0C++;
    g->w0 = 0xF64FC3BC;
    g->w1 = 0;
    g = D_8013EB0C++;
    g->w0 = 0xFF10013F;
    g->w1 = func_80057AF0(ctx->unk_80C8);
}
