#pragma region project include
#include "Game.h"
#include "Engine.h"
#include "MainScene.h"
#include "Font.h"
#include "WorldStatus.h"
#pragma endregion

#pragma region public function
// initialize game
void GGame::Init()
{
	// initialize the world status
	m_pWorldStatus = m_pWorldStatus->Get();
	//	// ToDo (m2vh) Delete before release
	m_pWorldStatus->SetState((EWorldState)(m_pWorldStatus->GetState()<< 3));
	LOG_MESSAGE("State of the world" , m_pWorldStatus->GetState());

	// create base gigi font
	m_pGigiFont = new CFont("Font/GIGI.ttf", 50);

	// create base gigi font
	m_pPristinaFont = new CFont("Font/PRISTINA.ttf", 50);

	// start game by creating new main scene
	CEngine::Get()->ChangeScene(new GMainScene());
}

// clean game
void GGame::Clean()
{
	// delete gigi font
	delete m_pGigiFont;

	// delete gigi font
	delete m_pPristinaFont;
}
#pragma endregion