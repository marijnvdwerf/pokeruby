#include "global.h"
#include "battle_ai.h"
#include "abilities.h"
#include "battle.h"
#include "battle_move_effects.h"
#include "data2.h"
#include "item.h"
#include "moves.h"
#include "pokemon.h"
#include "rng.h"
#include "rom_8077ABC.h"
#include "species.h"
#include "util.h"

extern u16 gBattleTypeFlags;
extern u16 gBattleWeather;
extern u8 gActiveBank;
extern u8 gBattlePartyID[][2];
extern u16 gCurrentMove;
extern int gBattleMoveDamage;
extern u8 gBankAttacker;
extern u8 gBankTarget;
extern u8 gAbsentBankFlags;
extern u8 gBattleMoveFlags;
extern u16 gDynamicBasePower;
extern u16 gLastUsedMove[];
extern u32 gUnknown_02024ACC[];
extern u32 gStatuses3[];
extern u16 gSideAffecting[];
extern struct BattlePokemon gBattleMons[];
extern struct BattlePokemon gUnknown_02024A8C[];
extern u8 gBattleResults[];
extern u8 gCritMultiplier;
extern u16 gTrainerBattleOpponent;
extern u8 *BattleAIs[];

/*
gAIScriptPtr is a pointer to the next battle AI cmd command to read.
when a command finishes processing, gAIScriptPtr is incremented by
the number of bytes that the current command had reserved for arguments
in order to read the next command correctly. refer to battle_ai_scripts.s for the
AI scripts.
*/
extern u8 *gAIScriptPtr;

static void BattleAICmd_if_random_less_than(void);
static void BattleAICmd_if_random_greater_than(void);
static void BattleAICmd_if_random_equal(void);
static void BattleAICmd_if_random_not_equal(void);
static void BattleAICmd_score(void);
static void BattleAICmd_if_hp_less_than(void);
static void BattleAICmd_if_hp_more_than(void);
static void BattleAICmd_if_hp_equal(void);
static void BattleAICmd_if_hp_not_equal(void);
static void BattleAICmd_if_status(void);
static void BattleAICmd_if_not_status(void);
static void BattleAICmd_if_status2(void);
static void BattleAICmd_if_not_status2(void);
static void BattleAICmd_if_status3(void);
static void BattleAICmd_if_not_status3(void);
static void BattleAICmd_if_status4(void);
static void BattleAICmd_if_not_status4(void);
static void BattleAICmd_if_less_than(void);
static void BattleAICmd_if_more_than(void);
static void BattleAICmd_if_equal(void);
static void BattleAICmd_if_not_equal(void);
static void BattleAICmd_if_less_than_32(void);
static void BattleAICmd_if_more_than_32(void);
static void BattleAICmd_if_equal_32(void);
static void BattleAICmd_if_not_equal_32(void);
static void BattleAICmd_if_move(void);
static void BattleAICmd_if_not_move(void);
static void BattleAICmd_if_in_bytes(void);
static void BattleAICmd_if_not_in_bytes(void);
static void BattleAICmd_if_in_words(void);
static void BattleAICmd_if_not_in_words(void);
static void BattleAICmd_if_user_can_damage(void);
static void BattleAICmd_if_user_cant_damage(void);
static void BattleAICmd_get_turn_count(void);
static void BattleAICmd_get_type(void);
static void BattleAICmd_get_move_power(void);
static void BattleAICmd_is_most_powerful_move(void);
static void BattleAICmd_get_move(void);
static void BattleAICmd_if_arg_equal(void);
static void BattleAICmd_if_arg_not_equal(void);
static void BattleAICmd_if_would_go_first(void);
static void BattleAICmd_if_would_not_go_first(void);
static void BattleAICmd_nullsub_2A(void);
static void BattleAICmd_nullsub_2B(void);
static void BattleAICmd_count_alive_pokemon(void);
static void BattleAICmd_get_considered_move(void);
static void BattleAICmd_get_considered_move_effect(void);
static void BattleAICmd_get_ability(void);
static void BattleAICmd_get_highest_possible_damage(void);
static void BattleAICmd_if_damage_bonus(void);
static void BattleAICmd_nullsub_32(void);
static void BattleAICmd_nullsub_33(void);
static void BattleAICmd_if_status_in_party(void);
static void BattleAICmd_if_status_not_in_party(void);
static void BattleAICmd_get_weather(void);
static void BattleAICmd_if_effect(void);
static void BattleAICmd_if_not_effect(void);
static void BattleAICmd_if_stat_level_less_than(void);
static void BattleAICmd_if_stat_level_more_than(void);
static void BattleAICmd_if_stat_level_equal(void);
static void BattleAICmd_if_stat_level_not_equal(void);
static void BattleAICmd_if_can_faint(void);
static void BattleAICmd_if_cant_faint(void);
static void BattleAICmd_if_has_move(void);
static void BattleAICmd_if_dont_have_move(void);
static void BattleAICmd_if_move_effect(void);
static void BattleAICmd_if_not_move_effect(void);
static void BattleAICmd_if_last_move_did_damage(void);
static void BattleAICmd_if_encored(void);
static void BattleAICmd_flee(void);
static void BattleAICmd_if_random_100(void);
static void BattleAICmd_watch(void);
static void BattleAICmd_get_hold_effect(void);
static void BattleAICmd_get_gender(void);
static void BattleAICmd_is_first_turn(void);
static void BattleAICmd_get_stockpile_count(void);
static void BattleAICmd_is_double_battle(void);
static void BattleAICmd_get_item(void);
static void BattleAICmd_get_move_type_from_result(void);
static void BattleAICmd_get_move_power_from_result(void);
static void BattleAICmd_get_move_effect_from_result(void);
static void BattleAICmd_get_protect_count(void);
static void BattleAICmd_nullsub_52(void);
static void BattleAICmd_nullsub_53(void);
static void BattleAICmd_nullsub_54(void);
static void BattleAICmd_nullsub_55(void);
static void BattleAICmd_nullsub_56(void);
static void BattleAICmd_nullsub_57(void);
static void BattleAICmd_call(void);
static void BattleAICmd_jump(void);
static void BattleAICmd_end(void);
static void BattleAICmd_if_level_compare(void);
static void BattleAICmd_if_taunted(void);
static void BattleAICmd_if_not_taunted(void);

typedef void (*BattleAICmdFunc)(void);

static const BattleAICmdFunc sBattleAICmdTable[] =
{
    BattleAICmd_if_random_less_than,
    BattleAICmd_if_random_greater_than,
    BattleAICmd_if_random_equal,
    BattleAICmd_if_random_not_equal,
    BattleAICmd_score,
    BattleAICmd_if_hp_less_than,
    BattleAICmd_if_hp_more_than,
    BattleAICmd_if_hp_equal,
    BattleAICmd_if_hp_not_equal,
    BattleAICmd_if_status,
    BattleAICmd_if_not_status,
    BattleAICmd_if_status2,
    BattleAICmd_if_not_status2,
    BattleAICmd_if_status3,
    BattleAICmd_if_not_status3,
    BattleAICmd_if_status4,
    BattleAICmd_if_not_status4,
    BattleAICmd_if_less_than,
    BattleAICmd_if_more_than,
    BattleAICmd_if_equal,
    BattleAICmd_if_not_equal,
    BattleAICmd_if_less_than_32,
    BattleAICmd_if_more_than_32,
    BattleAICmd_if_equal_32,
    BattleAICmd_if_not_equal_32,
    BattleAICmd_if_move,
    BattleAICmd_if_not_move,
    BattleAICmd_if_in_bytes,
    BattleAICmd_if_not_in_bytes,
    BattleAICmd_if_in_words,
    BattleAICmd_if_not_in_words,
    BattleAICmd_if_user_can_damage,
    BattleAICmd_if_user_cant_damage,
    BattleAICmd_get_turn_count,
    BattleAICmd_get_type,
    BattleAICmd_get_move_power,
    BattleAICmd_is_most_powerful_move,
    BattleAICmd_get_move,
    BattleAICmd_if_arg_equal,
    BattleAICmd_if_arg_not_equal,
    BattleAICmd_if_would_go_first,
    BattleAICmd_if_would_not_go_first,
    BattleAICmd_nullsub_2A,
    BattleAICmd_nullsub_2B,
    BattleAICmd_count_alive_pokemon,
    BattleAICmd_get_considered_move,
    BattleAICmd_get_considered_move_effect,
    BattleAICmd_get_ability,
    BattleAICmd_get_highest_possible_damage,
    BattleAICmd_if_damage_bonus,
    BattleAICmd_nullsub_32,
    BattleAICmd_nullsub_33,
    BattleAICmd_if_status_in_party,
    BattleAICmd_if_status_not_in_party,
    BattleAICmd_get_weather,
    BattleAICmd_if_effect,
    BattleAICmd_if_not_effect,
    BattleAICmd_if_stat_level_less_than,
    BattleAICmd_if_stat_level_more_than,
    BattleAICmd_if_stat_level_equal,
    BattleAICmd_if_stat_level_not_equal,
    BattleAICmd_if_can_faint,
    BattleAICmd_if_cant_faint,
    BattleAICmd_if_has_move,
    BattleAICmd_if_dont_have_move,
    BattleAICmd_if_move_effect,
    BattleAICmd_if_not_move_effect,
    BattleAICmd_if_last_move_did_damage,
    BattleAICmd_if_encored,
    BattleAICmd_flee,
    BattleAICmd_if_random_100,
    BattleAICmd_watch,
    BattleAICmd_get_hold_effect,
    BattleAICmd_get_gender,
    BattleAICmd_is_first_turn,
    BattleAICmd_get_stockpile_count,
    BattleAICmd_is_double_battle,
    BattleAICmd_get_item,
    BattleAICmd_get_move_type_from_result,
    BattleAICmd_get_move_power_from_result,
    BattleAICmd_get_move_effect_from_result,
    BattleAICmd_get_protect_count,
    BattleAICmd_nullsub_52,
    BattleAICmd_nullsub_53,
    BattleAICmd_nullsub_54,
    BattleAICmd_nullsub_55,
    BattleAICmd_nullsub_56,
    BattleAICmd_nullsub_57,
    BattleAICmd_call,
    BattleAICmd_jump,
    BattleAICmd_end,
    BattleAICmd_if_level_compare,
    BattleAICmd_if_taunted,
    BattleAICmd_if_not_taunted,
};

#ifdef NONMATCHING
static
#endif
const u16 sDiscouragedPowerfulMoveEffects[] =
{
    EFFECT_EXPLOSION,
    EFFECT_DREAM_EATER,
    EFFECT_RAZOR_WIND,
    EFFECT_SKY_ATTACK,
    EFFECT_RECHARGE,
    EFFECT_SKULL_BASH,
    EFFECT_SOLARBEAM,
    EFFECT_SPIT_UP,
    EFFECT_FOCUS_PUNCH,
    EFFECT_SUPERPOWER,
    EFFECT_ERUPTION,
    EFFECT_OVERHEAT,
    0xFFFF
};

// if the AI is a Link battle, safari, battle tower, or ereader, it will ignore considering item uses.
void BattleAI_HandleItemUseBeforeAISetup(void)
{
    s32 i;
    u8 *data = (u8 *)UNK_2016A00_STRUCT;

    for (i = 0; (u32)i < sizeof(struct UnkBattleStruct1); i++)
        data[i] = 0;

    if ((gBattleTypeFlags & BATTLE_TYPE_TRAINER)
     && gTrainerBattleOpponent != 0x400
     && !(gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_SAFARI | BATTLE_TYPE_BATTLE_TOWER | BATTLE_TYPE_EREADER_TRAINER)))
    {
        for (i = 0; i < MAX_TRAINER_ITEMS; i++)
        {
            if (gTrainers[gTrainerBattleOpponent].items[i] != 0)
            {
                UNK_2016A00_STRUCT->items[UNK_2016A00_STRUCT->numOfItems] = gTrainers[gTrainerBattleOpponent].items[i];
                UNK_2016A00_STRUCT->numOfItems++;
            }
        }
    }

    BattleAI_SetupAIData();
}

#ifdef DEBUG
__attribute__((naked))
void BattleAI_SetupAIData()
{
    asm(
        "	push	{r4, r5, r6, r7, lr}\n"
        "	ldr	r2, ._16\n"
        "	mov	r4, #0x0\n"
        "	ldr	r3, ._16 + 4\n"
        "	mov	r1, #0x0\n"
        "._9:\n"
        "	add	r0, r2, r4\n"
        "	strb	r1, [r0]\n"
        "	add	r4, r4, #0x1\n"
        "	cmp	r4, #0x1b\n"
        "	bls	._9	@cond_branch\n"
        "	ldr	r0, ._16\n"
        "	mov	r1, #0x64\n"
        "	mov	r4, #0x3\n"
        "	add	r0, r0, #0x7\n"
        "._10:\n"
        "	strb	r1, [r0]\n"
        "	sub	r0, r0, #0x1\n"
        "	sub	r4, r4, #0x1\n"
        "	cmp	r4, #0\n"
        "	bge	._10	@cond_branch\n"
        "	ldrb	r0, [r3]\n"
        "	mov	r1, #0x0\n"
        "	mov	r2, #0xff\n"
        "	bl	sub_8015A98\n"
        "	lsl	r0, r0, #0x18\n"
        "	lsr	r7, r0, #0x18\n"
        "	mov	r4, #0x0\n"
        "	ldr	r0, ._16\n"
        "	add	r5, r0, #4\n"
        "	ldr	r6, ._16 + 8\n"
        "._12:\n"
        "	ldr	r0, [r6]\n"
        "	and	r0, r0, r7\n"
        "	cmp	r0, #0\n"
        "	beq	._11	@cond_branch\n"
        "	mov	r0, #0x0\n"
        "	strb	r0, [r5]\n"
        "._11:\n"
        "	bl	Random\n"
        "	lsl	r0, r0, #0x10\n"
        "	lsr	r0, r0, #0x10\n"
        "	mov	r1, #0xf\n"
        "	and	r0, r0, r1\n"
        "	mov	r1, #0x64\n"
        "	sub	r1, r1, r0\n"
        "	strb	r1, [r5, #0x14]\n"
        "	add	r5, r5, #0x1\n"
        "	add	r6, r6, #0x4\n"
        "	add	r4, r4, #0x1\n"
        "	cmp	r4, #0x3\n"
        "	ble	._12	@cond_branch\n"
        "	ldr	r0, ._16 + 12\n"
        "	add	r0, r0, #0x20\n"
        "	mov	r1, #0x0\n"
        "	strb	r1, [r0]\n"
        "	ldr	r1, ._16 + 16\n"
        "	ldr	r0, ._16 + 4\n"
        "	ldrb	r2, [r0]\n"
        "	strb	r2, [r1]\n"
        "	ldr	r0, ._16 + 20\n"
        "	ldrh	r1, [r0]\n"
        "	mov	r0, #0x1\n"
        "	and	r0, r0, r1\n"
        "	cmp	r0, #0\n"
        "	beq	._13	@cond_branch\n"
        "	ldr	r4, ._16 + 24\n"
        "	bl	Random\n"
        "	mov	r5, #0x2\n"
        "	and	r0, r0, r5\n"
        "	strb	r0, [r4]\n"
        "	ldr	r0, ._16 + 28\n"
        "	ldrb	r1, [r0]\n"
        "	ldr	r2, ._16 + 8\n"
        "	ldrb	r3, [r4]\n"
        "	lsl	r0, r3, #0x2\n"
        "	add	r0, r0, r2\n"
        "	ldr	r0, [r0]\n"
        "	and	r1, r1, r0\n"
        "	cmp	r1, #0\n"
        "	beq	._15	@cond_branch\n"
        "	eor	r3, r3, r5\n"
        "	strb	r3, [r4]\n"
        "	b	._15\n"
        "._17:\n"
        "	.align	2, 0\n"
        "._16:\n"
        "	.word	+0x2016800\n"
        "	.word	gActiveBank\n"
        "	.word	gBitTable\n"
        "	.word	+0x2016c00\n"
        "	.word	gBankAttacker\n"
        "	.word	gBattleTypeFlags\n"
        "	.word	gBankTarget\n"
        "	.word	gAbsentBankFlags\n"
        "._13:\n"
        "	ldr	r0, ._20\n"
        "	mov	r1, #0x1\n"
        "	eor	r1, r1, r2\n"
        "	strb	r1, [r0]\n"
        "._15:\n"
        "	ldr	r0, ._20 + 4\n"
        "	ldrh	r1, [r0]\n"
        "	mov	r0, #0x80\n"
        "	and	r0, r0, r1\n"
        "	cmp	r0, #0\n"
        "	beq	._18	@cond_branch\n"
        "	ldr	r1, ._20 + 8\n"
        "	mov	r0, #0x80\n"
        "	lsl	r0, r0, #0x17\n"
        "	b	._27\n"
        "._21:\n"
        "	.align	2, 0\n"
        "._20:\n"
        "	.word	gBankTarget\n"
        "	.word	gBattleTypeFlags\n"
        "	.word	+0x2016800\n"
        "._18:\n"
        "	mov	r2, #0x80\n"
        "	lsl	r2, r2, #0x3\n"
        "	add	r0, r2, #0\n"
        "	and	r0, r0, r1\n"
        "	cmp	r0, #0\n"
        "	beq	._22	@cond_branch\n"
        "	ldr	r1, ._24\n"
        "	mov	r0, #0x80\n"
        "	lsl	r0, r0, #0x16\n"
        "	b	._27\n"
        "._25:\n"
        "	.align	2, 0\n"
        "._24:\n"
        "	.word	+0x2016800\n"
        "._22:\n"
        "	mov	r0, #0x10\n"
        "	and	r0, r0, r1\n"
        "	cmp	r0, #0\n"
        "	beq	._26	@cond_branch\n"
        "	ldr	r1, ._28\n"
        "	mov	r0, #0x80\n"
        "	lsl	r0, r0, #0x18\n"
        "	b	._27\n"
        "._29:\n"
        "	.align	2, 0\n"
        "._28:\n"
        "	.word	+0x2016800\n"
        "._26:\n"
        "	mov	r0, #0x90\n"
        "	lsl	r0, r0, #0x4\n"
        "	and	r0, r0, r1\n"
        "	cmp	r0, #0\n"
        "	bne	._30	@cond_branch\n"
        "	ldr	r1, ._33\n"
        "	ldrh	r0, [r1]\n"
        "	cmp	r0, r2\n"
        "	bne	._31	@cond_branch\n"
        "._30:\n"
        "	ldr	r1, ._33 + 4\n"
        "	mov	r0, #0x7\n"
        "._27:\n"
        "	str	r0, [r1, #0xc]\n"
        "	add	r3, r1, #0\n"
        "	b	._32\n"
        "._34:\n"
        "	.align	2, 0\n"
        "._33:\n"
        "	.word	gTrainerBattleOpponent\n"
        "	.word	+0x2016800\n"
        "._31:\n"
        "	ldr	r3, ._36\n"
        "	ldr	r2, ._36 + 4\n"
        "	ldrh	r1, [r1]\n"
        "	lsl	r0, r1, #0x2\n"
        "	add	r0, r0, r1\n"
        "	lsl	r0, r0, #0x3\n"
        "	add	r2, r2, #0x1c\n"
        "	add	r0, r0, r2\n"
        "	ldr	r0, [r0]\n"
        "	str	r0, [r3, #0xc]\n"
        "._32:\n"
        "	ldr	r0, ._36 + 8\n"
        "	ldrb	r1, [r0]\n"
        "	mov	r0, #0x1\n"
        "	and	r0, r0, r1\n"
        "	cmp	r0, #0\n"
        "	beq	._35	@cond_branch\n"
        "	ldr	r0, ._36 + 12\n"
        "	ldr	r0, [r0]\n"
        "	str	r0, [r3, #0xc]\n"
        "._35:\n"
        "	pop	{r4, r5, r6, r7}\n"
        "	pop	{r0}\n"
        "	bx	r0\n"
        "._37:\n"
        "	.align	2, 0\n"
        "._36:\n"
        "	.word	+0x2016800\n"
        "	.word	gTrainers\n"
        "	.word	gUnknown_02023A14+0x50\n"
        "	.word	gUnknown_02023A14+0x4c\n"
        "\n"
    );
}
#else
void BattleAI_SetupAIData(void)
{
    s32 i;
    u8 *data = (u8 *)AI_THINKING_STRUCT;
    u8 r7;

    // clear AI data and set default move score to 100. strange that they didn't use memset here.
    for (i = 0; (u32)i < sizeof(struct AI_ThinkingStruct); i++)
        data[i] = 0;
    for (i = 0; i < MAX_MON_MOVES; i++)
        AI_THINKING_STRUCT->score[i] = 100;

    r7 = sub_8015A98(gActiveBank, 0, 0xFF);

    // probably sets up the moves to consider and ignores non-valid moves such as NO_MOVE or glitch moves.
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (gBitTable[i] & r7)
            AI_THINKING_STRUCT->score[i] = 0;

        AI_THINKING_STRUCT->simulatedRNG[i] = 100 - (Random() % 16);
    }

    // clear AI stack.
    AI_STACK->size = 0;
    gBankAttacker = gActiveBank;

    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
    {
        gBankTarget = Random() & 2; // just pick somebody to target.

        if (gAbsentBankFlags & gBitTable[gBankTarget])
            gBankTarget ^= 2;
    }
    else
        gBankTarget = gActiveBank ^ 1;

    // special AI flag cases.
    if (gBattleTypeFlags & BATTLE_TYPE_SAFARI)
        AI_THINKING_STRUCT->aiFlags = 0x40000000;
    else if (gBattleTypeFlags & BATTLE_TYPE_ROAMER)
        AI_THINKING_STRUCT->aiFlags = 0x20000000;
    else if (gBattleTypeFlags & BATTLE_TYPE_FIRST_BATTLE)
        AI_THINKING_STRUCT->aiFlags = 0x80000000;
#ifdef GERMAN
    else if (gBattleTypeFlags & 0x900 || gTrainerBattleOpponent == 0x400)
        AI_THINKING_STRUCT->aiFlags = 7;
#endif
    else // otherwise, just set aiFlags to whatever flags the trainer has set in their data.
        AI_THINKING_STRUCT->aiFlags = gTrainers[gTrainerBattleOpponent].aiFlags;
}
#endif

u8 BattleAI_GetAIActionToUse(void)
{
    u8 currentMoveArray[MAX_MON_MOVES];
    u8 consideredMoveArray[MAX_MON_MOVES];
    u8 numOfBestMoves;
    s32 i;

    sub_810745C();
    while (AI_THINKING_STRUCT->aiFlags != 0)
    {
        if (AI_THINKING_STRUCT->aiFlags & 1)
        {
            AI_THINKING_STRUCT->aiState = AIState_SettingUp;
            BattleAI_DoAIProcessing();
        }
        AI_THINKING_STRUCT->aiFlags >>= 1;
        AI_THINKING_STRUCT->aiLogicId++;
        AI_THINKING_STRUCT->movesetIndex = 0;
    }

    // special flee or watch cases for safari.
    if (AI_THINKING_STRUCT->aiAction & (AI_ACTION_FLEE)) // flee
        return 4;
    if (AI_THINKING_STRUCT->aiAction & (AI_ACTION_WATCH)) // watch
        return 5;

    numOfBestMoves = 1;
    currentMoveArray[0] = AI_THINKING_STRUCT->score[0];
    consideredMoveArray[0] = 0;

    for (i = 1; i < MAX_MON_MOVES; i++)
    {
        if (currentMoveArray[0] < AI_THINKING_STRUCT->score[i])
        {
            numOfBestMoves = 1;
            currentMoveArray[0] = AI_THINKING_STRUCT->score[i];
            consideredMoveArray[0] = i;
        }
        if (currentMoveArray[0] == AI_THINKING_STRUCT->score[i])
        {
            currentMoveArray[numOfBestMoves] = AI_THINKING_STRUCT->score[i];
            consideredMoveArray[numOfBestMoves++] = i;
        }
    }

    return consideredMoveArray[Random() % numOfBestMoves]; // break any ties that exist.
}

void BattleAI_DoAIProcessing(void)
{
    while (AI_THINKING_STRUCT->aiState != AIState_FinishedProcessing)
    {
        switch (AI_THINKING_STRUCT->aiState)
        {
        case AIState_DoNotProcess: //Needed to match.
            break;
        case AIState_SettingUp:
            gAIScriptPtr = BattleAIs[AI_THINKING_STRUCT->aiLogicId]; // set the AI ptr.
            if (gBattleMons[gBankAttacker].pp[AI_THINKING_STRUCT->movesetIndex] == 0)
            {
                AI_THINKING_STRUCT->moveConsidered = MOVE_NONE; // don't consider a move you have 0 PP for, idiot.
            }
            else
            {
                AI_THINKING_STRUCT->moveConsidered = gBattleMons[gBankAttacker].moves[AI_THINKING_STRUCT->movesetIndex];
            }
            AI_THINKING_STRUCT->aiState++;
            break;
        case AIState_Processing:
            if (AI_THINKING_STRUCT->moveConsidered != MOVE_NONE)
                sBattleAICmdTable[*(u8 *)gAIScriptPtr](); // run AI command.
            else
            {
                AI_THINKING_STRUCT->score[AI_THINKING_STRUCT->movesetIndex] = 0; // definitely do not consider any move that has 0 PP.
                AI_THINKING_STRUCT->aiAction |= AI_ACTION_DONE;
            }
            if (AI_THINKING_STRUCT->aiAction & AI_ACTION_DONE)
            {
                AI_THINKING_STRUCT->movesetIndex++;
                if (AI_THINKING_STRUCT->movesetIndex < MAX_MON_MOVES && (AI_THINKING_STRUCT->aiAction & AI_ACTION_DO_NOT_ATTACK) == 0)
                    AI_THINKING_STRUCT->aiState = AIState_SettingUp; // as long as their are more moves to process, keep setting this to setup state.
                else
                    AI_THINKING_STRUCT->aiState++; // done processing.
                AI_THINKING_STRUCT->aiAction &= (AI_ACTION_FLEE | AI_ACTION_WATCH | AI_ACTION_DO_NOT_ATTACK |
                AI_ACTION_UNK5 | AI_ACTION_UNK6 | AI_ACTION_UNK7 | AI_ACTION_UNK8); // disable AI_ACTION_DONE.
            }
            break;
        }
    }
}

void sub_810745C(void)
{
    s32 i;

    for (i = 0; i < 8; i++)
    {
        if (UNK_2016A00_STRUCT->movesUsed[gBankTarget >> 1][i] == 0)
        {
            UNK_2016A00_STRUCT->movesUsed[gBankTarget >> 1][i] = gLastUsedMove[gBankTarget];
            return;
        }
    }
}

void unref_sub_81074A0(u8 a)
{
    s32 i;

    for (i = 0; i < 8; i++)
        UNK_2016A00_STRUCT->movesUsed[a / 2][i] = 0;
}

void sub_81074C4(u8 a, u8 b)
{
    if (GetBankSide(a) == 0)
        UNK_2016A00_STRUCT->unk20[GetBankIdentity(a) & 1] = b;
}

void sub_81074F8(u8 a, u8 b)
{
    if (GetBankSide(a) == 0)
        UNK_2016A00_STRUCT->unk22[GetBankIdentity(a) & 1] = b;
}

static void BattleAICmd_if_random_less_than(void)
{
    if (Random() % 256 < gAIScriptPtr[1])
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

static void BattleAICmd_if_random_greater_than(void)
{
    if (Random() % 256 > gAIScriptPtr[1])
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

static void BattleAICmd_if_random_equal(void)
{
    if (Random() % 256 == gAIScriptPtr[1])
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

static void BattleAICmd_if_random_not_equal(void)
{
    if (Random() % 256 != gAIScriptPtr[1])
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

static void BattleAICmd_score(void)
{
    AI_THINKING_STRUCT->score[AI_THINKING_STRUCT->movesetIndex] += gAIScriptPtr[1]; // add the result to the array of the move consider's score.

    if (AI_THINKING_STRUCT->score[AI_THINKING_STRUCT->movesetIndex] < 0) // if the score is negative, flatten it to 0.
        AI_THINKING_STRUCT->score[AI_THINKING_STRUCT->movesetIndex] = 0;

    gAIScriptPtr += 2; // AI return.
}

static void BattleAICmd_if_hp_less_than(void)
{
    u16 index;

    if (gAIScriptPtr[1] == USER)
        index = gBankAttacker;
    else
        index = gBankTarget;

    if ((u32)(100 * gBattleMons[index].hp / gBattleMons[index].maxHP) < gAIScriptPtr[2])
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 3);
    else
        gAIScriptPtr += 7;
}

static void BattleAICmd_if_hp_more_than(void)
{
    u16 index;

    if (gAIScriptPtr[1] == USER)
        index = gBankAttacker;
    else
        index = gBankTarget;

    if ((u32)(100 * gBattleMons[index].hp / gBattleMons[index].maxHP) > gAIScriptPtr[2])
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 3);
    else
        gAIScriptPtr += 7;
}

static void BattleAICmd_if_hp_equal(void)
{
    u16 index;

    if (gAIScriptPtr[1] == USER)
        index = gBankAttacker;
    else
        index = gBankTarget;

    if ((u32)(100 * gBattleMons[index].hp / gBattleMons[index].maxHP) == gAIScriptPtr[2])
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 3);
    else
        gAIScriptPtr += 7;
}

static void BattleAICmd_if_hp_not_equal(void)
{
    u16 index;

    if (gAIScriptPtr[1] == USER)
        index = gBankAttacker;
    else
        index = gBankTarget;

    if ((u32)(100 * gBattleMons[index].hp / gBattleMons[index].maxHP) != gAIScriptPtr[2])
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 3);
    else
        gAIScriptPtr += 7;
}

static void BattleAICmd_if_status(void)
{
    u16 index;
    u32 arg;

    if (gAIScriptPtr[1] == USER)
        index = gBankAttacker;
    else
        index = gBankTarget;

    arg = AIScriptRead32(gAIScriptPtr + 2);

    if ((gBattleMons[index].status1 & arg) != 0)
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 6);
    else
        gAIScriptPtr += 10;
}

static void BattleAICmd_if_not_status(void)
{
    u16 index;
    u32 arg;

    if (gAIScriptPtr[1] == USER)
        index = gBankAttacker;
    else
        index = gBankTarget;

    arg = AIScriptRead32(gAIScriptPtr + 2);

    if ((gBattleMons[index].status1 & arg) == 0)
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 6);
    else
        gAIScriptPtr += 10;
}

static void BattleAICmd_if_status2(void)
{
    u16 index;
    u32 arg;

    if (gAIScriptPtr[1] == USER)
        index = gBankAttacker;
    else
        index = gBankTarget;

    arg = AIScriptRead32(gAIScriptPtr + 2);

    if ((gBattleMons[index].status2 & arg) != 0)
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 6);
    else
        gAIScriptPtr += 10;
}

static void BattleAICmd_if_not_status2(void)
{
    u16 index;
    u32 arg;

    if (gAIScriptPtr[1] == USER)
        index = gBankAttacker;
    else
        index = gBankTarget;

    arg = AIScriptRead32(gAIScriptPtr + 2);

    if ((gBattleMons[index].status2 & arg) == 0)
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 6);
    else
        gAIScriptPtr += 10;
}

static void BattleAICmd_if_status3(void)
{
    u16 index;
    u32 arg;

    if (gAIScriptPtr[1] == USER)
        index = gBankAttacker;
    else
        index = gBankTarget;

    arg = AIScriptRead32(gAIScriptPtr + 2);

    if ((gStatuses3[index] & arg) != 0)
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 6);
    else
        gAIScriptPtr += 10;
}

static void BattleAICmd_if_not_status3(void)
{
    u16 index;
    u32 arg;

    if (gAIScriptPtr[1] == USER)
        index = gBankAttacker;
    else
        index = gBankTarget;

    arg = AIScriptRead32(gAIScriptPtr + 2);

    if ((gStatuses3[index] & arg) == 0)
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 6);
    else
        gAIScriptPtr += 10;
}

static void BattleAICmd_if_status4(void)
{
    u16 index;
    u32 arg1, arg2;

    if (gAIScriptPtr[1] == USER)
        index = gBankAttacker;
    else
        index = gBankTarget;

    arg1 = GetBankIdentity(index) & 1;
    arg2 = AIScriptRead32(gAIScriptPtr + 2);

    if ((gSideAffecting[arg1] & arg2) != 0)
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 6);
    else
        gAIScriptPtr += 10;
}

static void BattleAICmd_if_not_status4(void)
{
    u16 index;
    u32 arg1, arg2;

    if (gAIScriptPtr[1] == USER)
        index = gBankAttacker;
    else
        index = gBankTarget;

    arg1 = GetBankIdentity(index) & 1;
    arg2 = AIScriptRead32(gAIScriptPtr + 2);

    if ((gSideAffecting[arg1] & arg2) == 0)
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 6);
    else
        gAIScriptPtr += 10;
}

static void BattleAICmd_if_less_than(void)
{
    if (AI_THINKING_STRUCT->funcResult < gAIScriptPtr[1])
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

static void BattleAICmd_if_more_than(void)
{
    if (AI_THINKING_STRUCT->funcResult > gAIScriptPtr[1])
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

static void BattleAICmd_if_equal(void)
{
    if (AI_THINKING_STRUCT->funcResult == gAIScriptPtr[1])
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

static void BattleAICmd_if_not_equal(void)
{
    if (AI_THINKING_STRUCT->funcResult != gAIScriptPtr[1])
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

static void BattleAICmd_if_less_than_32(void)
{
    u8 *temp = AIScriptReadPtr(gAIScriptPtr + 1);

    if (AI_THINKING_STRUCT->funcResult < *temp)
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 5);
    else
        gAIScriptPtr += 9;
}

static void BattleAICmd_if_more_than_32(void)
{
    u8 *temp = AIScriptReadPtr(gAIScriptPtr + 1);

    if (AI_THINKING_STRUCT->funcResult > *temp)
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 5);
    else
        gAIScriptPtr += 9;
}

static void BattleAICmd_if_equal_32(void)
{
    u8 *temp = AIScriptReadPtr(gAIScriptPtr + 1);

    if (AI_THINKING_STRUCT->funcResult == *temp)
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 5);
    else
        gAIScriptPtr += 9;
}

static void BattleAICmd_if_not_equal_32(void)
{
    u8 *temp = AIScriptReadPtr(gAIScriptPtr + 1);

    if (AI_THINKING_STRUCT->funcResult != *temp)
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 5);
    else
        gAIScriptPtr += 9;
}

static void BattleAICmd_if_move(void)
{
    u16 move = AIScriptRead16(gAIScriptPtr + 1);

    if (AI_THINKING_STRUCT->moveConsidered == move)
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 3);
    else
        gAIScriptPtr += 7;
}

static void BattleAICmd_if_not_move(void)
{
    u16 move = AIScriptRead16(gAIScriptPtr + 1);

    if (AI_THINKING_STRUCT->moveConsidered != move)
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 3);
    else
        gAIScriptPtr += 7;
}

static void BattleAICmd_if_in_bytes(void)
{
    u8 *ptr = AIScriptReadPtr(gAIScriptPtr + 1);

    while (*ptr != 0xFF)
    {
        if (AI_THINKING_STRUCT->funcResult == *ptr)
        {
            gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 5);
            return;
        }
        ptr++;
    }
    gAIScriptPtr += 9;
}

static void BattleAICmd_if_not_in_bytes(void)
{
    u8 *ptr = AIScriptReadPtr(gAIScriptPtr + 1);

    while (*ptr != 0xFF)
    {
        if (AI_THINKING_STRUCT->funcResult == *ptr)
        {
            gAIScriptPtr += 9;
            return;
        }
        ptr++;
    }
    gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 5);
}

static void BattleAICmd_if_in_words(void)
{
    u16 *ptr = (u16 *)AIScriptReadPtr(gAIScriptPtr + 1);

    while (*ptr != 0xFFFF)
    {
        if (AI_THINKING_STRUCT->funcResult == *ptr)
        {
            gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 5);
            return;
        }
        ptr++;
    }
    gAIScriptPtr += 9;
}

static void BattleAICmd_if_not_in_words(void)
{
    u16 *ptr = (u16 *)AIScriptReadPtr(gAIScriptPtr + 1);

    while (*ptr != 0xFFFF)
    {
        if (AI_THINKING_STRUCT->funcResult == *ptr)
        {
            gAIScriptPtr += 9;
            return;
        }
        ptr++;
    }
    gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 5);
}

static void BattleAICmd_if_user_can_damage(void)
{
    s32 i;

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (gBattleMons[gBankAttacker].moves[i] != 0
            && gBattleMoves[gBattleMons[gBankAttacker].moves[i]].power != 0)
            break;
    }
    if (i == MAX_MON_MOVES)
        gAIScriptPtr += 5;
    else
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 1);
}

static void BattleAICmd_if_user_cant_damage(void)
{
    s32 i;

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (gBattleMons[gBankAttacker].moves[i] != 0
         && gBattleMoves[gBattleMons[gBankAttacker].moves[i]].power != 0)
            break;
    }
    if (i != MAX_MON_MOVES)
        gAIScriptPtr += 5;
    else
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 1);
}

static void BattleAICmd_get_turn_count(void)
{
    AI_THINKING_STRUCT->funcResult = gBattleResults[19];
    gAIScriptPtr += 1;
}

static void BattleAICmd_get_type(void)
{
    switch (gAIScriptPtr[1])
    {
    case 1: // player primary type
        AI_THINKING_STRUCT->funcResult = gBattleMons[gBankAttacker].type1;
        break;
    case 0: // enemy primary type
        AI_THINKING_STRUCT->funcResult = gBattleMons[gBankTarget].type1;
        break;
    case 3: // player secondary type
        AI_THINKING_STRUCT->funcResult = gBattleMons[gBankAttacker].type2;
        break;
    case 2: // enemy secondary type
        AI_THINKING_STRUCT->funcResult = gBattleMons[gBankTarget].type2;
        break;
    case 4: // type of move being pointed to
        AI_THINKING_STRUCT->funcResult = gBattleMoves[AI_THINKING_STRUCT->moveConsidered].type;
        break;
    }
    gAIScriptPtr += 2;
}

static void BattleAICmd_get_move_power(void)
{
    AI_THINKING_STRUCT->funcResult = gBattleMoves[AI_THINKING_STRUCT->moveConsidered].power;
    gAIScriptPtr += 1;
}

#ifdef NONMATCHING
static void BattleAICmd_is_most_powerful_move(void)
{
    int i, j;
    s32 damages[MAX_MON_MOVES];

    for (i = 0; sDiscouragedPowerfulMoveEffects[i] != 0xFFFF; i++)
        if (gBattleMoves[AI_THINKING_STRUCT->moveConsidered].effect == sDiscouragedPowerfulMoveEffects[i])
            break;

    if (gBattleMoves[AI_THINKING_STRUCT->moveConsidered].power > 1
     && sDiscouragedPowerfulMoveEffects[i] == 0xFFFF)
    {
        gDynamicBasePower = 0;
        unk_2000000[0x1601C] = 0; // why is this a manual array?
        unk_2000000[0x1601F] = 1;
        gBattleMoveFlags = 0;
        gCritMultiplier = 1;

        for (i = 0; i < MAX_MON_MOVES; i++)
        {
            for (j = 0; sDiscouragedPowerfulMoveEffects[j] != 0xFFFF; j++)
            { // _08108276
                if (gBattleMoves[gBattleMons[gBankAttacker].moves[i]].effect == sDiscouragedPowerfulMoveEffects[j])
                    break;
            }

            // _081082BA
            if (gBattleMons[gBankAttacker].moves[i]
             && sDiscouragedPowerfulMoveEffects[j] == 0xFFFF
             && gBattleMoves[gBattleMons[gBankAttacker].moves[i]].power > 1)
            {
                gCurrentMove = gBattleMons[gBankAttacker].moves[i];
                sub_801CAF8(gBankAttacker, gBankTarget);
                move_effectiveness_something(gCurrentMove, gBankAttacker, gBankTarget);
                damages[i] = (gBattleMoveDamage * AI_THINKING_STRUCT->simulatedRNG[i]) / 100;

                if (damages[i] == 0) // moves always do at least 1 damage.
                    damages[i] = 1;
            }
            else
            {
                damages[i] = 0;
            }
        }

        for (i = 0; i < MAX_MON_MOVES; i++)
            if (damages[i] > damages[AI_THINKING_STRUCT->movesetIndex])
                break;

        if (i == MAX_MON_MOVES)
            AI_THINKING_STRUCT->funcResult = 2;
        else
            AI_THINKING_STRUCT->funcResult = 1;
    }
    else
    {
        AI_THINKING_STRUCT->funcResult = 0;
    }

    gAIScriptPtr += 1;
}
#else
__attribute__((naked))
static void BattleAICmd_is_most_powerful_move(void)
{
    asm(".syntax unified\n\
    push {r4-r7,lr}\n\
    mov r7, r10\n\
    mov r6, r9\n\
    mov r5, r8\n\
    push {r5-r7}\n\
    sub sp, 0x14\n\
    movs r3, 0\n\
    ldr r0, _08108328 @ =sDiscouragedPowerfulMoveEffects\n\
    ldrh r1, [r0]\n\
    ldr r4, _0810832C @ =0x0000ffff\n\
    ldr r6, _08108330 @ =gBattleMoves\n\
    ldr r5, _08108334 @ =0x02016800\n\
    cmp r1, r4\n\
    beq _0810822E\n\
    ldrh r1, [r5, 0x2]\n\
    lsls r0, r1, 1\n\
    adds r0, r1\n\
    lsls r0, 2\n\
    adds r0, r6\n\
    ldrb r2, [r0]\n\
    ldr r1, _08108328 @ =sDiscouragedPowerfulMoveEffects\n\
_0810821E:\n\
    ldrh r0, [r1]\n\
    cmp r2, r0\n\
    beq _0810822E\n\
    adds r1, 0x2\n\
    adds r3, 0x1\n\
    ldrh r0, [r1]\n\
    cmp r0, r4\n\
    bne _0810821E\n\
_0810822E:\n\
    ldrh r0, [r5, 0x2]\n\
    lsls r1, r0, 1\n\
    adds r1, r0\n\
    lsls r1, 2\n\
    adds r1, r6\n\
    ldrb r0, [r1, 0x1]\n\
    cmp r0, 0x1\n\
    bhi _08108240\n\
    b _081083B2\n\
_08108240:\n\
    lsls r0, r3, 1\n\
    ldr r1, _08108328 @ =sDiscouragedPowerfulMoveEffects\n\
    adds r0, r1\n\
    ldrh r3, [r0]\n\
    ldr r0, _0810832C @ =0x0000ffff\n\
    cmp r3, r0\n\
    beq _08108250\n\
    b _081083B2\n\
_08108250:\n\
    ldr r0, _08108338 @ =gDynamicBasePower\n\
    movs r1, 0\n\
    strh r1, [r0]\n\
    ldr r2, _0810833C @ =0xfffff81c\n\
    adds r0, r5, r2\n\
    strb r1, [r0]\n\
    adds r2, 0x3\n\
    adds r0, r5, r2\n\
    movs r2, 0x1\n\
    strb r2, [r0]\n\
    ldr r0, _08108340 @ =gBattleMoveFlags\n\
    strb r1, [r0]\n\
    ldr r0, _08108344 @ =gCritMultiplier\n\
    strb r2, [r0]\n\
    movs r6, 0\n\
    mov r9, r3\n\
    ldr r0, _08108328 @ =sDiscouragedPowerfulMoveEffects\n\
    ldrh r0, [r0]\n\
    str r0, [sp, 0x10]\n\
_08108276:\n\
    movs r3, 0\n\
    ldr r5, _08108348 @ =gBattleMons\n\
    lsls r4, r6, 1\n\
    ldr r7, _0810834C @ =gBankAttacker\n\
    lsls r1, r6, 2\n\
    mov r8, r1\n\
    adds r2, r6, 0x1\n\
    mov r10, r2\n\
    ldr r0, [sp, 0x10]\n\
    cmp r0, r9\n\
    beq _081082BA\n\
    ldr r2, _08108330 @ =gBattleMoves\n\
    ldrb r1, [r7]\n\
    movs r0, 0x58\n\
    muls r0, r1\n\
    adds r0, r4, r0\n\
    adds r1, r5, 0\n\
    adds r1, 0xC\n\
    adds r0, r1\n\
    ldrh r1, [r0]\n\
    lsls r0, r1, 1\n\
    adds r0, r1\n\
    lsls r0, 2\n\
    adds r0, r2\n\
    ldrb r2, [r0]\n\
    ldr r1, _08108328 @ =sDiscouragedPowerfulMoveEffects\n\
_081082AA:\n\
    ldrh r0, [r1]\n\
    cmp r2, r0\n\
    beq _081082BA\n\
    adds r1, 0x2\n\
    adds r3, 0x1\n\
    ldrh r0, [r1]\n\
    cmp r0, r9\n\
    bne _081082AA\n\
_081082BA:\n\
    ldrb r1, [r7]\n\
    movs r0, 0x58\n\
    muls r0, r1\n\
    adds r0, r4, r0\n\
    adds r1, r5, 0\n\
    adds r1, 0xC\n\
    adds r1, r0, r1\n\
    ldrh r0, [r1]\n\
    cmp r0, 0\n\
    beq _0810835C\n\
    lsls r0, r3, 1\n\
    ldr r2, _08108328 @ =sDiscouragedPowerfulMoveEffects\n\
    adds r0, r2\n\
    ldrh r0, [r0]\n\
    cmp r0, r9\n\
    bne _0810835C\n\
    ldr r0, _08108330 @ =gBattleMoves\n\
    ldrh r2, [r1]\n\
    lsls r1, r2, 1\n\
    adds r1, r2\n\
    lsls r1, 2\n\
    adds r1, r0\n\
    ldrb r0, [r1, 0x1]\n\
    cmp r0, 0x1\n\
    bls _0810835C\n\
    ldr r5, _08108350 @ =gCurrentMove\n\
    strh r2, [r5]\n\
    ldrb r0, [r7]\n\
    ldr r4, _08108354 @ =gBankTarget\n\
    ldrb r1, [r4]\n\
    bl sub_801CAF8\n\
    ldrh r0, [r5]\n\
    ldrb r1, [r7]\n\
    ldrb r2, [r4]\n\
    bl move_effectiveness_something\n\
    mov r4, sp\n\
    add r4, r8\n\
    ldr r2, _08108358 @ =gBattleMoveDamage\n\
    ldr r0, _08108334 @ =0x02016800\n\
    adds r0, 0x18\n\
    adds r0, r6, r0\n\
    ldrb r1, [r0]\n\
    ldr r0, [r2]\n\
    muls r0, r1\n\
    movs r1, 0x64\n\
    bl __divsi3\n\
    str r0, [r4]\n\
    cmp r0, 0\n\
    bne _08108364\n\
    movs r0, 0x1\n\
    str r0, [r4]\n\
    b _08108364\n\
    .align 2, 0\n\
_08108328: .4byte sDiscouragedPowerfulMoveEffects\n\
_0810832C: .4byte 0x0000ffff\n\
_08108330: .4byte gBattleMoves\n\
_08108334: .4byte 0x02016800\n\
_08108338: .4byte gDynamicBasePower\n\
_0810833C: .4byte 0xfffff81c\n\
_08108340: .4byte gBattleMoveFlags\n\
_08108344: .4byte gCritMultiplier\n\
_08108348: .4byte gBattleMons\n\
_0810834C: .4byte gBankAttacker\n\
_08108350: .4byte gCurrentMove\n\
_08108354: .4byte gBankTarget\n\
_08108358: .4byte gBattleMoveDamage\n\
_0810835C:\n\
    mov r1, sp\n\
    add r1, r8\n\
    movs r0, 0\n\
    str r0, [r1]\n\
_08108364:\n\
    mov r6, r10\n\
    cmp r6, 0x3\n\
    ble _08108276\n\
    movs r6, 0\n\
    ldr r1, _081083A4 @ =0x02016800\n\
    ldrb r0, [r1, 0x1]\n\
    lsls r0, 2\n\
    add r0, sp\n\
    ldr r2, [sp]\n\
    ldr r0, [r0]\n\
    adds r5, r1, 0\n\
    ldr r4, _081083A8 @ =gAIScriptPtr\n\
    cmp r2, r0\n\
    bgt _0810839A\n\
    adds r3, r5, 0\n\
    mov r2, sp\n\
_08108384:\n\
    adds r2, 0x4\n\
    adds r6, 0x1\n\
    cmp r6, 0x3\n\
    bgt _0810839A\n\
    ldrb r0, [r3, 0x1]\n\
    lsls r0, 2\n\
    add r0, sp\n\
    ldr r1, [r2]\n\
    ldr r0, [r0]\n\
    cmp r1, r0\n\
    ble _08108384\n\
_0810839A:\n\
    cmp r6, 0x4\n\
    bne _081083AC\n\
    movs r0, 0x2\n\
    str r0, [r5, 0x8]\n\
    b _081083B8\n\
    .align 2, 0\n\
_081083A4: .4byte 0x02016800\n\
_081083A8: .4byte gAIScriptPtr\n\
_081083AC:\n\
    movs r0, 0x1\n\
    str r0, [r5, 0x8]\n\
    b _081083B8\n\
_081083B2:\n\
    movs r0, 0\n\
    str r0, [r5, 0x8]\n\
    ldr r4, _081083D0 @ =gAIScriptPtr\n\
_081083B8:\n\
    ldr r0, [r4]\n\
    adds r0, 0x1\n\
    str r0, [r4]\n\
    add sp, 0x14\n\
    pop {r3-r5}\n\
    mov r8, r3\n\
    mov r9, r4\n\
    mov r10, r5\n\
    pop {r4-r7}\n\
    pop {r0}\n\
    bx r0\n\
    .align 2, 0\n\
_081083D0: .4byte gAIScriptPtr\n\
    .syntax divided\n");
}
#endif // NONMATCHING

static void BattleAICmd_get_move(void)
{
    if (gAIScriptPtr[1] == USER)
        AI_THINKING_STRUCT->funcResult = gLastUsedMove[gBankAttacker];
    else
        AI_THINKING_STRUCT->funcResult = gLastUsedMove[gBankTarget];

    gAIScriptPtr += 2;
}

static void BattleAICmd_if_arg_equal(void)
{
    if (gAIScriptPtr[1] == AI_THINKING_STRUCT->funcResult)
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

static void BattleAICmd_if_arg_not_equal(void)
{
    if (gAIScriptPtr[1] != AI_THINKING_STRUCT->funcResult)
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

static void BattleAICmd_if_would_go_first(void)
{
    if (b_first_side(gBankAttacker, gBankTarget, 1) == gAIScriptPtr[1])
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

static void BattleAICmd_if_would_not_go_first(void)
{
    if (b_first_side(gBankAttacker, gBankTarget, 1) != gAIScriptPtr[1])
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

static void BattleAICmd_nullsub_2A(void)
{
}

static void BattleAICmd_nullsub_2B(void)
{
}

static void BattleAICmd_count_alive_pokemon(void)
{
    struct Pokemon *party;
    int i;
    u8 index;
    u8 var, var2;

    AI_THINKING_STRUCT->funcResult = 0;

    if (gAIScriptPtr[1] == USER)
        index = gBankAttacker;
    else
        index = gBankTarget;

    if (GetBankSide(index) == 0)
        party = gPlayerParty;
    else
        party = gEnemyParty;

    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
    {
        u32 status;
        var = gBattlePartyID[index][0];
        status = GetBankIdentity(index) ^ 2;
        var2 = gBattlePartyID[GetBankByPlayerAI(status)][0];
    }
    else
    {
        var = gBattlePartyID[index][0];
        var2 = gBattlePartyID[index][0];
    }

    for (i = 0; i < 6; i++)
    {
        if (i != var && i != var2
         && GetMonData(&party[i], MON_DATA_HP) != 0
         && GetMonData(&party[i], MON_DATA_SPECIES2) != SPECIES_NONE
         && GetMonData(&party[i], MON_DATA_SPECIES2) != SPECIES_EGG)
        {
            AI_THINKING_STRUCT->funcResult++;
        }
    }

    gAIScriptPtr += 2;
}

static void BattleAICmd_get_considered_move(void)
{
    AI_THINKING_STRUCT->funcResult = AI_THINKING_STRUCT->moveConsidered;
    gAIScriptPtr += 1;
}

static void BattleAICmd_get_considered_move_effect(void)
{
    AI_THINKING_STRUCT->funcResult = gBattleMoves[AI_THINKING_STRUCT->moveConsidered].effect;
    gAIScriptPtr += 1;
}

static void BattleAICmd_get_ability(void)
{
    u8 index;

    if (gAIScriptPtr[1] == USER)
        index = gBankAttacker;
    else
        index = gBankTarget;

    if (GetBankSide(index) == TARGET)
    {
        u16 unk = GetBankIdentity(index) & 1;

        if (UNK_2016A00_STRUCT->unk20[unk] != 0)
        {
            AI_THINKING_STRUCT->funcResult = UNK_2016A00_STRUCT->unk20[unk];
            gAIScriptPtr += 2;
            return;
        }

        // abilities that prevent fleeing.
        if (gBattleMons[index].ability == ABILITY_SHADOW_TAG
        || gBattleMons[index].ability == ABILITY_MAGNET_PULL
        || gBattleMons[index].ability == ABILITY_ARENA_TRAP)
        {
            AI_THINKING_STRUCT->funcResult = gBattleMons[index].ability;
            gAIScriptPtr += 2;
            return;
        }

        if (gBaseStats[gBattleMons[index].species].ability1 != ABILITY_NONE)
        {
            if (gBaseStats[gBattleMons[index].species].ability2 != ABILITY_NONE)
            {
                // AI has no knowledge of opponent, so it guesses which ability.
                if (Random() % 2)
                {
                    AI_THINKING_STRUCT->funcResult = gBaseStats[gBattleMons[index].species].ability1;
                }
                else
                {
                    AI_THINKING_STRUCT->funcResult = gBaseStats[gBattleMons[index].species].ability2;
                }
            }
            else
            {
                AI_THINKING_STRUCT->funcResult = gBaseStats[gBattleMons[index].species].ability1; // it's definitely ability 1.
            }
        }
        else
        {
            AI_THINKING_STRUCT->funcResult = gBaseStats[gBattleMons[index].species].ability2; // AI cant actually reach this part since every mon has at least 1 ability.
        }
    }
    else
    {
        // The AI knows its own ability.
        AI_THINKING_STRUCT->funcResult = gBattleMons[index].ability;
    }
    gAIScriptPtr += 2;
}

static void BattleAICmd_get_highest_possible_damage(void)
{
    s32 i;

    gDynamicBasePower = 0;
    BATTLE_STRUCT->unk.unk1 = 0;
    BATTLE_STRUCT->unk.unk4 = 1;
    gBattleMoveFlags = 0;
    gCritMultiplier = 1;
    AI_THINKING_STRUCT->funcResult = 0;

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        gBattleMoveDamage = 40;
        gCurrentMove = gBattleMons[gBankAttacker].moves[i];

        if (gCurrentMove)
        {
            move_effectiveness_something(gCurrentMove, gBankAttacker, gBankTarget);

            // reduce by 1/3.
            if (gBattleMoveDamage == 120)
                gBattleMoveDamage = 80;
            if (gBattleMoveDamage == 240)
                gBattleMoveDamage = 160;
            if (gBattleMoveDamage == 30)
                gBattleMoveDamage = 20;
            if (gBattleMoveDamage == 15)
                gBattleMoveDamage = 10;

            if (gBattleMoveFlags & 8) // if it's a status move, it wont do anything.
                gBattleMoveDamage = 0;

            if (AI_THINKING_STRUCT->funcResult < gBattleMoveDamage)
                AI_THINKING_STRUCT->funcResult = gBattleMoveDamage;
        }
    }
    gAIScriptPtr += 1;
}

static void BattleAICmd_if_damage_bonus(void)
{
    u8 damageVar;

    gDynamicBasePower = 0;
    BATTLE_STRUCT->unk.unk1 = 0;
    BATTLE_STRUCT->unk.unk4 = 1;
    gBattleMoveFlags = 0;
    gCritMultiplier = 1;

    gBattleMoveDamage = 40;
    gCurrentMove = AI_THINKING_STRUCT->moveConsidered;

    move_effectiveness_something(gCurrentMove, gBankAttacker, gBankTarget);

    if (gBattleMoveDamage == 120)
        gBattleMoveDamage = 80;
    if (gBattleMoveDamage == 240)
        gBattleMoveDamage = 160;
    if (gBattleMoveDamage == 30)
        gBattleMoveDamage = 20;
    if (gBattleMoveDamage == 15)
        gBattleMoveDamage = 10;

    if (gBattleMoveFlags & 8)
        gBattleMoveDamage = 0;

    // store gBattleMoveDamage in a u8 variable because gAIScriptPtr[1] is a u8.
    damageVar = gBattleMoveDamage;

    if (damageVar == gAIScriptPtr[1])
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

static void BattleAICmd_nullsub_32(void)
{
}

static void BattleAICmd_nullsub_33(void)
{
}

static void BattleAICmd_if_status_in_party(void)
{
    struct Pokemon *party;
    struct Pokemon *partyPtr;
    int i;
    u32 statusToCompareTo;

    // for whatever reason, game freak put the party pointer into 2 variables instead of 1. it's possible at some point the switch encompassed the whole function and used each respective variable creating largely duplicate code.
    switch (gAIScriptPtr[1])
    {
    case 1:
        party = partyPtr = gEnemyParty;
        break;
    default:
        party = partyPtr = gPlayerParty;
        break;
    }

    statusToCompareTo = AIScriptRead32(gAIScriptPtr + 2);

    for (i = 0; i < 6; i++)
    {
        u16 species = GetMonData(&party[i], MON_DATA_SPECIES);
        u16 hp = GetMonData(&party[i], MON_DATA_HP);
        u32 status = GetMonData(&party[i], MON_DATA_STATUS);

        if (species != SPECIES_NONE && species != SPECIES_EGG && hp != 0 && status == statusToCompareTo)
        {
            gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 6); // WHAT. why is this being merged into the above switch
            return;
        }
    }

    gAIScriptPtr += 10;
}

// bugged, doesnt return properly. also unused
static void BattleAICmd_if_status_not_in_party(void)
{
    struct Pokemon *party;
    struct Pokemon *partyPtr;
    int i;
    u32 statusToCompareTo;

    switch (gAIScriptPtr[1])
    {
    case 1:
        party = partyPtr = gEnemyParty;
        break;
    default:
        party = partyPtr = gPlayerParty;
        break;
    }

    statusToCompareTo = AIScriptRead32(gAIScriptPtr + 2);

    for (i = 0; i < 6; i++)
    {
        u16 species = GetMonData(&party[i], MON_DATA_SPECIES);
        u16 hp = GetMonData(&party[i], MON_DATA_HP);
        u32 status = GetMonData(&party[i], MON_DATA_STATUS);

        // everytime the status is found, the AI's logic jumps further and further past its intended destination. this results in a broken AI macro and is probably why it is unused.
        if (species != SPECIES_NONE && species != SPECIES_EGG && hp != 0 && status == statusToCompareTo)
            gAIScriptPtr += 10; // doesnt return?
    }
    gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 6);
}

static void BattleAICmd_get_weather(void)
{
    if (gBattleWeather & 7)
        AI_THINKING_STRUCT->funcResult = WEATHER_RAIN;
    if (gBattleWeather & 0x18)
        AI_THINKING_STRUCT->funcResult = WEATHER_SANDSTORM;
    if (gBattleWeather & 0x60)
        AI_THINKING_STRUCT->funcResult = WEATHER_SUN;
    if (gBattleWeather & 0x80)
        AI_THINKING_STRUCT->funcResult = WEATHER_HAIL;

    gAIScriptPtr += 1;
}

static void BattleAICmd_if_effect(void)
{
    if (gBattleMoves[AI_THINKING_STRUCT->moveConsidered].effect == gAIScriptPtr[1])
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

static void BattleAICmd_if_not_effect(void)
{
    if (gBattleMoves[AI_THINKING_STRUCT->moveConsidered].effect != gAIScriptPtr[1])
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

static void BattleAICmd_if_stat_level_less_than(void)
{
    u32 party;

    if (gAIScriptPtr[1] == USER)
        party = gBankAttacker;
    else
        party = gBankTarget;

    if (gBattleMons[party].statStages[gAIScriptPtr[2]] < gAIScriptPtr[3])
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 4);
    else
        gAIScriptPtr += 8;
}

static void BattleAICmd_if_stat_level_more_than(void)
{
    u32 party;

    if (gAIScriptPtr[1] == USER)
        party = gBankAttacker;
    else
        party = gBankTarget;

    if (gBattleMons[party].statStages[gAIScriptPtr[2]] > gAIScriptPtr[3])
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 4);
    else
        gAIScriptPtr += 8;
}

static void BattleAICmd_if_stat_level_equal(void)
{
    u32 party;

    if (gAIScriptPtr[1] == USER)
        party = gBankAttacker;
    else
        party = gBankTarget;

    if (gBattleMons[party].statStages[gAIScriptPtr[2]] == gAIScriptPtr[3])
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 4);
    else
        gAIScriptPtr += 8;
}

static void BattleAICmd_if_stat_level_not_equal(void)
{
    u32 party;

    if (gAIScriptPtr[1] == USER)
        party = gBankAttacker;
    else
        party = gBankTarget;

    if (gBattleMons[party].statStages[gAIScriptPtr[2]] != gAIScriptPtr[3])
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 4);
    else
        gAIScriptPtr += 8;
}

static void BattleAICmd_if_can_faint(void)
{
    if (gBattleMoves[AI_THINKING_STRUCT->moveConsidered].power < 2)
    {
        gAIScriptPtr += 5;
        return;
    }

    gDynamicBasePower = 0;
    BATTLE_STRUCT->unk.unk1 = 0;
    BATTLE_STRUCT->unk.unk4 = 1;
    gBattleMoveFlags = 0;
    gCritMultiplier = 1;
    gCurrentMove = AI_THINKING_STRUCT->moveConsidered;
    sub_801CAF8(gBankAttacker, gBankTarget);
    move_effectiveness_something(gCurrentMove, gBankAttacker, gBankTarget);

    gBattleMoveDamage = gBattleMoveDamage * AI_THINKING_STRUCT->simulatedRNG[AI_THINKING_STRUCT->movesetIndex] / 100;

    // moves always do at least 1 damage.
    if (gBattleMoveDamage == 0)
        gBattleMoveDamage = 1;

    if (gBattleMons[gBankTarget].hp <= gBattleMoveDamage)
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void BattleAICmd_if_cant_faint(void)
{
    if (gBattleMoves[AI_THINKING_STRUCT->moveConsidered].power < 2)
    {
        gAIScriptPtr += 5;
        return;
    }

    gDynamicBasePower = 0;
    BATTLE_STRUCT->unk.unk1 = 0;
    BATTLE_STRUCT->unk.unk4 = 1;
    gBattleMoveFlags = 0;
    gCritMultiplier = 1;
    gCurrentMove = AI_THINKING_STRUCT->moveConsidered;
    sub_801CAF8(gBankAttacker, gBankTarget);
    move_effectiveness_something(gCurrentMove, gBankAttacker, gBankTarget);

    gBattleMoveDamage = gBattleMoveDamage * AI_THINKING_STRUCT->simulatedRNG[AI_THINKING_STRUCT->movesetIndex] / 100;

    // this macro is missing the damage 0 = 1 assumption.

    if (gBattleMons[gBankTarget].hp > gBattleMoveDamage)
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void BattleAICmd_if_has_move(void)
{
    int i;
    u16 *temp_ptr = (u16 *)(gAIScriptPtr + 2);

    switch (gAIScriptPtr[1])
    {
    case 1:
    case 3:
        for (i = 0; i < MAX_MON_MOVES; i++)
        {
            if (gBattleMons[gBankAttacker].moves[i] == *temp_ptr)
                break;
        }
        if (i == MAX_MON_MOVES)
            gAIScriptPtr += 8;
        else
            gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 4);
        break;
    case 0:
    case 2:
        for (i = 0; i < 8; i++)
        {
            if (UNK_2016A00_STRUCT->movesUsed[gBankTarget >> 1][i] == *temp_ptr)
                break;
        }
        if (i == 8)
            gAIScriptPtr += 8;
         else
            gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 4);
        break;
    }
}

static void BattleAICmd_if_dont_have_move(void)
{
    int i;
    u16 *temp_ptr = (u16 *)(gAIScriptPtr + 2);

    switch (gAIScriptPtr[1])
    {
    case 1:
    case 3:
        for (i = 0; i < MAX_MON_MOVES; i++)
        {
            if (gBattleMons[gBankAttacker].moves[i] == *temp_ptr)
                break;
        }
        if (i != MAX_MON_MOVES)
            gAIScriptPtr += 8;
        else
            gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 4);
        break;
    case 0:
    case 2:
        for (i = 0; i < 8; i++)
        {
            if (UNK_2016A00_STRUCT->movesUsed[gBankTarget >> 1][i] == *temp_ptr)
                break;
        }
        if (i != 8)
            gAIScriptPtr += 8;
        else
            gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 4);
        break;
    }
}

static void BattleAICmd_if_move_effect(void)
{
    int i;

    switch (gAIScriptPtr[1])
    {
    case 1:
    case 3:
        for (i = 0; i < MAX_MON_MOVES; i++)
        {
            if (gBattleMons[gBankAttacker].moves[i] != 0 && gBattleMoves[gBattleMons[gBankAttacker].moves[i]].effect == gAIScriptPtr[2])
                break;
        }
        if (i != MAX_MON_MOVES)
            gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 3);
        else
            gAIScriptPtr += 7;
        break;
    case 0:
    case 2:
        for (i = 0; i < 8; i++)
        {
            if (gBattleMons[gBankAttacker].moves[i] != 0 && gBattleMoves[UNK_2016A00_STRUCT->movesUsed[gBankTarget >> 1][i]].effect == gAIScriptPtr[2])
                break;
        }
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 3);
    }
}

static void BattleAICmd_if_not_move_effect(void)
{
    int i;

    switch (gAIScriptPtr[1])
    {
    case 1:
    case 3:
        for (i = 0; i < MAX_MON_MOVES; i++)
        {
            if (gBattleMons[gBankAttacker].moves[i] != 0 && gBattleMoves[gBattleMons[gBankAttacker].moves[i]].effect == gAIScriptPtr[2])
                break;
        }
        if (i != MAX_MON_MOVES)
            gAIScriptPtr += 7;
        else
            gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 3);
        break;
    case 0:
    case 2:
        for (i = 0; i < 8; i++)
        {
            if (UNK_2016A00_STRUCT->movesUsed[gBankTarget >> 1][i] != 0 && gBattleMoves[UNK_2016A00_STRUCT->movesUsed[gBankTarget >> 1][i]].effect == gAIScriptPtr[2])
                break;
        }
        gAIScriptPtr += 7;
    }
}

static void BattleAICmd_if_last_move_did_damage(void)
{
    u8 index;

    if (gAIScriptPtr[1] == USER)
        index = gBankAttacker;
    else
        index = gBankTarget;

    if (gAIScriptPtr[2] == 0)
    {
        if (gDisableStructs[index].unk4 == 0)
        {
            gAIScriptPtr += 7;
            return;
        }
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 3);
        return;
    }
    else if (gAIScriptPtr[2] != 1) // ignore the macro if its not 0 or 1.
    {
        gAIScriptPtr += 7;
        return;
    }
    else if (gDisableStructs[index].unk6 != 0)
    {
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 3);
        return;
    }
    gAIScriptPtr += 7;
}

static void BattleAICmd_if_encored(void)
{
    switch (gAIScriptPtr[1])
    {
    case 0: // _08109348
        if (gDisableStructs[gActiveBank].unk4 == AI_THINKING_STRUCT->moveConsidered)
        {
            gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 2);
            return;
        }
        gAIScriptPtr += 6;
        return;
    case 1: // _08109370
        if (gDisableStructs[gActiveBank].unk6 == AI_THINKING_STRUCT->moveConsidered)
        {
            gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 2);
            return;
        }
        gAIScriptPtr += 6;
        return;
    default:
        gAIScriptPtr += 6;
        return;
    }
}

static void BattleAICmd_flee(void)
{
    AI_THINKING_STRUCT->aiAction |= (AI_ACTION_DONE | AI_ACTION_FLEE | AI_ACTION_DO_NOT_ATTACK); // what matters is AI_ACTION_FLEE being enabled.
}

static void BattleAICmd_if_random_100(void)
{
    u8 safariFleeRate = BATTLE_STRUCT->safariFleeRate * 5; // safari flee rate, from 0-20

    if ((u8)(Random() % 100) < safariFleeRate)
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void BattleAICmd_watch(void)
{
    AI_THINKING_STRUCT->aiAction |= (AI_ACTION_DONE | AI_ACTION_WATCH | AI_ACTION_DO_NOT_ATTACK); // what matters is AI_ACTION_WATCH being enabled.
}

static void BattleAICmd_get_hold_effect(void)
{
    u8 index;
    u16 status;

    if (gAIScriptPtr[1] == USER)
        index = gBankAttacker;
    else
        index = gBankTarget;

    if (GetBankSide(index) == 0)
    {
        status = (GetBankIdentity(index) & 1);
        AI_THINKING_STRUCT->funcResult = UNK_2016A00_STRUCT->unk22[status];
    }
    else
        AI_THINKING_STRUCT->funcResult = ItemId_GetHoldEffect(gBattleMons[index].item);

    gAIScriptPtr += 2;
}

static void BattleAICmd_get_gender(void)
{
    u8 index;

    if (gAIScriptPtr[1] == USER)
        index = gBankAttacker;
    else
        index = gBankTarget;

    AI_THINKING_STRUCT->funcResult = GetGenderFromSpeciesAndPersonality(gBattleMons[index].species, gBattleMons[index].personality);

    gAIScriptPtr += 2;
}

static void BattleAICmd_is_first_turn(void)
{
    u8 index;

    if (gAIScriptPtr[1] == USER)
        index = gBankAttacker;
    else
        index = gBankTarget;

    AI_THINKING_STRUCT->funcResult = gDisableStructs[index].unk16;

    gAIScriptPtr += 2;
}

static void BattleAICmd_get_stockpile_count(void)
{
    u8 index;

    if (gAIScriptPtr[1] == USER)
        index = gBankAttacker;
    else
        index = gBankTarget;

    AI_THINKING_STRUCT->funcResult = gDisableStructs[index].unk9;

    gAIScriptPtr += 2;
}

static void BattleAICmd_is_double_battle(void)
{
    AI_THINKING_STRUCT->funcResult = gBattleTypeFlags & BATTLE_TYPE_DOUBLE;

    gAIScriptPtr += 1;
}

static void BattleAICmd_get_item(void)
{
    u8 index;

    if (gAIScriptPtr[1] == USER)
        index = gBankAttacker;
    else
        index = gBankTarget;

    // this hack and a half matches. whatever. i dont care. someone else fix this mess later. PS: still cant fix this.
    AI_THINKING_STRUCT->funcResult = ewram[0x160CC + (index * 2)];

    gAIScriptPtr += 2;
}

static void BattleAICmd_get_move_type_from_result(void)
{
    AI_THINKING_STRUCT->funcResult = gBattleMoves[AI_THINKING_STRUCT->funcResult].type;

    gAIScriptPtr += 1;
}

static void BattleAICmd_get_move_power_from_result(void)
{
    AI_THINKING_STRUCT->funcResult = gBattleMoves[AI_THINKING_STRUCT->funcResult].power;

    gAIScriptPtr += 1;
}

static void BattleAICmd_get_move_effect_from_result(void)
{
    AI_THINKING_STRUCT->funcResult = gBattleMoves[AI_THINKING_STRUCT->funcResult].effect;

    gAIScriptPtr += 1;
}

static void BattleAICmd_get_protect_count(void)
{
    u8 index;

    if (gAIScriptPtr[1] == USER)
        index = gBankAttacker;
    else
        index = gBankTarget;

    AI_THINKING_STRUCT->funcResult = gDisableStructs[index].unk8;

    gAIScriptPtr += 2;
}

static void BattleAICmd_nullsub_52(void)
{
}

static void BattleAICmd_nullsub_53(void)
{
}

static void BattleAICmd_nullsub_54(void)
{
}

static void BattleAICmd_nullsub_55(void)
{
}

static void BattleAICmd_nullsub_56(void)
{
}

static void BattleAICmd_nullsub_57(void)
{
}

static void BattleAICmd_call(void)
{
    AIStackPushVar(gAIScriptPtr + 5);
    gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 1);
}

static void BattleAICmd_jump(void)
{
    gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 1);
}

static void BattleAICmd_end(void)
{
    if (AIStackPop() == FALSE)
        AI_THINKING_STRUCT->aiAction |= AI_ACTION_DONE;
}

static void BattleAICmd_if_level_compare(void)
{
    switch (gAIScriptPtr[1])
    {
    case 0: // greater than
        if (gBattleMons[gBankAttacker].level > gBattleMons[gBankTarget].level)
        {
            gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 2);
            return;
        }
        gAIScriptPtr += 6;
        return;
    case 1: // less than
        if (gBattleMons[gBankAttacker].level < gBattleMons[gBankTarget].level)
        {
            gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 2);
            return;
        }
        gAIScriptPtr += 6;
        return;
    case 2: // equal
        if (gBattleMons[gBankAttacker].level == gBattleMons[gBankTarget].level)
        {
            gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 2);
            return;
        }
        gAIScriptPtr += 6;
        return;
    }
}

static void BattleAICmd_if_taunted(void)
{
    if (gDisableStructs[gBankTarget].taunt != 0)
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void BattleAICmd_if_not_taunted(void)
{
    if (gDisableStructs[gBankTarget].taunt == 0)
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

void AIStackPushVar(u8 *var)
{
    AI_STACK->ptr[AI_STACK->size++] = var;
}

// unused
void AIStackPushAIPtr(void)
{
    AI_STACK->ptr[AI_STACK->size++] = gAIScriptPtr;
}

bool8 AIStackPop(void)
{
    if (AI_STACK->size != 0)
    {
        --AI_STACK->size;
        gAIScriptPtr = AI_STACK->ptr[AI_STACK->size];
        return TRUE;
    }
    else
        return FALSE;
}
