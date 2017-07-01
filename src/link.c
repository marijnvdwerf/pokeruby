#include "global.h"
#include "link.h"
#include "battle.h"
#include "berry.h"
#include "berry_blender.h"
#include "hall_of_fame.h"
#include "main.h"
#include "menu.h"
#include "palette.h"
#include "rng.h"
#include "save.h"
#include "songs.h"
#include "sound.h"
#include "sprite.h"
#include "strings2.h"
#include "string_util.h"
#include "task.h"
#include "text.h"

#define SIO_MULTI_CNT ((struct SioMultiCnt *)REG_ADDR_SIOCNT)

struct BlockTransfer
{
    u16 pos;
    u16 size;
    void *src;
    bool8 active;
    u8 multiplayerId;
};

struct LinkTestBGInfo
{
    u32 screenBaseBlock;
    u32 paletteNum;
    u32 dummy_8;
    u32 dummy_C;
};

extern u8 unk_2000000[];
extern u8 unk_2004000[];
extern u16 gBattleTypeFlags;
extern u16 gScriptItemId;

extern u16 word_3004858;

static void InitLinkTestBG(u8, u8, u8, u8);
void InitLinkTestBG_Unused(u8, u8, u8, u8);
void LinkTestScreen();
static void InitLocalLinkPlayer(void);
static void VBlankCB_LinkTest(void);
static void InitLink(void);
static void Task_TriggerHandshake(u8);
static void TestBlockTransfer(u32, u32, u32);
static void LinkTestProcessKeyInput(void);
static void CB2_LinkTest(void);
static void HandleReceiveRemoteLinkPlayer(u8);
static void ProcessRecvCmds(u8);
static void BuildSendCmd(u16);
static void sub_8007B44(void);
static void ResetBlockSend(void);
static bool8 InitBlockSend(void *, u32);
static void LinkCB_BlockSendBegin(void);
static void LinkCB_BlockSend(void);
static void LinkCB_BlockSendEnd(void);
static void sub_8007E04(void);
u32 sub_8007E40(void);
static void SetBlockReceivedFlag(u8);
static u16 LinkTestCalcBlockChecksum(void *, u16);
static void PrintHexDigit(u8, u8, u8);
void PrintHex(u32, u8, u8, u8);
static void LinkCB_RequestPlayerDataExchange(void);
static void Task_PrintTestData(u8);
bool8 sub_8008224(void);
u8 GetDummy2(void);
static void sub_8008350(void);
static void sub_800837C(void);
static void sub_80083E0(void);
static void sub_8008454(void);
static void sub_80084C8(void);
static void sub_80084F4(void);

static void CheckErrorStatus(void);
static void CB2_PrintErrorMessage(void);
static u8 IsSioMultiMaster(void);
static void DisableSerial(void);
static void EnableSerial(void);
static void CheckMasterOrSlave(void);
static void InitTimer(void);
static void EnqueueSendCmd(u16 *);
static void DequeueRecvCmds(u16[CMD_LENGTH][MAX_LINK_PLAYERS]);
static void StartTransfer(void);
static bool8 DoHandshake(void);
static void DoRecv(void);
static void DoSend(void);
static void StopTimer(void);
static void SendRecvDone(void);
void ResetSendBuffer(void);
void ResetRecvBuffer(void);

static struct BlockTransfer sBlockSend;
static struct BlockTransfer sBlockRecv[MAX_LINK_PLAYERS];
static u32 sBlockSendDelayCounter;
static u32 sDummy1;
static u8 sDummy2;
static u32 sPlayerDataExchangeStatus;
static u32 sErrorLinkStatus;
static u32 sErrorLastRecvQueueCount;
static u32 sErrorLastSendQueueCount;
static u32 sDummy3;
static u8 sLinkTestLastBlockSendPos;
static u8 sLinkTestLastBlockRecvPos[MAX_LINK_PLAYERS];
static u8 sNumVBlanksWithoutSerialIntr;
static bool8 sSendBufferEmpty;
static u16 sSendNonzeroCheck;
static u16 sRecvNonzeroCheck;
static u8 sChecksumAvailable;
static u8 sHandshakePlayerCount;

u16 word_3002910[MAX_LINK_PLAYERS];
u32 gLinkDebugValue1;
struct LinkPlayerBlock localLinkPlayerBlock;
bool8 gLinkErrorOccurred;
u32 gLinkDebugValue2;
bool8 gLinkPlayerPending[MAX_LINK_PLAYERS];
struct LinkPlayer gLinkPlayers[MAX_LINK_PLAYERS];
bool8 gBlockReceived[MAX_LINK_PLAYERS];
u16 gLinkHeldKeys;
u16 gLinkTimeOutCounter;
struct LinkPlayer localLinkPlayer;
u16 gRecvCmds[CMD_LENGTH][MAX_LINK_PLAYERS];
u32 gLinkStatus;
bool8 gLinkDummyBool;
u8 byte_3002A68;
u8 gBlockSendBuffer[BLOCK_BUFFER_SIZE];
bool8 u8_array_3002B70[MAX_LINK_PLAYERS];
u16 gLinkType;
bool8 u8_array_3002B78[MAX_LINK_PLAYERS];
u16 gBlockRecvBuffer[MAX_LINK_PLAYERS][BLOCK_BUFFER_SIZE / 2];
bool8 gSuppressLinkErrorMessage;
u8 gSavedLinkPlayerCount;
u16 gSendCmd[CMD_LENGTH];
u8 gSavedMultiplayerId;
bool8 gReceivedRemoteLinkPlayers;
struct LinkTestBGInfo gLinkTestBGInfo;
void (*gLinkCallback)(void);
struct LinkPlayer gSavedLinkPlayers[MAX_LINK_PLAYERS];
u8 gShouldAdvanceLinkState;
u16 gLinkTestBlockChecksums[MAX_LINK_PLAYERS];
u8 gBlockRequestType;
u8 gLastSendQueueCount;
struct Link gLink;
u8 gLastRecvQueueCount;
u16 gLinkSavedIme;

#ifdef GERMAN
u8 deUnkValue1;
u8 deUnkValue2;
#endif

EWRAM_DATA bool8 gLinkTestDebugValuesEnabled = {0};
EWRAM_DATA bool8 gLinkTestDummyBool = {0};
EWRAM_DATA u32 gFiller_20238B8 = {0};
EWRAM_DATA u32 dword_20238BC = {0};
EWRAM_DATA bool8 gLinkOpen = {0};

static const u16 sLinkTestDigitPalette[] = INCBIN_U16("graphics/interface/link_test_digits.gbapal");
static const u32 sLinkTestDigitTiles[] = INCBIN_U32("graphics/interface/link_test_digits.4bpp");

static const u8 sDebugMessages[7][12] =
{
    _("せつぞく　ちゅうです"),
    _("せつぞく　できません"),
    _("かくにん　ちゅうです"),
    _("かくにん　できました"),
    _("かくにん　できません"),
    _("かくにん　を　かくにん"),
    _("かくにん　は　しっぱい"),
};

static const u8 sColorCodes[] = _("{HIGHLIGHT TRANSPARENT}{COLOR WHITE2}");

const struct BlockRequest sBlockRequestLookupTable[5] =
{
    {gBlockSendBuffer, 200},
    {gBlockSendBuffer, 200},
    {gBlockSendBuffer, 100},
    {gBlockSendBuffer, 220},
    {gBlockSendBuffer, 40},
};

static const u8 sTestString[] = _("テストな");

ALIGNED(4) static const u8 sMagic[] = "GameFreak inc.";

static const u8 sEmptyString[] = _(" ");

void Task_DestroySelf(u8 taskId)
{
    DestroyTask(taskId);
}

static void InitLinkTestBG(u8 paletteNum, u8 bgNum, u8 screenBaseBlock, u8 charBaseBlock)
{
    LoadPalette(sLinkTestDigitPalette, 16 * paletteNum, 32);
    DmaCopy16(3, sLinkTestDigitTiles, BG_CHAR_ADDR(charBaseBlock), 0x220);

    gLinkTestBGInfo.screenBaseBlock = screenBaseBlock;
    gLinkTestBGInfo.paletteNum = paletteNum;

    switch (bgNum)
    {
    case 1:
        REG_BG1CNT = BGCNT_PRIORITY(1) | BGCNT_SCREENBASE(screenBaseBlock) | BGCNT_CHARBASE(charBaseBlock);
        break;
    case 2:
        REG_BG2CNT = BGCNT_PRIORITY(1) | BGCNT_SCREENBASE(screenBaseBlock) | BGCNT_CHARBASE(charBaseBlock);
        break;
    case 3:
        REG_BG3CNT = BGCNT_PRIORITY(1) | BGCNT_SCREENBASE(screenBaseBlock) | BGCNT_CHARBASE(charBaseBlock);
        break;
    }
}

void InitLinkTestBG_Unused(u8 paletteNum, u8 bgNum, u8 screenBaseBlock, u8 charBaseBlock)
{
    LoadPalette(sLinkTestDigitPalette, 16 * paletteNum, 32);
    DmaCopy16(3, sLinkTestDigitTiles, BG_CHAR_ADDR(charBaseBlock), 0x220);

    gLinkTestBGInfo.screenBaseBlock = screenBaseBlock;
    gLinkTestBGInfo.paletteNum = paletteNum;

    *gBGControlRegs[bgNum] = (screenBaseBlock << 8) | (charBaseBlock << 2);
}

void LinkTestScreen(void)
{
    s32 i;
    ResetSpriteData();
    FreeAllSpritePalettes();
    ResetTasks();
    SetVBlankCallback(VBlankCB_LinkTest);
    SetUpWindowConfig(&gWindowConfig_81E6CE4);
    InitMenuWindow((struct WindowConfig *)&gWindowConfig_81E6CE4);
    ResetBlockSend();
    gLinkType = 0x1111;
    OpenLink();
    SeedRng(gMain.vblankCounter1);

    for (i = 0; i < 4; i++)
    {
        // Very weird code, but nothing else seems to match.
        // The following would have the same effect:
        // gSaveBlock2.playerTrainerId[i] = Random();
        u8 *trainerId = gSaveBlock2.playerTrainerId;
        s32 r;
        s32 mask = 0xFF;
        trainerId[i] = (r = Random()) & mask;
    }

    InitLinkTestBG(0, 2, 4, 0);
    REG_DISPCNT = DISPCNT_MODE_0 | DISPCNT_OBJ_ON | DISPCNT_BG0_ON | DISPCNT_BG2_ON | DISPCNT_OBJ_1D_MAP;
    CreateTask(Task_DestroySelf, 0);
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
    sDummy3 = 0;
    InitLocalLinkPlayer();
    CreateTask(Task_PrintTestData, 0);
    SetMainCallback2(CB2_LinkTest);
}

void sub_8007270(u8 a1)
{
    localLinkPlayer.lp_field_18 = a1;
}

static void InitLocalLinkPlayer(void)
{
    s32 i;

    localLinkPlayer.trainerId = gSaveBlock2.playerTrainerId[0]
                              | (gSaveBlock2.playerTrainerId[1] << 8)
                              | (gSaveBlock2.playerTrainerId[2] << 16)
                              | (gSaveBlock2.playerTrainerId[3] << 24);

    for (i = 0; i < (s32)sizeof(localLinkPlayer.name); i++)
        localLinkPlayer.name[i] = gSaveBlock2.playerName[i]; // UB: reads past the end of "playerName" array

    localLinkPlayer.gender = gSaveBlock2.playerGender;
    localLinkPlayer.linkType = gLinkType;
    localLinkPlayer.language = gGameLanguage;
    localLinkPlayer.version = gGameVersion + 0x4000;
    localLinkPlayer.lp_field_2 = 0;
}

static void VBlankCB_LinkTest(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void InitLink(void)
{
    s32 i;

    for (i = 0; i < CMD_LENGTH; i++)
        gSendCmd[i] = 0xEFFF;

    gLinkOpen = TRUE;
    EnableSerial();
}

static void Task_TriggerHandshake(u8 taskId)
{
    gTasks[taskId].data[0]++;

    if (gTasks[taskId].data[0] == 5)
    {
        gShouldAdvanceLinkState = 1;
        DestroyTask(taskId);
    }
}

void OpenLink(void)
{
    s32 i;

    ResetSerial();
    InitLink();

    gLinkCallback = LinkCB_RequestPlayerDataExchange;
    gLinkVSyncDisabled = FALSE;
    gLinkErrorOccurred = FALSE;
    gSuppressLinkErrorMessage = FALSE;

    ResetBlockReceivedFlags();

    sDummy1 = 0;
    byte_3002A68 = 0;
    gLinkDummyBool = FALSE;
    gReceivedRemoteLinkPlayers = FALSE;

    for (i = 0; i < 4; i++)
    {
        gLinkPlayerPending[i] = TRUE;
        u8_array_3002B78[i] = 0;
        u8_array_3002B70[i] = 0;
    }

    CreateTask(Task_TriggerHandshake, 2);
}

void CloseLink(void)
{
    gReceivedRemoteLinkPlayers = FALSE;
    gLinkOpen = FALSE;
    DisableSerial();
}

static void TestBlockTransfer(u32 a1, u32 a2, u32 a3)
{
    u8 i;
    u8 val;

    if (sLinkTestLastBlockSendPos != sBlockSend.pos)
    {
        PrintHex(sBlockSend.pos, 2, 3, 2);
        sLinkTestLastBlockSendPos = sBlockSend.pos;
    }

    for (i = 0; i < MAX_LINK_PLAYERS; i++)
    {
        if (sLinkTestLastBlockRecvPos[i] != sBlockRecv[i].pos)
        {
            PrintHex(sBlockRecv[i].pos, 2, i + 4, 2);
            sLinkTestLastBlockRecvPos[i] = sBlockRecv[i].pos;
        }
    }

    val = GetBlockReceivedStatus();

    if (val == 0xF)
    {
        for (i = 0; i < MAX_LINK_PLAYERS; i++)
        {
            if ((val >> i) & 1)
            {
                gLinkTestBlockChecksums[i] = LinkTestCalcBlockChecksum(&gBlockRecvBuffer[i], sBlockRecv[i].size);
                ResetBlockReceivedFlag(i);
                if (gLinkTestBlockChecksums[i] != 834)
                {
                    gLinkTestDebugValuesEnabled = FALSE;
                    gLinkTestDummyBool = FALSE;
                }
            }
        }
    }
}

static void LinkTestProcessKeyInput(void)
{
    if (gMain.newKeys & A_BUTTON)
        gShouldAdvanceLinkState = 1;
    if (gMain.heldKeys & B_BUTTON)
        InitBlockSend(unk_2004000, 0x2004);
    if (gMain.newKeys & L_BUTTON)
        BeginNormalPaletteFade(-1, 0, 0x10, 0, 2);
    if (gMain.newKeys & START_BUTTON)
        SetSuppressLinkErrorMessage(TRUE);
    if (gMain.newKeys & R_BUTTON)
        TrySavingData(LINK_SAVE);
    if (gMain.newKeys & SELECT_BUTTON)
        sub_800832C();
    if (gLinkTestDebugValuesEnabled)
    {
        u32 vblankCounter1 = gMain.vblankCounter1;
        u8 val = gLinkVSyncDisabled;
        if (!gLinkCallback)
            val = gLinkVSyncDisabled | 0x10;
        SetLinkDebugValues(vblankCounter1, val);
    }
}

static void CB2_LinkTest(void)
{
    LinkTestProcessKeyInput();
    TestBlockTransfer(1, 1, 0);
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

u16 LinkMain2(u16 *heldKeys)
{
    u8 i;

    if (!gLinkOpen)
        return 0;

    for (i = 0; i < CMD_LENGTH; i++)
        gSendCmd[i] = 0;

    gLinkHeldKeys = *heldKeys;

    if (gLinkStatus & LINK_STAT_CONN_ESTABLISHED)
    {
        ProcessRecvCmds(SIO_MULTI_CNT->id);
        if (gLinkCallback)
            gLinkCallback();
        CheckErrorStatus();
    }

    return gLinkStatus;
}

static void HandleReceiveRemoteLinkPlayer(u8 multiplayerId)
{
    u32 pendingLinkPlayerCount = 0;
    s32 i;

    gLinkPlayerPending[multiplayerId] = FALSE;

    for (i = 0; i < GetLinkPlayerCount_2(); i++)
        pendingLinkPlayerCount += gLinkPlayerPending[i];

    if (pendingLinkPlayerCount == 0 && !gReceivedRemoteLinkPlayers)
        gReceivedRemoteLinkPlayers = TRUE;
}

#ifdef DEBUG
__attribute__((naked))
void ProcessRecvCmds(u8 u81)
{
    asm(
        "	push	{r4, r5, r6, r7, lr}\n"
        "	mov	r7, sl\n"
        "	mov	r6, r9\n"
        "	mov	r5, r8\n"
        "	push	{r5, r6, r7}\n"
        "	add	sp, sp, #0xfffffffc\n"
        "	mov	r7, #0x0\n"
        "	ldr	r0, ._86\n"
        "	add	r0, r0, #0x8\n"
        "	mov	sl, r0\n"
        "._163:\n"
        "	ldr	r0, ._86 + 4\n"
        "	lsl	r3, r7, #0x1\n"
        "	add	r2, r3, r0\n"
        "	mov	r1, #0x0\n"
        "	strh	r1, [r2]\n"
        "	ldr	r4, ._86\n"
        "	add	r1, r3, r4\n"
        "	ldrh	r0, [r1]\n"
        "	mov	r8, r3\n"
        "	add	r5, r7, #1\n"
        "	str	r5, [sp]\n"
        "	cmp	r0, #0\n"
        "	bne	._74	@cond_branch\n"
        "	b	._159\n"
        "._74:\n"
        "	ldrh	r1, [r1]\n"
        "	ldr	r0, ._86 + 8\n"
        "	cmp	r1, r0\n"
        "	bne	._76	@cond_branch\n"
        "	b	._77\n"
        "._76:\n"
        "	cmp	r1, r0\n"
        "	bgt	._78	@cond_branch\n"
        "	ldr	r0, ._86 + 12\n"
        "	cmp	r1, r0\n"
        "	bne	._79	@cond_branch\n"
        "	b	._103\n"
        "._79:\n"
        "	cmp	r1, r0\n"
        "	bgt	._81	@cond_branch\n"
        "	ldr	r0, ._86 + 16\n"
        "	cmp	r1, r0\n"
        "	beq	._82	@cond_branch\n"
        "	ldr	r0, ._86 + 20\n"
        "	cmp	r1, r0\n"
        "	bne	._83	@cond_branch\n"
        "	b	._84\n"
        "._83:\n"
        "	b	._159\n"
        "._87:\n"
        "	.align	2, 0\n"
        "._86:\n"
        "	.word	gRecvCmds\n"
        "	.word	word_3002910\n"
        "	.word	0x5fff\n"
        "	.word	0x4444\n"
        "	.word	0x2222\n"
        "	.word	0x2ffe\n"
        "._81:\n"
        "	ldr	r0, ._91\n"
        "	cmp	r1, r0\n"
        "	beq	._89	@cond_branch\n"
        "	add	r0, r0, #0x11\n"
        "	cmp	r1, r0\n"
        "	beq	._89	@cond_branch\n"
        "	b	._159\n"
        "._92:\n"
        "	.align	2, 0\n"
        "._91:\n"
        "	.word	0x5555\n"
        "._78:\n"
        "	ldr	r0, ._100\n"
        "	cmp	r1, r0\n"
        "	bne	._93	@cond_branch\n"
        "	b	._94\n"
        "._93:\n"
        "	cmp	r1, r0\n"
        "	bgt	._95	@cond_branch\n"
        "	ldr	r0, ._100 + 4\n"
        "	cmp	r1, r0\n"
        "	beq	._96	@cond_branch\n"
        "	ldr	r0, ._100 + 8\n"
        "	cmp	r1, r0\n"
        "	bne	._97	@cond_branch\n"
        "	b	._98\n"
        "._97:\n"
        "	b	._159\n"
        "._101:\n"
        "	.align	2, 0\n"
        "._100:\n"
        "	.word	0xaaab\n"
        "	.word	0x8888\n"
        "	.word	0xaaaa\n"
        "._95:\n"
        "	ldr	r0, ._107\n"
        "	cmp	r1, r0\n"
        "	bne	._102	@cond_branch\n"
        "	b	._103\n"
        "._102:\n"
        "	cmp	r1, r0\n"
        "	bgt	._104	@cond_branch\n"
        "	ldr	r0, ._107 + 4\n"
        "	cmp	r1, r0\n"
        "	beq	._105	@cond_branch\n"
        "	b	._159\n"
        "._108:\n"
        "	.align	2, 0\n"
        "._107:\n"
        "	.word	0xcafe\n"
        "	.word	0xbbbb\n"
        "._104:\n"
        "	ldr	r0, ._112\n"
        "	cmp	r1, r0\n"
        "	bne	._109	@cond_branch\n"
        "	b	._110\n"
        "._109:\n"
        "	b	._159\n"
        "._113:\n"
        "	.align	2, 0\n"
        "._112:\n"
        "	.word	0xcccc\n"
        "._82:\n"
        "	bl	InitLocalLinkPlayer\n"
        "	ldr	r0, ._115\n"
        "	add	r2, r0, #0\n"
        "	add	r2, r2, #0x10\n"
        "	ldr	r1, ._115 + 4\n"
        "	ldmia	r1!, {r3, r4, r6}\n"
        "	stmia	r2!, {r3, r4, r6}\n"
        "	ldmia	r1!, {r3, r5, r6}\n"
        "	stmia	r2!, {r3, r5, r6}\n"
        "	ldr	r1, [r1]\n"
        "	str	r1, [r2]\n"
        "	ldr	r4, ._115 + 8\n"
        "	add	r2, r0, #0\n"
        "	add	r1, r4, #0\n"
        "	ldmia	r1!, {r3, r5, r6}\n"
        "	stmia	r2!, {r3, r5, r6}\n"
        "	ldrh	r3, [r1]\n"
        "	strh	r3, [r2]\n"
        "	ldrb	r1, [r1, #0x2]\n"
        "	strb	r1, [r2, #0x2]\n"
        "	add	r1, r0, #0\n"
        "	add	r1, r1, #0x2c\n"
        "	ldmia	r4!, {r2, r5, r6}\n"
        "	stmia	r1!, {r2, r5, r6}\n"
        "	ldrh	r2, [r4]\n"
        "	strh	r2, [r1]\n"
        "	ldrb	r2, [r4, #0x2]\n"
        "	strb	r2, [r1, #0x2]\n"
        "	mov	r1, #0x3c\n"
        "	bl	InitBlockSend\n"
        "	b	._159\n"
        "._116:\n"
        "	.align	2, 0\n"
        "._115:\n"
        "	.word	localLinkPlayerBlock\n"
        "	.word	localLinkPlayer\n"
        "	.word	sMagic\n"
        "._89:\n"
        "	ldr	r1, ._118\n"
        "	mov	r0, #0x1\n"
        "	strb	r0, [r1]\n"
        "	b	._159\n"
        "._119:\n"
        "	.align	2, 0\n"
        "._118:\n"
        "	.word	byte_3002A68\n"
        "._105:\n"
        "	add	r1, r3, r7\n"
        "	lsl	r1, r1, #0x2\n"
        "	ldr	r5, ._121\n"
        "	add	r1, r1, r5\n"
        "	mov	r6, #0x0\n"
        "	strh	r6, [r1]\n"
        "	mov	r2, sl\n"
        "	add	r0, r3, r2\n"
        "	ldrh	r0, [r0]\n"
        "	strh	r0, [r1, #0x2]\n"
        "	ldr	r0, ._121 + 4\n"
        "	add	r0, r0, #0x10\n"
        "	add	r0, r3, r0\n"
        "	ldrh	r0, [r0]\n"
        "	strb	r0, [r1, #0x9]\n"
        "	b	._159\n"
        "._122:\n"
        "	.align	2, 0\n"
        "._121:\n"
        "	.word	sBlockRecv\n"
        "	.word	gRecvCmds\n"
        "._96:\n"
        "	add	r0, r3, r7\n"
        "	lsl	r0, r0, #0x2\n"
        "	ldr	r5, ._126\n"
        "	add	r4, r0, r5\n"
        "	ldrh	r1, [r4, #0x2]\n"
        "	mov	r0, #0x80\n"
        "	lsl	r0, r0, #0x1\n"
        "	add	r6, r5, #0\n"
        "	mov	r9, r6\n"
        "	cmp	r1, r0\n"
        "	bls	._123	@cond_branch\n"
        "	ldr	r6, ._126 + 4\n"
        "	mov	r2, #0x0\n"
        "	add	r5, r3, #0\n"
        "	add	r3, r4, #0\n"
        "	ldr	r4, ._126 + 8\n"
        "._124:\n"
        "	ldrh	r1, [r3]\n"
        "	lsr	r1, r1, #0x1\n"
        "	add	r1, r1, r2\n"
        "	lsl	r1, r1, #0x1\n"
        "	add	r1, r1, r6\n"
        "	add	r2, r2, #0x1\n"
        "	lsl	r0, r2, #0x3\n"
        "	add	r0, r5, r0\n"
        "	add	r0, r0, r4\n"
        "	ldrh	r0, [r0]\n"
        "	strh	r0, [r1]\n"
        "	lsl	r2, r2, #0x10\n"
        "	lsr	r2, r2, #0x10\n"
        "	cmp	r2, #0x6\n"
        "	bls	._124	@cond_branch\n"
        "	b	._125\n"
        "._127:\n"
        "	.align	2, 0\n"
        "._126:\n"
        "	.word	sBlockRecv\n"
        "	.word	+0x2000000\n"
        "	.word	gRecvCmds\n"
        "._123:\n"
        "	mov	r2, #0x0\n"
        "	ldr	r0, ._135\n"
        "	mov	ip, r0\n"
        "	add	r5, r3, #0\n"
        "	ldr	r6, ._135 + 4\n"
        "	lsl	r3, r7, #0x8\n"
        "._128:\n"
        "	ldrh	r1, [r4]\n"
        "	lsr	r1, r1, #0x1\n"
        "	add	r1, r1, r2\n"
        "	lsl	r1, r1, #0x1\n"
        "	add	r1, r1, r3\n"
        "	add r1, r1, ip\n"
        "	add	r2, r2, #0x1\n"
        "	lsl	r0, r2, #0x3\n"
        "	add	r0, r5, r0\n"
        "	add	r0, r0, r6\n"
        "	ldrh	r0, [r0]\n"
        "	strh	r0, [r1]\n"
        "	lsl	r2, r2, #0x10\n"
        "	lsr	r2, r2, #0x10\n"
        "	cmp	r2, #0x6\n"
        "	bls	._128	@cond_branch\n"
        "._125:\n"
        "	mov	r2, r8\n"
        "	add	r1, r2, r7\n"
        "	lsl	r1, r1, #0x2\n"
        "	add r1, r1, r9\n"
        "	ldrh	r0, [r1]\n"
        "	add	r0, r0, #0xe\n"
        "	strh	r0, [r1]\n"
        "	lsl	r0, r0, #0x10\n"
        "	lsr	r0, r0, #0x10\n"
        "	ldrh	r1, [r1, #0x2]\n"
        "	cmp	r0, r1\n"
        "	bcs	._129	@cond_branch\n"
        "	b	._159\n"
        "._129:\n"
        "	ldr	r0, ._135 + 8\n"
        "	add	r0, r7, r0\n"
        "	ldrb	r0, [r0]\n"
        "	cmp	r0, #0x1\n"
        "	bne	._131	@cond_branch\n"
        "	lsl	r1, r7, #0x8\n"
        "	ldr	r0, ._135\n"
        "	add	r5, r1, r0\n"
        "	lsl	r4, r7, #0x3\n"
        "	sub	r1, r4, r7\n"
        "	lsl	r1, r1, #0x2\n"
        "	ldr	r0, ._135 + 12\n"
        "	add	r1, r1, r0\n"
        "	add	r0, r5, #0\n"
        "	add	r0, r0, #0x10\n"
        "	ldmia	r0!, {r2, r3, r6}\n"
        "	stmia	r1!, {r2, r3, r6}\n"
        "	ldmia	r0!, {r2, r3, r6}\n"
        "	stmia	r1!, {r2, r3, r6}\n"
        "	ldr	r0, [r0]\n"
        "	str	r0, [r1]\n"
        "	ldr	r6, ._135 + 16\n"
        "	add	r0, r5, #0\n"
        "	add	r1, r6, #0\n"
        "	bl	gScriptFuncs_End+0x5c78\n"
        "	cmp	r0, #0\n"
        "	bne	._132	@cond_branch\n"
        "	add	r0, r5, #0\n"
        "	add	r0, r0, #0x2c\n"
        "	add	r1, r6, #0\n"
        "	bl	gScriptFuncs_End+0x5c78\n"
        "	cmp	r0, #0\n"
        "	beq	._133	@cond_branch\n"
        "._132:\n"
        "	ldr	r0, ._135 + 20\n"
        "	bl	SetMainCallback2\n"
        "	b	._134\n"
        "._136:\n"
        "	.align	2, 0\n"
        "._135:\n"
        "	.word	gBlockRecvBuffer\n"
        "	.word	gRecvCmds\n"
        "	.word	gLinkPlayerPending\n"
        "	.word	gLinkPlayers\n"
        "	.word	sMagic\n"
        "	.word	CB2_LinkError+1\n"
        "._133:\n"
        "	lsl	r0, r7, #0x18\n"
        "	lsr	r0, r0, #0x18\n"
        "	bl	HandleReceiveRemoteLinkPlayer\n"
        "._134:\n"
        "	sub	r2, r4, r7\n"
        "	lsl	r2, r2, #0x2\n"
        "	ldr	r1, ._138\n"
        "	add	r0, r2, r1\n"
        "	add	r1, r1, r2\n"
        "	ldrb	r1, [r1, #0x12]\n"
        "	bl	ConvertInternationalString\n"
        "	b	._159\n"
        "._139:\n"
        "	.align	2, 0\n"
        "._138:\n"
        "	.word	gLinkPlayers+0x8\n"
        "._131:\n"
        "	lsl	r4, r7, #0x18\n"
        "	lsr	r4, r4, #0x18\n"
        "	add	r0, r4, #0\n"
        "	bl	SetBlockReceivedFlag\n"
        "	add	r0, r4, #0\n"
        "	bl	debug_sub_808B838\n"
        "	b	._159\n"
        "._77:\n"
        "	ldr	r0, ._142\n"
        "	b	._141\n"
        "._143:\n"
        "	.align	2, 0\n"
        "._142:\n"
        "	.word	u8_array_3002B78\n"
        "._84:\n"
        "	ldr	r0, ._145\n"
        "._141:\n"
        "	add	r0, r7, r0\n"
        "	mov	r1, #0x1\n"
        "	strb	r1, [r0]\n"
        "	b	._159\n"
        "._146:\n"
        "	.align	2, 0\n"
        "._145:\n"
        "	.word	u8_array_3002B70\n"
        "._98:\n"
        "	bl	sub_8007E24\n"
        "	b	._159\n"
        "._94:\n"
        "	lsl	r0, r7, #0x18\n"
        "	lsr	r0, r0, #0x18\n"
        "	mov	r4, sl\n"
        "	add	r1, r3, r4\n"
        "	ldrh	r1, [r1]\n"
        "	bl	sub_80516C4\n"
        "	b	._159\n"
        "._110:\n"
        "	ldr	r4, ._151\n"
        "	ldrb	r0, [r4]\n"
        "	cmp	r0, #0x1\n"
        "	bne	._149	@cond_branch\n"
        "	mov	r0, #0x2\n"
        "	strb	r0, [r4]\n"
        "	ldr	r1, ._151 + 4\n"
        "	mov	r5, sl\n"
        "	add	r0, r3, r5\n"
        "	ldrh	r0, [r0]\n"
        "	strb	r0, [r1]\n"
        "	b	._159\n"
        "._152:\n"
        "	.align	2, 0\n"
        "._151:\n"
        "	.word	deUnkValue2\n"
        "	.word	deUnkValue1\n"
        "._149:\n"
        "	sub	r0, r0, #0x2\n"
        "	lsl	r0, r0, #0x18\n"
        "	lsr	r0, r0, #0x18\n"
        "	cmp	r0, #0x1\n"
        "	bhi	._153	@cond_branch\n"
        "	mov	r6, sl\n"
        "	add	r0, r3, r6\n"
        "	ldrh	r0, [r0]\n"
        "	lsl	r0, r0, #0x3\n"
        "	ldr	r2, ._156\n"
        "	add	r1, r0, r2\n"
        "	ldr	r1, [r1]\n"
        "	ldr	r3, ._156 + 4\n"
        "	add	r0, r0, r3\n"
        "	ldrh	r2, [r0]\n"
        "	mov	r0, #0x0\n"
        "	bl	SendBlock\n"
        "	ldrb	r0, [r4]\n"
        "	cmp	r0, #0x2\n"
        "	bne	._154	@cond_branch\n"
        "	mov	r0, #0x1\n"
        "	strb	r0, [r4]\n"
        "	b	._159\n"
        "._157:\n"
        "	.align	2, 0\n"
        "._156:\n"
        "	.word	sBlockRequestLookupTable\n"
        "	.word	sBlockRequestLookupTable+0x4\n"
        "._154:\n"
        "	mov	r5, #0x0\n"
        "	strb	r5, [r4]\n"
        "	add	r6, r7, #1\n"
        "	str	r6, [sp]\n"
        "	b	._159\n"
        "._153:\n"
        "	mov	r1, sl\n"
        "	add	r0, r3, r1\n"
        "	ldrh	r0, [r0]\n"
        "	lsl	r0, r0, #0x3\n"
        "	ldr	r2, ._160\n"
        "	add	r1, r0, r2\n"
        "	ldr	r1, [r1]\n"
        "	ldr	r3, ._160 + 4\n"
        "	add	r0, r0, r3\n"
        "	ldrh	r2, [r0]\n"
        "	mov	r0, #0x0\n"
        "	bl	SendBlock\n"
        "	b	._159\n"
        "._161:\n"
        "	.align	2, 0\n"
        "._160:\n"
        "	.word	sBlockRequestLookupTable\n"
        "	.word	sBlockRequestLookupTable+0x4\n"
        "._103:\n"
        "	mov	r4, sl\n"
        "	add	r0, r3, r4\n"
        "	ldrh	r0, [r0]\n"
        "	strh	r0, [r2]\n"
        "._159:\n"
        "	ldr	r5, [sp]\n"
        "	lsl	r0, r5, #0x10\n"
        "	lsr	r7, r0, #0x10\n"
        "	cmp	r7, #0x3\n"
        "	bhi	._162	@cond_branch\n"
        "	b	._163\n"
        "._162:\n"
        "	add	sp, sp, #0x4\n"
        "	pop	{r3, r4, r5}\n"
        "	mov	r8, r3\n"
        "	mov	r9, r4\n"
        "	mov	sl, r5\n"
        "	pop	{r4, r5, r6, r7}\n"
        "	pop	{r0}\n"
        "	bx	r0\n"
        "\n"
    );
}
#else
static void ProcessRecvCmds(u8 unusedParam)
{
    u16 i;
    for (i = 0; i < MAX_LINK_PLAYERS; i++)
    {
        word_3002910[i] = 0;
        if (!gRecvCmds[0][i])
            continue;
        switch (gRecvCmds[0][i])
        {
        case 0x2222:
            InitLocalLinkPlayer();
            localLinkPlayerBlock.linkPlayer = localLinkPlayer;
            memcpy(localLinkPlayerBlock.magic1, sMagic, sizeof(localLinkPlayerBlock.magic1) - 1);
            memcpy(localLinkPlayerBlock.magic2, sMagic, sizeof(localLinkPlayerBlock.magic2) - 1);
            InitBlockSend(&localLinkPlayerBlock, sizeof(localLinkPlayerBlock));
            break;
        case 0x4444:
            word_3002910[i] = gRecvCmds[1][i];
            break;
        case 0x5555:
            byte_3002A68 = 1;
            break;
        case 0x5566:
            byte_3002A68 = 1;
            break;
        case 0xBBBB:
        {
            struct BlockTransfer *blockRecv = &sBlockRecv[i];
            blockRecv->pos = 0;
            blockRecv->size = gRecvCmds[1][i];
            blockRecv->multiplayerId = gRecvCmds[2][i];
            break;
        }
        case 0x8888:
            if (sBlockRecv[i].size > BLOCK_BUFFER_SIZE)
            {
                u16 *buffer = (u16 *)unk_2000000;
                u16 j;
                for (j = 0; j < CMD_LENGTH - 1; j++)
                    buffer[(sBlockRecv[i].pos / 2) + j] = gRecvCmds[j + 1][i];
            }
            else
            {
                u16 j;
                for (j = 0; j < CMD_LENGTH - 1; j++)
                    gBlockRecvBuffer[i][(sBlockRecv[i].pos / 2) + j] = gRecvCmds[j + 1][i];
            }

            sBlockRecv[i].pos += (CMD_LENGTH - 1) * 2;

            if (sBlockRecv[i].pos >= sBlockRecv[i].size)
            {
                if (gLinkPlayerPending[i] == TRUE)
                {
                    struct LinkPlayerBlock *block = (struct LinkPlayerBlock *)&gBlockRecvBuffer[i];
                    struct LinkPlayer *linkPlayer = &gLinkPlayers[i];
                    *linkPlayer = block->linkPlayer;

                    if (strcmp(block->magic1, sMagic)
                     || strcmp(block->magic2, sMagic))
                    {
                        SetMainCallback2(CB2_LinkError);
                    }
                    else
                    {
                        HandleReceiveRemoteLinkPlayer(i);
                    }

                    ConvertInternationalString(gLinkPlayers[i].name, gLinkPlayers[i].language);
                }
                else
                {
                    SetBlockReceivedFlag(i);
                }
            }
            break;
        case 0x5FFF:
            u8_array_3002B78[i] = 1;
            break;
        case 0x2FFE:
            u8_array_3002B70[i] = 1;
            break;
        case 0xAAAA:
            sub_8007E24();
            break;
        case 0xAAAB:
            sub_80516C4(i, gRecvCmds[1][i]);
            break;
        case 0xCCCC:
#if defined(ENGLISH)
            SendBlock(0, sBlockRequestLookupTable[gRecvCmds[1][i]].address, sBlockRequestLookupTable[gRecvCmds[1][i]].size);
#elif defined(GERMAN)
            if (deUnkValue2 == 1)
            {
                deUnkValue2 = 2;
                deUnkValue1 = gRecvCmds[1][i];
            }
            else if (deUnkValue2 == 2 || deUnkValue2 == 3)
            {
                SendBlock(0, sBlockRequestLookupTable[gRecvCmds[1][i]].address, sBlockRequestLookupTable[gRecvCmds[1][i]].size);

                if (deUnkValue2 == 2)
                    deUnkValue2 = 1;
                else
                    deUnkValue2 = 0;
            }
            else
            {
                SendBlock(0, sBlockRequestLookupTable[gRecvCmds[1][i]].address, sBlockRequestLookupTable[gRecvCmds[1][i]].size);
            }
#endif
            break;
        case 0xCAFE:
            word_3002910[i] = gRecvCmds[1][i];
            break;
        }
    }
}
#endif

static void BuildSendCmd(u16 code)
{
    switch (code)
    {
    case 0x2222:
        gSendCmd[0] = 0x2222;
        gSendCmd[1] = gLinkType;
        break;
    case 0x2FFE:
        gSendCmd[0] = 0x2FFE;
        break;
    case 0x4444:
        gSendCmd[0] = 0x4444;
        gSendCmd[1] = gMain.heldKeys;
        break;
    case 0x5555:
        gSendCmd[0] = 0x5555;
        break;
    case 0x5566:
        gSendCmd[0] = 0x5566;
        break;
    case 0x6666:
        gSendCmd[0] = 0x6666;
        gSendCmd[1] = 0;
        break;
    case 0x7777:
    {
        u8 i;

        gSendCmd[0] = 0x7777;

        for (i = 0; i < 5; i++)
            gSendCmd[i + 1] = 0xEE;

        break;
    }
    case 0xBBBB:
        gSendCmd[0] = 0xBBBB;
        gSendCmd[1] = sBlockSend.size;
        gSendCmd[2] = sBlockSend.multiplayerId + 128;
        break;
    case 0xAAAA:
        gSendCmd[0] = 0xAAAA;
        break;
    case 0xAAAB:
        gSendCmd[0] = 0xAAAB;
        gSendCmd[1] = gScriptItemId;
        break;
    case 0xCCCC:
        gSendCmd[0] = 0xCCCC;
        gSendCmd[1] = gBlockRequestType;
        break;
    case 0x5FFF:
        gSendCmd[0] = 0x5FFF;
        break;
    case 0xCAFE:
        if (!word_3004858 || gLinkTransferringData)
            break;
        gSendCmd[0] = 0xCAFE;
        gSendCmd[1] = word_3004858;
        break;
    }
}

void sub_8007B14(void)
{
    gLinkCallback = sub_8007B44;
}

bool32 sub_8007B24(void)
{
    if (gLinkCallback == sub_8007B44)
        return TRUE;
    else
        return FALSE;
}

static void sub_8007B44(void)
{
    if (gReceivedRemoteLinkPlayers == TRUE)
        BuildSendCmd(0xCAFE);
}

void ClearLinkCallback(void)
{
    gLinkCallback = NULL;
}

void ClearLinkCallback_2(void)
{
    gLinkCallback = NULL;
}

u8 GetLinkPlayerCount(void)
{
    return EXTRACT_PLAYER_COUNT(gLinkStatus);
}

void OpenLinkTimed(void)
{
    sPlayerDataExchangeStatus = EXCHANGE_NOT_STARTED;
    gLinkTimeOutCounter = 0;
#if defined(GERMAN)
    ResetBlockSend();
#endif
    OpenLink();
}

u8 GetLinkPlayerDataExchangeStatusTimed(void)
{
    s32 i;
    s32 count = 0;
    u32 index;

    if (gReceivedRemoteLinkPlayers == TRUE)
    {
        if (GetLinkPlayerCount() == 0)
        {
            gLinkErrorOccurred = TRUE;
            CloseLink();
        }

        i = 0;
        index = 0;

        while (i < GetLinkPlayerCount())
        {
            if (gLinkPlayers[index].linkType == gLinkPlayers[0].linkType)
                ++count;
            ++index;
            ++i;
        }

        if (count == GetLinkPlayerCount())
            sPlayerDataExchangeStatus = EXCHANGE_COMPLETE;
        else
            sPlayerDataExchangeStatus = EXCHANGE_IN_PROGRESS;
    }
    else
    {
        gLinkTimeOutCounter++;
        if (gLinkTimeOutCounter > 600)
            sPlayerDataExchangeStatus = EXCHANGE_TIMED_OUT;
    }

    return sPlayerDataExchangeStatus;
}

bool8 IsLinkPlayerDataExchangeComplete(void)
{
    u8 i;
    u8 count = 0;
    u8 isComplete;

    for (i = 0; i < GetLinkPlayerCount(); i++)
        if (gLinkPlayers[i].linkType == gLinkPlayers[0].linkType)
            count++;

    if (count == GetLinkPlayerCount())
    {
        isComplete = TRUE;
        sPlayerDataExchangeStatus = EXCHANGE_COMPLETE;
    }
    else
    {
        isComplete = FALSE;
        sPlayerDataExchangeStatus = EXCHANGE_IN_PROGRESS;
    }

    return isComplete;
}

u32 GetLinkPlayerTrainerId(u8 multiplayerId)
{
    return gLinkPlayers[multiplayerId].trainerId;
}

void ResetLinkPlayers(void)
{
    s32 i;
    for (i = 0; i < 4; i++)
        memset(&gLinkPlayers[i], 0, sizeof(struct LinkPlayer));
}

static void ResetBlockSend(void)
{
    sBlockSend.active = FALSE;
    sBlockSend.pos = 0;
    sBlockSend.size = 0;
    sBlockSend.src = NULL;
}

static bool8 InitBlockSend(void *data, u32 size)
{
    if (sBlockSend.active)
    {
        return FALSE;
    }
    else
    {
        sBlockSend.multiplayerId = GetMultiplayerId();
        sBlockSend.active = TRUE;
        sBlockSend.size = size;
        sBlockSend.pos = 0;

        if (size > BLOCK_BUFFER_SIZE)
        {
            sBlockSend.src = data;
        }
        else
        {
            if (data != gBlockSendBuffer)
                memcpy(gBlockSendBuffer, data, size);
            sBlockSend.src = gBlockSendBuffer;
        }

        BuildSendCmd(0xBBBB);
        gLinkCallback = LinkCB_BlockSendBegin;
        sBlockSendDelayCounter = 0;
        return TRUE;
    }
}

static void LinkCB_BlockSendBegin(void)
{
    sBlockSendDelayCounter++;
    if (sBlockSendDelayCounter > 2)
        gLinkCallback = LinkCB_BlockSend;
}

static void LinkCB_BlockSend(void)
{
    s32 i;
    u8 *buffer = sBlockSend.src;

    gSendCmd[0] = 0x8888;

    for (i = 0; i < CMD_LENGTH - 1; i++)
    {
        s32 offset = sBlockSend.pos + 2 * i;
        gSendCmd[i + 1] = (buffer[offset + 1] << 8) | buffer[offset];
    }

    sBlockSend.pos += (CMD_LENGTH - 1) * 2;

    if (sBlockSend.size <= sBlockSend.pos)
    {
        sBlockSend.active = FALSE;
        gLinkCallback = LinkCB_BlockSendEnd;
    }
}

static void LinkCB_BlockSendEnd(void)
{
    gLinkCallback = NULL;
}

static void sub_8007E04(void)
{
    GetMultiplayerId(); // whats the point of calling this if you dont use the multiplayer ID?
    BuildSendCmd(0x4444);
    dword_20238BC++;
}

void sub_8007E24(void)
{
    dword_20238BC = 0;
    gLinkCallback = sub_8007E04;
}

u32 sub_8007E40(void)
{
    return dword_20238BC;
}

void sub_8007E4C(void)
{
    BuildSendCmd(0xAAAA);
}

u8 GetMultiplayerId(void)
{
    return SIO_MULTI_CNT->id;
}

u8 bitmask_all_link_players_but_self(void)
{
    return ((1 << GetMultiplayerId()) ^ 0xF);
}

bool8 SendBlock(u8 a1, void *a2, u16 a3)
{
    return InitBlockSend(a2, a3);
}

bool8 sub_8007E9C(u8 a1)
{
    if (!gLinkCallback)
    {
        gBlockRequestType = a1;
        BuildSendCmd(0xCCCC);
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

bool8 sub_8007ECC(void)
{
    u8 retVal = FALSE;

    if (!gLinkCallback)
        retVal = TRUE;

    return retVal;
}

u8 GetBlockReceivedStatus(void)
{
    return (gBlockReceived[3] << 3)
         | (gBlockReceived[2] << 2)
         | (gBlockReceived[1] << 1)
         | gBlockReceived[0];
}

static void SetBlockReceivedFlag(u8 multiplayerId)
{
    gBlockReceived[multiplayerId] = TRUE;
}

void ResetBlockReceivedFlags(void)
{
    s32 i;
    for (i = 0; i < 4; i++)
        gBlockReceived[i] = FALSE;
}

void ResetBlockReceivedFlag(u8 multiplayerId)
{
    if (gBlockReceived[multiplayerId])
        gBlockReceived[multiplayerId] = FALSE;
}

void sub_8007F4C(void)
{
    if ((gLinkStatus & LINK_STAT_MASTER) && EXTRACT_PLAYER_COUNT(gLinkStatus) > 1)
        gShouldAdvanceLinkState = 1;
}

static u16 LinkTestCalcBlockChecksum(void *data, u16 size)
{
    u16 sum = 0;
    u16 i;

    for (i = 0; i < size / 2; i++)
        sum += ((u16 *)data)[i];

    return sum;
}

static void PrintHexDigit(u8 tileNum, u8 x, u8 y)
{
    u16 *tilemap = (u16 *)BG_SCREEN_ADDR(gLinkTestBGInfo.screenBaseBlock);
    tilemap[(32 * y) + x] = (gLinkTestBGInfo.paletteNum << 12) | (tileNum + 1);
}

void PrintHex(u32 num, u8 x, u8 y, u8 maxDigits)
{
    u8 buffer[16];
    s32 i;

    for (i = 0; i < maxDigits; i++)
    {
        buffer[i] = num & 0xF;
        num >>= 4;
    }

    for (i = maxDigits - 1; i >= 0; i--)
    {
        PrintHexDigit(buffer[i], x, y);
        x++;
    }
}

#ifdef DEBUG

EWRAM_DATA u8 *unk_20238C4 = NULL;
EWRAM_DATA u32 unk_20238C8 = 0;
EWRAM_DATA u8 *unk_20238CC = NULL;
EWRAM_DATA u32 unk_20238D0 = 0;

void debug_sub_8008218(u8 *buffer, u32 arg1, u8 *arg2, u32 arg3) {
    CpuSet(sLinkTestDigitTiles, buffer, 272);
    unk_20238C4 = buffer;
    unk_20238C8 = arg1;
    unk_20238CC = arg2;
    unk_20238D0 = arg3;
}

__attribute__((naked))
void debug_sub_8008264()
{
    asm(
        "	push	{r4, r5, r6, r7, lr}\n"
        "	mov	r7, r8\n"
        "	push	{r7}\n"
        "	add	sp, sp, #0xffffffe0\n"
        "	add	r5, r0, #0\n"
        "	add	r6, r1, #0\n"
        "	add	r4, r3, #0\n"
        "	ldr	r0, [sp, #0x38]\n"
        "	ldr	r1, ._347\n"
        "	ldr	r1, [r1]\n"
        "	cmp	r1, r0\n"
        "	bne	._345	@cond_branch\n"
        "	cmp	r4, #0x8\n"
        "	ble	._342	@cond_branch\n"
        "	mov	r4, #0x8\n"
        "._342:\n"
        "	mov	r3, sp\n"
        "	ldr	r0, ._347 + 4\n"
        "	mov	r8, r0\n"
        "	lsl	r2, r2, #0x6\n"
        "	mov	ip, r2\n"
        "	lsl	r6, r6, #0x1\n"
        "	lsl	r7, r4, #0x2\n"
        "	cmp	r4, #0\n"
        "	ble	._343	@cond_branch\n"
        "	mov	r1, #0xf\n"
        "	add	r2, r4, #0\n"
        "._344:\n"
        "	add	r0, r5, #0\n"
        "	and	r0, r0, r1\n"
        "	stmia	r3!, {r0}\n"
        "	lsr	r5, r5, #0x4\n"
        "	sub	r2, r2, #0x1\n"
        "	cmp	r2, #0\n"
        "	bne	._344	@cond_branch\n"
        "._343:\n"
        "	mov	r1, r8\n"
        "	ldr	r0, [r1]\n"
        "	add r0, r0, ip\n"
        "	add	r5, r0, r6\n"
        "	mov	r1, sp\n"
        "	add	r0, r1, r7\n"
        "	sub	r3, r0, #4\n"
        "	cmp	r4, #0\n"
        "	ble	._345	@cond_branch\n"
        "	ldr	r7, ._347 + 8\n"
        "	ldr	r6, ._347 + 12\n"
        "	add	r2, r4, #0\n"
        "._346:\n"
        "	ldr	r1, [r7]\n"
        "	ldr	r0, [r6]\n"
        "	sub	r1, r1, r0\n"
        "	lsr	r1, r1, #0x5\n"
        "	ldr	r0, [r3]\n"
        "	add	r0, r0, r1\n"
        "	add	r0, r0, #0x1\n"
        "	strh	r0, [r5]\n"
        "	sub	r3, r3, #0x4\n"
        "	add	r5, r5, #0x2\n"
        "	sub	r2, r2, #0x1\n"
        "	cmp	r2, #0\n"
        "	bne	._346	@cond_branch\n"
        "._345:\n"
        "	add	sp, sp, #0x20\n"
        "	pop	{r3}\n"
        "	mov	r8, r3\n"
        "	pop	{r4, r5, r6, r7}\n"
        "	pop	{r0}\n"
        "	bx	r0\n"
        "._348:\n"
        "	.align	2, 0\n"
        "._347:\n"
        "	.word	unk_20238D0\n"
        "	.word	unk_20238CC\n"
        "	.word	unk_20238C4\n"
        "	.word	unk_20238C8\n"
        "\n"
    );
}

#endif

static void LinkCB_RequestPlayerDataExchange(void)
{
    // Only one request needs to be sent, so only the master sends it.
    if (gLinkStatus & LINK_STAT_MASTER)
        BuildSendCmd(0x2222);
    gLinkCallback = NULL;
}

void Task_PrintTestData(u8 taskId)
{
    s32 i;

    PrintHex(gShouldAdvanceLinkState, 2, 1, 2);
    PrintHex(gLinkStatus, 15, 1, 8);
    PrintHex(gLink.state, 2, 10, 2);
    PrintHex(EXTRACT_PLAYER_COUNT(gLinkStatus), 15, 10, 2);
    PrintHex(GetMultiplayerId(), 15, 12, 2);
    PrintHex(gLastSendQueueCount, 25, 1, 2);
    PrintHex(gLastRecvQueueCount, 25, 2, 2);
    PrintHex(GetBlockReceivedStatus(), 15, 5, 2);
    PrintHex(gLinkDebugValue1, 2, 12, 8);
    PrintHex(gLinkDebugValue2, 2, 13, 8);
    PrintHex(GetSioMultiSI(), 25, 5, 1);
    PrintHex(IsSioMultiMaster(), 25, 6, 1);
    PrintHex(IsLinkConnectionEstablished(), 25, 7, 1);
    PrintHex(HasLinkErrorOccurred(), 25, 8, 1);

    for (i = 0; i < MAX_LINK_PLAYERS; i++)
        PrintHex(gLinkTestBlockChecksums[i], 10, 4 + i, 4);
}

void SetLinkDebugValues(u32 value1, u32 value2)
{
    gLinkDebugValue1 = value1;
    gLinkDebugValue2 = value2;
}

u8 sub_8008198(void)
{
    u8 result = 0;
    s32 i;

    for (i = 0; i < gSavedLinkPlayerCount; i++)
        result |= (1 << i);

    return result;
}

void sub_80081C8(u8 playerCount)
{
    s32 i;

    gSavedLinkPlayerCount = playerCount;
    gSavedMultiplayerId = GetMultiplayerId();

    for (i = 0; i < 4; i++)
        gSavedLinkPlayers[i] = gLinkPlayers[i];
}

u8 sub_800820C(void)
{
    return gSavedLinkPlayerCount;
}

u8 sub_8008218(void)
{
    return gSavedMultiplayerId;
}

bool8 sub_8008224(void)
{
    s32 count = 0;
    s32 i;

    for (i = 0; i < gSavedLinkPlayerCount; i++)
        if (gLinkPlayers[i].trainerId == gSavedLinkPlayers[i].trainerId)
            count++;

    if (count == gSavedLinkPlayerCount)
        return TRUE;
    else
        return FALSE;
}

void sub_800826C(void)
{
    u8 i;

    for (i = 0; i < gSavedLinkPlayerCount; i++)
    {
        if (gSavedLinkPlayers[i].trainerId != gLinkPlayers[i].trainerId
         || StringCompareWithoutExtCtrlCodes(gSavedLinkPlayers[i].name, gLinkPlayers[i].name))
        {
            gLinkErrorOccurred = TRUE;
            CloseLink();
            SetMainCallback2(CB2_LinkError);
        }
    }
}

void sub_80082EC(void)
{
    gSavedLinkPlayerCount = 0;
    gSavedMultiplayerId = 0;
}

u8 GetLinkPlayerCount_2(void)
{
    return EXTRACT_PLAYER_COUNT(gLinkStatus);
}

bool8 IsLinkMaster(void)
{
    return EXTRACT_MASTER(gLinkStatus);
}

u8 GetDummy2(void)
{
    return sDummy2;
}

void sub_800832C(void)
{
    if (!gLinkCallback)
    {
        gLinkCallback = sub_8008350;
        gLinkDummyBool = FALSE;
    }
}

static void sub_8008350(void)
{
    if (gLastRecvQueueCount == 0)
    {
        BuildSendCmd(0x5FFF);
        gLinkCallback = sub_800837C;
    }
}

static void sub_800837C(void)
{
    s32 i;
    s32 totalCount = GetLinkPlayerCount();
    s32 count = 0;

    for (i = 0; i < totalCount; i++)
        if (u8_array_3002B78[i])
            count++;

    if (count == totalCount)
    {
        gBattleTypeFlags &= ~BATTLE_TYPE_20;
        gLinkVSyncDisabled = TRUE;
        CloseLink();
        gLinkCallback = NULL;
        gLinkDummyBool = TRUE;
    }
}

static void sub_80083E0(void)
{
    s32 i;
    s32 totalCount = GetLinkPlayerCount();
    s32 count = 0;

    for (i = 0; i < totalCount; i++)
    {
        if (gLinkPlayers[i].language == 1)
            count++;
        else if (u8_array_3002B78[i])
            count++;
    }

    if (count == totalCount)
    {
        gBattleTypeFlags &= ~BATTLE_TYPE_20;
        gLinkVSyncDisabled = TRUE;
        CloseLink();
        gLinkCallback = 0;
        gLinkDummyBool = TRUE;
    }
}

static void sub_8008454(void)
{
    if (gLastRecvQueueCount == 0)
    {
        BuildSendCmd(0x5FFF);
        gLinkCallback = sub_80083E0;
    }
}

void sub_8008480(void)
{
    if (!gLinkCallback)
    {
        gLinkCallback = sub_8008454;
        gLinkDummyBool = FALSE;
    }
}

void sub_80084A4(void)
{
    if (!gLinkCallback)
        gLinkCallback = sub_80084C8;
    gLinkDummyBool = FALSE;
}

static void sub_80084C8(void)
{
    if (gLastRecvQueueCount == 0)
    {
        BuildSendCmd(0x2FFE);
        gLinkCallback = sub_80084F4;
    }
}

static void sub_80084F4(void)
{
    u8 totalCount = GetLinkPlayerCount();
    u8 count = 0;

    while (count < totalCount && u8_array_3002B70[count])
        count++;

    if (count == totalCount)
    {
        u8 i;
        for (i = 0; i < 4; i++)
            u8_array_3002B70[i] = 0;
        gLinkCallback = NULL;
    }
}

static void CheckErrorStatus(void)
{
    if (gLinkOpen)
    {
        if (gLinkStatus & LINK_STAT_ERRORS)
        {
            if (!gSuppressLinkErrorMessage)
            {
                sErrorLinkStatus = gLinkStatus;
                sErrorLastRecvQueueCount = gLastRecvQueueCount;
                sErrorLastSendQueueCount = gLastSendQueueCount;
                SetMainCallback2(CB2_LinkError);
            }
            gLinkErrorOccurred = TRUE;
            CloseLink();
        }
    }
}

void CB2_LinkError(void)
{
    ResetSpriteData();
    FreeAllSpritePalettes();
    ResetPaletteFadeControl();
    FillPalette(0, 0, 2);
    ResetTasks();
    SetVBlankCallback(VBlankCB_LinkTest);
    SetUpWindowConfig(&gWindowConfig_81E7198);
    InitMenuWindow((struct WindowConfig *)&gWindowConfig_81E7198);
    MenuZeroFillScreen();
    REG_BLDALPHA = 0;
    REG_BG0VOFS = 0;
    REG_BG0HOFS = 0;
    REG_DISPCNT = DISPCNT_MODE_0 | DISPCNT_OBJ_1D_MAP | DISPCNT_BG0_ON;
    gSoftResetDisabled = FALSE;
    CreateTask(Task_DestroySelf, 0);
    StopMapMusic();
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
    SetMainCallback2(CB2_PrintErrorMessage);
}

static void CB2_PrintErrorMessage(void)
{
    u8 buffer[0x20] __attribute__((unused)); // unused
    u8 buffer2[0x20] __attribute__((unused)); // unused

    switch (gMain.state)
    {
    case 0:
        MenuPrint_PixelCoords(gMultiText_LinkError, 20, 56, 1);
#ifdef DEBUG
            StringCopy(buffer, sColorCodes);

            ConvertIntToHexStringN(buffer2, sErrorLinkStatus, STR_CONV_MODE_LEADING_ZEROS, 8);
            StringAppend(buffer, buffer2);

            StringAppend(buffer, sEmptyString);

            ConvertIntToHexStringN(buffer2, sErrorLastSendQueueCount, STR_CONV_MODE_LEADING_ZEROS, 2);
            StringAppend(buffer, buffer2);

            StringAppend(buffer, sEmptyString);

            ConvertIntToHexStringN(buffer2, sErrorLastRecvQueueCount, STR_CONV_MODE_LEADING_ZEROS, 2);
            StringAppend(buffer, buffer2);

            MenuPrint(buffer, 2, 15);
#endif
        break;
    case 30:
    case 60:
        PlaySE(SE_BOO);
        break;
    case 90:
        PlaySE(SE_BOO);
        break;
    }

    if (gMain.state != 200)
        gMain.state++;
}

u8 GetSioMultiSI(void)
{
    return (REG_SIOCNT >> SIO_MULTI_SI_SHIFT) & SIO_MULTI_SI_MASK;
}

static bool8 IsSioMultiMaster(void)
{
    bool8 isMaster = FALSE;

    if ((REG_SIOCNT & SIO_MULTI_SD) && !(REG_SIOCNT & SIO_MULTI_SI))
        isMaster = TRUE;

    return isMaster;
}

bool8 IsLinkConnectionEstablished(void)
{
    return EXTRACT_CONN_ESTABLISHED(gLinkStatus);
}

void SetSuppressLinkErrorMessage(bool8 value)
{
    gSuppressLinkErrorMessage = value;
}

bool8 HasLinkErrorOccurred(void)
{
    return gLinkErrorOccurred;
}

static void DisableSerial(void)
{
    gLinkSavedIme = REG_IME;
    REG_IME = 0;
    REG_IE &= ~(INTR_FLAG_TIMER3 | INTR_FLAG_SERIAL);
    REG_IME = gLinkSavedIme;

    REG_SIOCNT = 0;
    REG_TM3CNT_H = 0;
    REG_IF = INTR_FLAG_TIMER3 | INTR_FLAG_SERIAL;

    CpuFill32(0, &gLink, sizeof(gLink));
}

static void EnableSerial(void)
{
    gLinkSavedIme = REG_IME;
    REG_IME = 0;
    REG_IE &= ~(INTR_FLAG_TIMER3 | INTR_FLAG_SERIAL);
    REG_IME = gLinkSavedIme;

    REG_RCNT = 0;

    REG_SIOCNT = SIO_MULTI_MODE;
    REG_SIOCNT |= SIO_INTR_ENABLE | SIO_115200_BPS;

    gLinkSavedIme = REG_IME;
    REG_IME = 0;
    REG_IE |= INTR_FLAG_SERIAL;
    REG_IME = gLinkSavedIme;

    REG_SIOMLT_SEND = 0;

    CpuFill32(0, &gLink, sizeof(gLink));

    sNumVBlanksWithoutSerialIntr = 0;
    sSendNonzeroCheck = 0;
    sRecvNonzeroCheck = 0;
    sChecksumAvailable = FALSE;
    sHandshakePlayerCount = 0;
    gLastSendQueueCount = 0;
    gLastRecvQueueCount = 0;
}

void ResetSerial(void)
{
    EnableSerial();
    DisableSerial();
}

u32 LinkMain1(u8 *shouldAdvanceLinkState, u16 *sendCmd, u16 recvCmds[CMD_LENGTH][MAX_LINK_PLAYERS])
{
    u32 retVal;
    u32 retVal2;

    switch (gLink.state)
    {
    case LINK_STATE_START0:
        DisableSerial();
        gLink.state = LINK_STATE_START1;
        break;
    case LINK_STATE_START1:
        if (*shouldAdvanceLinkState == 1)
        {
            EnableSerial();
            gLink.state = LINK_STATE_HANDSHAKE;
        }
        break;
    case LINK_STATE_HANDSHAKE:
        switch (*shouldAdvanceLinkState)
        {
        case 1:
            if (gLink.isMaster == 8 && gLink.playerCount > 1)
                gLink.handshakeAsMaster = TRUE;
            break;
        case 2:
            gLink.state = LINK_STATE_START0;
            REG_SIOMLT_SEND = 0;
            break;
        default:
            CheckMasterOrSlave();
            break;
        }
        break;
    case LINK_STATE_INIT_TIMER:
        InitTimer();
        gLink.state = LINK_STATE_CONN_ESTABLISHED;
    case LINK_STATE_CONN_ESTABLISHED:
        EnqueueSendCmd(sendCmd);
        DequeueRecvCmds(recvCmds);
        break;
    }

    *shouldAdvanceLinkState = 0;

    retVal = gLink.localId;
    retVal |= (gLink.playerCount << 2);

    if (gLink.isMaster == 8)
        retVal |= 0x20;

    {
        u32 receivedNothing = gLink.receivedNothing << 8;
        u32 link_field_F = gLink.link_field_F << 9;
        u32 hardwareError = gLink.hardwareError << 12;
        u32 badChecksum = gLink.badChecksum << 13;
        u32 queueFull = gLink.queueFull << 14;
        u32 val;

        if (gLink.state == LINK_STATE_CONN_ESTABLISHED)
        {
            val = 0x40;
            val |= receivedNothing;
            val |= retVal;
            val |= link_field_F;
            val |= hardwareError;
            val |= badChecksum;
            val |= queueFull;
        }
        else
        {
            val = retVal;
            val |= receivedNothing;
            val |= link_field_F;
            val |= hardwareError;
            val |= badChecksum;
            val |= queueFull;
        }

        retVal = val;
    }

    if (gLink.lag == LAG_MASTER)
        retVal |= 0x10000;

    if (gLink.localId > 3)
        retVal |= 0x20000;

    retVal2 = retVal;
    if (gLink.lag == LAG_SLAVE)
        retVal2 |= 0x40000;

    return retVal2;
}

static void CheckMasterOrSlave(void)
{
    u32 terminals = *(u32 *)REG_ADDR_SIOCNT & (SIO_MULTI_SD | SIO_MULTI_SI);

    if (terminals == SIO_MULTI_SD && !gLink.localId)
        gLink.isMaster = 8;
    else
        gLink.isMaster = 0;
}

static void InitTimer(void)
{
    if (gLink.isMaster)
    {
        REG_TM3CNT_L = 65339;
        REG_TM3CNT_H = TIMER_INTR_ENABLE | TIMER_64CLK;

        gLinkSavedIme = REG_IME;
        REG_IME = 0;
        REG_IE |= INTR_FLAG_TIMER3;
        REG_IME = gLinkSavedIme;
    }
}

static void EnqueueSendCmd(u16 *sendCmd)
{
    gLinkSavedIme = REG_IME;
    REG_IME = 0;

    if (gLink.sendQueue.count < QUEUE_CAPACITY)
    {
        u8 i;
        u8 offset = gLink.sendQueue.pos + gLink.sendQueue.count;

        if (offset >= QUEUE_CAPACITY)
            offset -= QUEUE_CAPACITY;

        for (i = 0; i < CMD_LENGTH; i++)
        {
            sSendNonzeroCheck |= *sendCmd;
            gLink.sendQueue.data[i][offset] = *sendCmd;
            *sendCmd = 0;
            sendCmd++;
        }
    }
    else
    {
        gLink.queueFull = QUEUE_FULL_SEND;
    }

    if (sSendNonzeroCheck)
    {
        gLink.sendQueue.count++;
        sSendNonzeroCheck = 0;
    }

    REG_IME = gLinkSavedIme;
    gLastSendQueueCount = gLink.sendQueue.count;
}

void DequeueRecvCmds(u16 recvCmds[CMD_LENGTH][MAX_LINK_PLAYERS])
{
    u8 i;
    u8 j;

    gLinkSavedIme = REG_IME;
    REG_IME = 0;

    if (gLink.recvQueue.count == 0)
    {
        for (i = 0; i < CMD_LENGTH; i++)
            for (j = 0; j < gLink.playerCount; j++)
                recvCmds[i][j] = 0;

        gLink.receivedNothing = TRUE;
    }
    else
    {
        for (i = 0; i < CMD_LENGTH; i++)
            for (j = 0; j < gLink.playerCount; j++)
                recvCmds[i][j] = gLink.recvQueue.data[j][i][gLink.recvQueue.pos];

        gLink.recvQueue.count--;
        gLink.recvQueue.pos++;

        if (gLink.recvQueue.pos >= QUEUE_CAPACITY)
            gLink.recvQueue.pos = 0;

        gLink.receivedNothing = FALSE;
    }

    REG_IME = gLinkSavedIme;
}

void LinkVSync(void)
{
    if (gLink.isMaster)
    {
        switch (gLink.state)
        {
        case LINK_STATE_HANDSHAKE:
            StartTransfer();
            break;
        case LINK_STATE_CONN_ESTABLISHED:
            if (gLink.serialIntrCounter > 8)
            {
                if (gLink.lag == LAG_MASTER)
                    return;
                gLink.serialIntrCounter = 0;
            }
            else if (gLink.hardwareError != TRUE)
            {
                gLink.lag = LAG_MASTER;
                return;
            }
            StartTransfer();
            break;
        }
    }
    else if (gLink.state == LINK_STATE_CONN_ESTABLISHED
          || gLink.state == LINK_STATE_HANDSHAKE)
    {
        sNumVBlanksWithoutSerialIntr++;

        if (sNumVBlanksWithoutSerialIntr > 10)
        {
            if (gLink.state == LINK_STATE_CONN_ESTABLISHED)
                gLink.lag = LAG_SLAVE;

            if (gLink.state == LINK_STATE_HANDSHAKE)
            {
                gLink.playerCount = 0;
                gLink.link_field_F = 0;
            }
        }
    }
}

void Timer3Intr(void)
{
    StopTimer();
    StartTransfer();
}

void SerialCB(void)
{
    gLink.localId = SIO_MULTI_CNT->id;

    switch (gLink.state)
    {
    case LINK_STATE_CONN_ESTABLISHED:
        gLink.hardwareError = SIO_MULTI_CNT->error;
        DoRecv();
        DoSend();
        SendRecvDone();
        break;
    case LINK_STATE_HANDSHAKE:
        if (DoHandshake())
        {
            if (gLink.isMaster)
            {
                gLink.state = LINK_STATE_INIT_TIMER;
                gLink.serialIntrCounter = 8;
            }
            else
            {
                gLink.state = LINK_STATE_CONN_ESTABLISHED;
            }
        }
        break;
    }

    gLink.serialIntrCounter++;
    sNumVBlanksWithoutSerialIntr = 0;

    if (gLink.serialIntrCounter == 8)
        gLastRecvQueueCount = gLink.recvQueue.count;
}

static void StartTransfer(void)
{
    REG_SIOCNT |= SIO_START;
}

static bool8 DoHandshake(void)
{
    u8 i;
    u8 playerCount = 0;
    u16 minRecv = 0xFFFF;

    if (gLink.handshakeAsMaster == TRUE)
        REG_SIOMLT_SEND = MASTER_HANDSHAKE;
    else
        REG_SIOMLT_SEND = SLAVE_HANDSHAKE;

    *(u64 *)&gLink.tempRecvBuffer[0] = REG_SIOMLT_RECV;
    REG_SIOMLT_RECV = 0;

    gLink.handshakeAsMaster = FALSE;

    for (i = 0; i < 4; i++)
    {
        if ((gLink.tempRecvBuffer[i] & ~0x3) == SLAVE_HANDSHAKE
         || gLink.tempRecvBuffer[i] == MASTER_HANDSHAKE)
        {
            playerCount++;

            if (minRecv > gLink.tempRecvBuffer[i] && gLink.tempRecvBuffer[i] != 0)
                minRecv = gLink.tempRecvBuffer[i];
        }
        else
        {
            if (gLink.tempRecvBuffer[i] != 0xFFFF)
                playerCount = 0;
            break;
        }
    }

    gLink.playerCount = playerCount;

    // The handshake is successful when:
    // 1. There are multiple players.
    // 2. The number of players agrees with the last attempt.
    // 3. Player no. 0 is identifying as the master.
    if (gLink.playerCount > 1
     && gLink.playerCount == sHandshakePlayerCount
     && gLink.tempRecvBuffer[0] == MASTER_HANDSHAKE)
        return TRUE;

    if (gLink.playerCount > 1)
        gLink.link_field_F = (minRecv & 3) + 1;
    else
        gLink.link_field_F = 0;

    sHandshakePlayerCount = gLink.playerCount;

    return FALSE;
}

static void DoRecv(void)
{
    u16 recvBuffer[4];
    u8 i;

    *(u64 *)&recvBuffer[0] = REG_SIOMLT_RECV;

    if (gLink.sendCmdIndex == 0)
    {
        for (i = 0; i < gLink.playerCount; i++)
            if (gLink.checksum != recvBuffer[i] && sChecksumAvailable)
                    gLink.badChecksum = TRUE;

        gLink.checksum = 0;
        sChecksumAvailable = TRUE;
    }
    else
    {
        u8 index = gLink.recvQueue.pos + gLink.recvQueue.count;

        if (index >= QUEUE_CAPACITY)
            index -= QUEUE_CAPACITY;

        if (gLink.recvQueue.count < QUEUE_CAPACITY)
        {
            for (i = 0; i < gLink.playerCount; i++)
            {
                gLink.checksum += recvBuffer[i];
                sRecvNonzeroCheck |= recvBuffer[i];
                gLink.recvQueue.data[i][gLink.recvCmdIndex][index] = recvBuffer[i];
            }
        }
        else
        {
            gLink.queueFull = QUEUE_FULL_RECV;
        }

        gLink.recvCmdIndex++;

        if (gLink.recvCmdIndex == CMD_LENGTH && sRecvNonzeroCheck)
        {
            gLink.recvQueue.count++;
            sRecvNonzeroCheck = 0;
        }
    }
}

static void DoSend(void)
{
    if (gLink.sendCmdIndex == CMD_LENGTH)
    {
        REG_SIOMLT_SEND = gLink.checksum;

        if (!sSendBufferEmpty)
        {
            gLink.sendQueue.count--;
            gLink.sendQueue.pos++;

            if (gLink.sendQueue.pos >= QUEUE_CAPACITY)
                gLink.sendQueue.pos = 0;
        }
        else
        {
            sSendBufferEmpty = FALSE;
        }
    }
    else
    {
        if (!sSendBufferEmpty && gLink.sendQueue.count == 0)
            sSendBufferEmpty = TRUE;

        if (sSendBufferEmpty)
            REG_SIOMLT_SEND = 0;
        else
            REG_SIOMLT_SEND = gLink.sendQueue.data[gLink.sendCmdIndex][gLink.sendQueue.pos];

        gLink.sendCmdIndex++;
    }
}

static void StopTimer(void)
{
    if (gLink.isMaster)
    {
        REG_TM3CNT_H &= ~TIMER_ENABLE;
        REG_TM3CNT_L = 65339;
    }
}

static void SendRecvDone(void)
{
    if (gLink.recvCmdIndex == CMD_LENGTH)
    {
        gLink.sendCmdIndex = 0;
        gLink.recvCmdIndex = 0;
    }
    else if (gLink.isMaster)
    {
        REG_TM3CNT_H |= TIMER_ENABLE;
    }
}

void ResetSendBuffer(void)
{
    u8 i;
    u8 j;

    gLink.sendQueue.count = 0;
    gLink.sendQueue.pos = 0;

    for (i = 0; i < CMD_LENGTH; i++)
        for (j = 0; j < QUEUE_CAPACITY; j++)
            gLink.sendQueue.data[i][j] = 0xEFFF;
}

void ResetRecvBuffer(void)
{
    u8 i;
    u8 j;
    u8 k;

    gLink.recvQueue.count = 0;
    gLink.recvQueue.pos = 0;

    for (i = 0; i < 4; i++)
        for (j = 0; j < CMD_LENGTH; j++)
            for (k = 0; k < QUEUE_CAPACITY; k++)
                gLink.recvQueue.data[i][j][k] = 0xEFFF;
}
