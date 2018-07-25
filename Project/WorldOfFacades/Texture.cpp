#pragma region system include
#include <SDL_image.h>
#pragma endregion

#pragma region project include
#include "Texture.h"
#include "Renderer.h"
#include "Helper.h"
#include "Engine.h"
#pragma endregion

#pragma region constructor
// constructor
CTexture::CTexture(const char * _pFilePath, CRenderer * _pRenderer)
{
	// load texture
	m_pTexture = IMG_LoadTexture(
		_pRenderer->GetSDLRenderer(),		// sdl renderer
		GetAssetPath(_pFilePath, 4).c_str()	// absolute path
		);
}

// destructor
CTexture::~CTexture()
{
	// destroy texture
	if (m_pTexture)
		SDL_DestroyTexture(m_pTexture);
}
#pragma endregion