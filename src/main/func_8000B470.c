typedef struct {
    u32 w0;
    u32 w1;
} Gfx;

typedef struct {
    u32 type;
    u32 flags;
    u8 *ucode_boot;
    u32 ucode_boot_size;
    u8 *ucode;
    u32 ucode_size;
    u8 *ucode_data;
    u32 ucode_data_size;
    u8 *dram_stack;
    u32 dram_stack_size;
    u8 *output_buff;
    u8 *output_buff_size;
    Gfx *data_ptr;
    u32 data_size;
    u8 *yield_data_ptr;
    u32 yield_data_size;
} Task;

typedef struct {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    Task list;
    void *msgQ;
    void *msg;
    u8 pad58[0x60 - 0x58];
    u64 unk_60;
} ScTask;

typedef struct {
    ScTask task;
    Gfx gfx[(0x80A8 - 0x68) / 8];
    u8 unk_80A8[0x80C8 - 0x80A8];
    s32 unk_80C8;
} Frame;

extern void func_800013B0(void);
extern void func_80001424(void (*)(), void *, s32, s32, f32);
extern void func_800016C0(void);
extern void func_80001818(Frame *);
extern void func_80001F60(void);
extern void func_80003D08(void);
extern void func_80004010(s32);
extern s32 func_8000DBC0(void);
extern void func_8000DCFC(s32);
extern void func_8000DD7C(s32, s32);
extern void func_8000DDF4(s32, s32, s32, s32);
extern void func_8000DE60(s32);
extern void func_8000DEBC(char *);
extern void func_80012164(s32);
extern void func_8001A318(void);
extern void func_8001CAA8(void *, void *);
extern void func_80040284(s32);
extern void func_80040304(s32);
extern void func_80056C10(void);
extern void func_80057230(s32, void *, s32);
extern void func_80057BD0(char *, char *, s32);
extern void func_8005F540(char *, char *);
extern void func_80001AB4();
extern void func_8000A7F0();
extern u8 D_8006B390[];
extern u8 D_8006B460[];
extern u32 D_800745E4;
extern Gfx D_800749A0[];
extern u8 D_800761E0;
extern u8 D_80078A00[];
extern char D_80079768[];
extern char D_80079774[];
extern char D_80079784[];
extern char D_80079788[];
extern s32 D_8007D330;
extern s32 D_800A7AA4;
extern u8 D_800A8DDC;
extern u8 D_800ACC2E;
extern s32 D_80106880;
extern s32 D_80108B24;
extern u8 D_80109C70;
extern u8 D_80109C78;
extern u8 D_8010E490[];
extern u8 D_80112CF0[];
extern u8 D_80114CF0[];
extern s32 D_8011525C;
extern s32 D_8012EFD0;
extern u8 D_8012F060[];
extern u8 D_8013E690[];
extern Gfx *D_8013EB0C;
extern Gfx *D_8013EF68;
extern u8 D_80154000[], D_80154200[], D_80166E00[], D_80167000[], D_80179C00[], D_80179E00[];
extern u8 D_8018CA00[], D_8018CC00[], D_801A8E20[], D_801A9020[];

/* builds the frame's display list and sends the graphics task */
s32 func_8000B470(Frame *frame) {
    ScTask *task;
    s32 saved;
    char buf[0x68];

    D_8013EF68 = frame->gfx;
    D_8013EB0C = &frame->gfx[8];
    func_800013B0();
    func_80001424(func_80001AB4, NULL, 2, 0, 0);
    if (D_800761E0 == 1) {
        func_80001424(func_8000A7F0, NULL, 6, 0, 0);
    }
    D_800ACC2E = 1;
    func_80040284(D_8011525C);
    func_80001818(frame);
    func_800016C0();
    func_80040304(D_8011525C);
    if (D_8012EFD0 == 0x15) {
        switch (D_800745E4) {
            case 0:
                func_8001CAA8(D_8018CC00, D_8018CA00);
                break;
            case 1:
                func_8001CAA8(D_80167000, D_80166E00);
                break;
            case 2:
                func_8001CAA8(D_80179E00, D_80179C00);
                break;
            case 3:
                func_8001CAA8(D_801A9020, D_801A8E20);
                break;
            case 4:
                func_8001CAA8(D_80154200, D_80154000);
                if (!(D_80106880 & 0x40)) {
                    saved = func_8000DBC0();
                    func_8000DE60(1);
                    func_8000DDF4(0xFF, 0xFF, 0xFF, 0xFF);
                    func_8000DD7C(0x74, 0xC8);
                    func_8005F540(buf, D_80079768);
                    func_8000DEBC(buf);
                    {
                        Gfx *g = D_8013EB0C++;
                        g->w0 = 0x06000000;
                        g->w1 = (u32)D_800749A0;
                    }
                    func_8000DCFC(saved);
                }
                break;
            default:
                func_8001CAA8(D_80154200, D_80154000);
                break;
        }
    }
    if (D_8012EFD0 == 0x16) {
        func_8001A318();
    }
    if (D_80109C70 == 0) {
        func_80012164(0);
    }
    if (D_800A8DDC == 0) {
        func_80004010(0);
        func_80003D08();
    } else {
        func_80003D08();
        func_80004010(0);
    }
    if (D_80109C70 != 0) {
        func_80012164(0);
    }
    func_80001F60();
    if (D_80109C78 != 0) {
        saved = func_8000DBC0();
        func_8000DE60(1);
        func_8000DDF4(0xFF, 0xFF, 0xFF, 0xFF);
        func_8000DD7C(0x6C, 0x70);
        func_8005F540(buf, D_80079774);
        func_8000DEBC(buf);
        {
            Gfx *g = D_8013EB0C++;
            g->w0 = 0x06000000;
            g->w1 = (u32)D_800749A0;
        }
        func_8000DCFC(saved);
    }
    {
        Gfx *g = D_8013EB0C++;
        g->w0 = 0xE9000000;
        g->w1 = 0;
    }
    {
        Gfx *g = D_8013EB0C++;
        g->w0 = 0xB8000000;
        g->w1 = 0;
    }
    ((D_8013EB0C - (D_8013EF68 + 8)) < 0x1000) ? (void)0 : func_80057BD0(D_80079784, D_80079788, 0x1324);
    task = &frame->task;
    task->list.data_ptr = D_8013EF68 + 8;
    task->list.data_size = ((D_8013EB0C - (D_8013EF68 + 8))) * sizeof(Gfx);
    task->list.type = 1;
    task->list.flags = 0;
    task->list.ucode_boot = D_8006B390;
    task->list.ucode_boot_size = D_8006B460 - D_8006B390;
    task->list.ucode = D_8006B460;
    task->list.ucode_data = D_80078A00;
    task->list.ucode_data_size = 0x800;
    task->list.dram_stack = D_8013E690;
    task->list.dram_stack_size = 0x400;
    task->list.output_buff = D_80112CF0;
    task->list.output_buff_size = D_80114CF0;
    task->list.yield_data_ptr = D_8012F060;
    task->list.yield_data_size = 0xC00;
    task->unk_08 = D_80108B24 ? 0x63 : 0x23;
    task->unk_00 = 0;
    task->msgQ = D_8010E490;
    task->msg = frame->unk_80A8;
    task->unk_0C = frame->unk_80C8;
    task->unk_60 = 0;
    func_80056C10();
    func_80057230(D_800A7AA4, task, 1);
    D_8007D330++;
    return 1;
}
