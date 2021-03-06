#ifndef GUARD_FLAGS_H
#define GUARD_FLAGS_H

#define TRAINER_FLAG_START 0x500

// SYSTEM FLAGS

#define SYS_POKEMON_GET  0x800
#define SYS_POKEDEX_GET  0x801
#define SYS_POKENAV_GET  0x802
#define SYS_GAME_CLEAR   0x804
#define SYS_CHAT_USED    0x805
#define SYS_HIPSTER_MEET 0x806

// badges
#define BADGE01_GET 0x807
#define BADGE02_GET 0x808
#define BADGE03_GET 0x809
#define BADGE04_GET 0x80A
#define BADGE05_GET 0x80B
#define BADGE06_GET 0x80C
#define BADGE07_GET 0x80D
#define BADGE08_GET 0x80E

#define SYS_USE_FLASH        0x828
#define SYS_USE_STRENGTH     0x829
#define SYS_WEATHER_CTRL     0x82A
#define SYS_CYCLING_ROAD     0x82B
#define SYS_SAFARI_MODE      0x82C
#define SYS_CRUISE_MODE      0x82D

#define SYS_TV_HOME          0x830
#define SYS_TV_WATCH         0x831
#define SYS_TV_START         0x832
#define SYS_POPWORD_INPUT    0x833
#define SYS_MIX_RECORD       0x834
#define SYS_CLOCK_SET        0x835
#define SYS_NATIONAL_DEX     0x836
#define SYS_CAVE_SHIP        0x837
#define SYS_CAVE_WONDER      0x838
#define SYS_CAVE_BATTLE      0x839
#define SYS_SHOAL_TIDE       0x83A
#define SYS_RIBBON_GET       0x83B

#define SYS_PC_LANETTE       0x84B
#define SYS_EXDATA_ENABLE    0x84C
#define SYS_ENC_UP_ITEM      0x84D
#define SYS_ENC_DOWN_ITEM    0x84E
#define SYS_BRAILLE_DIG      0x84F
#define SYS_BRAILLE_STRENGTH 0x850
#define SYS_BRAILLE_WAIT     0x851
#define SYS_BRAILLE_FLY      0x852

#define SYS_TV_LATI          0x85D

#define SYS_SHOAL_ITEM       0x85F
#define SYS_B_DASH           0x860 // got Running Shoes
#define SYS_CTRL_OBJ_DELETE  0x861
#define SYS_RESET_RTC_ENABLE 0x862

// SPECIAL FLAGS (unknown purpose)

#define SPECIAL_FLAG_1 0x4001

#endif // GUARD_FLAGS_H

bool8 FlagGet(u16 flag);
