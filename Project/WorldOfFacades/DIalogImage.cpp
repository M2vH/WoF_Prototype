#include "DIalogImage.h"
#include "Texture.h"
#include "Engine.h"



GDIalogImage::GDIalogImage(SVector2 _pos, SVector2 _size, SVector2 _margin, char ** _fileNames) : CTexturedObject(_pos + _margin)
{
	// have a pointer to the Renderer
	CRenderer* theRenderer = CEngine::Get()->GetRenderer();
	// make textures of fileNames
	for (size_t i = 0; i < 3; i++)
	{
		CTexture* aTexture = new CTexture(
			_fileNames[i],
			theRenderer
		);
		m_AllTextures[i] = aTexture;
	}
	// set a default texture;
	m_pTexture = m_AllTextures[0];
}

GDIalogImage::~GDIalogImage()
{
}

void GDIalogImage::	Update(float _deltaTime)
{
	// ToDo (m2vh) Set the texture to mNPC of player;
	m_pTheBubble->Update(_deltaTime);
	CTexturedObject::Update(_deltaTime);
}

void GDIalogImage::Render(CRenderer * _pRenderer)
{
	//first render the bubble;
	m_pTheBubble->Render(_pRenderer);
	// then render the textImage;
	CTexturedObject::Render(_pRenderer);
}
