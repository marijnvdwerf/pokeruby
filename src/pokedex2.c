#include "global.h"
#include "task.h"
#include "palette.h"
#include "main.h"
#include "text.h"
#include "menu.h"
#include "pokedex.h"
#include "sound.h"
#include "strings.h"
#include "event_data.h"

#define CHAR_0 (0xA1)
#define CHAR_PERIOD (0xAD)
#define CHAR_COMMA (0xB8)

#define DECIMAL_SEPERATOR CHAR_PERIOD

u16 NationalPokedexNumToSpecies(u16);

u16 NationalToHoennOrder(u16);

extern IntrCallback gUnknown_03005CEC;
extern u8 gPokedexMenu_Gfx[];
extern u8 gUnknown_08E96BD4[];


struct PokedexEntry {
    /*0x00*/ u8 categoryName[12];
    /*0x0C*/ u16 height; //in decimeters
    /*0x0E*/ u16 weight; //in hectograms
    /*0x10*/ u8 *descriptionPage1;
    /*0x14*/ u8 *descriptionPage2;
    /*0x18*/ u16 unused;
    /*0x1A*/ u16 pokemonScale;
    /*0x1C*/ u16 pokemonOffset;
    /*0x1E*/ u16 trainerScale;
    /*0x20*/ u16 trainerOffset;
};  /*size = 0x24*/

extern struct PokedexEntry gPokedexEntries[];




#ifdef NONMATCHING
void unref_sub_80913A4(u16 r0, u8 left, u8 top) {
    u8 chars[8];
    u8 hundreds, tens;
    bool8 outputted;

    outputted = FALSE;

    hundreds = r0 / 1000;
    if (hundreds == 0)
    {
        chars[0] = CHAR_SPACE;
    }
    else
    {
        chars[0] = CHAR_0 + hundreds;
        outputted = TRUE;
    }

    tens = ((r0 % 1000) / 100);
    if (tens == 0 && !outputted)
    {
        chars[1] = CHAR_SPACE;
    }
    else
    {
        chars[1] = CHAR_0 + tens;
    }

    chars[2] = CHAR_0 + (((r0 % 1000) % 100) / 10);
    chars[3] = DECIMAL_SEPERATOR;
    chars[4] = CHAR_0 + (((r0 % 1000) % 100) % 10);
    chars[5] = EOS;

    MenuPrint(chars, left, top);
}
#endif
