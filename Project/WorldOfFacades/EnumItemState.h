#pragma once

/// <summary>
/// The states an Item is in.
/// </summary>
enum EItemState
{
	ITEM_STATE_NONE = 0,	// for completeness
	ACTIVE = 1, // << 0,	// item is in world
	FOUND = 2, // << 1,		// player has put it in inventory
				// 1 | 2	// player put item elsewhere
	USED = 4, //1 << 2,		// player put item in house
							// still in inventory list, but invisible
	CONSUMED = 8 // 1 << 3	// -> NPCState::DONE
};

