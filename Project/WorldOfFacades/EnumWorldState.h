#pragma once

/// <summary>
/// the state the world is in;
/// Game starts at WORLD_STATE_4;
/// </summary>
enum EWorldState
{
	WORLD_STATE_NONE = 0,
	WORLD_STATE_1 = 1 << 0,
	WORLD_STATE_2 = 1 << 1,
	WORLD_STATE_3 = 1 << 2,
	WORLD_STATE_4 = 1 << 3,
	WORLD_STATE_5 = 1 << 4,
	WORLD_STATE_6 = 1 << 5,
	WORLD_STATE_7 = 1 << 6

};