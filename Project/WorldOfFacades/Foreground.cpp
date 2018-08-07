#include "Foreground.h"

#include <iostream>	///TODO: DELETE
#include <string>	///TODO: DELETE




GForeground::~GForeground()
{
}

void GForeground::Update(float _deltaTime)
{
	// get the player movement
	SVector2 playerMovement = m_pPlayer->GetMovement() * m_speed * _deltaTime * PLAYER_SPEED;
	
	// get the player Y pos;
	// and add the difference to y pos
	m_position.Y = 
		GROUND_POSITION + 
		GROUND_POSITION - 
		(int)m_pPlayer->GetPosition().Y -
		m_pPlayer->GetRect().h +
		FOREGROUND_MARGIN;
	
	// calc the new position
	// check if out of bounds
	if (m_position.X + playerMovement.X < -(SCREEN_WIDTH / 2) )
	{
		// we are left out of bounds
		// jump to outer right
		m_movement.X = SCREEN_WIDTH / 2;
	}
	else if (m_position.X + playerMovement.X > SCREEN_WIDTH / 2)
	{
		// we are right out of bounds;
		// jump to outer left
		m_movement.X = -(SCREEN_WIDTH / 2);
	}
	else 
	{
		m_movement.X = playerMovement.X;
	}

	// pos.Y is GROUND + Distance of player to ground.
	// player moves up -> foreground moves down;
	// m_position.Y += GROUND_POSITION - (int)m_pPlayer->GetPosition().X + m_pPlayer->GetRect().h;

	// check if player is moveable
	if (m_pPlayer->IsMoveable())
	{
		SetNewPosition(SVector2(m_movement.X,0));
	}
	else {
		SetNewPosition(SVector2(0, 0));
	}

	LOG_MESSAGE("Position Y: ", to_string(m_position.Y));

	m_pLeftFill->SetPosition(SVector2(
		m_pLeftFill->GetPosition().X,
		m_position.Y));

	m_pRightFill->SetPosition(SVector2(
		m_pRightFill->GetPosition().X,
		m_position.Y));

	GWorldBackground::Update(_deltaTime);
	
}

void GForeground::Render(CRenderer * _pRenderer)
{
	GWorldBackground::Render(_pRenderer);
}

#pragma region private inline functions

inline void GForeground::SetNewPosition(SVector2 _movement)
{	
	
	
	// move the texture
	AddPosition(SVector2(_movement.X, 0));
	// adjust the Y coord
	// SetPosition(SVector2(m_position.X, m_position.Y ));
	// move left fill
	m_pLeftFill->AddPosition(SVector2(_movement.X, 0));
	// adjust the y of left fill
	// m_pLeftFill->SetPosition(SVector2(m_pLeftFill->GetPosition().X, GROUND_POSITION ));
	// move right fill
	m_pRightFill->AddPosition(SVector2(_movement.X, 0));
	// adjust the y coord of right fill
	// m_pRightFill->SetPosition(SVector2(m_pRightFill->GetPosition().X, GROUND_POSITION ));
}

#pragma endregion
