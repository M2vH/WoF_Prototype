#include "BackgroundSlide.h"
#include "BackgroundStatic.h"
#include "Renderer.h"
#include "Input.h"


/// <summary>
/// constructor
/// </summary>
/// <param name="_filePath">path/to/file</param>
GBackgroundSlide::GBackgroundSlide(const char * _filePath)
{
	m_ResetPosition = {0,0};
	m_pFilePath = _filePath;
	m_Size = { 1280,720 };
	m_Speed = PLAYER_SPEED / 3;
	// create the Background Triptichon
	m_pLeftImage = new GBackgroundStatic(
		SVector2(-1280,0),
		SVector2(1280,720),
		CEngine::Get()->GetRenderer(),
		m_pFilePath
	);
	m_pCenterImage = new GBackgroundStatic(
		SVector2(0, 0),
		SVector2(1280, 720),
		CEngine::Get()->GetRenderer(),
		m_pFilePath
	);
	m_pRightImage = new GBackgroundStatic(
		SVector2(2 * 1280, 0),
		SVector2(1280, 720),
		CEngine::Get()->GetRenderer(),
		m_pFilePath
	);


}

GBackgroundSlide::~GBackgroundSlide()
{
//	delete m_pLeftImage;
//	delete m_pRightImage;
//	delete m_pCenterImage;
}

void GBackgroundSlide::Update(float _deltaTime)
{
	
	SVector2 move;
	// movement left
	if (CInput::GetKey(SDL_SCANCODE_A))
	{
		// set movement and mirror
		move.X = 1.0f;
		// ToDo: delete
		// m_mirror.X = 1.0f;
	}

	// movement right
	else if (CInput::GetKey(SDL_SCANCODE_D))
	{
		// set movemenet and mirror
		move.X = -1.0f;
		// m_mirror.X = 0.0f;
	}

	// no movement left or right
	else
		move.X = 0.0f;

	move = move  * m_Speed * _deltaTime;
	m_ResetPosition.X += move.X;
	m_ResetPosition.X = (int)(m_ResetPosition.X) % 1280;

	m_pLeftImage->SetPosition(SVector2(m_ResetPosition.X - m_Size.X, 0));
	m_pCenterImage->SetPosition(SVector2(m_ResetPosition.X, 0));
	m_pRightImage->SetPosition(SVector2(m_ResetPosition.X + m_Size.X, 0));

	m_pLeftImage->Update(_deltaTime);
	m_pCenterImage->Update(_deltaTime);
	m_pRightImage->Update(_deltaTime);
}

void GBackgroundSlide::Render(CRenderer * _pRenderer)
{	
	// m_pLeftImage->Render(_pRenderer);
	m_pCenterImage->Render(_pRenderer);
	// m_pRightImage->Render(_pRenderer);
}
