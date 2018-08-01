#pragma once

/// <summary>
/// The states a NPC is in.
/// </summary>
enum ENPCState
{
	// NONE = 0,
	WAITING = 1 << 0,
	ISVISITED = 1 << 1,
	VISITED = 1 << 2,
	DONE = 1 << 3
};

