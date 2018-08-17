#include "HouseBackground.h"
#include "BackgroundStatic.h"
#include "EnumItemState.h"
#include "Macro.h"
#include "Texture.h"



GHouseBackground::GHouseBackground(
	SVector2 _pos,
	SVector2 _size,
	CRenderer* _pRenderer,
	char** _pFileNames
) : GBackgroundStatic(
		_pos,
		_size,
		_pRenderer,
		_pFileNames[0])
{
	/*
	Teddy; Horizontal; 330 px Vertikal; 250 px FURY
 
	Kerze; Horizontal; 290 px Vertikal 530 px FEAR
 
	Buch;  Horizontal; 410 px Vertikal; 730 px SADNESS
	*/
	
	m_pItemFury = new GInventoryItems(
		SVector2(_pos.X + HOUSE_ITEM_FURY_X, _pos.Y + HOUSE_ITEM_FURY_Y),
		SVector2(ITEM_WIDTH, ITEM_HEIGHT),
		_pRenderer,
		"Texture/Item/teddy.png"
	);
	// we keep it in screenspace???
	m_pItemFury->SetInWorld(false);
	
	// put it into the array
	m_pAllItems[0] = m_pItemFury;

	m_pItemFear = new GInventoryItems(
		SVector2(_pos.X + HOUSE_ITEM_FEAR_X, _pos.Y + HOUSE_ITEM_FEAR_Y),
		SVector2(ITEM_WIDTH, ITEM_HEIGHT),
		_pRenderer,
		"Texture/Item/candle.png"
	);
	m_pAllItems[1] = m_pItemFear;

	m_pItemSadness = new GInventoryItems(
		SVector2(_pos.X + HOUSE_ITEM_SADNESS_X, _pos.Y + HOUSE_ITEM_SADNESS_Y),
		SVector2(ITEM_WIDTH, ITEM_HEIGHT),
		_pRenderer,
		"Texture/Item/book_1.png"
	);
	m_pAllItems[2] = m_pItemSadness;

	// through all fileNames;
	for (size_t i = 0; i < 8; i++)
	{	
		CTexture* aBackground = new CTexture(
			_pFileNames[i],
			_pRenderer
		);
		m_allBackgrounds[i] = aBackground;

	}

}


GHouseBackground::~GHouseBackground()
{
}

void GHouseBackground::Render(CRenderer * _pRenderer)
{
	for (GInventoryItems* _item : m_pAllItems) {
		int itemsToDisplay = 0;
		if (_item->GetItemState() == EItemState::USED)
		{
			// we get the emotiontype
			itemsToDisplay += _item->GetItemType();

		}
		SetTexture(m_allBackgrounds[itemsToDisplay]);

	}
	
	GBackgroundStatic::Render(_pRenderer);
	// for all items
	for (GInventoryItems* _item : m_pAllItems) {
	// if itemState == 4
		if (_item->GetItemState() == EItemState::USED)
		{
	//		is in house -> render
			_item->Render(_pRenderer);

		}

	}
}

void GHouseBackground::Update(float _deltaTime) {
	GBackgroundStatic::Update(_deltaTime);
}
