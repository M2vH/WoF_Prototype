#pragma region system include
#include <SDL.h>
#include <SDL_image.h>
#pragma endregion

#pragma region project include
#include "Renderer.h"
#include "Rect.h"
#include "Texture.h"
#include "Engine.h"
#pragma endregion

#pragma region constructor
// constructor
CRenderer::CRenderer(SDL_Window * _pWindow)
{
	// create renderer
	m_pRenderer = SDL_CreateRenderer(
		_pWindow,												// window to render to
		1,														// renderer index
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC	// flags
		);
}
#pragma endregion

// destructor
CRenderer::~CRenderer()
{
	// destroy renderer
	if (m_pRenderer)
		SDL_DestroyRenderer(m_pRenderer);
}

#pragma region public function
// clear current screen
void CRenderer::ClearScreen()
{
	SDL_RenderClear(m_pRenderer);
}

void CRenderer::RenderTexture(CTexture * _pTexture)
{
	RenderTexture(_pTexture, SRect(), SRect());
}

void CRenderer::RenderTexture(CTexture * _pTexture, SRect _destRect, SRect _srcRect, 
	SVector2 _mirror, float _angle, bool _inWorld)
{
	// source rect
	SRect srcRect = _srcRect;

	// if source rect has no width or height
	if (_srcRect.w == 0 || _srcRect.h == 0)
	{
		// get width and height of texture
		SDL_QueryTexture(_pTexture->GetSDLTexture(), nullptr, nullptr, &srcRect.w, &srcRect.h);
	}

	// destination rect
	SRect destRect = _destRect;

	// if destination rect has no width or height
	if (destRect.w == 0 || destRect.h == 0)
	{
		destRect.w = SCREEN_WIDTH;
		destRect.h = SCREEN_HEIGHT;
	}

	// if texture is rendered in world and is not in screen return
	if (_inWorld &&
		(destRect.x >= m_camera.X + SCREEN_WIDTH / 2 + WORLD_BLOCK_WIDTH ||
		destRect.x <= m_camera.X - SCREEN_WIDTH / 2 - WORLD_BLOCK_WIDTH ||
		destRect.y >= m_camera.Y + SCREEN_HEIGHT / 2 + WORLD_BLOCK_HEIGHT ||
		destRect.y <= m_camera.Y - SCREEN_HEIGHT / 2 - WORLD_BLOCK_HEIGHT))
	{
		return;
	}

	// if texture is not in world and not in screen return
	if (!_inWorld &&
		(destRect.x >= SCREEN_WIDTH || destRect.x <= 0 ||
			destRect.y >= SCREEN_HEIGHT || destRect.y <= 0)
		)
	{
		return;
	}

	// if texture is rendered in world
	if (_inWorld)
	{
		// add camera offset to destination rect
		destRect.x -= m_camera.X - SCREEN_WIDTH / 2;
		destRect.y -= m_camera.Y - SCREEN_HEIGHT / 2;
	}

	// create rotation point
	SDL_Point rotationPoint;
	rotationPoint.x = _destRect.w / 2;
	rotationPoint.y = _destRect.h / 2;

	// flip enum
	SDL_RendererFlip flip = SDL_RendererFlip::SDL_FLIP_NONE;
	
	// flip horizontal if mirror x != 0
	if (_mirror.X != 0)
		flip = SDL_RendererFlip::SDL_FLIP_HORIZONTAL;

	// flip vertical if mirror y != 0 and x == 0
	else if (_mirror.X == 0 && _mirror.Y != 0)
		flip = SDL_RendererFlip::SDL_FLIP_VERTICAL;

	// render texture with angle
	SDL_RenderCopyEx(
		m_pRenderer,					// sdl renderer
		_pTexture->GetSDLTexture(),		// sdl texture
		&srcRect,						// source rect
		&destRect,						// destination rect
		_angle,							// angle of image
		&rotationPoint,					// rotation center
		flip							// flags
		);
}

// present rendered image
void CRenderer::Present()
{
	SDL_RenderPresent(m_pRenderer);
}
#pragma endregion