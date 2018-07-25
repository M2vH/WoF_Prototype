#pragma region project include
#include "Time.h"  
#pragma endregion

#pragma region static variable
int CTime::m_fps = 0;
float CTime::m_deltaTime = 0.0f;
#pragma endregion

#pragma region public function
// update every frame
void CTime::Update()
{
	// time since start application in milliseconds
	clock_t now = clock();

	// difference to last update
	clock_t diff = now - m_lastUpdate;

	// set delta time
	m_deltaTime = diff / (float)CLOCKS_PER_SEC;

	// last update now
	m_lastUpdate = now;

	// increase frames since last time stamp
	m_framesSinceLastTimeStamp++;

	// increase time since last time stamp
	m_timeSinceLastTimeStamp += diff;

	// time since last time stamp more than 1 second
	if (m_timeSinceLastTimeStamp > CLOCKS_PER_SEC)
	{
		// set fps
		m_fps = m_framesSinceLastTimeStamp;

		// reset frames since last time stamp
		m_framesSinceLastTimeStamp = 0;

		// decrease time since last time stamp
		m_timeSinceLastTimeStamp -= CLOCKS_PER_SEC;

		// reset delta time
		m_deltaTime = 0.0f;
	}
}
#pragma endregion