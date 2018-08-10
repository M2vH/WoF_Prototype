#pragma region debug include
#include <iostream>	///TODO: DELETE
#include <string>	///TODO: DELETE
#pragma endregion

#pragma region project include
#include "MoveObject.h"
#include "Engine.h"
#include "ContentManagement.h"
#include "Physic.h"
#include "Player.h"
#pragma endregion

#pragma region public override function
// update every frame
void CMoveObject::Update(float _deltaTime)
{
	if (!m_isMovable)
	{
		return;
	}
	// moveable default true
	//m_foundItem = false;
	bool moveable = true;
	bool itemFound = false;
	bool npcFound = false;

	// next position
	SVector2 nextPos = m_position + m_movement * m_speed * _deltaTime;

	// create next rect out of nextPos to do the collision calc on
	SRect nextRect = m_rect;

	// ToDo (m2vh) create bool hasBorder and check;

	//// set the WORLD_PLAYER_BORDER_LEFT and WORLD_PLAYER_BORDER_RIGHT
	//if (nextPos.X < WORLD_PLAYER_BORDER_LEFT)
	//{
	//	nextPos.X = WORLD_PLAYER_BORDER_LEFT;
	//}

	//if (nextPos.X > WORLD_PLAYER_BORDER_RIGHT)
	//{
	//	nextPos.X = WORLD_PLAYER_BORDER_RIGHT;
	//}


	// if player in mainsceen
	// let the player pos rotate
	// on the left 
	if (nextPos.X < 0)
	{
		// we jump to the right - 1
		// we have pos 0 -> 3839 (3840 pixel)
		nextPos.X = nextPos.X + WORLD_WIDTH - 1;
	}
	// on the right
	if (nextPos.X > WORLD_WIDTH)
	{
		nextPos.X = (float)((int)nextPos.X % WORLD_WIDTH) - 1;
	}

	nextRect.x = (int)nextPos.X;
	nextRect.y = (int)nextPos.Y;

	// else player in housesceen
	// if pos.x <= PLAYER_LEFT_BORDER
	//		pos.x = PLAYER_LEFT_BORDER
	// and same for right border.


	// only CollisionType MOVE check for collisions
	if (ECollisionType::MOVE)
	{
		// through all scene objects
		for (CObject* pObj : CEngine::Get()->GetCM()->GetSceneObjects())
		{
			// if current object is self continue
			if ((CMoveObject*)pObj && pObj == this)
				continue;

			// if collision type none
			// for all objects without any reactions
			if (((CTexturedObject*)pObj)->GetColType() == ECollisionType::NONE)
			{
				continue;

			}
			// or all objects with ECollisionType >= 4 (ITEM)
			// they dont stop the movement
			else if (((CTexturedObject*)pObj)->GetColType() >= ECollisionType::ITEM)
			{
				continue;
			}
			else
				// this are MOVE or WALL types
				// we check for collision
			{

				// set moveable by checking collision
				moveable = !CPhysic::RectRectCollision(nextRect, ((CTexturedObject*)pObj)->GetRect());
			}

			// if not moveable cancel collision check
			if (!moveable)
				break;
		}

		// if moveable
		if (moveable)
		{
			// through all persistant objects
			for (CObject* pObj : CEngine::Get()->GetCM()->GetPersistantObjects())
			{
				
				// if current object is self continue
				if ((CMoveObject*)pObj && pObj == this)
					continue;

				GPlayer* player = dynamic_cast<GPlayer*>(this);
				if (nullptr != player)
				{
					// it is ITEM and in reach
					if (((CTexturedObject*)pObj)->GetColType() == ECollisionType::ITEM && CPhysic::RectRectCollision(nextRect, ((CTexturedObject*)pObj)->GetRect()))
					{
						// LOG_MESSAGE("Item found.", "");
						player->SetInventoryItem((GInventoryItems*)pObj);

						continue;
					}
					else
					{
						if (((CTexturedObject*)pObj)->GetColType() == ECollisionType::ITEM)
						{
							continue;
						}
						else if (((CTexturedObject*)pObj)->GetColType() == ECollisionType::NONE)
						{
							continue;
						}
						else
						{

							// set moveable by checking collision
							moveable = !CPhysic::RectRectCollision(nextRect, ((CTexturedObject*)pObj)->GetRect());

						}
					}
					// It is NPC and in reach
					if (((CTexturedObject*)pObj)->GetColType() == ECollisionType::NPC && CPhysic::RectRectCollision(nextRect, ((CTexturedObject*)pObj)->GetRect()))
					{
						//LOG_MESSAGE("NPC found.", "");
						player->SetNPC((GNpc*)pObj);

						continue;
					}
					else
					{
						if (((CTexturedObject*)pObj)->GetColType() == ECollisionType::NPC)
						{
							continue;
						}
						else if (((CTexturedObject*)pObj)->GetColType() == ECollisionType::NONE)
						{
							continue;
						}
						else
						{

							// set moveable by checking collision
							moveable = !CPhysic::RectRectCollision(nextRect, ((CTexturedObject*)pObj)->GetRect());

						}
					}
				}
				// if not moveable cancel collision check
				if (!moveable)
					break;
			}
		}
	}


	// if moveable
	if (moveable)
	{
		// add position by movement * speed
		m_position = nextPos;

		// set position of rect
		m_rect.x = (int)m_position.X;
		m_rect.y = (int)m_position.Y;
	}

	// if no gravity return
	if (!m_gravity)
		return;

	// set moveable true
	moveable = true;

	// set next rect down
	nextRect = m_rect;

	// set y value
	nextRect.y += (int)(GRAVITY_VALUE * m_fallTime * m_fallTime + 1);

	// through all scene objects
	for (CObject* pObj : CEngine::Get()->GetCM()->GetSceneObjects())
	{
		// if current object is self continue
		if ((CMoveObject*)pObj && pObj == this)
			continue;

		// if collision type none
		if (((CTexturedObject*)pObj)->GetColType() == ECollisionType::NONE)
			continue;

		// set moveable by checking collision
		moveable = !CPhysic::RectRectCollision(nextRect, ((CTexturedObject*)pObj)->GetRect());

		// if not moveable cancel collision check
		if (!moveable)
			break;
	}

	// if moveable
	if (moveable)
	{
		// through all persistant objects
		for (CObject* pObj : CEngine::Get()->GetCM()->GetPersistantObjects())
		{
			// if current object is self continue
			if ((CMoveObject*)pObj && pObj == this)
				continue;

			// if collision type none
			if (((CTexturedObject*)pObj)->GetColType() == ECollisionType::NONE)
				continue;

			// set moveable by checking collision
			moveable = !CPhysic::RectRectCollision(nextRect, ((CTexturedObject*)pObj)->GetRect());

			// if not moveable cancel collision check
			if (!moveable)
				break;
		}
	}

	// if still moveable set y position
	if (moveable)
	{
		m_position.Y += GRAVITY_VALUE * m_fallTime * m_fallTime;
		m_rect.y = (int)m_position.Y;
		m_grounded = false;
		m_fallTime += _deltaTime;
	}

	// gravity active and not moveable
	else
	{
		m_fallTime = 0.001f;
		m_grounded = true;
	}
}

// render every frame
void CMoveObject::Render(CRenderer * _pRenderer)
{
	CTexturedObject::Render(_pRenderer);
}
#pragma endregion