#pragma once
#pragma region project include
#include "MoveObject.h"  
#pragma endregion

/// <summary>
/// inventoryItem class
/// </summary>
class GInventoryItem :	public CMoveObject
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
	GInventoryItem(SVector2 _pos, SVector2 _size, CRenderer* _pRenderer,
		const char* _pFileName);

	/// <summary>
	/// destructor
	/// </summary>
	~GInventoryItem();
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
	/// <summary>
	/// get emotion type of object
	/// </summary>
	/// <returns>collision type</returns>
	inline EEmotionType GetEmoType() { return m_emoType; }

	/// <summary>
	/// set emotion type of object
	/// </summary>
	/// <param name="_colType">emotion type</param>
	void SetColType(EEmotionType _emoType) { m_emoType = _emoType; }
#pragma endregion


protected:
#pragma region protected primitive variables
	/// <summary>
	/// emotion type
	/// </summary>
	EEmotionType m_emoType;

	/// <summary>
	/// fury enum
	/// </summary>
	EEmotionType m_fury = FURY;

	/// <summary>
	/// fear enum
	/// </summary>
	EEmotionType m_fear = FEAR;

	/// <summary>
	/// sadness enum
	/// </summary>
	EEmotionType m_sadness = SAD;
#pragma endregion

};

