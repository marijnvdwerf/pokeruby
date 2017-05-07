#include "global.h"
#include "text.h"
#include "item.h"
#include "menu.h"

struct UnkStruct {
    /*0x00*/ u8 var00;
    /*0x01*/ u8 var01;
    /*0x02*/ u8 filler02[2];

};
extern u8 gUnknown_02038558;
extern s8 gUnknown_02038559;

extern struct UnkStruct gUnknown_03005D10[];
extern struct BagPocket *gUnknown_03005D24;

void sub_80A4030();

void sub_80A405C();

void sub_80A40AC();

u8 *sub_80A425C(u8, u8 *, u8);

u8 sub_80A42B0(u8, int);

#ifdef NONMATCHING
void sub_80A444C(u16 arg0, u8 arg1, int arg2, int arg3) {
    u8 i;

    i = arg1;
    while (TRUE)
    {
        u8 index;
        u8 top;
        struct Item *item;
        u8 *local3;

        if (i > arg2)
        {
            break;
        }

        if (sub_80A42B0(i, arg3) == TRUE)
        {
            break;
        }

        index = gUnknown_03005D10[gUnknown_02038559].var01 + i;
        top = 2 + i * 2;

        local3 = sub_80A425C(arg0, gStringVar1, i);
        item = ItemId_GetItem(gUnknown_03005D24->itemSlots[index].itemId);
        sub_8072C74(local3, item->name, 96, 0);
        MenuPrint(gStringVar1, 14, top);

        if (gUnknown_02038558)
        {
            if (gUnknown_03005D24->itemSlots[index].itemId == gSaveBlock1.registeredItem)
            {
                sub_80A4030(i);
            }
        }
        else
        {
            if (gUnknown_03005D24->itemSlots[index].itemId == gSaveBlock1.registeredItem)
            {
                sub_80A405C(i);
            }
            else
            {
                sub_80A40AC(i);
            }
        }

        i += 1;
    }
}
#endif