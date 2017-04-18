#include "global.h"
#include "../include/menu.h"
#include "../include/global.h"

extern const u8 gOtherText_BattleResults[];
extern const u8 gOtherText_WinLoseDraw[];

void PrintLinkBattleWinsLossesDraws(void *);
void PrintLinkBattleRecord(void *, u8);

void ShowLinkBattleRecords(void) {
    s32 i;
    MenuDrawTextWindow(1, 0, 28, 18);
    sub_8072BD8((u8 *) gOtherText_BattleResults, 0, 1, 240);

    PrintLinkBattleWinsLossesDraws(gSaveBlock1.filler_30B8);
    MenuPrint(gOtherText_WinLoseDraw, 12, 6);

    for (i = 0; i < 5; i++)
    {
        PrintLinkBattleRecord(&gSaveBlock1.filler_30B8[i * 16], (i + 1) * 2 + 6);
    }
}
