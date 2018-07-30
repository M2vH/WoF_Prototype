#pragma once

/// <summary>
/// The states a NPC is in.
/// </summary>
enum ENPCState
{
	// NONE = 0,
	WAITING = 1 << 0,
	VISITED = 1 << 1,
	DONE = 1 << 2
};

