#pragma region project include
#include "MainScene.h"
#include "World.h"
#include "ContentManagement.h"
#include "TexturedObjectSlide.h"
#include "BackgroundStatic.h"
#include "Player.h"
#include "Renderer.h"
#include "BackgroundSlide.h"
#include "ForegroundSlide.h"
#include "Inventory.h"
#include "TexturedObject.h"
#include "FuryItem.h"
#include "Npc.h"
#pragma endregion

#pragma region public override function
// initialize scene
void GMainScene::Init()
{
	CRenderer* pTheRenderer = CEngine::Get()->GetRenderer();

	
	// create world
	//m_pWorld = new GWorld(CEngine::Get()->GetRenderer(), "Texture/World/T_WorldSide.png");
	//m_pWorld->Init();

	// create a screen background from TexturedObject
	// ToDo (m2vh) use this for displaying the moon
	CTexturedObject* pBackground = new CTexturedObject(
		SVector2(0,0),
		SVector2(1280, 720),
		CEngine::Get()->GetRenderer(),
		"Texture/World/T_backg_L2_1280x720.png"
	);
	pBackground->SetInWorld(false);

#pragma region BackgroundStatic
	// create a moveobject as background
// but keep it static (dont move it)
	GBackgroundStatic* pBackgroundStatic = new GBackgroundStatic(
		SVector2(0, 0),
		SVector2(1280, 720),
		CEngine::Get()->GetRenderer(),
		"Texture/World/T_backg_L2_1280x720.png"
	);
	// set values of object
	pBackgroundStatic->DeactivateGravity();
	pBackgroundStatic->SetInWorld(false);
	// pBackgroundStatic->SetSpeed(PLAYER_SPEED / 3);

#pragma endregion

#pragma region ForeGround

	// create a foreground object
	GForegroundSlide* pForeground = new GForegroundSlide(
		SVector2(-3840 / 2, 450),
		SVector2(3840 * 2, 400),
		CEngine::Get()->GetRenderer(),
		"Texture/World/T_world_tree_2_3840x720.png"
	);
	pForeground->SetInWorld(true);
	// todo: delete no fx
	// pForeground->SetSpeed(PLAYER_SPEED * 1.2);


#pragma endregion

#pragma region BackgroundSlide (NOT WORKING)

					// ToDo (m2vh) BackgroundSlide
	// create a BackgroundSlide
	// NOT WORKING
	//GBackgroundSlide* pBackgroundSlide = new GBackgroundSlide(
	//	"Texture/World/T_backg_L2_1280x720.png"
	//);

#pragma endregion

#pragma region WorldspaceBackground

	// create a worldspace background
	// as TexturedObject
	CTexturedObject* pBackgroundWorld = new CTexturedObject(
		SVector2(0, 100),	// pos of object in World
		SVector2(3840, 720),	// size; if 0,0 will be set to texture size
		CEngine::Get()->GetRenderer(),
		"Texture/World/T_world_tree_3840x720.png"
	);

#pragma endregion

#pragma region Player
	// add a player
	GPlayer * pPlayer = new GPlayer(
		SVector2(WORLD_WIDTH / 2, WORLD_HEIGHT / 2),	// in the middle of the screen // ToDo (m2vh) adjust player size
		SVector2(PLAYER_WIDTH, PLAYER_HEIGHT),			// 
		CEngine::Get()->GetRenderer(),
		//"Texture/Character/Player/T_Samus_Idle.png"
		//"Texture/Character/Player/A_player_walking.gif"
		"Texture/Character/Player/T_Player_idle_2.png"
	);

	// set player values
	pPlayer->SetSpeed(PLAYER_SPEED);
	pPlayer->SetMirror(PLAYER_MIRROR);
	pPlayer->SetColType(ECollisionType::MOVE);

	pPlayer->ActivateGravity();

#pragma endregion

#pragma region NPCs
	// create first NPC of EmoType FURY
	GNpc* pFury = new GNpc(
		EEmotionType::FURY,
		SVector2(2500, GROUND_POSITION - NPC_HEIGHT),
		SVector2(NPC_WIDTH, NPC_HEIGHT),
		pTheRenderer,
		"Texture/Character/Player/T_Samus_Idle.png"
	);
	
#pragma endregion


#pragma region Ground (to walk on)

	// Add a ground to walk on;
	GBackgroundStatic* pGround = new GBackgroundStatic(
		SVector2(0, GROUND_POSITION),
		SVector2(3840, 220),
		CEngine::Get()->GetRenderer(),
		"Texture/World/T_backg_G1_1280x720.png"
	);
	pGround->SetColType(ECollisionType::WALL);
	pGround->DeactivateGravity();
	pGround->SetInWorld(true);

#pragma endregion

#pragma region Inventory
	// create Inventory background
	GInventory* pInventoryBackground = new GInventory(SVector2(25, SCREEN_HEIGHT *0.25),
		SVector2(48 * 2, 48 * 6),
		CEngine::Get()->GetRenderer(),
		"Texture/Inventory/inventorybackground_496x756.png");

#pragma endregion

#pragma region FuryItem
	// create FuryItem 
	GFuryItem* pFuryItem = new GFuryItem(SVector2(900, 500 - WORLD_BLOCK_HEIGHT),
		SVector2(WORLD_BLOCK_WIDTH, WORLD_BLOCK_HEIGHT),
		CEngine::Get()->GetRenderer(),
		"Texture/Inventory/Fury_500x500.png");

#pragma endregion

#pragma region Adding objects to Lists
					

	//	//	PERSISTANT
	//	THE FOREGROUND
	CEngine::Get()->GetCM()->AddPersistantObject(pForeground);

	// THE GROUND TO WALK ON
	CEngine::Get()->GetCM()->AddPersistantObject(pGround);

	//	The Items
	CEngine::Get()->GetCM()->AddPersistantObject(pFuryItem);

	// add player to persistant list
	CEngine::Get()->GetCM()->AddPersistantObject(pPlayer);

	// add NPCs to persistant list
	CEngine::Get()->GetCM()->AddPersistantObject(pFury);
	
	//	//	SceneObjects
	//	// The Trees
	//	add worldbackground to SceneObject
	//  first in list, last to be rendered;
	CEngine::Get()->GetCM()->AddSceneObject(pBackgroundWorld);

	// add background to SceneObject-List
	// CEngine::Get()->GetCM()->AddSceneObject(pBackground);
	
	// Sliding background NOT working
	// CEngine::Get()->GetCM()->AddSceneObject(pBackgroundSlide);
	
	//	//	The Stars
	// adding a moveObject and dont move
	CEngine::Get()->GetCM()->AddSceneObject(pBackgroundStatic);

#pragma endregion
	// add object to cm
	CEngine::Get()->GetCM()->AddUIObject(pInventoryBackground);
	// CEngine::Get()->GetCM()->AddPersistantObject(pObj);
	
	// create world
	// m_pWorld = new GWorld(CEngine::Get()->GetRenderer(), "Texture/World/T_WorldSide.png");
	// m_pWorld->Init();
}

// cleaning up scene
void GMainScene::Clean()
{
	// delete world
	// delete m_pWorld;
}
#pragma endregion