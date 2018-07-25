#pragma region project include
#include "TexturedObject.h"
#include "Texture.h"
#include "Renderer.h"
#pragma endregion

#pragma region constructor
// constructor
CTexturedObject::CTexturedObject(SVector2 _pos, SVector2 _size, CRenderer * _pRenderer, 
	const char * _pFileName)
{
	// set position and rect
	m_position = _pos;
	m_rect.x = _pos.X;
	m_rect.y = _pos.Y;
	m_rect.w = _size.X;
	m_rect.h = _size.Y;

	// create texture
	m_pTexture = new CTexture(_pFileName, _pRenderer);
}

// destructor
CTexturedObject::~CTexturedObject()
{
	// delete texture
	if(m_pTexture)
		delete m_pTexture;
}
#pragma endregion

#pragma region public override function
// update every frame
void CTexturedObject::Update(float _deltaTime)
{
	// set position of rect
	m_rect.x = m_position.X;
	m_rect.y = m_position.Y;
}

// render every frame
void CTexturedObject::Render(CRenderer * _pRenderer)
{
	// render texture
	_pRenderer->RenderTexture(m_pTexture, m_rect, m_srcRect, m_mirror, m_angle);
}
#pragma endregion