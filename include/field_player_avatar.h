#ifndef GUARD_FIELD_PLAYER_AVATAR_H
#define GUARD_FIELD_PLAYER_AVATAR_H

// sub_80587B4
void player_step(u8 a, u16 b, u16 c);
// ForcedMovement_None
// ForcedMovement_Slip
// sub_8058AAC
// sub_8058AC4
// sub_8058ADC
// sub_8058AF4
// sub_8058B0C
// sub_8058B24
// sub_8058B3C
// sub_8058B54
// ForcedMovement_SlideSouth
// ForcedMovement_SlideNorth
// ForcedMovement_SlideWest
// ForcedMovement_SlideEast
// sub_8058C04
// sub_8058C10
// ForcedMovement_MuddySlope
// PlayerNotOnBikeNotMoving
// PlayerNotOnBikeTurningInPlace
// sub_8058D0C
u8 CheckForFieldObjectCollision(struct MapObject *a, s16 b, s16 c, u8 d, u8 e);
void SetPlayerAvatarTransitionFlags(u16 a);
// nullsub_49
// PlayerAvatarTransition_Normal
// PlayerAvatarTransition_MachBike
// PlayerAvatarTransition_AcroBike
// PlayerAvatarTransition_Surfing
// PlayerAvatarTransition_Underwater
// sub_80591F4
void sub_8059204(void);
u8 player_get_x22(void);
void PlayerSetAnimId(u8 a, u8 b);
void PlayerGoSpeed0(u8 a);
void sub_80593C4(u8 a);
void npc_use_some_d2s(u8 a);
void sub_80593F4(u8 a);
void sub_805940C(u8 a);
void PlayerOnBikeCollide(u8);
void PlayerFaceDirection(u8 a);
void PlayerTurnInPlace(u8 a);
void PlayerJumpLedge(u8 a);
void sub_80594C0(void);
void sub_8059504(u8 a);
void PlayerStartWheelie(u8 a);
void sub_8059534(u8 a);
void sub_805954C(u8 a);
void sub_8059570(u8 a);
void sub_8059594(u8 a);
void sub_80595B8(u8 a);
void sub_80595DC(u8 a);
void sub_8059600(u8 a);
void sub_8059618(u8 a);
void sub_8059630(u8 a);
void GetXYCoordsOneStepInFrontOfPlayer(s16 *x, s16 *y);
void PlayerGetDestCoords(s16 *, s16 *);
u8 player_get_direction_lower_nybble(void);
u8 player_get_direction_upper_nybble(void);
u8 PlayerGetZCoord(void);
u8 TestPlayerAvatarFlags(u8);
// sub_80597D0
u8 GetPlayerAvatarObjectId(void);
void sub_80597E8(void);
void sub_80597F4(void);
u8 GetRivalAvatarGraphicsIdByStateIdAndGender(u8 a, u8 b);
u8 GetPlayerAvatarGraphicsIdByStateId(u8 a);
u8 GetPlayerAvatarGenderByGraphicsId(u8 gfxId);
bool8 PartyHasMonWithSurf(void);
bool8 IsPlayerSurfingNorth(void);
bool8 IsPlayerFacingSurfableFishableWater(void);
// ClearPlayerAvatarInfo
void SetPlayerAvatarStateMask(u8 a);
u8 GetPlayerAvatarGraphicsIdByCurrentState(void);
void SetPlayerAvatarExtraStateTransition(u8 a, u8 b);
void InitPlayerAvatar(s16 a, s16 b, u8 c, u8 d);
// sub_8059B88
void sub_8059BF4(void);
// sub_8059C3C
void sub_8059C94(u8);
// sub_8059D08
// sub_8059E84
// sub_8059EA4
// sub_8059F40
// sub_805A000
// sub_805A0D8
// sub_805A100
// sub_805A178
// sub_805A1B8
void sub_805A20C(u8 a);
void StartFishing(u8 a);
// Fishing1
// Fishing2
// Fishing3
// Fishing4
// Fishing5
// Fishing6
// Fishing7
// Fishing8
// Fishing9
// Fishing10
// Fishing11
// Fishing12
// Fishing13
// Fishing14
// Fishing15
// Fishing16

#endif
