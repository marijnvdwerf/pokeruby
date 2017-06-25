#include "global.h"
#include "task.h"

#define ACTIVE_SENTINEL 0x10
#define HEAD_SENTINEL 0xFE
#define TAIL_SENTINEL 0xFF

// gTasks is a queue of the active 16 tasks
struct Task gTasks[ACTIVE_SENTINEL];

static void InsertTask(u8 newTaskId);
static u8 FindFirstActiveTask();

void ResetTasks()
{
    u8 taskId;

    for (taskId = 0; taskId < ACTIVE_SENTINEL; taskId++)
    {
        gTasks[taskId].isActive = FALSE;
        gTasks[taskId].func = TaskDummy;
        gTasks[taskId].prev = taskId;
        gTasks[taskId].next = taskId + 1;
        gTasks[taskId].priority = -1;
        memset(gTasks[taskId].data, 0, sizeof(gTasks[taskId].data));
    }

    gTasks[0].prev = HEAD_SENTINEL;
    gTasks[ACTIVE_SENTINEL - 1].next = TAIL_SENTINEL;
}

__attribute__((naked))
u8 CreateTask(TaskFunc func, u8 u81)
{
    asm(
        "	push	{r4, r5, r6, r7, lr}\n"
        "	add	r2, r0, #0\n"
        "	lsl	r1, r1, #0x18\n"
        "	lsr	r1, r1, #0x18\n"
        "	mov	r6, #0x0\n"
        "	ldr	r7, ._6\n"
        "._8:\n"
        "	lsl	r0, r6, #0x2\n"
        "	add	r0, r0, r6\n"
        "	lsl	r5, r0, #0x3\n"
        "	add	r4, r5, r7\n"
        "	ldrb	r0, [r4, #0x4]\n"
        "	cmp	r0, #0\n"
        "	bne	._4	@cond_branch\n"
        "	str	r2, [r4]\n"
        "	strb	r1, [r4, #0x7]\n"
        "	add	r0, r6, #0\n"
        "	bl	InsertTask\n"
        "	add	r0, r7, #0\n"
        "	add	r0, r0, #0x8\n"
        "	add	r0, r5, r0\n"
        "	mov	r1, #0x0\n"
        "	mov	r2, #0x20\n"
        "	bl	gScriptFuncs_End+0x5c24\n"
        "	mov	r0, #0x1\n"
        "	strb	r0, [r4, #0x4]\n"
        "	add	r0, r6, #0\n"
        "	b	._5\n"
        "._7:\n"
        "	.align	2, 0\n"
        "._6:\n"
        "	.word	gTasks\n"
        "._4:\n"
        "	add	r0, r6, #1\n"
        "	lsl	r0, r0, #0x18\n"
        "	lsr	r6, r0, #0x18\n"
        "	cmp	r6, #0xf\n"
        "	bls	._8	@cond_branch\n"
        "	ldr	r0, ._9\n"
        "	bl	unref_sub_80AB084\n"
        "	mov	r0, #0x0\n"
        "._5:\n"
        "	pop	{r4, r5, r6, r7}\n"
        "	pop	{r1}\n"
        "	bx	r1\n"
        "._10:\n"
        "	.align	2, 0\n"
        "._9:\n"
        "	.word	gSpriteTemplate_8393188+0x18\n"
        "\n"
    );
}

static void InsertTask(u8 newTaskId)
{
    u8 taskId = FindFirstActiveTask();

    if (taskId == ACTIVE_SENTINEL)
    {
        // The task system inserts from the top downwards starting from the end (0xFF) to 0. If FindFirstActiveTask returned the value equivalent to ACTIVE_SENTINEL, it means it is the only task because it searched the entire queue.
        gTasks[newTaskId].prev = HEAD_SENTINEL;
        gTasks[newTaskId].next = TAIL_SENTINEL;
        return;
    }

    while (1)
    {
        if (gTasks[newTaskId].priority < gTasks[taskId].priority)
        {
            // We've found a task with a higher priority value,
            // so we insert the new task before it.
            gTasks[newTaskId].prev = gTasks[taskId].prev;
            gTasks[newTaskId].next = taskId;

            if (gTasks[taskId].prev != HEAD_SENTINEL)
                gTasks[gTasks[taskId].prev].next = newTaskId; // as long as we are not at the end, insert the newTask appropriately.

            gTasks[taskId].prev = newTaskId;
            return;
        }
        if (gTasks[taskId].next == TAIL_SENTINEL) // we did not find a space for the task, so overwrite the last task as it is the lowest priority.
        {
            // We've reached the end.
            gTasks[newTaskId].prev = taskId;
            gTasks[newTaskId].next = gTasks[taskId].next;
            gTasks[taskId].next = newTaskId;
            return;
        }
        taskId = gTasks[taskId].next; // neither the priority was lower, nor the end. check the next task.
    }
}

void DestroyTask(u8 taskId)
{
    if (gTasks[taskId].isActive)
    {
        gTasks[taskId].isActive = FALSE;

        if (gTasks[taskId].prev == HEAD_SENTINEL)
        {
            if (gTasks[taskId].next != TAIL_SENTINEL)
                gTasks[gTasks[taskId].next].prev = HEAD_SENTINEL;
        }
        else
        {
            if (gTasks[taskId].next == TAIL_SENTINEL)
            {
                gTasks[gTasks[taskId].prev].next = TAIL_SENTINEL;
            }
            else
            {
                gTasks[gTasks[taskId].prev].next = gTasks[taskId].next;
                gTasks[gTasks[taskId].next].prev = gTasks[taskId].prev;
            }
        }
    }
}

void RunTasks(void)
{
    u8 taskId = FindFirstActiveTask();

    if (taskId != ACTIVE_SENTINEL)
    {
        do
        {
            gTasks[taskId].func(taskId);
            taskId = gTasks[taskId].next;
        } while (taskId != TAIL_SENTINEL);
    }
}

static u8 FindFirstActiveTask(void)
{
    u8 taskId;

    for (taskId = 0; taskId < ACTIVE_SENTINEL; taskId++)
        if (gTasks[taskId].isActive == TRUE && gTasks[taskId].prev == HEAD_SENTINEL)
            break;

    return taskId;
}

void TaskDummy(u8 taskId)
{
}

#define TASK_DATA_OP(taskId, offset, op)                    \
{                                                           \
    u32 tasksAddr = (u32)gTasks;                            \
    u32 addr = taskId * sizeof(struct Task) + offset;       \
    u32 dataAddr = tasksAddr + offsetof(struct Task, data); \
    addr += dataAddr;                                       \
    op;                                                     \
}

void SetTaskFuncWithFollowupFunc(u8 taskId, TaskFunc func, TaskFunc followupFunc)
{
    TASK_DATA_OP(taskId, 28, *((u16 *)addr) = (u32)followupFunc)
    TASK_DATA_OP(taskId, 30, *((u16 *)addr) = (u32)followupFunc >> 16)
    gTasks[taskId].func = func;
}

void SwitchTaskToFollowupFunc(u8 taskId)
{
    s32 func;

    gTasks[taskId].func = NULL;

    TASK_DATA_OP(taskId, 28, func = *((u16 *)addr))
    TASK_DATA_OP(taskId, 30, func |= *((s16 *)addr) << 16)

    gTasks[taskId].func = (TaskFunc)func;
}

bool8 FuncIsActiveTask(TaskFunc func)
{
    u8 i;

    for (i = 0; i < ACTIVE_SENTINEL; i++)
        if (gTasks[i].isActive == TRUE && gTasks[i].func == func)
            return TRUE;

    return FALSE;
}

u8 FindTaskIdByFunc(TaskFunc func)
{
    s32 i;

    for (i = 0; i < ACTIVE_SENTINEL; i++)
        if (gTasks[i].isActive == TRUE && gTasks[i].func == func)
            return (u8)i;

    return -1;
}

u8 GetTaskCount(void)
{
    u8 i;
    u8 count = 0;

    for (i = 0; i < ACTIVE_SENTINEL; i++)
        if (gTasks[i].isActive == TRUE)
            count++;

    return count;
}
