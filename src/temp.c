#include "global.h"
#include "link.h"
#include "string_util.h"
#include "menu.h"
#include "sprite.h"
#include "main.h"
#include "item.h"
#include "task.h"

struct UnkStruct_Sub {
    u8 filler00[16];
};

struct UnkStruct {
    /*0x00*/ u8 unk00;
    /*0x01*/ u8 filler01[79];
    /*0x50*/ u8 unk50[4];
    /*0x54*/ u8 filler54[6];
    /*0x5A*/ u16 unk5A;
    /*0x5C*/ u8 filler5C[36];
    /*0x80*/ u16 unk80[4];
    /*0x88*/ u8 unk88;
    /*0x89*/ u8 filler89[34];
    /*0xAB*/ u8 unkAB[129];
    /*0x12C*/ u32 unk12C;
    /*0x130*/ s32 unk130;
    /*0x134*/ u8 filler134[48];
    /*0x164*/ u8 unk164[4];
    /*0x168*/ u8 filler168[20];
    /*0x17C*/ u8 unk17C[2];
    /*0x17C*/ u8 unk17E[4][16];

};

extern u8 gUnknown_03004834;

extern struct UnkStruct *gUnknown_03004854;

// data/berry_blender.o
extern u8 *gUnknown_082162B8[];
extern const u8 gUnknown_082165E9[5];
extern const u8 gUnknown_082165EE[5];

// data/strings2.o
extern const u8 gMultiText_BerryBlenderMaxSpeedRecord[];
extern const u8 gMultiText_2P3P4P[];

extern const u8 gOtherText_ResultsOfBlending[];
extern const u8 gOtherText_Berry[];
extern const u8 gOtherText_RequiredTime[];
extern const u8 gOtherText_Min[];
extern const u8 gOtherText_Sec[];
extern const u8 gOtherText_MaxSpeed[];
extern const u8 gOtherText_RPM[];

#define CHAR_PERIOD 0xAD

void sub_8050760(void);

void sub_8052BD0(u8 taskId);

extern u16 gScriptItemId;

void sub_805201C(struct Pokeblock *arg0, u8 *arg1);

void sub_810CA34(struct Pokeblock *arg0);

void sub_8050520(void *arg0, struct Pokeblock *pokeblock, u8 arg2, u8 *arg3, u16 arg4);

#ifdef NONMATCHING
u8 sub_8051C58(void) {
    switch (gUnknown_03004854->unk00)
    {
    case 0:
        gUnknown_03004854->unk00 += 1;
        gUnknown_03004854->unk130 = 17;
        break;

    case 1:
        gUnknown_03004854->unk130 -= 10;
        if (gUnknown_03004854->unk130 < 0)
        {
            gUnknown_03004854->unk130 = 0;
            gUnknown_03004854->unk00 += 1;
        }
        break;

    case 2:
        gUnknown_03004854->unk130 += 1;
        if (gUnknown_03004854->unk130 > 20)
        {
            u16 i;

            for (i = 0; i < 3; i++)
            {
                DestroySprite(&gSprites[gUnknown_03004854->unk50[i]]);
            }

            gUnknown_03004854->unk130 = 0;
            gUnknown_03004854->unk00 += 1;
        }
        break;

    case 3:
    {
        u8 *ptr;
        u8 buffer[16];
        u8 r9[10];

        u16 value, r4, value2, value3, value4, i;

        MenuDrawTextWindow(4, 2, 25, 17);
        sub_8072BD8((u8 *) gOtherText_ResultsOfBlending, 5, 3, 160);
        // TODO: decompile
        if (gUnknown_03004854->unk88 > 0)
        {
            for (i = 0; i < gUnknown_03004854->unk88; i++)
            {
                u8 *ptr;
                u8 byte = gUnknown_03004854->unk164[i];

                StringCopy(r9, gUnknown_03004854->unk17E[byte]);
                ConvertInternationalString(r9, gLinkPlayers[byte].language);
                StringAppend(r9, gOtherText_Berry);

                ptr = ConvertIntToDecimalString(gUnknown_03004854->unkAB, i + 1);
                ptr[0] = CHAR_SPACE;
                ptr[1] = CHAR_PERIOD;
                ptr[2] = CHAR_PERIOD;
                ptr += 3;

                ptr = sub_8072C74(ptr, gLinkPlayers[byte].name, 88, 0);
                sub_8072C74(ptr, r9, 157, 0);


                MenuPrint(
                        gUnknown_03004854->unkAB,
                        5,
                        gUnknown_082165E9[gUnknown_03004854->unk88] + gUnknown_082165EE[gUnknown_03004854->unk88] * i
                );
            }
        }

        value4 = gUnknown_03004854->unk5A % 100;
        ConvertIntToDecimalStringN(r9, value4, 2, 2);

        ptr = gUnknown_03004854->unkAB;
        ptr = StringCopy(ptr, gOtherText_MaxSpeed);
        MenuPrint(gUnknown_03004854->unkAB, 5, 13);

        value3 = gUnknown_03004854->unk5A / 100;
        ptr = sub_8072C14(ptr, value3, 121, 1);

        ptr[0] = CHAR_SPACE;
        ptr[1] = CHAR_PERIOD;
        ptr[2] = CHAR_PERIOD;
        ptr += 3;

        ptr = sub_8072C74(ptr, r9, 142, 1);
        StringCopy(ptr, gOtherText_RPM);
        MenuPrint(gUnknown_03004854->unkAB, 5, 13);

        r4 = gUnknown_03004854->unk12C / 60;
        value = r4 % 60;
        value2 = r4 / 60;
        ConvertIntToDecimalStringN(r9, value2, 2, 2);
        ConvertIntToDecimalStringN(buffer, value, 2, 2);

        ptr = gUnknown_03004854->unkAB;
        ptr = StringCopy(ptr, gOtherText_RequiredTime);
        ptr = sub_8072C74(ptr, r9, 102, 1);
        ptr = StringAppend(ptr, gOtherText_Min);
        ptr = sub_8072C74(ptr, buffer, 136, 1);
        StringCopy(ptr, gOtherText_Sec);
        MenuPrint(gUnknown_03004854->unkAB, 5, 15);

        gUnknown_03004854->unk130 = 0;
        gUnknown_03004854->unk00 += 1;
    }
        break;

    case 4:
        if (gMain.newKeys & 1)
        {
            gUnknown_03004854->unk00 += 1;
        }
        break;

    case 5:
    {
        struct Pokeblock buffer;
        u8 buffer2[16];
        u16 results[4];
        u16 i;

        MenuZeroFillScreen();
        MenuDrawTextWindow(0, 14, 29, 19);

        for (i = 0; i < 4; i++)
        {
            if (gUnknown_03004854->unk80[i] != 0)
            {
                results[i] = gUnknown_03004854->unk80[i] - 133;
            }
        }
        sub_8050760();
        sub_8050520(gUnknown_03004854->unk17C, &buffer, gUnknown_03004854->unk88, buffer2, gUnknown_03004854->unk5A);
        sub_805201C(&buffer, gUnknown_03004854->unkAB);
        CreateTask(sub_8052BD0, 6);
        MenuPrintMessage(gUnknown_03004854->unkAB, 1, 15);
        RemoveBagItem(gScriptItemId, 1);
        sub_810CA34(&buffer);
        gUnknown_03004854->unk00 += 1;
    }
        break;

    case 6:
        if (MenuUpdateWindowText())
        {
            return TRUE;
        }
        break;
    }

    return FALSE;
}
#endif

#ifdef NONMATCHING
void ShowBerryBlenderRecordWindow(void) {
    int i;
    u8 buffer[32];

    MenuDrawTextWindow(6, 3, 23, 16);
    MenuPrint(gMultiText_BerryBlenderMaxSpeedRecord, 8, 4);
    MenuPrint(gMultiText_2P3P4P, 8, 9);

    for (i = 0; i < 3; i++)
    {
        u32 record;
        u8 *ptr;

        record = gSaveBlock1.berryBlenderRecords[i];

        ptr = sub_8072C14(buffer, record / 100, 18, 1);
        ptr[0] = CHAR_SPACE;
        ptr[1] = CHAR_PERIOD;
        ptr[2] = CHAR_PERIOD;
        ptr += 3;

        ptr = ConvertIntToDecimalStringN(ptr, record % 100, STR_CONV_MODE_LEADING_ZEROS, 2);

        StringAppend(ptr, gOtherText_RPM);
        MenuPrint(buffer, 15, 9 + 2 * i);
    }
}
#endif
