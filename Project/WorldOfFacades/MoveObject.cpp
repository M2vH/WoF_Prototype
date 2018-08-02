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

	// next rect
	SRect nextRect = m_rect;
	if (nextPos.X < 700)
	{
		nextPos.X = 700;
	}
	nextRect.x = (int)nextPos.X;

	if (nextPos.X > 3000)
	{
		nextPos.X = 3000;
	}

	nextRect.y = (int)nextPos.Y;

	if (ECollisionType::MOVE)
	{
		// through all scene objects
		// ToDo: Copy persistant check
		for (CObject* pObj : CEngine::Get()->GetCM()->GetSceneObjects())
		{
			// if current object is self continue
			if ((CMoveObject*)pObj && pObj == this)
				continue;

			// if collision type none
			if (((CTexturedObject*)pObj)->GetColType() == ECollisionType::NONE)
			{
				continue;

			}
			else
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
						LOG_MESSAGE("Item found.", "");
						player->GetInventory()->AddObject(((GInventoryItems*)pObj)->GetItemType());
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
						LOG_MESSAGE("NPC found.", "");
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