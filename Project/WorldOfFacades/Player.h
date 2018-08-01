#pragma once

#pragma region project include
#include "MoveObject.h"  
#pragma endregion

#pragma region forward declaration
class GInventoryItems;
class GNpc;
#pragma endregion



/// <summary>
/// player class
/// </summary>
class GPlayer :	public CMoveObject
{
public:
	static GPlayer* Get() { return s_instance; }
#pragma region constructor
	/// <summary>
	/// constructor
	/// </summary>
	/// <param name="_pos">position of object</param>
	GPlayer(SVector2 _pos) : CMoveObject(_pos) { s_instance = this; }

	/// <summary>
	/// constructor
	/// </summary>
	/// <param name="_pos">position of object</param>
	/// <param name="_size">width and height of rect</param>
	GPlayer(SVector2 _pos, SVector2 _size) : CMoveObject(_pos, _size) { s_instance = this; }

	/// <summary>
	/// constructor
	/// </summary>
	/// <param name="_pos">position of object</param>
	/// <param name="_size">width and height of rect</param>
	/// <param name="_pRenderer">renderer</param>
	/// <param name="_pFileName">file path name (relative)</param>
	GPlayer(SVector2 _pos, SVector2 _size, CRenderer* _pRenderer,
		const char* _pFileName) : CMoveObject(_pos, _size, _pRenderer, _pFileName) {
		m_foundItem = false;
		s_instance = this;
	}

	/// <summary>
	/// destructor
	/// </summary>
	~GPlayer() {}
#pragma endregion

#pragma region public override function
	/// <summary>
	/// update every frame
	/// </summary>
	/// <param name="_deltaTime">time since last frame</param>
	void Update(float _deltaTime) override;

	/// <summary>
	/// render every frame
	/// </summary>
	/// <param name="_pRenderer"></param>
	void Render(CRenderer* _pRenderer) override;
#pragma endregion

#pragma region public function
	/// <summary>
	/// set inventory item
	/// </summary>
	/// <param name="_inventoryItem">inventory item</param>
	void SetInventoryItem(GInventoryItems* _inventoryItem);
	
	/// /// <summary>
	/// set NPC
	/// </summary>
	/// <param name="_npc">NPC</param>
	void SetNPC(GNpc* _npc);
#pragma endregion


private:
#pragma region private primitive variable
	/// <summary>
	/// is jump active
	/// </summary>
	bool m_jump;

	/// <summary>
	/// time till jump ends
	/// </summary>
	float m_jumpTime;

	/// <summary>
	/// found item
	/// </summary>
	bool m_foundItem;

	/// <summary>
	/// is colliding with NPC
	/// </summary>
	bool m_npcCollision;

	/// <summary>
	/// inventory item
	/// </summary>
	GInventoryItems* m_inventoryItem;

	/// <summary>
	/// NPC
	/// </summary>
	GNpc* m_npc;
#pragma endregion

 static GPlayer* s_instance;
};