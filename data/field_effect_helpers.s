	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

@ XXX: Unused? Probably aligned because it's at the beginning of an object file.
	.align 2

@ 0x842E238
	.string "タマゴ$"

@ 0x842E23C
	.string "ガイブ$"

@ 0x842E240
	.string "ENGLISH$"

@ 0x842E248
	.string "TOURNAMENT$"

@ 0x842E253
	.string "　そら　　カードイー$"

@ 0x842E25E
	.string "ポケコッコ$"

@ 0x842E264
	.string "ticket$"

@ 0x842E26B
	.string "{PKMN}$"

@ 0x842E26E
	.string "wrong　{PKMN}$"

@ 0x842E277
	.string "ribbon$"

@ 0x842E27E
	.string "DEX$"

@ 0x842E282
	.string "message$"

@ 0x842E28A
	.string "egg$"

@ 0x842E28E
	.string "RAM　seed$"

@ 0x842E297
	.string "trainer$"

@ 0x842E29F
	.string "clock$"

@ 0x842E2A5
	.string "item$"

@ 0x842E2AA
	.string "goods$"

@ 0x842E2B0
	.string "potion$"

@ 0x842E2B7
	.string "ball$"

@ 0x842E2BC
	.string "cheri　berry$"

@ 0x842E2C8
	.string "TM01$"

@ 0x842E2D0
	.align 2
	.4byte 0x842E264, 0x813C405
	.4byte 0x842E26B, 0x813C811
	.4byte 0x842E26E, 0x813C889
	.4byte 0x842E277, 0x813C431
	.4byte 0x842E27E, 0x813C489
	.4byte 0x842E282, 0x813C45D
	.4byte 0x842E28A, 0x813C741
	.4byte 0x842E28E, 0x813C5B5
	.4byte 0x842E297, 0x813C93D
	.4byte 0x842E29F, 0x813C4B5
	.4byte 0x842E2A5, 0x813C4D5
	.4byte 0x842E2AA, 0x813C501
	.4byte 0x842E2B0, 0x813C581
	.4byte 0x842E2B7, 0x813C58D
	.4byte 0x842E2BC, 0x813C599
	.4byte 0x842E2C8, 0x813C5A5

@ 0x842E350
	.4byte      0x10
	.4byte 0x845DAE1
	.4byte 0x845DDB2
	.4byte 0x845E306
	.4byte 0x845E3E0
	.4byte 0x845E3E0
	.4byte 0x845E402
	.4byte 0x845E402
	.4byte 0x845E422
	.4byte 0x845E422
	.4byte 0x845E443

	.align 1
gUnknown_08401E2C:: @ 8401E2C
	.2byte 0xC, 0x1C, 0x2C

gUnknown_08401E32:: @ 8401E32
	.byte 0, 1, 2, 3

	.align 1
gUnknown_08401E36:: @ 8401E36
	.2byte 4, 4, 4, 16

	.align 2
gUnknown_08401E40:: @ 8401E40
	.4byte sub_81275A0
	.4byte sub_81275C4

	.align 2
gUnknown_08401E48:: @ 8401E48
	.4byte sub_8127DA0
	.4byte sub_8127DD0
	.4byte sub_8127E30

gUnknown_08401E54:: @ 8401E54
	.byte 0, 0, 1, 2, 3

	.align 1
gUnknown_08401E5A:: @ 8401E5A
	.2byte 3, 7
