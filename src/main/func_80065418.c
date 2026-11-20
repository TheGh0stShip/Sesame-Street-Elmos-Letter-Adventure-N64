/* find an active thread by id (__osGetActiveQueue walk) */
typedef struct OSThread_s {
    struct OSThread_s *next;
    s32 priority;
    struct OSThread_s **queue;
    struct OSThread_s *tlnext;
    u16 state;
    u16 flags;
    s32 id;
} OSThread;
extern OSThread *func_800669E0(void);   /* __osGetActiveQueue */
OSThread *func_80065418(s32 id)
{
    OSThread *t = func_800669E0();
    if (id <= 0) {
        return NULL;
    }
    while (t->priority != -1) {
        if (t->id == id) {
            return t;
        }
        t = t->tlnext;
    }
    return NULL;
}
