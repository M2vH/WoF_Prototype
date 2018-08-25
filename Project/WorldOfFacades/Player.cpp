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
#include "Sound.h"
#include "HouseScene.h"
#include "Npc.h"
#include "MainScene.h"
#include "HouseBackground.h"
#include "EnumItemState.h"

#pragma endregion


GPlayer* GPlayer::s_instance = nullptr;

#pragma region public override function
// update every frame
void GPlayer::Update(float _deltaTime)
{
	// ToDo!
	//// pick up item


	if (m_isInHouse)
	{
		// INPUT "1"
		if (CInput::GetKeyDown(SDL_SCANCODE_1))
		{
			// is item in inventory?
			if (CheckForItem(EEmotionType::FURY))
			{
				// yes -> 
				//	set item state in background;
				m_ptheHouseBackground->GetFuryItem()->SetItemState(EItemState::USED);
				//	remove from inventory;
				m_inventory->RemoveObjectItem(EEmotionType::FURY);

				m_pPickupItemSound->Play();
			}
		}
		// INPUT "2"
		if (CInput::GetKeyDown(SDL_SCANCODE_2))
		{
			// is item in inventory?
			if (CheckForItem(EEmotionType::FEAR))
			{
				// yes -> 
				//	set item state in background;
				m_ptheHouseBackground->GetFearItem()->SetItemState(EItemState::USED);
				//	remove from inventory;
				m_inventory->RemoveObjectItem(EEmotionType::FEAR);

				m_pPickupItemSound->Play();
			}
		}
		// INPUT "3"
		if (CInput::GetKeyDown(SDL_SCANCODE_3))
		{
			// is item in inventory?
			if (CheckForItem(EEmotionType::SAD))
			{
				// yes -> 
				//	set item state in background;
				m_ptheHouseBackground->GetSadnessItem()->SetItemState(EItemState::USED);
				//	remove from inventory;
				m_inventory->RemoveObjectItem(EEmotionType::SAD);

				m_pPickupItemSound->Play();
			}
		}

	}

	if (CInput::GetKeyDown(SDL_SCANCODE_S) && m_foundItem == true)
	{

		if (m_inventoryItem->GetItemState() == EItemState::USED ||
			m_inventoryItem->GetItemState() == EItemState::ACTIVE)
		{

			LOG_MESSAGE("Grab Item ", std::to_string(m_foundItem));
			m_inventory->RemoveObjectItem(m_inventoryItem->GetItemType());
			m_inventory->AddObject(m_inventoryItem->GetItemType());

			// delete item from list
			// CEngine::Get()->GetCM()->RemoveObject(m_inventoryItem);
			// make item invisible
			m_inventoryItem->SetItemState(EItemState::FOUND);

			// play pickup item sound
			m_pPickupItemSound->Play();

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

	}

	//TODO (m2vh) NPC state!
	// talk to NPC
	if (m_npcCollision == true)
	{
		// CLOSE the dialog
		if (CInput::GetKeyDown(SDL_SCANCODE_E))
		{
			// player visits the first time
			if (m_pNPC->GetNPCState() == ENPCState::WAITING)
			{
				// activate item
				m_pNPC->GetItem()->SetItemState(EItemState::ACTIVE);
				// return;
			}
			
			// close dialog
			m_pNPC->GetDialog()->SetRenderDisplay(false);
			m_pNPC->SetNPCState(
				(ENPCState)(m_pNPC->GetNPCState() << 1)
			);

			// make player moce again; m_isMovable = true;
			m_canMove = true;


		}

		// OPEN dialog
		if (CInput::GetKeyDown(SDL_SCANCODE_W))
		{
			//LOG_MESSAGE(
			//	"Talk to NPC ",
			//	std::to_string((int)(GetNPC()->GetNPCType()))
			//);

			// show the dialog
			m_pNPC->GetDialog()->SetRenderDisplay(true);

			// Player stops while talking to NPC;
			// m_isMovable = false;
			m_canMove = false;

		}


	}


	// // ToDo (m2vh) close TextDialog
	// stop talking to NPC
	// if Key == "R" &&  
	// put TextDialog object into RemoveList;
	// shift NPC into next state (???)
	// set NPC state to ISVISITED
	// set m_isMovable = true;

	// go into house and change scene
	if (m_houseCollision == true && CInput::GetKeyDown(SDL_SCANCODE_W))
	{
		LOG_MESSAGE("Change to GHouseScene", std::to_string(m_houseCollision));
		// change to houseScene
		CEngine::Get()->ChangeScene(new GHouseScene());
	}

	// if player is in house and on the far right of the screen and press W
	// he can switch back to main scene
	if (m_isInHouse &&
		m_position.X > SCREEN_WIDTH - PLAYER_INHOUSE_MARGIN - (PLAYER_WIDTH * 2) &&
		CInput::GetKeyDown(SDL_SCANCODE_W))
	{
		// change to mainScene
		CEngine::Get()->ChangeScene(new GMainScene());
	}

	// TODO!
	// change camera position if player 'bool inHouse = true;'
	// set position of camera
	SVector2 camPosition;

	// if inHouse
	if (m_isInHouse)
	{
		// set camera fix SCREEN_WIDTH /2 and SCREEN_HEIGHT / 2
		// camposition.x
		camPosition.X = SCREEN_WIDTH / 2;

		// camposition.y
		camPosition.Y = SCREEN_HEIGHT / 2;
	}
	// else
	else
	{
		camPosition.X = m_position.X + PLAYER_WIDTH / 2;
		// camPosition.Y = m_position.Y - PLAYER_HEIGHT / 2;

		camPosition.Y = m_position.Y - CAMERA_OFFSET_Y + PLAYER_HEIGHT / 2;
	}

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


#pragma region movement

	if (m_isMovable && m_canMove)
	{
		// moveable default true
		bool moveable = true;

		// check if we are not jumping
		if ((GetAnimState() & EAnimState::STATE_ANIM_JUMP) != STATE_ANIM_JUMP)
		{
			SetAnimState(EAnimState::STATE_ANIM_IDLE);
			SetAnimSpeed(m_pAnimIdleSpeed);
		}


		// movement left
		if (CInput::GetKey(SDL_SCANCODE_A))
		{
			// set movement and mirror
			m_movement.X = -1.0f;
			m_mirror.X = 1.0f;

			SetAnimState(EAnimState::STATE_ANIM_MOVE);
			SetAnimSpeed(m_pAnimMoveSpeed);
		}

		// movement right
		else if (CInput::GetKey(SDL_SCANCODE_D))
		{
			// set movemenet and mirror
			m_movement.X = 1.0f;
			m_mirror.X = 0.0f;

			SetAnimState(EAnimState::STATE_ANIM_MOVE);
			SetAnimSpeed(m_pAnimMoveSpeed);

			// TODO! do we need this?
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

			SetAnimState(EAnimState::STATE_ANIM_JUMP);
			SetAnimSpeed(m_pAnimJumpSpeed);
		}
#pragma endregion

#pragma region JUMP CHECK
		// Doing physics during jump

		// if jump enabled
		if (m_jump)
		{

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

				if (((CTexturedObject*)pObj)->GetColType() >= ECollisionType::ITEM)
				{
					continue;
				}

				// set moveable by checking collision
				moveable = !CPhysic::RectRectCollision(nextRect, ((CTexturedObject*)pObj)->GetRect());

				// if not moveable cancel collision check
				if (!moveable)
					// ToDo (m2vh) JumpAnimation
					// SetAnimState(EAnimState::STATE_ANIM_JUMP);
				break;
			}

			// if moveable
			if (moveable)
			{
				// we still fly
				// ToDo (m2vh) JumpAnimation
				// SetAnimState(EAnimState::STATE_ANIM_JUMP);

				// through all persistant objects
				for (CObject* pObj : CEngine::Get()->GetCM()->GetPersistantObjects())
				{
					// if current object is self continue
					if ((CMoveObject*)pObj && pObj == this)
						continue;

					// if collision type none
					if (((CTexturedObject*)pObj)->GetColType() == ECollisionType::NONE)
						continue;

					if (((CTexturedObject*)pObj)->GetColType() >= ECollisionType::ITEM)
						continue;


					// set moveable by checking collision
					moveable = !CPhysic::RectRectCollision(nextRect, ((CTexturedObject*)pObj)->GetRect());

					// if not moveable cancel collision check
					if (!moveable)
						//	SetAnimState(EAnimState::STATE_ANIM_IDLE);
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
				// ToDo (m2vh) JumpAnimation
				// SetAnimState(EAnimState::STATE_ANIM_JUMP);

			}

		}

#pragma endregion
	}

	//// ToDo (m2vh) put this into SetAnimState using default values;
	//float animSpeedIdle = 0.5f;
	//float animSpeed = 0.1f;
	//// set the animSpeed of IDLE
	//if (GetAnimState() == STATE_ANIM_MOVE)
	//{
	//	SetAnimSpeed(animSpeed);
	//}
	//else {
	//	SetAnimSpeed(animSpeedIdle);
	//}

	// set found item false
	m_foundItem = false;

	// set found npc false
	m_npcCollision = false;

	// set house collision false
	m_houseCollision = false;

	// update parent
	GAnimObject::Update(_deltaTime);
	//LOG_MESSAGE("Position Y: ", to_string(m_position.Y));
}

// render every frame
void GPlayer::Render(CRenderer * _pRenderer)
{
	GAnimObject::Render(_pRenderer);
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
		m_pNPC = _npc;
	}
}

bool GPlayer::CheckForItem(EEmotionType _type) {
	bool isInInventory = false;
	list<GInventoryItems*> liste = m_inventory->GetItemObjects();
	for (GInventoryItems* _item : liste) {
		if (_item->GetItemType() == _type)
		{
			isInInventory = true;
		}
	};

	return isInInventory;
}

#pragma endregion
