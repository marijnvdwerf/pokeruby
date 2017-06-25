#include "global.h"
#include "mail.h"
#include "easy_chat.h"
#include "items.h"
#include "mail_data.h"
#include "menu.h"
#include "menu_helpers.h"
#include "name_string_util.h"
#include "palette.h"
#include "pokemon_icon.h"
#include "rom4.h"
#include "sprite.h"
#include "string_util.h"
#include "strings2.h"
#include "task.h"
#include "text.h"
#include "unknown_task.h"

struct UnkMailStruct
{
    u8 unk_0_0:2;
    u8 unk_0_2:2;
    u8 unk_0_4:4;
};

struct MailLayout
{
    u8 var0;
    u8 var1;
    u8 var2;
    u8 var3_0:4;
    u8 var3_4:4;
    struct UnkMailStruct *var4;
};

struct Unk2000000
{
    /* 0x00*/ u8 words[8][27];
    /* 0xD8*/ u8 varD8[20];
    /* 0xEC*/ MainCallback varEC;
    /* 0xF0*/ MainCallback varF0;
    /* 0xF4*/ struct MailStruct *varF4;
    /* 0xF8*/ u8 varF8;
    /* 0xF9*/ u8 varF9;
    /* 0xFA*/ u8 varFA;
    /* 0xFB*/ u8 varFB;
    /* 0xFC*/ u8 varFC;
    u8 padFD[1];
    /* 0xFE*/ u8 varFE;
    /* 0xFF*/ u8 varFF;
    /*0x100*/ u8 var100;
    u8 pad101[3];
    /*0x104*/ MainCallback var104;
    /*0x108*/ MainCallback var108;
    /*0x10C*/ struct MailLayout *var10C;
};

struct MailGraphics
{
    u16 (*palette)[];
    u8 (*tiles)[];
    u8 (*tileMap)[];
    u16 var0C;
    u16 var0E;
    u16 color10;
    u16 color12;
};

extern u8 ewram[];
#define ewram0 (*(struct Unk2000000 *)(ewram))

extern struct MailGraphics gMailGraphicsTable[];
extern u16 gUnknown_083E562C[][2];

extern struct MailLayout gUnknown_083E5730[];
extern struct MailLayout gUnknown_083E57A4[];

static u8 sub_80F8A28(void);
void sub_80F8D50(void);
static void sub_80F8DA0(void);
static void sub_80F8E80(void);
void sub_80F8F18(void);
static void sub_80F8F2C(void);
static void sub_80F8F58(void);
static void sub_80F8F78(void);
static void sub_80F8FB4(void);

#ifdef DEBUG
__attribute__((naked))
void HandleReadMail(struct MailStruct *aStruct, MainCallback callback, bool8 bool81)
{
    asm(
        "	push	{r4, r5, r6, lr}\n"
        "	add	sp, sp, #0xfffffffc\n"
        "	add	r4, r0, #0\n"
        "	add	r6, r1, #0\n"
        "	lsl	r2, r2, #0x18\n"
        "	lsr	r5, r2, #0x18\n"
        "	ldr	r0, ._3\n"
        "	ldrb	r3, [r0]\n"
        "	cmp	r3, #0\n"
        "	beq	._1	@cond_branch\n"
        "	ldr	r2, ._3 + 4\n"
        "	add	r1, r2, #0\n"
        "	add	r1, r1, #0xff\n"
        "	mov	r0, #0x5\n"
        "	strb	r0, [r1]\n"
        "	ldr	r0, ._3 + 8\n"
        "	ldrh	r1, [r0]\n"
        "	mov	r3, #0x80\n"
        "	lsl	r3, r3, #0x1\n"
        "	add	r0, r2, r3\n"
        "	strb	r1, [r0]\n"
        "	mov	r0, #0x82\n"
        "	lsl	r0, r0, #0x1\n"
        "	add	r1, r2, r0\n"
        "	ldr	r0, ._3 + 12\n"
        "	str	r0, [r1]\n"
        "	add	r3, r3, #0x8\n"
        "	add	r1, r2, r3\n"
        "	ldr	r0, ._3 + 16\n"
        "	str	r0, [r1]\n"
        "	ldr	r0, ._3 + 20\n"
        "	ldrh	r1, [r0]\n"
        "	b	._2\n"
        "._4:\n"
        "	.align	2, 0\n"
        "._3:\n"
        "	.word	gUnknown_03000748+0x4\n"
        "	.word	+0x2000000\n"
        "	.word	gSpecialVar_0x8004\n"
        "	.word	sub_80EB3FC+1\n"
        "	.word	ConvertEasyChatWordsToString+1\n"
        "	.word	gSpecialVar_0x8006\n"
        "._1:\n"
        "	ldr	r2, ._7\n"
        "	add	r1, r2, #0\n"
        "	add	r1, r1, #0xff\n"
        "	mov	r0, #0x5\n"
        "	strb	r0, [r1]\n"
        "	add	r0, r0, #0xfb\n"
        "	add	r1, r2, r0\n"
        "	mov	r0, #0x1\n"
        "	strb	r0, [r1]\n"
        "	mov	r0, #0x82\n"
        "	lsl	r0, r0, #0x1\n"
        "	add	r1, r2, r0\n"
        "	ldr	r0, ._7 + 4\n"
        "	str	r0, [r1]\n"
        "	mov	r0, #0x84\n"
        "	lsl	r0, r0, #0x1\n"
        "	add	r1, r2, r0\n"
        "	ldr	r0, ._7 + 8\n"
        "	str	r0, [r1]\n"
        "	ldrh	r1, [r4, #0x20]\n"
        "	add	r0, r1, #0\n"
        "	sub	r0, r0, #0x79\n"
        "	lsl	r0, r0, #0x10\n"
        "	lsr	r0, r0, #0x10\n"
        "	cmp	r0, #0xb\n"
        "	bhi	._5	@cond_branch\n"
        "	sub	r1, r1, #0x79\n"
        "._2:\n"
        "	add	r0, r2, #0\n"
        "	add	r0, r0, #0xfa\n"
        "	strb	r1, [r0]\n"
        "	b	._6\n"
        "._8:\n"
        "	.align	2, 0\n"
        "._7:\n"
        "	.word	+0x2000000\n"
        "	.word	sub_80EB3FC+1\n"
        "	.word	ConvertEasyChatWordsToString+1\n"
        "._5:\n"
        "	add	r0, r2, #0\n"
        "	add	r0, r0, #0xfa\n"
        "	strb	r3, [r0]\n"
        "	mov	r5, #0x0\n"
        "._6:\n"
        "	ldr	r1, ._12\n"
        "	mov	r2, #0x80\n"
        "	lsl	r2, r2, #0x1\n"
        "	add	r0, r1, r2\n"
        "	ldrb	r0, [r0]\n"
        "	cmp	r0, #0\n"
        "	beq	._9	@cond_branch\n"
        "	cmp	r0, #0x1\n"
        "	beq	._10	@cond_branch\n"
        "._9:\n"
        "	mov	r3, #0x86\n"
        "	lsl	r3, r3, #0x1\n"
        "	add	r2, r1, r3\n"
        "	add	r0, r1, #0\n"
        "	add	r0, r0, #0xfa\n"
        "	ldrb	r0, [r0]\n"
        "	lsl	r0, r0, #0x3\n"
        "	ldr	r1, ._12 + 4\n"
        "	b	._11\n"
        "._13:\n"
        "	.align	2, 0\n"
        "._12:\n"
        "	.word	+0x2000000\n"
        "	.word	gUnknown_083E5730\n"
        "._10:\n"
        "	mov	r0, #0x86\n"
        "	lsl	r0, r0, #0x1\n"
        "	add	r2, r1, r0\n"
        "	add	r0, r1, #0\n"
        "	add	r0, r0, #0xfa\n"
        "	ldrb	r0, [r0]\n"
        "	lsl	r0, r0, #0x3\n"
        "	ldr	r1, ._18\n"
        "._11:\n"
        "	add	r0, r0, r1\n"
        "	str	r0, [r2]\n"
        "	ldrh	r0, [r4, #0x1e]\n"
        "	mov	r1, sp\n"
        "	bl	MailSpeciesToSpecies\n"
        "	lsl	r0, r0, #0x10\n"
        "	ldr	r1, ._18 + 4\n"
        "	add	r0, r0, r1\n"
        "	mov	r1, #0xcd\n"
        "	lsl	r1, r1, #0x11\n"
        "	cmp	r0, r1\n"
        "	bhi	._14	@cond_branch\n"
        "	ldr	r0, ._18 + 8\n"
        "	add	r1, r0, #0\n"
        "	add	r1, r1, #0xfa\n"
        "	ldrb	r2, [r1]\n"
        "	add	r1, r0, #0\n"
        "	cmp	r2, #0x6\n"
        "	beq	._15	@cond_branch\n"
        "	cmp	r2, #0x9\n"
        "	beq	._16	@cond_branch\n"
        "	b	._17\n"
        "._19:\n"
        "	.align	2, 0\n"
        "._18:\n"
        "	.word	gUnknown_083E57A4\n"
        "	.word	0xffff0000\n"
        "	.word	+0x2000000\n"
        "._15:\n"
        "	add	r2, r1, #0\n"
        "	add	r2, r2, #0xfb\n"
        "	mov	r0, #0x1\n"
        "	b	._21\n"
        "._16:\n"
        "	add	r2, r1, #0\n"
        "	add	r2, r2, #0xfb\n"
        "	mov	r0, #0x2\n"
        "	b	._21\n"
        "._14:\n"
        "	ldr	r1, ._22\n"
        "._17:\n"
        "	add	r2, r1, #0\n"
        "	add	r2, r2, #0xfb\n"
        "	mov	r0, #0x0\n"
        "._21:\n"
        "	strb	r0, [r2]\n"
        "	add	r0, r1, #0\n"
        "	add	r0, r0, #0xf4\n"
        "	str	r4, [r0]\n"
        "	sub	r0, r0, #0x8\n"
        "	str	r6, [r0]\n"
        "	add	r0, r0, #0xc\n"
        "	strb	r5, [r0]\n"
        "	ldr	r0, ._22 + 4\n"
        "	bl	SetMainCallback2\n"
        "	add	sp, sp, #0x4\n"
        "	pop	{r4, r5, r6}\n"
        "	pop	{r0}\n"
        "	bx	r0\n"
        "._23:\n"
        "	.align	2, 0\n"
        "._22:\n"
        "	.word	+0x2000000\n"
        "	.word	sub_80F8D50+1\n"
        "\n"
    );
}
#else
void HandleReadMail(struct MailStruct *arg0, MainCallback arg1, bool8 arg2)
{
    u16 mailDesign;
    u16 buffer[2];

    ewram0.varFF = GAME_LANGUAGE;
    ewram0.var100 = 1;
    ewram0.var104 = (MainCallback)sub_80EB3FC;
    ewram0.var108 = (MainCallback)ConvertEasyChatWordsToString;

    mailDesign = arg0->itemId - ITEM_ORANGE_MAIL;

    if (mailDesign <= 11)
    {
        ewram0.varFA = arg0->itemId - ITEM_ORANGE_MAIL;
    }
    else
    {
        ewram0.varFA = 0;
        arg2 = FALSE;
    }

    switch (ewram0.var100)
    {
    case 0:
    default:
        ewram0.var10C = &gUnknown_083E5730[ewram0.varFA];
        break;

    case 1:
        ewram0.var10C = &gUnknown_083E57A4[ewram0.varFA];
        break;
    }

    if (((MailSpeciesToSpecies(arg0->species, buffer) << 16) + 0xFFFF0000) <= (410 << 16))
    {
        switch (ewram0.varFA)
        {
        case 6:
            ewram0.varFB = 1;
            break;

        case 9:
            ewram0.varFB = 2;
            break;

        default:
            ewram0.varFB = 0;
            break;
        }
    }
    else
    {
        ewram0.varFB = 0;
    }


    ewram0.varF4 = arg0;
    ewram0.varEC = arg1;
    ewram0.varF8 = arg2;

    SetMainCallback2(sub_80F8D50);
}
#endif

#define RETURN_UP_STATE break
#define RETURN_SKIP_STATE return FALSE

static u8 sub_80F8A28(void)
{
    switch (gMain.state)
    {
    case 0:
        SetVBlankCallback(NULL);
        remove_some_task();
        REG_DISPCNT = 0;
        RETURN_UP_STATE;

    case 1: CpuFill16(0, (void *)OAM, OAM_SIZE);
        RETURN_UP_STATE;

    case 2:
        ResetPaletteFade();
        RETURN_UP_STATE;

    case 3:
        ResetTasks();
        RETURN_UP_STATE;

    case 4:
        ResetSpriteData();
        RETURN_UP_STATE;

    case 5:
        FreeAllSpritePalettes();
        REG_BG0HOFS = 0;
        REG_BG0VOFS = 0;
        REG_BG1HOFS = 0;
        REG_BG1VOFS = 0;
        REG_BG2VOFS = 0;
        REG_BG2HOFS = 0;
        REG_BG3HOFS = 0;
        REG_BG3VOFS = 0;
        REG_BLDCNT = 0;
        REG_BLDALPHA = 0;
        RETURN_UP_STATE;

    case 6:
        SetUpWindowConfig(&gWindowConfig_81E6DFC);
        RETURN_UP_STATE;

    case 7:
        MultistepInitMenuWindowBegin(&gWindowConfig_81E6DFC);
        RETURN_UP_STATE;

    case 8:
        if (MultistepInitMenuWindowContinue() == 0)
        {
            return FALSE;
        }
        RETURN_UP_STATE;

    case 9:
        MenuZeroFillScreen();
        RETURN_UP_STATE;

    case 10: CpuFill16(1, (void *)(VRAM + 0x4800), 0x800);
        RETURN_UP_STATE;

    case 11:
        LoadPalette(gMailGraphicsTable[ewram0.varFA].palette, 0, 16 * 2);
        RETURN_UP_STATE;

    case 12:
        LZ77UnCompVram(gMailGraphicsTable[ewram0.varFA].tileMap, (void *)(VRAM + 0x4000));
        RETURN_UP_STATE;

    case 13:
        LZ77UnCompVram(gMailGraphicsTable[ewram0.varFA].tiles, (void *)(VRAM));

        gPlttBufferUnfaded[241] = gMailGraphicsTable[ewram0.varFA].color10;
        gPlttBufferUnfaded[248] = gMailGraphicsTable[ewram0.varFA].color12;
        gPlttBufferUnfaded[10] = gUnknown_083E562C[gSaveBlock2.playerGender][0];
        gPlttBufferUnfaded[11] = gUnknown_083E562C[gSaveBlock2.playerGender][1];
        RETURN_UP_STATE;

    case 14:
        if (ewram0.varF8 != 0)
        {
            sub_80F8DA0();
        }
        RETURN_UP_STATE;

    case 15:
        if (ewram0.varF8 != 0)
        {
            sub_80F8E80();
        }

        SetVBlankCallback(sub_80F8F18);
        gPaletteFade.bufferTransferDisabled = 1;
        RETURN_UP_STATE;

    case 16:
    {
        u16 local1;

        local1 = sub_809D4A8(ewram0.varF4->species);

        switch (ewram0.varFB)
        {
        case 1:
            sub_809D580(local1);
            ewram0.varFC = sub_809D3A4(local1, SpriteCallbackDummy, 96, 128, 0);
            break;

        case 2:
            sub_809D580(local1);
            ewram0.varFC = sub_809D3A4(local1, SpriteCallbackDummy, 40, 128, 0);
            break;
        }
        RETURN_UP_STATE;
    }

    case 17:
        if (sub_8055870() != TRUE)
        {
            RETURN_UP_STATE;
        }
        RETURN_SKIP_STATE;

    case 18:
        REG_BG0CNT = BGCNT_PRIORITY(0) | BGCNT_CHARBASE(2) | BGCNT_SCREENBASE(31) | BGCNT_16COLOR | BGCNT_TXT256x512;
        REG_BG1CNT = BGCNT_PRIORITY(1) | BGCNT_CHARBASE(0) | BGCNT_SCREENBASE(8)  | BGCNT_16COLOR | BGCNT_TXT256x256;
        REG_BG2CNT = BGCNT_PRIORITY(2) | BGCNT_CHARBASE(0) | BGCNT_SCREENBASE(9)  | BGCNT_16COLOR | BGCNT_TXT256x256;
        REG_BLDCNT = 0;
        REG_DISPCNT = DISPCNT_MODE_0 | DISPCNT_OBJ_1D_MAP | DISPCNT_BG0_ON | DISPCNT_BG1_ON | DISPCNT_BG2_ON | DISPCNT_OBJ_ON;
        BeginNormalPaletteFade(-1, 0, 16, 0, 0);
        gPaletteFade.bufferTransferDisabled = 0;
        ewram0.varF0 = sub_80F8F58;
        return TRUE;

    default:
        return FALSE;
    }

    gMain.state += 1;
    return FALSE;
}

void sub_80F8D50(void)
{
    do
    {
        if (sub_80F8A28() == 1)
        {
            SetMainCallback2(sub_80F8F2C);
            return;
        }
    } while (sub_80F9344() != 1);
}

static u8 *sub_80F8D7C(u8 *dest, u8 *src)
{
    u16 length;

    StringCopy(dest, src);
    SanitizeNameString(dest);

    length = StringLength(dest);

    return dest + length;
}

static void sub_80F8DA0(void)
{
    u16 i;
    u8 r6;
    u8 *ptr;

    r6 = 0;
    for (i = 0; i < ewram0.var10C->var0; i++)
    {
        ConvertEasyChatWordsToString(ewram0.words[i], &ewram0.varF4->words[r6], ewram0.var10C->var4[i].unk_0_2, 1);
        r6 += ewram0.var10C->var4[i].unk_0_2;
    }
    ptr = ewram0.varD8;
    if (ewram0.var100 == 0)
    {
        ptr = sub_80F8D7C(ptr, ewram0.varF4->playerName);
        StringCopy(ptr, gOtherText_From);
        ewram0.varF9 = ewram0.var10C->var2 - StringLength(ewram0.varD8);

    }
    else
    {
        ptr = StringCopy(ptr, gOtherText_From);
        sub_80F8D7C(ptr, ewram0.varF4->playerName);
        ewram0.varF9 = ewram0.var10C->var2;
    }
}

static void sub_80F8E80(void)
{
    u16 pos;
    u8 x;
    u8 y = 0;

    for (pos = 0; pos < ewram0.var10C->var0; pos++)
    {
        if (ewram0.words[pos][0] == 0xFF)
        {
            continue;
        }

        if (ewram0.words[pos][0] == 0x00)
        {
            continue;
        }

        x = ewram0.var10C->var4[pos].unk_0_4;
        y += ewram0.var10C->var4[pos].unk_0_0;
        MenuPrint(ewram0.words[pos], ewram0.var10C->var3_4 + x, ewram0.var10C->var3_0 + y);
        y += 2;
    }

    MenuPrint(ewram0.varD8, ewram0.varF9, ewram0.var10C->var1);
}

void sub_80F8F18(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void sub_80F8F2C(void)
{
    if (ewram0.varFB != 0)
    {
        AnimateSprites();
        BuildOamBuffer();
    }

    ewram0.varF0();
}

static void sub_80F8F58(void)
{
    u8 local0;

    local0 = UpdatePaletteFade();
    if (local0 == 0)
    {
        ewram0.varF0 = sub_80F8F78;
    }
}

static void sub_80F8F78(void)
{
    if (gMain.newKeys & (A_BUTTON | B_BUTTON))
    {
        BeginNormalPaletteFade(-1, 0, 0, 16, 0);
        ewram0.varF0 = sub_80F8FB4;
    }
}

#ifdef DEBUG

__attribute__((naked))
void sub_80F8FB4()
{
    asm(
        "	push	{r4, lr}\n"
        "	bl	UpdatePaletteFade\n"
        "	lsl	r0, r0, #0x18\n"
        "	cmp	r0, #0\n"
        "	bne	._135	@cond_branch\n"
        "	ldr	r4, ._138\n"
        "	add	r0, r4, #0\n"
        "	add	r0, r0, #0xec\n"
        "	ldr	r0, [r0]\n"
        "	bl	SetMainCallback2\n"
        "	add	r0, r4, #0\n"
        "	add	r0, r0, #0xfb\n"
        "	ldrb	r0, [r0]\n"
        "	cmp	r0, #0x2\n"
        "	bgt	._137	@cond_branch\n"
        "	cmp	r0, #0x1\n"
        "	blt	._137	@cond_branch\n"
        "	add	r0, r4, #0\n"
        "	add	r0, r0, #0xf4\n"
        "	ldr	r0, [r0]\n"
        "	ldrh	r0, [r0, #0x1e]\n"
        "	bl	sub_809D4A8\n"
        "	lsl	r0, r0, #0x10\n"
        "	lsr	r0, r0, #0x10\n"
        "	bl	sub_809D608\n"
        "	add	r0, r4, #0\n"
        "	add	r0, r0, #0xfc\n"
        "	ldrb	r1, [r0]\n"
        "	lsl	r0, r1, #0x4\n"
        "	add	r0, r0, r1\n"
        "	lsl	r0, r0, #0x2\n"
        "	ldr	r1, ._138 + 4\n"
        "	add	r0, r0, r1\n"
        "	bl	sub_809D510\n"
        "._137:\n"
        "	bl	ResetPaletteFade\n"
        "._135:\n"
        "	pop	{r4}\n"
        "	pop	{r0}\n"
        "	bx	r0\n"
        "._139:\n"
        "	.align	2, 0\n"
        "._138:\n"
        "	.word	+0x2000000\n"
        "	.word	gSprites\n"
        "\n"
    );
}
#else
static void sub_80F8FB4(void)
{
    u16 local1;

    if (UpdatePaletteFade())
    {
        return;
    }

#ifndef DEBUG
    SetMainCallback2(ewram0.varEC);
#endif

    switch (ewram0.varFB)
    {
    case 2:
    case 1:
        local1 = sub_809D4A8(ewram0.varF4->species);
        sub_809D608(local1);

        sub_809D510(&gSprites[ewram0.varFC]);
        break;
    }

    memset(&ewram0, 0, 0x110);

#ifndef DEBUG
    ResetPaletteFade();
#endif
}
#endif
