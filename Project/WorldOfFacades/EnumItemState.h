#pragma once

/// <summary>
/// The states an Item is in.
/// </summary>
enum EItemState
{
	//NONE = 0,	// for completeness
	ACTIVE = 1, // << 0,
	FOUND = 2, // << 1,
	USED = 4, //1 << 2, // still in inventory list, but invisible
	CONSUMED = 8 // 1 << 3	// -> NPCState::DONE
};

// ToDo (m2vh) Create WorldStates
// an Enum representing the states of escalation
// WorldState should have effect on darkness of background- and foreground-textures
