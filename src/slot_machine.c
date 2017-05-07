#include "global.h"
#include "decompress.h"
#include "palette.h"
#include "task.h"

extern struct UnkStruct1 *gUnknown_083ED048[];
extern const u16 gPalette_83EDE24[];

extern const u8 gSlotMachine_Gfx[];
#define SLOTMACHINE_GFX_TILES 233
extern const u16 gUnknown_08E95A18[];

struct UnkStruct2000000 {
    /*0x00*/ u8 filler00[61];
    /*0x3D*/ u8 unk3D;
};

struct UnkStruct1 {
    /*0x00*/ u8 unk00;
    /*0x01*/ u8 unk01;
    /*0x02*/ s16 unk02;
};

extern struct UnkStruct2000000 unk_2000000;

// include
void sub_8104DA4(void);
u8 sub_8105BB4(u8, u8, s16);

void sub_8104CAC(u8 arg0) {
    u8 i;
    struct Task* task;

    sub_8104DA4();

    task = &gTasks[unk_2000000.unk3D];
    task->data[1] = arg0;

    i = 0;
    while (gUnknown_083ED048[arg0][i].unk00 != 0xFF)
    {
        u8 local1;
        local1 = sub_8105BB4(
                gUnknown_083ED048[arg0][i].unk00,
                gUnknown_083ED048[arg0][i].unk01,
                gUnknown_083ED048[arg0][i].unk02
        );
        task->data[4 + i] = local1;
        i += 1;
    }
}

asm(".section .text_c");

void sub_8106448(void) {
    u32 offsetRead, offsetWrite;
    u32 size;

    sub_800D238(gSlotMachine_Gfx, (void *) 0x02010000);

    offsetRead = 0x02010000;
    offsetWrite = BG_VRAM;
    size = SLOTMACHINE_GFX_TILES * 32;
    while (TRUE)
    {
        DmaCopy16(3, offsetRead, (void *) (offsetWrite), 0x1000);
        offsetRead += 0x1000;
        offsetWrite += 0x1000;
        size -= 0x1000;
        if (size <= 0x1000)
        {
            DmaCopy16(3, offsetRead, (void *) (offsetWrite), size);
            break;
        }
    }

    LoadPalette(gUnknown_08E95A18, 0, 160);
    LoadPalette(gPalette_83EDE24, 208, 32);
}
