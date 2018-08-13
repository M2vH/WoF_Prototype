#include "AnimObject.h"
#include "Texture.h"
#include <SDL_timer.h>




//GAnimObject::GAnimObject(SVector2 _pos, SVector2 _size, CRenderer * _pRenderer, const char * _pFileName) 
//{
//	
//}

GAnimObject::GAnimObject(int _count, float _speed, SVector2 _blockSize, SVector2 _pos, SVector2 _size, CRenderer * _pRenderer, char ** _pFileNames)  : CMoveObject(_pos, _size) 
{
		m_animFilesCount = _count,
		m_animSpeed = _speed;
		m_blockSize = _blockSize;
		m_pTextureList = new list<CTexture*>;
		m_animState = EAnimState::STATE_ANIM_IDLE;
		m_pFileNames = _pFileNames;

		m_pIdleTextures[0] = 0;
		m_pIdleTextures[1] = 1;
		m_pIdleTextures[2] = 2;

		m_pMoveTextures[0] = 3;
		m_pMoveTextures[1] = 4;
		m_pMoveTextures[2] = 5;

		m_pJumpTextures[0] = 6;
		m_pJumpTextures[1] = 7;
		m_pJumpTextures[2] = 8;


		// create each texture and store in list;
		// ToDo (m2vh) get the amount of images;
		for (int i = 0; i < m_animFilesCount; i++)
		{
			CTexture* texture= new CTexture(m_pFileNames[i], _pRenderer);

			// SDL_Delay(500);
			m_pTextureArray[i] = texture;
		}
		SetTexture(m_pTextureArray[0]);
		
		SetSrcRect(SRect(0, 0, _size.X, _size.Y));
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
	// Update the movement of the anim
	 CMoveObject::Update(_deltaTime);

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
	if ((m_animState & EAnimState::STATE_ANIM_IDLE) == STATE_ANIM_IDLE)
	{
		// reset the other animations;
		m_pstartMove = 0;
		m_pstartJump = 0;

		// set the texture
		SetTexture(m_pTextureArray[m_pIdleTextures[m_pstartIdle]]);

		// set next index
		m_pstartIdle++;
		m_pstartIdle %= 3;
	}else
	
	// check if we are in moving state;
	if ((m_animState & EAnimState::STATE_ANIM_MOVE) == STATE_ANIM_MOVE)
	{
		// reset the other anim
		m_pstartIdle = 0;
		m_pstartJump = 0;
		// set the texture
		SetTexture(m_pTextureArray[m_pMoveTextures[m_pstartMove]]);

		// set next index
		m_pstartMove++;
		m_pstartMove %= 3;
	}else

	// check if we are in jumping state;
		// we are jumping
	if ((m_animState & EAnimState::STATE_ANIM_JUMP) == STATE_ANIM_JUMP)
	{
		// reset the other anim
		m_pstartIdle = 0;
		m_pstartMove = 0;
		// set the texture
		SetTexture(m_pTextureArray[m_pJumpTextures[m_pstartJump]]);

		// set next index
		m_pstartJump++;
		m_pstartJump %= 3;
	}

	}

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
