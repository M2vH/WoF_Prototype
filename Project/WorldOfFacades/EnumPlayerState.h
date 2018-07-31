#pragma once

/// <summary>
/// The flagged state a Player is in.
/// </summary>
// ToDo (m2vh) Question: Values MUST be base of 2 (0,1,2,4,8...) ???

enum EPlayerState
{
	NONE = 0,	// for completeness
	IDLE = 1, // << 0, // Player can move
	BLOCKED = 2, // << 1,	// Player can't move
				 //	while dialog is displayed
	AT_ITEM = 4,	// Item is in reach
	AT_NPC = 8,	// NPC in reach
	VISIT_NPC = 16 // << 4	// at NPC; block the move

	// is it possible to do this:
	// VISIT_NPC = BLOCKED | 5;
	// results in 
	// (VISIT_NPC & BLOCKED ) == BLOCKED
};

