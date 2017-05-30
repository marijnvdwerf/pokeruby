	.include "constants/gba_constants.inc"
	.include "constants/species_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_8120F98
sub_8120F98: @ 8120F98
	push {r4,r5,lr}
	sub sp, 0x8
	adds r4, r0, 0
	ldr r1, _08120FB0 @ =gUnknown_084017A8
	mov r0, sp
	movs r2, 0x8
	bl memcpy
	mov r2, sp
	movs r3, 0
	b _08120FC0
	.align 2, 0
_08120FB0: .4byte gUnknown_084017A8
_08120FB4:
	strb r1, [r2]
	adds r4, 0x1
	adds r2, 0x1
	adds r3, 0x1
	cmp r3, 0x7
	bhi _08120FC8
_08120FC0:
	ldrb r1, [r4]
	adds r0, r1, 0
	cmp r0, 0xFF
	bne _08120FB4
_08120FC8:
	ldr r5, [sp]
	ldr r4, [sp, 0x4]
	movs r3, 0
	ldr r2, _08120FE4 @ =gUnknown_081FA6D4
_08120FD0:
	ldr r1, [r2]
	ldr r0, [r1]
	cmp r5, r0
	bne _08120FE8
	ldr r0, [r1, 0x4]
	cmp r4, r0
	bne _08120FE8
	ldr r0, [r2, 0x4]
	b _08120FF2
	.align 2, 0
_08120FE4: .4byte gUnknown_081FA6D4
_08120FE8:
	adds r2, 0x8
	adds r3, 0x1
	cmp r3, 0x6
	bls _08120FD0
	movs r0, 0
_08120FF2:
	add sp, 0x8
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8120F98



	.align 2, 0 @ Don't pad with nop.
.section .text_c

	thumb_func_start sub_8121D1C
sub_8121D1C: @ 8121D1C
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r2, 0
	ldr r5, _08121D50 @ =gSelectedOrderFromParty
	ldr r3, _08121D54 @ =gUnknown_084016BC
_08121D26:
	cmp r2, 0x4
	beq _08121D3C
	ldrh r1, [r3]
	cmp r1, 0
	bne _08121D32
	adds r2, 0x1
_08121D32:
	ldr r0, [r5]
	adds r3, 0x2
	ldrh r0, [r0]
	cmp r1, r0
	bne _08121D26
_08121D3C:
	cmp r2, 0
	blt _08121D68
	cmp r2, 0x2
	bgt _08121D5C
	ldr r1, _08121D58 @ =gUnknown_08400E5E
	adds r0, r4, 0
	bl StringCopy
	b _08121D68
	.align 2, 0
_08121D50: .4byte gSelectedOrderFromParty
_08121D54: .4byte gUnknown_084016BC
_08121D58: .4byte gUnknown_08400E5E
_08121D5C:
	cmp r2, 0x4
	bgt _08121D68
	ldr r1, _08121D70 @ =gUnknown_08400E62
	adds r0, r4, 0
	bl StringCopy
_08121D68:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08121D70: .4byte gUnknown_08400E62
	thumb_func_end sub_8121D1C

	thumb_func_start sub_8121D74
sub_8121D74: @ 8121D74
	push {r4,r5,lr}
	adds r3, r0, 0
	movs r4, 0
	b _08121D7E
_08121D7C:
	adds r3, 0x1
_08121D7E:
	ldrb r0, [r3]
	cmp r0, 0xFF
	bne _08121D7C
	ldr r1, _08121DB4 @ =gUnknown_084016BC
	ldr r5, _08121DB8 @ =gSelectedOrderFromParty
	movs r0, 0
	lsls r0, 1
	adds r2, r0, r1
_08121D8E:
	cmp r4, 0x4
	beq _08121DA8
	ldrh r1, [r2]
	cmp r1, 0
	bne _08121D9A
	adds r4, 0x1
_08121D9A:
	ldr r0, [r5]
	adds r2, 0x2
	ldrh r0, [r0]
	cmp r1, r0
	bne _08121D8E
	cmp r4, 0x4
	bhi _08121E04
_08121DA8:
	lsls r0, r4, 2
	ldr r1, _08121DBC @ =_08121DC0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08121DB4: .4byte gUnknown_084016BC
_08121DB8: .4byte gSelectedOrderFromParty
_08121DBC: .4byte _08121DC0
	.align 2, 0
_08121DC0:
	.4byte _08121DD4
	.4byte _08121DDC
	.4byte _08121DE4
	.4byte _08121DEC
	.4byte _08121DFC
_08121DD4:
	ldr r1, _08121DD8 @ =gUnknown_084007C8
	b _08121DEE
	.align 2, 0
_08121DD8: .4byte gUnknown_084007C8
_08121DDC:
	ldr r1, _08121DE0 @ =gUnknown_084007CA
	b _08121DEE
	.align 2, 0
_08121DE0: .4byte gUnknown_084007CA
_08121DE4:
	ldr r1, _08121DE8 @ =gUnknown_084007CC
	b _08121DEE
	.align 2, 0
_08121DE8: .4byte gUnknown_084007CC
_08121DEC:
	ldr r1, _08121DF8 @ =gUnknown_084007CE
_08121DEE:
	adds r0, r3, 0
	bl StringCopy
	b _08121E04
	.align 2, 0
_08121DF8: .4byte gUnknown_084007CE
_08121DFC:
	ldr r1, _08121E0C @ =gUnknown_084007D0
	adds r0, r3, 0
	bl StringCopy
_08121E04:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08121E0C: .4byte gUnknown_084007D0
	thumb_func_end sub_8121D74

	.align 2, 0 @ Don't pad with nop.
