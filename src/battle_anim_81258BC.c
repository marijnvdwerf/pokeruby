#include "global.h"
#include "text.h"
#include "menu_cursor.h"

extern struct Window gUnknown_03004210;
extern u8 gUnknown_020238CC[];
extern u8 gUnknown_02024E60[];

extern const u8 gUnknown_08400CBB[];
extern u8 gUnknown_02024A60;
extern const u8 gUnknown_08400D15[];

extern void* gUnknown_03004330[];
extern u16 gUnknown_030042A0;
extern u16 gUnknown_030042A4;

// asm/battle_2.o
void nullsub_8(u8);

//  asm/battle_5.o
void sub_802E3E4(u8, int);

//  asm/battle_message.o
void get_battle_strings_(u8 *);

void bx_battle_menu_t6_2(void);

void sub_812BB10(void) {
    int i;

    gUnknown_030042A4 = 0;
    gUnknown_030042A0 = 160;
    gUnknown_03004210.paletteNum = 0;
    FillWindowRect_DefaultPalette(&gUnknown_03004210, 10, 2, 15, 27, 18);
    FillWindowRect_DefaultPalette(&gUnknown_03004210, 10, 2, 35, 16, 36);
    gUnknown_03004330[gUnknown_02024A60] = bx_battle_menu_t6_2;

    InitWindow(&gUnknown_03004210, gUnknown_08400D15, 400, 18, 35);
    sub_8002F44(&gUnknown_03004210);
    sub_814A5C0(0, 0xFFFF, 12, 11679, 0);

    for (i = 0; i < 4; i++)
    {
        nullsub_8(i);
    }

    sub_802E3E4(gUnknown_02024E60[gUnknown_02024A60], 0);
    get_battle_strings_((u8 *) gUnknown_08400CBB);

    InitWindow(&gUnknown_03004210, gUnknown_020238CC, 440, 2, 35);
    sub_8002F44(&gUnknown_03004210);
}