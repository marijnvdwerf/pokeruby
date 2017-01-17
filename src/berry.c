#include "global.h"
#include "berry.h"
#include "asm.h"
#include "item.h"
#include "items.h"
#include "main.h"
#include "rng.h"
#include "string_util.h"
#include "text.h"

#define FIRST_BERRY ITEM_CHERI_BERRY
#define LAST_BERRY  ITEM_ENIGMA_BERRY

extern struct Berry gBerries[];
extern u8 BerryTreeScript;
extern struct BerryTree gBlankBerryTree;
extern u16 gScriptItemId;
extern u16 gScriptLastTalked;
extern u16 gSpecialVar_0x8004;
extern u16 gSpecialVar_0x8005;
extern u16 gSpecialVar_0x8006;

void debug_sub_80C2B04(void) {
    asm(".fill 40");
}

void debug_sub_80C2B30(void) {
    asm(".fill 40");
}

// unused
void ClearEnigmaBerries(void)
{
    CpuFill16(0, &gSaveBlock1.enigmaBerry, sizeof(gSaveBlock1.enigmaBerry));
}

void SetEnigmaBerry(u8 *src)
{
    u32 i;
    u8 *dest = (u8*)&gSaveBlock1.enigmaBerry;

    for (i = 0; i < sizeof(gSaveBlock1.enigmaBerry); i++)
        dest[i] = src[i];

    gSaveBlock1.enigmaBerry.berry.description1 = gSaveBlock1.enigmaBerry.description1;
    gSaveBlock1.enigmaBerry.berry.description2 = gSaveBlock1.enigmaBerry.description2;
}

void debug_sub_80C2BD0(void) {
    asm(".fill 68");
}

u32 GetEnigmaBerryChecksum(struct EnigmaBerry *enigmaBerry)
{
    u8 *description1;
    u8 *description2;
    u32 i;
    u32 checksum;
    u8 *dest;

    description1 = gSaveBlock1.enigmaBerry.berry.description1;
    description2 = gSaveBlock1.enigmaBerry.berry.description2;
    gSaveBlock1.enigmaBerry.berry.description1 = 0;
    gSaveBlock1.enigmaBerry.berry.description2 = 0;

    dest = (u8*)enigmaBerry;
    checksum = 0;
    for (i = 0; i < ((u32)&gSaveBlock1.enigmaBerry.checksum - (u32)&gSaveBlock1.enigmaBerry); i++)
    {
        checksum += dest[i];
    }

    gSaveBlock1.enigmaBerry.berry.description1 = description1;
    gSaveBlock1.enigmaBerry.berry.description2 = description2;

    asm(".fill 196");
    return checksum;
}

void debug_sub_80C2D24(void) {
    asm(".fill 92");
}

bool32 IsEnigmaBerryValid(void)
{
    if (!gSaveBlock1.enigmaBerry.berry.stageDuration)
        return FALSE;
    if (!gSaveBlock1.enigmaBerry.berry.maxYield)
        return FALSE;
    if (GetEnigmaBerryChecksum(&gSaveBlock1.enigmaBerry) != gSaveBlock1.enigmaBerry.checksum)
        return FALSE;
    return TRUE;
}

struct Berry *GetBerryInfo(u8 berry)
{
    if (berry == 0x2B && IsEnigmaBerryValid())
        return &gSaveBlock1.enigmaBerry.berry;
    else
    {
        if (berry == 0 || berry > 0x2B)
            berry = 1;
        return &gBerries[berry - 1];
    }
}

struct BerryTree *GetBerryTreeInfo(u8 id)
{
    return &gSaveBlock1.berryTrees[id];
}

bool32 FieldObjectInteractionWaterBerryTree(void)
{
    struct BerryTree *tree = GetBerryTreeInfo(FieldObjectGetBerryTreeId(gSelectedMapObject));

    switch (tree->stage)
    {
    case 1:
        tree->watered1 = TRUE;
        break;
    case 2:
        tree->watered2 = TRUE;
        break;
    case 3:
        tree->watered3 = TRUE;
        break;
    case 4:
        tree->watered4 = TRUE;
        break;
    default:
        return FALSE;
    }
    return TRUE;
}

bool32 IsPlayerFacingPlantedBerryTree(void)
{
    if (GetFieldObjectScriptPointerForComparison() == &BerryTreeScript
     && GetStageByBerryTreeId(FieldObjectGetBerryTreeId(gSelectedMapObject)) == 0)
        return TRUE;
    else
        return FALSE;
}

u8 TryToWaterBerryTree(void)
{
    if (GetFieldObjectScriptPointerForComparison() != &BerryTreeScript)
        return 0;
    else
        return FieldObjectInteractionWaterBerryTree();
}

void ClearBerryTrees(void)
{
    int i;
    struct SaveBlock1 *saveBlock1 = &gSaveBlock1;
    struct BerryTree berryTree = gBlankBerryTree;

    for (i = 0; i < 128; i++)
        saveBlock1->berryTrees[i] = berryTree;
}

bool32 BerryTreeGrow(struct BerryTree *tree)
{
    if (tree->growthSparkle)
        return FALSE;
    switch (tree->stage)
    {
    case 0:
        return FALSE;
    case 4:
        tree->berryYield = CalcBerryYield(tree);
    case 1:
    case 2:
    case 3:
        tree->stage++;
        break;
    case 5:
        tree->watered1 = 0;
        tree->watered2 = 0;
        tree->watered3 = 0;
        tree->watered4 = 0;
        tree->berryYield = 0;
        tree->stage = 2;
        if (++tree->regrowthCount == 10)
            *tree = gBlankBerryTree;
        break;
    }
    return TRUE;
}

void BerryTreeTimeUpdate(int time)
{
    int i;
    struct BerryTree *tree;

    for (i = 0; i < 128; i++)
    {
        tree = &gSaveBlock1.berryTrees[i];

        if (tree->berry && tree->stage && !tree->growthSparkle)
        {
            if (time >= GetStageDurationByBerryType(tree->berry) * 71)
            {
                *tree = gBlankBerryTree;
            }
            else
            {
                int time2 = time;

                while (time2 != 0)
                {
                    if (tree->secondsUntilNextStage > time2)
                    {
                        tree->secondsUntilNextStage -= time2;
                        break;
                    }
                    time2 -= tree->secondsUntilNextStage;
                    tree->secondsUntilNextStage = GetStageDurationByBerryType(tree->berry);
                    if (!BerryTreeGrow(tree))
                        break;
                    if (tree->stage == 5)
                        tree->secondsUntilNextStage *= 4;
                }
            }
        }
    }
}

void PlantBerryTree(u8 id, u8 berry, u8 stage, bool8 sparkle)
{
    struct BerryTree *tree = GetBerryTreeInfo(id);

    *tree = gBlankBerryTree;
    tree->berry = berry;
    tree->secondsUntilNextStage = GetStageDurationByBerryType(berry);
    tree->stage = stage;
    if (stage == 5)
    {
        tree->berryYield = CalcBerryYield(tree);
        tree->secondsUntilNextStage *= 4;
    }
    if (!sparkle)
    {
        tree->growthSparkle = TRUE;
    }
}

void RemoveBerryTree(u8 id)
{
    gSaveBlock1.berryTrees[id] = gBlankBerryTree;
}

u8 GetBerryTypeByBerryTreeId(u8 id)
{
    return gSaveBlock1.berryTrees[id].berry;
}

u8 GetStageByBerryTreeId(u8 id)
{
    return gSaveBlock1.berryTrees[id].stage;
}

u8 ItemIdToBerryType(u16 item)
{
    u16 berry = item - FIRST_BERRY;

    if (berry > LAST_BERRY - FIRST_BERRY)
        return 1;
    else
        return item - FIRST_BERRY + 1;
}

u16 BerryTypeToItemId(u16 berry)
{
    u16 item = berry - 1;

    if (item > LAST_BERRY - FIRST_BERRY)
        return FIRST_BERRY;
    else
        return berry + FIRST_BERRY - 1;
}

void GetBerryNameByBerryType(u8 berry, u8 *string)
{
    memcpy(string, GetBerryInfo(berry)->name, 6);
    string[6] = EOS;
}

void ResetBerryTreeSparkleFlag(u8 id)
{
    GetBerryTreeInfo(id)->growthSparkle = 0;
}

u8 BerryTreeGetNumStagesWatered(struct BerryTree *tree)
{
    u8 count = 0;

    if (tree->watered1)
        count++;
    if (tree->watered2)
        count++;
    if (tree->watered3)
        count++;
    if (tree->watered4)
        count++;
    return count;
}

u8 GetNumStagesWateredByBerryTreeId(u8 id)
{
    return BerryTreeGetNumStagesWatered(GetBerryTreeInfo(id));
}

u8 CalcBerryYieldInternal(u16 max, u16 min, u8 water)
{
    u32 randMin;
    u32 randMax;
    u32 rand;
    u32 extraYield;

    if (water == 0)
        return min;
    else
    {
        randMin = (max - min) * (water - 1);
        randMax = (max - min) * (water);
        rand = randMin + Random() % (randMax - randMin + 1);

        if ((rand & 3) > 1)
            extraYield = rand / 4 + 1;
        else
            extraYield = rand / 4;
        return extraYield + min;
    }
}

u8 CalcBerryYield(struct BerryTree *tree)
{
    struct Berry *berry = GetBerryInfo(tree->berry);
    u8 min = berry->minYield;
    u8 max = berry->maxYield;

    return CalcBerryYieldInternal(max, min, BerryTreeGetNumStagesWatered(tree));
}

u8 GetBerryCountByBerryTreeId(u8 id)
{
    return gSaveBlock1.berryTrees[id].berryYield;
}

u16 GetStageDurationByBerryType(u8 berry)
{
    return GetBerryInfo(berry)->stageDuration * 60;
}

void FieldObjectInteractionGetBerryTreeData(void)
{
    u8 id;
    u8 berry;
    u8 unk;
    u8 group;
    u8 num;

    id = FieldObjectGetBerryTreeId(gSelectedMapObject);
    berry = GetBerryTypeByBerryTreeId(id);
    ResetBerryTreeSparkleFlag(id);
    unk = gScriptLastTalked;
    num = gSaveBlock1.location.mapNum;
    group = gSaveBlock1.location.mapGroup;
    if (sub_8060234(unk, num, group))
        gSpecialVar_0x8004 = 0xFF;
    else
        gSpecialVar_0x8004 = GetStageByBerryTreeId(id);
    gSpecialVar_0x8005 = GetNumStagesWateredByBerryTreeId(id);
    gSpecialVar_0x8006 = GetBerryCountByBerryTreeId(id);
    GetBerryNameByBerryType(berry, gStringVar1);
}

void sub_80B4EE4(void)
{
    SetMainCallback2(sub_80A68CC);
}

void FieldObjectInteractionPlantBerryTree(void)
{
    u8 berry = ItemIdToBerryType(gScriptItemId);

    PlantBerryTree(FieldObjectGetBerryTreeId(gSelectedMapObject), berry, 1, TRUE);
    FieldObjectInteractionGetBerryTreeData();
}

void FieldObjectInteractionPickBerryTree(void)
{
    u8 id = FieldObjectGetBerryTreeId(gSelectedMapObject);
    u8 berry = GetBerryTypeByBerryTreeId(id);

    gSpecialVar_0x8004 = AddBagItem(BerryTypeToItemId(berry), GetBerryCountByBerryTreeId(id));
}

void FieldObjectInteractionRemoveBerryTree(void)
{
    RemoveBerryTree(FieldObjectGetBerryTreeId(gSelectedMapObject));
    sub_8060288(gScriptLastTalked, gSaveBlock1.location.mapNum, gSaveBlock1.location.mapGroup);
}

u8 PlayerHasBerries(void)
{
    return IsBagPocketNonEmpty(BAG_BERRIES);
}

#ifdef DEBUG

void debug_sub_80C33FC(u8 *buffer, s32 value, u8 n) {
    StringAppend(gStringVar4, buffer);
    ConvertIntToDecimalStringN(gStringVar1, value, STR_CONV_MODE_LEADING_ZEROS, n);
    StringAppend(gStringVar4, gStringVar1);
}

extern u8 gUnknown_Debug_083F7F9D[];
extern u8 gUnknown_Debug_083F7FA2[];
extern u8 gUnknown_Debug_083F7FA9[];
extern u8 gUnknown_Debug_083F7FB0[];
extern u8 gUnknown_Debug_083F7FB7[];
extern u8 gUnknown_Debug_083F7FBE[];
extern u8 gUnknown_Debug_083F7FC5[];
extern u8 gUnknown_Debug_083F7FCC[];
extern u8 gUnknown_Debug_083F7FD3[];
extern u8 gUnknown_Debug_083F7FD3[];
extern u8 gUnknown_Debug_083F7FD3[];

#ifdef NONMATCHING
u8* DebugOpenBerryInfo(void) {
    s32 i;
    u8 berryTreeId;
    struct BerryTree *berryTree;

    if (GetFieldObjectScriptPointerForComparison() != &BerryTreeScript) {
        return NULL;
    }

    berryTreeId = FieldObjectGetBerryTreeId(gSelectedMapObject);
    berryTree = GetBerryTreeInfo(berryTreeId);
    
    for (i = 0; i < 500; i++) {
        gStringVar4[i] |= 0xFF;
    }

    debug_sub_80C33FC(gUnknown_Debug_083F7F9D, berryTreeId, 3);
    debug_sub_80C33FC(gUnknown_Debug_083F7FA2, berryTree->berry, 2);
    debug_sub_80C33FC(gUnknown_Debug_083F7FA9, berryTree->stage, 2);
    debug_sub_80C33FC(gUnknown_Debug_083F7FB0, berryTree->secondsUntilNextStage, 5);
    debug_sub_80C33FC(gUnknown_Debug_083F7FB7, berryTree->berryYield, 2);
    debug_sub_80C33FC(gUnknown_Debug_083F7FBE, berryTree->regrowthCount, 3);
    debug_sub_80C33FC(gUnknown_Debug_083F7FC5, berryTree->growthSparkle, 1);
    debug_sub_80C33FC(gUnknown_Debug_083F7FCC, berryTree->watered1, 1);
    debug_sub_80C33FC(gUnknown_Debug_083F7FD3, berryTree->watered2, 1);
    debug_sub_80C33FC(gUnknown_Debug_083F7FD3, berryTree->watered3, 1);
    debug_sub_80C33FC(gUnknown_Debug_083F7FD3, berryTree->watered4, 1);

    return gStringVar4;
}
#else
void DebugOpenBerryInfo(void) {
    asm(".fill 252");
}
#endif

#endif

void ResetBerryTreeSparkleFlags(void)
{
    s16 cam_left;
    s16 cam_top;
    s16 left;
    s16 top;
    s16 right;
    s16 bottom;
    int i;

    GetCameraCoords(&cam_left, &cam_top);
    left = cam_left;
    top = cam_top + 3;
    right = cam_left + 14;
    bottom = top + 8;
    for (i = 0; i < 16; i++)
    {
        if (gMapObjects[i].active && gMapObjects[i].animPattern == 12)
        {
            cam_left = gMapObjects[i].coords2.x;
            cam_top = gMapObjects[i].coords2.y;
            if (left <= cam_left && cam_left <= right && top <= cam_top && cam_top <= bottom)
                ResetBerryTreeSparkleFlag(gMapObjects[i].trainerRange_berryTreeId);
        }
    }
}
