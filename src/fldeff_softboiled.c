#include "global.h"
#include "fldeff_softboiled.h"
#include "menu.h"
#include "party_menu.h"
#include "pokemon.h"
#include "pokemon_menu.h"
#include "songs.h"
#include "sound.h"
#include "sprite.h"
#include "strings.h"
#include "task.h"

struct UnknownStruct1
{
    u8 filler0[0x259];
    u8 unk259;
    u8 filler25A[6];
    u8 unk260;
    u8 unk261;
    u8 unk262;
    s16 unk264;
    s16 unk266;
    u8 filler268[10];
    u16 unk272;
    u8 filler274[14];
    u16 unk282;
};

struct UnknownStruct2
{
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 filler3[9];
    void *unkC;
};

struct UnknownStruct3
{
    struct Pokemon *unk0;
    u8 filler4[1];
    u8 unk5;
    u16 unk6;
    u8 filler8[4];
    s32 unkC;
    void *unk10;
    u8 filler14[26];
    s16 unk2E;
};

#if ENGLISH
#define WINDOW_LEFT 3
#define WINDOW_RIGHT 26
#elif GERMAN
#define WINDOW_LEFT 0
#define WINDOW_RIGHT 29
#endif

#define EWRAM_1000 (*(struct UnknownStruct2 *)(unk_2000000 + 0x1000))
#define EWRAM_1B000 (*(struct UnknownStruct1 *)(unk_2000000 + 0x1B000))
#define EWRAM_1C000 (*(struct UnknownStruct3 *)(unk_2000000 + 0x1C000))

// extern
extern u8 gUnknown_0202E8F6;
extern u8 gLastFieldPokeMenuOpened;

extern u8 unk_2000000[];
extern u8 gUnknown_0202E8F4;

// Static
static void sub_8133D50(u8 taskId);
static void sub_8133E74(u8 taskId);
static void sub_8133EB8(u8 taskId);
static void sub_8133EF8(void);

bool8 SetUpFieldMove_SoftBoiled(void)
{
    u16 maxHp;
    u16 hp;
    u16 minHp;

    maxHp = GetMonData(&gPlayerParty[gLastFieldPokeMenuOpened], MON_DATA_MAX_HP);
    hp = GetMonData(&gPlayerParty[gLastFieldPokeMenuOpened], MON_DATA_HP);

    minHp = (maxHp / 5);
    if (hp >= minHp)
    {
        return TRUE;
    }

    return FALSE;
}

void sub_8133D28(u8 taskid)
{
    EWRAM_1000.unkC = sub_8133D50;
    EWRAM_1B000.unk272 = 3;
    sub_808A004(taskid);
}

static void sub_8133D50(u8 taskId)
{
    u8 unk1, unk2;
    u16 hp;
    struct Pokemon *pokemon;
    //struct Task *task;

    struct Sprite *sprites = gSprites;

    unk1 = sprites[EWRAM_1000.unk1].data0;
    unk2 = sprites[EWRAM_1000.unk2].data0;

    if (unk1 > 5 || unk2 > 5)
    {
        sub_806CD44(taskId);
        return;
    }

    EWRAM_1C000.unk0 = &gPlayerParty[sprites[EWRAM_1000.unk2].data0];
    hp = GetMonData(EWRAM_1C000.unk0, MON_DATA_HP);

    if (hp == 0 || unk1 == unk2 || GetMonData(EWRAM_1C000.unk0, MON_DATA_MAX_HP) == hp)
    {
        sub_8133EB8(taskId);
        return;
    }

    PlaySE(SE_KAIFUKU);

    EWRAM_1C000.unk5 = gSprites[EWRAM_1000.unk1].data0;

    pokemon = &gPlayerParty[EWRAM_1C000.unk5];
    EWRAM_1C000.unk0 = pokemon;
    EWRAM_1C000.unk6 = 0;
    EWRAM_1C000.unkC = -0x8000;
    EWRAM_1C000.unk10 = sub_8133EF8;

    gTasks[taskId].data[10] = GetMonData(EWRAM_1C000.unk0, MON_DATA_MAX_HP);
    gTasks[taskId].data[11] = GetMonData(EWRAM_1C000.unk0, MON_DATA_HP);
    gTasks[taskId].data[12] = gTasks[taskId].data[10] / 5;

    sub_806D5A4();
    gTasks[taskId].func = sub_806FA18;
    EWRAM_1B000.unk282 = gTasks[taskId].data[11];
}

static void sub_8133E74(u8 taskId)
{
    if (gUnknown_0202E8F6)
    {
        return;
    }

    MenuZeroFillWindowRect(WINDOW_LEFT, 14, WINDOW_RIGHT, 19);
    sub_806D538(3, 0);
    gTasks[taskId].func = sub_806CB74;
}

static void sub_8133EB8(u8 taskId)
{
    gUnknown_0202E8F4 = 0;
    sub_806D5A4();
    sub_806E834(gOtherText_CantUseOnPoke, 1);
    gTasks[taskId].func = sub_8133E74;
}

static void sub_8133EF8(void)
{
    sub_806CCE4();
    EWRAM_1B000.unk261 = 2;
    DestroySprite(&gSprites[EWRAM_1000.unk1]);
    MenuZeroFillWindowRect(WINDOW_LEFT, 14, WINDOW_RIGHT, 19);
    sub_806D538(0, 0);
    SwitchTaskToFollowupFunc(EWRAM_1000.unk0);
}
