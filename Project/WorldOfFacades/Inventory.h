#pragma once
#pragma region system include
#include <list>
#pragma endregion

#pragma region project include
#include "TexturedObject.h"
#include "EnumEmotionType.h"
#include "InventoryItems.h"
#pragma endregion

#pragma region forward decleration
class CObject;
#pragma endregion

#pragma region using
using namespace std;
#pragma endregion

/// <summary>
/// inventory class
/// </summary>
class GInventory : public CTexturedObject
{
public:
#pragma region constructor
	/// <summary>
	/// constructor
	/// </summary>
	/// <param name="_pos">position of object</param>
	/// <param name="_size">width and height of rect</param>
	/// <param name="_pRenderer">renderer</param>
	/// <param name="_pFileName">file path name (relative)</param>
	GInventory(SVector2 _pos, SVector2 _size, CRenderer* _pRenderer,
		const char* _pFileName);
	
	/// <summary>
	/// destuctor
	/// </summary>
	~GInventory() {};
#pragma endregion

#pragma region public inline funtion
	/// <summary>
	/// get scene objects list
	/// </summary>
	/// <returns>list of all scene object</returns>
	inline list<GInventoryItems*> GetItemObjects() { return m_pItemObjects; }
#pragma endregion


#pragma region public override function
	/// <summary>
	/// update every frame
	/// </summary>
	/// <param name="_deltaTime">time since last frame</param>
	virtual void Update(float _deltaTime) override;

	/// <summary>
	/// render every frame
	/// </summary>
	/// <param name="_pRenderer">renderer</param>
	virtual void Render(CRenderer* _pRenderer) override;
#pragma endregion

#pragma region private variable
	/// <summary>
	/// scene / world objects
	/// </summary>
	list<GInventoryItems*> m_pItemObjects;

	/// <summary>
	/// fury item
	/// </summary>
	GInventoryItems* m_pFuryItem;

	/// <summary>
	/// fear item
	/// </summary>
	GInventoryItems* m_pFearItem;

	/// <summary>
	/// sadness item
	/// </summary>
	GInventoryItems* m_pSadnessItem;
#pragma endregion

#pragma region private function
	/// <summary>
	/// add object to list
	/// </summary>
	/// <param name="_pObj">object</param>
	/// <param name="_pList">list to add to</param>
	void AddObject(EEmotionType _emoType);
#pragma endregion

};

