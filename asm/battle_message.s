	.include "constants/gba_constants.inc"
	.include "constants/species_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_8121A68
sub_8121A68: @ 8121A68
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0xC
	adds r7, r0, 0
	adds r6, r1, 0
	movs r5, 0x1
	movs r0, 0
	mov r8, r0
	movs r0, 0xFF
	strb r0, [r6]
	ldrb r0, [r7, 0x1]
	cmp r0, 0xFF
	bne _08121A86
	b _08121D0E
_08121A86:
	adds r0, r7, r5
	ldrb r1, [r0]
	adds r2, r0, 0
	cmp r1, 0xA
	bls _08121A92
	b _08121D04
_08121A92:
	lsls r0, r1, 2
	ldr r1, _08121A9C @ =_08121AA0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08121A9C: .4byte _08121AA0
	.align 2, 0
_08121AA0:
	.4byte _08121ACC
	.4byte _08121AE8
	.4byte _08121B3C
	.4byte _08121B54
	.4byte _08121B64
	.4byte _08121BDC
	.4byte _08121BF0
	.4byte _08121C02
	.4byte _08121C48
	.4byte _08121C5C
	.4byte _08121C78
_08121ACC:
	adds r0, r5, r7
	ldrb r2, [r0, 0x1]
	ldrb r0, [r0, 0x2]
	lsls r0, 8
	orrs r2, r0
	cmp r2, 0xD1
	beq _08de121ADA
	cmp r2, 0xD3
	bne _08de121ADC
_08de121ADA:
	adds r5, 0x3
_08de121ADC:
	ldr r0, _08121AE4 @ =gUnknown_08400F8C
	adds r1, r2, 0
	subs r1, 0xC
	lsls r1, 2
	adds r1, r0
	ldr r1, [r1]
	b _08121CE2
	.align 2, 0
_08121AE4: .4byte gUnknown_08400F8C
_08121AE8:
	adds r1, r2, 0
	ldrb r0, [r1, 0x1]
	cmp r0, 0x2
	beq _08121B04
	cmp r0, 0x2
	bgt _08121AF8
	cmp r0, 0x1
	beq _08121AFE
	b _08121B26
_08121AF8:
	cmp r0, 0x4
	beq _08121B0C
	b _08121B26
_08121AFE:
	ldrb r1, [r1, 0x3]
	b _08de121B30
_08121B04:
	ldrb r0, [r1, 0x3]
	mov r8, r0
	ldrb r0, [r1, 0x4]
	lsls r0, 8
	mov r1, r8
	b _08121B22
_08121B0C:
	ldrb r0, [r2, 0x3]
	mov r8, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 8
	mov r1, r8
	orrs r1, r0
	ldrb r0, [r2, 0x5]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x6]
	lsls r0, 24
_08121B22:
	orrs r1, r0
_08de121B30:
	mov r8, r1
_08121B26:
	adds r4, r5, r7
	ldrb r3, [r4, 0x2]
	adds r0, r6, 0
	mov r1, r8
	movs r2, 0
	bl ConvertIntToDecimalStringN
	adds r0, r5, 0x3
	ldrb r4, [r4, 0x1]
	adds r5, r0, r4
	b _08121D04
_08121B3C:
	adds r0, r5, r7
	ldrb r1, [r0, 0x1]
	ldrb r0, [r0, 0x2]
	lsls r0, 8
	orrs r1, r0
	movs r0, 0xD
	muls r1, r0
	ldr r0, _08de121B5C @ =gMoveNames
	adds r1, r0
	b _08121CE2
	.align 2, 0
_08de121B5C: .4byte gMoveNames
_08121B54:
	adds r0, r5, r7
	ldrb r0, [r0, 0x1]
	lsls r1, r0, 3
	subs r1, r0
	ldr r0, _08de121B6C @ =gTypeNames
	b _08121C66
	.align 2, 0
_08de121B6C: .4byte gTypeNames
_08121B64:
	adds r4, r5, r7
	ldrb r0, [r4, 0x1]
	bl battle_side_get_owner
	lsls r0, 24
	cmp r0, 0
	bne _08121B88
	ldrb r1, [r4, 0x2]
	movs r0, 0x64
	muls r0, r1
	ldr r1, _08121B84 @ =gPlayerParty
	adds r0, r1
	movs r1, 0x2
	mov r2, sp
	bl GetMonData
	mov r0, sp
	bl StringGetEnd10
	adds r0, r6, 0
	mov r1, sp
	bl StringAppend
	b _08121D02
	.align 2, 0
_08121B84: .4byte gPlayerParty
_08121B88:
	ldrb r1, [r4, 0x2]
	movs r0, 0x64
	muls r0, r1
	ldr r1, _08de121BD4 @ =gEnemyParty
	adds r0, r1
	movs r1, 0x2
	mov r2, sp
	bl GetMonData
	mov r0, sp
	bl StringGetEnd10
	adds r0, r6, 0
	mov r1, sp
	bl StringAppend
	ldr r0, _08121BA0 @ =gBattleTypeFlags
	ldrh r1, [r0]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _08121BA8
	ldr r1, _08121BA4 @ =gUnknown_08400797
	b _08121CE2
	.align 2, 0
_08de121BD4: .4byte gEnemyParty
_08121BA0: .4byte gBattleTypeFlags
_08121BA4: .4byte gUnknown_08400797
_08121BA8:
	ldr r1, _08121BD4 @ =gUnknown_08400791
	adds r0, r6, 0
	bl StringAppend
	b _08121D02
	.align 2, 0
_08121BD4: .4byte gUnknown_08400791
_08121BDC:
	ldr r1, _08121BEC @ =gUnknown_08400F58
	adds r0, r5, r7
	ldrb r0, [r0, 0x1]
	lsls r0, 2
	adds r0, r1
	ldr r1, [r0]
	b _08121C68
	.align 2, 0
_08121BEC: .4byte gUnknown_08400F58
_08121BF0:
	adds r0, r5, r7
	ldrb r1, [r0, 0x1]
	ldrb r0, [r0, 0x2]
	lsls r0, 8
	orrs r1, r0
	adds r0, r6, 0
	bl GetSpeciesName
	b _08121D02
_08121C02:
	adds r4, r5, r7
	ldrb r0, [r4, 0x1]
	bl battle_side_get_owner
	lsls r0, 24
	cmp r0, 0
	bne _08121C28
	ldrb r1, [r4, 0x2]
	movs r0, 0x64
	muls r0, r1
	ldr r1, _08121C24 @ =gPlayerParty
	adds r0, r1
	movs r1, 0x2
	adds r2, r6, 0
	bl GetMonData
	b _08121C3A
	.align 2, 0
_08121C24: .4byte gPlayerParty
_08121C28:
	ldrb r1, [r4, 0x2]
	movs r0, 0x64
	muls r0, r1
	ldr r1, _08121C44 @ =gEnemyParty
	adds r0, r1
	movs r1, 0x2
	adds r2, r6, 0
	bl GetMonData
_08121C3A:
	adds r0, r6, 0
	bl StringGetEnd10
	b _08121D02
	.align 2, 0
_08121C44: .4byte gEnemyParty
_08121C48:
	ldr r1, _08121C58 @ =gUnknown_08400F78
	adds r0, r5, r7
	ldrb r0, [r0, 0x1]
	lsls r0, 2
	adds r0, r1
	ldr r1, [r0]
	b _08121C68
	.align 2, 0
_08121C58: .4byte gUnknown_08400F78
_08121C5C:
	adds r0, r5, r7
	ldrb r1, [r0, 0x1]
	movs r0, 0xD
	muls r1, r0
	ldr r0, _08121C74 @ =gAbilityNames
_08121C66:
	adds r1, r0
_08121C68:
	adds r0, r6, 0
	bl StringAppend
	adds r5, 0x2
	b _08121D04
	.align 2, 0
_08121C74: .4byte gAbilityNames
_08121C78:
	adds r0, r5, r7
	ldrb r2, [r0, 0x1]
	ldrb r0, [r0, 0x2]
	lsls r0, 8
	orrs r2, r0
	ldr r0, _08121CC4 @ =gBattleTypeFlags
	ldrh r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08121CFA
	cmp r2, 0xAF
	bne _08121CF0
	ldr r2, _08121CC8 @ =gLinkPlayers
	ldr r0, _08121CCC @ =0x02000000
	ldr r1, _08121CD0 @ =0x000160cb
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r0, r2
	ldr r1, _08121CD4 @ =gUnknown_02024C0B
	ldrb r2, [r1]
	ldrh r0, [r0, 0x18]
	cmp r0, r2
	bne _08121CE0
	lsls r1, r2, 3
	subs r1, r2
	lsls r1, 2
	ldr r0, _08121CD8 @ =gEnigmaBerries
	adds r1, r0
	adds r0, r6, 0
	bl StringCopy
	ldr r1, _08121CDC @ =gUnknown_08400A85
	adds r0, r6, 0
	bl de_sub_8073174
	b _08121D02
	.align 2, 0
_08121CC4: .4byte gBattleTypeFlags
_08121CC8: .4byte gLinkPlayers
_08121CCC: .4byte 0x02000000
_08121CD0: .4byte 0x000160cb
_08121CD4: .4byte gUnknown_02024C0B
_08121CD8: .4byte gEnigmaBerries
_08121CDC: .4byte gUnknown_08400A85
_08121CE0:
	ldr r1, _08121CEC @ =gUnknown_08400A78
_08121CE2:
	adds r0, r6, 0
	bl StringAppend
	b _08121D02
	.align 2, 0
_08121CEC: .4byte gUnknown_08400A78
_08121CF0:
	adds r0, r2, 0
	adds r1, r6, 0
	bl CopyItemName
	b _08121D02
_08121CFA:
	adds r0, r2, 0
	adds r1, r6, 0
	bl CopyItemName
_08121D02:
	adds r5, 0x3
_08121D04:
	adds r0, r7, r5
	ldrb r0, [r0]
	cmp r0, 0xFF
	beq _08121D0E
	b _08121A86
_08121D0E:
	add sp, 0xC
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8121A68

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
