#include "global.h"
#include "battle_message.h"
#include "battle.h"
#include "data2.h"
#include "item.h"
#include "items.h"
#include "link.h"
#include "moves.h"
#include "rom_8077ABC.h"
#include "string_util.h"
#include "text.h"

extern u8 gUnknown_03004290[];

extern u8 gUnknown_02024C0B;

extern struct BattleEnigmaBerry gEnigmaBerries[];

extern u16 gBattleTypeFlags;

// data/battle_message.s
extern const u8 gUnknown_08400791[];
extern const u8 gUnknown_08400797[];
extern const u8 gUnknown_084007D0[];
extern const u8 gUnknown_084007C8[];
extern const u8 gUnknown_084007CA[];
extern const u8 gUnknown_084007CC[];
extern const u8 gUnknown_084007CE[];
extern const u8 gUnknown_08400A78[];
extern const u8 gUnknown_08400A85[];
extern const u8 *gUnknown_08400F58[];
extern const u8 *gUnknown_08400F78[];
extern const u8 *gUnknown_08400F8C[];
extern const u16 gUnknown_084016BC[];

extern u8 gUnknown_020238CC[];

extern u8 gUnknown_08400E5E[];
extern u8 gUnknown_08400E62[];


extern u8 ewram[];
#define ewram160CB (ewram[0x160CB])

extern u8 gUnknown_030041C0[];

const u8 *sub_8120F98(u8 *);


struct UnkStructBattle {
    const u8 (*jpnText)[8];
    const u8 (*battleText)[];
};

extern const struct UnkStructBattle gUnknown_081FA6D4[];

// <editor-fold desc="Description">
extern const u8 gUnknown_083FEE5D[];
extern const u8 gUnknown_083FEE92[];
extern const u8 BattleText_PreventedS[];
extern const u8 gUnknown_083FFCCA[];
extern const u8 gUnknown_083FFDB3[];
extern const u8 gUnknown_083FFDD3[];
extern const u8 gUnknown_083FFEFC[];
extern const u8 gUnknown_083FFF56[];
extern const u8 gUnknown_083FFF6A[];
extern const u8 gUnknown_083FFF81[];
extern const u8 gUnknown_083FFF99[];
extern const u8 gUnknown_083FFFB3[];
extern const u8 gUnknown_083FFFCB[];
extern const u8 gUnknown_083FFFEA[];
extern const u8 gUnknown_083FFFF7[];
extern const u8 gUnknown_08400555[];
extern const u8 gUnknown_08400568[];
extern const u8 gUnknown_0840057B[];
extern const u8 gUnknown_08400590[];
extern const u8 gUnknown_084005AA[];
extern const u8 gUnknown_084005C7[];
extern const u8 gUnknown_084005DB[];
extern const u8 gUnknown_084005F5[];
extern const u8 gUnknown_08400608[];
extern const u8 gUnknown_08400622[];
extern const u8 gUnknown_08400635[];
extern const u8 gUnknown_08400645[];
extern const u8 gUnknown_0840065C[];
extern const u8 gUnknown_0840067C[];
extern const u8 gUnknown_0840068C[];
extern const u8 gUnknown_0840069C[];
extern const u8 gUnknown_084006A4[];
extern const u8 gUnknown_084006B3[];
extern const u8 gUnknown_084006BB[];
extern const u8 gUnknown_084006C6[];
extern const u8 gUnknown_084006D5[];
extern const u8 gUnknown_084006F1[];
extern const u8 gUnknown_08400709[];
extern const u8 gUnknown_08400727[];
extern const u8 gUnknown_08400736[];
extern const u8 gUnknown_08400749[];
extern const u8 gUnknown_0840075E[];
extern const u8 gUnknown_08400771[];
extern const u8 gUnknown_08400781[];
extern const u8 gUnknown_08400791[];
extern const u8 gUnknown_08400797[];
extern const u8 gUnknown_0840079C[];
extern const u8 gUnknown_084007A1[];
extern const u8 gUnknown_084007A7[];
extern const u8 gUnknown_084007AC[];
extern const u8 gUnknown_084007B2[];
extern const u8 gUnknown_084007B7[];
extern const u8 gUnknown_084007BD[];
extern const u8 gUnknown_084007C8[];
extern const u8 gUnknown_084007CA[];
extern const u8 gUnknown_084007CC[];
extern const u8 gUnknown_084007CE[];
extern const u8 gUnknown_084007D0[];
extern const u8 gUnknown_084009ED[];
extern const u8 gUnknown_084009F7[];
extern const u8 gUnknown_08400A78[];
extern const u8 gUnknown_08400A85[];
extern const u8 gUnknown_08400C4A[];
extern const u8 gUnknown_08400C60[];
extern const u8 gUnknown_08400C8D[];
extern const u8 gUnknown_08400CA8[];
extern const u8 gUnknown_08400CBB[];
extern const u8 gUnknown_08400CCC[];
extern const u8 gUnknown_08400CE0[];
extern const u8 gUnknown_08400CF3[];
extern const u8 gUnknown_08400D15[];
extern const u8 gUnknown_08400D38[];
extern const u8 gUnknown_08400D49[];
extern const u8 gUnknown_08400D52[];
extern const u8 gUnknown_08400D7A[];
extern const u8 gUnknown_08400D89[];
extern const u8 gUnknown_08400D9F[];
extern const u8 gUnknown_08400DAA[];
extern const u8 gUnknown_08400DAC[];
extern const u8 gUnknown_08400DD6[];
extern const u8 BattleText_SafariBall[];
extern const u8 BattleText_SafariBall[];
extern const u8 gUnknown_08400DE6[];
extern const u8 gUnknown_08400DF0[];
extern const u8 BattleText_HighlightR[];
extern const u8 BattleText_Sleep[];
extern const u8 BattleText_PoisonStat[];
extern const u8 BattleText_Burn[];
extern const u8 BattleText_Paralysis[];
extern const u8 BattleText_IceStatus[];
extern const u8 BattleText_Confusion[];
extern const u8 BattleText_Love[];
extern const u8 gUnknown_08400E23[];
extern const u8 gUnknown_08400E29[];
extern const u8 gUnknown_08400E2C[];
extern const u8 gUnknown_08400E2E[];
extern const u8 gUnknown_08400E30[];
extern const u8 gUnknown_08400E32[];
extern const u8 gUnknown_08400E36[];
extern const u8 gBadEggNickname[];
extern const u8 gUnknown_08400E42[];
extern const u8 BattleText_Wally[];
extern const u8 BattleText_Win[];
extern const u8 BattleText_Loss[];
extern const u8 BattleText_Tie[];
extern const u8 gUnknown_08401508[];
extern const u8 BattleTextList_401512[];
extern const u8 BattleTextList_40151C[];
extern const u8 BattleTextList_401528[];
extern const u8 BattleTextList_40152C[];
extern const u8 BattleTextList_401530[];
extern const u8 BattleTextList_401534[];
extern const u8 BattleTextList_40153A[];
extern const u8 BattleTextList_401540[];
extern const u8 BattleTextList_40154C[];
extern const u8 BattleTextList_401556[];
extern const u8 BattleTextList_40155A[];
extern const u8 BattleTextList_40155E[];
extern const u8 BattleTextList_401562[];
extern const u8 BattleTextList_401566[];
extern const u8 BattleTextList_40156A[];
extern const u8 BattleTextList_401570[];
extern const u8 BattleTextList_40157C[];
extern const u8 BattleTextList_401584[];
extern const u8 BattleTextList_401594[];
extern const u8 BattleTextList_4015A0[];
extern const u8 BattleTextList_4015A4[];
extern const u8 BattleTextList_4015A8[];
extern const u8 BattleTextList_4015AC[];
extern const u8 BattleTextList_4015B0[];
extern const u8 BattleTextList_4015B4[];
extern const u8 BattleTextList_4015B8[];
extern const u8 BattleTextList_4015BC[];
extern const u8 BattleTextList_4015C0[];
extern const u8 BattleTextList_4015C4[];
extern const u8 BattleTextList_4015C8[];
extern const u8 BattleTextList_4015D0[];
extern const u8 BattleTextList_4015D4[];
extern const u8 BattleTextList_4015D8[];
extern const u8 BattleTextList_4015E2[];
extern const u8 BattleTextList_4015E6[];
extern const u8 BattleTextList_4015EE[];
extern const u8 BattleTextList_40160E[];
extern const u8 BattleTextList_401616[];
extern const u8 BattleTextList_40161A[];
extern const u8 BattleTextList_401620[];
extern const u8 BattleTextList_40162C[];
extern const u8 BattleTextList_401630[];
extern const u8 BattleTextList_401636[];
extern const u8 BattleTextList_40163C[];
extern const u8 BattleTextList_401642[];
extern const u8 BattleTextList_401648[];
extern const u8 gUnknown_0840164C[];
extern const u8 gUnknown_0840165C[];
extern const u8 *gUnknown_08401674[];
extern const u8 gUnknown_084017A8[];
// </editor-fold>

struct UnkStructA {
    u16 var00;
    u8 pad02[2];
    u16 var04;
    u8 var06;
    u8 var07;
    u8 var08;
    u8 var09;
    u8 var0A;
    u8 var0B;
    u8 var0C[4];
    u8 var10[16];
    u8 var20[16];
    u8 var30[16];
    u8 pad40[448];
};

extern u16 gUnknown_02024C04;
extern u8 byte_2024C06;

extern struct UnkStructA gUnknown_02023A64[];

extern u16 gTrainerBattleOpponent;
extern struct UnkStructA *gSelectedOrderFromParty;

#define BATTLE_TEXT_NoEffectOn 362


extern u8 gUnknown_02024A60;
extern u8 gUnknown_030042B0[];
extern u8 gUnknown_0203926C[];

void sub_8121D1C(const u8 *arg0);

void sub_8121D74(const u8 *dstPtr);

void sub_8120AA8(u16 arg0) {
    int i;
    const u8 *ptr = NULL;

    gSelectedOrderFromParty = &gUnknown_02023A64[gUnknown_02024A60];

    gUnknown_02024C04 = gSelectedOrderFromParty->var04;
    byte_2024C06 = gSelectedOrderFromParty->var06;
    ewram[0x16003] = gSelectedOrderFromParty->var07;
    ewram[0x1605E] = gSelectedOrderFromParty->var08;
    ewram[0x160C1] = gSelectedOrderFromParty->var09;
    gUnknown_02024C0B = gSelectedOrderFromParty->var0A;
    ewram[0x160A0] = gSelectedOrderFromParty->var0B;

    for (i = 0; i < 4; i++)
    {
        gUnknown_0203926C[i] = gSelectedOrderFromParty->var0C[i];
    }


    for (i = 0; i < 0x10; i++)
    {
        gUnknown_030041C0[i] = gSelectedOrderFromParty->var10[i];
        gUnknown_03004290[i] = gSelectedOrderFromParty->var20[i];
        gUnknown_030042B0[i] = gSelectedOrderFromParty->var30[i];
    }

    switch (arg0)
    {
    case 0:
        if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
        {
            if (gBattleTypeFlags & BATTLE_TYPE_LINK)
            {
                if (!(gBattleTypeFlags & BATTLE_TYPE_MULTI))
                {
                    ptr = gUnknown_084005C7;
                    break;
                }

                ptr = gUnknown_084005DB;
            }
            else
            {
                ptr = gUnknown_084005AA;
            }
        }
        else
        {
            if (gBattleTypeFlags & BATTLE_TYPE_LEGENDARY)
            {
                ptr = gUnknown_08400568;
            }
            else if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
            {
                ptr = gUnknown_08400590;
            }
            else if (gBattleTypeFlags & BATTLE_TYPE_WALLY_TUTORIAL)
            {
                ptr = gUnknown_0840057B;
            }
            else
            {
                ptr = gUnknown_08400555;
            }
        }

        break;

    case 1:
        if (battle_side_get_owner(gUnknown_02024A60) == 0)
        {
            if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
            {
                if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
                {
                    ptr = gUnknown_084006F1;
                }
                else
                {
                    ptr = gUnknown_084006A4;
                }
            }
            else
            {
                ptr = gUnknown_0840069C;
            }
        }
        else
        {
            if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
            {
                if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
                {
                    ptr = gUnknown_0840065C;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_LINK)
                {
                    ptr = gUnknown_08400645;
                }
                else
                {
                    ptr = gUnknown_08400608;
                }
            }
            else
            {
                if (gBattleTypeFlags & BATTLE_TYPE_LINK)
                {
                    ptr = gUnknown_08400635;
                }
                else
                {
                    ptr = gUnknown_084005F5;
                }
            }
        }

        break;

    case 2:
        if (battle_side_get_owner(gUnknown_02024A60) == 0)
        {
            if (ewram[0x160C1] == 0)
            {
                ptr = gUnknown_08400709;
            }
            else if (ewram[0x160C1] == 1 || (gBattleTypeFlags & BATTLE_TYPE_DOUBLE))
            {
                ptr = gUnknown_08400727;
            }
            else if (ewram[0x160C1] == 2)
            {
                ptr = gUnknown_08400736;
            }
            else
            {
                ptr = gUnknown_08400749;
            }
        }
        else
        {

            if (gTrainerBattleOpponent == 0x800)
            {
                if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
                {
                    ptr = gUnknown_08400781;
                }
                else
                {
                    ptr = gUnknown_08400771;
                }
            }
            else
            {
                ptr = gUnknown_0840075E;
            }
        }

        break;

    case 3:
        if (battle_side_get_owner(ewram[0x16003]) == 0)
        {
            if (ewram[0x160C1] == 0 || gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
            {
                ptr = gUnknown_084006B3;
            }
            else if (ewram[0x160C1] == 1)
            {
                ptr = gUnknown_084006BB;
            }
            else if (ewram[0x160C1] == 2)
            {
                ptr = gUnknown_084006C6;
            }
            else
            {
                ptr = gUnknown_084006D5;
            }
        }
        else
        {
            if (gBattleTypeFlags & BATTLE_TYPE_LINK)
            {
                if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
                {
                    ptr = gUnknown_0840068C;
                }
                else
                {
                    ptr = gUnknown_0840067C;
                }
            }
            else
            {
                ptr = gUnknown_08400622;
            }
        }

        break;

    case 4:
        sub_8121D1C(gUnknown_030041C0);

        if (gSelectedOrderFromParty->var00 > MOVE_PSYCHO_BOOST)
        {
            StringCopy(gUnknown_03004290, gUnknown_08401674[ewram[0x160A0]]);
        }
        else
        {
            StringCopy(gUnknown_03004290, gMoveNames[gSelectedOrderFromParty->var00]);
        }

        sub_8121D74(gUnknown_03004290);
        ptr = gUnknown_084007BD;
        break;

    case 5:
        if (gUnknown_030041C0[0] & 0x80)
        {
            gUnknown_030041C0[0] &= ~0x80;

            if (battle_side_get_owner(gUnknown_02024A60) == 1 && gUnknown_030041C0[0] != 3)
            {
                gUnknown_030041C0[0] ^= 3;
            }

            if ((u8) (gUnknown_030041C0[0] - 2) < 2)
            {
                ptr = gUnknown_083FFEFC;
            }
            else
            {
                if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
                {
                    ptr = gUnknown_083FFFF7;
                }
                else
                {
                    ptr = gUnknown_083FFFEA;
                }
            }
        }
        else
        {
            if (battle_side_get_owner(gUnknown_02024A60) == 1 && gUnknown_030041C0[0] != 3)
            {
                gUnknown_030041C0[0] ^= 3;
            }


            if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
            {
                switch (gUnknown_030041C0[0])
                {
                case 1:
                    ptr = gUnknown_083FFF6A;
                    break;
                case 2:
                    ptr = gUnknown_083FFF99;
                    break;
                case 3:
                    ptr = gUnknown_083FFFCB;
                    break;
                }
            }
            else
            {
                switch (gUnknown_030041C0[0])
                {
                case 1:
                    ptr = gUnknown_083FFF56;
                    break;
                case 2:
                    ptr = gUnknown_083FFF81;
                    break;
                case 3:
                    ptr = gUnknown_083FFFB3;
                    break;
                }
            }
        }

        break;

    default:
        if (arg0 > BATTLE_TEXT_NoEffectOn)
        {
            gUnknown_020238CC[0] = EOS;
            return;
        }

        ptr = gUnknown_08400F8C[arg0 - 12];
        break;
    }

    get_battle_strings_(ptr);
}


u8* get_battle_strings_(const u8 * arg0) {
    return sub_8120FFC(arg0, gUnknown_020238CC);
}


#ifdef NONMATCHING
const u8 *sub_8120F98(u8 *arg0) {
    u32 i;

    u8 sp[8] = {EOS, EOS, EOS, EOS, EOS, EOS, EOS, EOS};

    for (i = 0; i < 8; i++)
    {
        if (arg0[i] == EOS)
        {
            break;
        }

        sp[i] = arg0[i];
    }

    for (i = 0; i < 7; i++)
    {
        const struct UnkStructBattle unkStructBattle = gUnknown_081FA6D4[i];

        if (((u32 *) *(unkStructBattle.jpnText))[0] == ((u32 *) sp)[0] &&
            ((u32 *) *(unkStructBattle.jpnText))[1] == ((u32 *) sp)[1])
        {
            return *(unkStructBattle.battleText);
        }

    }

    return NULL;
}
#endif

#ifdef NONMATCHING
int sub_8120FFC(const u8 *msg, u8 *buffer) {
    u8 multiplayerId = GetMultiplayerId();

    int index = 0;

    int i = 0;
    while (msg[i] != EOS)
    {
        if (msg[i] != 0xFD)
        {
            buffer[index] = msg[i];
            index += 1;
            i += 1;

            continue;
        }

        switch (msg[i + 1])
        {
        case 0:
            if(gUnknown_030041C0[0] == 0xFD) {
                sub_8121A68(gUnknown_030041C0, gStringVar1);
            } else {
                if(sub_8120F98(gUnknown_030041C0)) {

                }
            }
            break;
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            break;
        case 10:
            break;
        case 11:
            break;
        case 12:
            break;
        case 13:
            break;
        case 14:
            break;
        case 15:
            break;
        case 16:
            break;
        case 17:
            break;
        case 18:
            break;
        case 19:
            break;
        case 20:
            break;
        case 21:
            break;
        case 22:
            break;
        case 23:
            break;
        case 24:
            break;
        case 25:
            break;
        case 26:
            break;
        case 27:
            break;
        case 28:
            break;
        case 29:
            break;
        case 30:
            break;
        case 31:
            break;
        case 32:
            break;
        case 33:
            break;
        case 34:
            break;
        case 35:
            break;
        case 36:
            break;
        case 37:
            break;
        case 38:
            break;
        case 39:
            break;
        case 40:
            break;
        case 41:
            break;
        case 42:
            break;

        }
    }

    buffer[index] = msg[i];

    return index + 1;
}
#endif

asm(".section .text.sub_8121A68");

void sub_8121A68(u8 *r0, u8 *r1) {
    int i = 1;
    u8 buffer[12];
    u32 arg;

    arg = 0;
    r1[0] = EOS;


    while (r0[i] != EOS)
    {
        switch (r0[i])
        {
        case 0:
        {
            int arg = r0[i + 1] | (r0[i + 2] << 8);
#if GERMAN
            if (arg == 0xD1 || arg == 0xD3)
            {
                i += 3;
            }
#endif

            StringAppend(r1, gUnknown_08400F8C[arg - 12]);
            i += 3;
            break;
        }

        case 1:
        {
            switch (r0[i + 1])
            {
            case 1:
                arg = r0[i + 3];
                break;
            case 2:
                arg = r0[i + 3] | (r0[i + 4] << 8);
                break;
            case 4:
                arg = r0[i + 3] | (r0[i + 4] << 8) | (r0[i + 5] << 16) | (r0[i + 6] << 24);
                break;
            }

            ConvertIntToDecimalStringN(r1, arg, STR_CONV_MODE_LEFT_ALIGN, r0[i + 2]);
            i += 3 + r0[i + 1];
            break;
        }

        case 2:
        {
            u16 arg = r0[i + 1] | (r0[i + 2] << 8);

            StringAppend(r1, gMoveNames[arg]);
            i += 3;
            break;
        }

        case 3:
        {
            StringAppend(r1, gTypeNames[r0[i + 1]]);
            i += 2;
            break;
        }

        case 4:
        {

            if (battle_side_get_owner(r0[i + 1]) == 0)
            {
                GetMonData(&gPlayerParty[r0[i + 2]], MON_DATA_NICKNAME, buffer);
            }
            else
            {
                if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
                {
                    StringAppend(r1, gUnknown_08400797);
                }
                else
                {
                    StringAppend(r1, gUnknown_08400791);
                }

                GetMonData(&gEnemyParty[r0[i + 2]], MON_DATA_NICKNAME, buffer);
            }

            StringGetEnd10(buffer);
            StringAppend(r1, buffer);
            i += 3;
            break;
        }

        case 5:
        {
            StringAppend(r1, gUnknown_08400F58[r0[i + 1]]);
            i += 2;
            break;
        }

        case 6:
        {
            u16 species = r0[i + 1] | (r0[i + 2] << 8);
            GetSpeciesName(r1, species);
            i += 3;
            break;
        }

        case 7:
        {
            if (battle_side_get_owner(r0[i + 1]) == 0)
            {
                GetMonData(&gPlayerParty[r0[i + 2]], MON_DATA_NICKNAME, r1);
            }
            else
            {
                GetMonData(&gEnemyParty[r0[i + 2]], MON_DATA_NICKNAME, r1);
            }

            StringGetEnd10(r1);
            i += 3;
            break;
        }

        case 8:
        {
            StringAppend(r1, gUnknown_08400F78[r0[i + 1]]);
            i += 2;
            break;
        }

        case 9:
        {
            StringAppend(r1, gAbilityNames[r0[i + 1]]);
            i += 2;
            break;
        }

        case 10:
        {
            int itemId = r0[i + 1] | (r0[i + 2] << 8);

            if (gBattleTypeFlags & BATTLE_TYPE_LINK)
            {
                if (itemId == ITEM_ENIGMA_BERRY)
                {
                    if (gLinkPlayers[ewram160CB].lp_field_18 == gUnknown_02024C0B)
                    {
                        StringCopy(r1, gEnigmaBerries[gUnknown_02024C0B].name);
                        StringAppend(r1, gUnknown_08400A85);
                    }
                    else
                    {
                        StringAppend(r1, gUnknown_08400A78);
                    }
                }
                else
                {
                    CopyItemName(itemId, r1);
                }
            }
            else
            {
                CopyItemName(itemId, r1);
            }


            i += 3;
            break;
        }
        }
    }
}
asm("\t.align 2, 0\n");

#ifdef NONMATCHING

struct UnkStruct1 {
    /*0x00*/ u16 unk0;
};

extern struct UnkStruct1 *gSelectedOrderFromParty;

void sub_8121D1C(u8 *arg0) {
    int i = 0;
    u16 *ptr;

    ptr = (u16 *) gUnknown_084016BC;
    while (i != 4)
    {
        u16 val = *ptr;
        if (val == 0)
        {
            i += 1;
        }

        if (*ptr++ == gSelectedOrderFromParty->unk0)
        {
            break;
        }
    }

    switch (i)
    {
    case 0:
    case 1:
    case 2:
        StringCopy(arg0, gUnknown_08400E5E);
        break;

    case 3:
    case 4:
        StringCopy(arg0, gUnknown_08400E62);
        break;
    }
}


void sub_8121D74(u8 *dstPtr) {
    u16 *ptr;

    int i=0;

    while (*dstPtr != EOS)
    {
        dstPtr++;
    }

    ptr = (u16 *) gUnknown_084016BC;
    while (i != 4)
    {
        u16 val = *ptr;
        if (val == 0)
        {
            i += 1;
        }

        if (*ptr++ == gSelectedOrderFromParty->unk0)
        {
            break;
        }
    }

    switch (i)
    {
    case 0:
        StringCopy(dstPtr, gUnknown_084007C8);
        break;

    case 1:
        StringCopy(dstPtr, gUnknown_084007CA);
        break;

    case 2:
        StringCopy(dstPtr, gUnknown_084007CC);
        break;

    case 3:
        StringCopy(dstPtr, gUnknown_084007CE);
        break;

    case 4:
        StringCopy(dstPtr, gUnknown_084007D0);
        break;
    }
}
#endif
