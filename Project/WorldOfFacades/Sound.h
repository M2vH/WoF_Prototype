#pragma once

#pragma region system include
#include <SDL_mixer.h>
#pragma endregion

/// <summary>
/// class to play sound effects
/// </summary>
class CSound
{
public:
#pragma region constructor
	/// <summary>
	/// constructor
	/// </summary>
	/// <param name="_pFileName"></param>
	CSound(const char* _pFileName)
	{
		// load sound
		m_pSound = Mix_LoadWAV(_pFileName);
	}

	/// <summary>
	/// destructor
	/// </summary>
	~CSound()
	{
		// free sound
		Mix_FreeChunk(m_pSound);
	}
#pragma endregion

#pragma region public inline function
	/// <summary>
	/// play sound effect
	/// </summary>
	void Play()
	{
		// play sound
		Mix_PlayChannel(-1, m_pSound, 0);
	}

	/// <summary>
	/// get sdl sound
	/// </summary>
	/// <returns>sdl sound</returns>
	inline Mix_Chunk* GetSDLSound() { return m_pSound; }
#pragma endregion

private:
#pragma region private variable
	/// <summary>
	/// sdl sound
	/// </summary>
	Mix_Chunk* m_pSound = nullptr;
#pragma endregion

};