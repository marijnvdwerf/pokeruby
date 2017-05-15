#include "global.h"
#include "asm.h"
#include "decompress.h"
#include "event_data.h"
#include "m4a.h"
#include "main.h"
#include "menu.h"
#include "palette.h"
#include "pokedex.h"
#include "rng.h"
#include "songs.h"
#include "sound.h"
#include "species.h"
#include "starter_choose.h"
#include "trig.h"

asm(".set REG_BASE, 0x4000000");
asm(".set OFFSET_REG_BLDCNT,      0x50");
asm(".set OFFSET_REG_BLDALPHA,    0x52");
asm(".set REG_BLDCNT,      REG_BASE + OFFSET_REG_BLDCNT");
asm(".set REG_BLDALPHA,    REG_BASE + OFFSET_REG_BLDALPHA");

u32 NationalPokedexNumToSpecies(u16 nationalNum);

struct MonCoords
{
    u8 x, y;
};

extern void *species_and_otid_get_pal(u32, u16, u16);

enum
{
    PAGE_TITLE,
    PAGE_DIRECTOR,
    PAGE_ART_DIRECTOR,
    PAGE_BATTLE_DIRECTOR,
    PAGE_MAIN_PROGRAMMER,
    PAGE_BATTLE_SYSTEM_PROGRAMMER,
    PAGE_PROGRAMMERS_1,
    PAGE_PROGRAMMERS_2,
    PAGE_PROGRAMMERS_3,
    PAGE_MAIN_GRAHPICS_DESIGNER,
    PAGE_POKEMON_GRAHPIC_DESIGNERS_1,
    PAGE_POKEMON_GRAHPIC_DESIGNERS_2,
    PAGE_POKEMON_GRAHPIC_DESIGNERS_3,
    PAGE_POKEMON_DESIGNERS_1,
    PAGE_POKEMON_DESIGNERS_2,
    PAGE_MUSIC_COMPOSITION,
    PAGE_SOUND_EFFECTS,
    PAGE_GAME_DESIGNERS_1,
    PAGE_GAME_DESIGNERS_2,
    PAGE_GAME_DESIGNERS_3,
    PAGE_PLOT_SCENARIO,
    PAGE_GAME_SCENARIO,
    PAGE_SCRIPT_DESIGNERS,
    PAGE_MAP_DESIGNERS,
    PAGE_MAP_DATA_DESIGNERS,
    PAGE_PARAMETRIC_DESIGNERS,
    PAGE_POKEDEX_TEXT,
    PAGE_ENVIRONMENT_TOOLS,
    PAGE_PRODUCT_TESTING,
    PAGE_SPECIAL_THANKS,
    PAGE_SPECIAL_THANKS_1,
    PAGE_SPECIAL_THANKS_2,
    PAGE_SPECIAL_THANKS_3,
    PAGE_INFORMATION_SUPERVISORS,
    PAGE_COORDINATORS,
    PAGE_TASK_MANAGERS,
    PAGE_PRODUCERS,
    PAGE_EXECUTIVE_DIRECTOR,
    PAGE_EXECUTIVE_PRODUCERS_1,
    PAGE_EXECUTIVE_PRODUCERS_2,
    PAGE_TRANSLATION_COORDINATOR,
    PAGE_TRANSLATORS,
    PAGE_PROGRAMMERS,
    PAGE_GRAPHIC_DESIGNERS,
    PAGE_PRODUCT_SUPPORT,
    PAGE_ARTWORK,
    PAGE_TEXT_EDITOR,
    PAGE_NOA_TESTING,
    PAGE_BRAILLE_CODE_CHECK_1,
    PAGE_BRAILLE_CODE_CHECK_2,
    PAGE_SPECIAL_THANKS_4,
    PAGE_SPECIAL_THANKS_5,

    PAGE_COUNT
};

#define UNK_DEFINE_82 (0x82)

#define COLOR_DARK_GREEN 0x1967
#define COLOR_LIGHT_GREEN 0x328D

enum
{
    TDA_0 = 0,
    TDA_TASK_C_ID = 1,
    TDA_TASK_E_ID = 2,
    TDA_TASK_D_ID = 3,
    TDA_4 = 4,
    TDA_PLAYER_CYCLIST = 5,
    TDA_RIVAL_CYCLIST = 6,
    TDA_7 = 7, // Has something to do with the bike scene
    TDA_11 = 11, // Gets set depending on whether the bike or the grass scene should be shown
    TDA_12 = 12,
    TDA_13 = 13,
    TDA_14 = 14,
    TDA_TASK_B_ID = 15,

    // Appears to be responsible for text
            TDB_0 = 0,
    TDB_TASK_A_ID = 1,
    TDB_CURRENT_PAGE = 2,
    TDB_3 = 3,

    TDC_0 = 0,
    TDC_1 = 1,
    TDC_2 = 2,
    TDC_3 = 3,
    TDC_4 = 4,
    TDC_5 = 5,

    TDD_STATE = 0,
    TDD_TASK_A_ID = 1,
    TDD_2 = 2,
    TDD_3 = 3,

    TDE_0 = 0,
    TDE_1 = 1,
    TDE_TASK_A_ID = 2,
};

#define POKEMON_TILE_COUNT 68

struct Unk201C000
{
    u16 unk0[POKEMON_TILE_COUNT];
    u16 unk88;
    u16 unk8A;
    u16 unk8C;
    u16 unk8E;
    u16 unk90[386];
    u16 unk394;
};

struct CreditsEntry
{
    u8 var_0;
    u8 *text;
};

extern u8 ewram[];

#define EWRAM_1F800          ((u16 *)(ewram + 0x1F800))
#define HALL_OF_FAME_SHEET_0 ((u8 *)(ewram + 0x1E000))
#define HALL_OF_FAME_SHEET_1 ((u8 *)(ewram + 0x1E800))
#define HALL_OF_FAME_SHEET_2 ((u8 *)(ewram + 0x1F000))
#define ewram1c000           (*(struct Unk201C000 *)(ewram + 0x1C000))

extern struct HallOfFame gHallOfFame;
extern u8 unk_201e800[0x800];
extern u8 unk_201f000[0x800];
extern u16 unk_201f800[];

extern struct SpriteTemplate gUnknown_02024E8C;

extern s16 gUnknown_02039320;
extern u16 gUnknown_02039322; // TASK A
extern u8 gUnknown_02039324;
extern u8 gUnknown_02039325;
extern u16 gUnknown_02039358;
extern s16 gUnknown_0203935A;
extern s16 gUnknown_0203935C;

extern u8 gReservedSpritePaletteCount;

// data/data2
extern struct MonCoords gMonFrontPicCoords[];
extern struct SpriteSheet gMonFrontPicTable[];

// data/starter_choose
extern u16 gBirchBagGrassPal[32];
extern u8 gBirchGrassTilemap[];
extern u8 gBirchHelpGfx[];

// data/hall_of_fame
extern void *gUnknown_0840B5A0[];

// data/credits
const u16 gUnknown_0840B7BC[] = INCBIN_U16("graphics/credits/palette_1.gbapal");
const u8 gUnknown_0840B7FC[] = INCBIN_U8("graphics/credits/ampersand.4bpp");
extern u8 gUnknown_0840B83C[];
extern u8 gUnknown_0840B84B[];
extern u8 gUnknown_0840B85A[];
extern u8 gUnknown_0840B869[];
extern u8 gUnknown_0840B878[];
extern struct CreditsEntry *gCreditsEntryPointerTable[][5];
extern u8 gUnknown_0840CA00[][2];
extern struct SpriteSheet gUnknown_0840CAA0;
extern struct SpritePalette gUnknown_0840CAB0;
extern const union AnimCmd *const gSpriteAnimTable_0840CA54[];
extern const union AnimCmd *const gSpriteAnimTable_0840CA94[];
extern struct SpriteTemplate gSpriteTemplate_840CAEC;

// data/intro_credits_graphics
extern const struct SpriteSheet gIntro2BrendanSpriteSheet;
extern const struct SpriteSheet gIntro2MaySpriteSheet;
extern const struct SpriteSheet gIntro2BicycleSpriteSheet;
extern const struct SpritePalette gIntro2SpritePalettes[];
extern const struct SpriteSheet gUnknown_08416E24;
extern const struct SpriteSheet gUnknown_08416E34;

// graphics
extern u8 gCreditsCopyrightEnd_Gfx[];
extern u16 gIntroCopyright_Pal[16];

static void task_a_8143B38(u8 taskIdA);
static void task_a_8143B68(u8 taskIdA);
static void task_a_8143BFC(u8 taskIdA);
static void task_a_80C9BFC(u8 taskIdA);
static void task_a_8143CC0(u8 taskIdA);
static void task_a_8143D04(u8 taskIdA);
static void task_a_8143EBC(u8 taskIdA);
static void task_a_8143F04(u8 taskIdA);
static void task_a_8143F3C(u8 taskIdA);
static void task_a_8143FDC(u8 taskIdA);
static void task_a_8144024(u8 taskIdA);
static void task_a_8144080(u8 taskIdA);
static void task_a_8144114(u8 taskIdA);
static void sub_8144130(void);
static void task_b_81441B8(u8 taskIdB);
static u8 sub_8144454(u8 page, u8 taskIdA);
static void task_d_8144514(u8 taskIdD);
static bool8 sub_8144ECC(u8 data, u8 taskIdA);
static void sub_81450AC(u8 taskIdA);
void sub_8145128(u16, u16, u16);
static void sub_81452D0(u16 arg0, u16 palette);
static void spritecb_player_8145378(struct Sprite *sprite);
static void spritecb_rival_8145420(struct Sprite *sprite);
u8 sub_81456B4(u16 nationalNum, u16 x, u16 y, u16 position);
void sub_81458DC(void);

static void vblank_8143948(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void sub_814395C(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();

    if (!(gMain.heldKeys & B_BUTTON))
    {
        return;
    }

    if (!gUnknown_02039324)
    {
        return;
    }

    if (gTasks[gUnknown_02039322].func != task_a_8143B68)
    {
        return;
    }

    vblank_8143948();
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
    gUnknown_02039325 = 1;
}

void sub_81439D0(void)
{
    u8 taskIdA;
    s16 taskIdC;
    u8 taskIdB;
    u16 savedIme;
    struct Unk201C000 *c000;

    sub_8144130();
    SetVBlankCallback(NULL);
    ResetPaletteFade();
    ResetTasks();

    taskIdA = CreateTask(task_a_8143B38, 0);

    gTasks[taskIdA].data[TDA_4] = 0;
    gTasks[taskIdA].data[TDA_7] = 0;
    gTasks[taskIdA].data[TDA_11] = 0;
    gTasks[taskIdA].data[TDA_13] = 1;

    while (TRUE)
    {
        if (sub_8144ECC(0, taskIdA))
        {
            break;
        }
    }

    taskIdC = gTasks[taskIdA].data[TDA_TASK_C_ID];
    gTasks[taskIdC].data[TDC_0] = 40;

    SetUpWindowConfig(&gWindowConfig_81E7208);
    InitMenuWindow(&gWindowConfig_81E7208);
    LoadPalette(&gUnknown_0840B7BC, 0x80, sizeof(gUnknown_0840B7BC));

    CpuCopy16(&gUnknown_0840B7FC, (void *)(VRAM + 0xBEE0), sizeof(gUnknown_0840B7FC));

    REG_BG0VOFS = 0xFFFC;

    taskIdB = CreateTask(task_b_81441B8, 0);

    gTasks[taskIdB].data[TDB_TASK_A_ID] = taskIdA;
    gTasks[taskIdA].data[TDA_TASK_B_ID] = taskIdB;

    BeginNormalPaletteFade(-1, 0, 16, 0, 0);

    savedIme = REG_IME;
    REG_IME = 0;
    REG_IE |= INTR_FLAG_VBLANK;
    REG_IME = savedIme;
    REG_DISPSTAT |= DISPSTAT_VBLANK_INTR;


    SetVBlankCallback(vblank_8143948);
    m4aSongNumStart(BGM_THANKFOR);
    SetMainCallback2(sub_814395C);
    gUnknown_02039325 = 0;

    c000 = &ewram1c000;

    sub_81458DC();

    c000->unk88 = 0;
    c000->unk8A = 0;
    c000->unk8C = 0;

    gUnknown_02039322 = taskIdA;
}

static void task_a_8143B38(u8 taskIdA)
{
    if (gPaletteFade.active)
    {
        return;
    }

    gTasks[taskIdA].func = task_a_8143B68;
}

static void task_a_8143B68(u8 taskIdA)
{
    u16 data11;

    if (gTasks[taskIdA].data[TDA_4])
    {
        s16 taskIdC;

        taskIdC = gTasks[taskIdA].data[TDA_TASK_C_ID];
        gTasks[taskIdC].data[TDC_0] = 30;

        gTasks[taskIdA].data[TDA_12] = 0x100;
        gTasks[taskIdA].func = task_a_8143EBC;
        return;
    }

    gUnknown_02039320 = 0;
    data11 = gTasks[taskIdA].data[TDA_11];

    if (gTasks[taskIdA].data[TDA_11] == 1)
    {
        gTasks[taskIdA].data[TDA_13] = data11;
        gTasks[taskIdA].data[TDA_11] = 0;
        BeginNormalPaletteFade(-1, 0, 0, 16, 0);
        gTasks[taskIdA].func = task_a_8143BFC;
    }
    else if (gTasks[taskIdA].data[TDA_11] == 2)
    {
        gTasks[taskIdA].data[TDA_13] = data11;
        gTasks[taskIdA].data[TDA_11] = 0;
        BeginNormalPaletteFade(-1, 0, 0, 16, 0);
        gTasks[taskIdA].func = task_a_8143CC0;
    }
}

static void task_a_8143BFC(u8 taskIdA)
{
    if (gPaletteFade.active)
    {
        return;
    }

    REG_DISPCNT = 0;
    sub_81450AC(taskIdA);
    gTasks[taskIdA].func = task_a_80C9BFC;
}

static void task_a_80C9BFC(u8 taskIdA)
{
    u16 backup;

    SetVBlankCallback(NULL);

    if (!sub_8144ECC(gTasks[taskIdA].data[TDA_7], taskIdA))
    {
        return;
    }

    BeginNormalPaletteFade(-1, 0, 16, 0, 0);

    backup = REG_IME;
    REG_IME = 0;
    REG_IE |= INTR_FLAG_VBLANK;
    REG_IME = backup;
    REG_DISPSTAT |= DISPSTAT_VBLANK_INTR;

    SetVBlankCallback(vblank_8143948);
    gTasks[taskIdA].func = task_a_8143B38;
}

static void task_a_8143CC0(u8 taskIdA)
{
    if (gPaletteFade.active)
    {
        return;
    }

    REG_DISPCNT = 0;
    sub_81450AC(taskIdA);
    gTasks[taskIdA].func = task_a_8143D04;
}

void task_a_8143D04(u8 taskIdA)
{
    switch (gMain.state)
    {
    default:
    case 0:
    {
        u16 i;

        ResetSpriteData();
        FreeAllSpritePalettes();
        gReservedSpritePaletteCount = 8;
        LZ77UnCompVram(&gBirchHelpGfx, (void *)VRAM);
        LZ77UnCompVram(&gBirchGrassTilemap, (void *)(VRAM + 0x3800));
        LoadPalette(gBirchBagGrassPal + 1, 1, 31 * 2);

        for (i = 0; i < 0x800; i++)
            HALL_OF_FAME_SHEET_0[i] = 0x11;
        for (i = 0; i < 0x800; i++)
            HALL_OF_FAME_SHEET_1[i] = 0x22;
        for (i = 0; i < 0x800; i++)
            HALL_OF_FAME_SHEET_2[i] = 0x33;

        EWRAM_1F800[0] = 0;
        EWRAM_1F800[1] = 0x53FF; // light yellow
        EWRAM_1F800[2] = 0x529F; // light red
        EWRAM_1F800[3] = 0x7E94; // light blue

        LoadSpriteSheet(&gUnknown_0840CAA0);
        LoadSpritePalette(&gUnknown_0840CAB0);

        gMain.state += 1;
        break;
    }
    case 1:
        gTasks[taskIdA].data[TDA_TASK_D_ID] = CreateTask(task_d_8144514, 0);
        gTasks[gTasks[taskIdA].data[TDA_TASK_D_ID]].data[TDD_STATE] = 1;
        gTasks[gTasks[taskIdA].data[TDA_TASK_D_ID]].data[TDD_TASK_A_ID] = taskIdA;
        gTasks[gTasks[taskIdA].data[TDA_TASK_D_ID]].data[TDD_2] = gTasks[taskIdA].data[TDA_7];

        BeginNormalPaletteFade(-1, 0, 16, 0, 0);
        REG_BG3HOFS = 0;
        REG_BG3VOFS = 32;
        REG_BG3CNT = BGCNT_PRIORITY(3) | BGCNT_CHARBASE(0) | BGCNT_SCREENBASE(7) | BGCNT_16COLOR | BGCNT_TXT256x256;
        REG_DISPCNT = DISPCNT_MODE_0 | DISPCNT_OBJ_1D_MAP | DISPCNT_BG0_ON | DISPCNT_BG3_ON | DISPCNT_OBJ_ON;

        gMain.state = 0;
        gUnknown_0203935C = 0;
        gTasks[taskIdA].func = task_a_8143B38;
        break;
    }
}

static void task_a_8143EBC(u8 taskIdA)
{
    if (gTasks[taskIdA].data[TDA_12])
    {
        gTasks[taskIdA].data[TDA_12] -= 1;
        return;
    }

    BeginNormalPaletteFade(-1, 12, 0, 16, 0);
    gTasks[taskIdA].func = task_a_8143F04;
}

static void task_a_8143F04(u8 taskIdA)
{
    if (gPaletteFade.active)
    {
        return;
    }

    sub_81450AC(taskIdA);
    gTasks[taskIdA].func = task_a_8143F3C;
}

static void task_a_8143F3C(u8 taskIdA)
{
    u16 backup;

    sub_8144130();
    ResetPaletteFade();
    sub_8145128(0, 0x3800, 0);
    ResetSpriteData();
    FreeAllSpritePalettes();
    BeginNormalPaletteFade(-1, 8, 16, 0, 0);

    REG_BG0CNT = BGCNT_PRIORITY(0) | BGCNT_CHARBASE(0) | BGCNT_SCREENBASE(7) | BGCNT_16COLOR | BGCNT_TXT256x256;
    backup = REG_IME;
    REG_IME = 0;
    REG_IE |= INTR_FLAG_VBLANK;
    REG_IME = backup;
    REG_DISPSTAT |= DISPSTAT_VBLANK_INTR;
    REG_DISPCNT = DISPCNT_MODE_0 | DISPCNT_OBJ_1D_MAP | DISPCNT_BG0_ON;

    gTasks[taskIdA].data[TDA_0] = 0x100;
    gTasks[taskIdA].func = task_a_8143FDC;
}

static void task_a_8143FDC(u8 taskIdA)
{
    if (gTasks[taskIdA].data[TDA_0])
    {
        gTasks[taskIdA].data[TDA_0] -= 1;
        return;
    }

    BeginNormalPaletteFade(-1, 6, 0, 16, 0);
    gTasks[taskIdA].func = task_a_8144024;
}

static void task_a_8144024(u8 taskIdA)
{
    if (gPaletteFade.active)
    {
        return;
    }

    sub_81452D0(0x3800, 0);

    BeginNormalPaletteFade(-1, 0, 0, 0, 0);
    gTasks[taskIdA].data[TDA_0] = 7200;
    gTasks[taskIdA].func = task_a_8144080;
}

static void task_a_8144080(u8 taskIdA)
{
    if (gPaletteFade.active)
    {
        return;
    }

    if (gTasks[taskIdA].data[TDA_0] == 0)
    {
        FadeOutBGM(4);
        BeginNormalPaletteFade(-1, 8, 0, 16, 0xFFFF);
        gTasks[taskIdA].func = task_a_8144114;
        return;
    }

    if (gMain.newKeys)
    {
        FadeOutBGM(4);
        BeginNormalPaletteFade(-1, 8, 0, 16, 0xFFFF);
        gTasks[taskIdA].func = task_a_8144114;
        return;
    }

    if (gTasks[taskIdA].data[TDA_0] == 7144)
    {
        FadeOutBGM(8);
    }

    if (gTasks[taskIdA].data[TDA_0] == 6840)
    {
        m4aSongNumStart(BGM_END);
    }

    gTasks[taskIdA].data[TDA_0] -= 1;
}

static void task_a_8144114(u8 taskIdA)
{
    if (gPaletteFade.active)
    {
        return;
    }

    SoftReset(0xFF);
}

static void sub_8144130(void)
{
    REG_DISPCNT = 0;

    REG_BG3HOFS = 0;
    REG_BG3VOFS = 0;
    REG_BG2HOFS = 0;
    REG_BG2VOFS = 0;
    REG_BG1HOFS = 0;
    REG_BG1VOFS = 0;
    REG_BG0HOFS = 0;
    REG_BG0VOFS = 0;

    REG_BLDCNT = 0;
    REG_BLDALPHA = 0;
    REG_BLDY = 0;

    DmaFill16(3, 0, (void *)VRAM, VRAM_SIZE);
    DmaFill32(3, 0, (void *)OAM, OAM_SIZE);
    DmaFill16(3, 0, (void *)(PLTT + 2), PLTT_SIZE - 2);
}

static void task_b_81441B8(u8 taskIdB)
{
    u16 i;

    switch (gTasks[taskIdB].data[TDB_0])
    {
    case 0:
    case 6:
    case 7:
    case 8:
    case 9:
    default:
        if (gPaletteFade.active)
        {
            return;
        }
        gTasks[taskIdB].data[TDB_0] = 1;
        gTasks[taskIdB].data[TDB_3] = 0x58;
        gTasks[gTasks[taskIdB].data[TDB_TASK_A_ID]].data[TDA_14] = 0;
        gUnknown_02039320 = 0;
        return;

    case 1:
        if (gTasks[taskIdB].data[TDB_3] != 0)
        {
            gTasks[taskIdB].data[TDB_3] -= 1;
            return;
        }

        gTasks[taskIdB].data[TDB_0] += 1;
        return;

    case 2:
        REG_DISPCNT &= ~DISPCNT_BG0_ON;

        if (gTasks[gTasks[taskIdB].data[TDB_TASK_A_ID]].func == task_a_8143B68)
        {
            if (gTasks[taskIdB].data[TDB_CURRENT_PAGE] < PAGE_COUNT)
            {

                for (i = 0; i < 5; i++)
                {
                    sub_8072BD8(gCreditsEntryPointerTable[gTasks[taskIdB].data[TDB_CURRENT_PAGE]][i]->text, 0, 9 + i * 2, 240);
                }

                gTasks[taskIdB].data[TDB_CURRENT_PAGE] += 1;
                gTasks[taskIdB].data[TDB_0] += 1;

                gTasks[gTasks[taskIdB].data[TDB_TASK_A_ID]].data[TDA_14] = 1;

                if (gTasks[gTasks[taskIdB].data[TDB_TASK_A_ID]].data[TDA_13] == 1)
                {
                    BeginNormalPaletteFade(0x300, 0, 16, 0, COLOR_LIGHT_GREEN);
                }
                else
                {
                    BeginNormalPaletteFade(0x300, 0, 16, 0, COLOR_DARK_GREEN);
                }
                return;
            }


            gTasks[taskIdB].data[TDB_0] = 10;
            return;
        }

        gTasks[gTasks[taskIdB].data[TDB_TASK_A_ID]].data[TDA_14] = 0;
        return;

    case 3:
        REG_DISPCNT |= DISPCNT_BG0_ON;

        if (gPaletteFade.active)
        {
            return;
        }

        gTasks[taskIdB].data[TDB_3] = UNK_DEFINE_82;
        gTasks[taskIdB].data[TDB_0] += 1;
        return;

    case 4:
        if (gTasks[taskIdB].data[TDB_3] != 0)
        {
            gTasks[taskIdB].data[TDB_3] -= 1;
            return;
        }

        if (sub_8144454((u8)gTasks[taskIdB].data[TDB_CURRENT_PAGE], (u8)gTasks[taskIdB].data[TDB_TASK_A_ID]))
        {
            gTasks[taskIdB].data[TDB_0] += 1;
            return;
        }

        gTasks[taskIdB].data[TDB_0] += 1;

        if (gTasks[gTasks[taskIdB].data[TDB_TASK_A_ID]].data[TDA_13] == 1)
        {
            BeginNormalPaletteFade(0x300, 0, 0, 16, COLOR_LIGHT_GREEN);
        }
        else
        {
            BeginNormalPaletteFade(0x300, 0, 0, 16, COLOR_DARK_GREEN);
        }

        return;

    case 5:
        if (gPaletteFade.active)
        {
            return;
        }

        MenuZeroFillWindowRect(0, 9, 29, 19);
        gTasks[taskIdB].data[TDB_0] = 2;
        return;

    case 10:
        gTasks[gTasks[taskIdB].data[TDB_TASK_A_ID]].data[TDA_4] = 1;
        DestroyTask(taskIdB);
        return;
    }
}

#define LAST_PAGE (PAGE_TEXT_EDITOR)

static u8 sub_8144454(u8 page, u8 taskIdA)
{
    // Starts with bike + ocean + morning

    if (page == PAGE_PROGRAMMERS_1)
    {
        // Grass patch
        gTasks[taskIdA].data[TDA_11] = 2;
    }

    if (page == PAGE_POKEMON_GRAHPIC_DESIGNERS_3)
    {
        // Bike + ocean + sunset
        gTasks[taskIdA].data[TDA_7] = 1;
        gTasks[taskIdA].data[TDA_11] = 1;
    }

    if (page == PAGE_GAME_DESIGNERS_2)
    {
        // Grass patch
        gTasks[taskIdA].data[TDA_11] = 2;
    }

    if (page == PAGE_MAP_DATA_DESIGNERS)
    {
        // Bike + forest + sunset
        gTasks[taskIdA].data[TDA_7] = 2;
        gTasks[taskIdA].data[TDA_11] = 1;
    }

    if (page == PAGE_SPECIAL_THANKS_1)
    {
        // Grass patch
        gTasks[taskIdA].data[TDA_11] = 2;
    }

    if (page == PAGE_TASK_MANAGERS)
    {
        // Bike + forest + sunset
        gTasks[taskIdA].data[TDA_7] = 3;
        gTasks[taskIdA].data[TDA_11] = 1;
    }

    if (page == PAGE_TRANSLATION_COORDINATOR)
    {
        // Grass patch
        gTasks[taskIdA].data[TDA_11] = 2;
    }

    if (page == LAST_PAGE)
    {
        // Bike + town + night
        gTasks[taskIdA].data[TDA_7] = 4;
        gTasks[taskIdA].data[TDA_11] = 1;
    }

    if (gTasks[taskIdA].data[TDA_11] != 0)
    {
        // Returns true if changed?
        return TRUE;
    }

    return FALSE;
}

static void task_d_8144514(u8 taskIdD)
{
    struct Unk201C000 *r6 = &ewram1c000;
    u8 r2;

    switch (gTasks[taskIdD].data[TDD_STATE])
    {
    case 0:
        break;
    case 1:
        if (r6->unk8A == 0 && gTasks[gTasks[taskIdD].data[TDD_TASK_A_ID]].data[TDA_14] == 0)
            break;
        gTasks[gTasks[taskIdD].data[TDD_TASK_A_ID]].data[TDA_14] = 0;
        gTasks[taskIdD].data[TDD_STATE]++;
        break;
    case 2:
        if (r6->unk88 == POKEMON_TILE_COUNT || gTasks[gTasks[taskIdD].data[TDD_TASK_A_ID]].func != task_a_8143B68)
            break;
        r2 = sub_81456B4(r6->unk0[r6->unk8C], gUnknown_0840CA00[r6->unk8A][0], gUnknown_0840CA00[r6->unk8A][1], r6->unk8A);
        if (r6->unk8C < r6->unk8E - 1)
        {
            r6->unk8C++;
            gSprites[r2].data3 = 50;
        }
        else
        {
            r6->unk8C = 0;
            gSprites[r2].data3 = 512;
        }
        r6->unk88++;
        if (r6->unk8A == 2)
            r6->unk8A = 0;
        else
            r6->unk8A++;
        gTasks[taskIdD].data[TDD_3] = 50;
        gTasks[taskIdD].data[TDD_STATE]++;
        break;
    case 3:
        if (gTasks[taskIdD].data[TDD_3] != 0)
            gTasks[taskIdD].data[TDD_3]--;
        else
            gTasks[taskIdD].data[TDD_STATE] = 1;
        break;
    }
}

void task_c_8144664(u8 taskIdC)
{
    switch (gTasks[taskIdC].data[0])
    {
    case 0:
        gUnknown_0203935A = Sin((gTasks[taskIdC].data[5] >> 1) & 0x7F, 12);
        gTasks[taskIdC].data[5]++;
        break;
    case 1:
        if (gUnknown_0203935A != 0)
        {
            gUnknown_0203935A = Sin((gTasks[taskIdC].data[5] >> 1) & 0x7F, 12);
            gTasks[taskIdC].data[5]++;
        }
        else
        {
            gSprites[gTasks[taskIdC].data[2]].data0 = 2;
            gTasks[taskIdC].data[5] = 0;
            gTasks[taskIdC].data[0]++;
        }
        break;
    case 2:
        if (gTasks[taskIdC].data[5] < 64)
        {
            gTasks[taskIdC].data[5]++;
            gUnknown_0203935A = Sin(gTasks[taskIdC].data[5] & 0x7F, 20);
        }
        else
        {
            gTasks[taskIdC].data[0]++;
        }
        break;
    case 3:
        gSprites[gTasks[taskIdC].data[2]].data0 = 3;
        gSprites[gTasks[taskIdC].data[3]].data0 = 1;
        gTasks[taskIdC].data[4] = 120;
        gTasks[taskIdC].data[0]++;
        break;
    case 4:
        if (gTasks[taskIdC].data[4] != 0)
        {
            gTasks[taskIdC].data[4]--;
        }
        else
        {
            gTasks[taskIdC].data[5] = 64;
            gTasks[taskIdC].data[0]++;
        }
        break;
    case 5:
        if (gTasks[taskIdC].data[5] > 0)
        {
            gTasks[taskIdC].data[5]--;
            gUnknown_0203935A = Sin(gTasks[taskIdC].data[5] & 0x7F, 20);
        }
        else
        {
            gSprites[gTasks[taskIdC].data[2]].data0 = 1;
            gTasks[taskIdC].data[0]++;
        }
        break;
    case 6:
        gTasks[taskIdC].data[0] = 50;
        break;
    case 10:
        gSprites[gTasks[taskIdC].data[3]].data0 = 2;
        gTasks[taskIdC].data[0] = 50;
        break;
    case 20:
        gSprites[gTasks[taskIdC].data[2]].data0 = 4;
        gTasks[taskIdC].data[0] = 50;
        break;
    case 30:
        gSprites[gTasks[taskIdC].data[2]].data0 = 5;
        gSprites[gTasks[taskIdC].data[3]].data0 = 3;
        gTasks[taskIdC].data[0] = 50;
        break;
    case 50:
        gTasks[taskIdC].data[0] = 0;
        break;
    }
}

#define UNK_DEF_1F3 (499)

void task_e_8144934(u8 taskIdE)
{
    s16 taskIdC;

    switch (gTasks[taskIdE].data[TDE_0])
    {
    default:
    case 0:
        if (gTasks[taskIdE].data[TDE_1] != 0x7FFF)
        {

            if (gTasks[gTasks[gTasks[taskIdE].data[TDE_TASK_A_ID]].data[TDA_TASK_B_ID]].data[TDB_CURRENT_PAGE] == PAGE_ART_DIRECTOR)
            {
                gTasks[gTasks[gTasks[taskIdE].data[TDE_TASK_A_ID]].data[TDA_TASK_C_ID]].data[TDC_0] = 20;
                gTasks[taskIdE].data[TDE_1] = 0x7FFF;
            }
        }

        sub_8149020(0);
        break;

    case 1:
        sub_8149020(0);
        break;

    case 2:
        if (gTasks[taskIdE].data[TDE_1] != 0x7FFF)
        {
            taskIdC = gTasks[gTasks[taskIdE].data[TDE_TASK_A_ID]].data[TDA_TASK_C_ID];

            // Floor to multiple of 128
            if ((gTasks[taskIdC].data[TDC_5] & -128) == 640)
            {
                gTasks[taskIdC].data[TDC_0] = 1;
                gTasks[taskIdE].data[TDE_1] = 0x7FFF;
            }
        }
        sub_8149020(1);
        break;

    case 3:
        if (gTasks[taskIdE].data[TDE_1] != 0x7FFF)
        {

            if (gTasks[taskIdE].data[TDE_1] == UNK_DEF_1F3)
            {
                gTasks[gTasks[gTasks[taskIdE].data[TDE_TASK_A_ID]].data[TDA_TASK_C_ID]].data[TDC_0] = 10;
                gTasks[taskIdE].data[TDE_1] = 0x7FFF;
            }
            else
            {
                gTasks[taskIdE].data[TDE_1] += 1;
            }
        }

        sub_8149020(1);
        break;

    case 4:
        sub_8149020(2);
        break;
    }
}

#define UNK_DEFINE_45 (0x45)

static void sub_8144A68(u8 data, u8 taskIdA)
{
    switch (data)
    {
    case 0:
        gSprites[gTasks[taskIdA].data[TDA_PLAYER_CYCLIST]].invisible = 0;
        gSprites[gTasks[taskIdA].data[TDA_RIVAL_CYCLIST]].invisible = 0;
        gSprites[gTasks[taskIdA].data[TDA_PLAYER_CYCLIST]].pos1.x = 272;
        gSprites[gTasks[taskIdA].data[TDA_RIVAL_CYCLIST]].pos1.x = 272;
        gSprites[gTasks[taskIdA].data[TDA_PLAYER_CYCLIST]].pos1.y = 46;
        gSprites[gTasks[taskIdA].data[TDA_RIVAL_CYCLIST]].pos1.y = 46;
        gSprites[gTasks[taskIdA].data[TDA_PLAYER_CYCLIST]].data0 = 0;
        gSprites[gTasks[taskIdA].data[TDA_RIVAL_CYCLIST]].data0 = 0;
        gTasks[taskIdA].data[TDA_0] = sub_8148EC0(0, 0x2000, 0x20, 8);
        break;

    case 1:
        gSprites[gTasks[taskIdA].data[TDA_PLAYER_CYCLIST]].invisible = 0;
        gSprites[gTasks[taskIdA].data[TDA_RIVAL_CYCLIST]].invisible = 0;
        gSprites[gTasks[taskIdA].data[TDA_PLAYER_CYCLIST]].pos1.x = 120;
        gSprites[gTasks[taskIdA].data[TDA_RIVAL_CYCLIST]].pos1.x = 272;
        gSprites[gTasks[taskIdA].data[TDA_PLAYER_CYCLIST]].pos1.y = 46;
        gSprites[gTasks[taskIdA].data[TDA_RIVAL_CYCLIST]].pos1.y = 46;
        gSprites[gTasks[taskIdA].data[TDA_PLAYER_CYCLIST]].data0 = 0;
        gSprites[gTasks[taskIdA].data[TDA_RIVAL_CYCLIST]].data0 = 0;
        gTasks[taskIdA].data[TDA_0] = sub_8148EC0(0, 0x2000, 0x20, 8);
        break;

    case 2:
        gSprites[gTasks[taskIdA].data[TDA_PLAYER_CYCLIST]].invisible = 0;
        gSprites[gTasks[taskIdA].data[TDA_RIVAL_CYCLIST]].invisible = 0;
        gSprites[gTasks[taskIdA].data[TDA_PLAYER_CYCLIST]].pos1.x = 120;
        gSprites[gTasks[taskIdA].data[TDA_RIVAL_CYCLIST]].pos1.x = 272;
        gSprites[gTasks[taskIdA].data[TDA_PLAYER_CYCLIST]].pos1.y = 46;
        gSprites[gTasks[taskIdA].data[TDA_RIVAL_CYCLIST]].pos1.y = 46;
        gSprites[gTasks[taskIdA].data[TDA_PLAYER_CYCLIST]].data0 = 0;
        gSprites[gTasks[taskIdA].data[TDA_RIVAL_CYCLIST]].data0 = 0;
        gTasks[taskIdA].data[TDA_0] = sub_8148EC0(1, 0x2000, 0x200, 8);
        break;

    case 3:
        gSprites[gTasks[taskIdA].data[TDA_PLAYER_CYCLIST]].invisible = 0;
        gSprites[gTasks[taskIdA].data[TDA_RIVAL_CYCLIST]].invisible = 0;
        gSprites[gTasks[taskIdA].data[TDA_PLAYER_CYCLIST]].pos1.x = 120;
        gSprites[gTasks[taskIdA].data[TDA_RIVAL_CYCLIST]].pos1.x = -32;
        gSprites[gTasks[taskIdA].data[TDA_PLAYER_CYCLIST]].pos1.y = 46;
        gSprites[gTasks[taskIdA].data[TDA_RIVAL_CYCLIST]].pos1.y = 46;
        gSprites[gTasks[taskIdA].data[TDA_PLAYER_CYCLIST]].data0 = 0;
        gSprites[gTasks[taskIdA].data[TDA_RIVAL_CYCLIST]].data0 = 0;
        gTasks[taskIdA].data[TDA_0] = sub_8148EC0(1, 0x2000, 0x200, 8);
        break;

    case 4:
        gSprites[gTasks[taskIdA].data[TDA_PLAYER_CYCLIST]].invisible = 0;
        gSprites[gTasks[taskIdA].data[TDA_RIVAL_CYCLIST]].invisible = 0;
        gSprites[gTasks[taskIdA].data[TDA_PLAYER_CYCLIST]].pos1.x = 88;
        gSprites[gTasks[taskIdA].data[TDA_RIVAL_CYCLIST]].pos1.x = 152;
        gSprites[gTasks[taskIdA].data[TDA_PLAYER_CYCLIST]].pos1.y = 46;
        gSprites[gTasks[taskIdA].data[TDA_RIVAL_CYCLIST]].pos1.y = 46;
        gSprites[gTasks[taskIdA].data[TDA_PLAYER_CYCLIST]].data0 = 0;
        gSprites[gTasks[taskIdA].data[TDA_RIVAL_CYCLIST]].data0 = 0;
        gTasks[taskIdA].data[TDA_0] = sub_8148EC0(2, 0x2000, 0x200, 8);
        break;
    }

    gTasks[taskIdA].data[TDA_TASK_E_ID] = CreateTask(task_e_8144934, 0);
    gTasks[gTasks[taskIdA].data[TDA_TASK_E_ID]].data[TDE_0] = data;
    gTasks[gTasks[taskIdA].data[TDA_TASK_E_ID]].data[TDE_1] = 0;
    gTasks[gTasks[taskIdA].data[TDA_TASK_E_ID]].data[TDE_TASK_A_ID] = taskIdA;

    gTasks[taskIdA].data[TDA_TASK_C_ID] = CreateTask(task_c_8144664, 0);
    gTasks[gTasks[taskIdA].data[TDA_TASK_C_ID]].data[TDC_0] = 0;
    gTasks[gTasks[taskIdA].data[TDA_TASK_C_ID]].data[TDC_1] = taskIdA;
    gTasks[gTasks[taskIdA].data[TDA_TASK_C_ID]].data[TDC_2] = gTasks[taskIdA].data[TDA_PLAYER_CYCLIST];
    gTasks[gTasks[taskIdA].data[TDA_TASK_C_ID]].data[TDC_3] = gTasks[taskIdA].data[TDA_RIVAL_CYCLIST];
    gTasks[gTasks[taskIdA].data[TDA_TASK_C_ID]].data[TDC_4] = 0;

    if (data == 2)
    {
        gTasks[gTasks[taskIdA].data[TDA_TASK_C_ID]].data[TDC_5] = UNK_DEFINE_45;
    }
}

static bool8 sub_8144ECC(u8 data, u8 taskIdA)
{
    u8 spriteId;

    switch (gMain.state)
    {
    default:
    case 0:
        REG_DISPCNT = 0;
        REG_BG3HOFS = 8;
        REG_BG3VOFS = 0;
        REG_BG2HOFS = 0;
        REG_BG2VOFS = 0;
        REG_BG1HOFS = 0;
        REG_BG1VOFS = 0;
        REG_BLDCNT = 0;
        REG_BLDALPHA = 0;
        ResetSpriteData();
        FreeAllSpritePalettes();
        gMain.state = 1;
        break;

    case 1:
        gUnknown_02039358 = 34;
        gUnknown_0203935A = 0;
        sub_8148CB0(data);
        gMain.state += 1;
        break;

    case 2:
        if (gSaveBlock2.playerGender == MALE)
        {
            LoadCompressedObjectPic(&gIntro2BrendanSpriteSheet);
            LoadCompressedObjectPic(&gUnknown_08416E34);
            LoadCompressedObjectPic(&gIntro2BicycleSpriteSheet);
            LoadSpritePalettes(gIntro2SpritePalettes);

            spriteId = intro_create_brendan_sprite(120, 46);
            gTasks[taskIdA].data[TDA_PLAYER_CYCLIST] = spriteId;
            gSprites[spriteId].callback = spritecb_player_8145378;
            gSprites[spriteId].anims = gSpriteAnimTable_0840CA54;

            spriteId = intro_create_may_sprite(272, 46);
            gTasks[taskIdA].data[TDA_RIVAL_CYCLIST] = spriteId;
            gSprites[spriteId].callback = spritecb_rival_8145420;
            gSprites[spriteId].anims = gSpriteAnimTable_0840CA94;
        }
        else
        {
            LoadCompressedObjectPic(&gIntro2MaySpriteSheet);
            LoadCompressedObjectPic(&gUnknown_08416E24);
            LoadCompressedObjectPic(&gIntro2BicycleSpriteSheet);
            LoadSpritePalettes(gIntro2SpritePalettes);

            spriteId = intro_create_may_sprite(120, 46);
            gTasks[taskIdA].data[TDA_PLAYER_CYCLIST] = spriteId;
            gSprites[spriteId].callback = spritecb_player_8145378;
            gSprites[spriteId].anims = gSpriteAnimTable_0840CA54;

            spriteId = intro_create_brendan_sprite(272, 46);
            gTasks[taskIdA].data[TDA_RIVAL_CYCLIST] = spriteId;
            gSprites[spriteId].callback = spritecb_rival_8145420;
            gSprites[spriteId].anims = gSpriteAnimTable_0840CA94;
        };

        gMain.state += 1;
        break;

    case 3:
        sub_8144A68(data, taskIdA);
        sub_8148E90(data);
        gMain.state = 0;
        return TRUE;
    }

    return FALSE;
}

static void sub_81450AC(u8 taskIdA)
{
    if (gTasks[taskIdA].data[TDA_0] != 0)
    {
        DestroyTask(gTasks[taskIdA].data[TDA_0]);
        gTasks[taskIdA].data[TDA_0] = 0;
    }

    if (gTasks[taskIdA].data[TDA_TASK_C_ID] != 0)
    {
        DestroyTask(gTasks[taskIdA].data[TDA_TASK_C_ID]);
        gTasks[taskIdA].data[TDA_TASK_C_ID] = 0;
    }

    if (gTasks[taskIdA].data[TDA_TASK_E_ID] != 0)
    {
        DestroyTask(gTasks[taskIdA].data[TDA_TASK_E_ID]);
        gTasks[taskIdA].data[TDA_TASK_E_ID] = 0;
    }

    if (gTasks[taskIdA].data[TDA_TASK_D_ID] != 0)
    {
        DestroyTask(gTasks[taskIdA].data[TDA_TASK_D_ID]);
        gTasks[taskIdA].data[TDA_TASK_D_ID] = 0;
    }

    gUnknown_0203935C = 1;
}

#ifdef NONMATCHING
// Sets up the tilemap for 'misc/end_copyright.png'
void sub_8145128(u16 arg0, u16 arg1, u16 arg2) {
    u16 i;
    u16 baseTile;
    u16 offset0, offset1, offset2, offset3, offset4;

    LZ77UnCompVram(gCreditsCopyrightEnd_Gfx, (void *) (VRAM + arg0));
    LoadPalette(gIntroCopyright_Pal, arg2, sizeof(gIntroCopyright_Pal));

    baseTile = (arg2 / 16) << 12;

    offset0 = baseTile + 1;
    for (i = 0; i < 32 * 32; i++)
    {
        ((u16 *) (VRAM + arg1))[i] = baseTile + 1;
    }

    offset1 = offset0 + 1;
    offset2 = offset1 + 21;
    offset3 = offset2 + 20;
    offset4 = offset3 + 23;

    for (i = 0; i < 21; i++)
    {
        ((u16 *) (VRAM + arg1))[7 * 32 + 4 + i] = offset1 + i;
    }

    for (i = 0; i < 20; i++)
    {
        ((u16 *) (VRAM + arg1))[9 * 32 + 4 + i] = offset2 + i;
    }

    for (i = 0; i < 23; i++)
    {
        ((u16 *) (VRAM + arg1))[11 * 32 + 4 + i] = offset3 + i;
    }

    for (i = 0; i < 12; i++)
    {
        ((u16 *) (VRAM + arg1))[13 * 32 + 4 + i] = offset4 + i;
    }
}
#else
__attribute__((naked))
void sub_8145128(u16 arg0, u16 arg1, u16 arg2)
{
    asm(".syntax unified\n\
    push {r4-r7,lr}\n\
    adds r3, r0, 0\n\
    adds r4, r2, 0\n\
    lsls r3, 16\n\
    lsrs r3, 16\n\
    lsls r1, 16\n\
    lsrs r7, r1, 16\n\
    lsls r4, 16\n\
    lsrs r5, r4, 16\n\
    ldr r0, _081451EC @ =gCreditsCopyrightEnd_Gfx\n\
    movs r6, 0xC0\n\
    lsls r6, 19\n\
    adds r3, r6\n\
    adds r1, r3, 0\n\
    bl LZ77UnCompVram\n\
    ldr r0, _081451F0 @ =gIntroCopyright_Pal\n\
    adds r1, r5, 0\n\
    movs r2, 0x20\n\
    bl LoadPalette\n\
    lsrs r4, 20\n\
    lsls r4, 28\n\
    lsrs r4, 16\n\
    movs r2, 0\n\
    adds r1, r4, 0x1\n\
    ldr r3, _081451F4 @ =0x000003ff\n\
_0814515E:\n\
    lsls r0, r2, 1\n\
    adds r0, r7\n\
    adds r0, r6\n\
    strh r1, [r0]\n\
    adds r0, r2, 0x1\n\
    lsls r0, 16\n\
    lsrs r2, r0, 16\n\
    cmp r2, r3\n\
    bls _0814515E\n\
    movs r2, 0\n\
    adds r0, r4, 0x2\n\
    adds r6, r4, 0\n\
    adds r6, 0x17\n\
    movs r1, 0x2B\n\
    adds r1, r4\n\
    mov r12, r1\n\
    adds r4, 0x42\n\
    ldr r5, _081451F8 @ =0x060001c8\n\
    adds r3, r0, 0\n\
_08145184:\n\
    lsls r0, r2, 1\n\
    adds r0, r7\n\
    adds r0, r5\n\
    adds r1, r2, r3\n\
    strh r1, [r0]\n\
    adds r0, r2, 0x1\n\
    lsls r0, 16\n\
    lsrs r2, r0, 16\n\
    cmp r2, 0x14\n\
    bls _08145184\n\
    movs r2, 0\n\
    ldr r5, _081451FC @ =0x06000248\n\
    adds r3, r6, 0\n\
_0814519E:\n\
    lsls r0, r2, 1\n\
    adds r0, r7\n\
    adds r0, r5\n\
    adds r1, r2, r3\n\
    strh r1, [r0]\n\
    adds r0, r2, 0x1\n\
    lsls r0, 16\n\
    lsrs r2, r0, 16\n\
    cmp r2, 0x13\n\
    bls _0814519E\n\
    movs r2, 0\n\
    ldr r5, _08145200 @ =0x060002c8\n\
    mov r3, r12\n\
_081451B8:\n\
    lsls r0, r2, 1\n\
    adds r0, r7\n\
    adds r0, r5\n\
    adds r1, r2, r3\n\
    strh r1, [r0]\n\
    adds r0, r2, 0x1\n\
    lsls r0, 16\n\
    lsrs r2, r0, 16\n\
    cmp r2, 0x16\n\
    bls _081451B8\n\
    movs r2, 0\n\
    ldr r3, _08145204 @ =0x06000348\n\
_081451D0:\n\
    lsls r0, r2, 1\n\
    adds r0, r7\n\
    adds r0, r3\n\
    adds r1, r2, r4\n\
    strh r1, [r0]\n\
    adds r0, r2, 0x1\n\
    lsls r0, 16\n\
    lsrs r2, r0, 16\n\
    cmp r2, 0xB\n\
    bls _081451D0\n\
    pop {r4-r7}\n\
    pop {r0}\n\
    bx r0\n\
    .align 2, 0\n\
_081451EC: .4byte gCreditsCopyrightEnd_Gfx\n\
_081451F0: .4byte gIntroCopyright_Pal\n\
_081451F4: .4byte 0x000003ff\n\
_081451F8: .4byte 0x060001c8\n\
_081451FC: .4byte 0x06000248\n\
_08145200: .4byte 0x060002c8\n\
_08145204: .4byte 0x06000348\n\
    .syntax divided\n");
}
#endif

u16 sub_8145208(u8 arg0)
{

    u16 out = (arg0 & 0x3F) + 80;

    if (arg0 == 0xFF)
    {
        return 1;
    }

    if (arg0 & (1 << 7))
    {
        out |= 1 << 11;
    }

    if (arg0 & (1 << 6))
    {
        out |= 1 << 10;
    }

    return out;
}

void sub_814524C(u8 arg0[], u8 baseX, u8 baseY, u16 arg3, u16 palette) {
    u8 y, x;

    const u16 tileOffset = (palette / 16) << 12;

    for (y = 0; y < 5; y++)
    {
        for (x = 0; x < 3; x++)
        {
            ((u16 *) (VRAM + arg3 + (baseY + y) * 64))[baseX + x] = tileOffset + sub_8145208(arg0[y * 3 + x]);
        }
    }
}

static void sub_81452D0(u16 arg0, u16 palette)
{
    u16 pos;
    u16 baseTile = (palette / 16) << 12;

    for (pos = 0; pos < 32 * 32; pos++)
        ((u16 *) (VRAM + arg0))[pos] = baseTile + 1;

    sub_814524C(gUnknown_0840B83C, 3, 7, arg0, palette);
    sub_814524C(gUnknown_0840B84B, 7, 7, arg0, palette);
    sub_814524C(gUnknown_0840B85A, 11, 7, arg0, palette);
    sub_814524C(gUnknown_0840B85A, 16, 7, arg0, palette);
    sub_814524C(gUnknown_0840B869, 20, 7, arg0, palette);
    sub_814524C(gUnknown_0840B878, 24, 7, arg0, palette);
}

static void spritecb_player_8145378(struct Sprite *sprite)
{
    if (gUnknown_0203935C != 0)
    {
        DestroySprite(sprite);
        return;
    }

    switch (sprite->data0)
    {
    case 0:
        StartSpriteAnimIfDifferent(sprite, 0);
        break;

    case 1:
        StartSpriteAnimIfDifferent(sprite, 1);
        if (sprite->pos1.x > -32)
        {
            sprite->pos1.x -= 1;
        }
        break;

    case 2:
        StartSpriteAnimIfDifferent(sprite, 2);
        break;

    case 3:
        StartSpriteAnimIfDifferent(sprite, 3);
        break;

    case 4:
        StartSpriteAnimIfDifferent(sprite, 0);
        if (sprite->pos1.x > 120)
        {
            sprite->pos1.x -= 1;
        }
        break;

    case 5:
        StartSpriteAnimIfDifferent(sprite, 0);
        if (sprite->pos1.x > -32)
        {
            sprite->pos1.x -= 1;
        }
        break;
    }
}

static void spritecb_rival_8145420(struct Sprite *sprite)
{
    if (gUnknown_0203935C != 0)
    {
        DestroySprite(sprite);
        return;
    }

    switch (sprite->data0)
    {
    case 0:
        sprite->pos2.y = 0;
        StartSpriteAnimIfDifferent(sprite, 0);
        break;

    case 1:
        if (sprite->pos1.x > 200)
        {
            StartSpriteAnimIfDifferent(sprite, 1);
        }
        else
        {
            StartSpriteAnimIfDifferent(sprite, 2);
        }

        if (sprite->pos1.x > -32)
        {
            sprite->pos1.x -= 2;
        }

        sprite->pos2.y = -gUnknown_0203935A;
        break;

    case 2:
        sprite->data7 += 1;
        StartSpriteAnimIfDifferent(sprite, 0);

        if ((sprite->data7 & 3) == 0)
        {
            sprite->pos1.x += 1;
        }
        break;

    case 3:
        StartSpriteAnimIfDifferent(sprite, 0);

        if (sprite->pos1.x > -32)
        {
            sprite->pos1.x -= 1;
        }
        break;


    }
}

void spritecb_81454E0(struct Sprite *sprite) {
    if (gUnknown_0203935C)
    {
        DestroySprite(sprite);
        return;
    }

    sprite->data7 += 1;
    switch (sprite->data0)
    {
    case 0:
    default:
        sprite->oam.affineMode = 1;
        sprite->oam.matrixNum = sprite->data1;
        sprite->data2 = 16;
        SetOamMatrix(sprite->data1, 0x10000 / sprite->data2, 0, 0, 0x10000 / sprite->data2);
        sprite->invisible = FALSE;
        sprite->data0 = 1;
        break;

    case 1:
        if (sprite->data2 < 256)
        {
            sprite->data2 += 8;
            SetOamMatrix(sprite->data1, 0x10000 / sprite->data2, 0, 0, 0x10000 / sprite->data2);
        }
        else
        {
            sprite->data0 += 1;
        }
        switch (sprite->data1)
        {
        case 1:
            if ((sprite->data7 & 3) == 0)
            {
                sprite->pos1.y += 1;
            }
            sprite->pos1.x -= 2;
            break;
        case 2:
            break;
        case 3:
            if ((sprite->data7 & 3) == 0)
            {
                sprite->pos1.y += 1;
            }
            sprite->pos1.x += 2;
            break;
        }
        break;

    case 2:
        if (sprite->data3 != 0)
        {
            sprite->data3 -= 1;
        }
        else
        {
            REG_BLDCNT = 0xF40;
            REG_BLDALPHA = 0x10;
            sprite->oam.objMode = 1;
            sprite->data3 = 16;
            sprite->data0 += 1;
        }
        break;

    case 3:
        if (sprite->data3 != 0)
        {
            int data3;
            vu16 *reg;

            sprite->data3 -= 1;

            reg = &REG_BLDALPHA;
            data3 = 16 - sprite->data3;
            *reg = (data3 << 8) + sprite->data3;
        }
        else
        {
            sprite->invisible = TRUE;
            sprite->data0 = 10;
        }
        break;

    case 10:
        REG_BLDCNT = 0;
        REG_BLDALPHA = 0;
        DestroySprite(sprite);
        break;

    }
}

#ifdef NONMATCHING
/*
extern struct SpriteFrameImage *gUnknown_0840B69C[];
extern const union AmimCmd *const gSpriteAnimTable_81E7C64[];
extern struct SpriteTemplate gUnknown_0840B6B8;

void sub_8143648(u16 paletteTag, u8 arg1) {
    gUnknown_02024E8C = gUnknown_0840B6B8;
    gUnknown_02024E8C.paletteTag = paletteTag;
    gUnknown_02024E8C.images = gUnknown_0840B69C[arg1];
    gUnknown_02024E8C.anims = (const union AnimCmd *const *) gSpriteAnimTable_81E7C64;
}
*/

void sub_8143648(u16 paletteTag, u8 arg1);

u8 sub_81456B4(u16 nationalNum, u16 x, u16 y, u16 position)
{
    u32 species;
    u32 personality;
    void *palette;
    u8 spriteId;
    u8 spriteId2;

    // FIXME: For some reason r0 is copied to r6 before.
    species = NationalPokedexNumToSpecies(nationalNum);


    switch (species)
    {
    default:
        personality = 0;
        break;

    case SPECIES_SPINDA:
        personality = gSaveBlock2.pokedex.spindaPersonality;
        break;

    case SPECIES_UNOWN:
        personality = gSaveBlock2.pokedex.unownPersonality;
        break;
    }

    LoadSpecialPokePic(
        &gMonFrontPicTable[species],
        gMonFrontPicCoords[species].x,
        gMonFrontPicCoords[species].y,
        0x2000000,
        gUnknown_0840B5A0[position],
        species,
        personality,
        1
    );

    palette = species_and_otid_get_pal(species, 0, 0xFFFF);
    LoadCompressedPalette(palette, 0x100 + (position * 16), 0x20);
    sub_8143648(position, position);

    spriteId = CreateSprite(&gUnknown_02024E8C, x, y, 0);
    gSprites[spriteId].oam.paletteNum = position;
    gSprites[spriteId].oam.priority = 1;
    gSprites[spriteId].data1 = position + 1;
    gSprites[spriteId].invisible = TRUE;
    gSprites[spriteId].callback = spritecb_81454E0;

    spriteId2 = CreateSprite(&gSpriteTemplate_840CAEC, gSprites[spriteId].pos1.x, gSprites[spriteId].pos1.y, 1);
    gSprites[spriteId2].data0 = spriteId;

    StartSpriteAnimIfDifferent(&gSprites[spriteId2], position);

    return spriteId;
}
#else
__attribute__((naked))
u8 sub_81456B4(u16 nationalNum, u16 x, u16 y, u16 arg3)
{
    asm(".syntax unified\n\
    push {r4-r7,lr}\n\
    mov r7, r10\n\
    mov r6, r9\n\
    mov r5, r8\n\
    push {r5-r7}\n\
    sub sp, 0x14\n\
    lsls r0, 16\n\
    lsrs r6, r0, 16\n\
    lsls r1, 16\n\
    lsrs r1, 16\n\
    mov r10, r1\n\
    lsls r2, 16\n\
    lsrs r2, 16\n\
    str r2, [sp, 0x10]\n\
    lsls r3, 16\n\
    lsrs r3, 16\n\
    mov r9, r3\n\
    adds r0, r6, 0\n\
    bl NationalPokedexNumToSpecies\n\
    adds r6, r0, 0\n\
    cmp r6, 0xC9\n\
    beq _081456F8\n\
    movs r0, 0x9A\n\
    lsls r0, 1\n\
    cmp r6, r0\n\
    beq _081456EE\n\
    movs r7, 0\n\
    b _081456FC\n\
_081456EE:\n\
    ldr r0, _081456F4 @ =gSaveBlock2\n\
    ldr r7, [r0, 0x20]\n\
    b _081456FC\n\
    .align 2, 0\n\
_081456F4: .4byte gSaveBlock2\n\
_081456F8:\n\
    ldr r0, _081457E8 @ =gSaveBlock2\n\
    ldr r7, [r0, 0x1C]\n\
_081456FC:\n\
    lsls r0, r6, 3\n\
    ldr r1, _081457EC @ =gMonFrontPicTable\n\
    adds r0, r1\n\
    ldr r1, _081457F0 @ =gMonFrontPicCoords\n\
    lsls r2, r6, 2\n\
    adds r2, r1\n\
    ldrb r1, [r2]\n\
    ldrb r2, [r2, 0x1]\n\
    movs r3, 0x80\n\
    lsls r3, 18\n\
    ldr r4, _081457F4 @ =gUnknown_0840B5A0\n\
    mov r8, r4\n\
    mov r5, r9\n\
    lsls r4, r5, 2\n\
    add r4, r8\n\
    ldr r4, [r4]\n\
    str r4, [sp]\n\
    str r6, [sp, 0x4]\n\
    str r7, [sp, 0x8]\n\
    movs r4, 0x1\n\
    str r4, [sp, 0xC]\n\
    bl LoadSpecialPokePic\n\
    ldr r2, _081457F8 @ =0x0000ffff\n\
    adds r0, r6, 0\n\
    movs r1, 0\n\
    bl species_and_otid_get_pal\n\
    lsls r5, 4\n\
    mov r8, r5\n\
    movs r1, 0x80\n\
    lsls r1, 1\n\
    add r1, r8\n\
    lsls r1, 16\n\
    lsrs r1, 16\n\
    movs r2, 0x20\n\
    bl LoadCompressedPalette\n\
    mov r7, r9\n\
    lsls r6, r7, 24\n\
    lsrs r6, 24\n\
    mov r0, r9\n\
    adds r1, r6, 0\n\
    bl sub_8143648\n\
    ldr r0, _081457FC @ =gUnknown_02024E8C\n\
    mov r2, r10\n\
    lsls r1, r2, 16\n\
    asrs r1, 16\n\
    ldr r3, [sp, 0x10]\n\
    lsls r2, r3, 16\n\
    asrs r2, 16\n\
    movs r3, 0\n\
    bl CreateSprite\n\
    adds r4, r0, 0\n\
    lsls r4, 24\n\
    lsrs r4, 24\n\
    ldr r5, _08145800 @ =gSprites\n\
    lsls r2, r4, 4\n\
    adds r2, r4\n\
    lsls r2, 2\n\
    adds r3, r2, r5\n\
    ldrb r1, [r3, 0x5]\n\
    movs r0, 0xF\n\
    ands r0, r1\n\
    mov r7, r8\n\
    orrs r0, r7\n\
    movs r1, 0xD\n\
    negs r1, r1\n\
    ands r0, r1\n\
    movs r1, 0x4\n\
    orrs r0, r1\n\
    strb r0, [r3, 0x5]\n\
    mov r0, r9\n\
    adds r0, 0x1\n\
    strh r0, [r3, 0x30]\n\
    movs r0, 0x3E\n\
    adds r0, r3\n\
    mov r8, r0\n\
    ldrb r0, [r0]\n\
    orrs r0, r1\n\
    mov r1, r8\n\
    strb r0, [r1]\n\
    adds r0, r5, 0\n\
    adds r0, 0x1C\n\
    adds r2, r0\n\
    ldr r0, _08145804 @ =spritecb_81454E0\n\
    str r0, [r2]\n\
    ldr r0, _08145808 @ =gSpriteTemplate_840CAEC\n\
    movs r2, 0x20\n\
    ldrsh r1, [r3, r2]\n\
    movs r7, 0x22\n\
    ldrsh r2, [r3, r7]\n\
    movs r3, 0x1\n\
    bl CreateSprite\n\
    adds r1, r0, 0\n\
    lsls r1, 24\n\
    lsrs r1, 24\n\
    lsls r0, r1, 4\n\
    adds r0, r1\n\
    lsls r0, 2\n\
    adds r0, r5\n\
    strh r4, [r0, 0x2E]\n\
    adds r1, r6, 0\n\
    bl StartSpriteAnimIfDifferent\n\
    adds r0, r4, 0\n\
    add sp, 0x14\n\
    pop {r3-r5}\n\
    mov r8, r3\n\
    mov r9, r4\n\
    mov r10, r5\n\
    pop {r4-r7}\n\
    pop {r1}\n\
    bx r1\n\
    .align 2, 0\n\
_081457E8: .4byte gSaveBlock2\n\
_081457EC: .4byte gMonFrontPicTable\n\
_081457F0: .4byte gMonFrontPicCoords\n\
_081457F4: .4byte gUnknown_0840B5A0\n\
_081457F8: .4byte 0x0000ffff\n\
_081457FC: .4byte gUnknown_02024E8C\n\
_08145800: .4byte gSprites\n\
_08145804: .4byte spritecb_81454E0\n\
_08145808: .4byte gSpriteTemplate_840CAEC\n\
    .syntax divided\n");
}
#endif

void spritecb_814580C(struct Sprite *sprite)
{
    if (gSprites[sprite->data0].data0 == 10 || gUnknown_0203935C)
    {
        DestroySprite(sprite);
        return;
    }

    sprite->invisible = gSprites[sprite->data0].invisible;
    sprite->oam.objMode = gSprites[sprite->data0].oam.objMode;
    sprite->oam.affineMode = gSprites[sprite->data0].oam.affineMode;
    sprite->oam.matrixNum = gSprites[sprite->data0].oam.matrixNum;
    sprite->pos1.x = gSprites[sprite->data0].pos1.x;
    sprite->pos1.y = gSprites[sprite->data0].pos1.y;
}

#ifdef NONMATCHING
void sub_81458DC(void) {
    u16 dexNum, seenTypesCount, count, i2;

    struct Unk201C000 *unk201C000 = &ewram1c000;

    const u16 starter = SpeciesToNationalPokedexNum(GetStarterPokemon(VarGet(VAR_FIRST_POKE)));

    dexNum = 1;
    seenTypesCount = 0;
    for (; dexNum < 386; dexNum++)
    {
        if (sub_8090D90(dexNum, 1))
        {
            unk201C000->unk90[seenTypesCount] = dexNum;
            seenTypesCount += 1;
        }
    }

    count = seenTypesCount;
    while (count < 386)
    {
        unk201C000->unk90[count] = 0;
        count += 1;
    }

    unk201C000->unk394 = seenTypesCount;
    if (unk201C000->unk394 < POKEMON_TILE_COUNT)
    {
        unk201C000->unk8E = unk201C000->unk394;
    }
    else
    {
        unk201C000->unk8E = POKEMON_TILE_COUNT;
    }

    for (i2 = 0; i2 < POKEMON_TILE_COUNT;)
    {
        const u16 r2 = Random() % unk201C000->unk394;
        unk201C000->unk0[i2] = unk201C000->unk90[r2];
        i2 += 1;

        unk201C000->unk90[r2] = 0;
        unk201C000->unk394 -= 1;

        if (r2 != unk201C000->unk394)
        {
            unk201C000->unk90[r2] = unk201C000->unk90[unk201C000->unk394];
            unk201C000->unk90[unk201C000->unk394] = 0;
        }

        if (unk201C000->unk394 == 0)
        {
            break;
        }
    }

    if (unk201C000->unk8E < POKEMON_TILE_COUNT)
    {
        u16 i;
        u16 page;
        for (i = unk201C000->unk8E; i < POKEMON_TILE_COUNT; i++)
        {
            unk201C000->unk0[i] = unk201C000->unk0[page];
            page += 1;

            if (page == unk201C000->unk8E)
            {
                page = 0;
            }
        }
    }
    else
    {
        u16 starterIndex;
        for (starterIndex = 0; starterIndex < POKEMON_TILE_COUNT; starterIndex++)
        {
            if (unk201C000->unk0[starterIndex] == starter)
            {
                break;
            }
        }

        if (starterIndex < unk201C000->unk8E)
        {
            unk201C000->unk0[starterIndex] = unk201C000->unk0[POKEMON_TILE_COUNT - 1];
        }
    }

    unk201C000->unk0[POKEMON_TILE_COUNT - 1] = starter;
    unk201C000->unk8E = POKEMON_TILE_COUNT;
}
#else
__attribute__((naked))
void sub_81458DC(void)
{
    asm(".syntax unified\n\
    push {r4-r7,lr}\n\
    mov r7, r10\n\
    mov r6, r9\n\
    mov r5, r8\n\
    push {r5-r7}\n\
    sub sp, 0x4\n\
    ldr r7, _0814597C @ =0x0201c000\n\
    ldr r0, _08145980 @ =0x00004023\n\
    bl VarGet\n\
    lsls r0, 16\n\
    lsrs r0, 16\n\
    bl GetStarterPokemon\n\
    lsls r0, 16\n\
    lsrs r0, 16\n\
    bl SpeciesToNationalPokedexNum\n\
    lsls r0, 16\n\
    lsrs r0, 16\n\
    mov r10, r0\n\
    movs r4, 0x1\n\
    movs r5, 0\n\
    ldr r0, _08145984 @ =0x00000181\n\
    mov r8, r0\n\
_0814590E:\n\
    adds r0, r4, 0\n\
    movs r1, 0x1\n\
    bl sub_8090D90\n\
    lsls r0, 24\n\
    adds r6, r7, 0\n\
    adds r6, 0x90\n\
    cmp r0, 0\n\
    beq _0814592C\n\
    lsls r0, r5, 1\n\
    adds r0, r6, r0\n\
    strh r4, [r0]\n\
    adds r0, r5, 0x1\n\
    lsls r0, 16\n\
    lsrs r5, r0, 16\n\
_0814592C:\n\
    adds r0, r4, 0x1\n\
    lsls r0, 16\n\
    lsrs r4, r0, 16\n\
    cmp r4, r8\n\
    bls _0814590E\n\
    adds r4, r5, 0\n\
    ldr r0, _08145984 @ =0x00000181\n\
    lsls r1, r4, 16\n\
    mov r9, r1\n\
    movs r2, 0x8E\n\
    adds r2, r7\n\
    mov r8, r2\n\
    adds r1, r7, 0\n\
    adds r1, 0x86\n\
    str r1, [sp]\n\
    cmp r4, r0\n\
    bhi _08145964\n\
    adds r1, r6, 0\n\
    movs r3, 0\n\
    adds r2, r0, 0\n\
_08145954:\n\
    lsls r0, r4, 1\n\
    adds r0, r1, r0\n\
    strh r3, [r0]\n\
    adds r0, r4, 0x1\n\
    lsls r0, 16\n\
    lsrs r4, r0, 16\n\
    cmp r4, r2\n\
    bls _08145954\n\
_08145964:\n\
    movs r2, 0xE5\n\
    lsls r2, 2\n\
    adds r0, r7, r2\n\
    strh r5, [r0]\n\
    mov r1, r9\n\
    lsrs r0, r1, 16\n\
    cmp r0, 0x43\n\
    bhi _08145988\n\
    mov r2, r8\n\
    strh r5, [r2]\n\
    b _0814598E\n\
    .align 2, 0\n\
_0814597C: .4byte 0x0201c000\n\
_08145980: .4byte 0x00004023\n\
_08145984: .4byte 0x00000181\n\
_08145988:\n\
    movs r0, 0x44\n\
    mov r1, r8\n\
    strh r0, [r1]\n\
_0814598E:\n\
    movs r5, 0\n\
    movs r2, 0xE5\n\
    lsls r2, 2\n\
    adds r4, r7, r2\n\
    mov r9, r5\n\
    b _0814599E\n\
_0814599A:\n\
    cmp r5, 0x43\n\
    bhi _081459EE\n\
_0814599E:\n\
    bl Random\n\
    lsls r0, 16\n\
    lsrs r0, 16\n\
    ldrh r1, [r4]\n\
    bl __umodsi3\n\
    lsls r0, 16\n\
    lsrs r2, r0, 16\n\
    lsls r1, r5, 1\n\
    adds r1, r7, r1\n\
    lsls r0, r2, 1\n\
    adds r3, r6, r0\n\
    ldrh r0, [r3]\n\
    strh r0, [r1]\n\
    adds r0, r5, 0x1\n\
    lsls r0, 16\n\
    lsrs r5, r0, 16\n\
    mov r0, r9\n\
    strh r0, [r3]\n\
    ldrh r0, [r4]\n\
    subs r0, 0x1\n\
    strh r0, [r4]\n\
    lsls r0, 16\n\
    lsrs r0, 16\n\
    cmp r2, r0\n\
    beq _081459E8\n\
    ldrh r0, [r4]\n\
    lsls r0, 1\n\
    adds r0, r6, r0\n\
    ldrh r0, [r0]\n\
    strh r0, [r3]\n\
    ldrh r0, [r4]\n\
    lsls r0, 1\n\
    adds r0, r6, r0\n\
    mov r1, r9\n\
    strh r1, [r0]\n\
_081459E8:\n\
    ldrh r0, [r4]\n\
    cmp r0, 0\n\
    bne _0814599A\n\
_081459EE:\n\
    mov r2, r8\n\
    ldrh r0, [r2]\n\
    cmp r0, 0x43\n\
    bhi _08145A26\n\
    adds r5, r0, 0\n\
    movs r2, 0\n\
    cmp r5, 0x43\n\
    bhi _08145A5C\n\
    mov r3, r8\n\
_08145A00:\n\
    lsls r1, r5, 1\n\
    adds r1, r7, r1\n\
    lsls r0, r2, 1\n\
    adds r0, r7, r0\n\
    ldrh r0, [r0]\n\
    strh r0, [r1]\n\
    adds r0, r2, 0x1\n\
    lsls r0, 16\n\
    lsrs r2, r0, 16\n\
    ldrh r0, [r3]\n\
    cmp r2, r0\n\
    bne _08145A1A\n\
    movs r2, 0\n\
_08145A1A:\n\
    adds r0, r5, 0x1\n\
    lsls r0, 16\n\
    lsrs r5, r0, 16\n\
    cmp r5, 0x43\n\
    bls _08145A00\n\
    b _08145A5C\n\
_08145A26:\n\
    movs r4, 0\n\
    ldrh r0, [r7]\n\
    cmp r0, r10\n\
    beq _08145A42\n\
_08145A2E:\n\
    adds r0, r4, 0x1\n\
    lsls r0, 16\n\
    lsrs r4, r0, 16\n\
    lsls r0, r4, 1\n\
    adds r0, r7, r0\n\
    ldrh r0, [r0]\n\
    cmp r0, r10\n\
    beq _08145A42\n\
    cmp r4, 0x43\n\
    bls _08145A2E\n\
_08145A42:\n\
    mov r1, r8\n\
    ldrh r0, [r1]\n\
    subs r0, 0x1\n\
    cmp r4, r0\n\
    bge _08145A5C\n\
    lsls r0, r4, 1\n\
    adds r0, r7, r0\n\
    ldr r2, [sp]\n\
    ldrh r1, [r2]\n\
    strh r1, [r0]\n\
    mov r0, r10\n\
    strh r0, [r2]\n\
    b _08145A62\n\
_08145A5C:\n\
    mov r2, r10\n\
    ldr r1, [sp]\n\
    strh r2, [r1]\n\
_08145A62:\n\
    movs r0, 0x44\n\
    mov r1, r8\n\
    strh r0, [r1]\n\
    add sp, 0x4\n\
    pop {r3-r5}\n\
    mov r8, r3\n\
    mov r9, r4\n\
    mov r10, r5\n\
    pop {r4-r7}\n\
    pop {r0}\n\
    bx r0\n\
    .syntax divided\n");
}
#endif
