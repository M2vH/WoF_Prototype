#pragma region project include
#include "Inventory.h" 
#include "Macro.h"
#pragma endregion

#pragma region constructor
// constructor
GInventory::GInventory(SVector2 _pos, SVector2 _size,
	CRenderer * _pRenderer, const char * _pFileName)
	: CTexturedObject(_pos, _size, _pRenderer, _pFileName)
{
	// set object in world
	m_inWorld = false;
	
	m_pFuryItem = new GInventoryItems(SVector2(0, 0),
		SVector2(ITEM_WIDTH, ITEM_HEIGHT),
		_pRenderer,
		"Texture/Item/teddy.png");
	m_pFuryItem->SetInWorld(false);

	m_pFearItem = new GInventoryItems(SVector2(0, 0),

		SVector2(ITEM_WIDTH, ITEM_HEIGHT),
		_pRenderer,
		"Texture/Item/candle.png");
	m_pFearItem->SetInWorld(false);

	m_pSadnessItem = new GInventoryItems(SVector2(0, 0),
		SVector2(ITEM_WIDTH, ITEM_HEIGHT),
		_pRenderer,
		"Texture/Item/book_1.png");

	m_pSadnessItem->SetInWorld(false);
}
#pragma endregion


#pragma region public override function
// update every frame
void GInventory::Update(float _deltaTime)
{
	CTexturedObject::Update(_deltaTime);

	// update every item object
	int temp = 1;

	SVector2 offset = { INVENTORY_ITEM_OFFSET_X, INVENTORY_ITEM_OFFSET_Y };

	for (GInventoryItems* pObj : m_pItemObjects) 
	{
		SVector2 newPosition = m_position + SVector2(offset.X, offset.Y * temp);
		pObj->SetPosition(newPosition);
		pObj->Update(_deltaTime);
		temp++;
	}

	// TODO: offset for items from inventory
}

// render every frame
void GInventory::Render(CRenderer * _pRenderer)
{
	// render texture
	CTexturedObject::Render(_pRenderer);
	
	// render every item object
	for each (CObject* pObj in m_pItemObjects)
		pObj->Render(_pRenderer);
}
#pragma endregion

#pragma region private function
void GInventory::AddObject(EEmotionType _emoType)
{
	switch (_emoType)
	{
		case EEmotionType::FURY:
			m_pItemObjects.push_back(m_pFuryItem);
			break;
		case EEmotionType::FEAR:
			m_pItemObjects.push_back(m_pFearItem);
			break;
		case EEmotionType::SAD:
			m_pItemObjects.push_back(m_pSadnessItem);
			break;
	
		default:
			break;
	}
}
#pragma endregion

