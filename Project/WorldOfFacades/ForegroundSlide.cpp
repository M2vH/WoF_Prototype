#include <iostream>	///TODO: DELETE
#include <string>	///TODO: DELETE

#pragma region project include
#include "ForegroundSlide.h"
#include "Input.h"
#include "Engine.h"
#include "ContentManagement.h"
#include "Physic.h"
#include "Renderer.h"
#include "Macro.h"

#pragma endregion




GForegroundSlide::~GForegroundSlide()
{
}

void GForegroundSlide::Update(float _deltaTime)
{
	// movement left
	if (CInput::GetKey(SDL_SCANCODE_A))
	{
		// set movement and mirror
		m_movement.X = 1.0f;
		// m_mirror.X = 1.0f;
	}

	// movement right
	else if (CInput::GetKey(SDL_SCANCODE_D))
	{
		// set movemenet and mirror
		m_movement.X = -1.0f;
		//m_mirror.X = 0.0f;
	}

	// no movement left or right
	else
		m_movement.X = 0.0f;

	// update 
	m_position = m_position + (m_movement * m_speed * _deltaTime);
	m_rect.x = m_position.X;
	LOG_MESSAGE("Foreground: ", std::to_string(m_position.X));

	m_position.X = m_rect.x;
	

	//CMoveObject::Update(_deltaTime);
}

void GForegroundSlide::Render(CRenderer * _pRenderer)
{
	CMoveObject::Render(_pRenderer);
}
