#pragma region project include
#include "MainScene.h"
#include "World.h"
#include "ContentManagement.h"
#include "TexturedObjectSlide.h"
#include "Player.h"
#pragma endregion

#pragma region public override function
// initialize scene
void GMainScene::Init()
{
	// create world
	//m_pWorld = new GWorld(CEngine::Get()->GetRenderer(), "Texture/World/T_WorldSide.png");
	//m_pWorld->Init();

	// create a screen background from TexturedObject
	CTexturedObject* pBackground = new CTexturedObject(
		SVector2(0,0),
		SVector2(SCREEN_WIDTH+48, SCREEN_HEIGHT+48),
		CEngine::Get()->GetRenderer(),
		"Texture/World/T_backg_L2_1280x720.png"
	);
	// keep background in camera;
	pBackground->SetInWorld(false);

	// create a worldspace background
	CTexturedObject* pBackgroundWorld = new CTexturedObject(
		SVector2(0, 100),	// pos of object in World
		SVector2(3840, 720),	// size; if 0,0 will be set to texture size
		CEngine::Get()->GetRenderer(),
		"Texture/World/T_world_tree_3840x720.png"
	);
	
	// create Paulchen Panther textured object
	CTexturedObjectSlide* pObj = new CTexturedObjectSlide(SVector2(100, 45), SVector2(32, 32),
		CEngine::Get()->GetRenderer(), "PP.png");

	// add a player
	GPlayer * pPlayer = new GPlayer(
		SVector2(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2),	// in the middle of the screen // ToDo (m2vh) adjust player size
		SVector2(PLAYER_WIDTH, PLAYER_HEIGHT),			// 
		CEngine::Get()->GetRenderer(),
		"Texture/Character/Player/T_Samus_Idle.png");

	// set player values
	pPlayer->SetSpeed(PLAYER_SPEED);
	pPlayer->SetMirror(PLAYER_MIRROR);
	pPlayer->SetColType(ECollisionType::MOVE);
	
	// pPlayer->ActivateGravity();

#pragma region Adding objects to Lists
					
	// SceneObjects
	// add worldbackground to SceneObject
	CEngine::Get()->GetCM()->AddSceneObject(pBackgroundWorld);

	// add background to SceneObject-List
	CEngine::Get()->GetCM()->AddSceneObject(pBackground);


	// PersistantObjects
	// add object to cm
	CEngine::Get()->GetCM()->AddPersistantObject(pObj);

	// add player to persistant list
	CEngine::Get()->GetCM()->AddPersistantObject(pPlayer);


#pragma endregion
}

// cleaning up scene
void GMainScene::Clean()
{
	// delete world
	delete m_pWorld;
}
#pragma endregion