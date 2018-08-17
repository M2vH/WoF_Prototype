#pragma once
#include "BackgroundStatic.h"
#include "InventoryItems.h"
#include "Macro.h"

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

	// GInventoryItems* GetTheItems() { return m_pAllItems[3]; }

#pragma endregion


#pragma region public functions to get and set Items
	GInventoryItems* GetFuryItem() { return m_pAllItems[0]; };
	GInventoryItems* GetFearItem() { return m_pAllItems[1]; };
	GInventoryItems* GetSadnessItem() { return m_pAllItems[2]; };

	inline void SetFuryItem(GInventoryItems* _item) { m_pAllItems[0] = _item; }
	inline void SetFearItem(GInventoryItems* _item) { m_pAllItems[1] = _item; }
	inline void SetSadnessItem(GInventoryItems* _item) { m_pAllItems[2] = _item; }

#pragma endregion

private:
	//GInventoryItems* m_pItemFury = nullptr;
	//GInventoryItems* m_pItemFear = nullptr;
	//GInventoryItems* m_pItemSadness = nullptr;

	GInventoryItems* m_pAllItems[3];

	CTexture* m_allBackgrounds[8];


};

