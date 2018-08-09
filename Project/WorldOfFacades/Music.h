#pragma once

#pragma region system include
#include <SDL_mixer.h>
#pragma endregion

/// <summary>
/// class to play music
/// </summary>
class CMusic
{
public:
#pragma region constructor
	/// <summary>
	/// constructor
	/// </summary>
	/// <param name="_pFileName">file path</param>
	CMusic(const char* _pFileName)
	{
		// load music
		m_pMusic = Mix_LoadMUS(_pFileName);
	}

	/// <summary>
	/// destructor
	/// </summary>
	~CMusic()
	{
		// free music
		Mix_FreeMusic(m_pMusic);
	}
#pragma endregion

#pragma region public inline function
	/// <summary>
	/// get volume
	/// </summary>
	/// <returns>volume</returns>
	int GetVolume() { return m_volume; }

	/// <summary>
	/// set volume
	/// </summary>
	/// <param name="_volume">volume to set</param>
	void SetVolume(int _volume)
	{
		m_volume = _volume;
		Mix_VolumeMusic(m_volume);
	}

	/// <summary>
	/// get sdl music
	/// </summary>
	/// <returns>sdl music</returns>
	Mix_Music* GetSDLMusic() { return m_pMusic; }

	/// <summary>
	/// play music
	/// </summary>
	/// <param name="_loop">music is looping</param>
	void Play(bool _loop)
	{
		// int for looping
		// 1 = 1 time
		// -1 = endless
		int loop = 1;

		// if loop
		if (_loop)
			loop = -1;

		// play music
		Mix_PlayMusic(m_pMusic, loop);
	}

	/// <summary>
	/// stop playing music
	/// </summary>
	void Stop()
	{
		// stop music
		Mix_HaltMusic();
	}
#pragma endregion

private:
#pragma region private primitive variable
	/// <summary>
	/// volume of music
	/// </summary>
	int m_volume = 100;
#pragma endregion

#pragma region private variable
	/// <summary>
	/// sdl music
	/// </summary>
	Mix_Music* m_pMusic = nullptr;
#pragma endregion
};