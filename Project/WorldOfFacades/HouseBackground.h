#pragma once
#include "BackgroundStatic.h"
#include "InventoryItems.h"
class GHouseBackground :
	public GBackgroundStatic
{
public:
	GHouseBackground(
		SVector2 _pos,
		SVector2 _size,
		CRenderer* _pRenderer,
		char** _pFileNames
	);

	~GHouseBackground();

#pragma region public override
	void Update(float _deltaTime) override;

	void Render(CRenderer* _pRenderer) override;
#pragma endregion


#pragma region public functions to get Items
	GInventoryItems* GetFuryItem() { return m_pItemFury; };
	GInventoryItems* GetFearItem() { return m_pItemFear; };
	GInventoryItems* GetSadnessItem() { return m_pItemSadness; };

#pragma endregion

private:
	GInventoryItems* m_pItemFury;
	GInventoryItems* m_pItemFear;
	GInventoryItems* m_pItemSadness;

	GInventoryItems* m_pAllItems[3];

	CTexture* m_allBackgrounds[8];


};

