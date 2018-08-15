#include "HouseBackground.h"
#include "BackgroundStatic.h"
#include "EnumItemState.h"



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
	m_pItemFury = new GInventoryItems(
		SVector2(),	// fill in position
		SVector2(),
		_pRenderer,
		""
	);
	m_pAllItems[0] = m_pItemFury;

	m_pItemFear = new GInventoryItems(
		SVector2(),
		SVector2(),
		_pRenderer,
		""
	);
	m_pAllItems[1] = m_pItemFear;

	m_pItemSadness = new GInventoryItems(
		SVector2(),
		SVector2(),
		_pRenderer,
		""
	);
	m_pAllItems[2] = m_pItemSadness;

	// through all fileNames;
}


GHouseBackground::~GHouseBackground()
{
}

void GHouseBackground::Render(CRenderer * _pRenderer)
{
	for (GInventoryItems* _item : m_pAllItems) {
		int itemsToDisplay = 0;
		if (_item->GetItemState == EItemState::USED)
		{
			// we get the emotiontype
			itemsToDisplay += _item->GetItemType();

		}
		SetTexture();

	}
	
	GBackgroundStatic::Render(_pRenderer);
	// for all items
	for (GInventoryItems* _item : m_pAllItems) {
	// if itemState == 4
		if (_item->GetItemState == EItemState::USED)
		{
	//		is in house -> render
			_item->Render(_pRenderer);

		}

	}
}

void GHouseBackground::Update(float _deltaTime) {
	GBackgroundStatic::Update(_deltaTime);
}
