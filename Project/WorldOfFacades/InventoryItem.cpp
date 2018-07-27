#pragma region project includes
#include "InventoryItem.h"  
#pragma endregion



#pragma region constructor
GInventoryItem::GInventoryItem(SVector2 _pos, SVector2 _size,
	CRenderer * _pRenderer,
	const char * _pFileName)
	: CMoveObject(_pos, _size, _pRenderer, _pFileName)
{
}
GInventoryItem::~GInventoryItem()
{
}
#pragma endregion


#pragma region public override function
void GInventoryItem::Update(float _deltaTime)
{
}

void GInventoryItem::Render(CRenderer * _pRenderer)
{
}
#pragma endregion

