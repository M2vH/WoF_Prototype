#pragma region project include
#include "MainScene.h"
#include "World.h"
#include "ContentManagement.h"
#pragma endregion

#pragma region public override function
// initialize scene
void GMainScene::Init()
{
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