#include "AnimObject.h"



//GAnimObject::GAnimObject(SVector2 _pos, SVector2 _size, CRenderer * _pRenderer, const char * _pFileName) 
//{
//	
//}

GAnimObject::GAnimObject(int _speed, SVector2 _blockSize, SVector2 _pos, SVector2 _size, CRenderer * _pRenderer, const char * _pFileName) : CMoveObject(_pos, _size) 
{
		m_animSpeed = _speed;
		m_blockSize = _blockSize;
		m_pTextureList = new list<CTexture*>;
}

GAnimObject::~GAnimObject()
{
	delete m_pTextureList;
}

void GAnimObject::Update(float _deltaTime)
{
	CMoveObject::Update(_deltaTime);
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
