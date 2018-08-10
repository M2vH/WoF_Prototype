#pragma once
#include <iostream>	// TODO: DELETE
#include <string>	// TODO: DELETE
#include "Macro.h"	// ToDo: Delete

#pragma region project includes
#include "EnumWorldState.h"
#pragma endregion

/// <summary>
/// singleton class; use Get() to get an instance;
/// </summary>
class GWorldStatus
{
public:
#pragma region public function
	
	/// <summary>
	/// get an instance of WorldStatus;
	/// </summary>
	/// <returns></returns>
	static GWorldStatus* Get() {
		return (!m_instance) ? m_instance = new GWorldStatus : m_instance;
	}

	/// <summary>
	/// Get the state the world is in;
	/// </summary>
	EWorldState GetState() { return m_worldState; };
	
	/// <summary>
	/// Set the status of the world; 
	/// Use bitshift to increase state;
	/// </summary>
	/// <param name="_newState">bitshift the GetState</param>
	void SetState(EWorldState _newState) {
		if (
			_newState < EWorldState::WORLD_STATE_1 ||
			_newState > EWorldState::WORLD_STATE_7)
		{
			return;
		}
		else
		{
			m_worldState = _newState;
		}

	};
#pragma endregion


private:
#pragma region private ctor
	/// <summary>
	/// private ctor; we are singleton;
	/// </summary>
	GWorldStatus() { 
		m_worldState = EWorldState::WORLD_STATE_4; 
		LOG_MESSAGE("World status: ", "Object created.");
	};
#pragma endregion
#pragma region destructor
	~GWorldStatus() ;

#pragma endregion
#pragma region private variables
	/// <summary>
	/// The instance of this singleton
	/// </summary>
	static GWorldStatus* m_instance;
 
	/// <summary>
	/// The state the world is in.
	/// </summary>
	EWorldState m_worldState = EWorldState::WORLD_STATE_1;
#pragma endregion



};

