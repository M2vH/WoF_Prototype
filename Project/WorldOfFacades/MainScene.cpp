#pragma region system include
#include <SDL_timer.h>
#pragma endregion


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
#include "EnumEmotionType.h"
#include "WorldBackground.h"
#include "Foreground.h"
#include "TextFPS.h"
#include "Game.h"
#include "Music.h"
#include "Sound.h"
#include "WorldImage.h"
#include "TextBubble.h"
#include "Dialog.h"
#include "DIalogImage.h"
#pragma endregion

	//GWorldStatus* pTheWorldStatus = pTheWorldStatus->Get();
	//CRenderer* pTheRenderer = CEngine::Get()->GetRenderer();
	//CContentManagement* pTheCM = CEngine::Get()->GetCM();

#pragma region public override function
// initialize scene
void GMainScene::Init()
{
	GWorldStatus* pTheWorldStatus;
	pTheWorldStatus = pTheWorldStatus->Get();
	CRenderer* pTheRenderer = CEngine::Get()->GetRenderer();
	CContentManagement* pTheCM = CEngine::Get()->GetCM();

#pragma region The new INIT
	// we set player is NOT in house
	GPlayer* pPlayer = dynamic_cast<GPlayer*>(CEngine::Get()->GetCM()->GetPlayerObjects().front());
	pPlayer->IsNotInHouse();

	// we clear CM Scene List
	pTheCM->CleanScene();

	// we fill CM with status
	list<CObject*> pTheStatus = pTheWorldStatus->GetMainSceneObjects();
	for (CObject* _pObj : pTheStatus) {
		pTheCM->AddSceneObject(_pObj);
	};

	// we fill CM Scene List with Status Scene List

#pragma endregion

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

	//GBackgroundStatic* pBackgroundHimmel = new GBackgroundStatic(
	//	SVector2(0, 0),
	//	SVector2(1280, 720),
	//	CEngine::Get()->GetRenderer(),
	//	"Texture/Background/Himmel/B_Himmel_Zustand4_1280x720.png"
	//);
	//// set values of object
	//pBackgroundHimmel->DeactivateGravity();
	//pBackgroundHimmel->SetInWorld(false);
	// pBackgroundStatic->SetSpeed(PLAYER_SPEED / 3);

	////	//	THE SKY as WorldImage;
	////	create the filePath array;
	//char * skyImages[7] = {
	//	"Texture/Background/Himmel/B_Himmel_Zustand1_1280x720.png",
	//	"Texture/Background/Himmel/B_Himmel_Zustand2_1280x720.png",
	//	"Texture/Background/Himmel/B_Himmel_Zustand3_1280x720.png",
	//	"Texture/Background/Himmel/B_Himmel_Zustand4_1280x720.png",
	//	"Texture/Background/Himmel/B_Himmel_Zustand5_1280x720.png",
	//	"Texture/Background/Himmel/B_Himmel_Zustand6_1280x720.png",
	//	"Texture/Background/Himmel/B_Himmel_Zustand7_1280x720.png"
	//};

	//// create instance of WorldImage;
	//GWorldImage* pWorldImageSky = new GWorldImage(
	//	skyImages,
	//	SVector2(0,0),
	//	SVector2(1280, 720),
	//	pTheRenderer
	//);
	//pWorldImageSky->SetSrcRect(SRect(0, 0, 1280, 720));


	// THE MOON
	// create a moveobject as background
	// but keep it static (dont move it)
	// ToDo (m2vh) delete
	//GBackgroundStatic* pBackgroundMoon = new GBackgroundStatic(
	//	SVector2(MOON_POSITION_X, MOON_POSITION_Y),
	//	SVector2(302, 302),
	//	CEngine::Get()->GetRenderer(),
	//	"Texture/Background/Mond/B_Mond_4_720x720.png"
	//);
	//// set values of object
	//pBackgroundHimmel->DeactivateGravity();
	//pBackgroundHimmel->SetInWorld(false);
	// pBackgroundStatic->SetSpeed(PLAYER_SPEED / 3);
	// (m2vh) enddelete

	////	The Moon as WorldImage
	////	the array of images;
	//char* moonImages[7] = {
	//	"Texture/Background/Mond/B_Mond_Zustand1_302x302.png",
	//	"Texture/Background/Mond/B_Mond_Zustand2_302x302.png",
	//	"Texture/Background/Mond/B_Mond_Zustand3_302x302.png",
	//	"Texture/Background/Mond/B_Mond_Zustand4_302x302.png",
	//	"Texture/Background/Mond/B_Mond_Zustand5_302x302.png",
	//	"Texture/Background/Mond/B_Mond_Zustand6_302x302.png",
	//	"Texture/Background/Mond/B_Mond_Zustand7_302x302.png"
	//};
	//GWorldImage* pWorldImageMoon = new GWorldImage(
	//	moonImages,
	//	SVector2(MOON_POSITION_X, MOON_POSITION_Y),
	//	SVector2(302,302),
	//	pTheRenderer
	//);
	//pWorldImageMoon->SetSrcRect(SRect(0, 0, 302, 302));

#pragma endregion


#pragma region BackgroundSlide (NOT WORKING)

	// ToDo (m2vh) BackgroundSlide
	// create a BackgroundSlide
	// we reuse the foreground with negative speed
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

	//GWorldBackground* pBackgroundWorld = new GWorldBackground(
	//	SVector2(0, -50),
	//	SVector2(3840, 720),
	//	pTheRenderer,
	//	"Texture/Background/Wald/B_Wald_3840x720.png"
	//);

#pragma endregion

//#pragma region Player
//
//	// create an array of filePaths
//	//	index 0..2	-> IDLE
//	//	index 3..5	-> WALK
//	//	index 6..8	-> JUMP
//
//	char* playerAnimFileNames[] = {
//		"Texture/Protagonist/protag_idle_1.png",
//		"Texture/Protagonist/protag_idle_2.png",
//		"Texture/Protagonist/protag_idle_3.png",
//
//		"Texture/Protagonist/protag_walk_1.png",
//		"Texture/Protagonist/protag_walk_2.png",
//		"Texture/Protagonist/protag_walk_3.png",
//
//		"Texture/Protagonist/protag_jump_1.png",
//		"Texture/Protagonist/protag_jump_2.png",
//		"Texture/Protagonist/protag_jump_3.png"
//
//	};
//
//	//	// add a NOW animated player
//	GPlayer* pPlayer = new GPlayer(
//		8,
//		0.15f,
//		SVector2(0, 0),
//		SVector2(WORLD_WIDTH / 2, 478 - PLAYER_HEIGHT),	// X: in the middle of the world Y: will fall till ground
//		SVector2(PLAYER_WIDTH, PLAYER_HEIGHT),			// 
//		CEngine::Get()->GetRenderer(),
//		playerAnimFileNames
//	);
//
//	// set player values
//	// pPlayer->SetSpeed(PLAYER_SPEED);
//	pPlayer->SetMirror(PLAYER_MIRROR);
//	pPlayer->SetColType(ECollisionType::MOVE);
//
//	pPlayer->ActivateGravity();
//
//	// set the Player to be in MainSceen
//	// pPlayer->SetIsAtHouse(false);
//	// pPlayer->IsNotInHouse();
//#pragma endregion

//#pragma region Inventory
//	GInventory* m_inventory = new GInventory(SVector2(20, 120),
//		SVector2(INVENTORY_WIDTH, INVENTORY_HEIGHT),
//		CEngine::Get()->GetRenderer(),
//		"Texture/Inventory/item_hub.png");
//
//	pPlayer->SetInventory(m_inventory);
//#pragma endregion

#pragma region ForeGround

	
	//// create a foreground object
	//// following is working
	//GForegroundSlide* pForeground = new GForegroundSlide(
	//	SVector2(-3840 / 2, GROUND_POSITION - 55),
	//	SVector2(3840 * 2, 400),
	//	CEngine::Get()->GetRenderer(),
	//	"Texture/Vordergrund/B_Vordergrund_Weg_2560x604.png"
	//);
	//pForeground->SetInWorld(true);
	//pForeground->SetColType(ECollisionType::NONE);
	//// todo: delete no fx
	//// pForeground->SetSpeed(PLAYER_SPEED * 1.2);

	/// <summary>
	/// the foreground in front of the player
	/// </summary>
	GForeground* pForeground = new GForeground(
		-2.0f,	// the speed
		SVector2(0, FOREGROUND_POSITION_Y),
		SVector2(1280, 302),
		pTheRenderer,
		"Texture/Vordergrund/B_Vordergrund_Weg_1280x302.png"
	);

#pragma region Walkground

	///// <summary>
	///// is the way, the player is moving on; place it between player and world
	///// </summary>
	//GForeground* pWalkground = new GForeground(
	//	-1.0f,	// is moving with playerspeed on the worldimage in opposite direction
	//	SVector2(0, GROUND_POSITION - WAY_HEIGHT),
	//	SVector2(1280, 170),
	//	pTheRenderer,
	//	"Texture/Background/Wald/B_Hintergrund_Weg_1280x170.png"
	//);
#pragma endregion


#pragma endregion
#pragma region Text
#pragma region FPS text
	// create fps text
	GTextFPS* pFPSText = new GTextFPS("FPS: 0",
		GGame::Get()->GetPristinaFont(),
		SRect(SCREEN_WIDTH / 2 + 500, 0, 100, 50));

	// add fps text to list
	// CEngine::Get()->GetCM()->AddUIObject(pFPSText);
#pragma endregion  

//#pragma region Inventory text
//	// create inventory text
//	CText* pInventoryText = new CText("Inventory",
//		GGame::Get()->GetPristinaFont(),
//		SRect(20, 80, INVENTORY_WIDTH, 50),
//		YELLOW);
//
//	// add inventory text to list
//	CEngine::Get()->GetCM()->AddUIObject(pInventoryText);
//#pragma endregion
#pragma endregion

#pragma region Music
	// create background music
	m_pBackgroundMusic = new CMusic(GetAssetPath("Audio/Moment-of-Strange.mp3", 4).c_str());

	// play music
	m_pBackgroundMusic->Play(true);
#pragma endregion

//#pragma region SoundFX
//	// create pickup item sound
//	CSound* pPickupItemSound = new CSound(GetAssetPath("Audio/Item _pickup.mp3", 4).c_str());
//
//	// set pickup item sound
//	pPlayer->SetPickupItemSound(pPickupItemSound);
//#pragma endregion

#pragma region TextBubble
	// instatiate a bubble
	// // (m2vh) bubbleOnly
	// next is working
	//GTextBubble* m_ptheBubble = new GTextBubble(
	//	SVector2(SCREEN_WIDTH / 2 - 100, SCREEN_HEIGHT / 2 - 100),
	//	SVector2(200,200)
	//);
	//pTheCM->AddUIObject(m_ptheBubble);
	//	// (m2vh) end bubbleOnly

	//	// (m2vh) textBubble
	//GDialog* m_pDialog = new GDialog(
	//	SVector2(DIALOG_POS_X, DIALOG_POS_Y),
	//	SVector2(DIALOG_TEXT_WIDTH, DIALOG_TEXT_HEIGHT),
	//	"This is the text.\n \
	//	The second line."
	//);
	//
	//m_pDialog->SetFont(GGame::Get()->GetPristinaFont());
	//pTheCM->AddUIObject(m_pDialog);
	//	// (m2vh) end textBubble

	//	// (m2vh) DialogImage bubble
	//	the array of text images
	//char* m_textImages[3] = {
	//	"Texture/Text/T_Text_Fear_1_330x85.png",
	//	"Texture/Text/T_Text_Fear_2_330x85.png",
	//	"Texture/Text/T_Text_Fear_3_330x85.png"
	//};
	//// instance of DialogImage
	//GDialogImage* m_pDialogImage = new GDialogImage(
	//	SVector2(DIALOG_POS_X, DIALOG_POS_Y),		// pos
	//	SVector2(330,85),		// size of text
	//	SVector2(32,32),		// margin
	//	m_textImages
	//);
	//// set display value to true
	//m_pDialogImage->SetRenderDisplay(true);
	//// add to UIList
	//pTheCM->AddUIObject(m_pDialogImage);

	//	// (m2vh) end DialogImage bubble
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
	// SDL_Delay(500);

#pragma region NPCs
	// create first NPC of EmoType FURY
	GNpc* pFury = new GNpc(
		EEmotionType::FURY,
		SVector2(3000, GROUND_POSITION - NPC_HEIGHT),	// Position min: 640 max: 3840 - 640 - NPC_WIDTH
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
		"Texture/Background/T_GroundToWalkOn.png"	// add empty string to create collision object
	);
	pGround->SetColType(ECollisionType::WALL);
	pGround->DeactivateGravity();
	pGround->SetInWorld(true);
	pGround->SetSrcRect(SRect(0, 0, 4, 4));

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
	GInventoryItems* pFuryItem = new GInventoryItems(SVector2(1100, GROUND_POSITION - ITEM_HEIGHT),
		SVector2(ITEM_WIDTH, ITEM_HEIGHT),
		CEngine::Get()->GetRenderer(),
		"Texture/Item/teddy.png");
	pFuryItem->SetItemType(EEmotionType::FURY);

	// create FearItem 
	GInventoryItems* pFearItem = new GInventoryItems(SVector2(1200, GROUND_POSITION - ITEM_HEIGHT),
		SVector2(ITEM_WIDTH, ITEM_HEIGHT),
		CEngine::Get()->GetRenderer(),
		"Texture/Item/candle.png");
	pFearItem->SetItemType(EEmotionType::FEAR);

	// create SadnessItem 
	GInventoryItems* pSadItem = new GInventoryItems(SVector2(1300, GROUND_POSITION - ITEM_HEIGHT),
		SVector2(ITEM_WIDTH, ITEM_HEIGHT),
		CEngine::Get()->GetRenderer(),
		"Texture/Item/book_1.png");
	pSadItem->SetItemType(EEmotionType::SAD);
#pragma endregion

//#pragma region THE HOUSE
//	// is a textured object.
//	// must be placed with the 'door';
//	// door is collision type 'DOOR';
//	CTexturedObject* pHouse = new CTexturedObject(
//		SVector2(HOUSE_POS_X,HOUSE_POS_Y),
//		SVector2(HOUSE_WIDTH,HOUSE_HEIGHT),
//		pTheRenderer,
//		"Texture/Haus/B_House_373x296.png"
//	);
//
//	// is inWorld
//	pHouse->SetInWorld(true);
//	// has CollisionType of HOUSE
//	pHouse->SetColType(ECollisionType::HOUSE);
//
//#pragma endregion



#pragma region Adding objects to Lists


	//	//	PERSISTANT
	//	THE FOREGROUND
	// ToDo (m2vh) check performance;
	CEngine::Get()->GetCM()->AddPersistantObject(pForeground);

	// THE GROUND TO WALK ON
	CEngine::Get()->GetCM()->AddPersistantObject(pGround);

	//	The Items
	CEngine::Get()->GetCM()->AddPersistantObject(pFuryItem);
	CEngine::Get()->GetCM()->AddPersistantObject(pFearItem);
	CEngine::Get()->GetCM()->AddPersistantObject(pSadItem);


	//// add player to persistant list
	//CEngine::Get()->GetCM()->AddPlayerObject(pPlayer);

	//// add inventory to UI list
	//CEngine::Get()->GetCM()->AddUIObject(m_inventory);

	// add NPCs to persistant list
	CEngine::Get()->GetCM()->AddPersistantObject(pFury);

	// add the anim object
	// ToDo (m2vh) delete
	// CEngine::Get()->GetCM()->AddPersistantObject(pAnimObj);



	//	//	SceneObjects
	//	// The House
	//	add pHouse
	//CEngine::Get()->GetCM()->AddSceneObject(pHouse);
	//	// The Way 
	//	add pWalkground
	// ToDo (m2vh) check walkground performance
	//CEngine::Get()->GetCM()->AddSceneObject(pWalkground);
	//	// The Trees
	//	add worldbackground to SceneObject
	//  first in list, last to be rendered;
	//CEngine::Get()->GetCM()->AddSceneObject(pBackgroundWorld);

	// add background to SceneObject-List
	// CEngine::Get()->GetCM()->AddSceneObject(pBackground);

	// Sliding background NOT working
	// CEngine::Get()->GetCM()->AddSceneObject(pBackgroundSlide);


	//	//	The Stars and the sky and the moon
	// adding a moveObject and dont move
	
	// the moon
	//	as backgroundImage
	//	CEngine::Get()->GetCM()->AddSceneObject(pBackgroundMoon);
	//	as worldImage
	//CEngine::Get()->GetCM()->AddSceneObject(pWorldImageMoon);
	

	
	////	// last to list, first to render
	////	// will be in the background
	//// the stars
	//// CEngine::Get()->GetCM()->AddSceneObject(pBackgroundHimmel);
	//pTheCM->AddSceneObject(pWorldImageSky);

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
	
	GWorldStatus* pTheWorldStatus;
	pTheWorldStatus = pTheWorldStatus->Get();
//	CRenderer* pTheRenderer = CEngine::Get()->GetRenderer();
	CContentManagement* pTheCM = CEngine::Get()->GetCM();

	// delete world
	// delete m_pWorld;

	// clean all objects

	// delete music
	delete m_pBackgroundMusic;

	// clean all objects
	//	// will be done by init
	// CEngine::Get()->GetCM()->CleanScene();
	//	// we need to copy into status
	pTheWorldStatus->CleanMainSceneObjects();

	pTheWorldStatus->Refresh();

	for (CObject* _pObj : pTheCM->GetSceneObjects()) {
		pTheWorldStatus->AddMainSceneObject(_pObj);
	}

	
	// TODO! Do not delete persistent object list
	// clean PersistentObjects 
	CEngine::Get()->GetCM()->CleanPersistantObjects();
}
#pragma endregion