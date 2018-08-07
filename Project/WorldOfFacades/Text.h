#pragma once

#pragma region system include
#include <SDL_ttf.h>
#include <SDL_image.h>
#pragma endregion

#pragma region project include
#include "Engine.h"
#include "TexturedObject.h"
#include "Color.h"
#include "Font.h"
#include "Renderer.h"
#pragma endregion

/// <summary>
/// class for text objects
/// </summary>
class CText : public CTexturedObject
{
public:
#pragma region constructor
	/// <summary>
	/// constructor
	/// </summary>
	/// <param name="_pText">text value</param>
	/// <param name="_pFont">font</param>
	/// <param name="_rect">rect</param>
	/// <param name="_color">color</param>
	CText(const char* _pText, CFont* _pFont, SRect _rect = SRect(), SColor _color = SColor())
	{
		// set values
		m_pText = _pText;
		m_pFont = _pFont;
		m_rect = _rect;
		m_color = _color;

		// load text
		Load();
	}

	/// <summary>
	/// destructor
	/// </summary>
	~CText()
	{
		// free surface
		SDL_FreeSurface(m_pSurface);

		// destroy texture
		SDL_DestroyTexture(m_pSDLTexture);
	}
#pragma endregion

#pragma region public override function
	/// <summary>
	/// update every frame
	/// </summary>
	/// <param name="_deltaTime">time since last frame</param>
	void Update(float _deltaTime) override {}

	/// <summary>
	/// render every frame
	/// </summary>
	/// <param name="_pRenderer">renderer</param>
	void Render(CRenderer* _pRenderer) override
	{
		SDL_RenderCopy(_pRenderer->GetSDLRenderer(), m_pSDLTexture, nullptr, &m_rect);
	}
#pragma endregion

#pragma region public inline function
	/// <summary>
	/// get text
	/// </summary>
	/// <returns>text value</returns>
	inline const char* GetText() { return m_pText; }

	/// <summary>
	/// set text
	/// </summary>
	/// <param name="_pText">text value to set</param>
	inline void SetText(const char* _pText)
	{
		m_pText = _pText;
		Load();
	}

	/// <summary>
	/// get color
	/// </summary>
	/// <returns>color</returns>
	inline SColor GetColor() { return m_color; }

	/// <summary>
	/// set color
	/// </summary>
	/// <param name="_color">color to set</param>
	inline void SetColor(SColor _color)
	{
		m_color = _color;
		Load();
	}

	/// <summary>
	/// get font
	/// </summary>
	/// <returns>font</returns>
	inline CFont* GetFont() { return m_pFont; }

	/// <summary>
	/// set font
	/// </summary>
	/// <param name="_pFont">font to set</param>
	inline void SetFont(CFont* _pFont)
	{
		m_pFont = _pFont;
		Load();
	}

	/// <summary>
	/// load text
	/// </summary>
	inline void Load()
	{
		// free surface
		SDL_FreeSurface(m_pSurface);

		// update surface
		m_pSurface = TTF_RenderText_Solid(m_pFont->GetFont(), m_pText, m_color);

		// destroy old texture
		SDL_DestroyTexture(m_pSDLTexture);

		// create texture
		m_pSDLTexture = SDL_CreateTextureFromSurface(CEngine::Get()->GetRenderer()->GetSDLRenderer(), m_pSurface);
	}
#pragma endregion 

protected:
#pragma region protected primitive variable
	/// <summary>
	/// text value
	/// </summary>
	const char* m_pText;
#pragma endregion

#pragma region protected variable
	/// <summary>
	/// color of text
	/// </summary>
	SColor m_color;

	/// <summary>
	/// font
	/// </summary>
	CFont* m_pFont = nullptr;

	/// <summary>
	/// sdl texture
	/// </summary>
	SDL_Texture* m_pSDLTexture;

	/// <summary>
	/// sdl surface
	/// </summary>
	SDL_Surface* m_pSurface = nullptr;
#pragma endregion

};