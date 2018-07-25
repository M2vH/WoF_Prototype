#pragma region project include
#include "MainScene.h"
#include "World.h"
#include "ContentManagement.h"
#include "TexturedObjectSlide.h"
#pragma endregion

#pragma region public override function
// initialize scene
void GMainScene::Init()
{
	// create world
	m_pWorld = new GWorld(CEngine::Get()->GetRenderer(), "Texture/World/T_WorldSide.png");
	m_pWorld->Init();

	// create Paulchen Panther textured object
	CTexturedObjectSlide* pObj = new CTexturedObjectSlide(SVector2(100, 45), SVector2(32, 32),
		CEngine::Get()->GetRenderer(), "PP.png");

	// add object to cm
	CEngine::Get()->GetCM()->AddPersistantObject(pObj);
}

// cleaning up scene
void GMainScene::Clean()
{
	// delete world
	delete m_pWorld;
}
#pragma endregion