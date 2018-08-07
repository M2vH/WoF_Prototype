#pragma once

#pragma region system include
#include <SDL.h>
#pragma endregion

/// <summary>
/// color struct
/// </summary>
struct SColor : public SDL_Color
{
#pragma region constructor
	/// <summary>
	/// constructor
	/// </summary>
	SColor() {}

	/// <summary>
	/// constructor
	/// </summary>
	/// <param name="_r">red value</param>
	/// <param name="_g">green value</param>
	/// <param name="_b">blue value</param>
	SColor(Uint8 _r, Uint8 _g, Uint8 _b)
	{
		r = _r;
		g = _g;
		b = _b;
	}

	/// <summary>
	/// constructor
	/// </summary>
	/// <param name="_r">red value</param>
	/// <param name="_g">green value</param>
	/// <param name="_b">blue value</param>
	/// <param name="_a">alpha value</param>
	SColor(Uint8 _r, Uint8 _g, Uint8 _b, Uint8 _a)
	{
		r = _r;
		g = _g;
		b = _b;
		a = _a;
	}
#pragma endregion
};