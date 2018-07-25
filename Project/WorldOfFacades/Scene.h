#pragma once

#pragma region project include
#include "Engine.h"
#pragma endregion

/// <summary>
/// pure virtual scene class
/// </summary>
class CScene
{
public:
#pragma region constructor
	/// <summary>
	/// constructor
	/// </summary>
	CScene() {}
#pragma endregion

#pragma region public function
	/// <summary>
	/// initialize scene
	/// </summary>
	virtual void Init() = 0;

	/// <summary>
	/// cleaning up scene
	/// </summary>
	virtual void Clean() = 0;
#pragma endregion
};