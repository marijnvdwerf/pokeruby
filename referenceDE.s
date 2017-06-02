	.include "asm/common.inc"

	thumb_func_start sub_8121424
sub_8121424:
	push	{r4, r5, r6, r7, lr}
	mov	r7, r9
	mov	r6, r8
	push	{r6, r7}
	add	sp, sp, #0xfffffff4
	mov	r9, r0
	mov	r8, r1
	mov	r6, #0x0
	mov	r4, #0x0
	bl	GetMultiplayerId
	lsl	r0, r0, #0x18
	lsr	r7, r0, #0x18
	mov	r0, r9
	ldrb	r1, [r0]
	bl	.L1
_277:
	cmp	r1, #0xfd
	beq	.L2	@cond_branch
	bl	.L3
_2:
	mov	r1, #0x1
	ADD r9, r1
	mov	r2, r9
	ldrb	r0, [r2]
	cmp	r0, #0x2a
	bls	.L4	@cond_branch
	bl	.L269
_4:
	lsl	r0, r0, #0x2
	ldr	r1, .L7
	add	r0, r0, r1
	ldr	r0, [r0]
	mov	pc, r0
_8:
	.align	2, 0
_7:
	.word	_6
_6:
	.word	_9
	.word	_10
	.word	_11
	.word	_12
	.word	_13
	.word	_14
	.word	_15
	.word	_16
	.word	_17
	.word	_18
	.word	_19
	.word	_20
	.word	_21
	.word	_22
	.word	_23
	.word	_24
	.word	_25
	.word	_26
	.word	_27
	.word	_28
	.word	_29
	.word	_30
	.word	_31
	.word	_32
	.word	_33
	.word	_34
	.word	_35
	.word	_36
	.word	_37
	.word	_38
	.word	_39
	.word	_40
	.word	_41
	.word	_42
	.word	_43
	.word	_44
	.word	_45
	.word	_46
	.word	_47
	.word	_48
	.word	_49
	.word	_50
	.word	_51
_9:
	ldr	r5, .L54
	ldrb	r0, [r5]
	cmp	r0, #0xfd
	bne	.L52	@cond_branch
	ldr	r4, .L54 + 4
	add	r0, r5, #0
	b	.L53
_55:
	.align	2, 0
_54:
	.word	gUnknown_030041C0
	.word	gStringVar1
_52:
	add	r0, r5, #0
	bl	#0x81213c0
	add	r4, r0, #0
	cmp	r4, #0
	beq	.L56	@cond_branch
	bl	.L269
_56:
	add	r4, r5, #0
	bl	.L269
_10:
	ldr	r1, .L61
	ldrb	r0, [r1]
	cmp	r0, #0xfd
	bne	.L63	@cond_branch
	ldr	r4, .L61 + 4
	b	.L60
_62:
	.align	2, 0
_61:
	.word	gUnknown_03004290
	.word	gStringVar2
_51:
	ldr	r1, .L65
	ldrb	r0, [r1]
	cmp	r0, #0xfd
	bne	.L63	@cond_branch
	ldr	r4, .L65 + 4
_60:
	add	r0, r1, #0
_53:
	add	r1, r4, #0
	bl	#0x8121dcc
	bl	.L269
_66:
	.align	2, 0
_65:
	.word	gUnknown_030042B0
	.word	gStringVar3
_63:
	add	r4, r1, #0
	bl	.L269
_11:
	mov	r0, #0x0
	bl	battle_get_side_with_given_state
	ldr	r1, .L69
	lsl	r0, r0, #0x18
	lsr	r0, r0, #0x17
	add	r0, r0, r1
	ldrh	r1, [r0]
	b	.L150
_70:
	.align	2, 0
_69:
	.word	gUnknown_02024A6A
_12:
	mov	r0, #0x1
	bl	battle_get_side_with_given_state
	ldr	r1, .L72
	lsl	r0, r0, #0x18
	lsr	r0, r0, #0x17
	add	r0, r0, r1
	ldrh	r1, [r0]
	mov	r0, #0x64
	mul	r0, r0, r1
	ldr	r1, .L72 + 4
	b	.L89
_73:
	.align	2, 0
_72:
	.word	gUnknown_02024A6A
	.word	gEnemyParty
_13:
	mov	r0, #0x2
	bl	battle_get_side_with_given_state
	ldr	r1, .L75
	lsl	r0, r0, #0x18
	lsr	r0, r0, #0x17
	add	r0, r0, r1
	ldrh	r1, [r0]
	b	.L150
_76:
	.align	2, 0
_75:
	.word	gUnknown_02024A6A
_14:
	mov	r0, #0x3
	bl	battle_get_side_with_given_state
	ldr	r1, .L78
	lsl	r0, r0, #0x18
	lsr	r0, r0, #0x17
	add	r0, r0, r1
	ldrh	r1, [r0]
	mov	r0, #0x64
	mul	r0, r0, r1
	ldr	r1, .L78 + 4
	b	.L89
_79:
	.align	2, 0
_78:
	.word	gUnknown_02024A6A
	.word	gEnemyParty
_15:
	ldr	r2, .L81
	ldr	r1, .L81 + 4
	lsl	r0, r7, #0x3
	sub	r0, r0, r7
	lsl	r0, r0, #0x2
	add	r0, r0, r1
	ldrh	r0, [r0, #0x18]
	lsl	r0, r0, #0x1
	add	r0, r0, r2
	ldrh	r1, [r0]
	b	.L150
_82:
	.align	2, 0
_81:
	.word	gUnknown_02024A6A
	.word	gLinkPlayers
_16:
	ldr	r2, .L84
	ldr	r1, .L84 + 4
	lsl	r0, r7, #0x3
	sub	r0, r0, r7
	lsl	r0, r0, #0x2
	add	r0, r0, r1
	ldrh	r1, [r0, #0x18]
	mov	r0, #0x1
	eor	r0, r0, r1
	lsl	r0, r0, #0x1
	add	r0, r0, r2
	ldrh	r1, [r0]
	mov	r0, #0x64
	mul	r0, r0, r1
	ldr	r1, .L84 + 8
	b	.L89
_85:
	.align	2, 0
_84:
	.word	gUnknown_02024A6A
	.word	gLinkPlayers
	.word	gEnemyParty
_17:
	ldr	r2, .L87
	ldr	r1, .L87 + 4
	lsl	r0, r7, #0x3
	sub	r0, r0, r7
	lsl	r0, r0, #0x2
	add	r0, r0, r1
	ldrh	r1, [r0, #0x18]
	mov	r0, #0x2
	eor	r0, r0, r1
	lsl	r0, r0, #0x1
	add	r0, r0, r2
	ldrh	r1, [r0]
	b	.L150
_88:
	.align	2, 0
_87:
	.word	gUnknown_02024A6A
	.word	gLinkPlayers
_18:
	ldr	r2, .L90
	ldr	r1, .L90 + 4
	lsl	r0, r7, #0x3
	sub	r0, r0, r7
	lsl	r0, r0, #0x2
	add	r0, r0, r1
	ldrh	r1, [r0, #0x18]
	mov	r0, #0x3
	eor	r0, r0, r1
	lsl	r0, r0, #0x1
	add	r0, r0, r2
	ldrh	r1, [r0]
	mov	r0, #0x64
	mul	r0, r0, r1
	ldr	r1, .L90 + 8
	b	.L89
_91:
	.align	2, 0
_90:
	.word	gUnknown_02024A6A
	.word	gLinkPlayers
	.word	gEnemyParty
_19:
	ldr	r4, .L94
	ldrb	r0, [r4]
	bl	battle_side_get_owner
	lsl	r0, r0, #0x18
	cmp	r0, #0
	beq	.L92	@cond_branch
	ldrb	r0, [r4]
	bl	battle_get_per_side_status
	add	r1, r0, #0
	mov	r0, #0x1
	and	r0, r0, r1
	bl	battle_get_side_with_given_state
	ldr	r1, .L94 + 4
	lsl	r0, r0, #0x18
	lsr	r0, r0, #0x17
	add	r0, r0, r1
	ldrh	r1, [r0]
	mov	r0, #0x64
	mul	r0, r0, r1
	ldr	r1, .L94 + 8
	add	r0, r0, r1
	mov	r1, #0x2
	mov	r2, sp
	bl	GetMonData
	mov	r0, sp
	bl	StringGetEnd10
	mov	r4, sp
	b	.L93
_95:
	.align	2, 0
_94:
	.word	gPlayerMonIndex
	.word	gUnknown_02024A6A
	.word	gEnemyParty
_96:
	mov	r3, r8
	add	r0, r3, r6
	strb	r1, [r0]
	add	r6, r6, #0x1
	add	r4, r4, #0x1
_93:
	ldrb	r1, [r4]
	add	r0, r1, #0
	cmp	r0, #0xff
	bne	.L96	@cond_branch
	b	.L149
_92:
	ldrb	r0, [r4]
	bl	battle_get_per_side_status
	add	r1, r0, #0
	mov	r0, #0x1
	and	r0, r0, r1
	bl	battle_get_side_with_given_state
	ldr	r1, .L99
	lsl	r0, r0, #0x18
	lsr	r0, r0, #0x17
	add	r0, r0, r1
	ldrh	r1, [r0]
	b	.L150
_100:
	.align	2, 0
_99:
	.word	gUnknown_02024A6A
_20:
	ldr	r4, .L103
	ldrb	r0, [r4]
	bl	battle_side_get_owner
	lsl	r0, r0, #0x18
	cmp	r0, #0
	bne	.L101	@cond_branch
	ldrb	r0, [r4]
	bl	battle_get_per_side_status
	add	r1, r0, #0
	mov	r0, #0x1
	and	r0, r0, r1
	bl	battle_get_side_with_given_state
	ldr	r1, .L103 + 4
	lsl	r0, r0, #0x18
	lsr	r0, r0, #0x17
	add	r0, r0, #0x4
	add	r0, r0, r1
	ldrh	r1, [r0]
	b	.L150
_104:
	.align	2, 0
_103:
	.word	gPlayerMonIndex
	.word	gUnknown_02024A6A
_101:
	ldrb	r0, [r4]
	bl	battle_get_per_side_status
	add	r1, r0, #0
	mov	r0, #0x1
	and	r0, r0, r1
	bl	battle_get_side_with_given_state
	ldr	r1, .L106
	lsl	r0, r0, #0x18
	lsr	r0, r0, #0x17
	add	r0, r0, #0x4
	add	r0, r0, r1
	ldrh	r1, [r0]
	mov	r0, #0x64
	mul	r0, r0, r1
	ldr	r1, .L106 + 4
	add	r0, r0, r1
	mov	r1, #0x2
	mov	r2, sp
	bl	GetMonData
	b	.L105
_107:
	.align	2, 0
_106:
	.word	gUnknown_02024A6A
	.word	gEnemyParty
_21:
	ldr	r4, .L110
	ldrb	r0, [r4]
	bl	battle_side_get_owner
	lsl	r0, r0, #0x18
	cmp	r0, #0
	beq	.L108	@cond_branch
	ldr	r1, .L110 + 4
	ldrb	r0, [r4]
	lsl	r0, r0, #0x1
	add	r0, r0, r1
	ldrh	r1, [r0]
	mov	r0, #0x64
	mul	r0, r0, r1
	ldr	r1, .L110 + 8
	add	r0, r0, r1
	mov	r1, #0x2
	mov	r2, sp
	bl	GetMonData
	mov	r0, sp
	bl	StringGetEnd10
	mov	r4, sp
	b	.L109
_111:
	.align	2, 0
_110:
	.word	gPlayerMonIndex
	.word	gUnknown_02024A6A
	.word	gEnemyParty
_112:
	mov	r5, r8
	add	r0, r5, r6
	strb	r1, [r0]
	add	r6, r6, #0x1
	add	r4, r4, #0x1
_109:
	ldrb	r1, [r4]
	add	r0, r1, #0
	cmp	r0, #0xff
	bne	.L112	@cond_branch
	b	.L149
_108:
	ldr	r1, .L115
	ldrb	r0, [r4]
	lsl	r0, r0, #0x1
	add	r0, r0, r1
	ldrh	r1, [r0]
	b	.L150
_116:
	.align	2, 0
_115:
	.word	gUnknown_02024A6A
_22:
	ldr	r4, .L119
	ldrb	r0, [r4]
	bl	battle_side_get_owner
	lsl	r0, r0, #0x18
	cmp	r0, #0
	beq	.L117	@cond_branch
	ldr	r1, .L119 + 4
	ldrb	r0, [r4]
	lsl	r0, r0, #0x1
	add	r0, r0, r1
	ldrh	r1, [r0]
	mov	r0, #0x64
	mul	r0, r0, r1
	ldr	r1, .L119 + 8
	add	r0, r0, r1
	mov	r1, #0x2
	mov	r2, sp
	bl	GetMonData
	mov	r0, sp
	bl	StringGetEnd10
	mov	r4, sp
	b	.L118
_120:
	.align	2, 0
_119:
	.word	gEnemyMonIndex
	.word	gUnknown_02024A6A
	.word	gEnemyParty
_121:
	mov	r2, r8
	add	r0, r2, r6
	strb	r1, [r0]
	add	r6, r6, #0x1
	add	r4, r4, #0x1
_118:
	ldrb	r1, [r4]
	add	r0, r1, #0
	cmp	r0, #0xff
	bne	.L121	@cond_branch
	b	.L149
_117:
	ldr	r1, .L124
	ldrb	r0, [r4]
	lsl	r0, r0, #0x1
	add	r0, r0, r1
	ldrh	r1, [r0]
	b	.L150
_125:
	.align	2, 0
_124:
	.word	gUnknown_02024A6A
_23:
	ldr	r4, .L128
	ldrb	r0, [r4]
	bl	battle_side_get_owner
	lsl	r0, r0, #0x18
	cmp	r0, #0
	beq	.L126	@cond_branch
	ldr	r1, .L128 + 4
	ldrb	r0, [r4]
	lsl	r0, r0, #0x1
	add	r0, r0, r1
	ldrh	r1, [r0]
	mov	r0, #0x64
	mul	r0, r0, r1
	ldr	r1, .L128 + 8
	add	r0, r0, r1
	mov	r1, #0x2
	mov	r2, sp
	bl	GetMonData
	mov	r0, sp
	bl	StringGetEnd10
	mov	r4, sp
	b	.L127
_129:
	.align	2, 0
_128:
	.word	gUnknown_02024C0A
	.word	gUnknown_02024A6A
	.word	gEnemyParty
_130:
	mov	r3, r8
	add	r0, r3, r6
	strb	r1, [r0]
	add	r6, r6, #0x1
	add	r4, r4, #0x1
_127:
	ldrb	r1, [r4]
	add	r0, r1, #0
	cmp	r0, #0xff
	bne	.L130	@cond_branch
	b	.L149
_126:
	ldr	r1, .L133
	ldrb	r0, [r4]
	lsl	r0, r0, #0x1
	add	r0, r0, r1
	ldrh	r1, [r0]
	b	.L150
_134:
	.align	2, 0
_133:
	.word	gUnknown_02024A6A
_24:
	ldr	r4, .L137
	ldrb	r0, [r4]
	bl	battle_side_get_owner
	lsl	r0, r0, #0x18
	cmp	r0, #0
	beq	.L135	@cond_branch
	ldr	r1, .L137 + 4
	ldrb	r0, [r4]
	lsl	r0, r0, #0x1
	add	r0, r0, r1
	ldrh	r1, [r0]
	mov	r0, #0x64
	mul	r0, r0, r1
	ldr	r1, .L137 + 8
	add	r0, r0, r1
	mov	r1, #0x2
	mov	r2, sp
	bl	GetMonData
	mov	r0, sp
	bl	StringGetEnd10
	mov	r4, sp
	b	.L136
_138:
	.align	2, 0
_137:
	.word	gUnknown_02024A60
	.word	gUnknown_02024A6A
	.word	gEnemyParty
_139:
	mov	r5, r8
	add	r0, r5, r6
	strb	r1, [r0]
	add	r6, r6, #0x1
	add	r4, r4, #0x1
_136:
	ldrb	r1, [r4]
	add	r0, r1, #0
	cmp	r0, #0xff
	bne	.L139	@cond_branch
	b	.L149
_135:
	ldr	r1, .L142
	ldrb	r0, [r4]
	lsl	r0, r0, #0x1
	add	r0, r0, r1
	ldrh	r1, [r0]
	b	.L150
_143:
	.align	2, 0
_142:
	.word	gUnknown_02024A6A
_25:
	ldr	r0, .L146
	ldr	r1, .L146 + 4
	add	r4, r0, r1
	ldrb	r0, [r4]
	bl	battle_side_get_owner
	lsl	r0, r0, #0x18
	cmp	r0, #0
	beq	.L144	@cond_branch
	ldr	r1, .L146 + 8
	ldrb	r0, [r4]
	lsl	r0, r0, #0x1
	add	r0, r0, r1
	ldrh	r1, [r0]
	mov	r0, #0x64
	mul	r0, r0, r1
	ldr	r1, .L146 + 12
	add	r0, r0, r1
	mov	r1, #0x2
	mov	r2, sp
	bl	GetMonData
	mov	r0, sp
	bl	StringGetEnd10
	mov	r4, sp
	b	.L145
_147:
	.align	2, 0
_146:
	.word	0x2000000
	.word	0x16003
	.word	gUnknown_02024A6A
	.word	gEnemyParty
_148:
	mov	r2, r8
	add	r0, r2, r6
	strb	r1, [r0]
	add	r6, r6, #0x1
	add	r4, r4, #0x1
_145:
	ldrb	r1, [r4]
	add	r0, r1, #0
	cmp	r0, #0xff
	bne	.L148	@cond_branch
	b	.L149
_144:
	ldr	r1, .L151
	ldrb	r0, [r4]
	lsl	r0, r0, #0x1
	add	r0, r0, r1
	ldrh	r1, [r0]
	b	.L150
_152:
	.align	2, 0
_151:
	.word	gUnknown_02024A6A
_26:
	ldr	r0, .L155
	ldr	r2, [r0]
	ldrh	r1, [r2]
	mov	r0, #0xb1
	lsl	r0, r0, #0x1
	cmp	r1, r0
	bls	.L153	@cond_branch
	ldr	r0, .L155 + 4
	ldr	r3, .L155 + 8
	add	r0, r0, r3
	b	.L154
_156:
	.align	2, 0
_155:
	.word	gSelectedOrderFromParty
	.word	0x2000000
	.word	0x160a0
_153:
	ldrh	r1, [r2]
	b	.L157
_27:
	ldr	r0, .L160
	ldr	r2, [r0]
	ldrh	r1, [r2, #0x2]
	mov	r0, #0xb1
	lsl	r0, r0, #0x1
	cmp	r1, r0
	bls	.L158	@cond_branch
	ldr	r0, .L160 + 4
	ldr	r5, .L160 + 8
	add	r0, r0, r5
_154:
	ldrb	r0, [r0]
	lsl	r0, r0, #0x2
	ldr	r1, .L160 + 12
	add	r4, r0, r1
	b	.L269
_161:
	.align	2, 0
_160:
	.word	gSelectedOrderFromParty
	.word	0x2000000
	.word	0x160a0
	.word	gUnknown_08401674
_158:
	ldrh	r1, [r2, #0x2]
_157:
	mov	r0, #0xd
	mul	r1, r1, r0
	ldr	r0, .L163
	add	r4, r1, r0
	b	.L269
_164:
	.align	2, 0
_163:
	.word	gMoveNames
_28:
	ldr	r0, .L169
	ldrh	r1, [r0]
	mov	r0, #0x2
	and	r0, r0, r1
	cmp	r0, #0
	beq	.L165	@cond_branch
	ldr	r1, .L169 + 4
	ldrh	r0, [r1]
	cmp	r0, #0xaf
	bne	.L166	@cond_branch
	ldr	r2, .L169 + 8
	ldr	r0, .L169 + 12
	ldr	r1, .L169 + 16
	add	r0, r0, r1
	ldrb	r1, [r0]
	lsl	r0, r1, #0x3
	sub	r0, r0, r1
	lsl	r0, r0, #0x2
	add	r0, r0, r2
	ldr	r1, .L169 + 20
	ldrb	r2, [r1]
	ldrh	r0, [r0, #0x18]
	cmp	r0, r2
	bne	.L167	@cond_branch
	lsl	r1, r2, #0x3
	sub	r1, r1, r2
	lsl	r1, r1, #0x2
	ldr	r0, .L169 + 24
	add	r1, r1, r0
	mov	r0, sp
	bl	StringCopy
	ldr	r1, .L169 + 28
	mov	r0, sp
	bl	de_sub_8073174
	mov	r4, sp
	b	.L269
_170:
	.align	2, 0
_169:
	.word	gBattleTypeFlags
	.word	gUnknown_02024C04
	.word	gLinkPlayers
	.word	0x2000000
	.word	0x160cb
	.word	gUnknown_02024C0B
	.word	gEnigmaBerries
	.word	gUnknown_08400A85
_167:
	ldr	r4, .L172
	b	.L269
_173:
	.align	2, 0
_172:
	.word	gUnknown_08400A78
_166:
	ldrh	r0, [r1]
	b	.L174
_165:
	ldr	r0, .L176
	ldrh	r0, [r0]
_174:
	mov	r1, sp
	bl	CopyItemName
	mov	r4, sp
	b	.L269
_177:
	.align	2, 0
_176:
	.word	gUnknown_02024C04
_29:
	ldr	r0, .L179
	b	.L178
_180:
	.align	2, 0
_179:
	.word	0x2024c06
_30:
	ldr	r1, .L182
	ldr	r0, .L182 + 4
	b	.L187
_183:
	.align	2, 0
_182:
	.word	gUnknown_0203926C
	.word	gPlayerMonIndex
_31:
	ldr	r1, .L185
	ldr	r0, .L185 + 4
	b	.L187
_186:
	.align	2, 0
_185:
	.word	gUnknown_0203926C
	.word	gEnemyMonIndex
_32:
	ldr	r1, .L188
	ldr	r0, .L188 + 4
	ldr	r2, .L188 + 8
	add	r0, r0, r2
	b	.L187
_189:
	.align	2, 0
_188:
	.word	gUnknown_0203926C
	.word	0x2000000
	.word	0x16003
_33:
	ldr	r1, .L191
	ldr	r0, .L191 + 4
_187:
	ldrb	r0, [r0]
	add	r0, r0, r1
_178:
	ldrb	r1, [r0]
	mov	r0, #0xd
	mul	r1, r1, r0
	ldr	r0, .L191 + 8
	add	r4, r1, r0
	b	.L269
_192:
	.align	2, 0
_191:
	.word	gUnknown_0203926C
	.word	gUnknown_02024C0A
	.word	gAbilityNames
_34:
	ldr	r3, .L195
	ldrh	r1, [r3]
	mov	r0, #0x80
	lsl	r0, r0, #0x3
	cmp	r1, r0
	bne	.L193	@cond_branch
	add	r0, r1, #0
	mov	r1, #0x0
	b	.L202
_196:
	.align	2, 0
_195:
	.word	gTrainerBattleOpponent
_193:
	ldr	r0, .L199
	ldrh	r1, [r0]
	mov	r2, #0x80
	lsl	r2, r2, #0x1
	add	r0, r2, #0
	and	r0, r0, r1
	cmp	r0, #0
	beq	.L197	@cond_branch
	add	r0, r2, #0
	mov	r1, #0x0
	b	.L202
_200:
	.align	2, 0
_199:
	.word	gBattleTypeFlags
_197:
	mov	r2, #0x80
	lsl	r2, r2, #0x4
	add	r0, r2, #0
	and	r0, r0, r1
	cmp	r0, #0
	beq	.L201	@cond_branch
	add	r0, r2, #0
	mov	r1, #0x0
	b	.L202
_201:
	ldrh	r1, [r3]
	mov	r0, #0x0
_202:
	bl	de_sub_8041024
	add	r4, r0, #0
	b	.L269
_35:
	ldr	r2, .L206
	ldrh	r1, [r2]
	mov	r0, #0x80
	lsl	r0, r0, #0x3
	cmp	r1, r0
	bne	.L204	@cond_branch
	mov	r0, sp
	mov	r1, #0xff
	mov	r2, #0x8
	bl	memset
	ldr	r1, .L206 + 4
	mov	r0, sp
	mov	r2, #0x7
	bl	memcpy
	mov	r4, sp
	b	.L269
_207:
	.align	2, 0
_206:
	.word	gTrainerBattleOpponent
	.word	0x2017002
_204:
	ldr	r0, .L210
	ldrh	r1, [r0]
	mov	r0, #0x80
	lsl	r0, r0, #0x1
	and	r0, r0, r1
	cmp	r0, #0
	beq	.L208	@cond_branch
	mov	r0, sp
	bl	get_trainer_name
	mov	r4, sp
	b	.L269
_211:
	.align	2, 0
_210:
	.word	gBattleTypeFlags
_208:
	mov	r0, #0x80
	lsl	r0, r0, #0x4
	and	r0, r0, r1
	cmp	r0, #0
	beq	.L212	@cond_branch
	mov	r0, sp
	bl	#0x8136370
	mov	r4, sp
	b	.L269
_212:
	ldrh	r0, [r2]
	lsl	r1, r0, #0x2
	add	r1, r1, r0
	lsl	r1, r1, #0x3
	ldr	r0, .L215
	add	r4, r1, r0
	b	.L269
_216:
	.align	2, 0
_215:
	.word	0x81fd47c
_36:
	lsl	r0, r7, #0x3
	sub	r0, r0, r7
	lsl	r0, r0, #0x2
	ldr	r1, .L218
	add	r4, r0, r1
	b	.L269
_219:
	.align	2, 0
_218:
	.word	0x3002988
_37:
	ldr	r4, .L221
	lsl	r0, r7, #0x3
	sub	r0, r0, r7
	lsl	r0, r0, #0x2
	add	r0, r0, r4
	ldrh	r1, [r0, #0x18]
	mov	r0, #0x2
	b	.L223
_222:
	.align	2, 0
_221:
	.word	gLinkPlayers
_38:
	ldr	r4, .L224
	lsl	r0, r7, #0x3
	sub	r0, r0, r7
	lsl	r0, r0, #0x2
	add	r0, r0, r4
	ldrh	r1, [r0, #0x18]
	mov	r0, #0x1
	b	.L223
_225:
	.align	2, 0
_224:
	.word	gLinkPlayers
_39:
	ldr	r4, .L227
	lsl	r0, r7, #0x3
	sub	r0, r0, r7
	lsl	r0, r0, #0x2
	add	r0, r0, r4
	ldrh	r1, [r0, #0x18]
	mov	r0, #0x3
_223:
	eor	r0, r0, r1
	bl	#0x803fe28
	lsl	r1, r0, #0x3
	sub	r1, r1, r0
	lsl	r1, r1, #0x2
	add	r4, r4, #0x8
	add	r4, r1, r4
	b	.L269
_228:
	.align	2, 0
_227:
	.word	gLinkPlayers
_40:
	ldr	r0, .L230
	ldr	r3, .L230 + 4
	add	r0, r0, r3
	ldrb	r0, [r0]
	bl	#0x803fe28
	lsl	r1, r0, #0x3
	sub	r1, r1, r0
	lsl	r1, r1, #0x2
	ldr	r0, .L230 + 8
	add	r4, r1, r0
	b	.L269
_231:
	.align	2, 0
_230:
	.word	0x2000000
	.word	0x16003
	.word	0x3002988
_41:
	ldr	r4, .L233
	b	.L269
_234:
	.align	2, 0
_233:
	.word	gSaveBlock2
_42:
	bl	#0x8082c64
	add	r4, r0, #0
	b	.L269
_43:
	ldr	r4, .L238
	ldr	r5, .L238 + 4
	add	r0, r4, r5
	ldrb	r0, [r0]
	bl	battle_side_get_owner
	lsl	r0, r0, #0x18
	cmp	r0, #0
	beq	.L236	@cond_branch
	ldr	r1, .L238 + 8
	add	r0, r4, r1
	ldrb	r1, [r0]
	mov	r0, #0x64
	mul	r0, r0, r1
	ldr	r1, .L238 + 12
	add	r0, r0, r1
	mov	r1, #0x2
	mov	r2, sp
	bl	GetMonData
	mov	r0, sp
	bl	StringGetEnd10
	mov	r4, sp
	b	.L237
_239:
	.align	2, 0
_238:
	.word	0x2000000
	.word	0x16003
	.word	0x1605e
	.word	gEnemyParty
_240:
	mov	r2, r8
	add	r0, r2, r6
	strb	r1, [r0]
	add	r6, r6, #0x1
	add	r4, r4, #0x1
_237:
	ldrb	r1, [r4]
	add	r0, r1, #0
	cmp	r0, #0xff
	bne	.L240	@cond_branch
_149:
	ldr	r0, .L243
	ldrh	r1, [r0]
	mov	r0, #0x8
	and	r0, r0, r1
	ldr	r4, .L243 + 4
	cmp	r0, #0
	beq	.L269	@cond_branch
	ldr	r4, .L243 + 8
	b	.L269
_244:
	.align	2, 0
_243:
	.word	gBattleTypeFlags
	.word	gUnknown_08400791
	.word	gUnknown_08400797
_236:
	ldr	r3, .L246
	add	r0, r4, r3
	ldrb	r1, [r0]
_150:
	mov	r0, #0x64
	mul	r0, r0, r1
	ldr	r1, .L246 + 4
_89:
	add	r0, r0, r1
	mov	r1, #0x2
	mov	r2, sp
	bl	GetMonData
_105:
	mov	r0, sp
	bl	StringGetEnd10
	mov	r4, sp
	b	.L269
_247:
	.align	2, 0
_246:
	.word	0x1605e
	.word	gPlayerParty
_44:
	ldr	r0, .L250
	bl	FlagGet
	lsl	r0, r0, #0x18
	ldr	r4, .L250 + 4
	cmp	r0, #0
	beq	.L269	@cond_branch
	ldr	r4, .L250 + 8
	b	.L269
_251:
	.align	2, 0
_250:
	.word	0x84b
	.word	gUnknown_084009ED
	.word	gUnknown_084009F7
_47:
	ldr	r0, .L253
	b	.L252
_254:
	.align	2, 0
_253:
	.word	gPlayerMonIndex
_48:
	ldr	r0, .L257
_252:
	ldrb	r0, [r0]
	bl	battle_side_get_owner
	lsl	r0, r0, #0x18
	ldr	r4, .L257 + 4
	cmp	r0, #0
	bne	.L269	@cond_branch
	ldr	r4, .L257 + 8
	b	.L269
_258:
	.align	2, 0
_257:
	.word	gEnemyMonIndex
	.word	gUnknown_084007A7
	.word	gUnknown_084007AC
_45:
	ldr	r0, .L260
	b	.L259
_261:
	.align	2, 0
_260:
	.word	gPlayerMonIndex
_46:
	ldr	r0, .L264
_259:
	ldrb	r0, [r0]
	bl	battle_side_get_owner
	lsl	r0, r0, #0x18
	ldr	r4, .L264 + 4
	cmp	r0, #0
	bne	.L269	@cond_branch
	ldr	r4, .L264 + 8
	b	.L269
_265:
	.align	2, 0
_264:
	.word	gEnemyMonIndex
	.word	gUnknown_0840079C
	.word	gUnknown_084007A1
_49:
	ldr	r0, .L267
	b	.L266
_268:
	.align	2, 0
_267:
	.word	gPlayerMonIndex
_50:
	ldr	r0, .L274
_266:
	ldrb	r0, [r0]
	bl	battle_side_get_owner
	lsl	r0, r0, #0x18
	ldr	r4, .L274 + 4
	cmp	r0, #0
	bne	.L269	@cond_branch
	ldr	r4, .L274 + 8
_269:
	ldrb	r1, [r4]
	add	r0, r1, #0
	mov	r5, r9
	ldrb	r2, [r5]
	mov	r3, r9
	add	r3, r3, #0x1
	cmp	r0, #0xff
	beq	.L270	@cond_branch
_271:
	mov	r5, r8
	add	r0, r5, r6
	strb	r1, [r0]
	add	r6, r6, #0x1
	add	r4, r4, #0x1
	ldrb	r1, [r4]
	add	r0, r1, #0
	cmp	r0, #0xff
	bne	.L271	@cond_branch
_270:
	lsl	r0, r2, #0x18
	lsr	r0, r0, #0x18
	cmp	r0, #0x21
	bne	.L273	@cond_branch
	mov	r0, r8
	add	r1, r0, r6
	mov	r0, #0xfc
	strb	r0, [r1]
	add	r6, r6, #0x1
	mov	r2, r8
	add	r1, r2, r6
	mov	r0, #0x9
	strb	r0, [r1]
	add	r6, r6, #0x1
	b	.L273
_275:
	.align	2, 0
_274:
	.word	gEnemyMonIndex
	.word	gUnknown_084007B2
	.word	gUnknown_084007B7
_3:
	mov	r3, r8
	add	r0, r3, r6
	strb	r1, [r0]
	add	r6, r6, #0x1
	mov	r3, r9
	add	r3, r3, #0x1
_273:
	mov	r9, r3
	ldrb	r1, [r3]
_1:
	add	r0, r1, #0
	cmp	r0, #0xff
	beq	.L276	@cond_branch
	bl	.L277
_276:
	mov	r5, r8
	add	r1, r5, r6
	mov	r2, r9
	ldrb	r0, [r2]
	strb	r0, [r1]
	add	r6, r6, #0x1
	add	r0, r6, #0
	add	sp, sp, #0xc
	pop	{r3, r4}
	mov	r8, r3
	mov	r9, r4
	pop	{r4, r5, r6, r7}
	pop	{r1}
	bx	r1
	thumb_func_end sub_8121424

.align 2, 0 @ Don't pad with nop.
