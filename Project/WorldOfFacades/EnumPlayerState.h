#pragma once

/// <summary>
/// The flagged state a Player is in.
/// </summary>
// ToDo (m2vh) Question: Values MUST be base of 2 (0,1,2,4,8...) ???

enum EPlayerState
{
	PLAYER_NONE = 0,	// for completeness
	PLAYER_IDLE = 1, // << 0, // Player can move
	PLAYER_BLOCKED = 2, // << 1,	// Player can't AYER_LwYERShileALPdialog is displayed
	PLAYER_WALK = 4,	// state when walking anim is lYER_aying
	PLAYER_JUMP = 8,
	PLAYER_AT_ITEM = 16,	// Item is in reach
	PLAYER_AT_NPC = 32,	// NPC in reach
	PLAYER_VISIT_NPC = 364 // << 4	// at NPC; block the move

	// is it possible to do this:
	// VISIT_NPC = BLOCKED | 5;
	// results in 
	// (VISIT_NPC & BLOCKED ) == BLOCKED
};

