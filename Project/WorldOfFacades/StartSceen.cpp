#include "StartSceen.h"
#include "Music.h"
#include "Helper.h"
#include "TexturedObject.h"
#include "Input.h"
#include "MainScene.h"
#include "Engine.h"
#include "Renderer.h"
#include "Macro.h"




void GStartSceen::Init()
{
#pragma region Music
	// create background music
	m_pBackgroundMusic = new CMusic(GetAssetPath("Audio/Moment-of-Strange.mp3", 4).c_str());

	// play music
	m_pBackgroundMusic->Play(true);

	CTexturedObject* m_pBackground = new CTexturedObject(
		SVector2(0,0),
		SVector2(1280,720),
		CEngine::Get()->GetRenderer(),
		"Texture/Start/WOF_title_screen_1280x720.png"
	);

	CEngine::Get()->GetRenderer()->SetCamera(SVector2(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2));


#pragma endregion
	if (CInput::GetKeyDown(SDL_SCANCODE_RETURN))
	{
		CEngine::Get()->ChangeScene(new GMainScene());

	}

}

void GStartSceen::Clean() {
	return;
}
