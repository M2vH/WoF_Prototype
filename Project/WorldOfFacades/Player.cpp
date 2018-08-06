#include <iostream>	///TODO: DELETE
#include <string>	///TODO: DELETE

#pragma region project include
#include "Player.h"
#include "Input.h"
#include "Engine.h"
#include "ContentManagement.h"
#include "Physic.h"
#include "Renderer.h"
#include "Time.h"	///TODO: DELETE
#include "EnumEmotionType.h"
#include "InventoryItems.h"
#pragma endregion


GPlayer* GPlayer::s_instance = nullptr;

#pragma region public override function
// update every frame
void GPlayer::Update(float _deltaTime)
{
	// ToDo!
	//// pick up item
	if (CInput::GetKeyDown(SDL_SCANCODE_S) && m_foundItem == true)
	{
		LOG_MESSAGE("Grab Item ", std::to_string(m_foundItem));
		m_inventory->RemoveObjectItem(m_inventoryItem->GetItemType());
		m_inventory->AddObject(m_inventoryItem->GetItemType());
		CEngine::Get()->GetCM()->RemoveObject(m_inventoryItem);
		// ToDo:
		// Push Item into Inventory;
		// Put item into RemoveObject-List;
		// Put item into Inventory-List;
		// reset value;
		m_foundItem = false;
		//CEngine::Get()->GetCM()->AddUIObject()


		/*if (m_inventoryItem->GetItemType() == EEmotionType::FURY)
		{

		}*/

	}

	//TODO!
	// talk to NPC
	if (CInput::GetKey(SDL_SCANCODE_E) && m_npcCollision == true)
	{
		LOG_MESSAGE("Talk to NPC ", std::to_string(m_npcCollision));
		// ToDo:
		//movable = false;
		m_isMovable = false;

	}

	// set position of camera
	SVector2 camPosition;
	camPosition.X = m_position.X + PLAYER_WIDTH / 2;
	// camPosition.Y = m_position.Y - PLAYER_HEIGHT / 2;

	camPosition.Y = m_position.Y - CAMERA_OFFSET_Y + PLAYER_HEIGHT / 2;

	CEngine::Get()->GetRenderer()->SetCamera(
		camPosition
	);

	
	// Origin version
	//CEngine::Get()->GetRenderer()->SetCamera(
	//	SVector2(m_position.X + PLAYER_WIDTH / 2, m_position.Y - CAMERA_OFFSET_Y + PLAYER_HEIGHT / 2)
	//);


#pragma region PLAYER_STATE DRAFT
	/*
	PlayerState::IDLE // Default state
	if moveable && moving
		Press A || D
		PlayerState::WALK
		if moveable && jumping
			PlayerState::JUMP
	if !moveable
		PlayerState::IDLE
	*/
#pragma endregion



	if (m_isMovable)
	{
#pragma region movement
		// moveable default true
		bool moveable = true;
		SetAnimState(EAnimState::STATE_ANIM_IDLE);


		// movement left
		if (CInput::GetKey(SDL_SCANCODE_A))
		{
			// set movement and mirror
			m_movement.X = -1.0f;
			m_mirror.X = 1.0f;
			SetAnimState(EAnimState::STATE_ANIM_MOVE);
		}

		// movement right
		else if (CInput::GetKey(SDL_SCANCODE_D))
		{
			// set movemenet and mirror
			m_movement.X = 1.0f;
			m_mirror.X = 0.0f;
			SetAnimState(EAnimState::STATE_ANIM_MOVE);
			GPlayer* test = this;
		}

		// no movement left or right
		else
			m_movement.X = 0.0f;

		// if key space is pressed this frame and jump not active and grounded
		if (CInput::GetKeyDown(SDL_SCANCODE_SPACE) && !m_jump && m_grounded)
		{
			// set jump enable, gravity false and set jump time
			m_jump = true;
			m_jumpTime = PLAYER_JUMP_TIME;
			m_gravity = false;
		}
#pragma endregion

#pragma region JUMP CHECK
		// if jump enabled
		if (m_jump)
		{
			SetAnimState(EAnimState::STATE_ANIM_JUMP);

			// decrease jump time
			m_jumpTime -= _deltaTime;

			// if jump time under 0
			if (m_jumpTime <= 0.0f)
			{
				// deactivate jump and activate gravity
				m_jump = false;
				m_gravity = true;
			}


			// next position
			SVector2 nextPos = m_position;
			nextPos.Y -= PLAYER_JUMP_FORCE * _deltaTime;

			// next rect
			SRect nextRect = m_rect;
			nextRect.x = (int)nextPos.X;
			nextRect.y = (int)nextPos.Y;

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
					SetAnimState(EAnimState::STATE_ANIM_JUMP);
				break;
			}

			// if moveable
			if (moveable)
			{
				// we still fly
				SetAnimState(EAnimState::STATE_ANIM_JUMP);

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
//						SetAnimState(EAnimState::STATE_ANIM_IDLE);
					break;
				}
			}

			// if still moveable set y position
			// player is still jumping
			if (moveable)
			{
				m_position.Y -= PLAYER_JUMP_FORCE * _deltaTime;
				m_rect.y = (int)m_position.Y;

				// set PLAYER_STATE::JUMP
				SetAnimState(EAnimState::STATE_ANIM_JUMP);

			}

		}

#pragma endregion
	}



	// update parent
	GAnimObject::Update(_deltaTime);
}

// render every frame
void GPlayer::Render(CRenderer * _pRenderer)
{
	CMoveObject::Render(_pRenderer);
}


#pragma endregion

#pragma region public functions
void GPlayer::SetInventoryItem(GInventoryItems * _inventoryItem)
{
	if (nullptr == _inventoryItem)
	{
		m_foundItem = false;
	}
	else
	{
		m_foundItem = true;
		m_inventoryItem = _inventoryItem;
	}
}
void GPlayer::SetNPC(GNpc * _npc)
{
	if (nullptr == _npc)
	{
		m_npcCollision = false;
	}
	else
	{
		m_npcCollision = true;
		m_npc = _npc;
	}
}
#pragma endregion
