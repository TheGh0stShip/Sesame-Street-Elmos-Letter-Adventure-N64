typedef struct Node { struct Node *prev; struct Node *next; s32 count; } Node;
extern Node *D_800A0130;
extern Node *D_800A0134;
extern s32 D_800A0148;
extern u8 D_800A0150[];
s32 func_80057100(void *mq, void *msg, s32 flag);
/* drain pending messages, then tick down timers moving expired nodes to the free list */
void func_80050814(void) {
    void *msg;
    Node *n;
    Node *next;

    while (D_800A0148 != 0) {
        func_80057100(D_800A0150, &msg, 0);
        D_800A0148--;
    }
    n = D_800A0130;
    while (n != NULL) {
        if (--n->count == 0) {
            next = n->next;
            if (next != NULL) next->prev = n->prev;
            if (n->prev != NULL) n->prev->next = n->next;
            else D_800A0130 = n->next;
            n->prev = NULL;
            n->next = D_800A0134;
            D_800A0134 = n;
            n = next;
        } else {
            n = n->next;
        }
    }
}
