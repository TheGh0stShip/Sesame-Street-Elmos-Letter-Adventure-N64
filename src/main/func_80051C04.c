typedef struct { u8 unk_00[0x18]; } Mtx18;
typedef struct { u8 unk_00[0x8]; } Buf8;
void func_80056C40(Mtx18 *, Buf8 *, s32);
void func_80056A60(s32, s32);
void func_8005EE10(Mtx18 *, s32, s32, s32, s32, s32, Mtx18 *);
void func_80057100(Mtx18 *, s32, s32);
void func_80057230(s32, s32, s32);

void func_80051C04(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    Mtx18 a;
    Mtx18 b;
    Buf8 c;
    func_80056C40(&a, &c, 1);
    func_80056A60(arg1, arg2);
    func_8005EE10(&b, 0, 0, arg0, arg1, arg2, &a);
    func_80057100(&a, 0, 1);
    func_80057230(arg3, 0, 1);
}
