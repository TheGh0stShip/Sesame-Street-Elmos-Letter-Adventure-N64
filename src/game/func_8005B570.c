#include "common.h"

typedef struct { void *head; } ALSynth;
/* alSynDelete */
void func_8005B570(ALSynth *drvr) { drvr->head = 0; }
