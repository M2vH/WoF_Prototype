#include "WorldImage.h"
#include "Texture.h"
#include "Engine.h"


/// <summary>
/// ctor;
/// </summary>
/// <param name="_fileNames">array of filepaths</param>
/// <param name="_pos">position to render</param>
/// <param name="_size">size to render</param>
GWorldImage::GWorldImage(char ** _fileNames, SVector2 _pos, SVector2 _size, CRenderer* _pRenderer) : GBackgroundStatic(_pos, _size, _pRenderer, _fileNames[3])
{
	// get the pointer to instance of worldstatus
	m_pWorldStatus = m_pWorldStatus->Get();

	// set the actual worldstate
	m_lastWorldState = m_pWorldStatus->GetState();
	
	// add filePaths to array
	m_pFileNames = _fileNames;
	
	for (size_t i = 0; i < 7; i++)
	{
		//create textures for all filepathes
		CTexture* newTexture = new CTexture(m_pFileNames[i], _pRenderer);
		// add texture* to array
		m_pTextures[i] = newTexture;
	}

}

/// <summary>
/// destructor;
/// </summary>
GWorldImage::~GWorldImage()
{
}

#pragma region public override functions
inline void GWorldImage::Update(float _deltaTime)
{
	// compare our worldstate with actual worldstate
	// if equal do nothing
	if (m_lastWorldState == m_pWorldStatus->GetState())
	{
		// ToDo (m2vh) delete
		// different textures are possible;
		SetTexture(m_pTextures[6]);
		// (m2vh) end delete
		return;
	}
	else
	{
		//	set our worldstate to actual worldstate
		//	set texture depending on worldstate
		m_lastWorldState = m_pWorldStatus->GetState();
		switch (m_lastWorldState)
		{
		case WORLD_STATE_NONE:
			break;
		case WORLD_STATE_1:
			SetTexture(m_pTextures[0]);
			break;
		case WORLD_STATE_2:
			SetTexture(m_pTextures[1]);
			break;
		case WORLD_STATE_3:
			SetTexture(m_pTextures[2]);
			break;
		case WORLD_STATE_4:
			SetTexture(m_pTextures[3]);
			break;
		case WORLD_STATE_5:
			SetTexture(m_pTextures[4]);
			break;
		case WORLD_STATE_6:
			SetTexture(m_pTextures[5]);
			break;
		case WORLD_STATE_7:
			SetTexture(m_pTextures[6]);
			break;
		default:
			break;
		}
	}

}

inline void GWorldImage::Render(CRenderer * pRenderer)
{
	GBackgroundStatic::Render(pRenderer);
}

#pragma endregion
