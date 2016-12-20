	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

@ 83CC740
	.include "data/text/berry_descriptions.inc"

@ 83CD2CC
	.include "data/berries.inc"

	.align 2
gBlankBerryTree:: @ 83CD780
	.4byte 0, 0

gUnknown_Debug_083F7F84:: @ 0x83F7F84
    .string "そとから　きた　きのみ$"

gUnknown_Debug_083F7F90:: @ 0x83F7F90
    .string "ただいま　かいはつちゅう$"

gUnknown_Debug_083F7F9D:: @ 0x83F7F9D
    .string "POS:$"

gUnknown_Debug_083F7FA2:: @ 0x83F7FA2
    .string "\n"
    .string "TYPE:$"

gUnknown_Debug_083F7FA9:: @ 0x83F7FA9
    .string "\n"
    .string "GROW:$"

gUnknown_Debug_083F7FB0:: @ 0x83F7FB0
    .string "\n"
    .string "TIME:$"

gUnknown_Debug_083F7FB7:: @ 0x83F7FB7
    .string "\n"
    .string "FCNT:$"

gUnknown_Debug_083F7FBE:: @ 0x83F7FBE
    .string "\n"
    .string "SCNT:$"

gUnknown_Debug_083F7FC5:: @ 0x83F7FC5
    .string "\n"
    .string "HOOK:$"

gUnknown_Debug_083F7FCC:: @ 0x83F7FCC
    .string "\n"
    .string "WBIT:$"

gUnknown_Debug_083F7FD3:: @ 0x83F7FD3
    .string "$"
