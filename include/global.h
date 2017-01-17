#ifndef GUARD_GLOBAL_H
#define GUARD_GLOBAL_H

#include "gba/gba.h"
#include "config.h"

#define GERMAN 1

// Prevent cross-jump optimization.
#define BLOCK_CROSS_JUMP asm("");

// to help in decompiling
#define asm_comment(x) asm volatile("@ -- " x " -- ")

#define ARRAY_COUNT(array) (sizeof(array) / sizeof((array)[0]))

#define POKEMON_NAME_LENGTH 10
#define OT_NAME_LENGTH 7

enum
{
    VERSION_SAPPHIRE = 1,
    VERSION_RUBY = 2,
    VERSION_EMERALD = 3,
};

enum LanguageId {
    LANGUAGE_JAPANESE = 1,
    LANGUAGE_ENGLISH = 2,
    LANGUAGE_GERMAN = 5,
};

#define GAME_LANGUAGE (LANGUAGE_GERMAN)

enum
{
    MALE,
    FEMALE
};

enum
{
    OPTIONS_BUTTON_MODE_NORMAL,
    OPTIONS_BUTTON_MODE_LR,
    OPTIONS_BUTTON_MODE_L_EQUALS_A
};

enum
{
    OPTIONS_TEXT_SPEED_SLOW,
    OPTIONS_TEXT_SPEED_MID,
    OPTIONS_TEXT_SPEED_FAST
};

enum
{
    OPTIONS_SOUND_MONO,
    OPTIONS_SOUND_STEREO
};

enum
{
    OPTIONS_BATTLE_STYLE_SHIFT,
    OPTIONS_BATTLE_STYLE_SET
};

enum
{
    BAG_ITEMS = 1,
    BAG_POKEBALLS,
    BAG_TMsHMs,
    BAG_BERRIES,
    BAG_KEYITEMS
};

struct Coords16
{
    s16 x;
    s16 y;
};

struct UCoords16
{
    u16 x;
    u16 y;
};

struct SecretBaseRecord
{
    u8 sbr_field_0; // ID?
    u8 sbr_field_1_0:4;
    u8 gender:1;
    u8 sbr_field_1_5:1;
    u8 sbr_field_2[7]; // 0xFF bytes?
    u8 trainerId[4]; // byte 0 is used for determining trainer class
    u16 sbr_field_e;
    u8 sbr_field_10;
    u8 sbr_field_11;
    u8 decorations[16];
    u8 sbr_field_22[16];
    u32 partyPersonality[6];
    u16 partyMoves[6 * 4];
    u16 partySpecies[6];
    u16 partyHeldItems[6];
    u8 partyLevels[6];
    u8 partyEVs[6];
};

#include "game_stat.h"
#include "global.fieldmap.h"
#include "global.berry.h"
#include "pokemon.h"

struct WarpData
{
    s8 mapGroup;
    s8 mapNum;
    s8 warpId;
    s16 x, y;
};

struct ItemSlot
{
    u16 itemId;
    u16 quantity;
};

struct Pokeblock
{
    u8 color;
    u8 spicy;
    u8 dry;
    u8 sweet;
    u8 bitter;
    u8 sour;
    u8 feel;
};

struct Roamer
{
    /*0x00*/ u32 ivs;
    /*0x04*/ u32 personality;
    /*0x08*/ u16 species;
    /*0x0A*/ u16 hp;
    /*0x0C*/ u8 level;
    /*0x0D*/ u8 status;
    /*0x0E*/ u8 cool;
    /*0x0F*/ u8 beauty;
    /*0x10*/ u8 cute;
    /*0x11*/ u8 smart;
    /*0x12*/ u8 tough;
    /*0x13*/ u8 active;
};

struct RamScriptData
{
    u8 magic;
    u8 mapGroup;
    u8 mapNum;
    u8 objectId;
    u8 script[995];
};

struct RamScript
{
    u32 checksum;
    struct RamScriptData data;
};

struct SB1_2EFC_Struct
{
    u8 unknown[0x20];
};

struct EasyChatPair
{
    u16 unk0_0:7;
    u16 unk0_7:7;
    u16 unk1_6:1;
    u16 unk2;
    u16 words[2];
}; /*size = 0x8*/

struct TVShowCommon {
    /*0x00*/ u8 var00;
    /*0x01*/ u8 var01;
};

struct TVShowFanClubLetter {
    /*0x00*/ u8 var00;
    /*0x01*/ u8 var01;
    /*0x02*/ u16 species;
    u8 pad04[12];
    /*0x10*/ u8 playerName[8];
    /*0x18*/ u8 var18;
};

struct TVShowRecentHappenings {
    /*0x00*/ u8 var00;
    /*0x01*/ u8 var01;
    /*0x02*/ u16 var02;
    u8 pad04[12];
    /*0x10*/ u8 var10[8];
    /*0x18*/ u8 var18;
    u8 pad19[10];
};

struct TVShowFanclubOpinions {
    /*0x00*/ u8 var00;
    /*0x01*/ u8 var01;
    /*0x02*/ u16 var02;
    /*0x04*/ u8 var04A:4;
    u8 var04B:4;
    /*0x04*/ u8 var05[8];
    /*0x0D*/ u8 var0D;
    /*0x0E*/ u8 var0E;
    /*0x0F*/ u8 var0F;
    /*0x10*/ u8 var10[8];
};

struct TVShowNameRaterShow {
    /*0x00*/ u8 var00;
    /*0x01*/ u8 var01;
    /*0x02*/ u16 species;
    /*0x04*/ u8 pokemonName[11];
    /*0x0F*/ u8 trainerName[11];
    /*0x1A*/ u8 random;
    /*0x1B*/ u8 random2;
    /*0x1C*/ u16 var1C;
    /*0x1E*/ u8 language;
    /*0x1F*/ u8 var1F;
};

struct TVShowMassOutbreak {
    /*0x00*/ u8 var00;
    /*0x01*/ u8 var01;
    /*0x02*/ u8 var02;
    /*0x03*/ u8 var03;
    /*0x04*/ u16 moves[4];
    /*0x0C*/ u16 species;
    /*0x0E*/ u16 var0E;
    /*0x10*/ u8 locationMapNum;
    /*0x11*/ u8 locationMapGroup;
    /*0x12*/ u8 var12;
    /*0x13*/ u8 probability;
    /*0x14*/ u8 level;
    /*0x15*/ u8 var15;
    /*0x16*/ u16 var16;
    /*0x18*/ u8 var18;
    u8 pad19[11];
};

typedef union TVShow {
    struct TVShowCommon common;
    struct TVShowFanClubLetter fanclubLetter;
    struct TVShowRecentHappenings recentHappenings;
    struct TVShowFanclubOpinions fanclubOpinions;
    struct TVShowNameRaterShow nameRaterShow;
    struct TVShowMassOutbreak massOutbreak;
} TVShow;

struct MailStruct
{
    /*0x00*/ u16 words[9];
    /*0x12*/ u8 playerName[8];
    /*0x1A*/ u8 trainerId[4];
    /*0x1E*/ u16 species;
    /*0x20*/ u16 itemId;
};

struct SaveBlock1 /* 0x02025734 */
{
    /*0x00*/ struct Coords16 pos;
    /*0x04*/ struct WarpData location;
    /*0x0C*/ struct WarpData warp1;
    /*0x14*/ struct WarpData warp2;
    /*0x1C*/ struct WarpData warp3;
    /*0x24*/ struct WarpData warp4;
    /*0x2C*/ u16 battleMusic;
    /*0x2E*/ u8 weather;
    /*0x2F*/ u8 filler_2F;
    /*0x30*/ u8 flashUsed;
    /*0x32*/ u16 mapDataId;
    /*0x34*/ u16 mapView[0x100];
    /*0x234*/ u8 playerPartyCount;
    /*0x238*/ struct Pokemon playerParty[6];
    /*0x490*/ u32 money;
    /*0x494*/ u16 coins;
    /*0x496*/ u16 registeredItem; // registered for use with SELECT button
    /*0x498*/ struct ItemSlot pcItems[50];
    /*0x560*/ struct ItemSlot bagPocket_Items[20];
    /*0x5B0*/ struct ItemSlot bagPocket_KeyItems[20];
    /*0x600*/ struct ItemSlot bagPocket_PokeBalls[16];
    /*0x640*/ struct ItemSlot bagPocket_TMHM[64];
    /*0x740*/ struct ItemSlot bagPocket_Berries[46];
    /*0x7F8*/ struct Pokeblock pokeblocks[40];
    /*0x938*/ u8 unk938[52];  // pokedex related
    /*0x96C*/ u16 berryBlenderRecords[3];
    /*0x972*/ u8 filler_972[0x6];
    /*0x978*/ u16 trainerRematchStepCounter;
    /*0x97A*/ u8 trainerRematches[100];
    /*0x9E0*/ struct MapObject mapObjects[16];
    /*0xC20*/ struct MapObjectTemplate mapObjectTemplates[64];
    /*0x1220*/ u8 flags[0x120];
    /*0x1340*/ u16 vars[0x100];
    /*0x1540*/ u32 gameStats[NUM_GAME_STATS];
    /*0x1608*/ struct BerryTree berryTrees[128];
    /*0x1A08*/ struct SecretBaseRecord secretBases[20];
    /*0x2688*/ u8 playerRoomDecor[12];
    /*0x2694*/ u8 playerRoomDecorPos[12];
    /*0x26A0*/ u8 decorDesk[10];
    /*0x26AA*/ u8 decorChair[10];
    /*0x26B4*/ u8 decorPlant[10];
    /*0x26BE*/ u8 decorOrnament[30];
    /*0x26DC*/ u8 decorMat[30];
    /*0x26FA*/ u8 decorPoster[10];
    /*0x2704*/ u8 decorDoll[40];
    /*0x272C*/ u8 decorCushion[10];
    /*0x2736*/ u8 padding_2736[2];
    /*0x2738*/ TVShow tvShows[24];
    /*0x2A98*/ u8 filler_2A98[0x64];
    /*0x2AFC*/ u16 outbreakPokemonSpecies;
    /*0x2AFE*/ u8 outbreakLocationMapNum;
    /*0x2AFF*/ u8 outbreakLocationMapGroup;
    /*0x2B00*/ u8 outbreakPokemonLevel;
    /*0x2B01*/ u8 outbreakUnk1;
    /*0x2B02*/ u16 outbreakUnk2;
    /*0x2B04*/ u16 outbreakPokemonMoves[4];
    /*0x2B0C*/ u8 outbreakUnk4;
    /*0x2B0D*/ u8 outbreakPokemonProbability;
    /*0x2B0E*/ u16 outbreakUnk5;
    /*0x2B10*/ u8 filler_2B0E[0xC];
    /*0x2B1C*/ u16 unk2B1C[4];
    /*0x2B24*/ u8 filler_2B24[0x28];
    /*0x2B4C*/ struct MailStruct mail[16];
    /*0x2D8C*/ u8 filler_2D8C[0x48];
    /*0x2DD4*/ struct EasyChatPair easyChatPairs[5]; //Dewford trend [0] and some other stuff
    /*0x2DFC*/ u8 filler_2DFC[0x100];
    /*0x2EFC*/ struct SB1_2EFC_Struct sb1_2EFC_struct[5];
    /*0x2F9C*/ u8 filler_2F9C[0xA0];
    /*0x303C*/ u8 filler_303C[0x38];
    /*0x3074*/ u8 filler_3074[0x42];
    /*0x30B6*/ u8 filler_30B6;
    /*0x30B7*/ u8 filler_30B7[0x59];
    /*0x3110*/ u8 giftRibbons[7];
    /*0x3117*/ u8 filler_311B[0x2D];
    /*0x3144*/ struct Roamer roamer;
    /*0x3158*/ u8 filler_3158[0x8];
    /*0x3160*/ struct EnigmaBerry enigmaBerry;
    /*0x3690*/ struct RamScript ramScript;
    /*0x3A7C*/ u8 filler_3A7C[0x10];
    /*0x3A8C*/ u8 unk3A8C[52]; //pokedex related
};

extern struct SaveBlock1 gSaveBlock1;

struct Time
{
    /*0x00*/ s16 days;
    /*0x02*/ s8 hours;
    /*0x03*/ s8 minutes;
    /*0x04*/ s8 seconds;
};

struct Pokedex
{
    /*0x00*/ u8 order;
    /*0x01*/ u8 unknown1;
    /*0x02*/ u8 nationalMagic; // must equal 0xDA in order to have National mode
    /*0x03*/ u8 unknown2;
    /*0x04*/ u32 unownPersonality; // set when you first see Unown
    /*0x08*/ u32 spindaPersonality; // set when you first see Spinda
    /*0x0C*/ u32 unknown3;
    /*0x10*/ u8 owned[52];
    /*0x44*/ u8 seen[52];
};

struct SaveBlock2_Sub
{
    /*0x0000, 0x00A8*/ u8 filler_000[0x4AE];
    /*0x04AE, 0x0556*/ u8 var_4AE;
    /*0x04AF, 0x0557*/ u8 var_4AF;
    /*0x04B0, 0x0558*/ u16 var_4B0;
    /*0x04B2, 0x055A*/ u16 var_4B2;
    /*0x04B4, 0x055C*/ u16 var_4B4;
    /*0x04B6, 0x055E*/ u16 var_4B6;
    /*0x04B8, 0x0560*/ u8 filler_4B8[0x10];
    /*0x04C8, 0x0570*/ u16 var_4C8;
    /*0x04CA, 0x0572*/ u16 var_4CA;
    /*0x04CC, 0x0574*/ u8 filler_4CC[0x31C];
};

struct SaveBlock2 /* 0x02024EA4 */
{
    /*0x00*/ u8 playerName[8];
    /*0x08*/ u8 playerGender; // MALE, FEMALE
    /*0x09*/ u8 specialSaveWarp;
    /*0x0A*/ u8 playerTrainerId[4];
    /*0x0E*/ u16 playTimeHours;
    /*0x10*/ u8 playTimeMinutes;
    /*0x11*/ u8 playTimeSeconds;
    /*0x12*/ u8 playTimeVBlanks;
    /*0x13*/ u8 optionsButtonMode;  // OPTIONS_BUTTON_MODE_[NORMAL/LR/L_EQUALS_A]
    /*0x14*/ u16 optionsTextSpeed:3; // OPTIONS_TEXT_SPEED_[SLOW/MID/FAST]
             u16 optionsWindowFrameType:5; // Specifies one of the 20 decorative borders for text boxes
             u16 optionsSound:1; // OPTIONS_SOUND_[MONO/STEREO]
             u16 optionsBattleStyle:1; // OPTIONS_BATTLE_STYLE_[SHIFT/SET]
             u16 optionsBattleSceneOff:1; // whether battle animations are disabled
             u16 regionMapZoom:1; // whether the map is zoomed in
    /*0x18*/ struct Pokedex pokedex;
    /*0x90*/ u8 filler_90[0x8];
    /*0x98*/ struct Time localTimeOffset;
    /*0xA0*/ struct Time lastBerryTreeUpdate;
    /*0xA8*/ struct SaveBlock2_Sub filler_A8;
};

struct MapPosition
{
    s16 x;
    s16 y;
    u8 height;
};

struct UnkStruct_8054FF8
{
    u8 a;
    u8 b;
    u8 c;
    u8 d;
    struct MapPosition sub;
    u16 field_C;
};

extern struct SaveBlock2 gSaveBlock2;

#endif // GUARD_GLOBAL_H
