/* __rmonRunThread (rmontask.c): resume a stopped CPU thread or the RSP for the debugger */
typedef struct {
    int length; u8 code; u8 type; short error; u8 rev; u8 method; short notused2;
} KKHeader;
typedef struct { unsigned int flags; unsigned int vaddr; } KKRun;
typedef struct { KKHeader header; int tid; KKRun actions; } KKRunThreadRequest;
typedef struct { KKHeader header; int object; } KKObjectEvent;
typedef struct { KKHeader header; u8 status[0x40]; } KKStatusEvent;
typedef struct OSThread_s {
    struct OSThread_s *next; s32 priority; struct OSThread_s **queue; struct OSThread_s *tlnext;
    u16 state; u16 flags; s32 id; s32 fp;
    u8 pad[0x11C - 0x1C]; u32 pc; /* context.pc */
} OSThread;

OSThread *func_800669E0(void); /* __osGetActiveQueue */
int func_80063A1C(int thread, u32 *instptr); /* __rmonSetSingleStep */
int func_80066C30(void); /* __rmonRCPrunning */
void func_80064030(u32 *addr, u32 val); /* __rmonWriteWordTo */
u32 func_80064070(u32 *addr); /* __rmonReadWordAt */
u32 func_8006389C(int method, int thread, char *addr); /* __rmonGetBranchTarget */
void func_80066C98(void); /* __rmonStepRCP */
void func_80066CAC(void); /* __rmonRunRCP */
extern u8 D_8013EB10; /* __rmonRcpAtBreak */
void func_8005EF28(KKHeader *reply, int len, int type); /* __rmonSendReply */
int func_80065660(int method, int id, KKStatusEvent *reply); /* __rmonGetThreadStatus */
void func_80063BC8(KKStatusEvent *reply); /* __rmonGetExceptionStatus */
void func_80057530(OSThread *t); /* osStartThread */

#define RMON_CPU 0
#define RMON_RSP 1
#define RMON_TID_RSP 1000
#define TV_ERROR_NO_ERROR 0
#define TV_ERROR_INVALID_ID -2
#define TV_ERROR_OPERATIONS_PROTECTED -4
#define KK_RUN_SSTEP 1
#define KK_RUN_SETPC 2
#define KK_TYPE_REPLY 1
#define KK_TYPE_EXCEPTION 2
#define OS_STATE_STOPPED 1
#define SP_PC_REG 0x04080000
#define SP_IMEM_START 0x04001000

int func_80065A44(KKHeader *req)
{
    KKRunThreadRequest *request = (KKRunThreadRequest *)req;
    KKObjectEvent reply;
    KKStatusEvent exceptionReply;
    register OSThread *tptr;
    register int runNeeded = 0;

    switch (req->method) {
    case RMON_CPU:
        tptr = func_800669E0();
        while (tptr->priority != -1) {
            if (tptr->id == request->tid) {
                break;
            }
            tptr = tptr->tlnext;
        }

        if (tptr->priority == -1) {
            return TV_ERROR_INVALID_ID;
        }
        if (tptr->state != OS_STATE_STOPPED) {
            return TV_ERROR_OPERATIONS_PROTECTED;
        }
        tptr->flags &= ~(1 | 2);
        if (request->actions.flags & KK_RUN_SETPC) {
            tptr->pc = request->actions.vaddr;
        }
        if ((request->actions.flags & KK_RUN_SSTEP) && !func_80063A1C(request->tid, (u32 *)tptr->pc)) {
            return TV_ERROR_OPERATIONS_PROTECTED;
        }
        runNeeded = 1;
        break;
    case RMON_RSP:
        if (func_80066C30()) {
            return TV_ERROR_OPERATIONS_PROTECTED;
        }
        if (request->actions.flags & KK_RUN_SETPC) {
            func_80064030((u32 *)SP_PC_REG, request->actions.vaddr - SP_IMEM_START);
        }
        if (request->actions.flags & KK_RUN_SSTEP) {
            if (func_8006389C(RMON_RSP, RMON_TID_RSP,
                              (void *)(func_80064070((u32 *)SP_PC_REG) + SP_IMEM_START)) % 4 == 0) {
                func_80066C98();
            }
            func_80066C98();
            D_8013EB10 = 1;
        } else {
            D_8013EB10 = 0;
            func_80066CAC();
        }
        reply.header.code = request->header.code;
        reply.header.error = TV_ERROR_NO_ERROR;
        reply.object = request->tid;
        func_8005EF28(&reply.header, sizeof(reply), KK_TYPE_REPLY);
        if (request->actions.flags & KK_RUN_SSTEP) {
            func_80065660(RMON_RSP, RMON_TID_RSP, &exceptionReply);
            func_80063BC8(&exceptionReply);
            func_8005EF28(&exceptionReply.header, sizeof(exceptionReply), KK_TYPE_EXCEPTION);
        }
        return TV_ERROR_NO_ERROR;
    default:
        return TV_ERROR_OPERATIONS_PROTECTED;
    }

    reply.header.code = request->header.code;
    reply.header.error = TV_ERROR_NO_ERROR;
    reply.object = request->tid;
    func_8005EF28(&reply.header, sizeof(reply), KK_TYPE_REPLY);

    if (runNeeded) {
        func_80057530(tptr);
    }
    return 1;
}
