	.include "constants/gba_constants.inc"
	.include "constants/species_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start InitKagayaDebugMenu_A
InitKagayaDebugMenu_A:
.syntax divided
	push	{lr}
	bl	InitKagayaDebugMenu_B
	mov	r0, #0x0
	pop	{r1}
	bx	r1
.syntax unified
	thumb_func_end InitKagayaDebugMenu_A

	thumb_func_start InitKagayaDebugMenu_B
InitKagayaDebugMenu_B:
.syntax divided
	push	{lr}
	add	sp, sp, #0xfffffff8
	bl	MenuZeroFillScreen
	mov	r0, #0x0
	mov	r1, #0x0
	mov	r2, #0xe
	mov	r3, #0x7
	bl	MenuDrawTextWindow
	ldr	r3, ._1
	mov	r0, #0x2
	mov	r1, #0x1
	mov	r2, #0x3
	bl	PrintMenuItems
	mov	r0, #0x0
	str	r0, [sp]
	mov	r0, #0xd
	str	r0, [sp, #0x4]
	mov	r0, #0x0
	mov	r1, #0x1
	mov	r2, #0x1
	mov	r3, #0x3
	bl	InitMenu
	ldr	r1, ._1 + 4
	ldr	r0, ._1 + 8
	str	r0, [r1]
	add	sp, sp, #0x8
	pop	{r0}
	bx	r0
._2:
	.align	2, 0
._1:
	.word	gSpriteTemplate_CutGrass+0x48
	.word	gCallback_03004AE8
	.word	debug_sub_80B061C+1
.syntax unified
	thumb_func_end InitKagayaDebugMenu_B

	thumb_func_start debug_sub_80B061C
debug_sub_80B061C:
.syntax divided
	push	{lr}
	bl	ProcessMenuInput
	lsl	r0, r0, #0x18
	asr	r1, r0, #0x18
	mov	r0, #0x2
	neg	r0, r0
	cmp	r1, r0
	bne	._3	@cond_branch
	mov	r0, #0x0
	b	._6
._3:
	mov	r0, #0x1
	neg	r0, r0
	cmp	r1, r0
	beq	._5	@cond_branch
	ldr	r2, ._7
	ldr	r0, ._7 + 4
	lsl	r1, r1, #0x3
	add	r0, r0, #0x4
	add	r1, r1, r0
	ldr	r0, [r1]
	str	r0, [r2]
	mov	r0, #0x0
	b	._6
._8:
	.align	2, 0
._7:
	.word	gCallback_03004AE8
	.word	gSpriteTemplate_CutGrass+0x48
._5:
	bl	CloseMenu
	mov	r0, #0x1
._6:
	pop	{r1}
	bx	r1
.syntax unified
	thumb_func_end debug_sub_80B061C

	thumb_func_start KagayaDebugMenu_TrainerCard
KagayaDebugMenu_TrainerCard:
.syntax divided
	push	{lr}
	add	sp, sp, #0xfffffffc
	mov	r0, #0x1
	neg	r0, r0
	mov	r1, #0x0
	str	r1, [sp]
	mov	r2, #0x0
	mov	r3, #0x10
	bl	BeginNormalPaletteFade
	ldr	r1, ._9
	ldr	r0, ._9 + 4
	str	r0, [r1]
	mov	r0, #0x0
	add	sp, sp, #0x4
	pop	{r1}
	bx	r1
._10:
	.align	2, 0
._9:
	.word	gCallback_03004AE8
	.word	debug_sub_80B068C+1
.syntax unified
	thumb_func_end KagayaDebugMenu_TrainerCard

	thumb_func_start debug_sub_80B068C
debug_sub_80B068C:
.syntax divided
	push	{lr}
	bl	UpdatePaletteFade
	lsl	r0, r0, #0x18
	cmp	r0, #0
	beq	._11	@cond_branch
	mov	r0, #0x0
	b	._12
._11:
	ldr	r0, ._13
	bl	debug_sub_80A0710
	bl	CloseMenu
	bl	ScriptContext2_Enable
	mov	r0, #0x1
._12:
	pop	{r1}
	bx	r1
._14:
	.align	2, 0
._13:
	.word	sub_805469C+1
.syntax unified
	thumb_func_end debug_sub_80B068C

	thumb_func_start KagayaDebugMenu_CardToExchange
KagayaDebugMenu_CardToExchange:
.syntax divided
	push	{lr}
	add	sp, sp, #0xfffffffc
	mov	r0, #0x1
	neg	r0, r0
	mov	r1, #0x0
	str	r1, [sp]
	mov	r2, #0x0
	mov	r3, #0x10
	bl	BeginNormalPaletteFade
	ldr	r1, ._15
	ldr	r0, ._15 + 4
	str	r0, [r1]
	mov	r0, #0x0
	add	sp, sp, #0x4
	pop	{r1}
	bx	r1
._16:
	.align	2, 0
._15:
	.word	gCallback_03004AE8
	.word	debug_sub_80B06E0+1
.syntax unified
	thumb_func_end KagayaDebugMenu_CardToExchange

	thumb_func_start debug_sub_80B06E0
debug_sub_80B06E0:
.syntax divided
	push	{lr}
	bl	UpdatePaletteFade
	lsl	r0, r0, #0x18
	cmp	r0, #0
	beq	._17	@cond_branch
	mov	r0, #0x0
	b	._18
._17:
	ldr	r0, ._19
	bl	debug_sub_80A073C
	bl	CloseMenu
	bl	ScriptContext2_Enable
	mov	r0, #0x1
._18:
	pop	{r1}
	bx	r1
._20:
	.align	2, 0
._19:
	.word	sub_805469C+1
.syntax unified
	thumb_func_end debug_sub_80B06E0

	thumb_func_start KagayaDebugMenu_SlotMachine
KagayaDebugMenu_SlotMachine:
.syntax divided
	push	{lr}
	add	sp, sp, #0xfffffffc
	mov	r0, #0x1
	neg	r0, r0
	mov	r1, #0x0
	str	r1, [sp]
	mov	r2, #0x0
	mov	r3, #0x10
	bl	BeginNormalPaletteFade
	ldr	r1, ._21
	ldr	r0, ._21 + 4
	str	r0, [r1]
	mov	r0, #0x0
	add	sp, sp, #0x4
	pop	{r1}
	bx	r1
._22:
	.align	2, 0
._21:
	.word	gCallback_03004AE8
	.word	Kagaya_80B0734+1
.syntax unified
	thumb_func_end KagayaDebugMenu_SlotMachine

	thumb_func_start Kagaya_80B0734
Kagaya_80B0734:
.syntax divided
	push	{lr}
	bl	UpdatePaletteFade
	lsl	r0, r0, #0x18
	cmp	r0, #0
	beq	._23	@cond_branch
	mov	r0, #0x0
	b	._24
._23:
	bl	Random
	lsl	r0, r0, #0x10
	lsr	r0, r0, #0x10
	mov	r1, #0x6
	bl	gScriptFuncs_End+0x43d0
	lsl	r0, r0, #0x18
	lsr	r0, r0, #0x18
	ldr	r1, ._25
	bl	debug_sub_811609C
	bl	CloseMenu
	bl	ScriptContext2_Enable
	mov	r0, #0x1
._24:
	pop	{r1}
	bx	r1
._26:
	.align	2, 0
._25:
	.word	sub_805469C+1
.syntax unified
	thumb_func_end Kagaya_80B0734

	thumb_func_start debug_sub_80B0770
debug_sub_80B0770:
.syntax divided
	push	{r4, lr}
	ldr	r0, ._30
	ldrb	r1, [r0]
	mov	r0, #0x8
	and	r0, r0, r1
	lsl	r0, r0, #0x18
	lsr	r4, r0, #0x18
	cmp	r4, #0
	bne	._27	@cond_branch
	bl	CloseMenu
	bl	IsPlayerFacingSurfableFishableWater
	lsl	r0, r0, #0x18
	cmp	r0, #0
	beq	._29	@cond_branch
	ldr	r0, ._30 + 4
	str	r4, [r0]
	mov	r0, #0x9
	bl	FieldEffectStart
	b	._29
._31:
	.align	2, 0
._30:
	.word	gPlayerAvatar
	.word	gUnknown_0202FF84
._27:
	bl	CloseMenu
._29:
	mov	r0, #0x1
	pop	{r4}
	pop	{r1}
	bx	r1
.syntax unified
	thumb_func_end debug_sub_80B0770

	thumb_func_start debug_sub_80B07B0
debug_sub_80B07B0:
.syntax divided
	push	{lr}
	add	sp, sp, #0xfffffffc
	mov	r0, #0x1
	neg	r0, r0
	mov	r1, #0x0
	str	r1, [sp]
	mov	r2, #0x0
	mov	r3, #0x10
	bl	BeginNormalPaletteFade
	ldr	r1, ._32
	ldr	r0, ._32 + 4
	str	r0, [r1]
	mov	r0, #0x0
	add	sp, sp, #0x4
	pop	{r1}
	bx	r1
._33:
	.align	2, 0
._32:
	.word	gCallback_03004AE8
	.word	debug_sub_80B07DC+1
.syntax unified
	thumb_func_end debug_sub_80B07B0

	thumb_func_start debug_sub_80B07DC
debug_sub_80B07DC:
.syntax divided
	push	{lr}
	bl	UpdatePaletteFade
	lsl	r0, r0, #0x18
	cmp	r0, #0
	beq	._34	@cond_branch
	mov	r0, #0x0
	b	._35
._34:
	bl	CloseMenu
	ldr	r0, ._36
	bl	SetMainCallback2
	mov	r0, #0x1
._35:
	pop	{r1}
	bx	r1
._37:
	.align	2, 0
._36:
	.word	sub_80FC074+1
.syntax unified
	thumb_func_end debug_sub_80B07DC

	thumb_func_start debug_sub_80B0800
debug_sub_80B0800:
.syntax divided
	push	{lr}
	bl	CloseMenu
	bl	sub_8068F18
	lsl	r0, r0, #0x18
	lsr	r2, r0, #0x18
	cmp	r2, #0
	beq	._38	@cond_branch
	ldr	r0, ._39
	mov	r1, #0x0
	str	r1, [r0]
	sub	r1, r2, #1
	str	r1, [r0, #0x4]
	mov	r0, #0x2c
	bl	FieldEffectStart
._38:
	mov	r0, #0x1
	pop	{r1}
	bx	r1
._40:
	.align	2, 0
._39:
	.word	gUnknown_0202FF84
.syntax unified
	thumb_func_end debug_sub_80B0800

	.align 2, 0 @ Don't pad with nop.
