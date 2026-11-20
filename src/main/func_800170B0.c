extern s32 D_002FBD50;
extern s32 D_002FE8D0;
extern s32 D_003E3FB0;
extern s32 D_003E4830;
extern s32 D_80079BE8;
extern s32 D_80079BEC;
extern s32 D_800A75F0;
extern s32 D_800AEC48;
extern s32 D_800AEC4C;
extern s32 D_800AEC50;
extern s32 D_800AEC54;
extern s32 D_800AEC58;
extern s32 D_800AEC5C;
extern s32 D_800AEC60;
extern s32 D_800AEC64;
extern s32 D_800AEC68;
extern s32 D_800AEC70;
extern s32 D_800AEC74;
extern s32 D_800AEC78;
extern s32 D_800AEC7C;
extern s32 D_800AEC80;
extern s32 D_800AEC84;
extern s32 D_800B0CA0;
extern s32 D_800BD480;
extern s32 D_80108B28;
extern s32 D_80115390;
s32 func_80017318();
s32 func_80017520();
s32 func_8004C6FC();
s32 func_8004D3B0();
s32 func_800510C0();
s32 func_80057BD0();

void f(void) {
    s32 sp10;

    if ((((s32)&D_002FE8D0) - ((s32)&D_002FBD50)) < 0x34D9) {
        goto L14;
    }
    func_80057BD0(((s32)&D_80079BE8), ((s32)&D_80079BEC), 106);
L14: ;
    func_80017318(((s32)&D_002FBD50), ((s32)&D_800B0CA0), (((s32)&D_002FE8D0) - ((s32)&D_002FBD50)));
    if ((((s32)&D_003E4830) - ((s32)&D_003E3FB0)) < 3123) {
        goto L39;
    }
    func_80057BD0(((s32)&D_80079BE8), ((s32)&D_80079BEC), 109);
L39: ;
    func_80017318(((s32)&D_003E3FB0), ((s32)&D_80115390), (((s32)&D_003E4830) - ((s32)&D_003E3FB0)));
    D_800AEC48 = 0;
    D_800AEC4C = 22;
    D_800AEC50 = (s32)&D_80108B28;
    D_800AEC54 = 239;
    D_800AEC58 = (s32)&D_800BD480;
    D_800AEC5C = 0x493E0;
    D_800AEC60 = (s32)&D_800B0CA0;
    D_800AEC64 = (s32)&D_002FE8D0;
    D_800AEC68 = (s32)&D_80115390;
    D_800AEC70 = 128;
    D_800AEC74 = 0x5622;
    D_800AEC78 = 0x1000;
    D_800AEC7C = 1;
    D_800AEC80 = 32;
    D_800AEC84 = 2048;
    sp10 = func_8004C6FC(((s32)&D_800AEC48));
    func_800510C0(2, 0x5622, 0, 0);
    func_80017520(0x3FFF, 0x3FFF);
    D_800A75F0 = 5;
    func_8004D3B0(2);
}
