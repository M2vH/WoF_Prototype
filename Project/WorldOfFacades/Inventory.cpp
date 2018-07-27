#pragma region project include
#include "Inventory.h" 
#pragma endregion

#pragma region constructor
// constructor
GInventory::GInventory(SVector2 _pos, SVector2 _size,
	CRenderer * _pRenderer, const char * _pFileName)
	: CTexturedObject(_pos, _size, _pRenderer, _pFileName)
{
	// set object in world
	m_inWorld = false;
}
#pragma endregion


#pragma region public override function
// update every frame
void GInventory::Update(float _deltaTime)
{
}

// render every frame
void GInventory::Render(CRenderer * _pRenderer)
{
	// render texture
	CTexturedObject::Render(_pRenderer);
}
#pragma endregion

