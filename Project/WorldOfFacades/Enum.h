#pragma once

/// <summary>
/// collision type enum
/// </summary>
enum ECollisionType
{
	NONE = 0,
	WALL = 1 << 0,
	MOVE = 1 << 1,	//
	ITEM = 1 << 2,
	NPC = 1 << 3,
	DOOR = 1 << 4,	// Collide with door object
	HOUSE = 1 << 5	// Collide with cave object
};

