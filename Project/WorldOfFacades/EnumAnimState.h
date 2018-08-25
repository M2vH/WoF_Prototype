#pragma once

enum EAnimState
{
	STATE_ANIM_NONE = 0,
	STATE_ANIM_IDLE = 1 << 0,
	STATE_ANIM_MOVE = 1 << 1,
	STATE_ANIM_JUMP = 1 << 2
};