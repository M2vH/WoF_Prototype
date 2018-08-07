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
#include "InventoryItems.h"
#include "Npc.h"
#include "AnimObject.h"
#include <SDL_timer.h>
#include "EnumEmotionType.h"
#include "WorldBackground.h"
#include "TextFPS.h"
#include "Game.h"
#pragma endregion

#pragma region public override function
// initialize scene
void GMainScene::Init()
{
	CRenderer* pTheRenderer = CEngine::Get()->GetRenderer();


#pragma region The static background (deactivated)
	//// create a screen background from TexturedObject
	//// ToDo (m2vh) use this for displaying the moon
	//CTexturedObject* pBackground = new CTexturedObject(
	//	SVector2(0, 0),
	//	SVector2(1280, 720),
	//	CEngine::Get()->GetRenderer(),
	//	"Texture/World/T_backg_L2_1280x720.png"
	//);
	//pBackground->SetInWorld(false);

#pragma endregion

#pragma region THE MOON and the STARS
	// create a moveobject as background
	// but keep it static (dont move it)

	GBackgroundStatic* pBackgroundHimmel = new GBackgroundStatic(
		SVector2(0, 0),
		SVector2(1280, 720),
		CEngine::Get()->GetRenderer(),
		"Texture/Background/Himmel/B_Himmel_Zustand4_1280x720.png"
	);
	// set values of object
	pBackgroundHimmel->DeactivateGravity();
	pBackgroundHimmel->SetInWorld(false);
	// pBackgroundStatic->SetSpeed(PLAYER_SPEED / 3);

	// THE MOON
	// create a moveobject as background
	// but keep it static (dont move it)
	GBackgroundStatic* pBackgroundMoon = new GBackgroundStatic(
		SVector2(MOON_POSITION_X, MOON_POSITION_Y),
		SVector2(302, 302),
		CEngine::Get()->GetRenderer(),
		"Texture/Background/Mond/B_Mond_4_720x720.png"
	);
	// set values of object
	pBackgroundHimmel->DeactivateGravity();
	pBackgroundHimmel->SetInWorld(false);
	// pBackgroundStatic->SetSpeed(PLAYER_SPEED / 3);
#pragma endregion

#pragma region ForeGround

	// create a foreground object
	GForegroundSlide* pForeground = new GForegroundSlide(
		SVector2(-3840 / 2, GROUND_POSITION - 55),
		SVector2(3840 * 2, 400),
		CEngine::Get()->GetRenderer(),
		"Texture/Vordergrund/B_Vordergrund_Weg_2560x604.png"
	);
	pForeground->SetInWorld(true);
	pForeground->SetColType(ECollisionType::NONE);
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
	//// the following is working;
	//CTexturedObject* pBackgroundWorld = new CTexturedObject(
	//	SVector2(0, 100),	// pos of object in World
	//	SVector2(3840, 720),	// size; if 0,0 will be set to texture size
	//	CEngine::Get()->GetRenderer(),
	//	"Texture/Background/Wald/B_Wald_3840x720.png"
	//);

	GWorldBackground* pBackgroundWorld = new GWorldBackground(
		SVector2(0, 100),
		SVector2(3840, 720),
		pTheRenderer,
		"Texture/Background/Wald/B_Wald_3840x720.png"
	);

#pragma endregion

#pragma region Player

	// create an array of filePaths
	//	index 0..2	-> IDLE
	//	index 3..5	-> WALK
	//	index 6..8	-> JUMP

	char* playerAnimFileNames[] = {
		"Texture/Protagonist/protag_idle_1.png",
		"Texture/Protagonist/protag_idle_2.png",
		"Texture/Protagonist/protag_idle_3.png",

		"Texture/Protagonist/protag_walk_1.png",
		"Texture/Protagonist/protag_walk_2.png",
		"Texture/Protagonist/protag_walk_3.png",

		"Texture/Protagonist/protag_jump_1.png",
		"Texture/Protagonist/protag_jump_2.png",
		"Texture/Protagonist/protag_jump_3.png"

	};

	//	// add a NOW animated player
	GPlayer * pPlayer = new GPlayer(
		8,
		0.1f,
		SVector2(0, 0),
		SVector2(WORLD_WIDTH / 2, 480 - PLAYER_HEIGHT),	// in the middle of the screen // ToDo (m2vh) adjust player size
		SVector2(PLAYER_WIDTH, PLAYER_HEIGHT),			// 
		CEngine::Get()->GetRenderer(),
		playerAnimFileNames
	);

	// set player values
	// pPlayer->SetSpeed(PLAYER_SPEED);
	pPlayer->SetMirror(PLAYER_MIRROR);
	pPlayer->SetColType(ECollisionType::MOVE);

	pPlayer->ActivateGravity();
#pragma endregion

#pragma region Inventory
	GInventory* m_inventory = new GInventory(SVector2(20, 120),
		SVector2(INVENTORY_WIDTH, INVENTORY_HEIGHT),
		CEngine::Get()->GetRenderer(),
		"Texture/Inventory/item_hub.png");

	pPlayer->SetInventory(m_inventory);
#pragma endregion

#pragma region Text
#pragma region FPS text
	// create fps text
	GTextFPS* pFPSText = new GTextFPS("FPS: 0",
		GGame::Get()->GetPristinaFont(),
		SRect(SCREEN_WIDTH / 2 + 500, 0, 100, 50));

	// add fps text to list
	CEngine::Get()->GetCM()->AddUIObject(pFPSText);
#pragma endregion  

#pragma region Inventory text
	// create inventory text
	CText* pInventoryText = new CText("Inventory",
		GGame::Get()->GetPristinaFont(),
		SRect(20, 80, INVENTORY_WIDTH, 50),
		YELLOW);

	// add inventory text to list
	CEngine::Get()->GetCM()->AddUIObject(pInventoryText);
#pragma endregion
#pragma endregion




#pragma region Animated Object

	//char* FileNames[] = { "Texture/Character/Player/T_Player_idle_1.png",
	//	"Texture/Character/Player/T_Player_idle_2.png",
	//	"Texture/Character/Player/T_Player_idle_1.png"
	//};
	//
	//GAnimObject* pAnimObj = new GAnimObject(
	//	3,
	//	0.5f,
	//	SVector2(0,0),
	//	SVector2(1900, 450),
	//	SVector2(128,64),
	//	CEngine::Get()->GetRenderer(),
	//	FileNames
	//);
#pragma endregion

	// TODO: WTF!!!!
	SDL_Delay(500);

#pragma region NPCs
	// create first NPC of EmoType FURY
	GNpc* pFury = new GNpc(
		EEmotionType::FURY,
		SVector2(2500, GROUND_POSITION - NPC_HEIGHT),
		SVector2(NPC_WIDTH, NPC_HEIGHT),
		pTheRenderer,
		"Texture/NPC/Anger/anger_mask_1.png"
	);

#pragma endregion


#pragma region Ground (to walk on)

	// Add a ground to walk on;
	GBackgroundStatic* pGround = new GBackgroundStatic(
		SVector2(0, GROUND_POSITION), 
		SVector2(3840, 220),
		CEngine::Get()->GetRenderer(),
		//"Texture/World/T_backg_G1_1280x720.png"
		""	// add empty string to create collision object
	);
	pGround->SetColType(ECollisionType::WALL);
	pGround->DeactivateGravity();
	pGround->SetInWorld(true);

#pragma endregion

#pragma region Inventory
	//// create Inventory background
	//GInventory* pInventoryBackground = new GInventory(SVector2(25, SCREEN_HEIGHT *0.25),
	//	SVector2(48 * 2, 48 * 6),
	//	CEngine::Get()->GetRenderer(),
	//	"Texture/Inventory/inventorybackground_496x756.png");

#pragma endregion

#pragma region Items
	// create FuryItem 
	GInventoryItems* pFuryItem = new GInventoryItems(SVector2(900, GROUND_POSITION - ITEM_HEIGHT),
		SVector2(ITEM_WIDTH, ITEM_HEIGHT),
		CEngine::Get()->GetRenderer(),
		"Texture/Item/teddy.png");
	pFuryItem->SetItemType(EEmotionType::FURY);

	// create FearItem 
	GInventoryItems* pFearItem = new GInventoryItems(SVector2(1000, GROUND_POSITION - ITEM_HEIGHT),
		SVector2(ITEM_WIDTH, ITEM_HEIGHT),
		CEngine::Get()->GetRenderer(),
		"Texture/Item/candle.png");
	pFearItem->SetItemType(EEmotionType::FEAR);

	// create SadnessItem 
	GInventoryItems* pSadItem = new GInventoryItems(SVector2(1100, GROUND_POSITION - ITEM_HEIGHT),
		SVector2(ITEM_WIDTH, ITEM_HEIGHT),
		CEngine::Get()->GetRenderer(),
		"Texture/Item/book_1.png");
	pSadItem->SetItemType(EEmotionType::SAD);
#pragma endregion

#pragma region Adding objects to Lists


	//	//	PERSISTANT
	//	THE FOREGROUND
	CEngine::Get()->GetCM()->AddPersistantObject(pForeground);

	// THE GROUND TO WALK ON
	CEngine::Get()->GetCM()->AddPersistantObject(pGround);

	//	The Items
	CEngine::Get()->GetCM()->AddPersistantObject(pFuryItem);
	CEngine::Get()->GetCM()->AddPersistantObject(pFearItem);
	CEngine::Get()->GetCM()->AddPersistantObject(pSadItem);


	// add player to persistant list
	CEngine::Get()->GetCM()->AddPersistantObject(pPlayer);

	// add inventory to UI list
	CEngine::Get()->GetCM()->AddUIObject(m_inventory);

	// add NPCs to persistant list
	CEngine::Get()->GetCM()->AddPersistantObject(pFury);

	// add the anim object
	// CEngine::Get()->GetCM()->AddPersistantObject(pAnimObj);



	//	//	SceneObjects
	//	// The Trees
	//	add worldbackground to SceneObject
	//  first in list, last to be rendered;
	CEngine::Get()->GetCM()->AddSceneObject(pBackgroundWorld);

	// add background to SceneObject-List
	// CEngine::Get()->GetCM()->AddSceneObject(pBackground);

	// Sliding background NOT working
	// CEngine::Get()->GetCM()->AddSceneObject(pBackgroundSlide);


	//	//	The Stars and the sky and the moon
	// adding a moveObject and dont move
	
	// the moon
	CEngine::Get()->GetCM()->AddSceneObject(pBackgroundMoon);
	
	// the stars
	CEngine::Get()->GetCM()->AddSceneObject(pBackgroundHimmel);

#pragma endregion
	// add object to cm
	//CEngine::Get()->GetCM()->AddUIObject(pInventoryBackground);
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

	// clean all objects

}
#pragma endregion