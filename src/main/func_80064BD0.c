/* rmonGetRcpRegister: read an RSP scalar register by stepping a single SW instruction */
extern u32 D_800A75B0; /* RCPpc */
extern u32 D_800A75B4; /* oldIMEMvalue */
extern u32 D_800A75B8[4]; /* DMEMbuffer */
s32 func_80066C30(void);                 /* __rmonRCPrunning */
u32 func_80064070(u32 *addr);            /* __rmonReadWordAt */
void func_80064030(u32 *addr, u32 val);  /* __rmonWriteWordTo */
void func_80066C98(void);                /* __rmonStepRCP */

typedef union {
    u32 everything;
    struct { int opcode : 6; int base : 5; int rt : 5; int offset : 16; } scalarop;
} INSTRUCTION;

static void LoadStoreSU(int opcode, int regno) {
    INSTRUCTION inst;
    inst.everything = 0;
    inst.scalarop.opcode = opcode;
    inst.scalarop.rt = regno;
    func_80064030((u32 *)0x04001000, inst.everything);
    func_80064030((u32 *)0x04080000, 0);
}

static void SetUpForRCPop(int isVector) {
    D_800A75B0 = func_80064070((u32 *)0x04080000);
    D_800A75B4 = func_80064070((u32 *)0x04001000);
    D_800A75B8[0] = func_80064070((u32 *)0x04000000);
    if (isVector) {
        D_800A75B8[1] = func_80064070((u32 *)0x04000004);
        D_800A75B8[2] = func_80064070((u32 *)0x04000008);
        D_800A75B8[3] = func_80064070((u32 *)0x0400000C);
    }
}

static void CleanupFromRCPop(int isVector) {
    func_80064030((u32 *)0x04000000, D_800A75B8[0]);
    if (isVector) {
        func_80064030((u32 *)0x04000004, D_800A75B8[1]);
        func_80064030((u32 *)0x04000008, D_800A75B8[2]);
        func_80064030((u32 *)0x0400000C, D_800A75B8[2]);
    }
    func_80064030((u32 *)0x04001000, D_800A75B4);
    func_80064030((u32 *)0x04080000, D_800A75B0);
}

u32 func_80064BD0(int regNumber) {
    u32 contents;

    if (func_80066C30())
        return 0;
    SetUpForRCPop(0);
    LoadStoreSU(0x2B, regNumber);
    func_80066C98();
    contents = func_80064070((u32 *)0x04000000);
    CleanupFromRCPop(0);
    return contents;
}
