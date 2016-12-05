	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

gExpandedPlaceholder_Empty:: @ 840DC80
	.string "$"

gExpandedPlaceholder_Kun:: @ 840DC81
	.string "$"

gExpandedPlaceholder_Chan:: @ 840DC82
	.string "$"

gExpandedPlaceholder_Sapphire:: @ 840DC83
	.string "SAPHIR$"

gExpandedPlaceholder_Ruby:: @ 840DC8C
	.string "RUBIN$"

gExpandedPlaceholder_Aqua:: @ 840DC91
	.string "AQUA$"

gExpandedPlaceholder_Magma:: @ 840DC96
	.string "MAGMA$"

gExpandedPlaceholder_Archie:: @ 840DC9C
	.string "ADRIAN$"

gExpandedPlaceholder_Maxie:: @ 840DCA3
	.string "MARC$"

gExpandedPlaceholder_Kyogre:: @ 840DCA9
	.string "KYOGRE$"

gExpandedPlaceholder_Groudon:: @ 840DCB0
	.string "GROUDON$"

gExpandedPlaceholder_Brendan:: @ 840DCB8
	.string "BRIX$"

gExpandedPlaceholder_May:: @ 840DCC0
	.string "MAIKE$"

gSystemText_Egg:: @ 840DCC4
	.string "EI$"

gSystemText_Pokemon2:: @ 840DCC8
	.string "POKéMON$"

gMainMenuString_NewGame:: @ 840DCD0
	.string "NEUES SPIEL$"

gMainMenuString_Continue:: @ 840DCD9
	.string "WEITER$"

gMainMenuString_Option:: @ 840DCE2
	.string "OPTIONEN$"

gMainMenuString_MysteryEvents:: @ 840DCE9
	.string "GEHEIMGESCHEHEN$"

SystemText_UpdatingSaveExternal:: @ 840DCF8
	.string "Neuer Spielstand mittels Übertra-\n"
	.string "gung externer Daten. Bitte warten.$"

SystemText_SaveUpdated:: @ 840DD2D
	.string "Der Spielstand wurde erneuert.$"

SystemText_SaveUpdatedExchangeBackup:: @ 840DD4D
	.string "Der Spielstand wurde gespeichert.\p"
	.string "Das Backup Memory kann keine \n"
	.string "weiteren Spieldaten sichern.\p"
	.string "Bitte Backup Memory austauschen.\p"
	.string "Bei Fragen bitte an die Nintendo\n"
	.string "Konsumentenberatung wenden.$"

SystemText_SaveNotUpdated:: @ 840DE01
	.string "Spielstand wurde nicht gesichert.\p"
	.string "Bitte Backup Memory \n"
	.string "austauschen.\p"
	.string "Bei Fragen bitte an die Nintendo\n"
	.string "Konsumentenberatung wenden.$"

gSaveFileCorruptMessage:: @ 840DE81
	.string "Der Spielstand ist beschädigt. Der\n"
	.string "vorherige Spielstand wird geladen.$"

gSaveFileDeletedMessage:: @ 840DEC2
	.string "Der Spielstand wurde gelöscht.$"

gBoardNotInstalledMessage:: @ 840DEE5
	.string "Das ‘1M Sub-circuit Board’\n"
	.string "ist nicht installiert.$"

gBatteryDryMessage:: @ 840DF10
	.string "Interne Batterie ist verbraucht.\n"
	.string "Spiel kann fortgesetzt werden.\p"
	.string "Aber zeitbasierende Spiel-Events\n"
	.string "werden nicht mehr initiiert.$"

gMainMenuString_Player:: @ 840DF7C
	.string "SPIELER$"

gMainMenuString_Pokedex:: @ 840DF83
	.string "POKéDEX$"

gMainMenuString_Time:: @ 840DF8B
	.string "SPIELZEIT$"

gMainMenuString_Badges:: @ 840DF90
	.string "ORDEN$"

gBirchText_Boy::
	.string "JUNGE$"
gBirchText_Girl::
	.string "MÄDEL$"
gBirchText_NewName::
	.string "NEUER NAME$"

gDefaultBoyName1::
	.ifdef SAPPHIRE
	.string "SEAN$"
	.else
	.string "ROLAND$"
	.endif
gDefaultBoyName2::
	.string "DANIEL$"
gDefaultBoyName3::
	.string "HELGE$"
gDefaultBoyName4::
	.string "JAN$"

gDefaultGirlName1::
	.ifdef SAPPHIRE
	.string "MARINA$"
	.else
	.string "PETRA$"
	.endif
gDefaultGirlName2::
	.string "TANJA$"
gDefaultGirlName3::
	.string "ANDREA$"
gDefaultGirlName4::
	.string "SARA$"

gSystemText_IntroWeCall::
	.string "Dies ist ein so genanntes\n"
	.string "“POKéMON”.$"

gSystemText_NewPara:: @ 840DFF7
	.string "\p$"

gDexText_UnknownPoke:: @ 840DFF9
	.string "?????$"

gDexText_UnknownHeight:: @ 840E013
	.string "???,?  m$"

gDexText_UnknownWeight:: @ 840E01D
	.string "???,?  kg$"
	.string "$"

gDexText_CryOf:: @ 840E02A
	.string "{CLEAR_TO 2}RUF VON$"
	.string "$"

gDexText_SizeComparedTo:: @ 840E035
	.string "GRÖSSE IM VERGLEICH ZU $"

gDexText_RegisterComplete:: @ 840E047
	.string "Neuer Eintrag aufgenommen.$"

gDexText_Searching:: @ 840E067
	.string "Suche läuft.\n"
	.string "Bitte warten...$"

gDexText_SearchComplete:: @ 840E081
	.string "Suche beendet.$"

gDexText_NoMatching:: @ 840E093
	.string "Es wurde keine Übereinstimmung ermittelt.$"

DexText_SearchForPoke::
	.string "Suche nach POKéMON anhand\n"
	.string "ausgewählter Parameter.$"
DexText_SwitchDex::
	.string "Ordnungssystem des POKéDEX ändern.$"
DexText_ReturnToDex::
	.string "Kehre zurück zum POKéDEX.$"
DexText_SelectDexMode::
	.string "Wähle einen POKéDEX.$"
DexText_SelectDexList::
	.string "Wähle ein Ordnungssystem des POKéDEX.$"
DexText_ListByABC::
	.string "Nach Anfangsbuchstaben suchen.\n"
	.string "(Alle gesehenen POKéMON.)$"
DexText_ListByColor::
	.string "Nach Körperfarbe suchen.\n"
	.string "(Alle gesehenen POKéMON.)$"
DexText_ListByType::
	.string "Nach Elementklasse suchen.\n"
	.string "(Nur gefangene POKéMON.)$"
DexText_ExecuteSearchSwitch::
	.string "Suche/Ändern ausführen.$"
DexText_HoennDex::
	.string "HOENN DEX$"
DexText_NationalDex::
	.string "NATIONALER DEX$"
DexText_NumericalMode::
	.string "NUMERISCH$"
DexText_ABCMode::
	.string "VON A BIS Z$"
DexText_HeaviestMode::
	.string "NACH GEWICHT {0x86}$"
DexText_LightestMode::
	.string "NACH GEWICHT {0x85}$"
DexText_TallestMode::
	.string "NACH GRÖSSE {0x86}$"
DexText_SmallestMode::
	.string "NACH GRÖSSE {0x85}$"
DexText_ABC::
	.string "ABC$"
DexText_DEF::
	.string "DEF$"
DexText_GHI::
	.string "GHI$"
DexText_JKL::
	.string "JKL$"
DexText_MNO::
	.string "MNO$"
DexText_PQR::
	.string "PQR$"
DexText_STU::
	.string "STU$"
DexText_VWX::
	.string "VWX$"
DexText_YZ::
	.string "YZ$"
DexText_Red::
	.string "ROT$"
DexText_Blue::
	.string "BLAU$"
DexText_Yellow::
	.string "GELB$"
DexText_Green::
	.string "GRÜN$"
DexText_Black::
	.string "SCHWARZ$"
DexText_Brown::
	.string "BRAUN$"
DexText_Purple::
	.string "LILA$"
DexText_Gray::
	.string "GRAU$"
DexText_White::
	.string "WEISS$"
DexText_Pink::
	.string "ROSA$"
DexText_HoennDex2::
	.string "POKéDEX von HOENN$"
DexText_NationalDex2::
	.string "POKéDEX, erweiterte Edition$"
DexText_ListByNumber::
	.string "POKéMON werden anhand ihrer\n"
	.string "Nummer sortiert.$"
DexText_ListByABC2::
	.string "Gesehene und gefangene POKéMON\n"
	.string "werden alphabetisch geordnet.$"
DexText_ListByHeavyToLightest::
	.string "Gefangene POKéMON werden nach Gewicht\n"
	.string "sortiert, beginnend mit dem schwersten.$"
DexText_ListByLightToHeaviest::
	.string "Gefangene POKéMON werden nach Gewicht\n"
	.string "sortiert, beginnend mit dem leichtesten.$"
DexText_ListByTallToSmallest::
	.string "Gefangene POKéMON werden nach Größe\n"
	.string "sortiert, beginnend mit dem größten.$"
DexText_ListBySmallToTallest::
	.string "Gefangene POKéMON werden nach Größe\n"
	.string "sortiert, beginnend mit dem kleinsten.$"
DexText_Terminator5::
	.string "$"
DexText_DontSpecify::
	.string "KEINE ANGABE$"
DexText_None::
	.string "KEINER$"
DexText_RightPointingTriangle::
	.string "▶$"
DexText_Terminator6::
	.string " $"

gMenuText_WelcomeToHOFAndDexRating:: @ 840E44F
	.string "Willkommen in der RUHMESHALLE!$"

	.string "Gesehene POKéMON: {STR_VAR_1}!\n"
	.string "Gefangene POKéMON: {STR_VAR_2}!\p"
	.string "PROF. BIRKs POKéDEX-Bewertung!\p"
	.string "PROF. BIRK: Sehen wir mal...\p"
	.string "$"

gMenuText_HOFSaving:: @ 840E4CD
	.string "SPEICHERVORGANG...\n"
	.string "DAS GERÄT NICHT AUSSCHALTEN!$"

gMenuText_HOFCorrupt:: @ 840E4F1
	.string "Die RH-Daten sind beschädigt.$"

gMenuText_HOFNumber:: @ 840E513
	.string "RUHMESHALLE, Nr. $"

gMenuText_HOFCongratulations:: @ 840E525
	.string "CHAMP der POKéMON LIGA!\n"
	.string "Herzlichen Glückwunsch!$"

gOtherText_Number2:: @ 840E547
	.string "Nr.$"

gOtherText_Level3:: @ 840E54C
	.string "Lv.$"

gOtherText_IDNumber:: @ 840E551
	.string "ID.Nr. /$"

gOtherText_Name:: @ 840E559
	.string "NAME /$"

gOtherText_IDNumber2:: @ 840E560
	.string "ID.Nr. /$"

gOtherText_BirchInTrouble:: @ 840E568
	.string "{HIGHLIGHT WHITE2}{COLOR DARK_GREY}PROF. BIRK ist in Schwierigkeiten!\n"
	.string "Schnapp’ dir ein POKéMON und hilf ihm!$"

gOtherText_DoYouChoosePoke:: @ 840E5AB
	.string "{HIGHLIGHT WHITE2}{COLOR DARK_GREY}Wählst du dieses POKéMON?$"

gOtherText_Poke:: @ 840E5CD
	.string "POKéMON$"

gSystemText_SaveErrorExchangeBackup:: @ 840E5D5
	.string "Fehler beim Speichern!\p"
	.string "Bitte Backup Memory\n"
	.string "austauschen.$"

gOtherText_FlyToWhere:: @ 840E604
	.string "Wohin willst du FLIEGEN?$"

OtherText_Use::
	.string "O.K.$"
OtherText_Toss::
	.string "MÜLL$"
OtherText_Register::
	.string "WÄHLEN$"
OtherText_Give2::
	.string "GEBEN$"
OtherText_CheckTag::
	.string "PRÜFEN$"
OtherText_Confirm::
	.string "O.K.$"

gOtherText_Walk:: @ 840E63B
	.string "LAUFEN$"

gUnknownText_Exit:: @ 840E640
	.string "BEENDEN$"

gOtherText_CancelNoTerminator:: @ 840E645
	.string "ZURÜCK$"

gOtherText_CancelWithTerminator:: @ 840E64C
	.string "$ZURÜCK$"

OtherText_Item::
	.string "ITEM$"
OtherText_Mail::
	.string "BRIEF$"
OtherText_Take2::
	.string "NEHMEN$"
OtherText_Store::
	.string "GEBEN$"

gOtherText_Check:: @ 840E669
	.string "PRÜFEN$"

gOtherText_None:: @ 840E66F
	.string "KEINES$"

gOtherText_ThreeQuestions2:: @ 840E674
	.string "???$"

gOtherText_FiveQuestionsAndSlash:: @ 840E678
	.string "?????$"

	.string "/$"

gOtherText_OneDash:: @ 840E680
	.string "-$"

gOtherText_TwoDashes:: @ 840E682
	.string "--$"

gOtherText_ThreeDashes2:: @ 840E685
	.string "---$"

gOtherText_MaleSymbol2:: @ 840E689
	.string "♂$"

gOtherText_FemaleSymbolAndLv:: @ 840E68B
	.string "♀$"
	.string "Lv.$"

gOtherText_TallPlusAndRightArrow:: @ 840E691
	.string "{TALL_PLUS}$"
	.string "{RIGHT_ARROW}$"

gMenuText_GoBackToPrev:: @ 840E697
	.string "Kehre zurück zum\n"
	.string "vorherigen Menü.$"

gOtherText_WhatWillYouDo:: @ 840E6B5
	.string "Was möchtest du tun?$"

gOtherText_xString1:: @ 840E6D0
	.string "×{STR_VAR_1}$"

gOtherText_Berry2:: @ 840E6D4
	.string "BEERE$"

gOtherText_Coins2:: @ 840E6DB
	.string "{STR_VAR_1} MÜNZ.$"

gOtherText_CloseBag:: @ 840E6E4
	.string "BEUTEL SCHLIESSEN$"

OtherText_TheField3::
	.string "zum Hauptmenü.$"
OtherText_TheBattle::
	.string "zum Kampf.$"
OtherText_ThePokeList::
	.string "zur POKéMON-LISTE.$"
OtherText_TheShop::
	.string "zum Geschäft.$"
OtherText_TheField::
	.string "zum Hauptmenü.$"
OtherText_TheField2::
	.string "zum Hauptmenü.$"
OtherText_ThePC::
	.string "zum PC.$"

	.align 2
gUnknown_0840E740:: @ 840E740
	.4byte OtherText_TheField3
	.4byte OtherText_TheBattle
	.4byte OtherText_ThePokeList
	.4byte OtherText_TheShop
	.4byte OtherText_TheField
	.4byte OtherText_TheField2
	.4byte OtherText_ThePC

gOtherText_ReturnTo:: @ 840E75C
	.string "Zurück $"

gOtherText_WhatWillYouDo2:: @ 840E766
	.string "Was möchtest\n"
	.string "du tun?$"

gOtherText_CantWriteMail:: @ 840E781
	.string "Du kannst keinen\n"
	.string "BRIEF schreiben.$"

gOtherText_NoPokemon:: @ 840E79C
	.string "Hier ist kein\n"
	.string "POKéMON.{PAUSE_UNTIL_PRESS}$"

gOtherText_SwitchWhichItem:: @ 840E7B3
	.string "Gegen welches Item\n"
	.string "austauschen?$"

gOtherText_CantBeHeld:: @ 840E7CB
	.string "{STR_VAR_1} ist nicht zu geben.$"

gOtherText_CantBeHeldHere:: @ 840E7DD
	.string "{STR_VAR_1} ist hier nicht zu geben.$"

gOtherText_HowManyToDeposit:: @ 840E7F4
	.string "Wie viele möchtest\n"
	.string "du ablegen?$"

gOtherText_DepositedItems:: @ 840E815
	.string "{STR_VAR_2}× {STR_VAR_1}\n"
	.string "wurde abgelegt.$"

gOtherText_NoRoomForItems:: @ 840E829
	.string "Kein Platz für\n"
	.string "weitere Items.$"

gOtherText_CantStoreSomeoneItem:: @ 840E849
	.string "Du kannst kein\n"
	.string "Item eines anderen\n"
	.string "auf dem PC lagern.$"

gOtherText_TooImportant:: @ 840E878
	.string "Das ist viel zu\n"
	.string "wichtig, um es\n"
	.string "wegzuwerfen!$"

gOtherText_HowManyToToss:: @ 840E89F
	.string "Wie viel in den Müll?$"

gOtherText_ThrewAwayItem:: @ 840E8B2
	.string "{STR_VAR_2} × {STR_VAR_1}\n"
	.string "weggeworfen.$"

gOtherText_OkayToThrowAwayPrompt:: @ 840E8C7
	.string "Willst du wirklich\n"
	.string "{STR_VAR_2} × {STR_VAR_1}\n"
	.string "wegwerfen?$"

gOtherText_DadsAdvice:: @ 840E8EA
	.string "VATI sagt immer...\n"
	.string "{PLAYER}, dies ist weder der rechte\l"
	.string "Ort noch der rechte Zeitpunkt dafür!{PAUSE_UNTIL_PRESS}$"

gOtherText_CantGetOffBike:: @ 840E929
	.string "Du kannst hier nicht vom RAD steigen.{PAUSE_UNTIL_PRESS}$"

gOtherText_ItemfinderResponding:: @ 840E94E
	.string "Oh!\n"
	.string "Das Gerät zeigt etwas an!\p"
	.string "Hier muss ein Item vergraben sein!{PAUSE_UNTIL_PRESS}$"

    gOtherText_ItemfinderItemUnderfoot:: @ 840E992
	.string "Das Gerät macht direkt unter\n"
	.string "deinen Füßen etwas aus!{PAUSE_UNTIL_PRESS}$"

gOtherText_NoResponse:: @ 840E9C8
	.string "... ... ... ... Nichts!\n"
	.string "Keine Anzeige.{PAUSE_UNTIL_PRESS}$"

gOtherText_Coins3:: @ 840E9F5
	.string "Deine MÜNZEN:\n"
	.string "{STR_VAR_1}{PAUSE_UNTIL_PRESS}$"

gOtherText_BootedTM:: @ 840EA06
	.string "Eine TM wurde aktiviert.$"

gOtherText_BootedHM:: @ 840EA16
	.string "Eine VM wurde aktiviert.$"

gOtherText_ContainsMove:: @ 840EA27
	.string "Sie enthält\n"
	.string "{STR_VAR_1}.\p"
	.string "{STR_VAR_1} einem\n"
	.string "POKéMON beibringen?$"

gOtherText_UsedItem:: @ 840EA4F
	.string "{PLAYER} setzt\n"
	.string "{STR_VAR_2} ein.{PAUSE_UNTIL_PRESS}$"

gOtherText_RepelLingers:: @ 840EA61
	.string "Aber SCHUTZ wirkt doch\n"
	.string "noch!{PAUSE_UNTIL_PRESS}$"

gOtherText_UsedFlute:: @ 840EA95
	.string "{PLAYER} setzt\n"
	.string "{STR_VAR_2} ein.\p"
	.string "Wilde POKéMON werden angezogen.{PAUSE_UNTIL_PRESS}$"

gOtherText_UsedRepel:: @ 840EAC3
	.string "{PLAYER} setzt\n"
	.string "{STR_VAR_2} ein.\p"
	.string "Wilde POKéMON werden abgehalten.{PAUSE_UNTIL_PRESS}$"

gOtherText_BoxIsFull:: @ 840EAF4
	.string "Die BOXEN sind voll.{PAUSE_UNTIL_PRESS}$"

gOtherText_Size:: @ 840EB07
	.string "MASS:$"

gOtherText_Firm:: @ 840EB0E
	.string "GÜTE:$"

gContestStatsText_Unknown1:: @ 840EB15
	.string "{STR_VAR_1},{STR_VAR_2} cm$"

ContestStatsText_VerySoft::
	.string "Sehr weich$"
ContestStatsText_Soft::
	.string "Weich$"
ContestStatsText_Hard::
	.string "Hart$"
ContestStatsText_VeryHard::
	.string "Sehr hart$"
ContestStatsText_SuperHard::
	.string "Steinhart$"
ContestStatsText_RedPokeBlock::
	.string "{POKEBLOCK} ROT$"
ContestStatsText_BluePokeBlock::
	.string "{POKEBLOCK} BLAU$"
ContestStatsText_PinkPokeBlock::
	.string "{POKEBLOCK} ROSA$"
ContestStatsText_GreenPokeBlock::
	.string "{POKEBLOCK} GRÜN$"
ContestStatsText_YellowPokeBlock::
	.string "{POKEBLOCK} GELB$"
ContestStatsText_PurplePokeBlock::
	.string "{POKEBLOCK} LILA$"
ContestStatsText_IndigoPokeBlock::
	.string "{POKEBLOCK} INDIGO$"
ContestStatsText_BrownPokeBlock::
	.string "{POKEBLOCK} BRAUN$"
ContestStatsText_LiteBluePokeBlock::
	.string "{POKEBLOCK} CYAN$"
ContestStatsText_OlivePokeBlock::
	.string "{POKEBLOCK} OLIV$"
ContestStatsText_GrayPokeBlock::
	.string "{POKEBLOCK} GRAU$"
ContestStatsText_BlackPokeBlock::
	.string "{POKEBLOCK} SCHWARZ$"
ContestStatsText_WhitePokeBlock::
	.string "{POKEBLOCK} WEISS$"
ContestStatsText_GoldPokeBlock::
	.string "{POKEBLOCK} GOLD$"

gContestStatsText_Spicy:: @ 840EBED
	.string "SCHARF$"

gContestStatsText_Dry:: @ 840EBF3
	.string "TROCKEN$"

gContestStatsText_Sweet:: @ 840EBF7
	.string "SÜSS$"

gContestStatsText_Bitter:: @ 840EBFD
	.string "BITTER$"

gContestStatsText_Sour:: @ 840EC04
	.string "SAUER$"
	.string "LECKER$"
	.string "WÜRZE$"

gContestStatsText_StowCase:: @ 840EC14
	.string "BOX verstauen.$"

gContestStatsText_ThrowAwayPrompt:: @ 840EC1F
	.string "{STR_VAR_1}\n"
	.string "wegwerfen?$"

gContestStatsText_WasThrownAway:: @ 840EC33
	.string "{STR_VAR_1}\n"
	.string "wurde weggeworfen.$"

gContestStatsText_NormallyAte:: @ 840EC4B
	.string "{STR_VAR_1} aß den\n"
	.string "{STR_VAR_2}.{PAUSE_UNTIL_PRESS}$"

gContestStatsText_HappilyAte:: @ 840EC5C
	.string "{STR_VAR_1} aß gerne den\n"
	.string "{STR_VAR_2}.{PAUSE_UNTIL_PRESS}$"

gContestStatsText_DisdainfullyAte:: @ 840EC75
	.string "{STR_VAR_1} aß ungern den\n"
	.string "{STR_VAR_2}.{PAUSE_UNTIL_PRESS}$"

MartText_Buy::
	.string "KAUFEN$"
MartText_Sell::
	.string "VERKAUFEN$"
MartText_Quit2::
	.string "TSCHÜSS!$"

gOtherText_QuitShopping:: @ 840ECA1
	.string "Einkauf beenden.$"

gOtherText_HowManyYouWant:: @ 840ECB0
	.string "{STR_VAR_1}? Aber gerne.\n"
	.string "Wie viele möchtest du?$"

gOtherText_ThatWillBe:: @ 840ECD8
	.string "{STR_VAR_1}? Und du möchtest {STR_VAR_2}?\n"
	.string "Das macht dann ¥{STR_VAR_3}.$"

gOtherText_ThatWillBe2:: @ 840ED01
	.string "{STR_VAR_1} soll es sein?\n"
	.string "Das kostet ¥{STR_VAR_2}. Einverstanden?$"

gOtherText_ThatWillBe3:: @ 840ED2C
	.string "Du wolltest {STR_VAR_1}?\n"
	.string "Das kostet ¥{STR_VAR_2}. Einverstanden?$"

gOtherText_HereYouGo:: @ 840ED5E
	.string "Bitte sehr!\n"
	.string "Und vielen Dank.$"

gOtherText_HereYouGo2:: @ 840ED80
	.string "Vielen Dank!\n"
	.string "Es wird auf deinen PC übertragen.$"

gOtherText_HereYouGo3:: @ 840EDA9
	.string "Danke!\n"
	.string "Es wird auf deinen PC übertragen.$"

gOtherText_NotEnoughMoney:: @ 840EDD2
	.string "Du hast nicht genug Geld.{PAUSE_UNTIL_PRESS}$"

gOtherText_NoRoomFor:: @ 840EDF1
	.string "Du hast keinen Platz für weitere Items.{PAUSE_UNTIL_PRESS}$"

gOtherText_SpaceForIsFull:: @ 840EE14
	.string "Es ist kein Platz für {STR_VAR_1}.{PAUSE_UNTIL_PRESS}$"

gOtherText_AnythingElse:: @ 840EE30
	.string "Gibt es noch etwas, womit\n"
	.string "ich dienen kann?$"

gOtherText_CanIHelpYou:: @ 840EE5C
	.string "Kann ich dir sonst noch dienlich sein?$"

gOtherText_FreePremierBall:: @ 840EE7F
	.string "Ich gebe dir noch einen PREMIERBALL.{PAUSE_UNTIL_PRESS}$"

gOtherText_CantBuyThat:: @ 840EEA4
	.string "{STR_VAR_2}? Es tut mir Leid, aber\n"
	.string "das kann ich nicht kaufen.{PAUSE_UNTIL_PRESS}$"

gOtherText_HowManyToSell:: @ 840EEC4
	.string "{STR_VAR_2}?\n"
	.string "Wie viele möchtest du verkaufen?$"

gOtherText_CanPay:: @ 840EEE9
	.string "Ich gebe dir ¥{STR_VAR_1}.\n"
	.string "Bist du damit einverstanden?$"

gOtherText_SoldItem:: @ 840EF0C
	.string "{STR_VAR_2} wurde übergeben\n"
	.string "im Tausch gegen ¥{STR_VAR_1}.$"

OtherText_Money::
	.string "¥{STR_VAR_1}$"
OtherText_Shift::
	.string "TAUSCH$"
OtherText_SendOut::
	.string "AUSSENDEN$"
OtherText_Switch2::
	.string "TAUSCH$"
OtherText_Summary::
	.string "BERICHT$"
OtherText_Moves::
	.string "ATTACKEN$"
OtherText_Enter2::
	.string "EINTRAGEN$"
OtherText_NoEntry::
	.string "AUSTRAGEN$"
OtherText_Take::
	.string "NEHMEN$"
OtherText_Read2::
	.string "LESEN$"

gOtherText_Hp2:: @ 840EF72
	.string "KP$"

gOtherText_SpAtk2:: @ 840EF75
	.string "SP. ANG.$"

gOtherText_SpDef2:: @ 840EF7D
	.string "SP. VER.$"

gOtherText_WontHaveAnyEffect:: @ 840EF85
	.string "Es wird keine Wirkung haben.{PAUSE_UNTIL_PRESS}$"

gOtherText_CantUseOnPoke:: @ 840EFA1
	.string "Das kann nicht bei diesem\n"
	.string "POKéMON eingesetzt werden.{PAUSE_UNTIL_PRESS}$"

gOtherText_CantBeSwitched:: @ 840EFCC
	.string "{STR_VAR_1} kann nicht ausge-\n"
	.string "tauscht werden!{PAUSE_UNTIL_PRESS}$"

gOtherText_AlreadyBattle:: @ 840EFE8
	.string "{STR_VAR_1}\n"
	.string "kämpft bereits!{PAUSE_UNTIL_PRESS}$"

gOtherText_AlreadySelected:: @ 840F003
	.string "{STR_VAR_1} ist\n"
	.string "bereits ausgewählt.{PAUSE_UNTIL_PRESS}$"

gOtherText_NoEnergyLeft:: @ 840F023
	.string "{STR_VAR_1} kann\n"
	.string "nicht kämpfen!{PAUSE_UNTIL_PRESS}$"

gOtherText_CantSwitchPokeWithYours:: @ 840F046
	.string "Ein POKéMON von {STR_VAR_1} ist\n"
	.string "nicht gegen deins eintauschbar!{PAUSE_UNTIL_PRESS}$"

gOtherText_EGGCantBattle:: @ 840F079
	.string "Ein EI kann nicht kämpfen!{PAUSE_UNTIL_PRESS}$"

gOtherText_CantBeUsedBadge:: @ 840F090
	.string "Das ist erst einsetzbar, wenn\n"
	.string "ein neuer ORDEN errungen wurde.$"

gOtherText_NoMoreThreePoke:: @ 840F0C2
	.string "Es können nicht mehr als\n"
	.string "drei POKéMON teilnehmen.$"

gOtherText_SendRemovedMailPrompt:: @ 840F0E8
	.string "Den abgenommenen BRIEF\n"
	.string "auf deinen PC übertragen?$"

gOtherText_MailWasSent:: @ 840F10A
	.string "Der BRIEF wurde auf deinen\n"
	.string "PC übertragen.{PAUSE_UNTIL_PRESS}$"

gOtherText_MailboxIsFull:: @ 840F12A
	.string "Du kannst keine weiteren BRIEFE\n"
	.string "auf deinen PC übertragen.{PAUSE_UNTIL_PRESS}$"

gOtherText_MailRemovedMessageLost:: @ 840F147
	.string "Wird der BRIEF entfernt, geht\n"
	.string "der Inhalt verloren, okay?$"

gOtherText_MailMustBeRemoved:: @ 840F17F
	.string "Der BRIEF muss entfernt werden,\n"
	.string "um ein Item tragen zu können.{PAUSE_UNTIL_PRESS}$"

gOtherText_WasGivenToHold:: @ 840F1AE
	.string "{STR_VAR_1} erhält\n"
	.string "{STR_VAR_2} zum Tragen.{PAUSE_UNTIL_PRESS}$"

gOtherText_AlreadyHolding:: @ 840F1CD
	.string "{STR_VAR_1} trägt bereits\n"
	.string "{STR_VAR_2}.\p"
	.string "Sollen die Items ausge-\n"
	.string "tauscht werden?$"

gOtherText_NotHoldingAnything:: @ 840F213
	.string "{STR_VAR_1} trägt\n"
	.string "kein Item.{PAUSE_UNTIL_PRESS}$"

gOtherText_ReceivedTheThingFrom:: @ 840F230
	.string "{STR_VAR_2} von\n"
	.string "{STR_VAR_1} erhalten.{PAUSE_UNTIL_PRESS}$"

gOtherText_MailTaken:: @ 840F24B
	.string "Der BRIEF wurde dem\n"
	.string "POKéMON abgenommen.{PAUSE_UNTIL_PRESS}$"

gOtherText_TakenAndReplaced:: @ 840F26E
	.string "{STR_VAR_2} wurde gegen\n"
	.string "{STR_VAR_1} ausgetauscht.{PAUSE_UNTIL_PRESS}$"

gOtherText_PokeHoldingItemCantMail:: @ 840F29B
	.string "Dieses POKéMON trägt ein Item.\n"
	.string "Es kann keinen BRIEF tragen.{PAUSE_UNTIL_PRESS}$"

gOtherText_MailTransferredMailbox:: @ 840F2D3
	.string "Der BRIEF wurde von deinem\n"
	.string "PC heruntergeladen.{PAUSE_UNTIL_PRESS}$"

gOtherText_BagFullCannotRemoveItem:: @ 840F2FC
	.string "Der BEUTEL ist voll. Das Item des\n"
	.string "POKéMON wurde nicht entfernt.{PAUSE_UNTIL_PRESS}$"

gOtherText_LearnedMove:: @ 840F338
	.string "{STR_VAR_1} erlernt\n"
	.string "{STR_VAR_2}!$"

gOtherText_NotCompatible:: @ 840F347
	.string "{STR_VAR_1} und {STR_VAR_2}\n"
	.string "sind nicht kompatibel.\p"
	.string "{STR_VAR_2} kann nicht \n"
	.string "erlernt werden.{PAUSE_UNTIL_PRESS}$"

gOtherText_WantsToLearn:: @ 840F37C
	.string "{STR_VAR_1} versucht,\n"
	.string "{STR_VAR_2} zu erlernen.\p"
	.string "Aber {STR_VAR_1} kann maximal\n"
	.string "vier Attacken erlernen.\p"
	.string "Soll eine andere Attacke durch\n"
	.string "{STR_VAR_2} ersetzt werden?$"

gOtherText_StopTryingTo:: @ 840F3F0
	.string "{STR_VAR_2} nicht\n"
	.string "erlernen?$"

gOtherText_DidNotLearnMove2:: @ 840F409
	.string "{STR_VAR_1} hat {STR_VAR_2}\n"
	.string "nicht erlernt.{PAUSE_UNTIL_PRESS}$"

gOtherText_WhichMoveToForget2:: @ 840F429
	.string "Welche Attacke soll vergessen\n"
	.string "werden?{PAUSE_UNTIL_PRESS}$"

gOtherText_ForgetMove123_2:: @ 840F44B
	.string "{PAUSE 32}1, {PAUSE 15}2 und{PAUSE 15}... {PAUSE 15}... {PAUSE 15}... {PAUSE 15}{PLAY_SE 0x38 0x00} Schwupp!\p"
	.string "{STR_VAR_1} hat\n"
	.string "{STR_VAR_2} vergessen.\p"
	.string "Und...{PAUSE_UNTIL_PRESS}$"

gOtherText_AlreadyKnows:: @ 840F49E
	.string "{STR_VAR_1} kennt\n"
	.string "{STR_VAR_2}.{PAUSE_UNTIL_PRESS}$"

gOtherText_HPRestoredBy:: @ 840F4B5
	.string "Die KP von {STR_VAR_1} wurden\n"
	.string "um {STR_VAR_2} Punkte aufgefüllt.{PAUSE_UNTIL_PRESS}$"

gOtherText_CuredPoisoning:: @ 840F4DA
	.string "Die Vergiftung von {STR_VAR_1}\n"
	.string "wurde geheilt.{PAUSE_UNTIL_PRESS}$"

gOtherText_CuredParalysis:: @ 840F4FB
	.string "Die Paralyse von {STR_VAR_1}\n"
	.string "wurde aufgehoben.{PAUSE_UNTIL_PRESS}$"

gOtherText_WokeUp:: @ 840F518
	.string "{STR_VAR_1} ist aufgewacht.{PAUSE_UNTIL_PRESS}$"

gOtherText_BurnHealed:: @ 840F526
	.string "Verbrennung von {STR_VAR_1}\n"
	.string "wurde geheilt.{PAUSE_UNTIL_PRESS}$"

gOtherText_ThawedOut:: @ 840F53E
	.string "{STR_VAR_1} wurde aufgetaut.{PAUSE_UNTIL_PRESS}$"

gOtherText_PPRestored:: @ 840F553
	.string "AP wurden aufgefüllt.{PAUSE_UNTIL_PRESS}$"

gOtherText_RegainedHealth:: @ 840F566
	.string "{STR_VAR_1} erholte sich.{PAUSE_UNTIL_PRESS}$"

gOtherText_BecameHealthy:: @ 840F57C
	.string "{STR_VAR_1} erholte sich.{PAUSE_UNTIL_PRESS}$"

gOtherText_PPIncreased:: @ 840F591
	.string "AP von {STR_VAR_1}\n"
	.string "wurden angehoben.{PAUSE_UNTIL_PRESS}$"

gOtherText_ElevatedTo:: @ 840F5A6
	.string "{STR_VAR_1} erreicht\n"
	.string "Lv. {STR_VAR_2}.$"

gOtherText_WasRaised:: @ 840F5C1
	.string "{STR_VAR_2} von\n"
	.string "{STR_VAR_1} wurde angehoben.{PAUSE_UNTIL_PRESS}$"

gOtherText_SnapConfusion:: @ 840F5D7
	.string "{STR_VAR_1} ist nicht\n"
	.string "mehr verwirrt.{PAUSE_UNTIL_PRESS}$"

gOtherText_GotOverLove:: @ 840F5FA
	.string "{STR_VAR_1} fühlt sich nicht\n"
	.string "mehr angezogen.{PAUSE_UNTIL_PRESS}$"

OtherText_ChoosePoke::
	.string "Wähle ein POKéMON.$"
OtherText_MovePokeTo::
	.string "An wessen Stelle setzen?$"
OtherText_TeachWhat::
	.string "Welches POKéMON lehren?$"
OtherText_UseWhat::
	.string "Welches POKéMON?$"
OtherText_GiveWhat::
	.string "Welchem POKéMON geben?$"
OtherText_DoWhat::
	.string "Was tun mit {STR_VAR_1}?$"
OtherText_NothingToCut::
	.string "Hier nicht einsetzbar.$"
OtherText_CantSurf::
	.string "SURFER nicht einsetzbar.$"
OtherText_AlreadySurfing::
	.string "SURFER ist eingesetzt.$"
OtherText_CantUseThatHere::
	.string "Hier nicht einsetzbar.$"
OtherText_RestoreWhatMove::
	.string "Welche Attacke auffüllen?$"
OtherText_BoostPP::
	.string "AP welcher Attacke heben?$"
OtherText_DoWhatWithItem::
	.string "Was willst du mit dem Item?$"
OtherText_NoPokeForBattle::
	.string "Kein POKéMON kampfbereit!$"
OtherText_ChoosePoke2::
	.string "Wähle ein POKéMON.$"
OtherText_NotEnoughHP::
	.string "Nicht genügend KP...$"
OtherText_ThreePokeNeeded::
	.string "Drei POKéMON sind nötig.$"
OtherText_PokeCantBeSame::
	.string "Nicht dieselben POKéMON!$"
OtherText_NoIdenticalHoldItems::
	.string "Nicht dieselben Items!$"
OtherText_TeachWhichPoke::
	.string "Welches POKéMON lehren?$"

gOtherText_Attack:: @ 840F7C6
	.string "ANGRIFF$"

gOtherText_Defense:: @ 840F7CD
	.string "VERT.$"

gOtherText_SpAtk:: @ 840F7D5
	.string "SP.ANG.$"

gOtherText_SpDef:: @ 840F7DD
	.string "SP.VER.$"

gOtherText_Speed:: @ 840F7E5
	.string "INIT.$"

gOtherText_HP:: @ 840F7EB
	.string "KP$"

gOtherText_Terminator18:: @ 840F7EE
	.string "$"

gOtherText_OriginalTrainer:: @ 840F7EF
	.string "OT:$"

gOtherText_Type2:: @ 840F7F3
	.string "TYP:$"

gOtherText_Power2:: @ 840F7F9
	.string "STÄRKE$"

gOtherText_Accuracy2:: @ 840F7FF
	.string "GENAU.$"

gOtherText_Appeal2:: @ 840F808
	.string "AUSDR.$"

gOtherText_Jam2:: @ 840F80F
	.string "EINDR.$"

gOtherText_Status:: @ 840F813
	.string "STATUS$"

gOtherText_ExpPoints:: @ 840F81A
	.string "E.-PUNKTE$"

gOtherText_NextLv:: @ 840F826
	.string "NÄCHST. Lv.$"

gOtherText_Ribbons00:: @ 840F82F
	.string "BÄNDER: 00$"

OtherText_Event::
	.string "GESCHEHEN$"
OtherText_Switch::
	.string "TAUSCH$"
OtherText_PokeInfo::
	.string "POKéMON-INFO$"
OtherText_PokeSkills::
	.string "POKéMON-FÄHIG.$"
OtherText_BattleMoves::
	.string "ATTACKEN$"
OtherText_ContestMoves::
	.string "WETT.-ATTACKEN$"
OtherText_Info::
	.string "INFO$"

gOtherText_EggLongTime:: @ 840F884
	.string "Dieses EI braucht sicher\n"
	.string "noch lange, bis es schlüpft.$"

gOtherText_EggSomeTime:: @ 840F8BB
	.string "Was da wohl schlüpfen wird?\n"
	.string "Es wird sicher lange dauern.$"

gOtherText_EggSoon:: @ 840F8EE
	.string "Es bewegt sich manchmal.\n"
	.string "Vielleicht schlüpft es bald?$"

gOtherText_EggAbout:: @ 840F91B
	.string "Es macht Geräusche.\n"
	.string "Sicher schlüpft es bald!$"

gOtherText_CantForgetHMs:: @ 840F944
	.string "VM-Attacken können jetzt\n"
	.string "nicht vergessen werden.$"

gOtherText_PlayersBase:: @ 840F965
	.string "BASIS v. {PLAYER}$"

gOtherText_OkayToDeleteFromRegistry:: @ 840F96D
	.string "Soll {STR_VAR_1} aus dem GRUNDBUCH\n"
	.string "gelöscht werden?$"

gOtherText_RegisteredDataDeleted:: @ 840F998
	.string "Eingetragene Daten wurden gelöscht.{PAUSE_UNTIL_PRESS}$"

gSecretBaseText_NoRegistry:: @ 840F9BB
	.string "Es gibt kein GRUNDBUCH.{PAUSE_UNTIL_PRESS}$"

SecretBaseText_DelRegist::
	.string "EINTR. LÖSCHEN$"
SecretBaseText_Decorate::
	.string "DEKORIEREN$"
SecretBaseText_PutAway::
	.string "WEGNEHMEN$"
SecretBaseText_Toss::
	.string "WEGWERFEN$"
SecretBaseText_PutOutDecor::
	.string "Wähle eine Dekoration \n"
	.string "und stelle sie auf.$"
SecretBaseText_StoreChosenDecor::
	.string "Wähle eine Dekoration und \n"
	.string "übertrage sie auf deinen PC.$"
SecretBaseText_ThrowAwayDecor::
	.string "Wähle eine Dekoration\n"
	.string "und wirf sie weg.$"

gSecretBaseText_NoDecors:: @ 840FA64
	.string "Es gibt keine Dekoration.{PAUSE_UNTIL_PRESS}$"

SecretBaseText_Desk::
	.string "TISCH$"
SecretBaseText_Chair::
	.string "STUHL$"
SecretBaseText_Plant::
	.string "PFLANZE$"
SecretBaseText_Ornament::
	.string "ORNAMENT$"
SecretBaseText_Mat::
	.string "MATTE$"
SecretBaseText_Poster::
	.string "POSTER$"
SecretBaseText_Doll::
	.string "PUPPE$"
SecretBaseText_Cushion::
	.string "KISSEN$"

gSecretBaseText_GoldRank:: @ 840FAB2
	.string "GOLD$"

gSecretBaseText_SilverRank:: @ 840FAB7
	.string "SILBER$"

gSecretBaseText_PlaceItHere:: @ 840FABE
	.string "Hierhin platzieren?$"

gSecretBaseText_CantBePlacedHere:: @ 840FACD
	.string "Kann hier nicht platziert werden.$"

gSecretBaseText_CancelDecorating:: @ 840FAE6
	.string "Dekorieren beenden?$"

gSecretBaseText_InUseAlready:: @ 840FAF9
	.string "Das wurde bereits platziert.$"

gSecretBaseText_NoMoreDecor:: @ 840FB11
	.string "Mehr kann nicht dekoriert werden. Es\n"
	.string "ist nur Platz für {STR_VAR_1} Dekorationen.$"

gSecretBaseText_NoMoreDecor2:: @ 840FB57
	.string "Mehr kann nicht dekoriert werden. Es\n"
	.string "ist nur Platz für {STR_VAR_1} Dekorationen.$"

gSecretBaseText_DecorMustPlaceOnTable::
	.string "Das geht nicht. Es muss auf einem\n"
	.string "TISCH oder Ähnlichem stehen.$"

gSecretBaseText_DecorCantPlace:: @ 840FBD3
	.string "Die Dekoration kann nicht in deinem\n"
	.string "eigenen Zimmer aufgestellt werden.$"

gSecretBaseText_DecorInUse:: @ 840FC05
	.string "Diese Dekoration wurde platziert.\n"
	.string "Du kannst sie nicht wegwerfen.$"

gSecretBaseText_WillBeDiscarded:: @ 840FC39
	.string "{STR_VAR_1} wird weggeworfen.\n"
	.string "Einverstanden?$"

gSecretBaseText_DecorThrownAway:: @ 840FC62
	.string "Die Dekoration wurde weggeworfen.$"

gSecretBaseText_StopPuttingAwayDecor:: @ 840FC87
	.string "Wegnehmen von Dekoration beenden?$"

gSecretBaseText_NoDecor:: @ 840FCA6
	.string "Hier ist keine Dekoration.$"

gSecretBaseText_ReturnDecor:: @ 840FCC8
	.string "Diese Dekoration auf \n"
	.string "den PC übertragen?$"

gSecretBaseText_DecorReturned:: @ 840FCEA
	.string "Die Dekoration wurde auf\n"
	.string "den PC übertragen.$"

gSecretBaseText_NoDecorInUse:: @ 840FD11
	.string "Es sind keine Dekorationen platziert.{PAUSE_UNTIL_PRESS}$"

SecretBaseText_Tristan:: @ 840FD34
	.string "TATIAN$"

SecretBaseText_Philip::
	.string "LARS$"
SecretBaseText_Dennis::
	.string "KLAAS$"
SecretBaseText_Roberto::
	.string "HAINER$"
SecretBaseText_TurnOff::
	.string "AUSSCHALTEN$"
SecretBaseText_Decoration::
	.string "DEKORATION$"
SecretBaseText_ItemStorage::
	.string "ITEM-LAGER$"

gPCText_Mailbox:: @ 840FD73
	.string "BRIEFBOX$"

PCText_DepositItem::
	.string "ITEM ABLEGEN$"
PCText_WithdrawItem::
	.string "ITEM NEHMEN$"
PCText_TossItem::
	.string "ITEM IN MÜLL$"
PCText_StoreItems::
	.string "Lagere Items auf deinem PC.$"
PCText_TakeOutItems::
	.string "Nimm Items von deinem PC.$"
PCText_ThrowAwayItems::
	.string "Wirf gelagerte Items weg.$"

gOtherText_NoItems:: @ 840FDF6
	.string "Es gibt keine Items.{PAUSE_UNTIL_PRESS}$"

gOtherText_NoMoreRoom:: @ 840FE0C
	.string "In deinem BEUTEL\n"
	.string "ist kein Platz mehr.$"

gOtherText_HowManyToWithdraw:: @ 840FE2E
	.string "Wie viele möchtest\n"
	.string "du aufnehmen?$"

gOtherText_WithdrewThing:: @ 840FE50
	.string "{STR_VAR_2} × {STR_VAR_1}\n"
	.string "aufgenommen.$"

OtherText_Read::
	.string "LESEN$"

gOtherText_MoveToBag:: @ 840FE68
	.string "IN BEUTEL GEBEN$"

OtherText_Give::
	.string "GEBEN$"

gOtherText_NoMailHere:: @ 840FE79
	.string "Hier ist kein BRIEF.{PAUSE_UNTIL_PRESS}$"

gOtherText_WhatWillYouDoMail:: @ 840FE91
	.string "Was soll mit dem BRIEF von\n"
	.string "{STR_VAR_1} geschehen?$"

gOtherText_MessageWillBeLost:: @ 840FEBB
	.string "Der Inhalt geht verloren.\n"
	.string "Ist das in Ordnung für dich?$"

gOtherText_BagIsFull:: @ 840FEE3
	.string "Der BEUTEL ist voll.{PAUSE_UNTIL_PRESS}$"

gOtherText_MailWasReturned:: @ 840FEF6
	.string "Der BRIEF, dessen Inhalt gelöscht\n"
	.string "ist, wurde im BEUTEL gelagert.{PAUSE_UNTIL_PRESS}$"

gOtherText_Dad:: @ 840FF32
	.string "VATI$"

gOtherText_Mom:: @ 840FF36
	.string "MUTTI$"

gOtherText_Wallace:: @ 840FF3A
	.string "WASSILI$"

gOtherText_Steven:: @ 840FF42
	.string "TROY$"

gOtherText_Brawly:: @ 840FF49
	.string "KAMILLO$"

gOtherText_Winona:: @ 840FF50
	.string "WIBKE$"

gOtherText_Phoebe:: @ 840FF57
	.string "ANTONIA$"

gOtherText_Glacia:: @ 840FF5E
	.string "FROSINA$"

gContestText_ContestWinner:: @ 840FF65
	.string "-WETTBEWERBSSIEGER\n$"

gOtherText_Unknown1:: @ 840FF75
	.string " von $"

OtherText_Cool::
	.string "COOL.$"
OtherText_Beauty2::
	.string "SCHÖN.$"
OtherText_Cute::
	.string "ANMUT$"
OtherText_Smart::
	.string "KLUG.$"
OtherText_Tough::
	.string "STÄRKE$"
OtherText_NonstopSuperCool::
	.string "Super-mega-cool ist\n"
	.string "dieses umwerfende $"
OtherText_Terminator6::
	.string "$"
OtherText_GoodLookingPoke::
	.string "Das anbetungswürdige\n"
	.string "POKéMON: $"
OtherText_Terminator7::
	.string "$"
OtherText_MarvelousGreat::
	.string "Phantastisch, großartig -\n"
	.string "schlicht brillant: $"
OtherText_Terminator8::
	.string "$"
OtherText_CenturyLastVenus::
	.string "Ein Bild von einem POKéMON!\n"
	.string "Das wunderschöne $"
OtherText_Terminator9::
	.string "$"
OtherText_Terminator10::
	.string "Einfach umwerfend, das strahlende\n"
	.string "Lächeln von $"
OtherText_DazzlingSlime::
	.string "$"
OtherText_PokeCenterIdol::
	.string "Superstar des POKéMON-CENTERs -\n"
	.string "das unvergleichliche $"
OtherText_Terminator11::
	.string "$"
OtherText_LovelyAndSweet::
	.string "Das liebliche, zuckersüße $"
OtherText_Terminator12::
	.string "$"
OtherText_ThePretty::
	.string "Das Gewinner-Portrait\n"
	.string "von dem hübschen $"
OtherText_WinningPortrait::
	.string "$"
OtherText_GiveUsWink::
	.string "Winke uns zu, du\n"
	.string "goldiges $"
OtherText_Terminator13::
	.string "$"
OtherText_SmartnessMaestro::
	.string "Der Gelehrte unter den\n"
	.string "POKéMON! Das weise $"
OtherText_Terminator14::
	.string "$"
OtherText_ChosenPokeAmong::
	.string "Das auserwählte und\n"
	.string "einzigartige POKéMON: $"
OtherText_Terminator15::
	.string "$"
OtherText_TheExcellent::
	.string "Das grandiose $"
OtherText_ItsMomentOfElegance::
	.string " -\n"
	.string "der Inbegriff von Eleganz und Stil$"
OtherText_PowerfullyMuscular::
	.string "Der energische, kraftstrotzende\n"
	.string "Überflieger: $"
OtherText_Terminator16::
	.string "$"
OtherText_StrongErEst::
	.string "Stark, stärker, am stärksten -\n"
	.string "das allerstärkste $"
OtherText_Terminator17::
	.string "$"
OtherText_MightyTough::
	.string "Das mächtige, prächtige - das\n"
	.string "stärkste POKéMON: $"
OtherText_Exclamation::
	.string "$"
OtherText_Petalburg::
	.string "BLÜTENBURG CITY$"
OtherText_Slateport::
	.string "GRAPHITPORT CITY$"
OtherText_Littleroot::
	.string "WURZELHEIM$"
OtherText_Lilycove::
	.string "SEEGRASULB CITY$"
OtherText_Dewford::
	.string "FAUSTAUHAVEN$"
OtherText_Enter::
	.string "JA$"
OtherText_Info3::
	.string "INFO$"
OtherText_WhatsAContest::
	.string "Der WETTBEWERB$"
OtherText_TypesOfContest::
	.string "WETTBEWERB-Arten$"
OtherText_Ranks::
	.string "Klassen$"
OtherText_Judging::
	.string "Bewertung$"
OtherText_CoolContest::
	.string "COOL.-WETTB.$"
OtherText_BeautyContest::
	.string "SCHÖN.-WETTB.$"
OtherText_CuteContest::
	.string "ANMUT-WETTB.$"
OtherText_SmartContest::
	.string "KLUG.-WETTB.$"
OtherText_ToughContest::
	.string "STÄRKE-WETTB.$"
OtherText_Decoration::
	.string "DEKORATION$"
OtherText_PackUp::
	.string "EINPACKEN$"
OtherText_Count::
	.string "ZÄHLEN$"
OtherText_Registry::
	.string "GRUNDBUCH$"
OtherText_Information::
	.string "INFORMATION$"
OtherText_Mach::
	.string "EIL$"
OtherText_Acro::
	.string "KUNST$"
OtherText_Poison::
	.string "GIF$"
OtherText_Paralysis::
	.string "PAR$"
OtherText_Sleep::
	.string "SLF$"
OtherText_Burn::
	.string "BRT$"
OtherText_Frozen::
	.string "GFR$"
OtherText_Quit::
	.string "ZURÜCK$"
OtherText_SawIt::
	.string "Gesehen$"
OtherText_NotYet::
	.string "Noch nicht$"
OtherText_Yes::
	.string "JA$"
OtherText_No::
	.string "NEIN$"
OtherText_Info2::
	.string "INFO$"
OtherText_SingleBattle::
	.string "EINZELKAMPF$"
OtherText_DoubleBattle::
	.string "DOPPELKAMPF$"
OtherText_MultiBattle::
	.string "MULTIKAMPF$"
OtherText_MrBriney::
	.string "MR. BRACK$"
OtherText_MakeAChallenge::
	.string "Zum Kampf fordern$"
OtherText_ObtainInformation::
	.string "Information dazu$"
OtherText_Lv50_2::
	.string "Lv. 50$"
OtherText_Lv100_2::
	.string "Lv. 100$"
OtherText_Zigzagoon::
	.string "ZIGZACHS$"
OtherText_Nincada::
	.string "NINCADA$"
OtherText_Poochyena::
	.string "FIFFYEN$"
OtherText_Nincada2::
	.string "NINCADA$"
OtherText_Lotad::
	.string "LOTURZEL$"
OtherText_Roselia::
	.string "ROSELIA$"
OtherText_Shroomish::
	.string "KNILZ$"
OtherText_Nincada3::
	.string "NINCADA$"
OtherText_Surskit::
	.string "GEHWEIHER$"
OtherText_Treecko::
	.string "GECKARBOR$"
OtherText_Torchic::
	.string "FLEMMLI$"
OtherText_Mudkip::
	.string "HYDROPI$"
OtherText_Seedot::
	.string "SAMURZEL$"
OtherText_Shroomish2::
	.string "KNILZ$"
OtherText_Spinda::
	.string "PANDIR$"
OtherText_Shroomish3::
	.string "KNILZ$"
OtherText_Zigzagoon2::
	.string "ZIGZACHS$"
OtherText_Wurmple::
	.string "WAUMPEL$"
OtherText_PokeBall::
	.string "POKéBALL$"
OtherText_SuperPotion::
	.string "SUPERTRANK$"
OtherText_SamePrice::
	.string "Zum selben Preis$"
OtherText_Yen135::
	.string "¥135$"
OtherText_Yen155::
	.string "¥155$"
OtherText_Yen175::
	.string "¥175$"
OtherText_CostMore::
	.string "Sie kosten mehr.$"
OtherText_CostLess::
	.string "Sie kosten weniger.$"
OtherText_SamePrice2::
	.string "Gleicher Preis$"
OtherText_MaleSymbol::
	.string "♂$"
OtherText_FemaleSymbol::
	.string "♀$"
OtherText_Neither::
	.string "Weder noch$"
OtherText_Males::
	.string "Männer$"
OtherText_Females::
	.string "Frauen$"
OtherText_SameNumber::
	.string "Gleich viele$"
OtherText_Male::
	.string "Männlich$"
OtherText_Female::
	.string "Weiblich$"
OtherText_ItDepends::
	.string "Ansichtssache$"
OtherText_Six2::
	.string "6$"
OtherText_Eight2::
	.string "8$"
OtherText_Ten::
	.string "10$"
OtherText_One::
	.string "1$"
OtherText_Two::
	.string "2$"
OtherText_Three::
	.string "3$"
OtherText_Six::
	.string "6$"
OtherText_Seven::
	.string "7$"
OtherText_Eight::
	.string "8$"
OtherText_FreshWater::
	.string "TAFELWASSER{CLEAR_TO 72}¥200$"
OtherText_SodaPop::
	.string "SPRUDEL{CLEAR_TO 72}¥300$"
OtherText_Lemonade::
	.string "LIMONADE{CLEAR_TO 72}¥350$"
OtherText_HowToRide::
	.string "RAD FAHREN$"
OtherText_HowToTurn::
	.string "KURVEN FAHREN$"
OtherText_SandySlopes::
	.string "SANDHÜGEL$"
OtherText_Wheelies::
	.string "WHEELIES$"
OtherText_BunnyHops::
	.string "HOPPELN$"
OtherText_Jumping::
	.string "SPRINGEN$"
OtherText_Satisfied::
	.string "Zufrieden$"
OtherText_Dissatisfied::
	.string "Unzufrieden$"
OtherText_Deepseatooth::
	.string "ABYSSZAHN$"
OtherText_Deepseascale::
	.string "ABYSSPLATTE$"
OtherText_BlueFlute2::
	.string "BLAUE FLÖTE$"
OtherText_YellowFlute2::
	.string "GELBE FLÖTE$"
OtherText_RedFlute2::
	.string "ROTE FLÖTE$"
OtherText_WhiteFlute2::
	.string "WEISSE FLÖTE$"
OtherText_BlackFlute2::
	.string "SCHWRZ. FLÖTE$"
OtherText_GlassChair::
	.string "GLASSTUHL$"
OtherText_GlassDesk::
	.string "GLASTISCH$"
OtherText_TreeckoDoll::
	.string "GECKARBOR-PUPPE 1.000 M.$"
OtherText_TorchicDoll::
	.string "FLEMMLI-PUPPE 1.000 M.$"
OtherText_MudkipDoll::
	.string "HYDROPI-PUPPE 1.000 M.$"
OtherText_50Coins::
	.string "  50 MÜNZEN    ¥1.000$"
OtherText_500Coins::
	.string "500 MÜNZEN  ¥10.000$"
OtherText_Excellent::
	.string "Klasse!$"
OtherText_NotSoHot::
	.string "Naja...$"
OtherText_RedShard::
	.string "PURPURSTÜCK$"
OtherText_YellowShard::
	.string "GELBSTÜCK$"
OtherText_BlueShard::
	.string "INDIGOSTÜCK$"
OtherText_GreenShard::
	.string "GRÜNSTÜCK$"
OtherText_BattleTower::
	.string "DUELLTURM$"
OtherText_Right::
	.string "Rechts$"
OtherText_Left::
	.string "Links$"
OtherText_TM32::
	.string "TM32  1.500 MÜNZEN$"
OtherText_TM29::
	.string "TM29  3.500 MÜNZEN$"
OtherText_TM35::
	.string "TM35  4.000 MÜNZEN$"
OtherText_TM24::
	.string "TM24  4.000 MÜNZEN$"
OtherText_TM13::
	.string "TM13  4.000 MÜNZEN$"
OtherText_1F_2::
	.string "EG$"
OtherText_2F_2::
	.string "1S$"
OtherText_3F_2::
	.string "2S$"
OtherText_4F_2::
	.string "3S$"
OtherText_5F_2::
	.string "4S$"
OtherText_Cool2::
	.string "COOL.$"
OtherText_Beauty3::
	.string "SCHÖN.$"
OtherText_Cute2::
	.string "ANMUT$"
OtherText_Smart2::
	.string "KLUG.$"
OtherText_Tough2::
	.string "STÄRKE$"
OtherText_Normal::
	.string "NORMAL$"
OtherText_Super::
	.string "SUPER$"
OtherText_Hyper::
	.string "HYPER$"
OtherText_Master::
	.string "MASTER$"
OtherText_Cool3::
	.string "COOL.$"
OtherText_Beauty4::
	.string "SCHÖN.$"
OtherText_Cute3::
	.string "ANMUT$"
OtherText_Smart3::
	.string "KLUG.$"
OtherText_Tough3::
	.string "STÄRKE$"
OtherText_Items::
	.string "ITEM$"
OtherText_KeyItems::
	.string "BASIS-ITEM$"
OtherText_Balls::
	.string "BALL$"
OtherText_TMsHMs::
	.string "TM/VM$"
OtherText_Berries::
	.string "BEEREN$"

gPCText_SomeonesPC:: @ 8410753
	.string "JEMANDES PC$"

gPCText_LanettesPC:: @ 8410760
	.string "LANETTES PC$"

gPCText_PlayersPC:: @ 841076D
	.string "PC von {PLAYER}$"

gPCText_HallOfFame:: @ 8410775
	.string "RUHMESHALLE$"

gPCText_LogOff:: @ 8410782
	.string "AUSLOGGEN$"

gOtherText_99Times:: @ 841078A
	.string "99-mal +$"

gOtherText_1Minute:: @ 8410795
	.string "1 Minute +$"

gOtherText_Seconds:: @ 84107A0
	.string " Sekunden$"

gOtherText_Times:: @ 84107A9
	.string "-mal$"
	.string ".$"

gOtherText_BigGuy:: @ 84107B2
	.string "$"

gOtherText_BigGirl:: @ 84107BA
	.string "$"

gOtherText_Son:: @ 84107C3
	.string "Sohn$"

gOtherText_Daughter:: @ 84107C7
	.string "Tochter$"

OtherText_BlueFlute::
	.string "BLAUE FLÖTE$"
OtherText_YellowFlute::
	.string "GELBE FLÖTE$"
OtherText_RedFlute::
	.string "ROTE FLÖTE$"
OtherText_WhiteFlute::
	.string "WEISSE FLÖTE$"
OtherText_BlackFlute::
	.string "SCHWRZ. FLÖTE$"
OtherText_PrettyChair::
	.string "EDLER STUHL$"
OtherText_PrettyDesk::
	.string "EDLER TISCH$"
OtherText_1F::
	.string "EG$"
OtherText_2F::
	.string "1S$"
OtherText_3F::
	.string "2S$"
OtherText_4F::
	.string "3S$"
OtherText_5F::
	.string "4S$"
OtherText_6F::
	.string "5S$"
OtherText_7F::
	.string "6S$"
OtherText_8F::
	.string "7S$"
OtherText_9F::
	.string "8S$"
OtherText_10F::
	.string "9S$"
OtherText_11F::
	.string "10S$"
OtherText_B1F::
	.string "U1S$"
OtherText_B2F::
	.string "U2S$"
OtherText_B3F::
	.string "U3S$"
OtherText_B4F::
	.string "U4S$"
OtherText_Rooftop::
	.string "DACH$"

gOtherText_NowOn:: @ 841085E
	.string "Momentan im$"

gPCText_Cancel:: @ 8410866
	.string "ZURÜCK$"

PCText_ExitBox::
	.string "Die BOX verlassen?$"
PCText_WhatYouDo::
	.string "Was möchtest du tun?$"
PCText_PickATheme::
	.string "Wähle eine Motivsammlung.$"
PCText_PickAWallpaper::
	.string "Wähle ein Hintergrundmotiv.$"
PCText_IsSelected::
	.string " ist ausgewählt.$"
PCText_JumpToWhichBox::
	.string "Zu welcher BOX wechseln?$"
PCText_DepositInWhichBox::
	.string "In welche BOX ablegen?$"
PCText_WasDeposited::
	.string " wurde abgelegt.$"
PCText_BoxIsFull::
	.string "Die BOX ist voll.$"
PCText_ReleasePoke::
	.string "Dieses POKéMON freilassen?$"
PCText_WasReleased::
	.string "{STR_VAR_1} ist wieder frei.$"
PCText_ByeBye::
	.string "Tschüss, !$"
PCText_MarkPoke::
	.string "Markiere dein POKéMON.$"
PCText_LastPoke::
	.string "Dein letztes POKéMON!$"
PCText_PartyFull::
	.string "Dein Team ist voll!$"
PCText_HoldingPoke::
	.string "Du hältst ein POKéMON!$"
PCText_WhichOneWillTake::
	.string "Welches wählst du aus?$"
PCText_CantReleaseEgg::
	.string "Du kannst kein EI freilass.!$"
PCText_ContinueBox::
	.string "Die BOX weiter bearbeiten?$"
PCText_CameBack::
	.string " kam zurück!$"
PCText_Worried::
	.string "War es in Sorge um dich?$"
PCText_Surprise::
	.string "... ... ... ... ...!$"
PCText_PleaseRemoveMail::
	.string "BRIEF bitte entfernen.$"
PCText_Cancel2::
	.string "ZURÜCK$"
PCText_Deposit::
	.string "ABLEGEN$"
PCText_Withdraw::
	.string "NEHMEN$"
PCText_Switch::
	.string "TAUSCHEN$"
PCText_Move::
	.string "BEWEGEN$"
PCText_Place::
	.string "ABSETZEN$"
PCText_Summary::
	.string "BERICHT$"
PCText_Release::
	.string "ENTLASS.$"
PCText_Mark::
	.string "MARKIER.$"
PCText_Name::
	.string "BENENNEN$"
PCText_Jump::
	.string "WECHSELN$"
PCText_Wallpaper::
	.string "MOTIV$"
PCText_Scenery1::
	.string "LISTE 1$"
PCText_Scenery2::
	.string "LISTE 2$"
PCText_Scenery3::
	.string "LISTE 3$"
PCText_Etc::
	.string "SONSTIGES$"
PCText_Forest::
	.string "WALD$"
PCText_City::
	.string "MAUER$"
PCText_Desert::
	.string "WÜSTE$"
PCText_Savanna::
	.string "STEPPE$"
PCText_Crag::
	.string "GERÖLL$"
PCText_Volcano::
	.string "VULKAN$"
PCText_Snow::
	.string "SCHNEE$"
PCText_Cave::
	.string "HÖHLE$"
PCText_Beach::
	.string "STRAND$"
PCText_Seafloor::
	.string "TIEFSEE$"
PCText_River::
	.string "FLUSS$"
PCText_Sky::
	.string "HIMMEL$"
PCText_Polka::
	.string "PUNKTE$"
PCText_PokeCenter::
	.string "POKéCENTER$"
PCText_Machine::
	.string "MASCHINE$"
PCText_Plain::
	.string "WEISS$"
PCText_WhatDoYouWant::
	.string "Was willst du tun?$"
PCText_WithdrawPoke::
	.string "POKéMON NEHMEN$"
PCText_DepositPoke::
	.string "POKéMON ABLEGEN$"
PCText_MovePoke::
	.string "POKéMON BEWEGEN$"
PCText_SeeYa::
	.string "TSCHÜSSI!$"
PCText_MovePokeToParty::
	.string "Nimm POKéMON aus einer\n"
	.string "BOX in dein Team auf.$"
PCText_StorePokeInBox::
	.string "Lagere POKéMON aus deinem\n"
	.string "Team in einer BOX.$"
PCText_OrganizeBoxesParty::
	.string "Ordne POKéMON in den BOXEN\n"
	.string "und/oder in deinem Team.$"
PCText_ReturnToPrevMenu::
	.string "Zurück zum vorherigen Menü.$"

gPCText_OnlyOne:: @ 8410C1C
	.string "Du führst nur ein POKéMON mit dir.$"

gPCText_PartyFull2:: @ 8410C40
	.string "Dein Team ist voll!$"

gPCText_BOX:: @ 8410C54
	.string "BOX $"

PCText_CheckMap::
	.string "{CLEAR 0}Karte der HOENN-Region$"
PCText_CheckPoke::
	.string "{CLEAR 0}POKéMON-Daten im Detail$"
PCText_CheckTrainer::
	.string "{CLEAR 0}TRAINER-Daten im Detail$"
PCText_CheckRibbons::
	.string "{CLEAR 0}Einsicht über BÄNDER$"
PCText_PutAwayNav::
	.string "{CLEAR 0}POKéNAV schließen$"
PCText_NoRibbonWin::
	.string "{CLEAR 0}Es gibt keine BÄNDER.$"
PCText_NoTrainers::
	.string "{CLEAR 0}Keine TRAINER-Daten aufgenommen$"
PCText_CheckParty::
	.string "{CLEAR 0}Daten über POKéMON des Teams$"
PCText_CheckPokeAll::
	.string "{CLEAR 0}Daten über alle POKéMON$"
PCText_ReturnToNav::
	.string "{CLEAR 0}Zurück zum POKéNAV-Menü$"
PCText_FindCool::
	.string "{CLEAR 0}Nach coolen POKéMON suchen.$"
PCText_FindBeauty::
	.string "{CLEAR 0}Nach schönen POKéMON suchen.$"
PCText_FindCute::
	.string "{CLEAR 0}Nach anmutigen POKéMON suchen.$"
PCText_FindSmart::
	.string "{CLEAR 0}Nach klugen POKéMON suchen.$"
PCText_FindTough::
	.string "{CLEAR 0}Nach starken POKéMON suchen.$"
PCText_ReturnToCondition::
	.string "{CLEAR 0}Zurück zum Menüpunkt ZUSTAND$"

gOtherText_NumberRegistered:: @ 8410E22
	.string "Registrierte:$"

gOtherText_NumberBattles:: @ 8410E31
	.string "Kämpfe:$"

gOtherText_Strategy:: @ 8410E40
	.string "{PALETTE 5}TAKTIK:$"

gOtherText_TrainersPokemon:: @ 8410E4C
	.string "{PALETTE 5}POKéMON:$"

gOtherText_SelfIntroduction:: @ 8410E61
	.string "{PALETTE 5}MOTTO:$"

gOtherText_Nature2:: @ 8410E76
	.string "NATUR/$"

gOtherText_InParty:: @ 8410E7E
	.string "IM TEAM$"

gOtherText_Number:: @ 8410E87
	.string "Nr. $"

gOtherText_Ribbons:: @ 8410E8C
	.string "BÄNDER$"

OtherText_MakeProfilePage1::
	.string "Erstelle dein eigenes Profil:$"
OtherText_MakeProfilePage2::
	.string "Kombiniere 4 Wörter/Ausdrücke.$"
OtherText_MakeMessagePage1::
	.string "Verwende 6 Ausdrücke.$"
OtherText_MakeMessagePage2::
	.string "Max. pro Zeile 2-mal 12 Buchstaben$"
OtherText_DescribeFeelingsPage1::
	.string "Finde Worte, die deine momentanen$"
OtherText_DescribeFeelingsPage2::
	.string "Empfindungen beschreiben.$"
OtherText_WithFourPhrases::
	.string "Verwende 4 Ausdrücke und$"
OtherText_CombineNinePhrasesPage1::
	.string "Kombiniere 9 Ausdrücke und$"
OtherText_CombineNinePhrasesPage2::
	.string "erstelle eine Nachricht.$"
OtherText_ImproveBardSongPage1::
	.string "Ändere nur 1 Wort/Ausdruck$"
OtherText_ImproveBardSongPage2::
	.string "und verbessere das BARDEN-Lied.$"
OtherText_YourProfile::
	.string "Dein Profil$"
OtherText_YourFeelingBattle::
	.string "Deine Gefühle zum Kampfbeginn$"
OtherText_SetWinMessage::
	.string "Deine Worte im Fall des Sieges$"
OtherText_SetLossMessage::
	.string "Deine Worte im Fall der Niederlage$"
OtherText_TheAnswer::
	.string "Die Antwort$"
OtherText_MailMessage::
	.string "Der Inhalt des BRIEFES$"
OtherText_MailSalutation::
	.string "Der Gruß des BRIEFES$"
OtherText_NewSong::
	.string "Das neue Lied$"
OtherText_CombineTwoPhrasesPage1::
	.string "Kombiniere 2 Ausdrücke und$"
OtherText_CombineTwoPhrasesPage2::
	.string "schaffe einen hippen Spruch.$"
OtherText_ConfirmTrendyPage1::
	.string "Der hippe Spruch$"
OtherText_ConfirmTrendyPage2::
	.string "lautet also so. O.K.?$"
OtherText_HipsterPage1::
	.string "Kombiniere 2 Ausdrücke und$"
OtherText_HipsterPage2::
	.string "bringe ihr einen guten Spruch bei.$"

gOtherText_TextDeletedConfirmPage1:: @ 84110EE
	.string "Der gesamte verfasste Text wird$"

gOtherText_TextDeletedConfirmPage2:: @ 841110D
	.string "gelöscht. Einverstanden?$"

gOtherText_QuitEditing:: @ 8411127
	.string "Das Textverfassen beenden?$"

gOtherText_EditedTextNoSavePage1:: @ 8411135
	.string "Der Text wird nicht gespeichert.$"

gOtherText_EditedTextNoSavePage2:: @ 8411158
	.string "Ist das in Ordnung?$"

gOtherText_EnterAPhraseOrWord:: @ 8411166
	.string "Bitte Wort/Ausdruck eingeben.$"

gOtherText_TextNoDelete:: @ 8411185
	.string "Gesamter Text ist nicht löschbar.$"

gOtherText_OnlyOnePhrase:: @ 84111A7
	.string "Nur ein Ausdruck ist änderbar.$"

gOtherText_OriginalSongRestored:: @ 84111C7
	.string "Das Lied wird wiederhergestellt.$"

gOtherText_TrendyAlready:: @ 84111EB
	.string "Das ist bereits hip.$"

gOtherText_CombineTwoPhrases:: @ 8411202
	.string "Kombiniere 2 Wörter/Ausdrücke.$"

gOtherText_QuitGivingInfo:: @ 8411220
	.string "Keine weiteren Infos liefern?$"

gOtherText_StopGivingMail:: @ 8411239
	.string "POKéMON keinen BRIEF geben?$"

gOtherText_Profile:: @ 8411257
	.string "PROFIL$"

gOtherText_AtBattleStart:: @ 841125F
	.string "Zum Kampfbeginn$"

gOtherText_UponWinningBattle:: @ 8411276
	.string "Über den Sieg$"

gOtherText_UponLosingBattle:: @ 841128D
	.string "Über die Niederlage$"

gOtherText_TheBardsSong:: @ 84112A3
	.string "Das BARDEN-Lied$"

gOtherText_WhatsHipHappening:: @ 84112B3
	.string "Was ist hip? Was ist top?$"

gOtherText_Interview:: @ 84112CD
	.string "Interview$"

gOtherText_GoodSaying:: @ 84112D7
	.string "Guter Spruch$"

OtherText_SoPretty::
	.string " so hübsch!$"
OtherText_SoDarling::
	.string " so reizend!$"
OtherText_SoRelaxed::
	.string " so lässig!$"
OtherText_SoSunny::
	.string " so überwältigend!$"
OtherText_SoDesirable::
	.string " so erstrebenswert!$"
OtherText_SoExciting::
	.string " so aufregend!$"
OtherText_SoAmusing::
	.string " so amüsant!$"
OtherText_SoMagical::
	.string " so zauberhaft!$"

gOtherText_Is:: @ 841134B
	.string " klingt$"

gOtherText_DontYouAgree:: @ 841134F
	.string "\n"
	.string "Findest du nicht auch?$"

OtherText_WantVacationNicePlace::
	.string "Ich will unbedingt verreisen!\n"
	.string "Kennst du ein hübsches Reiseziel?$"
OtherText_BoughtCrayonsIsNice::
	.string "Ich habe 120 verschiedene Farbstifte\n"
	.string "gekauft! Das ist doch toll, oder?$"
OtherText_IfWeCouldFloat::
	.string "Wäre es nicht herrlich, wir könnten auf\n"
	.string "einer Luftblasenwolke davonschweben?$"
OtherText_SandWashesAwayMakeSad::
	.string "Eine Botschaft in Sand geschrieben\n"
	.string "wird weggespült. Das ist traurig.$"
OtherText_WhatsBottomSeaLike::
	.string "Wie der Meeresgrund wohl ist? Ich\n"
	.string "würde ihn so gerne einmal erleben!$"
OtherText_SeeSettingSun::
	.string "Sehnst du dich beim Anblick der unter-\n"
	.string "gehenden Sonne nach deinem Zuhause?$"
OtherText_LyingInGreenGrass::
	.string "Einfach so im grünen Gras liegen...\n"
	.string "Oh, das ist so was von angenehm!$"
OtherText_SecretBasesWonderful::
	.string "GEHEIMBASEN sind superklasse!\n"
	.string "Findest du das nicht auch aufregend?$"
OtherText_PokeLeague::
	.string "POKéMON LIGA$"
OtherText_PokeCenter::
	.string "POKéMON-CENTER$"

gOtherText_GetsAPokeBlock:: @ 8411581
	.string " erhält einen {POKEBLOCK}?$"

OtherText_Coolness::
	.string "Coolness $"
OtherText_Beauty::
	.string "Schönheit $"
OtherText_Cuteness::
	.string "Anmut $"
OtherText_Smartness::
	.string "Klugheit $"
OtherText_Toughness::
	.string "Stärke $"

gOtherText_WasEnhanced:: @ 84115C2
	.string "wurde erhöht!$"

gOtherText_NothingChanged:: @ 84115D0
	.string "Keine Veränderung eingetreten!$"

gOtherText_WontEat:: @ 84115E1
	.string "Es will nicht mehr essen.$"

gSystemText_SaveFailedBackupCheck:: @ 84115F9
	.string "Speicherfehler\n"
	.string "Backup Memory wird geprüft.\n"
	.string "Bitte warten...\n"
	.string "{COLOR RED}“Benötigte Zeit: 1 Minute”$"

gSystemText_BackupDamagedGameContinue:: @ 841164E
	.string "Backup Memory defekt oder\n"
	.string "interne Batterie verbraucht!\n"
	.string "Spiel kann fortgesetzt werden.\n"
	.string "Weiteres Speichern nicht möglich.$"

gSystemText_GameplayEnded:: @ 84116CB
	.string "{COLOR RED}“Spiel fortsetzen nicht möglich.\n"
	.string "Zurück zum Titelbildschirm...”$"

gSystemText_CheckCompleteSaveAttempt:: @ 841170F
	.string "Überprüfung beendet.\n"
	.string "Neuer Speicherversuch erfolgt.\n"
	.string "Bitte warten...$"

gSystemText_SaveCompletedGameEnd:: @ 8411747
	.string "Speichern beendet.\n"
	.string "{COLOR RED}“Spiel fortsetzen nicht möglich.\n"
	.string "Zurück zum Titelbildschirm.”$"

gSystemText_SaveCompletedPressA:: @ 8411799
	.string "Speichern beendet.\n"
	.string "{COLOR RED}“Bitte A-Knopf drücken.”$"

gOtherText_Ferry:: @ 84117C9
	.string "FÄHRE$"

gOtherText_SecretBase:: @ 84117CF
	.string "GEHEIMBASIS$"

gOtherText_Hideout:: @ 84117DB
	.string "VERSTECK$"

gSystemText_ResetRTCPrompt:: @ 84117E3
	.string "Echtzeituhr zurücksetzen?\n"
	.string "A: Bestätigen, B: Zurück$"

gSystemText_PresentTime:: @ 8411804
	.string "Aktuelle Uhrzeit im Spiel$"

gSystemText_PreviousTime:: @ 8411819
	.string "Vorherige Uhrzeit im Spiel$"

gSystemText_PleaseResetTime:: @ 841182F
	.string "Bitte die Zeit zurückstellen.$"

gSystemText_ClockResetDataSave:: @ 8411846
	.string "Die Uhr wurde zurückgestellt. Daten\n"
	.string "werden gesichert. Bitte warten...$"

gSystemText_SaveCompleted:: @ 8411881
	.string "Speichern beendet.$"

gSystemText_SaveFailed:: @ 8411891
	.string "Speichern fehlgeschlagen.$"

gSystemText_NoSaveFileNoTime:: @ 84118A0
	.string "Es existiert kein Speicherstand. Uhr-\n"
	.string "zeit kann nicht eingestellt werden.$"

gSystemText_ClockAdjustmentUsable:: @ 84118D1
	.string "Das spielinterne Zeiteingabe-\n"
	.string "System ist jetzt verfügbar.$"

gSystemText_Saving:: @ 8411905
	.string "SPEICHERVORGANG...\n"
	.string "GERÄT NICHT AUSSCHALTEN!$"
