	.include "constants/gba_constants.inc"
	.include "constants/species_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text
	
	thumb_func_start OpponentHandleGetAttributes
OpponentHandleGetAttributes: @ 8033524
	push {r4-r6,lr}
	sub sp, 0x100
	movs r6, 0
	ldr r1, _08033550 @ =gBattleBufferA
	ldr r0, _08033554 @ =gActiveBank
	ldrb r2, [r0]
	lsls r0, r2, 9
	adds r1, 0x2
	adds r1, r0, r1
	ldrb r0, [r1]
	cmp r0, 0
	bne _0803355C
	ldr r0, _08033558 @ =gBattlePartyID
	lsls r1, r2, 1
	adds r1, r0
	ldrb r0, [r1]
	mov r1, sp
	bl sub_8033598
	adds r6, r0, 0
	b _0803357E
	.align 2, 0
_08033550: .4byte gBattleBufferA
_08033554: .4byte gActiveBank
_08033558: .4byte gBattlePartyID
_0803355C:
	ldrb r4, [r1]
	movs r5, 0
_08033560:
	movs r0, 0x1
	ands r0, r4
	cmp r0, 0
	beq _08033576
	lsls r0, r5, 24
	lsrs r0, 24
	mov r2, sp
	adds r1, r2, r6
	bl sub_8033598
	adds r6, r0
_08033576:
	lsrs r4, 1
	adds r5, 0x1
	cmp r5, 0x5
	ble _08033560
_0803357E:
	lsls r1, r6, 16
	lsrs r1, 16
	movs r0, 0x1
	mov r2, sp
	bl dp01_build_cmdbuf_x1D_1D_numargs_varargs
	bl OpponentBufferExecCompleted
	add sp, 0x100
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end OpponentHandleGetAttributes

	thumb_func_start sub_8033598
sub_8033598: @ 8033598
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x90
	adds r7, r1, 0
	lsls r0, 24
	lsrs r5, r0, 24
	movs r6, 0
	ldr r2, _080335CC @ =gBattleBufferA
	ldr r3, _080335D0 @ =gActiveBank
	ldrb r0, [r3]
	lsls r0, 9
	adds r1, r2, 0x1
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x3B
	bls _080335C2
	bl _08033D2E
_080335C2:
	lsls r0, 2
	ldr r1, _080335D4 @ =_080335D8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080335CC: .4byte gBattleBufferA
_080335D0: .4byte gActiveBank
_080335D4: .4byte _080335D8
	.align 2, 0
_080335D8:
	.4byte _080336C8
	.4byte _080338EC
	.4byte _080338FC
	.4byte _0803390C
	.4byte _08033974
	.4byte _08033974
	.4byte _08033974
	.4byte _08033974
	.4byte _08033990
	.4byte _080339CC
	.4byte _080339CC
	.4byte _080339CC
	.4byte _080339CC
	.4byte _08033D2E
	.4byte _08033D2E
	.4byte _08033D2E
	.4byte _08033D2E
	.4byte _080339E8
	.4byte _080339F8
	.4byte _08033A28
	.4byte _08033A38
	.4byte _08033A48
	.4byte _08033A58
	.4byte _08033A68
	.4byte _08033A78
	.4byte _08033A88
	.4byte _08033A98
	.4byte _08033AA8
	.4byte _08033AB8
	.4byte _08033AC8
	.4byte _08033AD8
	.4byte _08033AE8
	.4byte _08033B38
	.4byte _08033B48
	.4byte _08033B58
	.4byte _08033B68
	.4byte _08033B78
	.4byte _08033B88
	.4byte _08033B98
	.4byte _08033BA8
	.4byte _08033BB8
	.4byte _08033BEC
	.4byte _08033BFC
	.4byte _08033C0C
	.4byte _08033C1C
	.4byte _08033C2C
	.4byte _08033C3C
	.4byte _08033C4C
	.4byte _08033C5C
	.4byte _08033C7C
	.4byte _08033C8C
	.4byte _08033C9C
	.4byte _08033CAC
	.4byte _08033CBC
	.4byte _08033CCC
	.4byte _08033CDC
	.4byte _08033CEC
	.4byte _08033CFC
	.4byte _08033D0C
	.4byte _08033D1C
_080336C8:
	movs r0, 0x64
	adds r4, r5, 0
	muls r4, r0
	ldr r0, _080338DC @ =gEnemyParty
	adds r4, r0
	adds r0, r4, 0
	movs r1, 0xB
	bl GetMonData
	mov r1, sp
	strh r0, [r1]
	adds r0, r4, 0
	movs r1, 0xC
	bl GetMonData
	mov r1, sp
	strh r0, [r1, 0x2E]
	movs r6, 0
	add r0, sp, 0x24
	mov r9, r0
	movs r1, 0x3B
	add r1, sp
	mov r10, r1
	mov r2, sp
	adds r2, 0x2B
	str r2, [sp, 0x80]
	mov r0, sp
	adds r0, 0x2A
	str r0, [sp, 0x7C]
	mov r1, sp
	adds r1, 0x68
	str r1, [sp, 0x8C]
	adds r2, 0x5
	str r2, [sp, 0x84]
	adds r0, 0x12
	str r0, [sp, 0x88]
	mov r8, r4
	add r4, sp, 0xC
_08033714:
	adds r1, r6, 0
	adds r1, 0xD
	mov r0, r8
	bl GetMonData
	strh r0, [r4]
	adds r1, r6, 0
	adds r1, 0x11
	mov r0, r8
	bl GetMonData
	mov r2, r9
	adds r1, r2, r6
	strb r0, [r1]
	adds r4, 0x2
	adds r6, 0x1
	cmp r6, 0x3
	ble _08033714
	movs r0, 0x64
	adds r4, r5, 0
	muls r4, r0
	ldr r0, _080338DC @ =gEnemyParty
	adds r4, r0
	adds r0, r4, 0
	movs r1, 0x15
	bl GetMonData
	mov r1, r10
	strb r0, [r1]
	adds r0, r4, 0
	movs r1, 0x20
	bl GetMonData
	ldr r2, [sp, 0x80]
	strb r0, [r2]
	adds r0, r4, 0
	movs r1, 0x19
	bl GetMonData
	str r0, [sp, 0x44]
	adds r0, r4, 0
	movs r1, 0x27
	bl GetMonData
	mov r3, sp
	movs r5, 0x1F
	ands r0, r5
	ldrb r2, [r3, 0x14]
	movs r1, 0x20
	negs r1, r1
	ands r1, r2
	orrs r1, r0
	strb r1, [r3, 0x14]
	adds r0, r4, 0
	movs r1, 0x28
	bl GetMonData
	mov r3, sp
	movs r6, 0x1F
	ands r0, r6
	lsls r0, 5
	ldrh r2, [r3, 0x14]
	ldr r1, _080338E0 @ =0xfffffc1f
	ands r1, r2
	orrs r1, r0
	strh r1, [r3, 0x14]
	adds r0, r4, 0
	movs r1, 0x29
	bl GetMonData
	mov r3, sp
	ands r0, r5
	lsls r0, 2
	ldrb r2, [r3, 0x15]
	movs r1, 0x7D
	negs r1, r1
	ands r1, r2
	orrs r1, r0
	strb r1, [r3, 0x15]
	adds r0, r4, 0
	movs r1, 0x2A
	bl GetMonData
	movs r1, 0x1F
	ands r1, r0
	lsls r1, 15
	ldr r0, [sp, 0x14]
	ldr r2, _080338E4 @ =0xfff07fff
	ands r0, r2
	orrs r0, r1
	str r0, [sp, 0x14]
	adds r0, r4, 0
	movs r1, 0x2B
	bl GetMonData
	mov r3, sp
	ands r0, r6
	lsls r0, 4
	ldrh r2, [r3, 0x16]
	ldr r1, _080338E8 @ =0xfffffe0f
	ands r1, r2
	orrs r1, r0
	strh r1, [r3, 0x16]
	adds r0, r4, 0
	movs r1, 0x2C
	bl GetMonData
	mov r3, sp
	ands r0, r5
	lsls r0, 1
	ldrb r2, [r3, 0x17]
	movs r1, 0x3F
	negs r1, r1
	ands r1, r2
	orrs r1, r0
	strb r1, [r3, 0x17]
	adds r0, r4, 0
	movs r1, 0
	bl GetMonData
	str r0, [sp, 0x48]
	adds r0, r4, 0
	movs r1, 0x37
	bl GetMonData
	str r0, [sp, 0x4C]
	adds r0, r4, 0
	movs r1, 0x38
	bl GetMonData
	ldr r1, [sp, 0x7C]
	strb r0, [r1]
	adds r0, r4, 0
	movs r1, 0x39
	bl GetMonData
	mov r1, sp
	strh r0, [r1, 0x28]
	adds r0, r4, 0
	movs r1, 0x3A
	bl GetMonData
	mov r1, sp
	strh r0, [r1, 0x2C]
	adds r0, r4, 0
	movs r1, 0x3B
	bl GetMonData
	mov r1, sp
	strh r0, [r1, 0x2]
	adds r0, r4, 0
	movs r1, 0x3C
	bl GetMonData
	mov r1, sp
	strh r0, [r1, 0x4]
	adds r0, r4, 0
	movs r1, 0x3D
	bl GetMonData
	mov r1, sp
	strh r0, [r1, 0x6]
	adds r0, r4, 0
	movs r1, 0x3E
	bl GetMonData
	mov r1, sp
	strh r0, [r1, 0x8]
	adds r0, r4, 0
	movs r1, 0x3F
	bl GetMonData
	mov r1, sp
	strh r0, [r1, 0xA]
	adds r0, r4, 0
	movs r1, 0x2D
	bl GetMonData
	mov r3, sp
	movs r1, 0x1
	ands r0, r1
	lsls r0, 6
	ldrb r2, [r3, 0x17]
	movs r1, 0x41
	negs r1, r1
	ands r1, r2
	orrs r1, r0
	strb r1, [r3, 0x17]
	adds r0, r4, 0
	movs r1, 0x2E
	bl GetMonData
	mov r3, sp
	lsls r0, 7
	ldrb r2, [r3, 0x17]
	movs r1, 0x7F
	ands r1, r2
	orrs r1, r0
	strb r1, [r3, 0x17]
	adds r0, r4, 0
	movs r1, 0x1
	bl GetMonData
	str r0, [sp, 0x54]
	adds r0, r4, 0
	movs r1, 0x2
	ldr r2, [sp, 0x8C]
	bl GetMonData
	ldr r0, [sp, 0x84]
	ldr r1, [sp, 0x8C]
	bl StringCopy10
	adds r0, r4, 0
	movs r1, 0x7
	ldr r2, [sp, 0x88]
	bl GetMonData
	mov r2, sp
	movs r6, 0
_080338CC:
	adds r0, r7, r6
	adds r1, r2, r6
	ldrb r1, [r1]
	strb r1, [r0]
	adds r6, 0x1
	cmp r6, 0x57
	bls _080338CC
	b _08033D2E
	.align 2, 0
_080338DC: .4byte gEnemyParty
_080338E0: .4byte 0xfffffc1f
_080338E4: .4byte 0xfff07fff
_080338E8: .4byte 0xfffffe0f
_080338EC:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _080338F8 @ =gEnemyParty
	adds r0, r1
	movs r1, 0xB
	b _08033C66
	.align 2, 0
_080338F8: .4byte gEnemyParty
_080338FC:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _08033908 @ =gEnemyParty
	adds r0, r1
	movs r1, 0xC
	b _08033C66
	.align 2, 0
_08033908: .4byte gEnemyParty
_0803390C:
	movs r6, 0
	add r2, sp, 0x58
	mov r9, r2
	add r0, sp, 0x60
	mov r10, r0
	movs r0, 0x64
	adds r1, r5, 0
	muls r1, r0
	ldr r0, _08033970 @ =gEnemyParty
	adds r4, r1, r0
	mov r8, r9
_08033922:
	adds r1, r6, 0
	adds r1, 0xD
	adds r0, r4, 0
	bl GetMonData
	mov r1, r8
	strh r0, [r1]
	adds r1, r6, 0
	adds r1, 0x11
	adds r0, r4, 0
	bl GetMonData
	mov r2, r10
	adds r1, r2, r6
	strb r0, [r1]
	movs r0, 0x2
	add r8, r0
	adds r6, 0x1
	cmp r6, 0x3
	ble _08033922
	movs r0, 0x64
	muls r0, r5
	ldr r1, _08033970 @ =gEnemyParty
	adds r0, r1
	movs r1, 0x15
	bl GetMonData
	mov r1, r9
	strb r0, [r1, 0xC]
	mov r2, r9
	movs r6, 0
_08033960:
	adds r0, r7, r6
	adds r1, r2, r6
	ldrb r1, [r1]
	strb r1, [r0]
	adds r6, 0x1
	cmp r6, 0xF
	bls _08033960
	b _08033D2E
	.align 2, 0
_08033970: .4byte gEnemyParty
_08033974:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _0803398C @ =gEnemyParty
	adds r0, r1
	ldrb r1, [r3]
	lsls r1, 9
	adds r2, 0x1
	adds r1, r2
	ldrb r1, [r1]
	adds r1, 0x9
	b _08033C66
	.align 2, 0
_0803398C: .4byte gEnemyParty
_08033990:
	movs r6, 0
	movs r0, 0x64
	adds r4, r5, 0
	muls r4, r0
	ldr r2, _080339C8 @ =gEnemyParty
	mov r8, r2
_0803399C:
	adds r1, r6, 0
	adds r1, 0x11
	mov r2, r8
	adds r0, r4, r2
	bl GetMonData
	adds r1, r7, r6
	strb r0, [r1]
	adds r6, 0x1
	cmp r6, 0x3
	ble _0803399C
	movs r0, 0x64
	muls r0, r5
	ldr r1, _080339C8 @ =gEnemyParty
	adds r0, r1
	movs r1, 0x15
	bl GetMonData
	adds r1, r7, r6
	strb r0, [r1]
	adds r6, 0x1
	b _08033D2E
	.align 2, 0
_080339C8: .4byte gEnemyParty
_080339CC:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _080339E4 @ =gEnemyParty
	adds r0, r1
	ldrb r1, [r3]
	lsls r1, 9
	adds r2, 0x1
	adds r1, r2
	ldrb r1, [r1]
	adds r1, 0x8
	b _08033D26
	.align 2, 0
_080339E4: .4byte gEnemyParty
_080339E8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _080339F4 @ =gEnemyParty
	adds r0, r1
	movs r1, 0x1
	b _08033A02
	.align 2, 0
_080339F4: .4byte gEnemyParty
_080339F8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _08033A24 @ =gEnemyParty
	adds r0, r1
	movs r1, 0x19
_08033A02:
	bl GetMonData
	adds r1, r0, 0
	strb r1, [r7]
	movs r0, 0xFF
	lsls r0, 8
	ands r0, r1
	lsrs r0, 8
	strb r0, [r7, 0x1]
	movs r0, 0xFF
	lsls r0, 16
	ands r0, r1
	lsrs r0, 16
	strb r0, [r7, 0x2]
	movs r6, 0x3
	b _08033D2E
	.align 2, 0
_08033A24: .4byte gEnemyParty
_08033A28:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _08033A34 @ =gEnemyParty
	adds r0, r1
	movs r1, 0x1A
	b _08033D26
	.align 2, 0
_08033A34: .4byte gEnemyParty
_08033A38:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _08033A44 @ =gEnemyParty
	adds r0, r1
	movs r1, 0x1B
	b _08033D26
	.align 2, 0
_08033A44: .4byte gEnemyParty
_08033A48:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _08033A54 @ =gEnemyParty
	adds r0, r1
	movs r1, 0x1C
	b _08033D26
	.align 2, 0
_08033A54: .4byte gEnemyParty
_08033A58:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _08033A64 @ =gEnemyParty
	adds r0, r1
	movs r1, 0x1D
	b _08033D26
	.align 2, 0
_08033A64: .4byte gEnemyParty
_08033A68:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _08033A74 @ =gEnemyParty
	adds r0, r1
	movs r1, 0x1E
	b _08033D26
	.align 2, 0
_08033A74: .4byte gEnemyParty
_08033A78:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _08033A84 @ =gEnemyParty
	adds r0, r1
	movs r1, 0x1F
	b _08033D26
	.align 2, 0
_08033A84: .4byte gEnemyParty
_08033A88:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _08033A94 @ =gEnemyParty
	adds r0, r1
	movs r1, 0x20
	b _08033D26
	.align 2, 0
_08033A94: .4byte gEnemyParty
_08033A98:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _08033AA4 @ =gEnemyParty
	adds r0, r1
	movs r1, 0x22
	b _08033D26
	.align 2, 0
_08033AA4: .4byte gEnemyParty
_08033AA8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _08033AB4 @ =gEnemyParty
	adds r0, r1
	movs r1, 0x23
	b _08033D26
	.align 2, 0
_08033AB4: .4byte gEnemyParty
_08033AB8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _08033AC4 @ =gEnemyParty
	adds r0, r1
	movs r1, 0x24
	b _08033D26
	.align 2, 0
_08033AC4: .4byte gEnemyParty
_08033AC8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _08033AD4 @ =gEnemyParty
	adds r0, r1
	movs r1, 0x25
	b _08033D26
	.align 2, 0
_08033AD4: .4byte gEnemyParty
_08033AD8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _08033AE4 @ =gEnemyParty
	adds r0, r1
	movs r1, 0x26
	b _08033D26
	.align 2, 0
_08033AE4: .4byte gEnemyParty
_08033AE8:
	movs r0, 0x64
	adds r4, r5, 0
	muls r4, r0
	ldr r0, _08033B34 @ =gEnemyParty
	adds r4, r0
	adds r0, r4, 0
	movs r1, 0x27
	bl GetMonData
	strb r0, [r7]
	adds r0, r4, 0
	movs r1, 0x28
	bl GetMonData
	strb r0, [r7, 0x1]
	adds r0, r4, 0
	movs r1, 0x29
	bl GetMonData
	strb r0, [r7, 0x2]
	adds r0, r4, 0
	movs r1, 0x2A
	bl GetMonData
	strb r0, [r7, 0x3]
	adds r0, r4, 0
	movs r1, 0x2B
	bl GetMonData
	strb r0, [r7, 0x4]
	adds r0, r4, 0
	movs r1, 0x2C
	bl GetMonData
	strb r0, [r7, 0x5]
	movs r6, 0x6
	b _08033D2E
	.align 2, 0
_08033B34: .4byte gEnemyParty
_08033B38:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _08033B44 @ =gEnemyParty
	adds r0, r1
	movs r1, 0x27
	b _08033D26
	.align 2, 0
_08033B44: .4byte gEnemyParty
_08033B48:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _08033B54 @ =gEnemyParty
	adds r0, r1
	movs r1, 0x28
	b _08033D26
	.align 2, 0
_08033B54: .4byte gEnemyParty
_08033B58:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _08033B64 @ =gEnemyParty
	adds r0, r1
	movs r1, 0x29
	b _08033D26
	.align 2, 0
_08033B64: .4byte gEnemyParty
_08033B68:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _08033B74 @ =gEnemyParty
	adds r0, r1
	movs r1, 0x2A
	b _08033D26
	.align 2, 0
_08033B74: .4byte gEnemyParty
_08033B78:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _08033B84 @ =gEnemyParty
	adds r0, r1
	movs r1, 0x2B
	b _08033D26
	.align 2, 0
_08033B84: .4byte gEnemyParty
_08033B88:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _08033B94 @ =gEnemyParty
	adds r0, r1
	movs r1, 0x2C
	b _08033D26
	.align 2, 0
_08033B94: .4byte gEnemyParty
_08033B98:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _08033BA4 @ =gEnemyParty
	adds r0, r1
	movs r1, 0
	b _08033BC2
	.align 2, 0
_08033BA4: .4byte gEnemyParty
_08033BA8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _08033BB4 @ =gEnemyParty
	adds r0, r1
	movs r1, 0x9
	b _08033C66
	.align 2, 0
_08033BB4: .4byte gEnemyParty
_08033BB8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _08033BE8 @ =gEnemyParty
	adds r0, r1
	movs r1, 0x37
_08033BC2:
	bl GetMonData
	adds r1, r0, 0
	strb r1, [r7]
	movs r0, 0xFF
	lsls r0, 8
	ands r0, r1
	lsrs r0, 8
	strb r0, [r7, 0x1]
	movs r0, 0xFF
	lsls r0, 16
	ands r0, r1
	lsrs r0, 16
	strb r0, [r7, 0x2]
	lsrs r0, r1, 24
	strb r0, [r7, 0x3]
	movs r6, 0x4
	b _08033D2E
	.align 2, 0
_08033BE8: .4byte gEnemyParty
_08033BEC:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _08033BF8 @ =gEnemyParty
	adds r0, r1
	movs r1, 0x38
	b _08033D26
	.align 2, 0
_08033BF8: .4byte gEnemyParty
_08033BFC:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _08033C08 @ =gEnemyParty
	adds r0, r1
	movs r1, 0x39
	b _08033C66
	.align 2, 0
_08033C08: .4byte gEnemyParty
_08033C0C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _08033C18 @ =gEnemyParty
	adds r0, r1
	movs r1, 0x3A
	b _08033C66
	.align 2, 0
_08033C18: .4byte gEnemyParty
_08033C1C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _08033C28 @ =gEnemyParty
	adds r0, r1
	movs r1, 0x3B
	b _08033C66
	.align 2, 0
_08033C28: .4byte gEnemyParty
_08033C2C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _08033C38 @ =gEnemyParty
	adds r0, r1
	movs r1, 0x3C
	b _08033C66
	.align 2, 0
_08033C38: .4byte gEnemyParty
_08033C3C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _08033C48 @ =gEnemyParty
	adds r0, r1
	movs r1, 0x3D
	b _08033C66
	.align 2, 0
_08033C48: .4byte gEnemyParty
_08033C4C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _08033C58 @ =gEnemyParty
	adds r0, r1
	movs r1, 0x3E
	b _08033C66
	.align 2, 0
_08033C58: .4byte gEnemyParty
_08033C5C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _08033C78 @ =gEnemyParty
	adds r0, r1
	movs r1, 0x3F
_08033C66:
	bl GetMonData
	lsls r0, 16
	lsrs r0, 16
	strb r0, [r7]
	lsrs r0, 8
	strb r0, [r7, 0x1]
	movs r6, 0x2
	b _08033D2E
	.align 2, 0
_08033C78: .4byte gEnemyParty
_08033C7C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _08033C88 @ =gEnemyParty
	adds r0, r1
	movs r1, 0x16
	b _08033D26
	.align 2, 0
_08033C88: .4byte gEnemyParty
_08033C8C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _08033C98 @ =gEnemyParty
	adds r0, r1
	movs r1, 0x17
	b _08033D26
	.align 2, 0
_08033C98: .4byte gEnemyParty
_08033C9C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _08033CA8 @ =gEnemyParty
	adds r0, r1
	movs r1, 0x18
	b _08033D26
	.align 2, 0
_08033CA8: .4byte gEnemyParty
_08033CAC:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _08033CB8 @ =gEnemyParty
	adds r0, r1
	movs r1, 0x21
	b _08033D26
	.align 2, 0
_08033CB8: .4byte gEnemyParty
_08033CBC:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _08033CC8 @ =gEnemyParty
	adds r0, r1
	movs r1, 0x2F
	b _08033D26
	.align 2, 0
_08033CC8: .4byte gEnemyParty
_08033CCC:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _08033CD8 @ =gEnemyParty
	adds r0, r1
	movs r1, 0x30
	b _08033D26
	.align 2, 0
_08033CD8: .4byte gEnemyParty
_08033CDC:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _08033CE8 @ =gEnemyParty
	adds r0, r1
	movs r1, 0x32
	b _08033D26
	.align 2, 0
_08033CE8: .4byte gEnemyParty
_08033CEC:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _08033CF8 @ =gEnemyParty
	adds r0, r1
	movs r1, 0x33
	b _08033D26
	.align 2, 0
_08033CF8: .4byte gEnemyParty
_08033CFC:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _08033D08 @ =gEnemyParty
	adds r0, r1
	movs r1, 0x34
	b _08033D26
	.align 2, 0
_08033D08: .4byte gEnemyParty
_08033D0C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _08033D18 @ =gEnemyParty
	adds r0, r1
	movs r1, 0x35
	b _08033D26
	.align 2, 0
_08033D18: .4byte gEnemyParty
_08033D1C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _08033D40 @ =gEnemyParty
	adds r0, r1
	movs r1, 0x36
_08033D26:
	bl GetMonData
	strb r0, [r7]
	movs r6, 0x1
_08033D2E:
	adds r0, r6, 0
	add sp, 0x90
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08033D40: .4byte gEnemyParty
	thumb_func_end sub_8033598

	thumb_func_start dp01t_01_2_read_pokmon_data_slice
dp01t_01_2_read_pokmon_data_slice: @ 8033D44
	push {r4-r7,lr}
	sub sp, 0x58
	ldr r2, _08033DBC @ =gBattlePartyID
	ldr r5, _08033DC0 @ =gActiveBank
	ldrb r1, [r5]
	lsls r0, r1, 1
	adds r0, r2
	ldrh r2, [r0]
	movs r0, 0x64
	adds r4, r2, 0
	muls r4, r0
	ldr r3, _08033DC4 @ =gBattleBufferA
	lsls r1, 9
	adds r0, r3, 0x1
	adds r0, r1, r0
	ldrb r2, [r0]
	ldr r0, _08033DC8 @ =gEnemyParty
	adds r0, r2, r0
	adds r6, r4, r0
	mov r0, sp
	adds r4, r0, r2
	movs r2, 0
	adds r0, r3, 0x2
	adds r1, r0
	adds r7, r5, 0
	mov r12, r3
	ldrb r1, [r1]
	cmp r2, r1
	bcs _08033D9A
	adds r3, r0, 0
_08033D80:
	adds r1, r4, r2
	adds r0, r6, r2
	ldrb r0, [r0]
	strb r0, [r1]
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	ldrb r0, [r5]
	lsls r0, 9
	adds r0, r3
	ldrb r0, [r0]
	cmp r2, r0
	bcc _08033D80
_08033D9A:
	ldrb r0, [r7]
	lsls r0, 9
	mov r1, r12
	adds r1, 0x2
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x1
	adds r2, r4, 0
	bl dp01_build_cmdbuf_x1D_1D_numargs_varargs
	bl OpponentBufferExecCompleted
	add sp, 0x58
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08033DBC: .4byte gBattlePartyID
_08033DC0: .4byte gActiveBank
_08033DC4: .4byte gBattleBufferA
_08033DC8: .4byte gEnemyParty
	thumb_func_end dp01t_01_2_read_pokmon_data_slice

	thumb_func_start OpponentHandleSetAttributes
OpponentHandleSetAttributes: @ 8033DCC
	push {r4,r5,lr}
	ldr r1, _08033DF0 @ =gBattleBufferA
	ldr r0, _08033DF4 @ =gActiveBank
	ldrb r2, [r0]
	lsls r0, r2, 9
	adds r1, 0x2
	adds r1, r0, r1
	ldrb r0, [r1]
	cmp r0, 0
	bne _08033DFC
	ldr r0, _08033DF8 @ =gBattlePartyID
	lsls r1, r2, 1
	adds r1, r0
	ldrb r0, [r1]
	bl sub_8033E24
	b _08033E1A
	.align 2, 0
_08033DF0: .4byte gBattleBufferA
_08033DF4: .4byte gActiveBank
_08033DF8: .4byte gBattlePartyID
_08033DFC:
	ldrb r4, [r1]
	movs r5, 0
_08033E00:
	movs r0, 0x1
	ands r0, r4
	cmp r0, 0
	beq _08033E0E
	adds r0, r5, 0
	bl sub_8033E24
_08033E0E:
	lsrs r4, 1
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x5
	bls _08033E00
_08033E1A:
	bl OpponentBufferExecCompleted
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end OpponentHandleSetAttributes

	thumb_func_start sub_8033E24
sub_8033E24: @ 8033E24
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x38
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r3, _08033E5C @ =gActiveBank
	ldrb r0, [r3]
	lsls r0, 9
	ldr r2, _08033E60 @ =gUnknown_02023A63
	adds r4, r0, r2
	adds r7, r4, 0
	subs r1, r2, 0x2
	adds r0, r1
	ldrb r0, [r0]
	adds r6, r3, 0
	adds r3, r2, 0
	cmp r0, 0x3B
	bls _08033E52
	bl _08034730
_08033E52:
	lsls r0, 2
	ldr r1, _08033E64 @ =_08033E68
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08033E5C: .4byte gActiveBank
_08033E60: .4byte gUnknown_02023A63
_08033E64: .4byte _08033E68
	.align 2, 0
_08033E68:
	.4byte _08033F58
	.4byte _080340F0
	.4byte _0803410C
	.4byte _08034128
	.4byte _0803417C
	.4byte _0803417C
	.4byte _0803417C
	.4byte _0803417C
	.4byte _0803419C
	.4byte _08034204
	.4byte _08034204
	.4byte _08034204
	.4byte _08034204
	.4byte _08034730
	.4byte _08034730
	.4byte _08034730
	.4byte _08034730
	.4byte _0803422C
	.4byte _08034248
	.4byte _08034264
	.4byte _08034280
	.4byte _0803429C
	.4byte _080342B8
	.4byte _080342D4
	.4byte _080342F0
	.4byte _0803430C
	.4byte _08034328
	.4byte _08034344
	.4byte _08034360
	.4byte _0803437C
	.4byte _08034398
	.4byte _080343B4
	.4byte _08034428
	.4byte _08034444
	.4byte _08034460
	.4byte _0803447C
	.4byte _08034498
	.4byte _080344B4
	.4byte _080344D0
	.4byte _080344EC
	.4byte _08034508
	.4byte _08034524
	.4byte _08034540
	.4byte _0803455C
	.4byte _08034578
	.4byte _08034594
	.4byte _080345B0
	.4byte _080345CC
	.4byte _080345E8
	.4byte _08034604
	.4byte _08034620
	.4byte _0803463C
	.4byte _08034658
	.4byte _08034674
	.4byte _08034690
	.4byte _080346AC
	.4byte _080346C8
	.4byte _080346E4
	.4byte _08034700
	.4byte _0803471C
_08033F58:
	movs r0, 0x64
	adds r4, r5, 0
	muls r4, r0
	ldr r0, _080340EC @ =gEnemyParty
	adds r4, r0
	adds r0, r4, 0
	movs r1, 0xB
	adds r2, r7, 0
	bl SetMonData
	adds r2, r7, 0
	adds r2, 0x2E
	adds r0, r4, 0
	movs r1, 0xC
	bl SetMonData
	movs r0, 0
	mov r8, r0
	movs r0, 0x3B
	adds r0, r7
	mov r10, r0
	adds r0, r7, 0
	adds r0, 0x2B
	str r0, [sp, 0x20]
	adds r0, 0x19
	str r0, [sp, 0x28]
	adds r0, 0x4
	str r0, [sp, 0x2C]
	adds r0, 0x4
	str r0, [sp, 0x30]
	subs r0, 0x22
	str r0, [sp, 0x1C]
	subs r0, 0x2
	str r0, [sp, 0x18]
	adds r0, 0x4
	str r0, [sp, 0x24]
	adds r0, r7, 0x2
	str r0, [sp, 0x4]
	adds r0, r7, 0x4
	str r0, [sp, 0x8]
	adds r0, r7, 0x6
	str r0, [sp, 0xC]
	adds r0, 0x2
	str r0, [sp, 0x10]
	adds r0, 0x2
	str r0, [sp, 0x14]
	mov r9, r4
	adds r6, r7, 0
	adds r6, 0x24
	adds r4, r7, 0
	adds r4, 0xC
_08033FBE:
	mov r1, r8
	adds r1, 0xD
	mov r0, r9
	adds r2, r4, 0
	bl SetMonData
	mov r1, r8
	adds r1, 0x11
	mov r0, r9
	adds r2, r6, 0
	bl SetMonData
	adds r6, 0x1
	adds r4, 0x2
	movs r0, 0x1
	add r8, r0
	mov r0, r8
	cmp r0, 0x3
	ble _08033FBE
	movs r0, 0x64
	adds r4, r5, 0
	muls r4, r0
	ldr r0, _080340EC @ =gEnemyParty
	adds r4, r0
	adds r0, r4, 0
	movs r1, 0x15
	mov r2, r10
	bl SetMonData
	adds r0, r4, 0
	movs r1, 0x20
	ldr r2, [sp, 0x20]
	bl SetMonData
	adds r0, r4, 0
	movs r1, 0x19
	ldr r2, [sp, 0x28]
	bl SetMonData
	ldrb r0, [r7, 0x14]
	lsls r0, 27
	lsrs r0, 27
	mov r1, sp
	strb r0, [r1]
	adds r0, r4, 0
	movs r1, 0x27
	mov r2, sp
	bl SetMonData
	mov r1, sp
	ldrh r0, [r7, 0x14]
	lsls r0, 22
	lsrs r0, 27
	strb r0, [r1]
	adds r0, r4, 0
	movs r1, 0x28
	mov r2, sp
	bl SetMonData
	mov r1, sp
	ldrb r0, [r7, 0x15]
	lsls r0, 25
	lsrs r0, 27
	strb r0, [r1]
	adds r0, r4, 0
	movs r1, 0x29
	mov r2, sp
	bl SetMonData
	mov r1, sp
	ldr r0, [r7, 0x14]
	lsls r0, 12
	lsrs r0, 27
	strb r0, [r1]
	adds r0, r4, 0
	movs r1, 0x2A
	mov r2, sp
	bl SetMonData
	mov r1, sp
	ldrh r0, [r7, 0x16]
	lsls r0, 23
	lsrs r0, 27
	strb r0, [r1]
	adds r0, r4, 0
	movs r1, 0x2B
	mov r2, sp
	bl SetMonData
	mov r1, sp
	ldrb r0, [r7, 0x17]
	lsls r0, 26
	lsrs r0, 27
	strb r0, [r1]
	adds r0, r4, 0
	movs r1, 0x2C
	mov r2, sp
	bl SetMonData
	adds r0, r4, 0
	movs r1, 0
	ldr r2, [sp, 0x2C]
	bl SetMonData
	adds r0, r4, 0
	movs r1, 0x37
	ldr r2, [sp, 0x30]
	bl SetMonData
	adds r0, r4, 0
	movs r1, 0x38
	ldr r2, [sp, 0x1C]
	bl SetMonData
	adds r0, r4, 0
	movs r1, 0x39
	ldr r2, [sp, 0x18]
	bl SetMonData
	adds r0, r4, 0
	movs r1, 0x3A
	ldr r2, [sp, 0x24]
	bl SetMonData
	adds r0, r4, 0
	movs r1, 0x3B
	ldr r2, [sp, 0x4]
	bl SetMonData
	adds r0, r4, 0
	movs r1, 0x3C
	ldr r2, [sp, 0x8]
	bl SetMonData
	adds r0, r4, 0
	movs r1, 0x3D
	ldr r2, [sp, 0xC]
	bl SetMonData
	adds r0, r4, 0
	movs r1, 0x3E
	ldr r2, [sp, 0x10]
	bl SetMonData
	adds r0, r4, 0
	movs r1, 0x3F
	ldr r2, [sp, 0x14]
	bl SetMonData
	b _08034730
	.align 2, 0
_080340EC: .4byte gEnemyParty
_080340F0:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _08034108 @ =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0xB
	bl SetMonData
	b _08034730
	.align 2, 0
_08034108: .4byte gEnemyParty
_0803410C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _08034124 @ =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0xC
	bl SetMonData
	b _08034730
	.align 2, 0
_08034124: .4byte gEnemyParty
_08034128:
	movs r0, 0
	mov r8, r0
	movs r0, 0xC
	adds r0, r4
	mov r9, r0
	movs r0, 0x64
	adds r1, r5, 0
	muls r1, r0
	ldr r0, _08034178 @ =gEnemyParty
	adds r7, r1, r0
	adds r6, r4, 0
	adds r6, 0x8
_08034140:
	mov r1, r8
	adds r1, 0xD
	adds r0, r7, 0
	adds r2, r4, 0
	bl SetMonData
	mov r1, r8
	adds r1, 0x11
	adds r0, r7, 0
	adds r2, r6, 0
	bl SetMonData
	adds r6, 0x1
	adds r4, 0x2
	movs r0, 0x1
	add r8, r0
	mov r0, r8
	cmp r0, 0x3
	ble _08034140
	movs r0, 0x64
	muls r0, r5
	ldr r1, _08034178 @ =gEnemyParty
	adds r0, r1
	movs r1, 0x15
	mov r2, r9
	bl SetMonData
	b _08034730
	.align 2, 0
_08034178: .4byte gEnemyParty
_0803417C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _08034194 @ =gEnemyParty
	adds r0, r1
	ldr r3, _08034198 @ =gBattleBufferA
	ldrb r2, [r6]
	lsls r2, 9
	adds r1, r3, 0x1
	adds r1, r2, r1
	ldrb r1, [r1]
	adds r1, 0x9
	b _0803421A
	.align 2, 0
_08034194: .4byte gEnemyParty
_08034198: .4byte gBattleBufferA
_0803419C:
	movs r0, 0x64
	adds r4, r5, 0
	muls r4, r0
	ldr r0, _08034200 @ =gEnemyParty
	adds r4, r0
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	adds r0, r4, 0
	movs r1, 0x11
	str r3, [sp, 0x34]
	bl SetMonData
	ldrb r2, [r6]
	lsls r2, 9
	ldr r3, [sp, 0x34]
	adds r0, r3, 0x1
	adds r2, r0
	adds r0, r4, 0
	movs r1, 0x12
	bl SetMonData
	ldrb r2, [r6]
	lsls r2, 9
	ldr r3, [sp, 0x34]
	adds r0, r3, 0x2
	adds r2, r0
	adds r0, r4, 0
	movs r1, 0x13
	bl SetMonData
	ldrb r2, [r6]
	lsls r2, 9
	ldr r3, [sp, 0x34]
	adds r0, r3, 0x3
	adds r2, r0
	adds r0, r4, 0
	movs r1, 0x14
	bl SetMonData
	ldrb r2, [r6]
	lsls r2, 9
	ldr r3, [sp, 0x34]
	adds r0, r3, 0x4
	adds r2, r0
	adds r0, r4, 0
	movs r1, 0x15
	bl SetMonData
	b _08034730
	.align 2, 0
_08034200: .4byte gEnemyParty
_08034204:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _08034224 @ =gEnemyParty
	adds r0, r1
	ldr r3, _08034228 @ =gBattleBufferA
	ldrb r2, [r6]
	lsls r2, 9
	adds r1, r3, 0x1
	adds r1, r2, r1
	ldrb r1, [r1]
	adds r1, 0x8
_0803421A:
	adds r3, 0x3
	adds r2, r3
	bl SetMonData
	b _08034730
	.align 2, 0
_08034224: .4byte gEnemyParty
_08034228: .4byte gBattleBufferA
_0803422C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _08034244 @ =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x1
	bl SetMonData
	b _08034730
	.align 2, 0
_08034244: .4byte gEnemyParty
_08034248:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _08034260 @ =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x19
	bl SetMonData
	b _08034730
	.align 2, 0
_08034260: .4byte gEnemyParty
_08034264:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _0803427C @ =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x1A
	bl SetMonData
	b _08034730
	.align 2, 0
_0803427C: .4byte gEnemyParty
_08034280:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _08034298 @ =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x1B
	bl SetMonData
	b _08034730
	.align 2, 0
_08034298: .4byte gEnemyParty
_0803429C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _080342B4 @ =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x1C
	bl SetMonData
	b _08034730
	.align 2, 0
_080342B4: .4byte gEnemyParty
_080342B8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _080342D0 @ =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x1D
	bl SetMonData
	b _08034730
	.align 2, 0
_080342D0: .4byte gEnemyParty
_080342D4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _080342EC @ =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x1E
	bl SetMonData
	b _08034730
	.align 2, 0
_080342EC: .4byte gEnemyParty
_080342F0:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _08034308 @ =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x1F
	bl SetMonData
	b _08034730
	.align 2, 0
_08034308: .4byte gEnemyParty
_0803430C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _08034324 @ =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x20
	bl SetMonData
	b _08034730
	.align 2, 0
_08034324: .4byte gEnemyParty
_08034328:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _08034340 @ =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x22
	bl SetMonData
	b _08034730
	.align 2, 0
_08034340: .4byte gEnemyParty
_08034344:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _0803435C @ =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x23
	bl SetMonData
	b _08034730
	.align 2, 0
_0803435C: .4byte gEnemyParty
_08034360:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _08034378 @ =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x24
	bl SetMonData
	b _08034730
	.align 2, 0
_08034378: .4byte gEnemyParty
_0803437C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _08034394 @ =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x25
	bl SetMonData
	b _08034730
	.align 2, 0
_08034394: .4byte gEnemyParty
_08034398:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _080343B0 @ =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x26
	bl SetMonData
	b _08034730
	.align 2, 0
_080343B0: .4byte gEnemyParty
_080343B4:
	movs r0, 0x64
	adds r4, r5, 0
	muls r4, r0
	ldr r0, _08034424 @ =gEnemyParty
	adds r4, r0
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	adds r0, r4, 0
	movs r1, 0x27
	str r3, [sp, 0x34]
	bl SetMonData
	ldrb r2, [r6]
	lsls r2, 9
	ldr r3, [sp, 0x34]
	adds r0, r3, 0x1
	adds r2, r0
	adds r0, r4, 0
	movs r1, 0x28
	bl SetMonData
	ldrb r2, [r6]
	lsls r2, 9
	ldr r3, [sp, 0x34]
	adds r0, r3, 0x2
	adds r2, r0
	adds r0, r4, 0
	movs r1, 0x29
	bl SetMonData
	ldrb r2, [r6]
	lsls r2, 9
	ldr r3, [sp, 0x34]
	adds r0, r3, 0x3
	adds r2, r0
	adds r0, r4, 0
	movs r1, 0x2A
	bl SetMonData
	ldrb r2, [r6]
	lsls r2, 9
	ldr r3, [sp, 0x34]
	adds r0, r3, 0x4
	adds r2, r0
	adds r0, r4, 0
	movs r1, 0x2B
	bl SetMonData
	ldrb r2, [r6]
	lsls r2, 9
	ldr r3, [sp, 0x34]
	adds r0, r3, 0x5
	adds r2, r0
	adds r0, r4, 0
	b _080344C2
	.align 2, 0
_08034424: .4byte gEnemyParty
_08034428:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _08034440 @ =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x27
	bl SetMonData
	b _08034730
	.align 2, 0
_08034440: .4byte gEnemyParty
_08034444:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _0803445C @ =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x28
	bl SetMonData
	b _08034730
	.align 2, 0
_0803445C: .4byte gEnemyParty
_08034460:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _08034478 @ =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x29
	bl SetMonData
	b _08034730
	.align 2, 0
_08034478: .4byte gEnemyParty
_0803447C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _08034494 @ =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x2A
	bl SetMonData
	b _08034730
	.align 2, 0
_08034494: .4byte gEnemyParty
_08034498:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _080344B0 @ =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x2B
	bl SetMonData
	b _08034730
	.align 2, 0
_080344B0: .4byte gEnemyParty
_080344B4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _080344CC @ =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
_080344C2:
	movs r1, 0x2C
	bl SetMonData
	b _08034730
	.align 2, 0
_080344CC: .4byte gEnemyParty
_080344D0:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _080344E8 @ =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0
	bl SetMonData
	b _08034730
	.align 2, 0
_080344E8: .4byte gEnemyParty
_080344EC:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _08034504 @ =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x9
	bl SetMonData
	b _08034730
	.align 2, 0
_08034504: .4byte gEnemyParty
_08034508:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _08034520 @ =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x37
	bl SetMonData
	b _08034730
	.align 2, 0
_08034520: .4byte gEnemyParty
_08034524:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _0803453C @ =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x38
	bl SetMonData
	b _08034730
	.align 2, 0
_0803453C: .4byte gEnemyParty
_08034540:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _08034558 @ =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x39
	bl SetMonData
	b _08034730
	.align 2, 0
_08034558: .4byte gEnemyParty
_0803455C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _08034574 @ =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x3A
	bl SetMonData
	b _08034730
	.align 2, 0
_08034574: .4byte gEnemyParty
_08034578:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _08034590 @ =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x3B
	bl SetMonData
	b _08034730
	.align 2, 0
_08034590: .4byte gEnemyParty
_08034594:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _080345AC @ =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x3C
	bl SetMonData
	b _08034730
	.align 2, 0
_080345AC: .4byte gEnemyParty
_080345B0:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _080345C8 @ =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x3D
	bl SetMonData
	b _08034730
	.align 2, 0
_080345C8: .4byte gEnemyParty
_080345CC:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _080345E4 @ =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x3E
	bl SetMonData
	b _08034730
	.align 2, 0
_080345E4: .4byte gEnemyParty
_080345E8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _08034600 @ =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x3F
	bl SetMonData
	b _08034730
	.align 2, 0
_08034600: .4byte gEnemyParty
_08034604:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _0803461C @ =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x16
	bl SetMonData
	b _08034730
	.align 2, 0
_0803461C: .4byte gEnemyParty
_08034620:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _08034638 @ =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x17
	bl SetMonData
	b _08034730
	.align 2, 0
_08034638: .4byte gEnemyParty
_0803463C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _08034654 @ =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x18
	bl SetMonData
	b _08034730
	.align 2, 0
_08034654: .4byte gEnemyParty
_08034658:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _08034670 @ =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x21
	bl SetMonData
	b _08034730
	.align 2, 0
_08034670: .4byte gEnemyParty
_08034674:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _0803468C @ =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x2F
	bl SetMonData
	b _08034730
	.align 2, 0
_0803468C: .4byte gEnemyParty
_08034690:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _080346A8 @ =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x30
	bl SetMonData
	b _08034730
	.align 2, 0
_080346A8: .4byte gEnemyParty
_080346AC:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _080346C4 @ =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x32
	bl SetMonData
	b _08034730
	.align 2, 0
_080346C4: .4byte gEnemyParty
_080346C8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _080346E0 @ =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x33
	bl SetMonData
	b _08034730
	.align 2, 0
_080346E0: .4byte gEnemyParty
_080346E4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _080346FC @ =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x34
	bl SetMonData
	b _08034730
	.align 2, 0
_080346FC: .4byte gEnemyParty
_08034700:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _08034718 @ =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x35
	bl SetMonData
	b _08034730
	.align 2, 0
_08034718: .4byte gEnemyParty
_0803471C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _08034740 @ =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x36
	bl SetMonData
_08034730:
	add sp, 0x38
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08034740: .4byte gEnemyParty
	thumb_func_end sub_8033E24

	thumb_func_start sub_8034744
sub_8034744: @ 8034744
	push {r4-r7,lr}
	ldr r1, _080347A8 @ =gBattlePartyID
	ldr r7, _080347AC @ =gActiveBank
	ldrb r2, [r7]
	lsls r0, r2, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	adds r3, r1, 0
	muls r3, r0
	ldr r4, _080347B0 @ =gBattleBufferA
	lsls r2, 9
	adds r0, r4, 0x1
	adds r0, r2, r0
	ldrb r0, [r0]
	ldr r1, _080347B4 @ =gEnemyParty
	adds r0, r1
	adds r5, r3, r0
	movs r3, 0
	adds r0, r4, 0x2
	adds r2, r0
	ldrb r2, [r2]
	cmp r3, r2
	bcs _0803479C
	adds r6, r4, 0
	adds r2, r7, 0
	adds r4, r0, 0
_0803477A:
	adds r1, r5, r3
	ldrb r0, [r2]
	lsls r0, 9
	adds r0, 0x3
	adds r0, r3, r0
	adds r0, r6
	ldrb r0, [r0]
	strb r0, [r1]
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	ldrb r0, [r2]
	lsls r0, 9
	adds r0, r4
	ldrb r0, [r0]
	cmp r3, r0
	bcc _0803477A
_0803479C:
	bl OpponentBufferExecCompleted
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080347A8: .4byte gBattlePartyID
_080347AC: .4byte gActiveBank
_080347B0: .4byte gBattleBufferA
_080347B4: .4byte gEnemyParty
	thumb_func_end sub_8034744

	thumb_func_start OpponentHandleLoadPokeSprite
OpponentHandleLoadPokeSprite: @ 80347B8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r6, _080348E8 @ =gActiveBank
	ldrb r0, [r6]
	lsls r0, 1
	ldr r1, _080348EC @ =gBattlePartyID
	adds r0, r1
	ldrh r0, [r0]
	movs r7, 0x64
	muls r0, r7
	ldr r2, _080348F0 @ =gEnemyParty
	mov r10, r2
	add r0, r10
	movs r1, 0xB
	bl GetMonData
	mov r8, r0
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	ldrb r1, [r6]
	lsls r0, r1, 1
	ldr r2, _080348EC @ =gBattlePartyID
	adds r0, r2
	ldrh r0, [r0]
	muls r0, r7
	add r0, r10
	bl sub_8031794
	ldrb r0, [r6]
	bl GetBankIdentity
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	mov r0, r8
	bl GetMonSpriteTemplate_803C56C
	ldr r0, _080348F4 @ =gUnknown_02024E8C
	mov r9, r0
	ldrb r0, [r6]
	movs r1, 0x2
	bl sub_8077ABC
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	ldrb r0, [r6]
	bl sub_8077F68
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldrb r0, [r6]
	bl sub_8079E90
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	mov r0, r9
	adds r1, r5, 0
	adds r2, r4, 0
	bl CreateSprite
	ldr r4, _080348F8 @ =gObjectBankIDs
	ldrb r1, [r6]
	adds r1, r4
	strb r0, [r1]
	ldr r5, _080348FC @ =gSprites
	ldrb r0, [r6]
	adds r0, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldr r1, _08034900 @ =0x0000ff10
	strh r1, [r0, 0x24]
	ldrb r2, [r6]
	adds r0, r2, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	strh r2, [r0, 0x2E]
	ldrb r0, [r6]
	adds r0, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	mov r1, r8
	strh r1, [r0, 0x32]
	ldrb r3, [r6]
	adds r0, r3, r4
	ldrb r0, [r0]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r5
	lsls r3, 4
	ldrb r2, [r1, 0x5]
	movs r0, 0xF
	ands r0, r2
	orrs r0, r3
	strb r0, [r1, 0x5]
	ldrb r2, [r6]
	adds r4, r2, r4
	ldrb r1, [r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldr r1, _08034904 @ =gBattleMonForms
	adds r2, r1
	ldrb r1, [r2]
	bl StartSpriteAnim
	ldrb r4, [r6]
	lsls r0, r4, 1
	ldr r2, _080348EC @ =gBattlePartyID
	adds r0, r2
	ldrh r0, [r0]
	muls r0, r7
	add r0, r10
	movs r1, 0xB
	bl GetMonData
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	bl sub_8032984
	ldr r1, _08034908 @ =gBattleBankFunc
	ldrb r0, [r6]
	lsls r0, 2
	adds r0, r1
	ldr r1, _0803490C @ =sub_8033018
	str r1, [r0]
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080348E8: .4byte gActiveBank
_080348EC: .4byte gBattlePartyID
_080348F0: .4byte gEnemyParty
_080348F4: .4byte gUnknown_02024E8C
_080348F8: .4byte gObjectBankIDs
_080348FC: .4byte gSprites
_08034900: .4byte 0x0000ff10
_08034904: .4byte gBattleMonForms
_08034908: .4byte gBattleBankFunc
_0803490C: .4byte sub_8033018
	thumb_func_end OpponentHandleLoadPokeSprite

	thumb_func_start OpponentHandleSendOutPoke
OpponentHandleSendOutPoke: @ 8034910
	push {r4,lr}
	ldr r1, _08034948 @ =gBattlePartyID
	ldr r4, _0803494C @ =gActiveBank
	ldrb r0, [r4]
	lsls r2, r0, 1
	adds r2, r1
	ldr r3, _08034950 @ =gBattleBufferA
	lsls r0, 9
	adds r1, r3, 0x1
	adds r0, r1
	ldrb r0, [r0]
	strh r0, [r2]
	ldrb r0, [r4]
	lsls r1, r0, 9
	adds r3, 0x2
	adds r1, r3
	ldrb r1, [r1]
	bl sub_803495C
	ldr r1, _08034954 @ =gBattleBankFunc
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r1, _08034958 @ =sub_80333D4
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08034948: .4byte gBattlePartyID
_0803494C: .4byte gActiveBank
_08034950: .4byte gBattleBufferA
_08034954: .4byte gBattleBankFunc
_08034958: .4byte sub_80333D4
	thumb_func_end OpponentHandleSendOutPoke

	thumb_func_start sub_803495C
sub_803495C: @ 803495C
	push {r4-r6,lr}
	mov r6, r10
	mov r5, r9
	mov r4, r8
	push {r4-r6}
	adds r6, r0, 0
	lsls r6, 24
	lsrs r6, 24
	lsls r1, 24
	lsrs r1, 24
	adds r0, r6, 0
	bl sub_8032AA8
	ldr r0, _08034AB8 @ =gBattlePartyID
	lsls r4, r6, 1
	adds r4, r0
	ldr r0, _08034ABC @ =gBattleBufferA
	lsls r1, r6, 9
	adds r0, 0x1
	adds r1, r0
	ldrb r0, [r1]
	strh r0, [r4]
	ldrh r0, [r4]
	movs r1, 0x64
	mov r9, r1
	mov r1, r9
	muls r1, r0
	adds r0, r1, 0
	ldr r5, _08034AC0 @ =gEnemyParty
	adds r0, r5
	movs r1, 0xB
	bl GetMonData
	mov r8, r0
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	ldr r0, _08034AC4 @ =sub_80312F0
	bl CreateInvisibleSpriteWithCallback
	ldr r1, _08034AC8 @ =gUnknown_0300434C
	mov r10, r1
	add r10, r6
	mov r1, r10
	strb r0, [r1]
	ldrh r0, [r4]
	mov r1, r9
	muls r1, r0
	adds r0, r1, 0
	adds r0, r5
	adds r1, r6, 0
	bl sub_8031794
	adds r0, r6, 0
	bl GetBankIdentity
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	mov r0, r8
	bl GetMonSpriteTemplate_803C56C
	ldr r0, _08034ACC @ =gUnknown_02024E8C
	mov r9, r0
	adds r0, r6, 0
	movs r1, 0x2
	bl sub_8077ABC
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	adds r0, r6, 0
	bl sub_8077F68
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r6, 0
	bl sub_8079E90
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	mov r0, r9
	adds r1, r5, 0
	adds r2, r4, 0
	bl CreateSprite
	ldr r4, _08034AD0 @ =gObjectBankIDs
	adds r4, r6, r4
	strb r0, [r4]
	ldr r5, _08034AD4 @ =gSprites
	ldrb r1, [r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	strh r6, [r0, 0x2E]
	ldrb r1, [r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	mov r1, r8
	strh r1, [r0, 0x32]
	mov r0, r10
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldrb r1, [r4]
	strh r1, [r0, 0x30]
	ldrb r0, [r4]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r5
	lsls r3, r6, 4
	ldrb r2, [r1, 0x5]
	movs r0, 0xF
	ands r0, r2
	orrs r0, r3
	strb r0, [r1, 0x5]
	ldrb r1, [r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldr r1, _08034AD8 @ =gBattleMonForms
	adds r6, r1
	ldrb r1, [r6]
	bl StartSpriteAnim
	ldrb r1, [r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
	ldrb r1, [r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r5, 0
	adds r1, 0x1C
	adds r0, r1
	ldr r1, _08034ADC @ =SpriteCallbackDummy
	str r1, [r0]
	movs r0, 0
	movs r1, 0xFE
	bl sub_8046400
	mov r1, r10
	ldrb r2, [r1]
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	adds r1, r5
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r1, 0x2E]
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08034AB8: .4byte gBattlePartyID
_08034ABC: .4byte gBattleBufferA
_08034AC0: .4byte gEnemyParty
_08034AC4: .4byte sub_80312F0
_08034AC8: .4byte gUnknown_0300434C
_08034ACC: .4byte gUnknown_02024E8C
_08034AD0: .4byte gObjectBankIDs
_08034AD4: .4byte gSprites
_08034AD8: .4byte gBattleMonForms
_08034ADC: .4byte SpriteCallbackDummy
	thumb_func_end sub_803495C

	thumb_func_start OpponentHandleReturnPokeToBall
OpponentHandleReturnPokeToBall: @ 8034AE0
	push {r4-r6,lr}
	ldr r1, _08034B10 @ =gBattleBufferA
	ldr r6, _08034B14 @ =gActiveBank
	ldrb r2, [r6]
	lsls r0, r2, 9
	adds r1, 0x1
	adds r0, r1
	ldrb r3, [r0]
	cmp r3, 0
	bne _08034B24
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	ldr r1, _08034B18 @ =0x02017810
	adds r0, r1
	strb r3, [r0, 0x4]
	ldr r1, _08034B1C @ =gBattleBankFunc
	ldrb r0, [r6]
	lsls r0, 2
	adds r0, r1
	ldr r1, _08034B20 @ =sub_8034B74
	str r1, [r0]
	b _08034B60
	.align 2, 0
_08034B10: .4byte gBattleBufferA
_08034B14: .4byte gActiveBank
_08034B18: .4byte 0x02017810
_08034B1C: .4byte gBattleBankFunc
_08034B20: .4byte sub_8034B74
_08034B24:
	ldr r5, _08034B68 @ =gObjectBankIDs
	adds r0, r2, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r4, _08034B6C @ =gSprites
	adds r0, r4
	bl FreeSpriteOamMatrix
	ldrb r0, [r6]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	bl DestroySprite
	ldrb r0, [r6]
	bl sub_8032A08
	ldr r1, _08034B70 @ =gHealthboxIDs
	ldrb r0, [r6]
	adds r0, r1
	ldrb r0, [r0]
	bl sub_8043DB0
	bl OpponentBufferExecCompleted
_08034B60:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08034B68: .4byte gObjectBankIDs
_08034B6C: .4byte gSprites
_08034B70: .4byte gHealthboxIDs
	thumb_func_end OpponentHandleReturnPokeToBall

	thumb_func_start sub_8034B74
sub_8034B74: @ 8034B74
	push {r4,r5,lr}
	ldr r5, _08034B90 @ =gActiveBank
	ldrb r2, [r5]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	ldr r4, _08034B94 @ =0x02017810
	adds r3, r0, r4
	ldrb r0, [r3, 0x4]
	cmp r0, 0
	beq _08034B98
	cmp r0, 0x1
	beq _08034BC4
	b _08034BEC
	.align 2, 0
_08034B90: .4byte gActiveBank
_08034B94: .4byte 0x02017810
_08034B98:
	lsls r0, r2, 2
	adds r1, r4, 0
	subs r1, 0x10
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _08034BB4
	adds r0, r2, 0
	adds r1, r2, 0
	movs r3, 0x5
	bl move_anim_start_t4
_08034BB4:
	ldrb r0, [r5]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r4
	movs r0, 0x1
	strb r0, [r1, 0x4]
	b _08034BEC
_08034BC4:
	ldrb r1, [r3]
	movs r0, 0x40
	ands r0, r1
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	bne _08034BEC
	strb r0, [r3, 0x4]
	ldrb r2, [r5]
	adds r0, r2, 0
	adds r1, r2, 0
	movs r3, 0x2
	bl move_anim_start_t4
	ldr r1, _08034BF4 @ =gBattleBankFunc
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r1
	ldr r1, _08034BF8 @ =sub_8033160
	str r1, [r0]
_08034BEC:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08034BF4: .4byte gBattleBankFunc
_08034BF8: .4byte sub_8033160
	thumb_func_end sub_8034B74

	thumb_func_start OpponentHandleTrainerThrow
OpponentHandleTrainerThrow:
.syntax divided
	push	{r4, r5, r6, lr}
	mov	r6, r9
	mov	r5, r8
	push	{r5, r6}
	ldr	r0, ._480
	ldrb	r1, [r0]
	mov	r0, #0x10
	and	r0, r0, r1
	cmp	r0, #0
	beq	._478	@cond_branch
	ldr	r0, ._480 + 4
	ldr	r1, ._480 + 8
	add	r0, r0, r1
	ldrb	r0, [r0]
	b	._491
._481:
	.align	2, 0
._480:
	.word	gUnknown_02023A14+0x50
	.word	+0x2000000
	.word	0x160a3
._478:
	ldr	r3, ._484
	ldrh	r1, [r3]
	mov	r0, #0x80
	lsl	r0, r0, #0x3
	cmp	r1, r0
	bne	._482	@cond_branch
	bl	GetSecretBaseTrainerPicIndex
	b	._487
._485:
	.align	2, 0
._484:
	.word	gTrainerBattleOpponent
._482:
	ldr	r0, ._488
	ldrh	r1, [r0]
	mov	r0, #0x80
	lsl	r0, r0, #0x1
	and	r0, r0, r1
	cmp	r0, #0
	beq	._486	@cond_branch
	bl	get_trainer_class_pic_index
	b	._487
._489:
	.align	2, 0
._488:
	.word	gBattleTypeFlags
._486:
	mov	r0, #0x80
	lsl	r0, r0, #0x4
	and	r0, r0, r1
	cmp	r0, #0
	beq	._490	@cond_branch
	bl	sub_8135FBC
._487:
	lsl	r0, r0, #0x18
	lsr	r0, r0, #0x18
	b	._491
._490:
	ldr	r2, ._492
	ldrh	r1, [r3]
	lsl	r0, r1, #0x2
	add	r0, r0, r1
	lsl	r0, r0, #0x3
	add	r0, r0, r2
	ldrb	r0, [r0, #0x3]
._491:
	mov	r9, r0
	ldr	r2, ._492 + 4
	mov	r8, r2
	ldrb	r1, [r2]
	bl	sub_8031A6C
	mov	r1, r8
	ldrb	r0, [r1]
	bl	GetBankIdentity
	add	r1, r0, #0
	lsl	r1, r1, #0x18
	lsr	r1, r1, #0x18
	mov	r0, r9
	bl	GetMonSpriteTemplate_803C5A0
	ldr	r5, ._492 + 8
	ldr	r1, ._492 + 12
	mov	r2, r9
	lsl	r0, r2, #0x2
	add	r0, r0, r1
	ldrb	r0, [r0]
	mov	r4, #0x8
	sub	r4, r4, r0
	lsl	r4, r4, #0x12
	mov	r0, #0xa0
	lsl	r0, r0, #0xe
	add	r4, r4, r0
	asr	r4, r4, #0x10
	mov	r1, r8
	ldrb	r0, [r1]
	bl	sub_8079E90
	add	r3, r0, #0
	lsl	r3, r3, #0x18
	lsr	r3, r3, #0x18
	add	r0, r5, #0
	mov	r1, #0xb0
	add	r2, r4, #0
	bl	CreateSprite
	ldr	r5, ._492 + 16
	mov	r2, r8
	ldrb	r1, [r2]
	add	r1, r1, r5
	strb	r0, [r1]
	ldr	r4, ._492 + 20
	ldrb	r0, [r2]
	add	r0, r0, r5
	ldrb	r1, [r0]
	lsl	r0, r1, #0x4
	add	r0, r0, r1
	lsl	r0, r0, #0x2
	add	r0, r0, r4
	ldr	r1, ._492 + 24
	strh	r1, [r0, #0x24]
	ldrb	r0, [r2]
	add	r0, r0, r5
	ldrb	r1, [r0]
	lsl	r0, r1, #0x4
	add	r0, r0, r1
	lsl	r0, r0, #0x2
	add	r0, r0, r4
	mov	r1, #0x2
	strh	r1, [r0, #0x2e]
	ldr	r0, ._492 + 28
	mov	r1, r9
	lsl	r6, r1, #0x3
	add	r0, r6, r0
	ldrh	r0, [r0, #0x4]
	bl	IndexOfSpritePaletteTag
	mov	r2, r8
	ldrb	r1, [r2]
	add	r1, r1, r5
	ldrb	r1, [r1]
	lsl	r2, r1, #0x4
	add	r2, r2, r1
	lsl	r2, r2, #0x2
	add	r2, r2, r4
	lsl	r0, r0, #0x4
	ldrb	r3, [r2, #0x5]
	mov	r1, #0xf
	and	r1, r1, r3
	orr	r1, r1, r0
	strb	r1, [r2, #0x5]
	mov	r1, r8
	ldrb	r0, [r1]
	add	r0, r0, r5
	ldrb	r0, [r0]
	lsl	r1, r0, #0x4
	add	r1, r1, r0
	lsl	r1, r1, #0x2
	add	r1, r1, r4
	ldrh	r0, [r1, #0x4]
	lsl	r0, r0, #0x16
	lsr	r0, r0, #0x16
	strh	r0, [r1, #0x38]
	ldr	r0, ._492 + 32
	add	r6, r6, r0
	ldrh	r0, [r6, #0x6]
	bl	GetSpriteTileStartByTag
	mov	r2, r8
	ldrb	r1, [r2]
	add	r1, r1, r5
	ldrb	r2, [r1]
	lsl	r1, r2, #0x4
	add	r1, r1, r2
	lsl	r1, r1, #0x2
	add	r1, r1, r4
	ldr	r2, ._492 + 36
	and	r2, r2, r0
	ldrh	r3, [r1, #0x4]
	ldr	r0, ._492 + 40
	and	r0, r0, r3
	orr	r0, r0, r2
	strh	r0, [r1, #0x4]
	mov	r1, r8
	ldrb	r0, [r1]
	add	r0, r0, r5
	ldrb	r1, [r0]
	lsl	r0, r1, #0x4
	add	r0, r0, r1
	lsl	r0, r0, #0x2
	add	r0, r0, r4
	mov	r2, r9
	strh	r2, [r0, #0x6]
	mov	r1, r8
	ldrb	r0, [r1]
	add	r0, r0, r5
	ldrb	r1, [r0]
	lsl	r0, r1, #0x4
	add	r0, r0, r1
	lsl	r0, r0, #0x2
	add	r4, r4, #0x1c
	add	r0, r0, r4
	ldr	r1, ._492 + 44
	str	r1, [r0]
	ldr	r1, ._492 + 48
	mov	r2, r8
	ldrb	r0, [r2]
	lsl	r0, r0, #0x2
	add	r0, r0, r1
	ldr	r1, ._492 + 52
	str	r1, [r0]
	pop	{r3, r4}
	mov	r8, r3
	mov	r9, r4
	pop	{r4, r5, r6}
	pop	{r0}
	bx	r0
._493:
	.align	2, 0
._492:
	.word	gTrainers
	.word	gActiveBank
	.word	gUnknown_02024E8C
	.word	gTrainerFrontPicCoords
	.word	gObjectBankIDs
	.word	gSprites
	.word	0xff10
	.word	gTrainerFrontPicPaletteTable
	.word	gTrainerFrontPicTable
	.word	0x3ff
	.word	0xfffffc00
	.word	sub_80313A0+1
	.word	gBattleBankFunc
	.word	sub_8032B4C+1
.syntax unified
	thumb_func_end OpponentHandleTrainerThrow

	thumb_func_start OpponentHandleTrainerSlide
OpponentHandleTrainerSlide: @ 8034DC0
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	ldr r3, _08034DDC @ =gTrainerBattleOpponent
	ldrh r1, [r3]
	movs r0, 0x80
	lsls r0, 3
	cmp r1, r0
	bne _08034DE0
	bl GetSecretBaseTrainerPicIndex
	b _08034E06
	.align 2, 0
_08034DDC: .4byte gTrainerBattleOpponent
_08034DE0:
	ldr r0, _08034DF4 @ =gBattleTypeFlags
	ldrh r1, [r0]
	movs r0, 0x80
	lsls r0, 1
	ands r0, r1
	cmp r0, 0
	beq _08034DF8
	bl get_trainer_class_pic_index
	b _08034E06
	.align 2, 0
_08034DF4: .4byte gBattleTypeFlags
_08034DF8:
	movs r0, 0x80
	lsls r0, 4
	ands r0, r1
	cmp r0, 0
	beq _08034E0C
	bl sub_8135FBC
_08034E06:
	lsls r0, 24
	lsrs r0, 24
	b _08034E1A
_08034E0C:
	ldr r2, _08034F4C @ =gTrainers
	ldrh r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	ldrb r0, [r0, 0x3]
_08034E1A:
	mov r9, r0
	ldr r0, _08034F50 @ =gActiveBank
	mov r8, r0
	ldrb r1, [r0]
	mov r0, r9
	bl sub_8031A6C
	mov r1, r8
	ldrb r0, [r1]
	bl GetBankIdentity
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	mov r0, r9
	bl GetMonSpriteTemplate_803C5A0
	ldr r0, _08034F54 @ =gUnknown_02024E8C
	ldr r2, _08034F58 @ =gTrainerFrontPicCoords
	mov r3, r9
	lsls r1, r3, 2
	adds r1, r2
	ldrb r1, [r1]
	movs r2, 0x8
	subs r2, r1
	lsls r2, 18
	movs r1, 0xA0
	lsls r1, 14
	adds r2, r1
	asrs r2, 16
	movs r1, 0xB0
	movs r3, 0x1E
	bl CreateSprite
	ldr r5, _08034F5C @ =gObjectBankIDs
	mov r2, r8
	ldrb r1, [r2]
	adds r1, r5
	strb r0, [r1]
	ldr r4, _08034F60 @ =gSprites
	ldrb r0, [r2]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	movs r1, 0x60
	strh r1, [r0, 0x24]
	ldrb r0, [r2]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrh r1, [r0, 0x20]
	adds r1, 0x20
	strh r1, [r0, 0x20]
	ldrb r0, [r2]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldr r1, _08034F64 @ =0x0000fffe
	strh r1, [r0, 0x2E]
	ldr r0, _08034F68 @ =gTrainerFrontPicPaletteTable
	mov r3, r9
	lsls r6, r3, 3
	adds r0, r6, r0
	ldrh r0, [r0, 0x4]
	bl IndexOfSpritePaletteTag
	mov r2, r8
	ldrb r1, [r2]
	adds r1, r5
	ldrb r1, [r1]
	lsls r2, r1, 4
	adds r2, r1
	lsls r2, 2
	adds r2, r4
	lsls r0, 4
	ldrb r3, [r2, 0x5]
	movs r1, 0xF
	ands r1, r3
	orrs r1, r0
	strb r1, [r2, 0x5]
	mov r3, r8
	ldrb r0, [r3]
	adds r0, r5
	ldrb r0, [r0]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r4
	ldrh r0, [r1, 0x4]
	lsls r0, 22
	lsrs r0, 22
	strh r0, [r1, 0x38]
	ldr r0, _08034F6C @ =gTrainerFrontPicTable
	adds r6, r0
	ldrh r0, [r6, 0x6]
	bl GetSpriteTileStartByTag
	mov r2, r8
	ldrb r1, [r2]
	adds r1, r5
	ldrb r2, [r1]
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	adds r1, r4
	ldr r2, _08034F70 @ =0x000003ff
	ands r2, r0
	ldrh r3, [r1, 0x4]
	ldr r0, _08034F74 @ =0xfffffc00
	ands r0, r3
	orrs r0, r2
	strh r0, [r1, 0x4]
	mov r3, r8
	ldrb r0, [r3]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	mov r1, r9
	strh r1, [r0, 0x6]
	ldrb r0, [r3]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r4, 0x1C
	adds r0, r4
	ldr r1, _08034F78 @ =sub_80313A0
	str r1, [r0]
	ldr r1, _08034F7C @ =gBattleBankFunc
	ldrb r0, [r3]
	lsls r0, 2
	adds r0, r1
	ldr r1, _08034F80 @ =sub_8032B84
	str r1, [r0]
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08034F4C: .4byte gTrainers
_08034F50: .4byte gActiveBank
_08034F54: .4byte gUnknown_02024E8C
_08034F58: .4byte gTrainerFrontPicCoords
_08034F5C: .4byte gObjectBankIDs
_08034F60: .4byte gSprites
_08034F64: .4byte 0x0000fffe
_08034F68: .4byte gTrainerFrontPicPaletteTable
_08034F6C: .4byte gTrainerFrontPicTable
_08034F70: .4byte 0x000003ff
_08034F74: .4byte 0xfffffc00
_08034F78: .4byte sub_80313A0
_08034F7C: .4byte gBattleBankFunc
_08034F80: .4byte sub_8032B84
	thumb_func_end OpponentHandleTrainerSlide

	thumb_func_start OpponentHandleTrainerSlideBack
OpponentHandleTrainerSlideBack: @ 8034F84
	push {r4-r6,lr}
	ldr r6, _08035014 @ =gObjectBankIDs
	ldr r4, _08035018 @ =gActiveBank
	ldrb r0, [r4]
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r5, _0803501C @ =gSprites
	adds r0, r5
	bl oamt_add_pos2_onto_pos1
	ldrb r0, [r4]
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	movs r1, 0x23
	strh r1, [r0, 0x2E]
	ldrb r0, [r4]
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	movs r1, 0x8C
	lsls r1, 1
	strh r1, [r0, 0x32]
	ldrb r0, [r4]
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldrh r1, [r0, 0x22]
	strh r1, [r0, 0x36]
	ldrb r0, [r4]
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r5, 0
	adds r1, 0x1C
	adds r0, r1
	ldr r1, _08035020 @ =sub_8078B34
	str r1, [r0]
	ldrb r0, [r4]
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldr r1, _08035024 @ =SpriteCallbackDummy
	bl oamt_set_x3A_32
	ldr r1, _08035028 @ =gBattleBankFunc
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r1, _0803502C @ =sub_8032BBC
	str r1, [r0]
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08035014: .4byte gObjectBankIDs
_08035018: .4byte gActiveBank
_0803501C: .4byte gSprites
_08035020: .4byte sub_8078B34
_08035024: .4byte SpriteCallbackDummy
_08035028: .4byte gBattleBankFunc
_0803502C: .4byte sub_8032BBC
	thumb_func_end OpponentHandleTrainerSlideBack

	thumb_func_start sub_8035030
sub_8035030: @ 8035030
	push {r4,r5,lr}
	ldr r5, _08035074 @ =gActiveBank
	ldrb r2, [r5]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	ldr r4, _08035078 @ =0x02017810
	adds r3, r0, r4
	ldrb r0, [r3, 0x4]
	cmp r0, 0
	bne _0803507C
	lsls r0, r2, 2
	adds r1, r4, 0
	subs r1, 0x10
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _08035062
	adds r0, r2, 0
	adds r1, r2, 0
	movs r3, 0x5
	bl move_anim_start_t4
_08035062:
	ldrb r0, [r5]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r4
	ldrb r0, [r1, 0x4]
	adds r0, 0x1
	strb r0, [r1, 0x4]
	b _080350B8
	.align 2, 0
_08035074: .4byte gActiveBank
_08035078: .4byte 0x02017810
_0803507C:
	ldrb r1, [r3]
	movs r0, 0x40
	ands r0, r1
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	bne _080350B8
	strb r0, [r3, 0x4]
	movs r0, 0x10
	movs r1, 0x3F
	bl PlaySE12WithPanning
	ldr r2, _080350C0 @ =gSprites
	ldr r1, _080350C4 @ =gObjectBankIDs
	ldrb r0, [r5]
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, 0x1C
	adds r0, r2
	ldr r1, _080350C8 @ =sub_8010384
	str r1, [r0]
	ldr r1, _080350CC @ =gBattleBankFunc
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r1
	ldr r1, _080350D0 @ =sub_803311C
	str r1, [r0]
_080350B8:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_080350C0: .4byte gSprites
_080350C4: .4byte gObjectBankIDs
_080350C8: .4byte sub_8010384
_080350CC: .4byte gBattleBankFunc
_080350D0: .4byte sub_803311C
	thumb_func_end sub_8035030

	thumb_func_start sub_80350D4
sub_80350D4: @ 80350D4
	push {lr}
	bl OpponentBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_80350D4

	thumb_func_start sub_80350E0
sub_80350E0: @ 80350E0
	push {lr}
	bl OpponentBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_80350E0

	thumb_func_start OpponentHandleBallThrow
OpponentHandleBallThrow: @ 80350EC
	push {lr}
	bl OpponentBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end OpponentHandleBallThrow

	thumb_func_start OpponentHandlePause
OpponentHandlePause: @ 80350F8
	push {lr}
	bl OpponentBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end OpponentHandlePause

	thumb_func_start OpponentHandleMoveAnimation
OpponentHandleMoveAnimation: @ 8035104
	push {r4-r6,lr}
	ldr r6, _080351E8 @ =gActiveBank
	ldrb r0, [r6]
	bl mplay_80342A4
	lsls r0, 24
	cmp r0, 0
	beq _08035116
	b _08035226
_08035116:
	ldr r0, _080351EC @ =gBattleBufferA
	mov r12, r0
	ldrb r2, [r6]
	lsls r2, 9
	adds r0, 0x1
	adds r0, r2, r0
	ldrb r0, [r0]
	mov r1, r12
	adds r1, 0x2
	adds r1, r2, r1
	ldrb r1, [r1]
	lsls r1, 8
	orrs r0, r1
	ldr r5, _080351F0 @ =gUnknown_0202F7C4
	mov r1, r12
	adds r1, 0x3
	adds r2, r1
	ldrb r1, [r2]
	strb r1, [r5]
	ldr r4, _080351F4 @ =gMovePowerMoveAnim
	ldrb r2, [r6]
	lsls r2, 9
	mov r1, r12
	adds r1, 0x4
	adds r1, r2, r1
	ldrb r3, [r1]
	mov r1, r12
	adds r1, 0x5
	adds r2, r1
	ldrb r1, [r2]
	lsls r1, 8
	orrs r3, r1
	strh r3, [r4]
	ldr r4, _080351F8 @ =gMoveDmgMoveAnim
	ldrb r2, [r6]
	lsls r2, 9
	mov r1, r12
	adds r1, 0x6
	adds r1, r2, r1
	ldrb r3, [r1]
	mov r1, r12
	adds r1, 0x7
	adds r1, r2, r1
	ldrb r1, [r1]
	lsls r1, 8
	orrs r3, r1
	mov r1, r12
	adds r1, 0x8
	adds r1, r2, r1
	ldrb r1, [r1]
	lsls r1, 16
	orrs r3, r1
	mov r1, r12
	adds r1, 0x9
	adds r2, r1
	ldrb r1, [r2]
	lsls r1, 24
	orrs r3, r1
	str r3, [r4]
	ldr r3, _080351FC @ =gHappinessMoveAnim
	ldrb r1, [r6]
	lsls r1, 9
	mov r2, r12
	adds r2, 0xA
	adds r1, r2
	ldrb r1, [r1]
	strb r1, [r3]
	ldr r4, _08035200 @ =gWeatherMoveAnim
	ldrb r2, [r6]
	lsls r2, 9
	mov r1, r12
	adds r1, 0xC
	adds r1, r2, r1
	ldrb r3, [r1]
	mov r1, r12
	adds r1, 0xD
	adds r2, r1
	ldrb r1, [r2]
	lsls r1, 8
	orrs r3, r1
	strh r3, [r4]
	ldr r3, _08035204 @ =gDisableStructMoveAnim
	ldrb r2, [r6]
	lsls r2, 9
	mov r1, r12
	adds r1, 0x10
	adds r2, r1
	str r2, [r3]
	ldr r3, _08035208 @ =gPID_perBank
	ldrb r1, [r6]
	lsls r1, 2
	adds r1, r3
	ldr r2, [r2]
	str r2, [r1]
	ldrb r1, [r5]
	bl sub_8031720
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0
	beq _0803520C
	bl OpponentBufferExecCompleted
	b _08035226
	.align 2, 0
_080351E8: .4byte gActiveBank
_080351EC: .4byte gBattleBufferA
_080351F0: .4byte gUnknown_0202F7C4
_080351F4: .4byte gMovePowerMoveAnim
_080351F8: .4byte gMoveDmgMoveAnim
_080351FC: .4byte gHappinessMoveAnim
_08035200: .4byte gWeatherMoveAnim
_08035204: .4byte gDisableStructMoveAnim
_08035208: .4byte gPID_perBank
_0803520C:
	ldrb r1, [r6]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	ldr r1, _0803522C @ =0x02017810
	adds r0, r1
	strb r2, [r0, 0x4]
	ldr r1, _08035230 @ =gBattleBankFunc
	ldrb r0, [r6]
	lsls r0, 2
	adds r0, r1
	ldr r1, _08035234 @ =sub_8035238
	str r1, [r0]
_08035226:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0803522C: .4byte 0x02017810
_08035230: .4byte gBattleBankFunc
_08035234: .4byte sub_8035238
	thumb_func_end OpponentHandleMoveAnimation

	thumb_func_start sub_8035238
sub_8035238: @ 8035238
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	ldr r2, _0803527C @ =gBattleBufferA
	ldr r5, _08035280 @ =gActiveBank
	ldrb r3, [r5]
	lsls r1, r3, 9
	adds r0, r2, 0x1
	mov r9, r0
	adds r0, r1, r0
	ldrb r4, [r0]
	adds r6, r2, 0x2
	mov r8, r6
	adds r0, r1, r6
	ldrb r0, [r0]
	lsls r0, 8
	orrs r4, r0
	adds r2, 0xB
	adds r1, r2
	ldrb r7, [r1]
	lsls r0, r3, 1
	adds r0, r3
	lsls r0, 2
	ldr r6, _08035284 @ =0x02017810
	adds r0, r6
	ldrb r2, [r0, 0x4]
	cmp r2, 0x1
	beq _080352C6
	cmp r2, 0x1
	bgt _08035288
	cmp r2, 0
	beq _08035292
	b _08035390
	.align 2, 0
_0803527C: .4byte gBattleBufferA
_08035280: .4byte gActiveBank
_08035284: .4byte 0x02017810
_08035288:
	cmp r2, 0x2
	beq _080352EC
	cmp r2, 0x3
	beq _08035358
	b _08035390
_08035292:
	lsls r1, r3, 2
	adds r0, r6, 0
	subs r0, 0x10
	adds r1, r0
	ldrb r2, [r1]
	movs r0, 0xC
	ands r0, r2
	cmp r0, 0x4
	bne _080352B6
	movs r0, 0x8
	orrs r0, r2
	strb r0, [r1]
	ldrb r2, [r5]
	adds r0, r2, 0
	adds r1, r2, 0
	movs r3, 0x5
	bl move_anim_start_t4
_080352B6:
	ldrb r0, [r5]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r6
	movs r0, 0x1
	strb r0, [r1, 0x4]
	b _08035390
_080352C6:
	ldrb r1, [r0]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	bne _08035390
	movs r0, 0
	bl sub_80326EC
	adds r0, r4, 0
	bl ExecuteMoveAnim
	ldrb r0, [r5]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r6
	movs r0, 0x2
	strb r0, [r1, 0x4]
	b _08035390
_080352EC:
	ldr r0, _08035348 @ =gAnimScriptCallback
	ldr r0, [r0]
	bl _call_via_r0
	ldr r0, _0803534C @ =gAnimScriptActive
	ldrb r0, [r0]
	cmp r0, 0
	bne _08035390
	movs r0, 0x1
	bl sub_80326EC
	ldrb r2, [r5]
	lsls r0, r2, 2
	adds r4, r6, 0
	subs r4, 0x10
	adds r0, r4
	ldrb r1, [r0]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _08035334
	cmp r7, 0x1
	bhi _08035334
	adds r0, r2, 0
	adds r1, r2, 0
	movs r3, 0x6
	bl move_anim_start_t4
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r4
	ldrb r2, [r0]
	movs r1, 0x9
	negs r1, r1
	ands r1, r2
	strb r1, [r0]
_08035334:
	ldr r0, _08035350 @ =gActiveBank
	ldrb r1, [r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	ldr r1, _08035354 @ =0x02017810
	adds r0, r1
	movs r1, 0x3
	strb r1, [r0, 0x4]
	b _08035390
	.align 2, 0
_08035348: .4byte gAnimScriptCallback
_0803534C: .4byte gAnimScriptActive
_08035350: .4byte gActiveBank
_08035354: .4byte 0x02017810
_08035358:
	ldrb r1, [r0]
	movs r0, 0x40
	ands r0, r1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	bne _08035390
	bl sub_8031F24
	ldrb r0, [r5]
	lsls r2, r0, 9
	mov r3, r9
	adds r1, r2, r3
	ldrb r1, [r1]
	add r2, r8
	ldrb r2, [r2]
	lsls r2, 8
	orrs r1, r2
	bl sub_80324BC
	ldrb r1, [r5]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	strb r4, [r0, 0x4]
	bl OpponentBufferExecCompleted
_08035390:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8035238

	thumb_func_start OpponentHandlePrintString
OpponentHandlePrintString: @ 803539C
	push {r4,lr}
	sub sp, 0x4
	ldr r0, _080353E0 @ =gUnknown_030042A4
	movs r1, 0
	strh r1, [r0]
	ldr r0, _080353E4 @ =gUnknown_030042A0
	strh r1, [r0]
	ldr r4, _080353E8 @ =gActiveBank
	ldrb r0, [r4]
	lsls r0, 9
	ldr r1, _080353EC @ =gUnknown_02023A62
	adds r0, r1
	ldrh r0, [r0]
	bl BufferStringBattle
	ldr r0, _080353F0 @ =gUnknown_03004210
	ldr r1, _080353F4 @ =gDisplayedStringBattle
	movs r2, 0xF
	str r2, [sp]
	movs r2, 0x90
	movs r3, 0x2
	bl sub_8002EB0
	ldr r1, _080353F8 @ =gBattleBankFunc
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r1, _080353FC @ =sub_80331D0
	str r1, [r0]
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080353E0: .4byte gUnknown_030042A4
_080353E4: .4byte gUnknown_030042A0
_080353E8: .4byte gActiveBank
_080353EC: .4byte gUnknown_02023A62
_080353F0: .4byte gUnknown_03004210
_080353F4: .4byte gDisplayedStringBattle
_080353F8: .4byte gBattleBankFunc
_080353FC: .4byte sub_80331D0
	thumb_func_end OpponentHandlePrintString

	thumb_func_start OpponentHandlePrintStringPlayerOnly
OpponentHandlePrintStringPlayerOnly: @ 8035400
	push {lr}
	bl OpponentBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end OpponentHandlePrintStringPlayerOnly

	thumb_func_start sub_803540C
sub_803540C: @ 803540C
	push {lr}
	bl sub_8036B0C
	bl OpponentBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_803540C

	thumb_func_start sub_803541C
sub_803541C: @ 803541C
	push {lr}
	bl OpponentBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_803541C

	thumb_func_start sub_8035428
sub_8035428:
.syntax divided
	push	{r4, r5, r6, r7, lr}
	mov	r7, sl
	mov	r6, r9
	mov	r5, r8
	push	{r5, r6, r7}
	ldr	r6, ._549
	ldrb	r0, [r6]
	lsl	r0, r0, #0x9
	ldr	r1, ._549 + 4
	add	r5, r0, r1
	ldr	r2, ._549 + 8
	ldrb	r1, [r2]
	mov	r0, #0x4
	and	r0, r0, r1
	mov	sl, r6
	cmp	r0, #0
	beq	._546	@cond_branch
	ldr	r0, ._549 + 12
	mov	r9, r0
	ldr	r1, ._549 + 16
	mov	ip, r1
	add	r7, r6, #0
	mov	r0, #0x2
	mov	r8, r0
	ldr	r6, ._549 + 20
._552:
	ldrb	r1, [r7]
	mov	r0, r8
	and	r0, r0, r1
	lsl	r0, r0, #0x18
	lsr	r0, r0, #0x19
	add	r0, r0, r6
	mov	r1, ip
	add	r3, r0, r1
	ldrb	r1, [r3]
	lsl	r0, r1, #0x1
	add	r0, r5, r0
	ldrh	r2, [r0]
	add	r4, r1, #0
	cmp	r2, #0
	beq	._547	@cond_branch
	add	r0, r4, #1
	strb	r0, [r3]
	b	._548
._550:
	.align	2, 0
._549:
	.word	gActiveBank
	.word	gUnknown_02023A64
	.word	gUnknown_02023A14+0x50
	.word	gBattleMoves
	.word	+0x2000000
	.word	0x1609e
._547:
	strb	r2, [r3]
._548:
	ldrb	r0, [r7]
	mov	r1, r8
	and	r1, r1, r0
	lsl	r1, r1, #0x18
	lsr	r1, r1, #0x19
	add	r1, r1, r6
	add r1, r1, ip
	ldrb	r0, [r1]
	cmp	r0, #0x3
	bls	._551	@cond_branch
	mov	r0, #0x0
	strb	r0, [r1]
._551:
	cmp	r2, #0
	beq	._552	@cond_branch
	lsl	r0, r2, #0x1
	add	r0, r0, r2
	lsl	r0, r0, #0x2
	add r0, r0, r9
	ldrb	r3, [r0, #0x6]
	mov	r0, #0x12
	and	r0, r0, r3
	cmp	r0, #0
	beq	._553	@cond_branch
	mov	r1, sl
	ldrb	r0, [r1]
	b	._561
._553:
	ldr	r0, ._559
	ldrh	r1, [r0]
	mov	r0, #0x1
	and	r0, r0, r1
	cmp	r0, #0
	beq	._557	@cond_branch
	ldr	r0, ._559 + 4
	ldrb	r1, [r0]
	mov	r5, #0x2
	add	r0, r5, #0
	and	r0, r0, r1
	cmp	r0, #0
	beq	._556	@cond_branch
	cmp	r3, #0
	bne	._557	@cond_branch
	mov	r1, sl
	ldrb	r0, [r1]
	bl	GetBankIdentity
	mov	r1, #0x2
	eor	r0, r0, r1
	lsl	r0, r0, #0x18
	lsr	r0, r0, #0x18
	b	._558
._560:
	.align	2, 0
._559:
	.word	gBattleTypeFlags
	.word	gUnknown_02023A14+0x50
._556:
	bl	Random
	add	r1, r5, #0
	and	r1, r1, r0
	lsl	r1, r1, #0x10
	lsr	r0, r1, #0x10
	b	._561
._557:
	mov	r0, #0x0
._558:
	bl	GetBankByPlayerAI
	lsl	r0, r0, #0x18
	lsr	r0, r0, #0x18
._561:
	lsl	r2, r0, #0x8
	orr	r2, r2, r4
	mov	r0, #0x1
	mov	r1, #0xa
._569:
	bl	dp01_build_cmdbuf_x21_a_bb
._573:
	bl	OpponentBufferExecCompleted
	b	._562
._546:
	ldr	r0, ._567
	ldrh	r1, [r0]
	mov	r0, #0x93
	lsl	r0, r0, #0x3
	and	r0, r0, r1
	cmp	r0, #0
	beq	._563	@cond_branch
	bl	BattleAI_SetupAIData
	bl	BattleAI_GetAIActionToUse
	lsl	r0, r0, #0x18
	lsr	r4, r0, #0x18
	cmp	r4, #0x4
	beq	._564	@cond_branch
	cmp	r4, #0x5
	bne	._565	@cond_branch
	mov	r0, #0x1
	mov	r1, #0x4
	b	._566
._568:
	.align	2, 0
._567:
	.word	gBattleTypeFlags
._564:
	mov	r0, #0x1
	mov	r1, #0x3
._566:
	mov	r2, #0x0
	b	._569
._565:
	ldr	r3, ._574
	lsl	r0, r4, #0x1
	add	r2, r5, r0
	ldrh	r1, [r2]
	lsl	r0, r1, #0x1
	add	r0, r0, r1
	lsl	r0, r0, #0x2
	add	r0, r0, r3
	ldrb	r1, [r0, #0x6]
	mov	r0, #0x12
	and	r0, r0, r1
	cmp	r0, #0
	beq	._570	@cond_branch
	ldr	r1, ._574 + 4
	ldrb	r0, [r6]
	strb	r0, [r1]
._570:
	ldrh	r1, [r2]
	lsl	r0, r1, #0x1
	add	r0, r0, r1
	lsl	r0, r0, #0x2
	add	r0, r0, r3
	ldrb	r1, [r0, #0x6]
	mov	r0, #0x8
	and	r0, r0, r1
	cmp	r0, #0
	beq	._572	@cond_branch
	mov	r0, #0x0
	bl	GetBankByPlayerAI
	ldr	r5, ._574 + 4
	strb	r0, [r5]
	ldr	r0, ._574 + 8
	ldrb	r1, [r0]
	ldr	r2, ._574 + 12
	ldrb	r0, [r5]
	lsl	r0, r0, #0x2
	add	r0, r0, r2
	ldr	r0, [r0]
	and	r1, r1, r0
	cmp	r1, #0
	beq	._572	@cond_branch
	mov	r0, #0x2
	bl	GetBankByPlayerAI
	strb	r0, [r5]
._572:
	ldr	r0, ._574 + 4
	ldrb	r2, [r0]
	lsl	r2, r2, #0x8
	orr	r2, r2, r4
	mov	r0, #0x1
	mov	r1, #0xa
	bl	dp01_build_cmdbuf_x21_a_bb
	b	._573
._575:
	.align	2, 0
._574:
	.word	gBattleMoves
	.word	gBankTarget
	.word	gAbsentBankFlags
	.word	gBitTable
._563:
	mov	r6, #0x3
._576:
	bl	Random
	add	r4, r0, #0
	and	r4, r4, r6
	lsl	r0, r4, #0x1
	add	r0, r5, r0
	ldrh	r2, [r0]
	cmp	r2, #0
	beq	._576	@cond_branch
	ldr	r1, ._579
	lsl	r0, r2, #0x1
	add	r0, r0, r2
	lsl	r0, r0, #0x2
	add	r0, r0, r1
	ldrb	r1, [r0, #0x6]
	mov	r0, #0x12
	and	r0, r0, r1
	cmp	r0, #0
	beq	._577	@cond_branch
	ldr	r0, ._579 + 4
	ldrb	r2, [r0]
	lsl	r2, r2, #0x8
	b	._578
._580:
	.align	2, 0
._579:
	.word	gBattleMoves
	.word	gActiveBank
._577:
	ldr	r0, ._583
	ldrh	r1, [r0]
	mov	r0, #0x1
	and	r0, r0, r1
	cmp	r0, #0
	beq	._581	@cond_branch
	bl	Random
	mov	r1, #0x2
	and	r1, r1, r0
	lsl	r1, r1, #0x18
	lsr	r1, r1, #0x18
	add	r0, r1, #0
	bl	GetBankByPlayerAI
	add	r2, r0, #0
	lsl	r2, r2, #0x18
	lsr	r2, r2, #0x10
._578:
	orr	r2, r2, r4
	mov	r0, #0x1
	mov	r1, #0xa
	bl	dp01_build_cmdbuf_x21_a_bb
	b	._582
._584:
	.align	2, 0
._583:
	.word	gBattleTypeFlags
._581:
	mov	r0, #0x0
	bl	GetBankByPlayerAI
	add	r2, r0, #0
	lsl	r2, r2, #0x18
	lsr	r2, r2, #0x10
	orr	r2, r2, r4
	mov	r0, #0x1
	mov	r1, #0xa
	bl	dp01_build_cmdbuf_x21_a_bb
._582:
	bl	OpponentBufferExecCompleted
._562:
	pop	{r3, r4, r5}
	mov	r8, r3
	mov	r9, r4
	mov	sl, r5
	pop	{r4, r5, r6, r7}
	pop	{r0}
	bx	r0
.syntax unified
	thumb_func_end sub_8035428

	thumb_func_start sub_8035590
sub_8035590: @ 8035590
	push {lr}
	ldr r1, _080355B4 @ =0x02000000
	ldr r0, _080355B8 @ =gActiveBank
	ldrb r0, [r0]
	lsrs r0, 1
	lsls r0, 1
	ldr r2, _080355BC @ =0x000160d4
	adds r0, r2
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x1
	bl dp01_build_cmdbuf_x23_aa_0
	bl OpponentBufferExecCompleted
	pop {r0}
	bx r0
	.align 2, 0
_080355B4: .4byte 0x02000000
_080355B8: .4byte gActiveBank
_080355BC: .4byte 0x000160d4
	thumb_func_end sub_8035590

	thumb_func_start sub_80355C0
sub_80355C0: @ 80355C0
	push {r4-r6,lr}
	ldr r6, _08035604 @ =0x02000000
	ldr r5, _08035608 @ =gActiveBank
	ldrb r0, [r5]
	bl GetBankIdentity
	lsls r0, 24
	lsrs r0, 25
	ldr r1, _0803560C @ =0x000160c8
	adds r0, r1
	adds r0, r6
	ldrb r0, [r0]
	cmp r0, 0x6
	bne _08035664
	bl sub_8036CD4
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x6
	bne _0803568A
	ldr r0, _08035610 @ =gBattleTypeFlags
	ldrh r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08035614
	movs r0, 0x1
	bl GetBankByPlayerAI
	lsls r0, 24
	lsrs r5, r0, 24
	adds r6, r5, 0
	b _08035628
	.align 2, 0
_08035604: .4byte 0x02000000
_08035608: .4byte gActiveBank
_0803560C: .4byte 0x000160c8
_08035610: .4byte gBattleTypeFlags
_08035614:
	movs r0, 0x1
	bl GetBankByPlayerAI
	lsls r0, 24
	lsrs r6, r0, 24
	movs r0, 0x3
	bl GetBankByPlayerAI
	lsls r0, 24
	lsrs r5, r0, 24
_08035628:
	movs r4, 0
	b _0803562E
_0803562C:
	adds r4, 0x1
_0803562E:
	cmp r4, 0x5
	bgt _0803568A
	movs r0, 0x64
	muls r0, r4
	ldr r1, _0803565C @ =gEnemyParty
	adds r0, r1
	movs r1, 0x39
	bl GetMonData
	cmp r0, 0
	beq _0803562C
	ldr r1, _08035660 @ =gBattlePartyID
	lsls r0, r6, 1
	adds r0, r1
	ldrh r0, [r0]
	cmp r4, r0
	beq _0803562C
	lsls r0, r5, 1
	adds r0, r1
	ldrh r0, [r0]
	cmp r4, r0
	beq _0803562C
	b _0803568A
	.align 2, 0
_0803565C: .4byte gEnemyParty
_08035660: .4byte gBattlePartyID
_08035664:
	ldrb r0, [r5]
	bl GetBankIdentity
	lsls r0, 24
	lsrs r0, 25
	ldr r2, _080356B0 @ =0x000160c8
	adds r0, r2
	adds r0, r6
	ldrb r4, [r0]
	ldrb r0, [r5]
	bl GetBankIdentity
	lsls r0, 24
	lsrs r0, 25
	ldr r1, _080356B0 @ =0x000160c8
	adds r0, r1
	adds r0, r6
	movs r1, 0x6
	strb r1, [r0]
_0803568A:
	ldr r1, _080356B4 @ =0x02000000
	ldr r0, _080356B8 @ =gActiveBank
	ldrb r0, [r0]
	ldr r2, _080356BC @ =0x00016068
	adds r0, r2
	adds r0, r1
	strb r4, [r0]
	lsls r1, r4, 24
	lsrs r1, 24
	movs r0, 0x1
	movs r2, 0
	bl dp01_build_cmdbuf_x22_a_three_bytes
	bl OpponentBufferExecCompleted
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080356B0: .4byte 0x000160c8
_080356B4: .4byte 0x02000000
_080356B8: .4byte gActiveBank
_080356BC: .4byte 0x00016068
	thumb_func_end sub_80355C0

	thumb_func_start sub_80356C0
sub_80356C0: @ 80356C0
	push {lr}
	bl OpponentBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_80356C0

	thumb_func_start OpponentHandleHealthBarUpdate
OpponentHandleHealthBarUpdate: @ 80356CC
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x4
	movs r0, 0
	bl load_gfxc_health_bar
	ldr r3, _08035744 @ =gBattleBufferA
	ldr r0, _08035748 @ =gActiveBank
	mov r9, r0
	ldrb r4, [r0]
	lsls r2, r4, 9
	adds r0, r3, 0x3
	adds r0, r2, r0
	ldrb r1, [r0]
	lsls r1, 8
	adds r3, 0x2
	adds r2, r3
	ldrb r0, [r2]
	orrs r0, r1
	lsls r0, 16
	asrs r7, r0, 16
	ldr r0, _0803574C @ =0x00007fff
	cmp r7, r0
	beq _0803575C
	ldr r6, _08035750 @ =gBattlePartyID
	lsls r0, r4, 1
	adds r0, r6
	ldrh r0, [r0]
	movs r5, 0x64
	muls r0, r5
	ldr r4, _08035754 @ =gEnemyParty
	adds r0, r4
	movs r1, 0x3A
	bl GetMonData
	mov r8, r0
	mov r1, r9
	ldrb r0, [r1]
	lsls r0, 1
	adds r0, r6
	ldrh r0, [r0]
	muls r0, r5
	adds r0, r4
	movs r1, 0x39
	bl GetMonData
	adds r3, r0, 0
	mov r1, r9
	ldrb r0, [r1]
	ldr r1, _08035758 @ =gHealthboxIDs
	adds r1, r0, r1
	ldrb r1, [r1]
	str r7, [sp]
	mov r2, r8
	bl sub_8043D84
	b _08035786
	.align 2, 0
_08035744: .4byte gBattleBufferA
_08035748: .4byte gActiveBank
_0803574C: .4byte 0x00007fff
_08035750: .4byte gBattlePartyID
_08035754: .4byte gEnemyParty
_08035758: .4byte gHealthboxIDs
_0803575C:
	ldr r1, _080357A4 @ =gBattlePartyID
	lsls r0, r4, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, _080357A8 @ =gEnemyParty
	adds r0, r1
	movs r1, 0x3A
	bl GetMonData
	adds r2, r0, 0
	mov r1, r9
	ldrb r0, [r1]
	ldr r1, _080357AC @ =gHealthboxIDs
	adds r1, r0, r1
	ldrb r1, [r1]
	str r7, [sp]
	movs r3, 0
	bl sub_8043D84
_08035786:
	ldr r1, _080357B0 @ =gBattleBankFunc
	ldr r0, _080357B4 @ =gActiveBank
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r1, _080357B8 @ =sub_80330C8
	str r1, [r0]
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080357A4: .4byte gBattlePartyID
_080357A8: .4byte gEnemyParty
_080357AC: .4byte gHealthboxIDs
_080357B0: .4byte gBattleBankFunc
_080357B4: .4byte gActiveBank
_080357B8: .4byte sub_80330C8
	thumb_func_end OpponentHandleHealthBarUpdate

	thumb_func_start OpponentHandleExpBarUpdate
OpponentHandleExpBarUpdate: @ 80357BC
	push {lr}
	bl OpponentBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end OpponentHandleExpBarUpdate

	thumb_func_start OpponentHandleStatusIconUpdate
OpponentHandleStatusIconUpdate: @ 80357C8
	push {r4,lr}
	ldr r4, _08035820 @ =gActiveBank
	ldrb r0, [r4]
	bl mplay_80342A4
	lsls r0, 24
	cmp r0, 0
	bne _08035818
	ldr r0, _08035824 @ =gHealthboxIDs
	ldrb r1, [r4]
	adds r0, r1, r0
	ldrb r0, [r0]
	ldr r2, _08035828 @ =gBattlePartyID
	lsls r1, 1
	adds r1, r2
	ldrh r2, [r1]
	movs r1, 0x64
	muls r1, r2
	ldr r2, _0803582C @ =gEnemyParty
	adds r1, r2
	movs r2, 0x9
	bl sub_8045A5C
	ldrb r0, [r4]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	ldr r0, _08035830 @ =0x02017810
	adds r1, r0
	ldrb r2, [r1]
	movs r0, 0x11
	negs r0, r0
	ands r0, r2
	strb r0, [r1]
	ldr r1, _08035834 @ =gBattleBankFunc
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r1, _08035838 @ =sub_8033494
	str r1, [r0]
_08035818:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08035820: .4byte gActiveBank
_08035824: .4byte gHealthboxIDs
_08035828: .4byte gBattlePartyID
_0803582C: .4byte gEnemyParty
_08035830: .4byte 0x02017810
_08035834: .4byte gBattleBankFunc
_08035838: .4byte sub_8033494
	thumb_func_end OpponentHandleStatusIconUpdate

	thumb_func_start OpponentHandleStatusAnimation
OpponentHandleStatusAnimation: @ 803583C
	push {r4,r5,lr}
	ldr r5, _08035894 @ =gActiveBank
	ldrb r0, [r5]
	bl mplay_80342A4
	lsls r0, 24
	cmp r0, 0
	bne _0803588C
	ldr r4, _08035898 @ =gBattleBufferA
	ldrb r3, [r5]
	lsls r3, 9
	adds r0, r4, 0x1
	adds r0, r3, r0
	ldrb r0, [r0]
	adds r1, r4, 0x2
	adds r1, r3, r1
	ldrb r1, [r1]
	adds r2, r4, 0x3
	adds r2, r3, r2
	ldrb r2, [r2]
	lsls r2, 8
	orrs r1, r2
	adds r2, r4, 0x4
	adds r2, r3, r2
	ldrb r2, [r2]
	lsls r2, 16
	orrs r1, r2
	adds r4, 0x5
	adds r3, r4
	ldrb r2, [r3]
	lsls r2, 24
	orrs r1, r2
	bl move_anim_start_t2_for_situation
	ldr r1, _0803589C @ =gBattleBankFunc
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r1
	ldr r1, _080358A0 @ =sub_8033494
	str r1, [r0]
_0803588C:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08035894: .4byte gActiveBank
_08035898: .4byte gBattleBufferA
_0803589C: .4byte gBattleBankFunc
_080358A0: .4byte sub_8033494
	thumb_func_end OpponentHandleStatusAnimation

	thumb_func_start OpponentHandleStatusXor
OpponentHandleStatusXor: @ 80358A4
	push {lr}
	bl OpponentBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end OpponentHandleStatusXor

	thumb_func_start sub_80358B0
sub_80358B0: @ 80358B0
	push {lr}
	bl OpponentBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_80358B0

	thumb_func_start OpponentHandleDMATransfer
OpponentHandleDMATransfer: @ 80358BC
	push {lr}
	bl OpponentBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end OpponentHandleDMATransfer

	thumb_func_start sub_80358C8
sub_80358C8: @ 80358C8
	push {lr}
	bl OpponentBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_80358C8

	thumb_func_start sub_80358D4
sub_80358D4: @ 80358D4
	push {lr}
	bl OpponentBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_80358D4

	thumb_func_start sub_80358E0
sub_80358E0: @ 80358E0
	push {lr}
	bl OpponentBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_80358E0

	thumb_func_start sub_80358EC
sub_80358EC: @ 80358EC
	push {lr}
	bl OpponentBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_80358EC

	thumb_func_start sub_80358F8
sub_80358F8: @ 80358F8
	push {lr}
	bl OpponentBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_80358F8

	thumb_func_start sub_8035904
sub_8035904: @ 8035904
	push {lr}
	bl OpponentBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_8035904

	thumb_func_start sub_8035910
sub_8035910: @ 8035910
	push {lr}
	ldr r2, _08035928 @ =gUnknown_020238C8
	ldrb r1, [r2]
	movs r0, 0x80
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	bl OpponentBufferExecCompleted
	pop {r0}
	bx r0
	.align 2, 0
_08035928: .4byte gUnknown_020238C8
	thumb_func_end sub_8035910

	thumb_func_start sub_803592C
sub_803592C: @ 803592C
	push {lr}
	ldr r3, _08035958 @ =gUnknown_020238C8
	ldr r1, _0803595C @ =gBattleBufferA
	ldr r0, _08035960 @ =gActiveBank
	ldrb r0, [r0]
	lsls r0, 9
	adds r1, 0x1
	adds r0, r1
	ldrb r0, [r0]
	movs r1, 0x7F
	ands r1, r0
	ldrb r2, [r3]
	movs r0, 0x80
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	bl OpponentBufferExecCompleted
	pop {r0}
	bx r0
	.align 2, 0
_08035958: .4byte gUnknown_020238C8
_0803595C: .4byte gBattleBufferA
_08035960: .4byte gActiveBank
	thumb_func_end sub_803592C

	thumb_func_start sub_8035964
sub_8035964: @ 8035964
	push {lr}
	ldr r2, _08035978 @ =gUnknown_020238C8
	ldrb r1, [r2]
	movs r0, 0x7F
	ands r0, r1
	strb r0, [r2]
	bl OpponentBufferExecCompleted
	pop {r0}
	bx r0
	.align 2, 0
_08035978: .4byte gUnknown_020238C8
	thumb_func_end sub_8035964

	thumb_func_start sub_803597C
sub_803597C: @ 803597C
	push {lr}
	ldr r3, _080359A0 @ =gUnknown_020238C8
	ldr r1, [r3]
	lsls r1, 24
	lsrs r1, 31
	movs r0, 0x1
	eors r1, r0
	lsls r1, 7
	ldrb r2, [r3]
	movs r0, 0x7F
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	bl OpponentBufferExecCompleted
	pop {r0}
	bx r0
	.align 2, 0
_080359A0: .4byte gUnknown_020238C8
	thumb_func_end sub_803597C

	thumb_func_start OpponentHandleHitAnimation
OpponentHandleHitAnimation: @ 80359A4
	push {r4,lr}
	ldr r3, _080359CC @ =gSprites
	ldr r2, _080359D0 @ =gObjectBankIDs
	ldr r4, _080359D4 @ =gActiveBank
	ldrb r0, [r4]
	adds r0, r2
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	adds r0, 0x3E
	ldrb r0, [r0]
	lsls r0, 29
	cmp r0, 0
	bge _080359D8
	bl OpponentBufferExecCompleted
	b _08035A02
	.align 2, 0
_080359CC: .4byte gSprites
_080359D0: .4byte gObjectBankIDs
_080359D4: .4byte gActiveBank
_080359D8:
	ldr r1, _08035A08 @ =gDoingBattleAnim
	movs r0, 0x1
	strb r0, [r1]
	ldrb r0, [r4]
	adds r0, r2
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	movs r1, 0
	strh r1, [r0, 0x30]
	ldrb r0, [r4]
	bl sub_8047858
	ldr r1, _08035A0C @ =gBattleBankFunc
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r1, _08035A10 @ =bx_blink_t7
	str r1, [r0]
_08035A02:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08035A08: .4byte gDoingBattleAnim
_08035A0C: .4byte gBattleBankFunc
_08035A10: .4byte bx_blink_t7
	thumb_func_end OpponentHandleHitAnimation

	thumb_func_start sub_8035A14
sub_8035A14: @ 8035A14
	push {lr}
	bl OpponentBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_8035A14

	thumb_func_start OpponentHandleEffectivenessSound
OpponentHandleEffectivenessSound: @ 8035A20
	push {r4,lr}
	ldr r4, _08035A5C @ =gActiveBank
	ldrb r0, [r4]
	bl GetBankSide
	lsls r0, 24
	movs r3, 0x3F
	cmp r0, 0
	bne _08035A34
	movs r3, 0xC0
_08035A34:
	ldr r2, _08035A60 @ =gBattleBufferA
	ldrb r1, [r4]
	lsls r1, 9
	adds r0, r2, 0x1
	adds r0, r1, r0
	ldrb r0, [r0]
	adds r2, 0x2
	adds r1, r2
	ldrb r1, [r1]
	lsls r1, 8
	orrs r0, r1
	lsls r1, r3, 24
	asrs r1, 24
	bl PlaySE12WithPanning
	bl OpponentBufferExecCompleted
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08035A5C: .4byte gActiveBank
_08035A60: .4byte gBattleBufferA
	thumb_func_end OpponentHandleEffectivenessSound

	thumb_func_start sub_8035A64
sub_8035A64: @ 8035A64
	push {lr}
	ldr r2, _08035A8C @ =gBattleBufferA
	ldr r0, _08035A90 @ =gActiveBank
	ldrb r1, [r0]
	lsls r1, 9
	adds r0, r2, 0x1
	adds r0, r1, r0
	ldrb r0, [r0]
	adds r2, 0x2
	adds r1, r2
	ldrb r1, [r1]
	lsls r1, 8
	orrs r0, r1
	bl PlayFanfare
	bl OpponentBufferExecCompleted
	pop {r0}
	bx r0
	.align 2, 0
_08035A8C: .4byte gBattleBufferA
_08035A90: .4byte gActiveBank
	thumb_func_end sub_8035A64

	thumb_func_start OpponentHandleFaintingCry
OpponentHandleFaintingCry: @ 8035A94
	push {lr}
	ldr r1, _08035AC4 @ =gBattlePartyID
	ldr r0, _08035AC8 @ =gActiveBank
	ldrb r0, [r0]
	lsls r0, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, _08035ACC @ =gEnemyParty
	adds r0, r1
	movs r1, 0xB
	bl GetMonData
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x19
	movs r2, 0x5
	bl PlayCry3
	bl OpponentBufferExecCompleted
	pop {r0}
	bx r0
	.align 2, 0
_08035AC4: .4byte gBattlePartyID
_08035AC8: .4byte gActiveBank
_08035ACC: .4byte gEnemyParty
	thumb_func_end OpponentHandleFaintingCry

	thumb_func_start dp01t_2E_7_battle_intro
dp01t_2E_7_battle_intro: @ 8035AD0
	push {lr}
	ldr r1, _08035AF8 @ =gBattleBufferA
	ldr r0, _08035AFC @ =gActiveBank
	ldrb r0, [r0]
	lsls r0, 9
	adds r1, 0x1
	adds r0, r1
	ldrb r0, [r0]
	bl sub_80E43C0
	ldr r2, _08035B00 @ =gUnknown_02024DE8
	ldrh r0, [r2]
	movs r1, 0x1
	orrs r0, r1
	strh r0, [r2]
	bl OpponentBufferExecCompleted
	pop {r0}
	bx r0
	.align 2, 0
_08035AF8: .4byte gBattleBufferA
_08035AFC: .4byte gActiveBank
_08035B00: .4byte gUnknown_02024DE8
	thumb_func_end dp01t_2E_7_battle_intro

	thumb_func_start sub_8035B04
sub_8035B04: @ 8035B04
	push {r4-r6,lr}
	ldr r5, _08035BE0 @ =gObjectBankIDs
	ldr r6, _08035BE4 @ =gActiveBank
	ldrb r0, [r6]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r4, _08035BE8 @ =gSprites
	adds r0, r4
	bl oamt_add_pos2_onto_pos1
	ldrb r0, [r6]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	movs r1, 0x23
	strh r1, [r0, 0x2E]
	ldrb r0, [r6]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	movs r1, 0x8C
	lsls r1, 1
	strh r1, [r0, 0x32]
	ldrb r0, [r6]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrh r1, [r0, 0x22]
	strh r1, [r0, 0x36]
	ldrb r0, [r6]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r4, 0
	adds r1, 0x1C
	adds r0, r1
	ldr r1, _08035BEC @ =sub_8078B34
	str r1, [r0]
	ldrb r0, [r6]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldr r1, _08035BF0 @ =sub_8035C10
	bl oamt_set_x3A_32
	ldr r0, _08035BF4 @ =sub_8035C44
	movs r1, 0x5
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r4, _08035BF8 @ =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r4
	ldrb r0, [r6]
	strh r0, [r1, 0x8]
	ldrb r3, [r6]
	lsls r0, r3, 1
	adds r0, r3
	lsls r0, 2
	ldr r2, _08035BFC @ =0x02017810
	adds r0, r2
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08035BC2
	ldr r0, _08035C00 @ =gUnknown_02024E68
	adds r0, r3, r0
	ldrb r1, [r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r4
	ldr r1, _08035C04 @ =sub_8044CA0
	str r1, [r0]
_08035BC2:
	adds r2, 0x30
	ldrb r0, [r2, 0x9]
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r2, 0x9]
	ldr r1, _08035C08 @ =gBattleBankFunc
	ldrb r0, [r6]
	lsls r0, 2
	adds r0, r1
	ldr r1, _08035C0C @ =nullsub_45
	str r1, [r0]
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08035BE0: .4byte gObjectBankIDs
_08035BE4: .4byte gActiveBank
_08035BE8: .4byte gSprites
_08035BEC: .4byte sub_8078B34
_08035BF0: .4byte sub_8035C10
_08035BF4: .4byte sub_8035C44
_08035BF8: .4byte gTasks
_08035BFC: .4byte 0x02017810
_08035C00: .4byte gUnknown_02024E68
_08035C04: .4byte sub_8044CA0
_08035C08: .4byte gBattleBankFunc
_08035C0C: .4byte nullsub_45
	thumb_func_end sub_8035B04

	thumb_func_start sub_8035C10
sub_8035C10: @ 8035C10
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x6]
	bl sub_8031B74
	ldrh r0, [r4, 0x38]
	ldr r1, _08035C3C @ =0x000003ff
	ands r1, r0
	ldrh r2, [r4, 0x4]
	ldr r0, _08035C40 @ =0xfffffc00
	ands r0, r2
	orrs r0, r1
	strh r0, [r4, 0x4]
	adds r0, r4, 0
	bl FreeSpriteOamMatrix
	adds r0, r4, 0
	bl DestroySprite
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08035C3C: .4byte 0x000003ff
_08035C40: .4byte 0xfffffc00
	thumb_func_end sub_8035C10

	thumb_func_start sub_8035C44
sub_8035C44: @ 8035C44
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldr r7, _08035C9C @ =gActiveBank
	ldrb r0, [r7]
	mov r9, r0
	ldr r1, _08035CA0 @ =gTasks
	mov r2, r8
	lsls r0, r2, 2
	add r0, r8
	lsls r0, 3
	adds r0, r1
	ldrh r0, [r0, 0x8]
	strb r0, [r7]
	bl IsDoubleBattle
	lsls r0, 24
	cmp r0, 0
	beq _08035C7E
	ldr r0, _08035CA4 @ =gBattleTypeFlags
	ldrh r1, [r0]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _08035CB0
_08035C7E:
	ldr r0, _08035CA8 @ =gBattleBufferA
	ldrb r1, [r7]
	lsls r2, r1, 9
	adds r0, 0x1
	adds r2, r0
	ldr r0, _08035CAC @ =gBattlePartyID
	lsls r1, 1
	adds r1, r0
	ldrh r0, [r1]
	strb r0, [r2]
	ldrb r0, [r7]
	movs r1, 0
	bl sub_803495C
	b _08035CF0
	.align 2, 0
_08035C9C: .4byte gActiveBank
_08035CA0: .4byte gTasks
_08035CA4: .4byte gBattleTypeFlags
_08035CA8: .4byte gBattleBufferA
_08035CAC: .4byte gBattlePartyID
_08035CB0:
	ldr r4, _08035D14 @ =gBattleBufferA
	ldrb r0, [r7]
	lsls r1, r0, 9
	adds r4, 0x1
	adds r1, r4
	ldr r6, _08035D18 @ =gBattlePartyID
	lsls r0, 1
	adds r0, r6
	ldrh r0, [r0]
	strb r0, [r1]
	ldrb r0, [r7]
	movs r1, 0
	bl sub_803495C
	ldrb r0, [r7]
	movs r5, 0x2
	eors r0, r5
	strb r0, [r7]
	ldrb r0, [r7]
	lsls r1, r0, 9
	adds r1, r4
	lsls r0, 1
	adds r0, r6
	ldrh r0, [r0]
	strb r0, [r1]
	ldrb r0, [r7]
	movs r1, 0
	bl sub_803495C
	ldrb r0, [r7]
	eors r0, r5
	strb r0, [r7]
_08035CF0:
	ldr r1, _08035D1C @ =gBattleBankFunc
	ldr r2, _08035D20 @ =gActiveBank
	ldrb r0, [r2]
	lsls r0, 2
	adds r0, r1
	ldr r1, _08035D24 @ =sub_8032E2C
	str r1, [r0]
	mov r0, r9
	strb r0, [r2]
	mov r0, r8
	bl DestroyTask
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08035D14: .4byte gBattleBufferA
_08035D18: .4byte gBattlePartyID
_08035D1C: .4byte gBattleBankFunc
_08035D20: .4byte gActiveBank
_08035D24: .4byte sub_8032E2C
	thumb_func_end sub_8035C44

	thumb_func_start dp01t_30_7_0803D67C
dp01t_30_7_0803D67C: @ 8035D28
	push {r4-r6,lr}
	ldr r1, _08035D50 @ =gBattleBufferA
	ldr r0, _08035D54 @ =gActiveBank
	ldrb r2, [r0]
	lsls r0, r2, 9
	adds r1, 0x1
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _08035D58
	adds r0, r2, 0
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _08035D58
	bl OpponentBufferExecCompleted
	b _08035E12
	.align 2, 0
_08035D50: .4byte gBattleBufferA
_08035D54: .4byte gActiveBank
_08035D58:
	ldr r3, _08035DA8 @ =gActiveBank
	ldrb r1, [r3]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	ldr r4, _08035DAC @ =0x02017810
	adds r0, r4
	ldrb r1, [r0]
	movs r2, 0x1
	orrs r1, r2
	strb r1, [r0]
	ldr r1, _08035DB0 @ =gBattleBufferA
	ldrb r2, [r3]
	lsls r0, r2, 9
	adds r1, 0x2
	adds r0, r1
	ldrb r0, [r0]
	adds r6, r3, 0
	cmp r0, 0
	beq _08035DBC
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r3, r0, r4
	ldrb r2, [r3, 0x1]
	lsls r1, r2, 26
	lsrs r0, r1, 27
	cmp r0, 0x1
	bhi _08035DB4
	adds r0, 0x1
	movs r1, 0x1F
	ands r0, r1
	lsls r0, 1
	movs r1, 0x3F
	negs r1, r1
	ands r1, r2
	orrs r1, r0
	strb r1, [r3, 0x1]
	b _08035E12
	.align 2, 0
_08035DA8: .4byte gActiveBank
_08035DAC: .4byte 0x02017810
_08035DB0: .4byte gBattleBufferA
_08035DB4:
	movs r0, 0x3F
	negs r0, r0
	ands r0, r2
	strb r0, [r3, 0x1]
_08035DBC:
	adds r5, r6, 0
	ldrb r0, [r5]
	lsls r3, r0, 9
	ldr r4, _08035E18 @ =gUnknown_02023A64
	adds r1, r3, r4
	subs r2, r4, 0x3
	adds r2, r3, r2
	ldrb r2, [r2]
	subs r4, 0x2
	adds r3, r4
	ldrb r3, [r3]
	bl sub_8044804
	ldr r2, _08035E1C @ =gUnknown_02024E68
	ldrb r1, [r5]
	adds r1, r2
	movs r2, 0
	strb r0, [r1]
	ldrb r1, [r5]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	ldr r3, _08035E20 @ =0x02017810
	adds r0, r3
	strb r2, [r0, 0x5]
	ldrb r1, [r5]
	lsls r0, r1, 9
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0
	beq _08035E06
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	movs r1, 0x5D
	strb r1, [r0, 0x5]
_08035E06:
	ldr r0, _08035E24 @ =gBattleBankFunc
	ldrb r1, [r6]
	lsls r1, 2
	adds r1, r0
	ldr r0, _08035E28 @ =sub_8035E2C
	str r0, [r1]
_08035E12:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08035E18: .4byte gUnknown_02023A64
_08035E1C: .4byte gUnknown_02024E68
_08035E20: .4byte 0x02017810
_08035E24: .4byte gBattleBankFunc
_08035E28: .4byte sub_8035E2C
	thumb_func_end dp01t_30_7_0803D67C

	thumb_func_start sub_8035E2C
sub_8035E2C: @ 8035E2C
	push {r4,lr}
	ldr r4, _08035E64 @ =gActiveBank
	ldrb r1, [r4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	ldr r3, _08035E68 @ =0x02017810
	adds r0, r3
	ldrb r1, [r0, 0x5]
	adds r2, r1, 0x1
	strb r2, [r0, 0x5]
	lsls r1, 24
	lsrs r1, 24
	cmp r1, 0x5C
	bls _08035E5C
	ldrb r0, [r4]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r3
	movs r0, 0
	strb r0, [r1, 0x5]
	bl OpponentBufferExecCompleted
_08035E5C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08035E64: .4byte gActiveBank
_08035E68: .4byte 0x02017810
	thumb_func_end sub_8035E2C

	thumb_func_start sub_8035E6C
sub_8035E6C: @ 8035E6C
	push {lr}
	ldr r0, _08035EA4 @ =gActiveBank
	ldrb r3, [r0]
	lsls r0, r3, 1
	adds r0, r3
	lsls r0, 2
	ldr r1, _08035EA8 @ =0x02017810
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08035E9A
	ldr r2, _08035EAC @ =gTasks
	ldr r0, _08035EB0 @ =gUnknown_02024E68
	adds r0, r3, r0
	ldrb r1, [r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	ldr r1, _08035EB4 @ =sub_8044CA0
	str r1, [r0]
_08035E9A:
	bl OpponentBufferExecCompleted
	pop {r0}
	bx r0
	.align 2, 0
_08035EA4: .4byte gActiveBank
_08035EA8: .4byte 0x02017810
_08035EAC: .4byte gTasks
_08035EB0: .4byte gUnknown_02024E68
_08035EB4: .4byte sub_8044CA0
	thumb_func_end sub_8035E6C

	thumb_func_start sub_8035EB8
sub_8035EB8: @ 8035EB8
	push {lr}
	bl OpponentBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end sub_8035EB8

	thumb_func_start OpponentHandleSpriteInvisibility
OpponentHandleSpriteInvisibility: @ 8035EC4
	push {r4,lr}
	ldr r4, _08035F14 @ =gActiveBank
	ldrb r0, [r4]
	bl sub_8078874
	lsls r0, 24
	cmp r0, 0
	beq _08035F0A
	ldr r3, _08035F18 @ =gSprites
	ldr r0, _08035F1C @ =gObjectBankIDs
	ldrb r1, [r4]
	adds r0, r1, r0
	ldrb r0, [r0]
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	adds r2, r3
	ldr r0, _08035F20 @ =gBattleBufferA
	lsls r1, 9
	adds r0, 0x1
	adds r1, r0
	adds r2, 0x3E
	movs r0, 0x1
	ldrb r1, [r1]
	ands r1, r0
	lsls r1, 2
	ldrb r3, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r3
	orrs r0, r1
	strb r0, [r2]
	ldrb r0, [r4]
	bl sub_8031F88
_08035F0A:
	bl OpponentBufferExecCompleted
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08035F14: .4byte gActiveBank
_08035F18: .4byte gSprites
_08035F1C: .4byte gObjectBankIDs
_08035F20: .4byte gBattleBufferA
	thumb_func_end OpponentHandleSpriteInvisibility

	thumb_func_start OpponentHandleBattleAnimation
OpponentHandleBattleAnimation: @ 8035F24
	push {r4-r6,lr}
	sub sp, 0x4
	ldr r6, _08035F68 @ =gActiveBank
	ldrb r0, [r6]
	bl mplay_80342A4
	lsls r0, 24
	cmp r0, 0
	bne _08035F7C
	ldr r5, _08035F6C @ =gBattleBufferA
	ldrb r2, [r6]
	lsls r1, r2, 9
	adds r0, r5, 0x1
	adds r0, r1, r0
	ldrb r3, [r0]
	adds r0, r5, 0x2
	adds r0, r1, r0
	ldrb r4, [r0]
	adds r5, 0x3
	adds r1, r5
	ldrb r0, [r1]
	lsls r0, 8
	orrs r4, r0
	str r4, [sp]
	adds r0, r2, 0
	adds r1, r2, 0
	bl move_anim_start_t3
	lsls r0, 24
	cmp r0, 0
	beq _08035F70
	bl OpponentBufferExecCompleted
	b _08035F7C
	.align 2, 0
_08035F68: .4byte gActiveBank
_08035F6C: .4byte gBattleBufferA
_08035F70:
	ldr r0, _08035F84 @ =gBattleBankFunc
	ldrb r1, [r6]
	lsls r1, 2
	adds r1, r0
	ldr r0, _08035F88 @ =sub_80334C0
	str r0, [r1]
_08035F7C:
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08035F84: .4byte gBattleBankFunc
_08035F88: .4byte sub_80334C0
	thumb_func_end OpponentHandleBattleAnimation

	thumb_func_start OpponentHandleLinkStandbyMsg
OpponentHandleLinkStandbyMsg: @ 8035F8C
	push {lr}
	bl OpponentBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end OpponentHandleLinkStandbyMsg

	thumb_func_start OpponentHandleResetActionMoveSelection
OpponentHandleResetActionMoveSelection: @ 8035F98
	push {lr}
	bl OpponentBufferExecCompleted
	pop {r0}
	bx r0
	thumb_func_end OpponentHandleResetActionMoveSelection

	thumb_func_start sub_8035FA4
sub_8035FA4: @ 8035FA4
	push {lr}
	ldr r0, _08035FD8 @ =gBattleTypeFlags
	ldrh r1, [r0]
	movs r0, 0x6
	ands r0, r1
	cmp r0, 0x2
	bne _08035FCE
	ldr r2, _08035FDC @ =gMain
	ldr r0, _08035FE0 @ =0x0000043d
	adds r3, r2, r0
	ldrb r1, [r3]
	movs r0, 0x3
	negs r0, r0
	ands r0, r1
	strb r0, [r3]
	ldr r0, _08035FE4 @ =gPreBattleCallback1
	ldr r0, [r0]
	str r0, [r2]
	ldr r0, [r2, 0x8]
	bl SetMainCallback2
_08035FCE:
	bl OpponentBufferExecCompleted
	pop {r0}
	bx r0
	.align 2, 0
_08035FD8: .4byte gBattleTypeFlags
_08035FDC: .4byte gMain
_08035FE0: .4byte 0x0000043d
_08035FE4: .4byte gPreBattleCallback1
	thumb_func_end sub_8035FA4

	thumb_func_start nullsub_46
nullsub_46: @ 8035FE8
	bx lr
	thumb_func_end nullsub_46

	.align 2, 0 @ Don't pad with nop.
