typedef struct { u32 w0; u32 w1; } Acmd;
typedef struct ALPlayer {
    struct ALPlayer *next;
    void *clientData;
    s32 (*handler)(void *);
    s32 callTime;
    s32 samplesLeft;
} ALPlayer;
typedef struct {
    ALPlayer *head;
    u8 unk_04[0x18];
    s32 paramSamples;
    s32 curSamples;
    u8 unk_24[0x20];
    s32 maxOutSamples;
    s16 *outBuf;
} ALSynth;
extern ALSynth *D_800773B4;
s32 func_80054B54(s32);
Acmd *func_80054C00(s32, Acmd *);
void func_80054ABC(void);

/* alAudioFrame: run player handlers then pull samples into the command list */
Acmd *func_80054910(Acmd *cmdList, s32 *cmdLen, s16 *outBuf, s32 outLen) {
    ALPlayer *client;
    Acmd *cmdlEnd = cmdList;
    s32 nOut;
    s16 *lOutBuf = outBuf;

    if (D_800773B4->head == NULL) {
        *cmdLen = 0;
        return cmdList;
    }
    for (client = D_800773B4->head; client->samplesLeft - D_800773B4->curSamples < outLen; ) {
        D_800773B4->paramSamples = client->samplesLeft & ~0xF;
        client->samplesLeft += func_80054B54(client->handler(client));
    }
    D_800773B4->paramSamples &= ~0xF;
    while (outLen > 0) {
        nOut = (D_800773B4->maxOutSamples < outLen ? D_800773B4->maxOutSamples : outLen);
        D_800773B4->outBuf = lOutBuf;
        cmdlEnd = func_80054C00(D_800773B4->curSamples, cmdlEnd);
        outLen -= nOut;
        lOutBuf += nOut << 1;
        D_800773B4->curSamples += nOut;
    }
    *cmdLen = cmdlEnd - cmdList;
    func_80054ABC();
    return cmdlEnd;
}
