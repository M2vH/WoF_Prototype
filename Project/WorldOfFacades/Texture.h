#pragma once

#pragma region forward decleration
class SDL_Texture;
class CRenderer;
#pragma endregion

/// <summary>
/// texture class
/// </summary>
class CTexture
{
public:
#pragma region constructor
	/// <summary>
	/// costructor
	/// </summary>
	/// <param name="_pFilePath">file name with relative path (from /Build/Assets/)</param>
	/// <param name="_pRenderer">renderer</param>
	CTexture(const char* _pFilePath, CRenderer* _pRenderer);

	/// <summary>
	/// destructor
	/// </summary>
	~CTexture();
#pragma endregion

#pragma region public inline function
	/// <summary>
	/// get sdl texture
	/// </summary>
	/// <returns>sdl texture</returns>
	inline SDL_Texture* GetSDLTexture() { return m_pTexture; }
#pragma endregion

private:
#pragma region private variable
	/// <summary>
	/// sdl texture
	/// </summary>
	SDL_Texture* m_pTexture;
#pragma endregion
};