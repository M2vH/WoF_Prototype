#pragma region project include
#include "Physic.h"
#include "Rect.h"
#pragma endregion

// check collision of two rects
bool CPhysic::RectRectCollision(SRect _rectOne, SRect _rectTwo)
{
	// if first rect x is higher than second rect x + width
	if (_rectOne.x > _rectTwo.x + _rectTwo.w)
		return false;

	// if second rect x is higher than first rect x + width
	if (_rectTwo.x > _rectOne.x + _rectOne.w)
		return false;

	// if first rect y is higher than second rect y + height
	if (_rectOne.y > _rectTwo.y + _rectTwo.h)
		return false;

	// if second rect y is higher than first rect y + height
	if (_rectTwo.y > _rectOne.y + _rectOne.h)
		return false;

	// if collision return true
	return true;

}