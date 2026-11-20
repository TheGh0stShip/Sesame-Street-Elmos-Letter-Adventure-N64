#include "common.h"

/* osGetThreadPri */
typedef struct OSThread_s { struct OSThread_s *next; s32 priority; } OSThread;
extern OSThread *D_80077420; /* __osRunningThread */
s32 func_800615D0(OSThread *thread) {
    if (thread == NULL) {
        thread = D_80077420;
    }
    return thread->priority;
}
