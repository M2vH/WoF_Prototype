#include "HouseBackground.h"
#include "BackgroundStatic.h"
#include "EnumItemState.h"
#include "Macro.h"
#include "Texture.h"


/// <summary>
/// ctor;
/// </summary>
/// <param name="_pos">position on screen</param>
/// <param name="_size">size of image</param>
/// <param name="_pRenderer">the renderer </param>
/// <param name="_pFileNames">path to the files</param>
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

	//m_pItemFury = new GInventoryItems(
	//	SVector2(_pos.X + HOUSE_ITEM_FURY_X, _pos.Y + HOUSE_ITEM_FURY_Y),
	//	SVector2(ITEM_WIDTH, ITEM_HEIGHT),
	//	_pRenderer,
	//	"Texture/Item/teddy.png"
	//);
	//// we keep it in screenspace???
	//m_pItemFury->SetInWorld(false);
	//m_pItemFury->SetItemType(EEmotionType::FURY);

	//// put it into the array
	m_pAllItems[0] = nullptr;

	//m_pItemFear = new GInventoryItems(
	//	SVector2(_pos.X + HOUSE_ITEM_FEAR_X, _pos.Y + HOUSE_ITEM_FEAR_Y),
	//	SVector2(ITEM_WIDTH, ITEM_HEIGHT),
	//	_pRenderer,
	//	"Texture/Item/candle.png"
	//);
	//m_pItemFear->SetItemType(EEmotionType::FEAR);
	m_pAllItems[1] = nullptr;

	//m_pItemSadness = new GInventoryItems(
	//	SVector2(_pos.X + HOUSE_ITEM_SADNESS_X, _pos.Y + HOUSE_ITEM_SADNESS_Y),
	//	SVector2(ITEM_WIDTH, ITEM_HEIGHT),
	//	_pRenderer,
	//	"Texture/Item/book_1.png"
	//);
	//m_pItemSadness->SetItemType(EEmotionType::SAD);
	m_pAllItems[2] = nullptr;

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

	GBackgroundStatic::Render(_pRenderer);
	// for all items
	//for (GInventoryItems* _item : m_pAllItems) {
	//	// if itemState == 4
	//	if (_item->GetItemState() == EItemState::USED)
	//	{
	//		//		is in house -> render
	//		_item->Render(_pRenderer);

	//	}

	//}
}

/// <summary>
/// Update every frame; check ItemState and display corresponding texture;
/// </summary>
/// <param name="_deltaTime"></param>
void GHouseBackground::Update(float _deltaTime) {
	int itemsToDisplay = 0;
	for (GInventoryItems* _item : m_pAllItems) {
		if (_item->GetItemState() == EItemState::USED)
		{
			// we get the emotiontype
			itemsToDisplay += _item->GetItemType();

		}


	}
	// ToDo check for pointer eqquals
	if (GetTexture() != m_allBackgrounds[itemsToDisplay])
	{
		SetTexture(m_allBackgrounds[itemsToDisplay]);

	}

	GBackgroundStatic::Update(_deltaTime);
}
