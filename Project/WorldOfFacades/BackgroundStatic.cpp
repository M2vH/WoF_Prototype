#include <iostream>	///TODO: DELETE
#include <string>	///TODO: DELETE

#include "BackgroundStatic.h"
#include "Input.h"
#include "Macro.h"
#include "Engine.h"



GBackgroundStatic::~GBackgroundStatic()
{
}

void GBackgroundStatic::Update(float _deltaTime)
{
#pragma region using Input
	//// movement left
	//if (CInput::GetKey(SDL_SCANCODE_A))
	//{
	//	// set movement and mirror
	//	m_movement.X = 1.0f;
	//	// ToDo: delete
	//	// m_mirror.X = 1.0f;
	//}

	//// movement right
	//else if (CInput::GetKey(SDL_SCANCODE_D))
	//{
	//	// set movemenet and mirror
	//	m_movement.X = -1.0f;
	//	// m_mirror.X = 0.0f;
	//}

	//// no movement left or right
	//else
	//	m_movement.X = 0.0f;

	//m_position = m_position + m_movement * m_speed * _deltaTime;

	//// set position of rect
	//m_rect.x = m_position.X;
	//m_rect.y = m_position.Y;

	
#pragma endregion

 

	CMoveObject::Update(_deltaTime);
}

void GBackgroundStatic::Render(CRenderer * _pRenderer)
{
	CMoveObject::Render(_pRenderer);
}
