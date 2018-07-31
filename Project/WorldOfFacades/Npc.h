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
	// constructor

	GNpc(EEmotionType _type, SVector2 _pos, SVector2 _size, CRenderer* _pRenderer,
		const char* _pFileName) : CMoveObject(_pos, _size, _pRenderer, _pFileName) 
	{
		m_NpcState = ENPCState::WAITING;
		m_EmoType = _type;
	}

	// GNpc();
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

