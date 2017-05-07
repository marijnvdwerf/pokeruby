#include "global.h"
#include "menu.h"
#include "string_util.h"

struct StorageAction {
    u8 *text;
    u8 unk4;
};

extern const struct StorageAction gUnknown_083B6DF4[];

extern const u8 unk_2000000[];

#define gUnk2002694 (u8 *)(&unk_2000000[0x2694])
#define gUnk20011fa (u8 *)(&unk_2000000[0x11fa])
#define gUnk20026e4 (u8 *)(&unk_2000000[0x26e4])

#ifdef NONMATCHING
void sub_8098898(u8 arg0) {
    u8 *ptr;

    MenuDrawTextWindow(10, 16, 29, 19);

    switch (gUnknown_083B6DF4[arg0].unk4)
    {

    case 2:
        ptr = StringCopy(gUnk2002694, gUnknown_083B6DF4[arg0].text);
        ptr = StringCopy(ptr, gUnk20011fa);
        break;

    case 5:
        ptr = StringCopy(gUnk2002694, gUnknown_083B6DF4[arg0].text);
        ptr = StringCopy(ptr, gUnk20011fa);
        break;

    case 1:
        // {var} + " is selected."
        ptr = StringCopy(gUnk2002694, gUnk20011fa);
        ptr = StringCopy(ptr, gUnknown_083B6DF4[arg0].text);
        break;

    case 4:
        // {var} + " was released."
        ptr = StringCopy(gUnk2002694, gUnk20026e4);
        ptr = StringCopy(ptr, gUnknown_083B6DF4[arg0].text);
        break;

    case 3:
    {
        u8 *stringLength;
        u8 *text;

        text = gUnknown_083B6DF4[arg0].text;
        stringLength = &text[StringLength(text)] + 1;

        ptr = StringCopy(gUnk2002694, gUnknown_083B6DF4[arg0].text);
        ptr = StringCopy(ptr, gUnk20011fa);
        ptr = StringCopy(ptr, stringLength);
    }
        break;

    case 6:
        // "Bye-bye, !".substr(-1) + {var} + "Bye-bye, !".last()
    {
        u8 *stringLength;
        u8 *text;

        text = gUnknown_083B6DF4[arg0].text;
        stringLength = &text[StringLength(text)] - 1;

        ptr = StringCopy(gUnk2002694, gUnknown_083B6DF4[arg0].text);
        ptr = StringCopy(ptr - 1, gUnk20026e4);
        ptr = StringCopy(ptr, stringLength);
    }
        break;

    case 0:
    default:
        ptr = StringCopy(gUnk2002694, gUnknown_083B6DF4[arg0].text);
        break;
    }

    while (ptr != &unk_2000000[0x2694+18])
    {
            ptr[0] = CHAR_SPACE;
            ptr++;
    }

    ptr[0] = EOS;
    MenuPrint(gUnk2002694, 11, 17);
}
#endif