#include "DIalogImage.h"
#include "Texture.h"
#include "Engine.h"


/// <summary>
/// ctor;
/// </summary>
GDialogImage::GDialogImage(SVector2 _pos, SVector2 _size, SVector2 _margin, char ** _fileNames) : CTexturedObject(_pos + _margin, _size)
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

	// calculate the necessary bubble
	// _bubblePos = _pos;
	// _bubbleSize = _size;
	m_pTheBubble = new GTextBubble(_pos, _size);

	// make sure we are in screen space
	SetInWorld(false);
}

GDialogImage::~GDialogImage()
{
	// delete all Textures in array
	for(CTexture* _pObj : m_AllTextures)
	{
		delete _pObj;
	}

	// delete the bubble
	delete m_pTheBubble;
}

void GDialogImage::Update(float _deltaTime)
{
	// ToDo (m2vh) Set the texture to mNPC of player;
	m_pTheBubble->Update(_deltaTime);
	CTexturedObject::Update(_deltaTime);
}

void GDialogImage::Render(CRenderer * _pRenderer)
{
	// check for renderDisplay
	if (!m_renderDisplay)
	{
		return;
	}
	else
	{
		//first render the bubble;
		m_pTheBubble->Render(_pRenderer);
		// then render the textImage;
		CTexturedObject::Render(_pRenderer);
	}
}

void GDialogImage::SetText(ENPCState _state)
{
	switch (_state)
	{
	case WAITING:
		// display the first text
		SetTexture(m_AllTextures[0]);
		break;
	case ISVISITED:
		SetTexture(m_AllTextures[1]);
		break;
	case VISITED:
		SetTexture(m_AllTextures[2]);
		break;
	case DONE:
		break;
	default:
		break;
	}
}
