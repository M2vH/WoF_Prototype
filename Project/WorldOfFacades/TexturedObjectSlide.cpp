#pragma region project include
#include "TexturedObjectSlide.h"
#include "Texture.h"
#include "Renderer.h"
#include "Vector2.h"
#pragma endregion

#pragma region constructor
// constructor
CTexturedObjectSlide::CTexturedObjectSlide(SVector2 _pos, SVector2 _size, CRenderer * _pRenderer, 
	const char * _pFileName)
{
	// set position and rect
	m_position = _pos;
	m_rect.x = _pos.X;
	m_rect.y = _pos.Y;
	m_rect.w = _size.X;
	m_rect.h = _size.Y;

	m_srcRect = SRect(0, 0, _size.X, _size.Y);

	// create texture
	m_pTexture = new CTexture(_pFileName, _pRenderer);
}

// destructor
CTexturedObjectSlide::~CTexturedObjectSlide()
{
	// delete texture
	delete m_pTexture;
}
#pragma endregion

#pragma region public override function
// update every frame
void CTexturedObjectSlide::Update(float _deltaTime)
{
	// TODO (m2vh)
	// check if leaving left border;
	//	must come back from the right;

	m_position.X += 1;
	m_position.X = (int)(m_position.X)%1280;
	m_position.Y = 100;

	// set position of rect
	m_rect.x = m_position.X;
	m_rect.y = m_position.Y;
}

// render every frame
void CTexturedObjectSlide::Render(CRenderer * _pRenderer)
{
	// render texture
	_pRenderer->RenderTexture(m_pTexture, m_rect, m_srcRect);
}
#pragma endregion