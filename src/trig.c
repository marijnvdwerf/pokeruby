#include "global.h"
#include "trig.h"

extern s16 gSineTable[];
extern s16 gSineDegreeTable[];

void unk8040FE0(void) {
    asm(".fill 16");
}

void unk8040FF4(void) {
    asm(".fill 22");
}

void unk804100C(void) {
    asm(".fill 22");
}

void unk8041024(void) {
    asm(".fill 228");
}

void unk804110C(void) {
}

// amplitude * sin(index*(π/128))
s16 Sin(s16 index, s16 amplitude)
{
    return (amplitude * gSineTable[index]) >> 8;
}

// amplitude * cos(index*(π/128))
s16 Cos(s16 index, s16 amplitude)
{
    return (amplitude * gSineTable[index + 64]) >> 8;
}

// angle in degrees
s16 Sin2(u16 angle)
{
    s32 angleMod = angle % 180;
    s32 negate = ((angle / 180) & 1);
    s16 value = gSineDegreeTable[angleMod];

    if (negate)
        return -value;
    else
        return value;
}

// angle in degrees
s16 Cos2(u16 angle)
{
    return Sin2(angle + 90);
}
