/* libultra rmon __rmonSetVRegs: load RSP vector registers by stepping LQV instructions */
typedef struct {
    s32 length;
    u8 code;
    u8 unk_05;
    s16 error;
    s32 method;
    s32 object;
} KKHeader;
typedef struct {
    KKHeader header;
    u32 vregs[32];
} KKVregRequest;
typedef union {
    u32 everything;
    struct {
        unsigned opcode : 6;
        unsigned base : 5;
        unsigned rt : 5;
        unsigned opc : 5;
        unsigned element : 4;
        unsigned offset : 7;
    } swcop;
} INSTRUCTION;

extern s32 func_80066C30(void); /* __rmonRCPrunning */
extern u32 func_80064070(u32 addr); /* __rmonReadWordAt */
extern void func_80064030(u32 addr, u32 val); /* __rmonWriteWordTo */
extern void func_800640E0(u32 dst, void *src, s32 n); /* __rmonMemcpy */
extern void func_80066C98(void); /* __rmonStepRCP */
extern void func_8005EF28(void *reply, s32 size, s32 flag); /* __rmonSendReply */
extern u32 D_800A75B0, D_800A75B4, D_800A75B8, D_800A75BC, D_800A75C0, D_800A75C4;

s32 func_80065180(KKVregRequest *req) {
    KKHeader reply;
    INSTRUCTION inst;
    s32 i;

    if (func_80066C30()) {
        return -4;
    }
    D_800A75B0 = func_80064070(0x04080000);
    D_800A75B4 = func_80064070(0x04001000);
    D_800A75B8 = func_80064070(0x04000000);
    D_800A75BC = func_80064070(0x04000004);
    D_800A75C0 = func_80064070(0x04000008);
    D_800A75C4 = func_80064070(0x0400000C);
    for (i = 0; i < 32; i++) {
        func_800640E0(0x04000000, &req->vregs[i], 4);
        inst.everything = 0xC8000000;
        inst.swcop.rt = i;
        inst.swcop.opc = 4;
        func_80064030(0x04001000, inst.everything);
        func_80064030(0x04080000, 0);
        func_80066C98();
    }
    func_80064030(0x04000000, D_800A75B8);
    func_80064030(0x04000004, D_800A75BC);
    func_80064030(0x04000008, D_800A75C0);
    func_80064030(0x0400000C, D_800A75C0);
    func_80064030(0x04001000, D_800A75B4);
    func_80064030(0x04080000, D_800A75B0);
    reply.object = req->header.object;
    reply.code = req->header.code;
    reply.error = 0;
    func_8005EF28(&reply, sizeof(reply), 1);
    return 0;
}
