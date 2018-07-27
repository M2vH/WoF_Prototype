#pragma region project includes
#include "FuryItem.h"  
#pragma endregion

GFuryItem::GFuryItem(SVector2 _pos,
	SVector2 _size,
	CRenderer * _pRenderer,
	const char * _pFileName)
	: CMoveObject(_pos, _size, _pRenderer, _pFileName)
{
	// set object in world
	m_inWorld = true;

	m_colType = WALL;
}


#pragma region public override function
// update every frame
void GFuryItem::Update(float _deltaTime)
{
}

// render every frame
void GFuryItem::Render(CRenderer * _pRenderer)
{
	// render texture
	CMoveObject::Render(_pRenderer);
}
#pragma endregion

