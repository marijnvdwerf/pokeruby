#include "global.h"
#include "menu_cursor.h"
#include "text.h"

extern u8 gUnknown_020238CC[];
extern u8 gUnknown_02024A60;
extern u8 gUnknown_02024E60[];

extern struct Window gUnknown_03004210;
extern u16 gUnknown_030042A0;
extern u16 gUnknown_030042A4;
extern void *gUnknown_03004330[];

extern u8 BattleText_PlayerMenu[];
extern u8 BattleText_MenuOptionsSafari[];

void bx_battle_menu_t6_2();
void nullsub_8(u8);
void sub_802E3E4();
void get_battle_strings_(u8 *);

void sub_812BB10(void) {
    s32 i;

    gUnknown_030042A4 = 0;
    gUnknown_030042A0 = 160;
    gUnknown_03004210.paletteNum = 0;

    FillWindowRect_DefaultPalette(&gUnknown_03004210, 10, 2, 15, 27, 18);
    FillWindowRect_DefaultPalette(&gUnknown_03004210, 10, 2, 35, 16, 36);

    gUnknown_03004330[gUnknown_02024A60] = (void *) bx_battle_menu_t6_2;
    InitWindow(&gUnknown_03004210, BattleText_MenuOptionsSafari, 400, 18, 35);
    sub_8002F44(&gUnknown_03004210);

    sub_814A5C0(0, 0xFFFF, 12, 11679, 0);

    for (i = 0; i < 4; i++)
    {
        nullsub_8(i);
    }

    sub_802E3E4(gUnknown_02024E60[gUnknown_02024A60], 0);
    get_battle_strings_(BattleText_PlayerMenu);

    InitWindow(&gUnknown_03004210, gUnknown_020238CC, 440, 2, 35);
    sub_8002F44(&gUnknown_03004210);
}
