#pragma once

/// <summary>
/// The states a NPC is in.
/// </summary>
enum ENPCState
{
	NONE = 0,
	VISITED = 1 << 0,
	DONE = 1 << 1
};

