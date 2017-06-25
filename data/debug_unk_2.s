	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

@ 0x8411540
	.string "レイアウトを　にほんごで　ひょうじ？$"

@ 0x8411553
	.string "にほんご　$"

@ 0x8411559
	.string "かいがい　$"

@ 0x8411560
	.align 2
	.4byte 0x8411553, 0x8411559

@ 0x8411568
	.string "イメージ　タイプを　えらんでね$"

@ 0x8411578
	.string "{STR_VAR_1}$"

@ 0x841157B
	.string "オレンジ　$"

@ 0x8411581
	.string "ハーバー　$"

@ 0x8411587
	.string "キラキラ　$"

@ 0x841158D
	.string "メカニカル$"

@ 0x8411593
	.string "ウッディー$"

@ 0x8411599
	.string "クロス　　$"

@ 0x841159F
	.string "トレジャー$"

@ 0x84115A5
	.string "シャドウ　$"

@ 0x84115AB
	.string "トロピカル$"

@ 0x84115B1
	.string "ドリーム　$"

@ 0x84115B7
	.string "ミラクル　$"

@ 0x84115BD
	.string "レトロ　　$"

@ 0x84115C4
	.align 2
	.4byte 0x841157B, 0x8411581
	.4byte 0x8411587, 0x841158D
	.4byte 0x8411593, 0x8411599
	.4byte 0x841159F, 0x84115A5
	.4byte 0x84115AB, 0x84115B1
	.4byte 0x84115B7, 0x84115BD

@ 0x84115F4
	.string "メールをみる$"

@ 0x84115FB
	.string "メールとうろく$"

@ 0x8411603
	.string "もたせる$"

@ 0x8411608
	.string "メールをけす$"

@ 0x841160F
	.string "　　　　い{STR_VAR_1}　{STR_VAR_2}$"

@ 0x841161A
	.string "メール{STR_VAR_1}　{STR_VAR_2}$"

@ 0x8411623
	.string "メール{STR_VAR_1}を　だれに　もたせる？$"

@ 0x8411634
	.string "000　{STR_VAR_1}$"

@ 0x841163B
	.string "せいきの　データが　とうろくずみ　です\n"
	.string "しんき　とうろく　できません$"

@ 0x841165E
	.string "せいきに　とうろくされたメールデータは\n"
	.string "へんこう　できません$"

@ 0x841167D
	.string "メール{STR_VAR_1}　とうろく　かいじょ$"

@ 0x841168D
	.string "デバッグメニューから　とうろくした\n"
	.string "メール　いがいは　けせません$"

@ 0x84116AE
	.string "メール{STR_VAR_1}　{STR_VAR_2}　{STR_VAR_3}$"

@ 0x84116BC
	.align 2
	.4byte 0x84115F4, 0x0
	.4byte 0x84115FB, 0x0
	.4byte 0x8411603, 0x0
	.4byte 0x8411608, 0x0
