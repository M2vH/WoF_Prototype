#pragma region project includes
#include "InventoryItems.h"  
#pragma endregion

//GInventoryItems::GInventoryItems(SVector2 _pos,
//	SVector2 _size,
//	CRenderer * _pRenderer,
//	const char * _pFileName)
//	: CMoveObject(_pos, _size, _pRenderer, _pFileName)
//{
//	// set object in world
//}


#pragma region public override function
// update every frame
void GInventoryItems::Update(float _deltaTime)
{
	CTexturedObject::Update(_deltaTime);
}

// render every frame
void GInventoryItems::Render(CRenderer * _pRenderer)
{
	// render texture
	CMoveObject::Render(_pRenderer);
}
#pragma endregion

