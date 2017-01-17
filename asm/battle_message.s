	.include "constants/gba_constants.inc"
	.include "constants/species_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_8120AA8
sub_8120AA8: @ 8120AA8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r0, 16
	lsrs r7, r0, 16
	movs r6, 0
	ldr r5, _08120B70 @ =gUnknown_02039270
	ldr r4, _08120B74 @ =gUnknown_02024A60
	ldrb r1, [r4]
	lsls r1, 9
	ldr r0, _08120B78 @ =gUnknown_02023A64
	adds r1, r0
	str r1, [r5]
	ldr r2, _08120B7C @ =gUnknown_02024C04
	ldrh r0, [r1, 0x4]
	strh r0, [r2]
	ldr r2, _08120B80 @ =byte_2024C06
	ldrb r0, [r1, 0x6]
	strb r0, [r2]
	ldr r3, _08120B84 @ =0x02000000
	ldrb r0, [r1, 0x7]
	mov r8, r0
	ldr r2, _08120B88 @ =0x00016003
	adds r0, r3, r2
	mov r2, r8
	strb r2, [r0]
	ldrb r0, [r1, 0x8]
	mov r8, r0
	ldr r2, _08120B8C @ =0x0001605e
	adds r0, r3, r2
	mov r2, r8
	strb r2, [r0]
	ldrb r0, [r1, 0x9]
	mov r8, r0
	ldr r2, _08120B90 @ =0x000160c1
	adds r0, r3, r2
	mov r2, r8
	strb r2, [r0]
	ldr r2, _08120B94 @ =gUnknown_02024C0B
	ldrb r0, [r1, 0xA]
	strb r0, [r2]
	ldrb r1, [r1, 0xB]
	ldr r2, _08120B98 @ =0x000160a0
	adds r0, r3, r2
	strb r1, [r0]
	movs r2, 0
	mov r9, r3
	ldr r3, _08120B9C @ =gUnknown_030041C0
	mov r10, r3
	ldr r3, _08120BA0 @ =gUnknown_0203926C
_08120B10:
	adds r0, r2, r3
	ldr r1, [r5]
	adds r1, 0xC
	adds r1, r2
	ldrb r1, [r1]
	strb r1, [r0]
	adds r2, 0x1
	cmp r2, 0x3
	ble _08120B10
	movs r2, 0
	ldr r0, _08120B9C @ =gUnknown_030041C0
	mov r8, r0
	ldr r3, _08120B70 @ =gUnknown_02039270
	ldr r1, _08120BA4 @ =gUnknown_03004290
	mov r12, r1
	ldr r5, _08120BA8 @ =gUnknown_030042B0
_08120B30:
	mov r0, r8
	adds r1, r2, r0
	ldr r0, [r3]
	adds r0, 0x10
	adds r0, r2
	ldrb r0, [r0]
	strb r0, [r1]
	mov r0, r12
	adds r1, r2, r0
	ldr r0, [r3]
	adds r0, 0x20
	adds r0, r2
	ldrb r0, [r0]
	strb r0, [r1]
	adds r1, r2, r5
	ldr r0, [r3]
	adds r0, 0x30
	adds r0, r2
	ldrb r0, [r0]
	strb r0, [r1]
	adds r2, 0x1
	cmp r2, 0xF
	ble _08120B30
	cmp r7, 0x5
	bls _08120B64
	b _08120F78
_08120B64:
	lsls r0, r7, 2
	ldr r1, _08120BAC @ =_08120BB0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08120B70: .4byte gUnknown_02039270
_08120B74: .4byte gUnknown_02024A60
_08120B78: .4byte gUnknown_02023A64
_08120B7C: .4byte gUnknown_02024C04
_08120B80: .4byte byte_2024C06
_08120B84: .4byte 0x02000000
_08120B88: .4byte 0x00016003
_08120B8C: .4byte 0x0001605e
_08120B90: .4byte 0x000160c1
_08120B94: .4byte gUnknown_02024C0B
_08120B98: .4byte 0x000160a0
_08120B9C: .4byte gUnknown_030041C0
_08120BA0: .4byte gUnknown_0203926C
_08120BA4: .4byte gUnknown_03004290
_08120BA8: .4byte gUnknown_030042B0
_08120BAC: .4byte _08120BB0
	.align 2, 0
_08120BB0:
	.4byte _08120BC8
	.4byte _08120C48
	.4byte _08120CE4
	.4byte _08120D7C
	.4byte _08120E10
	.4byte _08120E78
_08120BC8:
	ldr r0, _08120BEC @ =gBattleTypeFlags
	ldrh r1, [r0]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _08120C08
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08120BF8
	movs r0, 0x40
	ands r0, r1
	ldr r6, _08120BF0 @ =gUnknown_084005C7
	cmp r0, 0
	bne _08120BE8
	b _08120FA2
_08120BE8:
	ldr r6, _08120BF4 @ =gUnknown_084005DB
	b _08120FA2
	.align 2, 0
_08120BEC: .4byte gBattleTypeFlags
_08120BF0: .4byte gUnknown_084005C7
_08120BF4: .4byte gUnknown_084005DB
_08120BF8:
	ldr r6, _08120C00 @ =gUnknown_084005AA
	ldr r0, _08120C04 @ =0x0000ffff
	b _08120F9A
	.align 2, 0
_08120C00: .4byte gUnknown_084005AA
_08120C04: .4byte 0x0000ffff
_08120C08:
	movs r0, 0x80
	lsls r0, 6
	ands r0, r1
	cmp r0, 0
	beq _08120C1C
	ldr r6, _08120C18 @ =gUnknown_08400568
	b _08120FA2
	.align 2, 0
_08120C18: .4byte gUnknown_08400568
_08120C1C:
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08120C2C
	ldr r6, _08120C28 @ =gUnknown_08400590
	b _08120FA2
	.align 2, 0
_08120C28: .4byte gUnknown_08400590
_08120C2C:
	movs r0, 0x80
	lsls r0, 2
	ands r0, r1
	ldr r6, _08120C40 @ =gUnknown_08400555
	cmp r0, 0
	bne _08120C3A
	b _08120FA2
_08120C3A:
	ldr r6, _08120C44 @ =gUnknown_0840057B
	b _08120FA2
	.align 2, 0
_08120C40: .4byte gUnknown_08400555
_08120C44: .4byte gUnknown_0840057B
_08120C48:
	ldrb r0, [r4]
	bl battle_side_get_owner
	lsls r0, 24
	cmp r0, 0
	bne _08120C84
	ldr r0, _08120C70 @ =gBattleTypeFlags
	ldrh r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08120C7C
	movs r0, 0x40
	ands r0, r1
	ldr r6, _08120C74 @ =gUnknown_084006A4
	cmp r0, 0
	bne _08120C6C
	b _08120FA2
_08120C6C:
	ldr r6, _08120C78 @ =gUnknown_084006F1
	b _08120FA2
	.align 2, 0
_08120C70: .4byte gBattleTypeFlags
_08120C74: .4byte gUnknown_084006A4
_08120C78: .4byte gUnknown_084006F1
_08120C7C:
	ldr r6, _08120C80 @ =gUnknown_0840069C
	b _08120FA2
	.align 2, 0
_08120C80: .4byte gUnknown_0840069C
_08120C84:
	ldr r0, _08120C9C @ =gBattleTypeFlags
	ldrh r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08120CC4
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _08120CA4
	ldr r6, _08120CA0 @ =gUnknown_0840065C
	b _08120FA2
	.align 2, 0
_08120C9C: .4byte gBattleTypeFlags
_08120CA0: .4byte gUnknown_0840065C
_08120CA4:
	movs r0, 0x2
	ands r0, r1
	ldr r6, _08120CB8 @ =gUnknown_08400645
	cmp r0, 0
	beq _08120CB0
	b _08120FA2
_08120CB0:
	ldr r6, _08120CBC @ =gUnknown_08400608
	ldr r0, _08120CC0 @ =0x0000ffff
	b _08120F9A
	.align 2, 0
_08120CB8: .4byte gUnknown_08400645
_08120CBC: .4byte gUnknown_08400608
_08120CC0: .4byte 0x0000ffff
_08120CC4:
	movs r0, 0x2
	ands r0, r1
	ldr r6, _08120CD8 @ =gUnknown_08400635
	cmp r0, 0
	beq _08120CD0
	b _08120FA2
_08120CD0:
	ldr r6, _08120CDC @ =gUnknown_084005F5
	ldr r0, _08120CE0 @ =0x0000ffff
	b _08120F9A
	.align 2, 0
_08120CD8: .4byte gUnknown_08400635
_08120CDC: .4byte gUnknown_084005F5
_08120CE0: .4byte 0x0000ffff
_08120CE4:
	ldrb r0, [r4]
	bl battle_side_get_owner
	lsls r0, 24
	cmp r0, 0
	bne _08120D3C
	ldr r0, _08120D00 @ =0x02000000
	ldr r1, _08120D04 @ =0x000160c1
	adds r0, r1
	ldrb r2, [r0]
	cmp r2, 0
	bne _08120D0C
	ldr r6, _08120D08 @ =gUnknown_08400709
	b _08120FA2
	.align 2, 0
_08120D00: .4byte 0x02000000
_08120D04: .4byte 0x000160c1
_08120D08: .4byte gUnknown_08400709
_08120D0C:
	cmp r2, 0x1
	beq _08120D1C
	ldr r0, _08120D20 @ =gBattleTypeFlags
	ldrh r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08120D28
_08120D1C:
	ldr r6, _08120D24 @ =gUnknown_08400727
	b _08120FA2
	.align 2, 0
_08120D20: .4byte gBattleTypeFlags
_08120D24: .4byte gUnknown_08400727
_08120D28:
	ldr r6, _08120D34 @ =gUnknown_08400749
	cmp r2, 0x2
	beq _08120D30
	b _08120FA2
_08120D30:
	ldr r6, _08120D38 @ =gUnknown_08400736
	b _08120FA2
	.align 2, 0
_08120D34: .4byte gUnknown_08400749
_08120D38: .4byte gUnknown_08400736
_08120D3C:
	ldr r0, _08120D5C @ =gTrainerBattleOpponent
	ldrh r1, [r0]
	movs r0, 0x80
	lsls r0, 4
	cmp r1, r0
	bne _08120D6C
	ldr r0, _08120D60 @ =gBattleTypeFlags
	ldrh r1, [r0]
	movs r0, 0x40
	ands r0, r1
	ldr r6, _08120D64 @ =gUnknown_08400771
	cmp r0, 0
	bne _08120D58
	b _08120FA2
_08120D58:
	ldr r6, _08120D68 @ =gUnknown_08400781
	b _08120FA2
	.align 2, 0
_08120D5C: .4byte gTrainerBattleOpponent
_08120D60: .4byte gBattleTypeFlags
_08120D64: .4byte gUnknown_08400771
_08120D68: .4byte gUnknown_08400781
_08120D6C:
	ldr r6, _08120D74 @ =gUnknown_0840075E
	ldr r0, _08120D78 @ =0x0000ffff
	b _08120F9A
	.align 2, 0
_08120D74: .4byte gUnknown_0840075E
_08120D78: .4byte 0x0000ffff
_08120D7C:
	ldr r0, _08120DA8 @ =0x00016003
	add r0, r9
	ldrb r0, [r0]
	bl battle_side_get_owner
	lsls r0, 24
	cmp r0, 0
	bne _08120DD8
	ldr r0, _08120DAC @ =0x000160c1
	add r0, r9
	ldrb r3, [r0]
	cmp r3, 0
	beq _08120DA2
	ldr r0, _08120DB0 @ =gBattleTypeFlags
	ldrh r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08120DB8
_08120DA2:
	ldr r6, _08120DB4 @ =gUnknown_084006B3
	b _08120FA2
	.align 2, 0
_08120DA8: .4byte 0x00016003
_08120DAC: .4byte 0x000160c1
_08120DB0: .4byte gBattleTypeFlags
_08120DB4: .4byte gUnknown_084006B3
_08120DB8:
	cmp r3, 0x1
	bne _08120DC4
	ldr r6, _08120DC0 @ =gUnknown_084006BB
	b _08120FA2
	.align 2, 0
_08120DC0: .4byte gUnknown_084006BB
_08120DC4:
	ldr r6, _08120DD0 @ =gUnknown_084006D5
	cmp r3, 0x2
	beq _08120DCC
	b _08120FA2
_08120DCC:
	ldr r6, _08120DD4 @ =gUnknown_084006C6
	b _08120FA2
	.align 2, 0
_08120DD0: .4byte gUnknown_084006D5
_08120DD4: .4byte gUnknown_084006C6
_08120DD8:
	ldr r0, _08120DF4 @ =gBattleTypeFlags
	ldrh r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08120E00
	movs r0, 0x40
	ands r0, r1
	ldr r6, _08120DF8 @ =gUnknown_0840067C
	cmp r0, 0
	bne _08120DF0
	b _08120FA2
_08120DF0:
	ldr r6, _08120DFC @ =gUnknown_0840068C
	b _08120FA2
	.align 2, 0
_08120DF4: .4byte gBattleTypeFlags
_08120DF8: .4byte gUnknown_0840067C
_08120DFC: .4byte gUnknown_0840068C
_08120E00:
	ldr r6, _08120E08 @ =gUnknown_08400622
	ldr r0, _08120E0C @ =0x0000ffff
	b _08120F9A
	.align 2, 0
_08120E08: .4byte gUnknown_08400622
_08120E0C: .4byte 0x0000ffff
_08120E10:
	mov r0, r10
	bl sub_8121D1C
	ldr r0, _08120E3C @ =gUnknown_02039270
	ldr r2, [r0]
	ldrh r1, [r2]
	movs r0, 0xB1
	lsls r0, 1
	cmp r1, r0
	bls _08120E50
	ldr r0, _08120E40 @ =gUnknown_03004290
	ldr r2, _08120E44 @ =gUnknown_08401674
	ldr r1, _08120E48 @ =0x02000000
	ldr r3, _08120E4C @ =0x000160a0
	adds r1, r3
	ldrb r1, [r1]
	lsls r1, 2
	adds r1, r2
	ldr r1, [r1]
	bl StringCopy
	b _08120E60
	.align 2, 0
_08120E3C: .4byte gUnknown_02039270
_08120E40: .4byte gUnknown_03004290
_08120E44: .4byte gUnknown_08401674
_08120E48: .4byte 0x02000000
_08120E4C: .4byte 0x000160a0
_08120E50:
	ldr r0, _08120E6C @ =gUnknown_03004290
	ldrh r2, [r2]
	movs r1, 0xD
	muls r1, r2
	ldr r2, _08120E70 @ =gMoveNames
	adds r1, r2
	bl StringCopy
_08120E60:
	ldr r0, _08120E6C @ =gUnknown_03004290
	bl sub_8121D74
	ldr r6, _08120E74 @ =gUnknown_084007BD
	b _08120FA2
	.align 2, 0
_08120E6C: .4byte gUnknown_03004290
_08120E70: .4byte gMoveNames
_08120E74: .4byte gUnknown_084007BD
_08120E78:
	ldr r5, _08120EB8 @ =gUnknown_030041C0
	ldrb r1, [r5]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _08120EE0
	movs r0, 0x7F
	ands r0, r1
	strb r0, [r5]
	ldrb r0, [r4]
	bl battle_side_get_owner
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _08120EA4
	ldrb r1, [r5]
	cmp r1, 0x3
	beq _08120EA4
	movs r0, 0x3
	eors r0, r1
	strb r0, [r5]
_08120EA4:
	ldr r0, _08120EB8 @ =gUnknown_030041C0
	ldrb r0, [r0]
	subs r0, 0x2
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bhi _08120EC0
	ldr r6, _08120EBC @ =gUnknown_083FFEFC
	b _08120FA2
	.align 2, 0
_08120EB8: .4byte gUnknown_030041C0
_08120EBC: .4byte gUnknown_083FFEFC
_08120EC0:
	ldr r0, _08120ED4 @ =gBattleTypeFlags
	ldrh r1, [r0]
	movs r0, 0x40
	ands r0, r1
	ldr r6, _08120ED8 @ =gUnknown_083FFFEA
	cmp r0, 0
	beq _08120FA2
	ldr r6, _08120EDC @ =gUnknown_083FFFF7
	b _08120FA2
	.align 2, 0
_08120ED4: .4byte gBattleTypeFlags
_08120ED8: .4byte gUnknown_083FFFEA
_08120EDC: .4byte gUnknown_083FFFF7
_08120EE0:
	ldrb r0, [r4]
	bl battle_side_get_owner
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _08120EFA
	ldrb r1, [r5]
	cmp r1, 0x3
	beq _08120EFA
	movs r0, 0x3
	eors r0, r1
	strb r0, [r5]
_08120EFA:
	ldr r0, _08120F18 @ =gBattleTypeFlags
	ldrh r1, [r0]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _08120F40
	ldr r0, _08120F1C @ =gUnknown_030041C0
	ldrb r0, [r0]
	cmp r0, 0x2
	beq _08120F30
	cmp r0, 0x2
	bgt _08120F20
	cmp r0, 0x1
	beq _08120F26
	b _08120FA2
	.align 2, 0
_08120F18: .4byte gBattleTypeFlags
_08120F1C: .4byte gUnknown_030041C0
_08120F20:
	cmp r0, 0x3
	beq _08120F38
	b _08120FA2
_08120F26:
	ldr r6, _08120F2C @ =gUnknown_083FFF6A
	b _08120FA2
	.align 2, 0
_08120F2C: .4byte gUnknown_083FFF6A
_08120F30:
	ldr r6, _08120F34 @ =gUnknown_083FFF99
	b _08120FA2
	.align 2, 0
_08120F34: .4byte gUnknown_083FFF99
_08120F38:
	ldr r6, _08120F3C @ =gUnknown_083FFFCB
	b _08120FA2
	.align 2, 0
_08120F3C: .4byte gUnknown_083FFFCB
_08120F40:
	ldr r0, _08120F54 @ =gUnknown_030041C0
	ldrb r0, [r0]
	cmp r0, 0x2
	beq _08120F68
	cmp r0, 0x2
	bgt _08120F58
	cmp r0, 0x1
	beq _08120F5E
	b _08120FA2
	.align 2, 0
_08120F54: .4byte gUnknown_030041C0
_08120F58:
	cmp r0, 0x3
	beq _08120F70
	b _08120FA2
_08120F5E:
	ldr r6, _08120F64 @ =gUnknown_083FFF56
	b _08120FA2
	.align 2, 0
_08120F64: .4byte gUnknown_083FFF56
_08120F68:
	ldr r6, _08120F6C @ =gUnknown_083FFF81
	b _08120FA2
	.align 2, 0
_08120F6C: .4byte gUnknown_083FFF81
_08120F70:
	ldr r6, _08120F74 @ =gUnknown_083FFFB3
	b _08120FA2
	.align 2, 0
_08120F74: .4byte gUnknown_083FFFB3
_08120F78:
	movs r0, 0xB5
	lsls r0, 1
	cmp r7, r0
	bls _08120F8C
	ldr r1, _08120F88 @ =gUnknown_020238CC
	movs r0, 0xFF
	strb r0, [r1]
	b _08120FA8
	.align 2, 0
_08120F88: .4byte gUnknown_020238CC
_08120F8C:
	ldr r1, _08120FB8 @ =gUnknown_08400F8C
	adds r0, r7, 0
	subs r0, 0xC
	lsls r0, 2
	adds r0, r1
	ldr r6, [r0]
	adds r0, r7, 0
_08120F9A:
	adds r1, r6, 0
	bl de_sub_804110C
	adds r6, r0, 0
_08120FA2:
	adds r0, r6, 0
	bl get_battle_strings_
_08120FA8:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08120FB8: .4byte gUnknown_08400F8C
	thumb_func_end sub_8120AA8

	thumb_func_start get_battle_strings_
get_battle_strings_: @ 8120F88
	push {lr}
	ldr r1, _08120F94 @ =gUnknown_020238CC
	bl sub_8120FFC
	pop {r1}
	bx r1
	.align 2, 0
_08120F94: .4byte gUnknown_020238CC
	thumb_func_end get_battle_strings_

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

	thumb_func_start sub_8120FFC
sub_8120FFC: @ 8120FFC
	.fill 2472
	thumb_func_end sub_8120FFC

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
	bne _08121A82
	b _de_08121D26
_08121A82:
	adds r0, r7, r5
	ldrb r1, [r0]
	adds r2, r0, 0
	cmp r1, 0xA
	bls _08121A8E
	b _08121D1C
_08121A8E:
	lsls r0, r1, 2
	ldr r1, _08121A98 @ =_08121A9C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08121A98: .4byte _08121A9C
	.align 2, 0
_08121A9C:
	.4byte _08121AC8
	.4byte _08121AF0
	.4byte _08121B48
	.4byte _08121B60
	.4byte _08121B70
	.4byte _08121BF0
	.4byte _08121C04
	.4byte _08121C16
	.4byte _08121C5C
	.4byte _08121C70
	.4byte _08121C8C
_08121AC8:
	adds r0, r5, r7
	ldrb r2, [r0, 0x1]
	ldrb r0, [r0, 0x2]
	lsls r0, 8
	orrs r2, r0
	cmp r2, 0xD1
	beq _08121ADA
	cmp r2, 0xD3
	bne _08121ADC
_08121ADA:
	adds r5, 0x3
_08121ADC:
	ldr r0, _08121AEC @ =gUnknown_08400F8C
	adds r1, r2, 0
	subs r1, 0xC
	lsls r1, 2
	adds r1, r0
	ldr r1, [r1]
	b _08121CFA
	.align 2, 0
_08121AEC: .4byte gUnknown_08400F8C
_08121AF0:
	adds r1, r2, 0
	ldrb r0, [r1, 0x1]
	cmp r0, 0x2
	beq _08121B0C
	cmp r0, 0x2
	bgt _08121B02
	cmp r0, 0x1
	beq _08121B08
	b _08121B32
_08121B02:
	cmp r0, 0x4
	beq _08121B18
	b _08121B32
_08121B08:
	ldrb r1, [r1, 0x3]
	b _08121B30
_08121B0C:
	ldrb r0, [r1, 0x3]
	mov r8, r0
	ldrb r0, [r1, 0x4]
	lsls r0, 8
	mov r1, r8
	b _08121B2E
_08121B18:
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
_08121B2E:
	orrs r1, r0
_08121B30:
	mov r8, r1
_08121B32:
	adds r4, r5, r7
	ldrb r3, [r4, 0x2]
	adds r0, r6, 0
	mov r1, r8
	movs r2, 0
	bl ConvertIntToDecimalStringN
	adds r0, r5, 0x3
	ldrb r4, [r4, 0x1]
	adds r5, r0, r4
	b _08121D1C
_08121B48:
	adds r0, r5, r7
	ldrb r1, [r0, 0x1]
	ldrb r0, [r0, 0x2]
	lsls r0, 8
	orrs r1, r0
	movs r0, 0xD
	muls r1, r0
	ldr r0, _08121B5C @ =gMoveNames
	adds r1, r0
	b _08121CFA
	.align 2, 0
_08121B5C: .4byte gMoveNames
_08121B60:
	adds r0, r5, r7
	ldrb r0, [r0, 0x1]
	lsls r1, r0, 3
	subs r1, r0
	ldr r0, _08121B6C @ =gTypeNames
	b _08121C7A
	.align 2, 0
_08121B6C: .4byte gTypeNames
_08121B70:
	adds r4, r5, r7
	ldrb r0, [r4, 0x1]
	bl battle_side_get_owner
	lsls r0, 24
	cmp r0, 0
	bne _08121BA4
	ldrb r1, [r4, 0x2]
	movs r0, 0x64
	muls r0, r1
	ldr r1, _08121BA0 @ =gPlayerParty
	adds r0, r1
	movs r1, 0x2
	mov r2, sp
	bl GetMonData
	mov r0, sp
	bl StringGetEnd10
	adds r0, r6, 0
	mov r1, sp
	bl StringAppend
	b _08121D1A
	.align 2, 0
_08121BA0: .4byte gPlayerParty
_08121BA4:
	ldrb r1, [r4, 0x2]
	movs r0, 0x64
	muls r0, r1
	ldr r1, _08121BD4 @ =gEnemyParty
	adds r0, r1
	movs r1, 0x2
	mov r2, sp
	bl GetMonData
	mov r0, sp
	bl StringGetEnd10
	adds r0, r6, 0
	mov r1, sp
	bl StringAppend
	ldr r0, _08121BD8 @ =gBattleTypeFlags
	ldrh r1, [r0]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _08121BE0
	ldr r1, _08121BDC @ =gUnknown_08400797
	b _08121CFA
	.align 2, 0
_08121BD4: .4byte gEnemyParty
_08121BD8: .4byte gBattleTypeFlags
_08121BDC: .4byte gUnknown_08400797
_08121BE0:
	ldr r1, _08121BEC @ =gUnknown_08400791
	adds r0, r6, 0
	bl StringAppend
	b _08121D1A
	.align 2, 0
_08121BEC: .4byte gUnknown_08400791
_08121BF0:
	ldr r1, _08121C00 @ =gUnknown_08400F58
	adds r0, r5, r7
	ldrb r0, [r0, 0x1]
	lsls r0, 2
	adds r0, r1
	ldr r1, [r0]
	b _08121C7C
	.align 2, 0
_08121C00: .4byte gUnknown_08400F58
_08121C04:
	adds r0, r5, r7
	ldrb r1, [r0, 0x1]
	ldrb r0, [r0, 0x2]
	lsls r0, 8
	orrs r1, r0
	adds r0, r6, 0
	bl GetSpeciesName
	b _08121D1A
_08121C16:
	adds r4, r5, r7
	ldrb r0, [r4, 0x1]
	bl battle_side_get_owner
	lsls r0, 24
	cmp r0, 0
	bne _08121C3C
	ldrb r1, [r4, 0x2]
	movs r0, 0x64
	muls r0, r1
	ldr r1, _08121C38 @ =gPlayerParty
	adds r0, r1
	movs r1, 0x2
	adds r2, r6, 0
	bl GetMonData
	b _08121C4E
	.align 2, 0
_08121C38: .4byte gPlayerParty
_08121C3C:
	ldrb r1, [r4, 0x2]
	movs r0, 0x64
	muls r0, r1
	ldr r1, _08121C58 @ =gEnemyParty
	adds r0, r1
	movs r1, 0x2
	adds r2, r6, 0
	bl GetMonData
_08121C4E:
	adds r0, r6, 0
	bl StringGetEnd10
	b _08121D1A
	.align 2, 0
_08121C58: .4byte gEnemyParty
_08121C5C:
	ldr r1, _08121C6C @ =gUnknown_08400F78
	adds r0, r5, r7
	ldrb r0, [r0, 0x1]
	lsls r0, 2
	adds r0, r1
	ldr r1, [r0]
	b _08121C7C
	.align 2, 0
_08121C6C: .4byte gUnknown_08400F78
_08121C70:
	adds r0, r5, r7
	ldrb r1, [r0, 0x1]
	movs r0, 0xD
	muls r1, r0
	ldr r0, _08121C88 @ =gAbilityNames
_08121C7A:
	adds r1, r0
_08121C7C:
	adds r0, r6, 0
	bl StringAppend
	adds r5, 0x2
	b _08121D1C
	.align 2, 0
_08121C88: .4byte gAbilityNames
_08121C8C:
	adds r0, r5, r7
	ldrb r2, [r0, 0x1]
	ldrb r0, [r0, 0x2]
	lsls r0, 8
	orrs r2, r0
	ldr r0, _08121CDC @ =gBattleTypeFlags
	ldrh r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08121D12
	cmp r2, 0xAF
	bne _08121D08
	ldr r2, _08121CE0 @ =gLinkPlayers
	ldr r0, _08121CE4 @ =0x02000000
	ldr r1, _08121CE8 @ =0x000160cb
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r0, r2
	ldr r1, _08121CEC @ =gUnknown_02024C0B
	ldrb r2, [r1]
	ldrh r0, [r0, 0x18]
	cmp r0, r2
	bne _08121CF8
	lsls r1, r2, 3
	subs r1, r2
	lsls r1, 2
	ldr r0, _08121CF0 @ =gEnigmaBerries
	adds r1, r0
	adds r0, r6, 0
	bl StringCopy
	ldr r1, _08121CF4 @ =gUnknown_08400A85
	adds r0, r6, 0
	bl de_sub_8073174
	b _08121D1A
	.align 2, 0
_08121CDC: .4byte gBattleTypeFlags
_08121CE0: .4byte gLinkPlayers
_08121CE4: .4byte 0x02000000
_08121CE8: .4byte 0x000160cb
_08121CEC: .4byte gUnknown_02024C0B
_08121CF0: .4byte gEnigmaBerries
_08121CF4: .4byte gUnknown_08400A85
_08121CF8:
	ldr r1, _08121D04 @ =gUnknown_08400A78
_08121CFA:
	adds r0, r6, 0
	bl StringAppend
	b _08121D1A
	.align 2, 0
_08121D04: .4byte gUnknown_08400A78
_08121D08:
	adds r0, r2, 0
	adds r1, r6, 0
	bl CopyItemName
	b _08121D1A
_08121D12:
	adds r0, r2, 0
	adds r1, r6, 0
	bl CopyItemName
_08121D1A:
	adds r5, 0x3
_08121D1C:
	adds r0, r7, r5
	ldrb r0, [r0]
	cmp r0, 0xFF
	beq _de_08121D26
	b _08121A82
_de_08121D26:
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
	ldr r5, _08121D50 @ =gUnknown_02039270
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
_08121D50: .4byte gUnknown_02039270
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
	ldr r5, _08121DB8 @ =gUnknown_02039270
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
_08121DB8: .4byte gUnknown_02039270
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
