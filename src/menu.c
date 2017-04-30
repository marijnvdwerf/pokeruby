#include "global.h"
#include "menu.h"
#include "main.h"
#include "map_obj_lock.h"
#include "menu_cursor.h"
#include "script.h"
#include "songs.h"
#include "sound.h"
#include "text.h"
#include "text_window.h"
#include "string_util.h"

struct Menu
{
    u8 left;
    u8 top;
    s8 cursorPos;
    s8 minCursorPos;
    s8 maxCursorPos;
    u8 width;
    u8 height;
    u8 menu_field_7;
    u8 columnXCoords[8];
};

extern u8 OtherText_Yes[];
extern u8 OtherText_No[];

static void MultistepInitMenuWindowInternal(const struct WindowConfig *, u16);
static void InitMenuWindowInternal(const struct WindowConfig *, u16);
static bool8 sub_80723D4(void);
static u8 sub_8072484(u8, u8, u8, u8, u8, u8, u32);
static u8 sub_80724F4(u8, u8, u8, const struct MenuAction[], u8);
static void sub_8072620(u8, u8, u8, const struct MenuAction[], u8);
static void sub_8072D18(u8, u8);

static struct Menu gMenu;

EWRAM_DATA struct Window gMenuWindow = {0};
EWRAM_DATA u8 gFiller_202E908[0x90] = {0};
EWRAM_DATA struct Window *gMenuWindowPtr = NULL;
EWRAM_DATA u8 gMenuMultistepInitState = 0;
EWRAM_DATA u16 gMenuTextTileOffset = 0;
EWRAM_DATA u16 gMenuTextWindowTileOffset = 0;
EWRAM_DATA u16 gMenuTextWindowContentTileOffset = 0;
EWRAM_DATA u16 gMenuMessageBoxContentTileOffset = 0;

const struct MenuAction gMenuYesNoItems[] =
{
    { OtherText_Yes, NULL },
    { OtherText_No, NULL },
};

void CloseMenu(void)
{
    PlaySE(SE_SELECT);
    MenuZeroFillScreen();
    sub_8064E2C();
    ScriptContext2_Disable();
    sub_8072DEC();
}

void AppendToList(u8 *list, u8 *pindex, u32 value)
{
    list[*pindex] = value;
    (*pindex)++;
}

void InitMenuWindow(const struct WindowConfig *winConfig)
{
    InitMenuWindowInternal(winConfig, 1);
}

void MultistepInitMenuWindowBegin(const struct WindowConfig *winConfig)
{
    MultistepInitMenuWindowInternal(winConfig, 1);
}

static void MultistepInitMenuWindowInternal(const struct WindowConfig *winConfig, u16 tileOffset)
{
    gMenuMultistepInitState = 0;
    gMenuTextTileOffset = tileOffset;
    gMenuWindowPtr = &gMenuWindow;
    InitWindowFromConfig(&gMenuWindow, winConfig);
}

bool32 MultistepInitMenuWindowContinue(void)
{
    switch (gMenuMultistepInitState)
    {
    case 0:
        gMenuMultistepInitState++;
        return 0;
    case 1:
        gMenuTextWindowTileOffset = MultistepInitWindowTileData(gMenuWindowPtr, gMenuTextTileOffset);
        goto next;
    case 2:
        if (!MultistepLoadFont())
            goto fail;
        goto next;
    case 3:
        gMenuTextWindowContentTileOffset = SetTextWindowBaseTileNum(gMenuTextWindowTileOffset);
    next:
        gMenuMultistepInitState++;
        return 0;
    case 4:
        LoadTextWindowGraphics(gMenuWindowPtr);
        gMenuMessageBoxContentTileOffset = SetMessageBoxBaseTileNum(gMenuTextWindowContentTileOffset);
        return 1;
    default:
    fail:
        return 0;
    }
}

static void InitMenuWindowInternal(const struct WindowConfig *winConfig, u16 tileOffset)
{
    gMenuWindowPtr = &gMenuWindow;
    InitWindowFromConfig(&gMenuWindow, winConfig);
    gMenuTextTileOffset = tileOffset;
    gMenuTextWindowTileOffset = InitWindowTileData(gMenuWindowPtr, gMenuTextTileOffset);
    gMenuTextWindowContentTileOffset = SetTextWindowBaseTileNum(gMenuTextWindowTileOffset);
    LoadTextWindowGraphics(gMenuWindowPtr);
    gMenuMessageBoxContentTileOffset = SetMessageBoxBaseTileNum(gMenuTextWindowContentTileOffset);
}

void unref_sub_8071DA4(struct WindowConfig *winConfig, u16 tileOffset)
{
    gMenuWindowPtr = &gMenuWindow;
    InitWindowFromConfig(&gMenuWindow, winConfig);
    gMenuTextWindowTileOffset = tileOffset;
    gMenuTextWindowContentTileOffset = SetTextWindowBaseTileNum(gMenuTextWindowTileOffset);
    LoadTextWindowGraphics(gMenuWindowPtr);
    gMenuTextTileOffset = SetMessageBoxBaseTileNum(gMenuTextWindowContentTileOffset);
    gMenuMessageBoxContentTileOffset = InitWindowTileData(gMenuWindowPtr, gMenuTextTileOffset);
}

void MenuLoadTextWindowGraphics_OverrideFrameType(u8 frameType)
{
    LoadTextWindowGraphics_OverrideFrameType(gMenuWindowPtr, frameType);
}

void MenuLoadTextWindowGraphics(void)
{
    LoadTextWindowGraphics(gMenuWindowPtr);
}

void BasicInitMenuWindow(const struct WindowConfig *winConfig)
{
    InitWindowFromConfig(gMenuWindowPtr, winConfig);
    gMenuWindowPtr->tileDataStartOffset = gMenuTextTileOffset;
}

void MenuPrint(const u8 *str, u8 left, u8 top)
{
    sub_8003460(gMenuWindowPtr, str, gMenuTextTileOffset, left, top);
}

void MenuZeroFillWindowRect(u8 a1, u8 a2, u8 a3, u8 a4)
{
    ZeroFillWindowRect(gMenuWindowPtr, a1, a2, a3, a4);
}

void MenuFillWindowRectWithBlankTile(u8 left, u8 top, u8 right, u8 bottom)
{
    FillWindowRectWithBlankTile(gMenuWindowPtr, left, top, right, bottom);
}

void MenuZeroFillScreen(void)
{
    MenuZeroFillWindowRect(0, 0, 29, 19);
}

void MenuDrawTextWindow(u8 left, u8 top, u8 right, u8 bottom)
{
    DrawTextWindow(gMenuWindowPtr, left, top, right, bottom);
}

void sub_8071F40(u8 *str)
{
    MenuDrawTextWindow(2, 14, 28, 19);
    MenuPrint(str, 3, 15);
}

void sub_8071F60(u8 a1, u8 a2, u8 a3, u8 a4)
{
    sub_8003490(gMenuWindowPtr, a1, gMenuTextTileOffset, a2, a3);
}

u16 unref_sub_8071F98(u8 x, u8 y)
{
    return GetWindowTilemapEntry(gMenuWindowPtr, x, y);
}

void unref_sub_8071FBC(u16 a1, u8 a2, u8 a3, u8 a4, u8 a5)
{
    DrawWindowRect(gMenuWindowPtr, a1, a2, a3, a4, a5);
}

void MenuDisplayMessageBox(void)
{
    DisplayMessageBox(gMenuWindowPtr);
}

void MenuPrintMessage(const u8 *str, u8 left, u8 top)
{
    sub_8002EB0(gMenuWindowPtr, str, gMenuTextTileOffset, left, top);
}

void sub_8072044(const u8 *str)
{
    sub_8002EB0(gMenuWindowPtr, str, gMenuTextTileOffset, 2, 15);
}

void MenuSetText(const u8 *str)
{
    sub_8002E90(gMenuWindowPtr, str);
}

u8 MenuUpdateWindowText(void)
{
    return sub_80035AC(gMenuWindowPtr);
}

u8 unref_sub_8072098(void)
{
    return sub_8003418(gMenuWindowPtr);
}

void sub_80720B0(void)
{
    ClearWindowTextLines(gMenuWindowPtr);
}

u8 MoveMenuCursor(s8 delta)
{
    s32 newPos = gMenu.cursorPos + delta;

    if (newPos < gMenu.minCursorPos)
        gMenu.cursorPos = gMenu.maxCursorPos;
    else if (newPos > gMenu.maxCursorPos)
        gMenu.cursorPos = gMenu.minCursorPos;
    else
        gMenu.cursorPos += delta;

    RedrawMenuCursor(gMenu.left, 2 * gMenu.cursorPos + gMenu.top);
    return gMenu.cursorPos;
}

u8 MoveMenuCursorNoWrap(s8 delta)
{
    s32 newPos = gMenu.cursorPos + delta;

    if (newPos < gMenu.minCursorPos)
        gMenu.cursorPos = gMenu.minCursorPos;
    else if (newPos > gMenu.maxCursorPos)
        gMenu.cursorPos = gMenu.maxCursorPos;
    else
        gMenu.cursorPos += delta;

    RedrawMenuCursor(gMenu.left, 2 * gMenu.cursorPos + gMenu.top);
    return gMenu.cursorPos;
}

u8 GetMenuCursorPos(void)
{
    return gMenu.cursorPos;
}

s8 ProcessMenuInput(void)
{
    if (gMain.newKeys & A_BUTTON)
    {
        PlaySE(SE_SELECT);
        if (gMenu.menu_field_7)
            sub_8072DEC();
        return gMenu.cursorPos;
    }

    if (gMain.newKeys & B_BUTTON)
    {
        if (gMenu.menu_field_7)
            sub_8072DEC();
        return -1;
    }

    if (gMain.newKeys & DPAD_UP)
    {
        PlaySE(SE_SELECT);
        MoveMenuCursor(-1);
        return -2;
    }
    else if (gMain.newKeys & DPAD_DOWN)
    {
        PlaySE(SE_SELECT);
        MoveMenuCursor(1);
        return -2;
    }

    return -2;
}

s8 ProcessMenuInputNoWrap(void)
{
    u8 cursorPos = gMenu.cursorPos;

    if (gMain.newKeys & A_BUTTON)
    {
        PlaySE(SE_SELECT);
        if (gMenu.menu_field_7)
            sub_8072DEC();
        return gMenu.cursorPos;
    }

    if (gMain.newKeys & B_BUTTON)
    {
        if (gMenu.menu_field_7)
            sub_8072DEC();
        return -1;
    }

    if (gMain.newKeys & DPAD_UP)
    {
        if (cursorPos != MoveMenuCursorNoWrap(-1))
            PlaySE(SE_SELECT);
        return -2;
    }
    else if (gMain.newKeys & DPAD_DOWN)
    {
        if (cursorPos != MoveMenuCursorNoWrap(1))
            PlaySE(SE_SELECT);
        return -2;
    }

    MoveMenuCursorNoWrap(0);
    return -2;
}

u8 MoveMenuCursor3(s8 delta)
{
    u8 menuHeight = (gMenu.maxCursorPos + 1) >> 1;
    s32 newPos = gMenu.cursorPos + delta;

    if (newPos < gMenu.minCursorPos)
        gMenu.cursorPos = gMenu.maxCursorPos;
    else if (newPos > gMenu.maxCursorPos)
        gMenu.cursorPos = gMenu.minCursorPos;
    else
        gMenu.cursorPos += delta;

    RedrawMenuCursor(
        6 * (gMenu.cursorPos / menuHeight) + gMenu.left,
        2 * (gMenu.cursorPos % menuHeight) + gMenu.top);

    return gMenu.cursorPos;
}

u8 MoveMenuCursor4(s8 delta)
{
    if (gMenu.cursorPos + delta <= gMenu.maxCursorPos)
    {
        if (sub_80723D4() == TRUE)
            return gMenu.cursorPos;
    }
    else
    {
        return gMenu.cursorPos;
    }

    gMenu.cursorPos += delta;

    if ((gMenu.maxCursorPos + 1) / gMenu.width == 0)
        RedrawMenuCursor(
            gMenu.left + gMenu.columnXCoords[gMenu.cursorPos % gMenu.width],
            2 * ((gMenu.cursorPos / gMenu.width) % gMenu.height) + gMenu.top);
    else
        RedrawMenuCursor(
            gMenu.left + gMenu.columnXCoords[gMenu.cursorPos % gMenu.width],
            2 * (gMenu.cursorPos / gMenu.width) + gMenu.top);

    return gMenu.cursorPos;
}

static bool8 sub_80723D4(void)
{
    if ((gMain.newKeys & DPAD_UP) && gMenu.cursorPos < gMenu.width)
        return TRUE;

    if ((gMain.newKeys & DPAD_DOWN) && gMenu.cursorPos >= (gMenu.maxCursorPos + 1) - gMenu.width)
        return TRUE;

    if ((gMain.newKeys & DPAD_LEFT)
     && ((gMenu.cursorPos - (gMenu.cursorPos % gMenu.width)) % gMenu.width == 1 // always false
         || gMenu.cursorPos == 0
         || gMenu.cursorPos % gMenu.width == 0))
         return TRUE;

    if ((gMain.newKeys & DPAD_RIGHT) && gMenu.cursorPos % gMenu.width == gMenu.width - 1)
        return TRUE;

    return FALSE;
}

static u8 sub_8072484(u8 a1, u8 a2, u8 menuItemCount, u8 a4, u8 width, u8 a6, u32 a7)
{
    u8 v7;

    gMenu.width = width;
    gMenu.height = menuItemCount / width;
    InitMenu(0, a1, a2, menuItemCount, a4, a6);
    v7 = 0;
    if (a7)
        v7 = -1;
    gMenu.menu_field_7 = v7;
    return a4;
}

static u8 sub_80724F4(u8 left, u8 top, u8 menuItemCount, const struct MenuAction menuItems[], u8 columnCount)
{
    u8 i;
    u8 maxWidth;
    s32 height;

    for (i = 0; i < 7; i++)
        gMenu.columnXCoords[i] = 0;

    maxWidth = 0;
    for (i = 0; i < menuItemCount; i++)
    {
        u8 width = (sub_8072CA4(menuItems[i].text) + 7) / 8;

        if (width > maxWidth)
            maxWidth = width;
    }

    for (i = 1; i <= columnCount; i++)
        gMenu.columnXCoords[i] = maxWidth;

    for (i = 1; i <= columnCount; i++)
        gMenu.columnXCoords[i] += 1 + gMenu.columnXCoords[i - 1];

    gMenu.columnXCoords[columnCount]--;

    if (!((menuItemCount / 2) < columnCount || (menuItemCount % 2 != 0))
     || columnCount == 1
     || columnCount == menuItemCount)
    {
        height = 2 * (menuItemCount / columnCount) + 1;
    }
    else
    {
        height = 2 * ((menuItemCount / columnCount) + 1) + 1;
    }

    {
        // TODO: Make this code less hideous but still match the original asm.
        u8 right;
        u8 bottom;
        u32 totalWidth;
        register s32 val asm("r1");

        val = (s8)top + height;
        val = val << 24;
        asm("" ::: "r3");
        bottom = val >> 24;

        totalWidth = (gMenu.columnXCoords[columnCount] + 1);
        right = left + totalWidth;

        MenuDrawTextWindow(left, top, right, bottom);
    }

    return maxWidth;
}

static void sub_8072620(u8 left, u8 top, u8 menuItemCount, const struct MenuAction menuItems[], u8 columnCount)
{
    u8 i;
    u8 maxWidth;

    for (i = 0; i < 7; i++)
        gMenu.columnXCoords[i] = 0;

    maxWidth = 0;
    for (i = 0; i < menuItemCount; i++)
    {
        u8 width = (sub_8072CA4(menuItems[i].text) + 7) / 8;

        if (width > maxWidth)
            maxWidth = width;
    }

    for (i = 1; i <= columnCount; i++)
        gMenu.columnXCoords[i] = maxWidth;

    for (i = 1; i <= columnCount; i++)
        gMenu.columnXCoords[i] += 1 + gMenu.columnXCoords[i - 1];

    gMenu.columnXCoords[columnCount]--;

    for (i = 0; i < columnCount; i++)
    {
        u8 row = 0;
        u8 j;
        for (j = 0; i + j < menuItemCount; j += columnCount, row++)
            MenuPrint(menuItems[i + j].text, left + gMenu.columnXCoords[i % columnCount], top + 2 * row);
    }
}

void sub_807274C(u8 left, u8 top, u8 menuItemCount, u8 a4, const struct MenuAction menuItems[], u8 columnCount, u32 a7)
{
    u8 maxWidth = sub_80724F4(left, top, menuItemCount, menuItems, columnCount);

    sub_8072484(left + 1, top + 1, menuItemCount, a4, columnCount, maxWidth, a7);
    sub_8072620(left + 1, top + 1, menuItemCount, menuItems, columnCount);
}

s8 sub_80727CC(void)
{
    if (gMain.newKeys & A_BUTTON)
    {
        if (gMenu.menu_field_7)
            sub_8072DEC();
        PlaySE(SE_SELECT);
        return GetMenuCursorPos();
    }

    if (gMain.newKeys & B_BUTTON)
    {
        if (gMenu.menu_field_7)
            sub_8072DEC();
        return -1;
    }

    if (gMain.newKeys & DPAD_UP)
    {
        PlaySE(SE_SELECT);
        MoveMenuCursor4(-gMenu.width);
        return -2;
    }
    else if (gMain.newKeys & DPAD_DOWN)
    {
        PlaySE(SE_SELECT);
        MoveMenuCursor4(gMenu.width);
        return -2;
    }
    else if (gMain.newKeys & DPAD_LEFT)
    {
        PlaySE(SE_SELECT);
        MoveMenuCursor4(-1);
        return -2;
    }
    else if (gMain.newKeys & DPAD_RIGHT)
    {
        PlaySE(SE_SELECT);
        MoveMenuCursor4(1);
        return -2;
    }

    return -2;
}

u8 sub_807288C(u8 column)
{
    return gMenu.columnXCoords[column];
}

void PrintMenuItems(u8 left, u8 top, u8 menuItemCount, const struct MenuAction menuItems[])
{
    u8 i;

    for (i = 0; i < menuItemCount; i++)
        MenuPrint(menuItems[i].text, left, top + 2 * i);
}

void PrintMenuItemsReordered(u8 left, u8 top, u8 menuItemCount, const struct MenuAction menuItems[], u8 *order)
{
    u8 i;

    for (i = 0; i < menuItemCount; i++)
        MenuPrint(menuItems[order[i]].text, left, top + 2 * i);
}

void InitYesNoMenu(u8 left, u8 top, u8 a3)
{
    PrintMenuItems(left + 1, top + 1, 2, gMenuYesNoItems);
    InitMenu(0, left + 1, top + 1, 2, 0, a3);
}

void DisplayYesNoMenu(u8 left, u8 top, u32 a3)
{
    MenuDrawTextWindow(left, top, left + 6, top + 5);
    InitYesNoMenu(left, top, 5);
    gMenu.menu_field_7 = a3 ? -1 : 0;
}

s8 ProcessMenuInputNoWrap_(void)
{
    return ProcessMenuInputNoWrap();
}

u8 MenuPrint_PixelCoords(u8 *text, u8 left, u16 top, u8 a4)
{
    return sub_8004D04(gMenuWindowPtr, text, gMenuTextTileOffset, left, top, a4);
}

u8 sub_8072A18(u8 *text, u8 left, u16 top, u8 width, u32 a5)
{
    return sub_8004FD0(gMenuWindowPtr, 0, text, gMenuTextTileOffset, left, top, width, a5);
}

u8 unref_sub_8072A5C(u8 *dest, u8 *src, u8 left, u16 top, u8 width, u32 a6)
{
    return sub_8004FD0(gMenuWindowPtr, dest, src, gMenuTextTileOffset, left, top, width, a6);
}

#ifdef NONMATCHING
int sub_8072AB0(u8 *str, u8 left, u16 top, u8 width, u8 height, u32 a6)
{
    u8 newlineCount = sub_8004FD0(gMenuWindowPtr, NULL, str, gMenuTextTileOffset, left, top, width, a6);

    left /= 8;
    top /= 8;
    width = (width + 7) / 8;
    height = (height + 7) / 8;

    if (newlineCount < height)
        MenuFillWindowRectWithBlankTile(left, top + 2 * newlineCount, left + width - 1, height + top - 1);
}
#else
__attribute__((naked))
int sub_8072AB0(u8 *str, u8 left, u16 top, u8 width, u8 height, u32 a6)
{
    asm(".syntax unified\n\
	push {r4-r7,lr}\n\
	sub sp, 0x10\n\
	mov r12, r0\n\
	ldr r0, [sp, 0x24]\n\
	ldr r4, [sp, 0x28]\n\
	str r4, [sp, 0xC]\n\
	lsls r1, 24\n\
	lsrs r5, r1, 24\n\
	lsls r2, 16\n\
	lsrs r4, r2, 16\n\
	lsls r3, 24\n\
	lsrs r6, r3, 24\n\
	lsls r0, 24\n\
	lsrs r7, r0, 24\n\
	ldr r0, _08072AF8 @ =gMenuWindowPtr\n\
	ldr r0, [r0]\n\
	ldr r1, _08072AFC @ =gMenuTextTileOffset\n\
	ldrh r3, [r1]\n\
	str r5, [sp]\n\
	str r4, [sp, 0x4]\n\
	str r6, [sp, 0x8]\n\
	movs r1, 0\n\
	mov r2, r12\n\
	bl sub_8004FD0\n\
	adds r1, r0, 0\n\
	lsls r1, 24\n\
	lsrs r2, r1, 24\n\
	movs r3, 0x7\n\
	ands r3, r5\n\
	cmp r3, 0\n\
	bne _08072B00\n\
	adds r1, r6, 0x7\n\
	asrs r1, 3\n\
	subs r1, 0x1\n\
	b _08072B0C\n\
	.align 2, 0\n\
_08072AF8: .4byte gMenuWindowPtr\n\
_08072AFC: .4byte gMenuTextTileOffset\n\
_08072B00:\n\
	adds r3, r6, r3\n\
	subs r1, r3, 0x1\n\
	cmp r1, 0\n\
	bge _08072B0A\n\
	adds r1, r3, 0x6\n\
_08072B0A:\n\
	asrs r1, 3\n\
_08072B0C:\n\
	lsls r1, 24\n\
	lsrs r1, 24\n\
	adds r6, r1, 0\n\
	lsrs r5, 3\n\
	adds r1, r7, 0x7\n\
	asrs r1, 3\n\
	lsls r1, 24\n\
	lsrs r7, r1, 24\n\
	lsrs r4, 3\n\
	cmp r2, r7\n\
	bcs _08072B3E\n\
	lsls r1, r2, 1\n\
	adds r1, r4, r1\n\
	lsls r1, 24\n\
	lsrs r1, 24\n\
	adds r2, r5, r6\n\
	lsls r2, 24\n\
	lsrs r2, 24\n\
	adds r3, r7, r4\n\
	subs r3, 0x1\n\
	lsls r3, 24\n\
	lsrs r3, 24\n\
	adds r0, r5, 0\n\
	bl MenuFillWindowRectWithBlankTile\n\
_08072B3E:\n\
	add sp, 0x10\n\
	pop {r4-r7}\n\
	pop {r1}\n\
	bx r1\n\
    .syntax divided\n");
}
#endif

void MenuPrint_RightAligned(u8 *str, u8 left, u8 top)
{
    sub_8004D38(gMenuWindowPtr, str, gMenuTextTileOffset, left, top);
}

void sub_8072B80(u8 *a1, u8 a2, u8 a3, u8 *a4)
{
    u8 buffer[64];
    u8 width = GetStringWidth(gMenuWindowPtr, a4);
    AlignString(gMenuWindowPtr, buffer, a1, width, 1);
    sub_8003460(gMenuWindowPtr, buffer, gMenuTextTileOffset, a2, a3);
}

void sub_8072BD8(u8 *a1, u8 a2, u8 a3, u16 a4)
{
    sub_8004DB0(gMenuWindowPtr, a1, gMenuTextTileOffset, a2, a3, a4);
}

u8 *sub_8072C14(u8 *a1, s32 a2, u8 a3, u8 a4)
{
    return AlignInt1(gMenuWindowPtr, a1, a2, a3, a4);
}

u8 *sub_8072C44(u8 *a1, s32 a2, u8 a3, u8 a4)
{
    return AlignInt2(gMenuWindowPtr, a1, a2, a3, a4);
}

u8 *sub_8072C74(u8 *a1, const u8 *a2, u8 a3, u8 a4)
{
    return AlignString(gMenuWindowPtr, a1, a2, a3, a4);
}

u8 sub_8072CA4(u8 *str)
{
    return GetStringWidth(gMenuWindowPtr, str);
}

u8 sub_8072CBC()
{
    return sub_8004E24(gMenuWindowPtr);
}

void sub_8072CD4(u8 *a1, u8 *a2, u8 *a3)
{
    sub_8004E28(gMenuWindowPtr, a1, a2, a3);
}

u32 MenuUpdateWindowText_OverrideLineLength(u8 lineLength)
{
    return sub_80037C8(gMenuWindowPtr, lineLength);
}

struct Window *unref_sub_8072D0C(void)
{
    return gMenuWindowPtr;
}

static void sub_8072D18(u8 a1, u8 a2)
{
    sub_814A5C0(a1, 0xFFFF, 12, 11679, 8 * a2);
}

u8 InitMenu(u8 cursorSubpriority, u8 left, u8 top, u8 numChoices, u8 cursorPos, u8 cursorWidth)
{
    s32 pos;

    if (cursorWidth)
        sub_8072D18(cursorSubpriority, cursorWidth);

    gMenu.left = left - 1;
    gMenu.top = top;
    gMenu.minCursorPos = 0;
    gMenu.maxCursorPos = numChoices - 1;
    gMenu.menu_field_7 = 0;

    pos = cursorPos;

    if (pos < 0 || pos > gMenu.maxCursorPos)
        pos = 0;

    gMenu.cursorPos = pos;
    MoveMenuCursor(0);

    return pos;
}

void RedrawMenuCursor(u8 a1, u8 a2)
{
    sub_814A880((a1 + 1) * 8, 8 * a2);
}

void unref_sub_8072DC0()
{
    sub_814A904();
}

void sub_8072DCC(u8 a1)
{
    sub_814A958(a1);
}

void sub_8072DDC(u8 a1)
{
    sub_8072DCC(8 * a1);
}

void sub_8072DEC(void)
{
    sub_814A7FC();
}

__attribute__((naked))
void de_sub_8073110(u8* buffer, u8 *name)
{
    asm(".syntax unified\n\
	push {r4-r7,lr}\n\
	mov r7, r8\n\
	push {r7}\n\
	adds r6, r0, 0\n\
	mov r8, r1\n\
	adds r5, r6, 0\n\
	ldr r4, _08073134 @ =gStringVar1\n\
	movs r1, 0x80\n\
	lsls r1, 1\n\
	adds r0, r4, 0\n\
	bl de_sub_8006CA8\n\
	adds r4, 0x1\n\
	adds r4, r0, r4\n\
	adds r1, r4, 0\n\
	movs r7, 0xFF\n\
	b _0807313E\n\
	.align 2, 0\n\
_08073134: .4byte gStringVar1\n\
_08073138:\n\
	strb r2, [r1]\n\
	adds r5, 0x1\n\
	adds r1, 0x1\n\
_0807313E:\n\
	ldrb r2, [r5]\n\
	adds r0, r2, 0\n\
	cmp r0, 0xFF\n\
	beq _08073168\n\
	cmp r0, 0xFD\n\
	bne _08073138\n\
	strb r7, [r1]\n\
	adds r5, 0x2\n\
	adds r0, r4, 0\n\
	mov r1, r8\n\
	bl StringAppend\n\
	adds r0, r4, 0\n\
	adds r1, r5, 0\n\
	bl StringAppend\n\
	strb r7, [r6]\n\
	adds r0, r6, 0\n\
	adds r1, r4, 0\n\
	bl StringAppend\n\
_08073168:\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4-r7}\n\
	pop {r0}\n\
	bx r0\n\
    .syntax divided\n");
}

u8 *de_sub_8073174(u8 *name, u8 *format) {
    u32 offset;
    u8 *ptr;

    offset = de_sub_8006CA8(gStringVar2, 0x100);
    ptr = &gStringVar2[1 + offset];

    StringCopy(ptr, format);

    de_sub_8073110(ptr, name);

    return StringCopy(name, ptr);
}