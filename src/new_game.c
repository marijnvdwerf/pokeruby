#include "global.h"
#include "new_game.h"
#include "battle_records.h"
#include "berry.h"
#include "contest.h"
#include "decoration_inventory.h"
#include "dewford_trend.h"
#include "easy_chat.h"
#include "event_data.h"
#include "field_specials.h"
#include "item_menu.h"
#include "lottery_corner.h"
#include "mail_data.h"
#include "mauville_old_man.h"
#include "play_time.h"
#include "player_pc.h"
#include "pokeblock.h"
#include "pokedex.h"
#include "pokemon_size_record.h"
#include "pokemon_storage_system.h"
#include "rng.h"
#include "roamer.h"
#include "rom4.h"
#include "rtc.h"
#include "script.h"
#include "secret_base.h"
#include "tv.h"

extern u8 gDifferentSaveFile;

extern u8 gPlayerPartyCount;
extern u8 gUnknown_03005CE8;
extern u16 gSaveFileStatus;

extern u8 gUnknown_0819FA81[];

const struct SB1_2EFC_Struct gUnknown_08216604 =
{
    0x0000,
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    }
};

const u8 gUnknown_Debug_0823C788[] = {
        0x19, 0x28, 0x02, 0x03, 0x00, 0x09, 0x01, 0x01
};

const u8 gUnknown_Debug_0823C790[] = _("KRÖTE");

void write_word_to_mem(u32 var, u8 *dataPtr)
{
    dataPtr[0] = var;
    dataPtr[1] = var >> 8;
    dataPtr[2] = var >> 16;
    dataPtr[3] = var >> 24;
}

void copy_word_to_mem(u8 *copyTo, u8 *copyFrom)
{
    s32 i;
    for (i = 0; i < 4; i++)
        copyTo[i] = copyFrom[i];
}

void InitPlayerTrainerId(void)
{
    write_word_to_mem((Random() << 16) | Random(), gSaveBlock2.playerTrainerId);
}

// L=A isnt set here for some reason.
void SetDefaultOptions(void)
{
    gSaveBlock2.optionsTextSpeed = OPTIONS_TEXT_SPEED_MID;
    gSaveBlock2.optionsWindowFrameType = 0;
    gSaveBlock2.optionsSound = OPTIONS_SOUND_MONO;
    gSaveBlock2.optionsBattleStyle = OPTIONS_BATTLE_STYLE_SHIFT;
    gSaveBlock2.optionsBattleSceneOff = FALSE;
    gSaveBlock2.regionMapZoom = FALSE;
}

void ClearPokedexFlags(void)
{
    gUnknown_03005CE8 = 0;
    memset(&gSaveBlock2.pokedex.owned, 0, sizeof(gSaveBlock2.pokedex.owned));
    memset(&gSaveBlock2.pokedex.seen, 0, sizeof(gSaveBlock2.pokedex.seen));
}

void sub_8052DA8(void)
{
    s32 i;

    sub_80B2D1C();
    for (i = 0; i < 5; i++)
        gSaveBlock1.sbStruct.unkSB1.sb1_2EFC_struct[i] = gUnknown_08216604;
}

void sub_8052DE4(void)
{
    CpuFill32(0, &gSaveBlock2.filler_A8, sizeof(gSaveBlock2.filler_A8));
}

__attribute__((naked))
void debug_sub_8052E04()
{
    asm(
        "	push	{r4, r5, r6, r7, lr}\n"
        "	add	sp, sp, #0xfffffffc\n"
        "	mov	r3, #0x0\n"
        "	ldr	r4, ._17\n"
        "	ldr	r2, ._17 + 4\n"
        "	add	r7, r4, #0\n"
        "	mov	r5, #0x4\n"
        "	ldsb	r5, [r2, r5]\n"
        "	add	r6, r4, #1\n"
        "._15:\n"
        "	lsl	r1, r3, #0x1\n"
        "	add	r0, r1, r7\n"
        "	ldrb	r0, [r0]\n"
        "	lsl	r0, r0, #0x18\n"
        "	asr	r0, r0, #0x18\n"
        "	cmp	r0, r5\n"
        "	bne	._13	@cond_branch\n"
        "	add	r0, r1, r6\n"
        "	mov	r1, #0x0\n"
        "	ldsb	r1, [r0, r1]\n"
        "	mov	r0, #0x5\n"
        "	ldsb	r0, [r2, r0]\n"
        "	cmp	r1, r0\n"
        "	beq	._14	@cond_branch\n"
        "._13:\n"
        "	add	r0, r3, #1\n"
        "	lsl	r0, r0, #0x18\n"
        "	lsr	r3, r0, #0x18\n"
        "	cmp	r3, #0x3\n"
        "	bls	._15	@cond_branch\n"
        "._14:\n"
        "	add	r0, r3, #1\n"
        "	lsl	r0, r0, #0x18\n"
        "	lsr	r3, r0, #0x18\n"
        "	cmp	r3, #0x3\n"
        "	bls	._16	@cond_branch\n"
        "	mov	r3, #0x0\n"
        "._16:\n"
        "	lsl	r1, r3, #0x1\n"
        "	add	r0, r1, r4\n"
        "	ldrb	r0, [r0]\n"
        "	lsl	r0, r0, #0x18\n"
        "	asr	r0, r0, #0x18\n"
        "	add	r2, r4, #1\n"
        "	add	r1, r1, r2\n"
        "	ldrb	r1, [r1]\n"
        "	lsl	r1, r1, #0x18\n"
        "	asr	r1, r1, #0x18\n"
        "	mov	r3, #0x1\n"
        "	neg	r3, r3\n"
        "	str	r3, [sp]\n"
        "	add	r2, r3, #0\n"
        "	bl	warp1_set\n"
        "	add	sp, sp, #0x4\n"
        "	pop	{r4, r5, r6, r7}\n"
        "	pop	{r0}\n"
        "	bx	r0\n"
        "._18:\n"
        "	.align	2, 0\n"
        "._17:\n"
        "	.word	gUnknown_Debug_0823C788\n"
        "	.word	gSaveBlock1\n"
        "\n"
    );
}

void WarpToTruck(void)
{
    warp1_set(25, 40, -1, -1, -1); // inside of truck
    warp_in();
}

void ClearSav2(void)
{
    CpuFill16(0, &gSaveBlock2, sizeof(gSaveBlock2));
    SetDefaultOptions();
}

#ifdef DEBUG
__attribute__((naked))
void sub_8052E4C()
{
    asm(
        "	push	{lr}\n"
        "	ldr	r0, ._21\n"
        "	mov	r1, #0x0\n"
        "	strb	r1, [r0]\n"
        "	ldr	r0, ._21 + 4\n"
        "	strb	r1, [r0]\n"
        "	bl	sub_808C0A0\n"
        "	bl	ZeroPlayerPartyMons\n"
        "	bl	ZeroEnemyPartyMons\n"
        "	bl	sub_80A3684\n"
        "	pop	{r0}\n"
        "	bx	r0\n"
        "._22:\n"
        "	.align	2, 0\n"
        "._21:\n"
        "	.word	gDifferentSaveFile\n"
        "	.word	gUnknown_020297ED\n"
        "\n"
    );
}
#else
void sub_8052E4C(void)
{
    gDifferentSaveFile = 0;
    sub_808C0A0();
    ZeroPlayerPartyMons();
    ZeroEnemyPartyMons();
    sub_80A3684();
}
#endif

void NewGameInitData(void)
{
    if (gSaveFileStatus == 0 || gSaveFileStatus == 2)
        RtcReset();

    gDifferentSaveFile = 1;
    ZeroPlayerPartyMons();
    ZeroEnemyPartyMons();
    ResetPokedex();
    sub_8052DE4();
    memset(&gSaveBlock1, 0, sizeof(gSaveBlock1));
    ClearMailData();
    gSaveBlock2.specialSaveWarp = 0;
    InitPlayerTrainerId();
    PlayTimeCounter_Reset();
    ClearPokedexFlags();
    InitEventData();
    ClearTVShowData();
    ResetGabbyAndTy();
    ResetSecretBases();
    ClearBerryTrees();
    gSaveBlock1.money = 3000;
    ResetLinkContestBoolean();
    ResetGameStats();
    sub_8052DA8();
    InitLinkBattleRecords();
    InitShroomishSizeRecord();
    InitBarboachSizeRecord();
    gPlayerPartyCount = 0;
    ZeroPlayerPartyMons();
    ResetPokemonStorageSystem();
    ClearRoamerData();
    ClearRoamerLocationData();
    gSaveBlock1.registeredItem = 0;
    ClearBag();
    NewGameInitPCItems();
    ClearPokeblocks();
    ClearDecorationInventories();
    InitEasyChatPhrases();
    SetMauvilleOldMan();
    InitDewfordTrend();
    ResetFanClub();
    ResetLotteryCorner();
    WarpToTruck();
    ScriptContext2_RunNewScript(gUnknown_0819FA81);
}

__attribute__((naked))
void debug_sub_8057508()
{
    asm(
        "	push	{r4, lr}\n"
        "	add	sp, sp, #0xfffffff8\n"
        "	add	r4, r0, #0\n"
        "	ldr	r1, ._28\n"
        "	mov	r0, #0x1\n"
        "	strb	r0, [r1]\n"
        "	bl	NewGameInitData\n"
        "	ldr	r0, ._28 + 4\n"
        "	mov	r1, #0x92\n"
        "	lsl	r1, r1, #0x3\n"
        "	add	r0, r0, r1\n"
        "	ldr	r1, ._28 + 8\n"
        "	str	r1, [r0]\n"
        "	mov	r0, #0x80\n"
        "	lsl	r0, r0, #0x4\n"
        "	bl	FlagSet\n"
        "	ldr	r0, ._28 + 12\n"
        "	bl	FlagSet\n"
        "	ldr	r0, ._28 + 16\n"
        "	bl	FlagSet\n"
        "	mov	r0, #0x86\n"
        "	lsl	r0, r0, #0x4\n"
        "	bl	FlagSet\n"
        "	ldr	r0, ._28 + 20\n"
        "	mov	r1, #0x0\n"
        "	str	r1, [sp]\n"
        "	str	r1, [sp, #0x4]\n"
        "	mov	r1, #0x63\n"
        "	mov	r2, #0x0\n"
        "	mov	r3, #0x0\n"
        "	bl	ScriptGiveMon\n"
        "	cmp	r4, #0x1\n"
        "	bne	._27	@cond_branch\n"
        "	ldr	r0, ._28 + 24\n"
        "	ldr	r2, ._28 + 28\n"
        "	mov	r1, #0x2\n"
        "	bl	SetMonData\n"
        "._27:\n"
        "	bl	debug_sub_80A3904\n"
        "	bl	debug_sub_80A3714\n"
        "	bl	debug_sub_8120F98\n"
        "	ldr	r0, ._28 + 32\n"
        "	bl	FlagSet\n"
        "	bl	sub_80EB8EC\n"
        "	bl	unref_sub_8070F90\n"
        "	bl	InitTimeBasedEvents\n"
        "	add	sp, sp, #0x8\n"
        "	pop	{r4}\n"
        "	pop	{r0}\n"
        "	bx	r0\n"
        "._29:\n"
        "	.align	2, 0\n"
        "._28:\n"
        "	.word	gUnknown_020297ED\n"
        "	.word	gSaveBlock1\n"
        "	.word	0xf423f\n"
        "	.word	0x801\n"
        "	.word	0x802\n"
        "	.word	0x115\n"
        "	.word	gPlayerParty\n"
        "	.word	gUnknown_Debug_0823C790\n"
        "	.word	0x806\n"
        "\n"
    );
}