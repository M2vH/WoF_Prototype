#pragma once

#pragma region project include
#include "Vector2.h"
#pragma endregion

#pragma region forward decleration
class SRect;
class CTexture;
class SDL_Window;
class SDL_Renderer;
#pragma endregion

/// <summary>
/// renderer class
/// </summary>
class CRenderer
{
public:
#pragma region constructor
	/// <summary>
	/// constructor
	/// </summary>
	/// <param name="_pWindow"></param>
	CRenderer(SDL_Window* _pWindow);

	/// <summary>
	/// destructor
	/// </summary>
	~CRenderer();
#pragma endregion

#pragma region public inline function
	/// <summary>
	/// get sdl renderer
	/// </summary>
	/// <returns>sdl renderer</returns>
	inline SDL_Renderer* GetSDLRenderer() { return m_pRenderer; }

	/// <summary>
	/// set position of camera
	/// </summary>
	/// <param name="_pos">position to set</param>
	inline void SetCamera(SVector2 _pos) { m_camera = _pos; }
#pragma endregion

#pragma region public function
	/// <summary>
	/// clear current screen
	/// </summary>
	void ClearScreen();

	/// <summary>
	/// render texture
	/// </summary>
	/// <param name="_pTexture">texture</param>
	void RenderTexture(CTexture* _pTexture);

	/// <summary>
	/// render texture
	/// </summary>
	/// <param name="_pTexture">texture</param>
	/// <param name="_destRect">destination rect on screen</param>
	/// <param name="_srcRect">source rect from image</param>
	/// <param name="_mirror">mirror value</param>
	/// <param name="_angle">angle of destination rect</param>
	/// <param name="_inWorld">texture rendered in world or not</param>
	void RenderTexture(CTexture* _pTexture, SRect _destRect, SRect _srcRect, 
		SVector2 _mirror = SVector2(), float _angle = 0.0f, bool _inWorld = true);

	/// <summary>
	/// present rendered image
	/// </summary>
	void Present();
#pragma endregion

private:
#pragma region private variable
	/// <summary>
	/// sdl renderer
	/// </summary>
	SDL_Renderer* m_pRenderer = nullptr;

	/// <summary>
	/// camera position
	/// </summary>
	SVector2 m_camera;
#pragma endregion
};