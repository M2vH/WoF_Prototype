#pragma region system include
#include <SDL_timer.h>  
#pragma endregion

#pragma region project include
#include "HouseScene.h"  
#include "Music.h"
#include "Sound.h"
#include "Renderer.h"
#include "BackgroundStatic.h"
#include "Engine.h"
#include "ContentManagement.h"
#include "Player.h"
#include "Foreground.h"
#include "MoveObject.h"
#pragma endregion





#pragma region public override function
// initialize scene
void GHouseScene::Init()
{
	CRenderer* pTheRenderer = CEngine::Get()->GetRenderer();

#pragma region InHouse background
	GBackgroundStatic* pBackgroundInHouse = new GBackgroundStatic(
		SVector2(0, 0),
		SVector2(1280, 720),
		CEngine::Get()->GetRenderer(),
		"Texture/Haus/Innen/B_Huette_Start_1280x720.png"
	);

	// set values of object
	pBackgroundInHouse->DeactivateGravity();
	pBackgroundInHouse->SetInWorld(false);

	CEngine::Get()->GetCM()->AddSceneObject(pBackgroundInHouse);

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
	GPlayer* pPlayer = new GPlayer(
		8,
		0.15f,
		SVector2(0, 0),
		SVector2(SCREEN_WIDTH / 2, GROUND_POSITION - PLAYER_HEIGHT - 30),	// X: in the middle of the world Y: will fall till ground
		SVector2(PLAYER_WIDTH, PLAYER_HEIGHT),			// 
		CEngine::Get()->GetRenderer(),
		playerAnimFileNames
	);

	// set player values
	// pPlayer->SetSpeed(PLAYER_SPEED);
	pPlayer->SetMirror(PLAYER_MIRROR);
	pPlayer->SetColType(ECollisionType::MOVE);

	pPlayer->ActivateGravity();
	pPlayer->IsInHouse();
#pragma endregion


#pragma region Walkground

	///// <summary>
	///// is the way, the player is moving on; place it between player and world
	///// </summary>
	//GForeground* pWalkground = new GForeground(
	//	-1.0f,	// is moving with playerspeed on the worldimage in opposite direction
	//	SVector2(0, 360),
	//	SVector2(1280, 170),
	//	pTheRenderer,
	//	"Texture/Background/Wald/"
	//);
#pragma endregion

#pragma region Ground (to walk on)

	// Add a ground to walk on;
	GBackgroundStatic* pGround = new GBackgroundStatic(
		SVector2(0, GROUND_POSITION),
		SVector2(1280, 220),
		CEngine::Get()->GetRenderer(),
		//"Texture/World/T_backg_G1_1280x720.png"
		""	// add empty string to create collision object
	);
	pGround->SetColType(ECollisionType::WALL);
	pGround->DeactivateGravity();
	pGround->SetInWorld(true);

#pragma endregion
	
	//// TODO: WTF!!!!
	//SDL_Delay(1000);

#pragma region Adding objects to lists

	//// background
	//CEngine::Get()->GetCM()->AddSceneObject(pBackgroundInHouse);
	
	// ground to walk on
	CEngine::Get()->GetCM()->AddPersistantObject(pGround);
	

	// player
	CEngine::Get()->GetCM()->AddPersistantObject(pPlayer);

	//// walkground
	//CEngine::Get()->GetCM()->AddSceneObject(pWalkground);
#pragma endregion

}

void GHouseScene::Clean()
{
}
#pragma endregion

