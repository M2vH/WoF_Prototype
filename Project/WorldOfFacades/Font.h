#pragma once

#pragma region system include
#include <SDL_ttf.h>
#pragma endregion

#pragma region project include
#include "Helper.h"
#pragma endregion

/// <summary>
/// font class
/// </summary>
class CFont
{
public:
#pragma region constructor
	/// <summary>
	/// constructor
	/// </summary>
	/// <param name="_pFileName">file name</param>
	/// <param name="_size">size of font</param>
	CFont(const char* _pFileName, int _size = 12)
	{
		// get asset path
		string file = GetAssetPath(_pFileName, 4);

		// save char* of file name
		m_pFile = file.c_str();

		// open font
		m_pFont = TTF_OpenFont(m_pFile, _size);
	}

	/// <summary>
	/// destructor
	/// </summary>
	~CFont()
	{
		// close font
		TTF_CloseFont(m_pFont);
	}
#pragma endregion

#pragma region public inline function
	/// <summary>
	/// get size of font
	/// </summary>
	/// <returns>size</returns>
	inline int GetSize() { return m_size; }

	/// <summary>
	/// set size of font
	/// </summary>
	/// <param name="_size">size to set</param>
	inline void SetSize(int _size)
	{
		// set size
		m_size = _size;

		// reopen font
		m_pFont = TTF_OpenFont(m_pFile, m_size);
	}

	/// <summary>
	/// get sdl font
	/// </summary>
	/// <returns>sdl font</returns>
	inline TTF_Font* GetFont() { return m_pFont; }
#pragma endregion

private:
#pragma region private primitive variable
	/// <summary>
	/// size of font
	/// </summary>
	int m_size;

	/// <summary>
	/// file name of font
	/// </summary>
	const char* m_pFile;
#pragma endregion

#pragma region private variable
	/// <summary>
	/// sdl font
	/// </summary>
	TTF_Font* m_pFont;
#pragma endregion
};