	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

@ 0x841B1C4
	.string "SETTEI$"

@ 0x841B1CB
	.string "MAWASITA$"

@ 0x841B1D4
	.string "MODOSI$"

@ 0x841B1DB
	.string "NOMARE$"

@ 0x841B1E2
	.string "MAE　7$"

@ 0x841B1E8
	.string "LR　　HENKOU$"

@ 0x841B1F3
	.string "START　　JIDOUSU$"

@ 0x841B202
	.string "SELECT　　SETTEI$"

@ 0x841B211
	.string "TYUHSEN$"

@ 0x841B219
	.string "CHERRY$"

@ 0x841B220
	.string "REPLAY$"

@ 0x841B227
	.string "HASUBO$"

@ 0x841B22E
	.string "RURIRI$"

@ 0x841B235
	.string "INAZU$"

@ 0x841B23B
	.string "REG$"

@ 0x841B23F
	.string "BIG$"

@ 0x841B243
	.string "BD$"

@ 0x841B246
	.string "R7$"

@ 0x841B249
	.string "B7$"

@ 0x841B24C
	.string "A　　COIN$"

@ 0x841B254
	.string "TYUHSEN$"

@ 0x841B25C
	.string "UD　　100$"

@ 0x841B264
	.string "LR　　1000$"

gUnknown_Debug_0841B26D:: @ 0x841B26D
    .string "×$"

	.align 2
@ 0x841B270
	.4byte 0x841B219, 0x811B1C5
	.4byte 0x841B220, 0x811B1ED
	.4byte 0x841B227, 0x811B211
	.4byte 0x841B22E, 0x811B239
	.4byte 0x841B235, 0x811B261
	.4byte 0x841B23B, 0x811B289
	.4byte 0x841B23F, 0x811B2B1
	.4byte 0x841B243, 0x811B2D9

@ 0x841B2B0
	.string "·カウントエラーがおきました$"

@ 0x841B2BF
	.string "·リールそうさで　エラーが　おきました$"

@ 0x841B2D3
	.string "·フラグオフエラーが　おきました$"

@ 0x841B2E4
	.string "·ボーナスこやくの　エラーが　おきました$"
