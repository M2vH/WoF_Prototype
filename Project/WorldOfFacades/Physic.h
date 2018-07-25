#pragma once

#pragma region forward decleration
class SRect;
#pragma endregion

/// <summary>
/// class for physics events
/// </summary>
class CPhysic
{
public:
	/// <summary>
	/// check collision of two rects
	/// </summary>
	/// <param name="_rectOne">rect one</param>
	/// <param name="_rectTwo">rect two</param>
	/// <returns>if rects collide</returns>
	static bool RectRectCollision(SRect _rectOne, SRect _rectTwo);
};