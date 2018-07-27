#pragma region project include
#include "MainScene.h"
#include "World.h"
#include "ContentManagement.h"
#include "TexturedObjectSlide.h"
#include "Inventory.h"
#include "TexturedObject.h"
#include "FuryItem.h"
#pragma endregion

#pragma region public override function
// initialize scene
void GMainScene::Init()
{

	// create Paulchen Panther textured object
	CTexturedObjectSlide* pObj = new CTexturedObjectSlide(SVector2(100, 45), SVector2(32, 32),
		CEngine::Get()->GetRenderer(), "PP.png");

	// create Inventory background
	GInventory* pInventoryBackground = new GInventory(SVector2(25, SCREEN_HEIGHT *0.25),
		SVector2(48*2,48*6),
		CEngine::Get()->GetRenderer(),
		"Texture/Inventory/inventorybackground_496x756.png");

	// create FuryItem
	GFuryItem* pFuryItem = new GFuryItem(SVector2(900, 580),
		SVector2(WORLD_BLOCK_WIDTH, WORLD_BLOCK_HEIGHT),
		CEngine::Get()->GetRenderer(),
		"Texture/Inventory/Fury_500x500.png");

	// add object to cm
	CEngine::Get()->GetCM()->AddUIObject(pInventoryBackground);
	CEngine::Get()->GetCM()->AddSceneObject(pFuryItem);
	CEngine::Get()->GetCM()->AddPersistantObject(pObj);
	
	// create world
	m_pWorld = new GWorld(CEngine::Get()->GetRenderer(), "Texture/World/T_WorldSide.png");
	m_pWorld->Init();
}

// cleaning up scene
void GMainScene::Clean()
{
	// delete world
	delete m_pWorld;
}
#pragma endregion