#include "global.h"
#include "event_data.h"
#include "menu.h"
#include "palette.h"
#include "script.h"
#include "sound.h"
#include "sprite.h"
#include "task.h"

struct MultichoiceListStruct
{
    struct MenuAction *list;
    u8 count;
};

extern const struct MultichoiceListStruct gMultichoiceLists[];

extern u16 gScriptResult;

extern void FreeResourcesAndDestroySprite(struct Sprite *sprite);
extern u8 CreateMonSprite_PicBox(u16, s16, s16, u8);
extern u8 sub_80B59AC(void);

extern u8 gPCText_PlayersPC[];
extern u8 gPCText_SomeonesPC[];
extern u8 gPCText_HallOfFame[];
extern u8 gPCText_LogOff[];
extern u8 gPCText_LanettesPC[];
extern u8 gPCText_WhichPCShouldBeAccessed[];

void DrawMultichoiceMenu(u8, u8, u8, struct MenuAction *list, u8, u8);
void sub_80B53B4(u8, u8, u8, struct MenuAction *list, u8);
void sub_80B52B4(u8);
void sub_80B5230(u8, u8, u8, u8, u8, u8);
void task_yes_no_maybe(u8);
void sub_80B5684(u8);
void CreatePCMenu(void);

bool8 sub_80B5054(u8 left, u8 top, u8 var3, u8 var4)
{
    if(FuncIsActiveTask(sub_80B52B4) == 1)
        return FALSE;
    else
    {
        gScriptResult = 0xFF;
        DrawMultichoiceMenu(left, top, gMultichoiceLists[var3].count, gMultichoiceLists[var3].list, var4, 0);
        return TRUE;
    }
}

bool8 sub_80B50B0(u8 left, u8 top, u8 var3, u8 var4, u8 var5)
{
    if(FuncIsActiveTask(sub_80B52B4) == 1)
        return FALSE;
    else
    {
        gScriptResult = 0xFF;
        DrawMultichoiceMenu(left, top, gMultichoiceLists[var3].count, gMultichoiceLists[var3].list, var4, var5);
        return TRUE;
    }
}

u16 GetStringWidthInTilesForScriptMenu(u8 *str)
{
    // each tile on screen is 8x8, so it needs the number of tiles and not pixels, hence the division by 8.
    return (GetStringWidthGivenWindowConfig((struct WindowConfig *)&gWindowConfig_81E6CE4, str) + 7) / 8;
}

void DrawMultichoiceMenu(u8 left, u8 top, u8 count, struct MenuAction *list, u8 var4, u8 cursorPos)
{
    u16 width = GetStringWidthInTilesForScriptMenu(list[0].text);
    u16 newWidth;
    u8 i;
    u8 right;
    u8 bottom;

    for(i = 1; i < count; i++)
    {
        newWidth = GetStringWidthInTilesForScriptMenu(list[i].text);
        if(width < newWidth)
            width = newWidth;
    }

    right = width;
    right = (right + left) + 1;

    if(right > 29)
    {
        left = left + (29 - right);
        right = 29;
    }

    bottom = top + (2 * count + 1);

    MenuDrawTextWindow(left, top, right, bottom);
    PrintMenuItems(left + 1, top + 1, count, list);
    InitMenu(0, left + 1, top + 1, count, cursorPos, right - left - 1);
    sub_80B5230(left, top, right, bottom, var4, count);
}

void sub_80B5230(u8 left, u8 top, u8 right, u8 bottom, u8 unkVar, u8 count)
{
    u8 taskId = CreateTask(sub_80B52B4, 80);

    gTasks[taskId].data[0] = left;
    gTasks[taskId].data[1] = top;
    gTasks[taskId].data[2] = right;
    gTasks[taskId].data[3] = bottom;
    gTasks[taskId].data[4] = unkVar;

    if(count > 3)
        gTasks[taskId].data[5] = TRUE;
    else
        gTasks[taskId].data[5] = FALSE;
}

void sub_80B52B4(u8 taskId)
{
    s8 var;

    if(!gPaletteFade.active)
    {
        if(!gTasks[taskId].data[5])
            var = ProcessMenuInputNoWrap();
        else
            var = ProcessMenuInput();

        if(var != -2)
        {
            if(var == -1)
            {
                if(!gTasks[taskId].data[4])
                {
                    PlaySE(5);
                    gScriptResult = 127;
                }
                else
                {
                    return;
                }
            }
            else
            {
                gScriptResult = var;
            }
            sub_8072DEC();
            MenuZeroFillWindowRect(gTasks[taskId].data[0], gTasks[taskId].data[1], gTasks[taskId].data[2], gTasks[taskId].data[3]);
            DestroyTask(taskId);
            EnableBothScriptContexts();
        }
    }
}

bool8 Multichoice(u8 var1, u8 var2, u8 var3, u8 var4)
{
    if(FuncIsActiveTask(sub_80B52B4) == 1)
        return FALSE;
    else
    {
        gScriptResult = 0xFF;
        sub_80B53B4(var1, var2, gMultichoiceLists[var3].count, gMultichoiceLists[var3].list, var4);
        return TRUE;
    }
}

void sub_80B53B4(u8 left, u8 top, u8 count, struct MenuAction *list, u8 var4)
{
    u16 width = GetStringWidthInTilesForScriptMenu(list[0].text);
    u16 newWidth;
    u8 i;
    u8 right;
    u8 bottom;

    for(i = 1; i < count; i++)
    {
        newWidth = GetStringWidthInTilesForScriptMenu(list[i].text);
        if(width < newWidth)
            width = newWidth;
    }

    right = width;
    right = (right + left) + 2;
    bottom = top + (2 * count + 1);

    PrintMenuItems(left, top, count, list);
    InitMenu(0, left, top, count, 0, right - left - 1);
    sub_80B5230(left, top, right, bottom, var4, count);
}

bool8 yes_no_box(u8 var1, u8 var2)
{
    u8 taskId;

    if(FuncIsActiveTask(task_yes_no_maybe) == 1)
        return FALSE;
    else
    {
        gScriptResult = 0xFF;
        DisplayYesNoMenu(var1, var2, 1);
        taskId = CreateTask(task_yes_no_maybe, 0x50);
        gTasks[taskId].data[0] = var1;
        gTasks[taskId].data[1] = var2;
        return TRUE;
    }
}

// unused
bool8 IsScriptActive(void)
{
    if(gScriptResult == 0xFF)
        return FALSE;
    else
        return TRUE;
}

void task_yes_no_maybe(u8 taskId)
{
    u8 left, top;

    if (gTasks[taskId].data[2] < 5)
    {
        gTasks[taskId].data[2]++;
        return;
    }

    switch (ProcessMenuInputNoWrap())
    {
    case -2:
        return;
    case -1:
    case 1:
        PlaySE(5);
        gScriptResult = 0;
        break;
    case 0:
        gScriptResult = 1;
        break;
    }

    left = gTasks[taskId].data[0];
    top = gTasks[taskId].data[1];

    MenuZeroFillWindowRect(left, top, left + 6, top + 5);
    DestroyTask(taskId);
    EnableBothScriptContexts();
}

bool8 sub_80B5578(u8 left, u8 top, u8 multichoiceId, u8 a4, u8 columnCount)
{
    u8 bottom = 0;

    if (FuncIsActiveTask(sub_80B5684) == TRUE)
    {
        return FALSE;
    }
    else
    {
        u8 taskId;
        u8 width;

        gScriptResult = 0xFF;

        sub_807274C(left, top, gMultichoiceLists[multichoiceId].count, 0, gMultichoiceLists[multichoiceId].list, columnCount, 0);

        taskId = CreateTask(sub_80B5684, 80);

        if (!((gMultichoiceLists[multichoiceId].count >> 1) < columnCount || (gMultichoiceLists[multichoiceId].count & 1))
         || columnCount == 1 || gMultichoiceLists[multichoiceId].count == columnCount)
        {
            bottom = (2 * (gMultichoiceLists[multichoiceId].count / columnCount)) + 1 + top;
        }
        else
        {
            bottom = (2 * (gMultichoiceLists[multichoiceId].count / columnCount)) + 3 + top;
        }

        width = sub_807288C(columnCount);
        gTasks[taskId].data[0] = left;
        gTasks[taskId].data[1] = top;
        gTasks[taskId].data[2] = width + left + 2;
        gTasks[taskId].data[3] = bottom;
        gTasks[taskId].data[4] = a4;
        return TRUE;
    }
}

void sub_80B5684(u8 taskId)
{
    s8 var = sub_80727CC();

    if (var != -2)
    {
        if (var == -1)
        {
            if (!gTasks[taskId].data[4])
            {
                PlaySE(5);
                gScriptResult = 127;
            }
            else
            {
                return;
            }
        }
        else
        {
            gScriptResult = var;
        }
        sub_8072DEC();
        MenuZeroFillWindowRect(gTasks[taskId].data[0], gTasks[taskId].data[1], gTasks[taskId].data[2], gTasks[taskId].data[3]);
        DestroyTask(taskId);
        EnableBothScriptContexts();
    }
}

bool8 TryCreatePCMenu(void)
{
    if(FuncIsActiveTask(sub_80B52B4) == 1)
        return FALSE;
    else
    {
        gScriptResult = 0xFF;
        CreatePCMenu();
        return TRUE;
    }
}

#ifdef NONMATCHING
void CreatePCMenu(void)
{
    u16 playersPCWidth = GetStringWidthInTilesForScriptMenu(gPCText_PlayersPC);
    u8 width;
    u8 numChoices;

    if(playersPCWidth > GetStringWidthInTilesForScriptMenu(gPCText_SomeonesPC))
        width = playersPCWidth;
    else
        width = 8;

    if(FlagGet(SYS_GAME_CLEAR)) // player has cleared game?
    {
        numChoices = 4;
        MenuDrawTextWindow(0, 0, width + 2, 9);
        MenuPrint(gPCText_HallOfFame, 1, 5);
        MenuPrint(gPCText_LogOff, 1, 7);
    }
    else
    {
        numChoices = 3;
        MenuDrawTextWindow(0, 0, width + 2, 7);
        MenuPrint(gPCText_LogOff, 1, 5);
    }

    if(FlagGet(SYS_PC_LANETTE)) // player met lanette?
        MenuPrint(gPCText_LanettesPC, 1, 1);
    else
        MenuPrint(gPCText_SomeonesPC, 1, 1);

    MenuPrint(gPCText_PlayersPC, 1, 3);
    InitMenu(0, 1, 1, numChoices, 0, width + 1);
    sub_80B5230(0, 0, width + 2, 2 * numChoices + 1, 0, numChoices);
}
#else
__attribute__((naked))
void CreatePCMenu(void) {
    asm(".syntax unified\n\
	push {r4-r7,lr}\n\
	sub sp, 0x18\n\
	ldr r0, _080B5748 @ =0x0000084b\n\
	bl FlagGet\n\
	lsls r0, 24\n\
	cmp r0, 0\n\
	beq _080B5750\n\
	ldr r0, _080B574C @ =gPCText_LanettesPC\n\
	b _080B5752\n\
	.align 2, 0\n\
_080B5748: .4byte 0x0000084b\n\
_080B574C: .4byte gPCText_LanettesPC\n\
_080B5750:\n\
	ldr r0, _080B57E8 @ =gPCText_SomeonesPC\n\
_080B5752:\n\
	bl GetStringWidthInTilesForScriptMenu\n\
	lsls r0, 16\n\
	lsrs r0, 16\n\
	str r0, [sp, 0x8]\n\
	movs r4, 0x1\n\
	ldr r0, _080B57EC @ =gPCText_PlayersPC\n\
	bl GetStringWidthInTilesForScriptMenu\n\
	lsls r1, r4, 2\n\
	add r1, sp\n\
	adds r1, 0x8\n\
	lsls r0, 16\n\
	lsrs r0, 16\n\
	str r0, [r1]\n\
	ldr r0, _080B57F0 @ =gPCText_LogOff\n\
	bl GetStringWidthInTilesForScriptMenu\n\
	lsls r0, 16\n\
	lsrs r0, 16\n\
	str r0, [sp, 0x10]\n\
	movs r4, 0x3\n\
	ldr r0, _080B57F4 @ =0x00000804\n\
	bl FlagGet\n\
	lsls r0, 24\n\
	cmp r0, 0\n\
	beq _080B5798\n\
	ldr r0, _080B57F8 @ =gPCText_HallOfFame\n\
	bl GetStringWidthInTilesForScriptMenu\n\
	lsls r0, 16\n\
	lsrs r0, 16\n\
	str r0, [sp, 0x14]\n\
	movs r4, 0x4\n\
_080B5798:\n\
	movs r5, 0\n\
	cmp r5, r4\n\
	bge _080B57B4\n\
	add r2, sp, 0x8\n\
	adds r1, r4, 0\n\
_080B57A2:\n\
	ldr r0, [r2]\n\
	cmp r5, r0\n\
	bge _080B57AC\n\
	lsls r0, 24\n\
	lsrs r5, r0, 24\n\
_080B57AC:\n\
	adds r2, 0x4\n\
	subs r1, 0x1\n\
	cmp r1, 0\n\
	bne _080B57A2\n\
_080B57B4:\n\
	ldr r0, _080B57F4 @ =0x00000804\n\
	bl FlagGet\n\
	lsls r0, 24\n\
	cmp r0, 0\n\
	beq _080B57FC\n\
	movs r7, 0x4\n\
	adds r4, r5, 0x2\n\
	lsls r2, r4, 24\n\
	lsrs r2, 24\n\
	movs r0, 0\n\
	movs r1, 0\n\
	movs r3, 0x9\n\
	bl MenuDrawTextWindow\n\
	ldr r0, _080B57F8 @ =gPCText_HallOfFame\n\
	movs r1, 0x1\n\
	movs r2, 0x5\n\
	bl MenuPrint\n\
	ldr r0, _080B57F0 @ =gPCText_LogOff\n\
	movs r1, 0x1\n\
	movs r2, 0x7\n\
	bl MenuPrint\n\
	b _080B5818\n\
	.align 2, 0\n\
_080B57E8: .4byte gPCText_SomeonesPC\n\
_080B57EC: .4byte gPCText_PlayersPC\n\
_080B57F0: .4byte gPCText_LogOff\n\
_080B57F4: .4byte 0x00000804\n\
_080B57F8: .4byte gPCText_HallOfFame\n\
_080B57FC:\n\
	movs r7, 0x3\n\
	adds r4, r5, 0x2\n\
	lsls r2, r4, 24\n\
	lsrs r2, 24\n\
	movs r0, 0\n\
	movs r1, 0\n\
	movs r3, 0x7\n\
	bl MenuDrawTextWindow\n\
	ldr r0, _080B5834 @ =gPCText_LogOff\n\
	movs r1, 0x1\n\
	movs r2, 0x5\n\
	bl MenuPrint\n\
_080B5818:\n\
	adds r6, r4, 0\n\
	ldr r0, _080B5838 @ =0x0000084b\n\
	bl FlagGet\n\
	lsls r0, 24\n\
	cmp r0, 0\n\
	beq _080B5840\n\
	ldr r0, _080B583C @ =gPCText_LanettesPC\n\
	movs r1, 0x1\n\
	movs r2, 0x1\n\
	bl MenuPrint\n\
	b _080B584A\n\
	.align 2, 0\n\
_080B5834: .4byte gPCText_LogOff\n\
_080B5838: .4byte 0x0000084b\n\
_080B583C: .4byte gPCText_LanettesPC\n\
_080B5840:\n\
	ldr r0, _080B5888 @ =gPCText_SomeonesPC\n\
	movs r1, 0x1\n\
	movs r2, 0x1\n\
	bl MenuPrint\n\
_080B584A:\n\
	ldr r0, _080B588C @ =gPCText_PlayersPC\n\
	movs r1, 0x1\n\
	movs r2, 0x3\n\
	bl MenuPrint\n\
	movs r4, 0\n\
	str r4, [sp]\n\
	adds r0, r5, 0x1\n\
	lsls r0, 24\n\
	lsrs r0, 24\n\
	str r0, [sp, 0x4]\n\
	movs r0, 0\n\
	movs r1, 0x1\n\
	movs r2, 0x1\n\
	adds r3, r7, 0\n\
	bl InitMenu\n\
	lsls r2, r6, 24\n\
	lsrs r2, 24\n\
	lsls r3, r7, 1\n\
	adds r3, 0x1\n\
	str r4, [sp]\n\
	str r7, [sp, 0x4]\n\
	movs r0, 0\n\
	movs r1, 0\n\
	bl sub_80B5230\n\
	add sp, 0x18\n\
	pop {r4-r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080B5888: .4byte gPCText_SomeonesPC\n\
_080B588C: .4byte gPCText_PlayersPC\n\
    .syntax divided\n");
}
#endif

void sub_80B5838(void)
{
    MenuDisplayMessageBox();
    MenuPrint(gPCText_WhichPCShouldBeAccessed, 2, 15);
}

void task_picbox(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch(task->data[0])
    {
        case 0:
            task->data[0]++;
            break;
        case 1:
            break;
        case 2:
            FreeResourcesAndDestroySprite(&gSprites[task->data[2]]);
            task->data[0]++;
            break;
        case 3:
            MenuZeroFillWindowRect(task->data[3], task->data[4], task->data[3] + 9, task->data[4] + 10);
            DestroyTask(taskId);
            break;
    }
}

bool8 sub_80B58C4(u16 var1, u8 var2, u8 var3)
{
    u8 taskId;
    u8 var;

    if(FindTaskIdByFunc(task_picbox) != 0xFF)
        return FALSE;
    else
    {
        MenuDrawTextWindow(var2, var3, var2 + 9, var3 + 10);
        taskId = CreateTask(task_picbox, 0x50);
        gTasks[taskId].data[0] = 0;
        gTasks[taskId].data[1] = var1;
        var = CreateMonSprite_PicBox(var1, var2 * 8 + 40, var3 * 8 + 40, 0);
        gTasks[taskId].data[2] = var;
        gTasks[taskId].data[3] = var2;
        gTasks[taskId].data[4] = var3;
        gSprites[var].callback = SpriteCallbackDummy;
        gSprites[var].oam.priority = 0;
        return TRUE;
    }
}

void *picbox_close(void)
{
    u8 taskId = FindTaskIdByFunc(task_picbox);

    if(taskId == 0xFF)
        return NULL;

    gTasks[taskId].data[0]++;
    return (void *)sub_80B59AC;
}

bool8 sub_80B59AC(void)
{
    if(FindTaskIdByFunc(task_picbox) == 0xFF)
        return TRUE;
    else
        return FALSE;
}
