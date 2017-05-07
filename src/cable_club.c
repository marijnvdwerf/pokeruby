#include "global.h"
#include "asm.h"
#include "field_message_box.h"
#include "link.h"
#include "main.h"
#include "script.h"
#include "string_util.h"
#include "task.h"
#include "text.h"
#include "trainer_card.h"

extern const u8 gUnknown_081A4975[];
extern struct TrainerCard gTrainerCards[4];
extern u16 gBlockRecvBuffer[MAX_LINK_PLAYERS][BLOCK_BUFFER_SIZE / 2];
extern u16 gScriptResult;

void sub_808303C(u8 taskId) {
    s32 linkPlayerCount;
    s16 *taskData;

    taskData = gTasks[taskId].data;

    linkPlayerCount = GetLinkPlayerCount_2();

    if (sub_8082E28(taskId) == 1)
    {
        return;
    }

    if (sub_8082EB8(taskId) == 1)
    {
        return;
    }

    if (sub_8082DF4(taskId) == 1)
    {
        return;
    }

    sub_8082D60(taskId, linkPlayerCount); // r6

    if (!(gMain.newKeys & A_BUTTON))
    {
        return;
    }

    if (linkPlayerCount < taskData[1] ) // r5
    {
        return;
    }


    sub_80081C8(linkPlayerCount); // r6
    sub_8082D4C();
    ConvertIntToDecimalStringN(gStringVar1, linkPlayerCount, STR_CONV_MODE_LEFT_ALIGN, 1); // r5
    ShowFieldAutoScrollMessage((u8 *) gUnknown_081A4975);
    gTasks[taskId].func = sub_80830E4;
}

asm(".section .text_b");

void sub_8083314(u8 taskId) {
    u8 index;

    struct TrainerCard *trainerCards;


    if (sub_8082DF4(taskId) == 1)
    {
        return;
    }

    if (GetBlockReceivedStatus() != sub_8008198())
    {
        return;
    }

    index = 0;
    trainerCards = gTrainerCards;
    for (index = 0; index < GetLinkPlayerCount(); index++)
    {
        void *src;
        src = gBlockRecvBuffer[index];
        memcpy(&trainerCards[index], src, sizeof(struct TrainerCard));
    }

    SetSuppressLinkErrorMessage(FALSE);
    ResetBlockReceivedFlags();
    HideFieldMessageBox();

    if (gScriptResult == 1)
    {
        u16 linkType;
        linkType = gLinkType;
        sub_8082D4C(0x00004411, linkType);
        EnableBothScriptContexts();
        DestroyTask(taskId);
        return;
    }

    sub_800832C();
    gTasks[taskId].func = sub_80833C4;
}
