#pragma region project include
#include "Game.h"
#include "Engine.h"
#include "MainScene.h"
#pragma endregion

#pragma region public function
// initialize game
void GGame::Init()
{
	// create new main scene
	CEngine::Get()->ChangeScene(new GMainScene());
}
#pragma endregion