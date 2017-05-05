#include "global.h"
#include "strings.h"
#include "string_util.h"
#include "link.h"

// mess
struct UnkStruct {
    /*0x00*/ u8 filler00[0x88];
    /*0x88*/ u8 unk88;
};

extern u8 gUnknown_03004834;

extern u8 *gUnknown_082162B8[];

extern struct UnkStruct *gUnknown_03004854;

//  data/pokeblock.o
extern u8 *gPokeblockNames[];

//  data/berry_blender.o
extern u8 gUnknown_08216249[];
extern u8 gUnknown_082162C8[];

//  data/strings2.o
extern u8 gOtherText_PokeBlockMade[];
extern u8 gOtherText_BlockLevelIs[];
extern u8 gOtherText_BlockFeelIs[];
extern u8 gOtherText_Period[];

//  asm/pokeblock.o
u8 sub_810C9B0(struct Pokeblock *);
u8 sub_810C9E8(struct Pokeblock *);

void sub_804E884(u8 arg0) {

    if (arg0 != 0)
    {
        int i;

        for (i = 0; i < MAX_LINK_PLAYERS; i++)
        {
            gLinkPlayers[i].language = GAME_LANGUAGE;
        }
    }

    switch (arg0)
    {
    case 0:
        gUnknown_03004834 = 0;
        break;

    case 1:
        gUnknown_03004834 = 1;
        gUnknown_03004854->unk88 = 2;

        StringCopy(gLinkPlayers[0].name, gSaveBlock2.playerName);
        StringCopy(gLinkPlayers[1].name, gUnknown_082162B8[0]);
        break;

    case 2:
        gUnknown_03004834 = 2;
        gUnknown_03004854->unk88 = 3;

        StringCopy(gLinkPlayers[0].name, gSaveBlock2.playerName);
        StringCopy(gLinkPlayers[1].name, gUnknown_082162B8[0]);
        StringCopy(gLinkPlayers[2].name, gUnknown_082162B8[1]);
        break;

    case 3:
        gUnknown_03004834 = 3;
        gUnknown_03004854->unk88 = 4;

        StringCopy(gLinkPlayers[0].name, gSaveBlock2.playerName);
        StringCopy(gLinkPlayers[1].name, gUnknown_082162B8[0]);
        StringCopy(gLinkPlayers[2].name, gUnknown_082162B8[1]);
        StringCopy(gLinkPlayers[3].name, gUnknown_082162B8[2]);
        break;

    }
}

asm(".section .text_b");

void sub_805201C(struct Pokeblock *arg0, u8 *arg1) {
    u8 buffer[12];
    u8 blockLevel, blockFeel;
    arg1[0] = 0xFF;

    StringCopy(arg1, gPokeblockNames[arg0->color]);
    StringAppend(arg1, gOtherText_PokeBlockMade);
    StringAppend(arg1, gUnknown_082162C8);

    blockLevel = sub_810C9B0(arg0);
    blockFeel = sub_810C9E8(arg0);

    StringAppend(arg1, gOtherText_BlockLevelIs);
    ConvertIntToDecimalStringN(buffer, blockLevel, STR_CONV_MODE_LEFT_ALIGN, 3);
    StringAppend(arg1, buffer);

    StringAppend(arg1, gOtherText_BlockFeelIs);
    ConvertIntToDecimalStringN(buffer, blockFeel, STR_CONV_MODE_LEFT_ALIGN, 3);
    StringAppend(arg1, buffer);

    StringAppend(arg1, gOtherText_Period);

    StringAppend(arg1, gUnknown_08216249);
}