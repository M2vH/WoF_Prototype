#pragma region project include
#include "Input.h"  
#pragma endregion

// static variable has to be initialized
#pragma region variable
bool CInput::m_keyIsDown[];
bool CInput::m_keyWasDown[];
#pragma endregion

#pragma region public function
// handle sdl event
void CInput::ParseEvent(SDL_Event _event)
{
	// if key is in range set key is down to event type
	if (_event.key.keysym.scancode < 256)
		m_keyIsDown[_event.key.keysym.scancode] = _event.type == SDL_KEYDOWN;
}

// refresh state
void CInput::RefreshState()
{
	// set last frame keys to current
	for (int i = 0; i < 256; i++)
		m_keyWasDown[i] = m_keyIsDown[i];
}

// key is pressed
bool CInput::GetKey(SDL_Scancode _key)
{
	return m_keyIsDown[_key];
}

// key is pressed in current frame
bool CInput::GetKeyDown(SDL_Scancode _key)
{
	return m_keyIsDown[_key] && !m_keyWasDown[_key];
}

bool CInput::GetKeyUp(SDL_Scancode _key)
{
	return !m_keyIsDown[_key] && m_keyWasDown[_key];
}
#pragma endregion