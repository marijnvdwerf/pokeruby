	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

@ 0x842DBD0
	.string "CABLE　CAR　U$"

@ 0x842DBDC
	.string "CABLE　CAR　D$"

@ 0x842DBE8
	.string "ROULETTE1$"

@ 0x842DBF2
	.string "ROULETTE3$"

@ 0x842DBFC
	.string "View　a　MAIL$"

@ 0x842DC08
	.4byte 0x842DBD0, 0x8138D75
	.4byte 0x842DBDC, 0x8138D8D
	.4byte 0x842DBE8, 0x8138C15
	.4byte 0x842DBF2, 0x8138C35
	.4byte 0x842DBFC, 0x810CD9D
