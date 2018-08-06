#include "WorldBackground.h"
#include "Macro.h"


/// <summary>
/// The ctor
/// </summary>
/// <param name="_pos">position in worldspace</param>
/// <param name="_size">the size in pixel</param>
/// <param name="_pRenderer">the renderer</param>
/// <param name="_pFileName">the relative path to image file</param>
GWorldBackground::GWorldBackground(SVector2 _pos, SVector2 _size, CRenderer* _pRenderer,
	const char* _pFileName) : CTexturedObject(_pos, _size, _pRenderer, _pFileName) 
{
	
	// create the left fill of the screen
	// player will possibly move towards 0,
	// but never go further;
	m_pLeftFill = new CTexturedObject(
		SVector2(this->m_position.X - SCREEN_WIDTH / 2, this->m_position.Y),	// pos is { -640, 0 }
		SVector2((float)SCREEN_WIDTH / 2, this->m_rect.h)
	);
	// re-use the texture of THIS GWorldBackground object
	m_pLeftFill->SetTexture(this->m_pTexture);
	m_pLeftFill->SetSrcRect(
		SRect(
			this->m_rect.w - SCREEN_WIDTH / 2,		// for left fill use half the screen of right
			0,
			SCREEN_WIDTH / 2,
			this->m_rect.h
		));

	// create the right fill of the screen
	// player will reach right end at 3840,
	// but will never go any further
	m_pRightFill = new CTexturedObject(
		SVector2(this->m_rect.w, this->m_position.Y), // the position is { 3840, 0 }
		SVector2((float)SCREEN_WIDTH / 2, this->m_rect.h)
	);
	// re-use the texture of THIS object;
	m_pRightFill->SetTexture(this->m_pTexture);
	m_pRightFill->SetSrcRect(
		SRect(
			0,	// for the right fill use the left side of picture
			0,				// the upper border
			SCREEN_WIDTH / 2,
			this->m_rect.h
		));
}

#pragma region override functions
void GWorldBackground::Update(float _deltaTime)
{
	CTexturedObject::Update(_deltaTime);
	m_pLeftFill->Update(_deltaTime);
	m_pRightFill->Update(_deltaTime);
}

void GWorldBackground::Render(CRenderer* _pRenderer)
{
	CTexturedObject::Render(_pRenderer);
	m_pLeftFill->Render(_pRenderer);
	m_pRightFill->Render(_pRenderer);
}
#pragma endregion


GWorldBackground::~GWorldBackground()
{
}
