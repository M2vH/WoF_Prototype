#pragma region project include
#include "Game.h"
#include "Engine.h"
#include "MainScene.h"
#include "Font.h"
#include "WorldStatus.h"
#include "HouseScene.h"  // TODO! delete
#include "Player.h"
#include "ContentManagement.h"
#include "Sound.h"
#include "WorldImage.h"
#include "WorldBackground.h"
#include "Foreground.h"
#include "Text.h"
#include "DIalogImage.h"
#include "Npc.h"
#include "HouseBackground.h"
#pragma endregion

//CRenderer* pTheRenderer = CEngine::Get()->GetRenderer();


#pragma region public function
// initialize game
void GGame::Init()
{
	CRenderer* pTheRenderer = CEngine::Get()->GetRenderer();

	
	// initialize the world status
	m_pWorldStatus = m_pWorldStatus->Get();
	//	// ToDo (m2vh) Delete before release
	//m_pWorldStatus->SetState((EWorldState)(m_pWorldStatus->GetState()<< 3));
	LOG_MESSAGE("State of the world" , m_pWorldStatus->GetState());

	// create base gigi font
	m_pGigiFont = new CFont("Font/GIGI.ttf", 50);

	// create base gigi font
	m_pPristinaFont = new CFont("Font/PRISTINA.ttf", 50);

	//	// Content from MainScen::Init()
	//	The Player and UI content;
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
	GPlayer* pPlayer = new GPlayer(
		8,
		0.15f,
		SVector2(0, 0),
		SVector2(WORLD_WIDTH / 2, 478 - PLAYER_HEIGHT),	// X: in the middle of the world Y: will fall till ground
		SVector2(PLAYER_WIDTH, PLAYER_HEIGHT),			// 
		CEngine::Get()->GetRenderer(),
		playerAnimFileNames
	);

	// set player values
	// pPlayer->SetSpeed(PLAYER_SPEED);
	pPlayer->SetMirror(PLAYER_MIRROR);
	pPlayer->SetColType(ECollisionType::MOVE);

	pPlayer->ActivateGravity();

	// set the Player to be in MainSceen
	// pPlayer->SetIsAtHouse(false);
	// pPlayer->IsNotInHouse();

	// add player to persistant list
	CEngine::Get()->GetCM()->AddPlayerObject(pPlayer);

#pragma endregion
#pragma region Inventory
	GInventory* m_inventory = new GInventory(SVector2(20, 120),
		SVector2(INVENTORY_WIDTH, INVENTORY_HEIGHT),
		CEngine::Get()->GetRenderer(),
		"Texture/Inventory/item_hub.png");

	pPlayer->SetInventory(m_inventory);

	// add inventory to UI list
	CEngine::Get()->GetCM()->AddUIObject(m_inventory);

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
#pragma region the text bubble
	char* m_textImages[3] = {
		"Texture/Text/T_Text_Fury_1_330x85.png",
		"Texture/Text/T_Text_Fury_2_330x85.png",
		"Texture/Text/T_Text_Fury_3_330x85.png"
	};
	// instance of DialogImage
	GDialogImage* m_pDialogFury = new GDialogImage(
		SVector2(DIALOG_POS_X, DIALOG_POS_Y),		// pos
		SVector2(330, 85),		// size of text
		SVector2(32, 32),		// margin
		m_textImages
	);


	char* m_textImagesFear[3] = {
		"Texture/Text/T_Text_Fear_1_330x85.png",
		"Texture/Text/T_Text_Fear_2_330x85.png",
		"Texture/Text/T_Text_Fear_3_330x85.png"
	};
	// instance of DialogImage
	GDialogImage* m_pDialogFear = new GDialogImage(
		SVector2(DIALOG_POS_X, DIALOG_POS_Y),		// pos
		SVector2(330, 85),		// size of text
		SVector2(32, 32),		// margin
		m_textImagesFear
	);


	char* m_textImagesSad[3] = {
		"Texture/Text/T_Text_Sadness_1_330x85.png",
		"Texture/Text/T_Text_Sadness_2_330x85.png",
		"Texture/Text/T_Text_Sadness_3_330x85.png"
	};
	// instance of DialogImage
	GDialogImage* m_pDialogSad = new GDialogImage(
		SVector2(DIALOG_POS_X, DIALOG_POS_Y),		// pos
		SVector2(330, 85),		// size of text
		SVector2(32, 32),		// margin
		m_textImagesSad
	);
	// set display value to true
	// m_pDialogImage->SetRenderDisplay(true);
	// add to UIList
	// CEngine::Get()->GetCM()->AddUIObject(m_pDialogImage);

#pragma endregion


#pragma region SoundFX
	// create pickup item sound
	CSound* pPickupItemSound = new CSound(GetAssetPath("Audio/Item _pickup.mp3", 4).c_str());

	// set pickup item sound
	pPlayer->SetPickupItemSound(pPickupItemSound);
#pragma endregion

#pragma region create SCENE OBJECTS for Main Scene
	
#pragma region THE HOUSE
	//	// THE HOUSE
	// is a textured object.
	// must be placed with the 'door';
	// door is collision type 'DOOR';
	CTexturedObject* pHouse = new CTexturedObject(
		SVector2(HOUSE_POS_X, HOUSE_POS_Y),
		SVector2(HOUSE_WIDTH, HOUSE_HEIGHT),
		pTheRenderer,
		"Texture/Haus/B_House_373x296.png"
	);

	// is inWorld
	pHouse->SetInWorld(true);
	// has CollisionType of HOUSE
	pHouse->SetColType(ECollisionType::HOUSE);


#pragma endregion
	// add pWalkground
#pragma region Walkground

	/// <summary>
	/// is the way, the player is moving on; place it between player and world
	/// </summary>
	GForeground* pWalkground = new GForeground(
		-1.0f,	// is moving with playerspeed on the worldimage in opposite direction
		SVector2(0, GROUND_POSITION - WAY_HEIGHT),
		SVector2(1280, 170),
		pTheRenderer,
		"Texture/Background/Wald/B_Hintergrund_Weg_1280x170.png"
	);

#pragma endregion

	// add pBackgroundWorld
	GWorldBackground* pBackgroundWorld = new GWorldBackground(
		SVector2(0, -50),
		SVector2(3840, 720),
		pTheRenderer,
		"Texture/Background/Wald/B_Wald_3840x720.png"
	);

	//	// THE MOON
	//	The Moon as WorldImage
	//	the array of images;
	char* moonImages[7] = {
		"Texture/Background/Mond/B_Mond_Zustand1_302x302.png",
		"Texture/Background/Mond/B_Mond_Zustand2_302x302.png",
		"Texture/Background/Mond/B_Mond_Zustand3_302x302.png",
		"Texture/Background/Mond/B_Mond_Zustand4_302x302.png",
		"Texture/Background/Mond/B_Mond_Zustand5_302x302.png",
		"Texture/Background/Mond/B_Mond_Zustand6_302x302.png",
		"Texture/Background/Mond/B_Mond_Zustand7_302x302.png"
	};
	GWorldImage* pWorldImageMoon = new GWorldImage(
		moonImages,
		SVector2(MOON_POSITION_X, MOON_POSITION_Y),
		SVector2(302, 302),
		pTheRenderer
	);
	pWorldImageMoon->SetSrcRect(SRect(0, 0, 302, 302));

	


	//	//	THE SKY as WorldImage;
	//	create the filePath array;
	char * skyImages[7] = {
		"Texture/Background/Himmel/B_Himmel_Zustand1_1280x720.png",
		"Texture/Background/Himmel/B_Himmel_Zustand2_1280x720.png",
		"Texture/Background/Himmel/B_Himmel_Zustand3_1280x720.png",
		"Texture/Background/Himmel/B_Himmel_Zustand4_1280x720.png",
		"Texture/Background/Himmel/B_Himmel_Zustand5_1280x720.png",
		"Texture/Background/Himmel/B_Himmel_Zustand6_1280x720.png",
		"Texture/Background/Himmel/B_Himmel_Zustand7_1280x720.png"
	};

	// create instance of WorldImage;
	GWorldImage* pWorldImageSky = new GWorldImage(
		skyImages,
		SVector2(0, 0),
		SVector2(1280, 720),
		pTheRenderer
	);
	pWorldImageSky->SetSrcRect(SRect(0, 0, 1280, 720));

	// copy them into WorldStatus list
	//	// last to list, first to render
	//	// will be in the background
	// the stars
	// CEngine::Get()->GetCM()->AddSceneObject(pBackgroundHimmel);

	m_pWorldStatus->AddMainSceneObject(pWorldImageSky);
	m_pWorldStatus->AddMainSceneObject(pWorldImageMoon);
	m_pWorldStatus->AddMainSceneObject(pBackgroundWorld);
	m_pWorldStatus->AddMainSceneObject(pWalkground);
	m_pWorldStatus->AddMainSceneObject(pHouse);

#pragma endregion

#pragma region create PERSISTANT OBJECTS for MainScene
	//	// create the persistant objects
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

	// // create first NPC of EmoType FURY
	GNpc* pFury = new GNpc(
		EEmotionType::FURY,
		SVector2(3500, GROUND_POSITION - NPC_HEIGHT),	// Position min: 640 max: 3840 - 640 - NPC_WIDTH
		SVector2(NPC_WIDTH, NPC_HEIGHT),
		pTheRenderer,
		"Texture/NPC/Anger/anger_mask_1.png"
	);

	// set the NPC dialog
	pFury->SetDialog(m_pDialogFury);

	// create second NPC FEAR
	GNpc* pFear = new GNpc(
		EEmotionType::FEAR,
		SVector2(3000, GROUND_POSITION - NPC_HEIGHT),	// Position min: 640 max: 3840 - 640 - NPC_WIDTH
		SVector2(NPC_WIDTH, NPC_HEIGHT),
		pTheRenderer,
		"Texture/NPC/Fear/Fear_mask_1.png"
	);

	// set the NPC dialog
	pFear->SetDialog(m_pDialogFear);

	// create third NPC SADNESS
	GNpc* pSadness = new GNpc(
		EEmotionType::SAD,
		SVector2(2500, GROUND_POSITION - NPC_HEIGHT),	// Position min: 640 max: 3840 - 640 - NPC_WIDTH
		SVector2(NPC_WIDTH, NPC_HEIGHT),
		pTheRenderer,
		"Texture/NPC/Sadness/sadness_mask_1.png"
	);

	// set the NPC dialog
	pSadness->SetDialog(m_pDialogSad);


	//	// Add a ground to walk on;
	GBackgroundStatic* pGround = new GBackgroundStatic(
		SVector2(0, GROUND_POSITION),
		SVector2(3840, 220),
		CEngine::Get()->GetRenderer(),
		"Texture/Background/T_GroundToWalkOn.png"	
	);
	pGround->SetColType(ECollisionType::WALL);
	pGround->DeactivateGravity();
	pGround->SetInWorld(true);
	pGround->SetSrcRect(SRect(0, 0, 4, 4));

#pragma region Items
	//	ToDo (m2vh) Evolve the items
	//	// add an item as member to NPC.class
		// add isVisible param to item.class;
		// let NPC control visibility of his item
	
	// create FuryItem 
	GInventoryItems* pFuryItem = new GInventoryItems(SVector2(1300, GROUND_POSITION - ITEM_HEIGHT),
		SVector2(ITEM_WIDTH, ITEM_HEIGHT),
		CEngine::Get()->GetRenderer(),
		"Texture/Item/teddy.png"
	);
	pFuryItem->SetItemType(EEmotionType::FURY);

	// set item invisible
	pFuryItem->SetItemState(EItemState::ITEM_STATE_NONE);

	pFury->SetItem(pFuryItem);

	// create FearItem 
	GInventoryItems* pFearItem = new GInventoryItems(SVector2(1650, GROUND_POSITION - ITEM_HEIGHT),
		SVector2(ITEM_WIDTH, ITEM_HEIGHT),
		CEngine::Get()->GetRenderer(),
		"Texture/Item/candle.png"
	);
	pFearItem->SetItemType(EEmotionType::FEAR);
	// set item invisible
	pFearItem->SetItemState(EItemState::ITEM_STATE_NONE);

	pFear->SetItem(pFearItem);

	// create SadnessItem 
	GInventoryItems* pSadItem = new GInventoryItems(SVector2(2000, GROUND_POSITION - ITEM_HEIGHT),
		SVector2(ITEM_WIDTH, ITEM_HEIGHT),
		CEngine::Get()->GetRenderer(),
		"Texture/Item/book_1.png"
	);
	pSadItem->SetItemType(EEmotionType::SAD);
	// set item invisible
	pSadItem->SetItemState(EItemState::ITEM_STATE_NONE);

	pSadness->SetItem(pSadItem);
#pragma endregion


	//	// add objects to WorldStaus list
	m_pWorldStatus->AddMainPersistObject(pFury);
	m_pWorldStatus->AddMainPersistObject(pFear);
	m_pWorldStatus->AddMainPersistObject(pSadness);
	// the items
	m_pWorldStatus->AddMainPersistObject(pSadItem);
	m_pWorldStatus->AddMainPersistObject(pFearItem);
	m_pWorldStatus->AddMainPersistObject(pFuryItem);
	// m_pWorldStatus->AddMainPersistObject(pGround);
	m_pWorldStatus->AddMainSceneObject(pGround);
	m_pWorldStatus->AddMainPersistObject(pForeground);


#pragma endregion

#pragma region the HOUSE SCENE
	//	// the Scene objects
	//	The background
		// instantiate object

	//	// (m2vh) DELETE 
	//	next is working
	//GBackgroundStatic* pBackgroundInHouse = new GBackgroundStatic(
	//	SVector2(0, 0),
	//	SVector2(1280, 720),
	//	CEngine::Get()->GetRenderer(),
	//	"Texture/Haus/Innen/B_Huette_Start_1280x720.png"
	//);

	//	// set values of object
	//pBackgroundInHouse->DeactivateGravity();
	//pBackgroundInHouse->SetInWorld(false);
	//	// (m2vh) DELETE

	char* theHouseImages[8] = {
		"Texture/Haus/Innen/B_Huette_0_normal_1280x720.png",
		"Texture/Haus/Innen/B_Huette_4_Teddy_1280x720.png", 
		"Texture/Haus/Innen/B_Huette_1_Kerze_1280x720.png", 
		"Texture/Haus/Innen/B_Huette_5_TeddyKerze_1280x720.png", 
		"Texture/Haus/Innen/B_Huette_2_Buch_1280x720.png", 
		"Texture/Haus/Innen/B_Huette_6_TeddyBuch_1280x720.png", 
		"Texture/Haus/Innen/B_Huette_3_KerzeBuch_1280x720.png", 
		"Texture/Haus/Innen/B_Huette_7_AlleItems_1280x720.png"
	};
	GHouseBackground* pHouseBackground = new GHouseBackground(
		SVector2(0,0),
		SVector2(1280,720),
		pTheRenderer,
		theHouseImages
	);

	GInventoryItems* m_pHouseItemFury = new GInventoryItems(
		SVector2(HOUSE_ITEM_FURY_X, HOUSE_ITEM_FURY_Y),
		SVector2(ITEM_WIDTH, ITEM_HEIGHT),
		pTheRenderer,
		"Texture/Item/teddy.png"
	);
	// we keep it in screenspace???
	m_pHouseItemFury->SetInWorld(false);
	m_pHouseItemFury->SetItemType(EEmotionType::FURY);
	m_pHouseItemFury->SetItemState(EItemState::ITEM_STATE_NONE);
	pHouseBackground->SetFuryItem(m_pHouseItemFury);

	// put it into the array
	// m_pAllItems[0] = m_pItemFury;

	GInventoryItems* m_pHouseItemFear = new GInventoryItems(
		SVector2(HOUSE_ITEM_FEAR_X, HOUSE_ITEM_FEAR_Y),
		SVector2(ITEM_WIDTH, ITEM_HEIGHT),
		pTheRenderer,
		"Texture/Item/candle.png"
	);
	m_pHouseItemFear->SetItemType(EEmotionType::FEAR);
	m_pHouseItemFear->SetItemState(EItemState::ITEM_STATE_NONE);
	pHouseBackground->SetFearItem(m_pHouseItemFear);

	// m_pAllItems[1] = m_pItemFear;

	GInventoryItems* m_pHouseItemSadness = new GInventoryItems(
		SVector2(HOUSE_ITEM_SADNESS_X, HOUSE_ITEM_SADNESS_Y),
		SVector2(ITEM_WIDTH, ITEM_HEIGHT),
		pTheRenderer,
		"Texture/Item/book_1.png"
	);
	m_pHouseItemSadness->SetItemType(EEmotionType::SAD);
	m_pHouseItemSadness->SetItemState(EItemState::ITEM_STATE_NONE);
	pHouseBackground->SetSadnessItem(m_pHouseItemSadness);
	// m_pAllItems[2] = m_pItemSadness;




	//	The ground to walk on
	GBackgroundStatic* pHouseGround = new GBackgroundStatic(
		SVector2(0, GROUND_POSITION),
		SVector2(1280, 220),
		CEngine::Get()->GetRenderer(),
		//"Texture/World/T_backg_G1_1280x720.png"
		"Texture/Background/T_GroundToWalkOn.png"
	);
	pHouseGround->SetColType(ECollisionType::WALL);
	pHouseGround->DeactivateGravity();
	pHouseGround->SetInWorld(true);

	// add object to world list
	m_pWorldStatus->AddHouseSceneObject(pHouseBackground);
	m_pWorldStatus->AddHouseSceneObject(pHouseGround);

	// add all items to list;
	// will chekc for state in render() of class
	m_pWorldStatus->AddHousePersistObject(m_pHouseItemFury);
	m_pWorldStatus->AddHousePersistObject(m_pHouseItemFear);
	m_pWorldStatus->AddHousePersistObject(m_pHouseItemSadness);




	// set house background in PLayer
	pPlayer->SetHouseBackground(pHouseBackground);
#pragma endregion



	// start game by creating new main scene
	CEngine::Get()->ChangeScene(new GMainScene()); // TODO! change back to GMainScene() 
}

// clean game
void GGame::Clean()
{
	// delete gigi font
	delete m_pGigiFont;

	// delete gigi font
	delete m_pPristinaFont;

	// TODO!
	// delete world status
	// clean CM completely
}
#pragma endregion