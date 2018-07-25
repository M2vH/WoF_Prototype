#pragma once

#pragma region system include
#include <time.h>
#pragma endregion

/// <summary>
/// time class
/// </summary>
class CTime
{
public:
#pragma region constructor
	/// <summary>
	/// constructor
	/// </summary>
	CTime() {}
#pragma endregion

#pragma region public inline function
	/// <summary>
	/// get fps
	/// </summary>
	/// <returns>frames per second</returns>
	static inline int GetFPS() { return m_fps; }

	/// <summary>
	/// get time since last frame
	/// </summary>
	/// <returns></returns>
	static inline float GetDeltaTime() { return m_deltaTime; }
#pragma endregion

#pragma region public function
	/// <summary>
	/// update every frame
	/// </summary>
	void Update();
#pragma endregion

private:
#pragma region private primitive variable
	/// <summary>
	/// frames per second
	/// </summary>
	static int m_fps;

	/// <summary>
	/// time since last frame in seconds
	/// </summary>
	static float m_deltaTime;

	/// <summary>
	/// frames since last time stamp
	/// </summary>
	int m_framesSinceLastTimeStamp;

	/// <summary>
	/// last updated time point
	/// </summary>
	clock_t m_lastUpdate;

	/// <summary>
	/// time since last time stamp
	/// </summary>
	clock_t m_timeSinceLastTimeStamp;
#pragma endregion

};