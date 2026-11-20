extern s32 D_0007C6B0;
extern s32 D_000A54D0;
extern s32 D_0010D0F0;
extern s32 D_001BF6F0;
extern s32 D_00204D00;
extern s32 D_00227BA0;
extern s32 D_00243E20;
extern s32 D_002604B0;
extern s32 D_0028FDB0;
extern s32 D_002ACFA0;
extern s32 D_002D1FB0;
extern s32 D_002F9B60;
extern s16 D_80109C40;
extern s32 D_80154000;
extern s32 D_8024B000;
s32 func_8000CF50();
s32 func_8000E010();
s32 func_80013560();
s32 func_8001375C();
s32 func_80017318();

void f(s32 arg0) {
    s32 sp10[8];
    s32 sp30;
    s32 sp34;

    func_8001375C(((s32)&sp10), ((s32)&D_80154000), 0x86800);
    switch (arg0) {
    case 21:
        sp30 = ((s32)&D_0010D0F0) - ((s32)&D_000A54D0);
        sp34 = (s32)&D_000A54D0;
        func_80017318(sp34, ((s32)&D_80154000), sp30);
        break;
    case 22:
        sp30 = ((s32)&D_000A54D0) - ((s32)&D_0007C6B0);
        sp34 = (s32)&D_0007C6B0;
        func_80017318(sp34, ((s32)&D_80154000), sp30);
        break;
    case 2:
        sp30 = ((s32)&D_00204D00) - ((s32)&D_001BF6F0);
        sp34 = (s32)&D_001BF6F0;
        D_80109C40 = 3;
        func_80013560(((s32)&sp10), sp34, sp30);
        D_80109C40 = 4;
        break;
    case 19:
        sp30 = ((s32)&D_002F9B60) - ((s32)&D_002D1FB0);
        sp34 = (s32)&D_002D1FB0;
        func_80013560(((s32)&sp10), sp34, sp30);
        break;
    case 16:
        sp30 = ((s32)&D_00227BA0) - ((s32)&D_00204D00);
        sp34 = (s32)&D_00204D00;
        func_80013560(((s32)&sp10), sp34, sp30);
        break;
    case 15:
        sp30 = ((s32)&D_00243E20) - ((s32)&D_00227BA0);
        sp34 = (s32)&D_00227BA0;
        func_80013560(((s32)&sp10), sp34, sp30);
        break;
    case 18:
        sp30 = ((s32)&D_002604B0) - ((s32)&D_00243E20);
        sp34 = (s32)&D_00243E20;
        func_80013560(((s32)&sp10), sp34, sp30);
        break;
    case 17:
        sp30 = ((s32)&D_0028FDB0) - ((s32)&D_002604B0);
        sp34 = (s32)&D_002604B0;
        func_80013560(((s32)&sp10), sp34, sp30);
        break;
    case 14:
        sp30 = ((s32)&D_002ACFA0) - ((s32)&D_0028FDB0);
        sp34 = (s32)&D_0028FDB0;
        func_80013560(((s32)&sp10), sp34, sp30);
        break;
    case 13:
        sp30 = ((s32)&D_002D1FB0) - ((s32)&D_002ACFA0);
        sp34 = (s32)&D_002ACFA0;
        func_80013560(((s32)&sp10), sp34, sp30);
        break;
    default:
        return;
    }
    sp30 = ((s32)&D_001BF6F0) - ((s32)&D_0010D0F0);
    func_80017318(((s32)&D_0010D0F0), ((s32)&D_8024B000), sp30);
    D_80109C40 = 4;
    func_8000CF50();
    func_8000E010(0, 0);
}
