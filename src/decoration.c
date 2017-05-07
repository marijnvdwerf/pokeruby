#include "global.h"
#include "asm.h"
#include "decoration.h"
#include "menu.h"

extern const struct Decoration gDecorations[];

extern u8 (*gUnknown_020388D0)[1];
extern u8 gUnknown_020388F2;
extern u8 gUnknown_020388F3;
extern u8 gUnknown_020388F4;
extern u8 gUnknown_020388F6;
extern u8 gUnknown_020388D5;

void sub_80FEC94(u8 arg0);
void sub_80FECB8(u8 arg0);
void sub_80FECE0(u8 arg0);

void sub_80FE7EC(u8 arg0)
{
    sub_8072DEC();
    MenuZeroFillWindowRect(0, 0, 29, 19);

    sub_80FEC94(arg0);
    sub_80FECB8(gUnknown_020388F6);

    MenuDrawTextWindow(15, 12, 29, 19);

    sub_80FECE0(gUnknown_020388F2 + gUnknown_020388F4);
    InitMenu(0, 1, 2, gUnknown_020388F3 + 1, gUnknown_020388F2, 13);
}

asm(".section .text_b");

void sub_80FECE0(u8 arg0) {
    sub_8072AB0(gDecorations[*gUnknown_020388D0[arg0]].description, 128, 104, 104, 48, 1);
}
