#pragma once

#pragma region forward decleration
struct SDL_Texture;
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

	/// <summary>
	/// set sdl texture
	/// </summary>
	/// <param name="_pTexture">set sdl texture</param>
	inline void SetSDLTexture(SDL_Texture* _pTexture) { m_pTexture = _pTexture; }
#pragma endregion

private:
#pragma region private variable
	/// <summary>
	/// sdl texture
	/// </summary>
	SDL_Texture* m_pTexture;
#pragma endregion
};