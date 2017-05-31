#include "global.h"
#include "battle_message.h"
#include "battle.h"
#include "battle_setup.h"
#include "battle_tower.h"
#include "data2.h"
#include "flags.h"
#include "item.h"
#include "items.h"
#include "link.h"
#include "moves.h"
#include "opponent_constants.h"
#include "rom_8077ABC.h"
#include "string_util.h"
#include "text.h"

extern struct SecretBaseRecord gSecretBaseRecord;


extern u8 gPlayerMonIndex;
extern u8 gUnknown_03004290[];

extern u8 gUnknown_02024C0B;

extern struct BattleEnigmaBerry gEnigmaBerries[];

extern u16 gBattleTypeFlags;
extern u8 gUnknown_02024C0A;

// data/battle_message.s
extern const u8 *gUnknown_08400F58[];
extern const u8 *gUnknown_08400F8C[];

extern u8 gUnknown_020238CC[];


extern u8 ewram[];
#define ewram160CB (ewram[0x160CB])

extern u8 gUnknown_030041C0[];

// <editor-fold desc="Description">
extern const u8 gUnknown_083FEE5D[];
extern const u8 gUnknown_083FEE92[];
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
extern const u8 gUnknown_084007BD[];
extern const u8 gUnknown_08400CA8[];
extern const u8 gUnknown_08400CBB[];
extern const u8 gUnknown_08400CF3[];
extern const u8 gUnknown_08400D15[];
extern const u8 gBadEggNickname[];
extern const u8 BattleText_Wally[];
extern const u8 BattleText_Win[];
extern const u8 BattleText_Loss[];
extern const u8 BattleText_Tie[];
extern const u8 *gUnknown_08401674[];
// </editor-fold>

struct UnkStructA {
    u16 var00;
    u16 var02;
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

void sub_8121A68(u8 *r0, u8 *r1);



struct UnkStructBattle {
    const u8 (*jpnText)[8];
    const u8 (*battleText)[];
};

extern const struct UnkStructBattle gUnknown_081FA6D4[];

#if GERMAN
const u8 *de_sub_804110C(u16 arg0, const u8 * arg1) {
    return arg1;
}
#endif

#if ENGLISH
#define FILTER_STR(arg0, arg1) arg1
#elif GERMAN
#define FILTER_STR(arg0, arg1) de_sub_804110C(arg0, arg1)
#endif

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
                ptr = FILTER_STR(-1, ptr);
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
                    ptr = FILTER_STR(-1, ptr);
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
                    ptr = FILTER_STR(-1, ptr);
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

            if (gTrainerBattleOpponent == OPPONENT_800)
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
                ptr = FILTER_STR(-1, ptr);
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
                ptr = FILTER_STR(-1, ptr);
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
        ptr = FILTER_STR(arg0, ptr);
        break;
    }

    get_battle_strings_(ptr);
}

int get_battle_strings_(const u8 *arg0) {
    return sub_8120FFC(arg0, gUnknown_020238CC);
}

const u8 *sub_8120F98(u8 *arg0) {
    u32 i;
    u8 *sp2;
    u32 i1, i2;

    u8 sp[8] = {EOS, EOS, EOS, EOS, EOS, EOS, EOS, EOS};

    sp2 = sp;
    i = 0;
    while (i < 8 && *arg0 != EOS)
    {
        *sp2 = *arg0;
        arg0++;
        sp2++;
        i++;
    }

    i1 = ((u32 *) sp)[0];
    i2 = ((u32 *) sp)[1];
    for (i = 0; i < 7; i++)
    {
        const struct UnkStructBattle *unkStructBattle = &gUnknown_081FA6D4[i];

        if (i1 == ((u32 *) *(unkStructBattle->jpnText))[0] &&
            i2 == ((u32 *) *(unkStructBattle->jpnText))[1])
        {
            return *(unkStructBattle->battleText);
        }

    }

    return NULL;
}
