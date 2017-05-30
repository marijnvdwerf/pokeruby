#ifndef GUARD_DATA2_H
#define GUARD_DATA2_H

#include "sprite.h"

struct UnknownStructD2 {
    u32 unk0;
    u32 unk4;
    u32 unk8;
};

struct MonCoords
{
    // This would use a bitfield, but sub_8079F44
    // uses it as a u8 and casting won't match.
    u8 coords; // u8 x:4, y:4;
    u8 y_offset;
};

extern const union AffineAnimCmd *const gSpriteAffineAnimTable_81E7C18;
extern const union AnimCmd *const gSpriteAnimTable_81E7C64[];
extern struct MonCoords gMonFrontPicCoords[];
extern struct MonCoords gMonBackPicCoords[];
extern struct SpriteSheet gMonFrontPicTable[];
extern struct SpriteSheet gMonBackPicTable[];
extern const struct SpritePalette gMonPaletteTable[];
extern const struct SpritePalette gMonShinyPaletteTable[];
extern const union AnimCmd *const *const gUnknown_081EC2A4[];
extern const union AnimCmd *const *const gUnknown_081ECACC[];
extern struct MonCoords gTrainerBackPicCoords[];
extern struct SpriteSheet gTrainerBackPicTable[];
extern struct SpritePalette gTrainerBackPicPaletteTable[];
extern u8 gEnemyMonElevation[];
extern const u8 gTrainerClassNames[][13];
extern const struct Trainer gTrainers[];
extern u8 gSpeciesNames[][11];
extern u8 gMoveNames[][13];
extern const struct UnknownStructD2 gUnknown_081F9674;
extern const u8 gUnknown_081F96C8[];
extern struct SpriteSheet gUnknown_081FAEA4;
extern struct SpritePalette gUnknown_081FAEAC;
extern const struct SpriteTemplate gSpriteTemplate_81FAF0C;
extern void *gUnknown_081FAF4C[];
extern struct BattleMove gBattleMoves[];

extern u8 gTypeNames[][7];
extern u8 gAbilityNames[][13];

#endif // GUARD_DATA2_H
