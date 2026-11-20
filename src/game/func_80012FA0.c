#include "common.h"


/* sound sequencing thread: plays a command list, waiting on a timer between entries */
void func_80012FA0(void *arg0) {
    void *msg;

    osCreateMesgQueue(D_8013ED88, D_80109BA8, 1);
    (*(SndCmd *(*))&D_80115374) = NULL;
    while (1) {
        osRecvMesg(D_8013ED88, NULL, 1);
        if ((*(SndCmd *(*))&D_80115374) != NULL) {
            if ((*(SndCmd *(*))&D_80115374)->unk_04 == 0) {
                (*(SndCmd *(*))&D_80115374) = NULL;
            } else {
                if ((*(SndCmd *(*))&D_80115374)->unk_00 == -1) {
                    osSetTimer(D_8012EF88, (s64)(*(SndCmd *(*))&D_80115374)->unk_04 * 46875, 0, D_8013ED88, NULL);
                } else if ((*(SndCmd *(*))&D_80115374)->unk_04 == -1) {
                    if ((*(SndCmd *(*))&D_80115258) != NULL) {
                        func_80051418(D_800A7AF8);
                        D_800A7AF8 = func_80051314((*(SndCmd *(*))&D_80115258)->unk_00, 0x40, 0x7FFF);
                        D_80109C3E = 0x7FFF;
                        osSetTimer(D_8012EF88, (s64)(*(SndCmd *(*))&D_80115258)->unk_04 * 46875, 0, D_8013ED88, NULL);
                    }
                } else if ((*(SndCmd *(*))&D_80115374)->unk_04 == -2) {
                    if ((*(SndCmd *(*))&D_8013E680) != NULL) {
                        func_80051418(D_800A7AF8);
                        D_800A7AF8 = func_80051314((*(SndCmd *(*))&D_8013E680)->unk_00, 0x40, 0x7FFF);
                        D_80109C3E = 0x7FFF;
                        osSetTimer(D_8012EF88, (s64)(*(SndCmd *(*))&D_8013E680)->unk_04 * 46875, 0, D_8013ED88, NULL);
                    }
                } else {
                    func_80051418(D_800A7AF8);
                    D_800A7AF8 = func_80051314((*(SndCmd *(*))&D_80115374)->unk_00, 0x40, 0x7FFF);
                    D_80109C3E = 0x7FFF;
                    osSetTimer(D_8012EF88, (s64)(*(SndCmd *(*))&D_80115374)->unk_04 * 46875, 0, D_8013ED88, NULL);
                }
                (*(SndCmd *(*))&D_80115374)++;
            }
        }
    }
}
