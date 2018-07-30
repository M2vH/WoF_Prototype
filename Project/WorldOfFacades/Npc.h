#pragma once
#pragma region project include
#include "MoveObject.h"
#include "EnumNpcState.h"
#pragma endregion


class GNpc :
	public CMoveObject
{
public:

#pragma region constructor
	// constructor

	GNpc(SVector2 _pos, SVector2 _size, CRenderer* _pRenderer,
		const char* _pFileName) : CMoveObject(_pos, _size, _pRenderer, _pFileName) 
	{
		m_NpcState = ENPCState::NONE;
	}

	// GNpc();
	~GNpc();

#pragma endregion
#pragma region public inline functions
	// Get and Set of private vars
	void SetNPCState(ENPCState _state) { m_NpcState = _state; }

	ENPCState GetNPCState() { return m_NpcState; }
#pragma endregion

#pragma region private primitive variable
	// the state 
	ENPCState m_NpcState;
#pragma endregion

};

