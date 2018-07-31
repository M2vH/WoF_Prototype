#pragma once
#pragma region project include
#include "MoveObject.h"
#include "EnumNpcState.h"
#include "EnumEmotionType.h"
#pragma endregion


class GNpc :
	public CMoveObject
{
public:

#pragma region constructor
	/// <summary>
	/// constructor
	/// </summary>
	/// <param name="_type">emotionType</param>
	/// <param name="_pos">position of object</param>
	/// <param name="_size">width and height of rect</param>
	/// <param name="_pRenderer">renderer</param>
	/// <param name="_pFileName">file path name (relative)</param>
	GNpc(EEmotionType _type, SVector2 _pos, SVector2 _size, CRenderer* _pRenderer,
		const char* _pFileName) : CMoveObject(_pos, _size, _pRenderer, _pFileName) 
	{
		m_NpcState = ENPCState::WAITING;
		m_EmoType = _type;
	}

	// GNpc();
	/// <summary>
	/// destructor
	/// </summary>
	~GNpc();
#pragma endregion

#pragma region public inline functions
	// Get and Set of private vars
	inline void SetNPCState(ENPCState _state) { m_NpcState = _state; }

	inline ENPCState GetNPCState() { return m_NpcState; }
#pragma endregion

private:
#pragma region private primitive variable
	// the state 
	ENPCState m_NpcState;

	// the type
	EEmotionType m_EmoType;
#pragma endregion

};

