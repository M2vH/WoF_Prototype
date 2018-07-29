#pragma once

/// <summary>
/// collision type enum
/// </summary>
enum ECollisionType
{
	NONE,
	MOVE,	//
	WALL,
	ITEM,
	NPC		
};

/// <summary>
/// emotion type enum
/// </summary>
enum EEmotionType 
{
	FURY,
	FEAR,
	SAD
};

/// <summary>
/// The states a NPC is in.
/// </summary>
enum ENPCState
{
	// NONE,	// = 0,
	VISITED,// = 1, // << 0,
	DONE	//= 1 // << 1
};

/// <summary>
/// The flagged state a Player is in.
/// </summary>
// ToDo (m2vh) Question: Values MUST be base of 2 (0,1,2,4,8...) ???

enum EPlayerState
{
	// NONE = 0,	// for completeness
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

enum EItemState
{
	// NONE = 0,	// for completeness
	ACTIVE = 1, // << 0,
	FOUND = 2, // << 1,
	USED = 4, //1 << 2, // still in inventory list, but invisible
	CONSUMED = 8 // 1 << 3	// -> NPCState::DONE
};

// ToDo (m2vh) Create WorldStates
// an Enum representing the states of escalation
// WorldState should have effect on darkness of background- and foreground-textures