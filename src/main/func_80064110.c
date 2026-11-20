/* host-io style write request: validate address/size, send a header packet then the data */
typedef struct {
    u32 unk0;
    u8 unk4;
    u16 unk6;
    u32 unk8;
    u32 unkC;
} Hdr;
typedef struct {
    u32 unk0;
    u8 unk4;
    u8 unk5[4];
    u8 unk9;
    u32 unkC;
    u32 unk10;
    u32 unk14;
} Req;
extern Hdr D_80115270;
u32 func_80057AF0(u32 a);
s32 func_80061AD0(u8 *buf, s32 n, s32 c);
void func_8005EEC0(Hdr *h, s32 size, s32 b);
void func_8005EFE0(u32 addr, u32 size);

s32 func_80064110(Req *r)
{
    u32 addr;
    s32 n;
    u32 len;
    Hdr *h;
    u8 *p;

    h = &D_80115270;
    D_80115270.unk4 = r->unk4;
    D_80115270.unkC = r->unkC;
    D_80115270.unk6 = 0;
    if (r->unk10 == -1) {
        return -5;
    }
    if (r->unk14 > 0x400) {
        return -8;
    }
    if (r->unk9 == 1) {
        if (!((r->unk10 > 0x04000FFF && r->unk10 + r->unk14 <= 0x04001FFF)
              || (r->unk10 > 0x03FFFFFF && r->unk10 + r->unk14 <= 0x04000FFF))) {
            return -5;
        }
    } else if (func_80057AF0(r->unk10) == -1) {
        return -5;
    }
    addr = r->unk10;
    h->unk0 = r->unk14 + 0x10;
    len = r->unk14 + 0x10;
    p = (u8 *)&len;
    for (n = 0; n < 4; n += func_80061AD0(p + n, 4 - n, 8)) {
    }
    func_8005EEC0(h, 0x10, 1);
    func_8005EFE0(addr, r->unk14);
    return 0;
}
