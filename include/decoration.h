#ifndef GUARD_DECORATION_H
#define GUARD_DECORATION_H

struct Decoration
{
    /*0x00*/ u8 id;
    /*0x01*/ u8 name[16];
    /*0x00*/ u8 decor_field_11;
    /*0x11*/ u8 decor_field_12;
    /*0x12*/ u8 decor_field_13;
    /*0x14*/ u16 price;
    /*0x18*/ u8 *description;
    /*0x1C*/ void *tiles;
};

#endif // GUARD_DECORATION_H
