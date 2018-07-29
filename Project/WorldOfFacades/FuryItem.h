#pragma once
#pragma region project includes
#include "MoveObject.h"  
#include "EnumItemState.h"
#pragma endregion

class GFuryItem :
	public CMoveObject
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
	GFuryItem(
		SVector2 _pos, 
		SVector2 _size, 
		CRenderer* _pRenderer,
		const char* _pFileName
		) : CMoveObject(
				_pos, 
				_size, 
				_pRenderer, 
				_pFileName) 
	{
		m_inWorld = true;
		m_colType = ITEM;
	}

	/// <summary>
	/// destructor
	/// </summary>
	~GFuryItem() {};
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

#pragma region public inline function
	// ToDo (m2vh) make Get and Set for private vars
	// GetItemState
	/// <summary>
	/// Get the state the item is in.
	/// </summary>
	/// <returns>the state the item is in</returns>
	EItemState GetItemState() { return m_ItemState; }

	// SetItemState
	/// <summary>
	/// Set the state
	/// </summary>
	/// <param name="_state">the new state</param>
	void SetItemState(EItemState _state) { m_ItemState = _state; }
#pragma endregion
#pragma region private primitive variables

	EItemState m_ItemState = EItemState::ACTIVE;

#pragma endregion


};

