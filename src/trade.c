#include "global.h"
#include "sprite.h"
#include "text.h"
#include "menu.h"

struct UnkStructA {
    /*0x00*/ u8 filler00[4];
    /*0x04*/ struct Window unk04;
    /*0x34*/ u8 spriteIds[2][6];
    /*0x40*/ u8 filler40[2];
    /*0x42*/ u8 unk42[4];
    /*0x46*/ u8 filler46[0x34];
    /*0x7A*/ u8 unk7A;
    /*0x7B*/ u8 filler7B[3];
    /*0x7E*/ u16 unk7E;
    /*0x80*/ u8 unk80[4];
    /*0x84*/ u8 unk84;
    /*0x85*/ u8 filler85[67];
    /*0xC8*/ u8 unkC8[1];
};

struct UCoords8 {
    u8 x;
    u8 y;
};

extern struct UnkStructA *gUnknown_03004824;

//  data/strings2.o
extern const u8 gOtherText_Terminator2[];
extern const u8 *gUnknown_0820C14C[];

//  data/trade.o
extern const u16 gTradeMovesBoxTilemap[];
extern const u16 gTradePartyBoxTilemap[];
extern const struct UCoords8 gTradeMonSpriteCoords[];
extern const u8 gUnknown_0820C330[][2];
extern const u8 gUnknown_0820C334[][2][2];
extern const s8 gUnknown_0820C3D1[][2];

//  asm/pokemon_icon.o
void sub_809D62C(struct Sprite *);

//  asm/trade.o
s8 sub_804A2B4(u8 *, int, int);
void sub_804A33C(u8 *buffer, u8 var28, u8 local1);
void sub_804A51C(u8 r0, u8 r1, u8 r2, u8 r3, u8 sp, u8 sp4);
void sub_804A80C(void);
void sub_804A96C(void *, u8, u8, u16 *, u8, u8, u16);
void sub_804ACD8(u8 *, void *, u8);

//  asm/rom_8077ABC.o
void oamt_set_x3A_32(struct Sprite *sprite, void(*callback)(struct Sprite *));
void sub_8078A34(struct Sprite *);

#ifdef NONMATCHING
void sub_8049ED4(u8 arg0) {
    u8 buffer1[40];
    u8 buffer[56];
    u8 monPos;
    u8 player;
    u32 spriteId;

    player = 1;
    if (gUnknown_03004824->unk84 <= 5)
    {
        player = 0;
    }

    monPos = gUnknown_03004824->unk84 % 6;

    switch (gUnknown_03004824->unk80[arg0])
    {

    case 1:
        asm_comment("Case 1");
        if (gUnknown_03004824->unk42[arg0] > 0)
        {
            u8 i;

            for (i = 0; i < gUnknown_03004824->unk42[arg0]; i++)
            {
                gSprites[gUnknown_03004824->spriteIds[player][i]].invisible = TRUE;
            }
        }

        gSprites[gUnknown_03004824->spriteIds[player][monPos]].invisible = FALSE;
        gSprites[gUnknown_03004824->spriteIds[player][monPos]].data0 = 20;
        gSprites[gUnknown_03004824->spriteIds[player][monPos]].data2 = ((gTradeMonSpriteCoords[player * 6].x + gTradeMonSpriteCoords[player * 6 + 1].x) / 2 * 8) + 14;
        gSprites[gUnknown_03004824->spriteIds[player][monPos]].data4 = gTradeMonSpriteCoords[player*6].x * 8 - 12;

        oamt_set_x3A_32(&gSprites[gUnknown_03004824->spriteIds[player][monPos]], sub_809D62C);

        gUnknown_03004824->unk80[arg0] += 1;

        sub_8078A34(&gSprites[gUnknown_03004824->spriteIds[player][monPos]]);
        sub_8072DEC();

        // (struct Window *win, u16 tileNum, u8 left, u8 top, u8 right, u8 bottom);
        FillWindowRect_DefaultPalette(
                &gUnknown_03004824->unk04,
                0,
                gUnknown_0820C330[player][0],
                0,
                gUnknown_0820C330[player][1],
                19
        );
        sub_804A96C(
                gUnknown_03004824->unkC8,
                arg0 * 16 - arg0,
                0,
                (u16 *) gTradePartyBoxTilemap,
                15,
                17,
                0
        );

        if (player == 0)
        {
            sub_804A80C();
        }

        break;

    case 2:
    {
        struct Sprite *sprites = gSprites;

        asm_comment("Case 2");
        spriteId = gUnknown_03004824->spriteIds[player][monPos];
        if (sprites[spriteId].callback == sub_809D62C)
        {
            gUnknown_03004824->unk80[arg0] = 3;
        }
    }
        break;

    case 3:
    {
        s8 width;

        asm_comment("Case 3");

        sub_804A96C(
                gUnknown_03004824->unkC8,
                player * 15,
                0,
                gTradeMovesBoxTilemap,
                15,
                17,
                0
        );

        gSprites[gUnknown_03004824->spriteIds[player][monPos]].pos1.x = ((gTradeMonSpriteCoords[player * 6].x + gTradeMonSpriteCoords[player * 6 + 1].x) / 2 * 8) + 14;
        gSprites[gUnknown_03004824->spriteIds[player][monPos]].pos1.y = gTradeMonSpriteCoords[player * 6].y - 12;
        gSprites[gUnknown_03004824->spriteIds[player][monPos]].pos2.x = 0;
        gSprites[gUnknown_03004824->spriteIds[player][monPos]].pos2.y = 0;

        width = sub_804A2B4(&buffer1[6], player, monPos);

        buffer1[0] = 0xFC;
        buffer1[1] = 0x06;
        buffer1[2] = 0x04;

        buffer1[3] = 0xFC;
        buffer1[4] = 0x11;
        buffer1[5] = (64 - width) / 2;


        sub_8003460(
                &gUnknown_03004824->unk04,
                buffer1,
                gUnknown_03004824->unk7A + player * 192,
                gUnknown_0820C334[player][0][0],
                gUnknown_0820C334[player][0][1]
        );

        sub_804A33C(buffer, player, monPos);
        sub_8003460(
                &gUnknown_03004824->unk04,
                gOtherText_Terminator2,
                gUnknown_03004824->unk7A + player * 192 + 32,
                gUnknown_0820C334[player][1][0],
                gUnknown_0820C334[player][1][1] + 1
        );
        sub_8003460(
                &gUnknown_03004824->unk04,
                buffer,
                gUnknown_03004824->unk7A + player * 192 + 38,
                gUnknown_0820C334[player][1][0],
                gUnknown_0820C334[player][1][1] + 1
        );
        gUnknown_03004824->unk80[arg0] += 1;
    }
        break;

    case 4:
        asm_comment("Case 4");
        // 'Press B to exit'
        sub_804ACD8((u8 *) gUnknown_0820C14C[5], (void *) (VRAM + 0x10000 + gUnknown_03004824->unk7E * 32), 20);

        sub_804A51C(
                arg0,
                monPos,
                gUnknown_0820C3D1[arg0][0] + 4,
                gUnknown_0820C3D1[arg0][1] + 1,
                gUnknown_0820C3D1[arg0][0],
                gUnknown_0820C3D1[arg0][1]
        );

        gUnknown_03004824->unk80[arg0] += 1;
        break;
    }
}
#endif