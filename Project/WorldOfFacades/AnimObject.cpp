#include "AnimObject.h"
#include "Texture.h"



//GAnimObject::GAnimObject(SVector2 _pos, SVector2 _size, CRenderer * _pRenderer, const char * _pFileName) 
//{
//	
//}

GAnimObject::GAnimObject(float _speed, SVector2 _blockSize, SVector2 _pos, SVector2 _size, CRenderer * _pRenderer, char ** _pFileNames)  : CMoveObject(_pos, _size) 
{
	// m_position = _pos;
	//m_rect.w = _size.X;
	//m_rect.h = _size.Y;
		m_animSpeed = _speed;
		m_blockSize = _blockSize;
		m_pTextureList = new list<CTexture*>;
//		m_pTextureArray = CTexture * [3];
		m_PlayerState = EPlayerState::PLAYER_WALK;
		m_pFileNames = _pFileNames;

		m_pIdleTextures[0] = 0;
		m_pIdleTextures[1] = 0;
		m_pIdleTextures[2] = 0;

		m_pMoveTextures[0] = 0;
		m_pMoveTextures[1] = 1;
		m_pMoveTextures[2] = 2;


		// create each texture and store in list;
		for (int i = 0; i < 3; i++)
		{
			//m_pTextureList->push_back(
			//	new CTexture(m_pFileNames[i], _pRenderer)
			//);
			CTexture* texture= new CTexture(m_pFileNames[i], _pRenderer);
			m_pTextureArray[i] = texture;
			// m_pTextureArray[i] = new CTexture(m_pFileNames[i], _pRenderer);
			
		}
		SetTexture(m_pTextureArray[0]);
}

GAnimObject::~GAnimObject()
{
	// ToDo (m2vh) 
	// clear the list
	// delete the list
	delete m_pTextureList;
}

void GAnimObject::Update(float _deltaTime)
{
	// temp animSpeed value;
	static float speedReset = m_animSpeed;
	
	// decrease samplerate
	speedReset -= _deltaTime;
	
	if (speedReset <= 0)
	{
	//		reset samplerate
	speedReset += m_animSpeed;
	// 
	// check state
	// if IDLE
	if ((m_PlayerState & PLAYER_IDLE) == PLAYER_IDLE)
	{
		// reset the other anim
		m_pstartMove = 0;

		// set the texture
		SetTexture(m_pTextureArray[m_pIdleTextures[m_pstartIdle]]);

		// set next index
		m_pstartIdle++;
		m_pstartIdle %= 3;
	}
	
	if ((m_PlayerState & EPlayerState::PLAYER_WALK) == PLAYER_WALK)
	{
		// reset the other anim
		m_pstartIdle = 0;
		// set the texture
		SetTexture(m_pTextureArray[m_pMoveTextures[m_pstartMove]]);

		// set next index
		m_pstartMove++;
		m_pstartMove %= 3;
	}

	//		set texture
	// else if MOVE
	//		get the first texture;
	// texture = m_pTextureList->front();
	//		set texture
	// SetTexture(texture);
	//		pop texture from list
	// m_pTextureList->pop_front();
	//		reset samplerate

	//		push_back texture to list

	}
	CMoveObject::Update(_deltaTime);

	// 
}

void GAnimObject::Render(CRenderer * _pRenderer)
{
	CMoveObject::Render(_pRenderer);
}

inline void GAnimObject::NextTexture()
{
	SetTexture(m_pTextureList->front());
}

//inline void GAnimObject::SetTexture(CTexture * _texture)
//{
//}
