#include "global.h"
#include "battle_message.h"
#include "battle.h"
#include "data2.h"
#include "item.h"
#include "items.h"
#include "link.h"
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
