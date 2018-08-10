#pragma region project include
#include "HouseScene.h"  
#include "Music.h"
#include "Sound.h"
#include "Renderer.h"
#include "BackgroundStatic.h"
#include "Engine.h"
#include "ContentManagement.h"
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
		"Texture/Haus/innen/B_Hütte_Start_1280x720 (1).png"
	);

	// set values of object
	pBackgroundInHouse->DeactivateGravity();
	pBackgroundInHouse->SetInWorld(false);

	CEngine::Get()->GetCM()->AddSceneObject(pBackgroundInHouse);

#pragma endregion

}

void GHouseScene::Clean()
{
}
#pragma endregion

