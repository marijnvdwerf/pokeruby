#include "global.h"
#include "save_menu_util.h"
#include "event_data.h"
#include "menu.h"
#include "pokedex.h"
#include "region_map.h"
#include "string_util.h"
#include "strings2.h"

void HandleDrawSaveWindowInfo(s16 left, s16 top)
{
    u32 width = 12;

    // old handle for setting window width?
    if (IsResizeSaveWindowEnabled())
        width = 13;

    if (FlagGet(SYS_POKEDEX_GET))
    {
        // print info + dex information.
        MenuDrawTextWindow(left, top, left + width, top + 11);
        PrintSaveMapName(++left, ++top);      // MAP NAME
        PrintSavePlayerName(left, top + 2);   // PLAYER
        PrintSaveBadges(left, top + 4);       // BADGES
        PrintSavePokedexCount(left, top + 6); // POKEDEX
        PrintSavePlayTime(left, top + 8);     // PLAY TIME
    }
    else
    {
        // print everything besides dex.
        MenuDrawTextWindow(left, top, left + width, top + 9);
        PrintSaveMapName(++left, ++top);    // MAP NAME
        PrintSavePlayerName(left, top + 2); // PLAYER
        PrintSaveBadges(left, top + 4);     // BADGES
        PrintSavePlayTime(left, top + 6);   // PLAY TIME
    }
}

void HandleCloseSaveWindow(u16 left, u16 top)
{
    u32 width = 12;

    // old handle for setting window width?
    if (IsResizeSaveWindowEnabled())
        width = 13;

    if (FlagGet(SYS_POKEDEX_GET))
        MenuZeroFillWindowRect(left, top, left + width, top + 11);
    else
        MenuZeroFillWindowRect(left, top, left + width, top + 9);
}

/*
theory: This function was used to handle the save menu window's width being auto sized from
either 12 or 13 in an older source. Whatever was here might have either been optimized out by
GF's compiler or was dummied out to always return a TRUE at some point.
*/
u8 IsResizeSaveWindowEnabled(void) // i don't know what else to name it..
{
    return TRUE;
}

void PrintSavePlayerName(s16 x, s16 y)
{
    MenuPrint(gOtherText_Player, x, y);
    MenuPrint_RightAligned(gSaveBlock2.playerName, x + 12, y);
}

void PrintSaveMapName(s16 x, s16 y)
{
    char name[32];

    CopyMapName(name, gMapHeader.name);
    MenuPrint(name, x, y);
}

void PrintSaveBadges(s16 x, s16 y)
{
    char badges[16];

    MenuPrint(gOtherText_Badges, x, y);
    ConvertIntToDecimalString(badges, GetBadgeCount());
    MenuPrint_RightAligned(badges, x + 12, y);
}

void PrintSavePokedexCount(s16 x, s16 y)
{
    char pokedex[16];

    MenuPrint(gOtherText_Pokedex, x, y);
    ConvertIntToDecimalStringN(pokedex, GetPokedexSeenCount(), 1, 3);
    MenuPrint_RightAligned(pokedex, x + 12, y);
}

void PrintSavePlayTime(s16 x, s16 y)
{
    char playtime[16];

    MenuPrint(gOtherText_PlayTime, x, y);
    FormatPlayTime(playtime, gSaveBlock2.playTimeHours, gSaveBlock2.playTimeMinutes, 1);
    MenuPrint_RightAligned(playtime, x + 12, y);
}

u8 GetBadgeCount(void)
{
    u8 badgeCount = 0;
    int badgeFlag;

    for (badgeFlag = BADGE01_GET; badgeFlag <= BADGE08_GET; badgeFlag++)
        if (FlagGet(badgeFlag))
            badgeCount++;

    return badgeCount;
}

u16 GetPokedexSeenCount()
{
    u16 pokedexSeenCount;

    if (IsNationalPokedexEnabled())
        pokedexSeenCount = GetNationalPokedexCount(1);
    else
        pokedexSeenCount = GetHoennPokedexCount(1);

    return pokedexSeenCount;
}

void FormatPlayTime(char *playtime, u16 hours, u16 minutes, u16 unk)
{
    s16 colon = unk;
    playtime = ConvertIntToDecimalString(playtime, hours);

    // playtime[0] is hours.
    // playtime[1] is the character to render between hours and minutes.
    // playtime[2] is minutes.

    playtime[0] = 0;

    if (colon)
        playtime[1] = 0xF0; // set middle character to ":"
    else
        playtime[1] = 0;

    playtime[2] = 0;
    playtime += 3;

    ConvertIntToDecimalStringN(playtime, minutes, 2, 2);
}
