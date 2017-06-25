	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

@ 0x843E36C
	.string "Berries$"

@ 0x843E374
	.string "Goods$"

@ 0x843E37A
	.string "{PKMN}　list$"

@ 0x843E382
	.string "トラップ$"

@ 0x843E387
	.string "Move　your　base$"

@ 0x843E396
	.string "Moving　{PKMN}$"

@ 0x843E3A0
	.string "Fishing　points$"

@ 0x843E3AF
	.string "Set　{POKEBLOCK}$"

@ 0x843E3B9
	.string "Make　basesシto　maxス$"

@ 0x843E3CC
	.string "Base　location$"

@ 0x843E3DC
	.align 2
	.4byte 0x843E36C, 0x815FC55
	.4byte 0x843E37A, 0x815F2B5
	.4byte 0x843E374, 0x815FC95
	.4byte 0x843E387, 0x815FB1D
	.4byte 0x843E3B9, 0x815F2F5
	.4byte 0x843E3CC, 0x815F62D
	.4byte 0x843E396, 0x815FBE9
	.4byte 0x843E3A0, 0x815FE1D
	.4byte 0x843E3AF, 0x8160D99

@ 0x843E424
	.incbin "baserom-debug.gba", 0x43E424, 300

@ 0x843E550
	.string "R$"

@ 0x843E552
	.string "X$"

@ 0x843E554
	.string "Y$"

@ 0x843E556
	.string "♂1\n"
	.string "♂2\n"
	.string "♂3\n"
	.string "♂4\n"
	.string "♂5\n"
	.string "♀1\n"
	.string "♀2\n"
	.string "♀3\n"
	.string "♀4\n"
	.string "♀5$"

@ 0x843E574
	.string "ー$"

@ 0x843E576
	.string "あ$"

@ 0x843E578
	.string "ア$"

@ 0x843E57A
	.string "A$"

@ 0x843E57C
	.string "a$"

@ 0x843E57E
	.string "0$"

@ 0x843E580
	.string "ADD\n"
	.string "DEL\n"
	.string "EXIT$"

@ 0x843E58D
	.string "Fishing　location　R119\n"
	.string "　Y1\n"
	.string "　Y2\n"
	.string "　Y3\n"
	.string "Encounter　location\n"
	.string "\n"
	.string "\n"
	.string "front　of　you$"

@ 0x843E5D1
	.string "そにのAボタン　{ESCAPE}\p"
	.string "　　Bボタン　ー\n"
	.string "START　けってい$"

@ 0x843E5F0
	.string "？$"

@ 0x843E5F2
	.string "HP　どりょくち$"

@ 0x843E5FB
	.string "こうげき　どりょくち$"

@ 0x843E606
	.string "ぼうぎょ　どりょくち$"

@ 0x843E611
	.string "すばやさ　どりょくち$"

@ 0x843E61C
	.string "とくこう　どりょくち$"

@ 0x843E627
	.string "とくぼう　どりょくち$"

@ 0x843E632
	.string "なつきど$"

@ 0x843E637
	.string "どりょくち　ごうけい$"

@ 0x843E642
	.string "ここから$"

@ 0x843E647
	.string "ここまで$"

@ 0x843E64C
	.string "かいすう$"

@ 0x843E651
	.string "けっか$"

@ 0x843E655
	.string "かい$"

@ 0x843E658
	.string "0$"

@ 0x843E65A
	.string "はんい$"
