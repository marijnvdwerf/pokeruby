#include "global.h"
#include "asm.h"
#include "sprite.h"
#include "string_util.h"
#include "text.h"


extern void *gUnknown_0820A804[];
extern void *gUnknown_0820A80C[];
extern void *gUnknown_0820A814[];
extern u8 gUnknown_0820A81C[0x1E];

#define WRITE_CHAR(string, charcode)    \
{                                   \
    *string = charcode;                 \
    string++;                       \
}

#ifdef NONMATCHING
void sub_8043FC0(u8 spriteId, u8 r1) {
    u8 *string;
    u8 owner;
    u8 *src;
    void **destList;
    s32 r4;
    u8 data[30];
    struct Sprite *sprite;

    memcpy(data, gUnknown_0820A81C, sizeof(data));

    if (!IsDoubleBattle())
    {
        owner = battle_side_get_owner(gSprites[spriteId].data6);
        destList = gUnknown_0820A80C;
        if (owner == 0)
        {
            destList = gUnknown_0820A804;
        }
    }
    else
    {
        owner = battle_side_get_owner(gSprites[spriteId].data6);
        destList = gUnknown_0820A80C;
        if (owner == 0)
        {
            destList = gUnknown_0820A814;
        }
    }

    string = data + 6;
    if (r1 == 100)
    {
        string = ConvertIntToDecimalStringN(string, 100, STR_CONV_MODE_LEFT_ALIGN, 3);
    }
    else
    {
        WRITE_CHAR(string, EXT_CTRL_CODE_BEGIN);
        string = data + 7;
        WRITE_CHAR(string, 0x11);
        WRITE_CHAR(string, 0x01);

        WRITE_CHAR(string, EXT_CTRL_CODE_BEGIN);
        WRITE_CHAR(string, 0x14);
        WRITE_CHAR(string, 0x04);

        WRITE_CHAR(string, 0xF0); // :

        WRITE_CHAR(string, EXT_CTRL_CODE_BEGIN);
        WRITE_CHAR(string, 0x14);
        WRITE_CHAR(string, 0x00);

        string = ConvertIntToDecimalStringN(string, r1, STR_CONV_MODE_LEFT_ALIGN, 2);
    }

    WRITE_CHAR(string, EXT_CTRL_CODE_BEGIN);
    WRITE_CHAR(string, 0x13);
    WRITE_CHAR(string, 0x0F);
    *string = EOS;

    sub_80034D4((u8 *) 0x2000000, data);

    // wrong register
    sprite = gSprites;
    sprite += spriteId;
    src = (u8 *) 0x2000020;
    for (r4 = 2; r4 != 0; r4--)
    {
        s32 index = sprite->oam.tileNum;
        CpuSet(src, *destList + index * 32, CPU_SET_32BIT | 8);
        destList++;

        src += 0x40;
    }
}
#endif