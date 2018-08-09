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
	m_pWorldStatus->Get();

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