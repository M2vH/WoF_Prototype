#pragma once
#pragma region system include
#include "SDL_rect.h"
#pragma endregion

/// <summary>
/// rect struct
/// </summary>
struct SRect : public SDL_Rect
{
public:
#pragma region constructor
	/// <summary>
	/// constructor
	/// </summary>
	SRect()
	{
		x = 0;
		y = 0;
		w = 0;
		h = 0;
	}

	/// <summary>
	/// constructor
	/// </summary>
	/// <param name="_w">width</param>
	/// <param name="_h">height</param>
	SRect(int _w, int _h)
	{
		x = 0;
		y = 0;
		w = _w;
		h = _h;
	}

	/// <summary>
	/// constructor
	/// </summary>
	/// <param name="_x">position x</param>
	/// <param name="_y">position y</param>
	/// <param name="_w">width</param>
	/// <param name="_h">height</param>
	SRect(int _x, int _y, int _w, int _h)
	{
		x = _x;
		y = _y;
		w = _w;
		h = _h;
	}
#pragma endregion
};