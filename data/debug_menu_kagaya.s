	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

@ 0x83EBB34
        .string "Trainer’s card$"

@ 0x83EBB43
        .string "Card to exchange$"

@ 0x83EBB54
        .string "Slot machine$"

@ 0x83EBB64
        .align 2
        .4byte 0x83EBB34, 0x80B0661
        .4byte 0x83EBB43, 0x80B06B5
        .4byte 0x83EBB54, 0x80B0709
