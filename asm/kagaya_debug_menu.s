	.include "constants/gba_constants.inc"
	.include "constants/species_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start InitKagayaDebugMenu_A
InitKagayaDebugMenu_A:
	.fill 12
	thumb_func_end InitKagayaDebugMenu_A

	thumb_func_start InitKagayaDebugMenu_B
InitKagayaDebugMenu_B:
	.fill 76
	thumb_func_end InitKagayaDebugMenu_B

	thumb_func_start debug_sub_80B061C
debug_sub_80B061C:
	.fill 68
	thumb_func_end debug_sub_80B061C

	thumb_func_start KagayaDebugMenu_TrainerCard
KagayaDebugMenu_TrainerCard:
	.fill 44
	thumb_func_end KagayaDebugMenu_TrainerCard

	thumb_func_start debug_sub_80B068C
debug_sub_80B068C:
	.fill 40
	thumb_func_end debug_sub_80B068C

	thumb_func_start KagayaDebugMenu_CardToExchange
KagayaDebugMenu_CardToExchange:
	.fill 44
	thumb_func_end KagayaDebugMenu_CardToExchange

	thumb_func_start debug_sub_80B06E0
debug_sub_80B06E0:
	.fill 40
	thumb_func_end debug_sub_80B06E0

	thumb_func_start KagayaDebugMenu_SlotMachine
KagayaDebugMenu_SlotMachine:
	.fill 44
	thumb_func_end KagayaDebugMenu_SlotMachine

	thumb_func_start Kagaya_80B0734
Kagaya_80B0734:
	.fill 60
	thumb_func_end Kagaya_80B0734

	thumb_func_start debug_sub_80B0770
debug_sub_80B0770:
	.fill 64
	thumb_func_end debug_sub_80B0770

	thumb_func_start debug_sub_80B07B0
debug_sub_80B07B0:
	.fill 44
	thumb_func_end debug_sub_80B07B0

	thumb_func_start debug_sub_80B07DC
debug_sub_80B07DC:
	.fill 36
	thumb_func_end debug_sub_80B07DC

	thumb_func_start debug_sub_80B0800
debug_sub_80B0800:
	.fill 44
	thumb_func_end debug_sub_80B0800

	.align 2, 0 @ Don't pad with nop.
