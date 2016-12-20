#include "global.h"
#include "menu.h"
#include "task.h"

extern u8 gUnknown_Debug_0839BBA4[];
extern u8 gUnknown_Debug_0839BBB6[];
extern u8 gUnknown_Debug_0839BBC1[];

void debug_sub_8076BB4(u8 taskId);

void debug_sub_8077CF4(u8 x, u8 y);

void debug_sub_8076AC8(u8 arg0) {
    asm(".fill 128");
}

void debug_sub_8076B4C(void) {
    u8 taskId;

    taskId = FindTaskIdByFunc(debug_sub_8076BB4);
    if (taskId != 0xFF) {
        DestroyTask(taskId);
    }
}

void debug_sub_8076B68(void) {
    MenuPrint(gUnknown_Debug_0839BBB6, 1, 1);
    MenuPrint(gUnknown_Debug_0839BBC1, 1, 3);
    MenuPrint(gUnknown_Debug_0839BBA4, 1, 9);
    debug_sub_8077CF4(4, 11);
    debug_sub_8076AC8(0);
    CreateTask(debug_sub_8076BB4, 1);
}

void debug_sub_8076BB4(u8 taskId) {
    asm(".fill 180");
}

void DebugMenu_8076C6C(void) {
    asm(".fill 16");
}

void DebugMenu_8076C80(void) {
    asm(".fill 12");
}

void DebugMenu_8076C90(void) {
    asm(".fill 40");
}

void DebugMenu_8076CBC(void) {
    asm(".fill 0");
}

void DebugMenu_8076CC0(void) {
    asm(".fill 16");
}

void DebugMenu_8076CD4(void) {
    asm(".fill 0");
}

void DebugMenu_8076CD8(void) {
    asm(".fill 16");
}

void DebugMenu_8076CEC(void) {
    asm(".fill 16");
}

void DebugMenu_8076D00(void) {
    asm(".fill 16");
}

void DebugMenu_8076D14(void) {
    asm(".fill 16");
}

void DebugMenu_8076D28(void) {
    asm(".fill 16");
}

void DebugMenu_8076D3C(void) {
    asm(".fill 16");
}

void DebugMenu_8076D50(void) {
    asm(".fill 8");
}

void DebugMenu_8076D5C(void) {
    asm(".fill 12");
}

void DebugMenu_8076D6C(void) {
    asm(".fill 168");
}

void DebugMenu_8076E18(void) {
    asm(".fill 20");
}

void DebugMenu_8076E30(void) {
    asm(".fill 168");
}

void DebugMenu_8076EDC(void) {
    asm(".fill 20");
}

void DebugMenu_8076EF4(void) {
    asm(".fill 104");
}

void DebugMenu_8076F60(void) {
    asm(".fill 136");
}

void DebugMenu_8076FEC(void) {
    asm(".fill 20");
}

void DebugMenu_8077004(void) {
    asm(".fill 24");
}

void DebugMenu_8077020(void) {
    asm(".fill 36");
}

void DebugMenu_8077048(void) {
    asm(".fill 32");
}

void DebugMenu_807706C(void) {
    asm(".fill 44");
}

void DebugMenu_807709C(void) {
    asm(".fill 252");
}

void DebugMenu_807719C(void) {
    asm(".fill 76");
}

void DebugMenu_80771EC(void) {
    asm(".fill 72");
}

void DebugMenu_8077238(void) {
    asm(".fill 284");
}

void DebugMenu_Exit(void) {
    asm(".fill 8");
}

void DebugMenu_OpenSogabe(void) {
    asm(".fill 12");
}

void DebugMenu_OpenTamada(void) {
    asm(".fill 12");
}

void DebugMenu_OpenKagaya(void) {
    asm(".fill 12");
}

void DebugMenu_OpenMatsuda(void) {
    asm(".fill 12");
}

void DebugMenu_OpenNohara(void) {
    asm(".fill 12");
}

void DebugMenu_OpenWatanabe(void) {
    asm(".fill 24");
}

void DebugMenu_EndSequenceDemo(void) {
    asm(".fill 24");
}

void DebugMenu_HallOfFame(void) {
    asm(".fill 16");
}

void DebugMenu_OpenSizeComparison(void) {
    asm(".fill 16");
}

void DebugMenu_HoennNationalDex(void) {
    asm(".fill 28");
}

void DebugMenu_8077434(void) {
    asm(".fill 212");
}

void DebugMenu_807750C(void) {
    asm(".fill 16");
}

void DebugMenu_SetRamBerry(void) {
    asm(".fill 32");
}

void DebugMenu_ToggleBGM(void) {
    asm(".fill 28");
}

void DebugMenu_BattleForDebug(void) {
    asm(".fill 16");
}

void DebugMenu_NationalDex(void) {
    asm(".fill 56");
}

void DebugMenu_HoennDex(void) {
    asm(".fill 60");
}

void DebugMenu_CreatePKMN(void) {
    asm(".fill 16");
}

void DebugMenu_ViewPokemonGraphics(void) {
    asm(".fill 16");
}

void DebugMenu_OpenSeeTrainers(void) {
    asm(".fill 16");
}

void DebugMenu_OpenMori(void) {
    asm(".fill 12");
}

void DebugMenu_OpenTomomichi(void) {
    asm(".fill 12");
}

void DebugMenu_OpenAoki(void) {
    asm(".fill 8");
}

void DebugMenu_OpenTaya(void) {
    asm(".fill 12");
}

void DebugMenu_OpenNakamura(void) {
    asm(".fill 12");
}

void DebugMenu_OpenIwasawa(void) {
    asm(".fill 12");
}

void DebugMenu_Teleport(void) {
    asm(".fill 20");
}

void DebugMenu_EditPKMN(void) {
    asm(".fill 12");
}

void DebugMenu_80776B4(void) {
    asm(".fill 76");
}

void DebugMenu_8077704(void) {
    asm(".fill 88");
}

void DebugMenu_8077760(void) {
    asm(".fill 208");
}

void DebugMenu_SwitchBG(void) {
    asm(".fill 52");
}

void DebugMenu_807786C(void) {
    asm(".fill 56");
}

void DebugMenu_80778A8(void) {
    asm(".fill 76");
}

void DebugMenu_ControlEncounter(void) {
    asm(".fill 36");
}

void DebugMenu_UseHM(void) {
    asm(".fill 16");
}

void DebugMenu_8077934(void) {
    asm(".fill 4");
}

void DebugMenu_807793C(void) {
    asm(".fill 20");
}

void DebugMenu_8077954(void) {
    asm(".fill 28");
}

void DebugMenu_8077974(void) {
    asm(".fill 168");
}

void DebugMenu_8077A20(void) {
    asm(".fill 28");
}

void DebugMenu_8077A40(void) {
    asm(".fill 28");
}

void DebugMenu_8077A60(void) {
    asm(".fill 16");
}

void DebugMenu_RematchTrainers(void) {
    asm(".fill 36");
}

void DebugMenu_8077A9C(void) {
    asm(".fill 20");
}

void DebugMenu_8077AB4(void) {
    asm(".fill 20");
}

void DebugMenu_8077ACC(void) {
    asm(".fill 24");
}

void DebugMenu_8077AE8(void) {
    asm(".fill 20");
}

void DebugMenu_8077B00(void) {
    asm(".fill 56");
}

void DebugMenu_8077B3C(void) {
    asm(".fill 16");
}

void DebugMenu_Safari(void) {
    asm(".fill 96");
}

void DebugMenu_8077BB4(void) {
    asm(".fill 8");
}

void DebugMenu_8077BC0(void) {
    asm(".fill 8");
}

void DebugMenu_8077BCC(void) {
    asm(".fill 8");
}

void DebugMenu_8077BD8(void) {
    asm(".fill 8");
}

void DebugMenu_8077BE4(void) {
    asm(".fill 12");
}

void DebugMenu_8077BF4(void) {
    asm(".fill 8");
}

void DebugMenu_8077C00(void) {
    asm(".fill 16");
}

void DebugMenu_8077C14(void) {
    asm(".fill 36");
}

void DebugMenu_8077C3C(void) {
    asm(".fill 180");
}

void debug_sub_8077CF4(u8 x, u8 y) {
    asm(".fill 44");
}

void DebugMenu_8077D24(void) {
    asm(".fill 80");
}

void DebugMenu_8077D78(void) {
    asm(".fill 56");
}

void DebugMenu_8077DB4(void) {
    asm(".fill 32");
}

void DebugMenu_8077DD8(void) {
    asm(".fill 100");
}

void DebugMenu_8077E40(void) {
    asm(".fill 84");
}

void DebugMenu_MakeItems(void) {
    asm(".fill 16");
}

void DebugMenu_8077EAC(void) {
    asm(".fill 48");
}

void DebugMenu_8077EE0(void) {
    asm(".fill 92");
}

void DebugMenu_8077F40(void) {
    asm(".fill 56");
}

void DebugMenu_8077F7C(void) {
    asm(".fill 124");
}

void DebugMenu_8077FFC(void) {
    asm(".fill 108");
}

void DebugMenu_807806C(void) {
    asm(".fill 28");
}

void DebugMenu_807808C(void) {
    asm(".fill 236");
}

void DebugMenu_807817C(void) {
    asm(".fill 40");
}

void DebugMenu_80781A8(void) {
    asm(".fill 140");
}

void DebugMenu_ViewPortraits(void) {
    asm(".fill 24");
}

void DebugMenu_8078254(void) {
    asm(".fill 8");
}

void DebugMenu_AllBadges(void) {
    asm(".fill 88");
}

void DebugMenu_TimeRecords(void) {
    asm(".fill 24");
}

void DebugMenu_SetTime(void) {
    asm(".fill 16");
}

void DebugMenu_80782EC(void) {
    asm(".fill 32");
}

void DebugMenu_8078310(void) {
    asm(".fill 152");
}

void DebugMenu_MiragaIslandRND(void) {
    asm(".fill 24");
}

void DebugMenu_80783C8(void) {
    asm(".fill 104");
}

void DebugMenu_ToggleClearFlag(void) {
    asm(".fill 44");
}

void DebugMenu_8078464(void) {
    asm(".fill 76");
}

void DebugMenu_OpenWeatherEvents(void) {
    asm(".fill 48");
}

void DebugMenu_80784E8(void) {
    asm(".fill 56");
}

void DebugMenu_OpenMysteryEvent(void) {
    asm(".fill 40");
}

void DebugMenu_8078550(void) {
    asm(".fill 184");
}

void DebugMenu_807860C(void) {
    asm(".fill 176");
}

void DebugMenu_80786C0(void) {
    asm(".fill 12");
}

void DebugMenu_80786D0(void) {
    asm(".fill 64");
}

void DebugMenu_8078714(void) {
    asm(".fill 64");
}

void DebugMenu_8078758(void) {
    asm(".fill 24");
}

void DebugMenu_8078774(void) {
    asm(".fill 16");
}

void DebugMenu_8078788(void) {
    asm(".fill 16");
}

void DebugMenu_807879C(void) {
    asm(".fill 16");
}

void DebugMenu_80787B0(void) {
    asm(".fill 16");
}

void DebugMenu_OpenLegendsRecord(void) {
    asm(".fill 36");
}

void DebugMenu_80787EC(void) {
    asm(".fill 144");
}

void DebugMenu_8078880(void) {
    asm(".fill 108");
}

void DebugMenu_CellInfo(void) {
    asm(".fill 28");
}

void DebugMenu_OpenBerryInfo(void) {
    asm(".fill 60");
}

void DebugMenu_8078950(void) {
    asm(".fill 20");
}

void DebugMenu_8078968(void) {
    asm(".fill 56");
}

void DebugMenu_80789A4(void) {
    asm(".fill 36");
}

void DebugMenu_80789CC(void) {
    asm(".fill 68");
}

void DebugMenu_8078A14(void) {
    asm(".fill 140");
}

void DebugMenu_8078AA4(void) {
    asm(".fill 144");
}

void DebugMenu_8078B38(void) {
    asm(".fill 24");
}

void DebugMenu_BattleTowerStages(void) {
    asm(".fill 24");
}

void DebugMenu_8078B70(void) {
    asm(".fill 32");
}

void DebugMenu_8078B94(void) {
    asm(".fill 60");
}

void DebugMenu_8078BD4(void) {
    asm(".fill 140");
}

void DebugMenu_CheckPKBLCK(void) {
    asm(".fill 24");
}

void DebugMenu_8078C80(void) {
    asm(".fill 36");
}

void DebugMenu_8078CA8(void) {
    asm(".fill 56");
}

void DebugMenu_8078CE4(void) {
    asm(".fill 72");
}

void DebugMenu_8078D30(void) {
    asm(".fill 72");
}

void DebugMenu_8078D7C(void) {
    asm(".fill 36");
}

void DebugMenu_8078DA4(void) {
    asm(".fill 32");
}

void DebugMenu_MeTooBackupMan(void) {
    asm(".fill 36");
}

void DebugMenu_8078DF0(void) {
    asm(".fill 16");
}

void DebugMenu_8078E04(void) {
    asm(".fill 56");
}

void DebugMenu_8078E40(void) {
    asm(".fill 36");
}

void DebugMenu_8078E68(void) {
    asm(".fill 20");
}

void DebugMenu_8078E80(void) {
    asm(".fill 44");
}

void DebugMenu_8078EB0(void) {
    asm(".fill 104");
}

void DebugMenu_8078F1C(void) {
    asm(".fill 72");
}

void DebugMenu_8078F68(void) {
    asm(".fill 180");
}

void DebugMenu_8079020(void) {
    asm(".fill 24");
}

void DebugMenu_PTime(void) {
    asm(".fill 24");
}

void DebugMenu_8079058(void) {
    asm(".fill 152");
}

void DebugMenu_OpenMurakawa(void) {
    asm(".fill 24");
}

void DebugMenu_8079110(void) {
    asm(".fill 120");
}

void DebugMenu_OpenKiwa(void) {
    asm(".fill 24");
}
