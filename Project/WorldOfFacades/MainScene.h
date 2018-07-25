#pragma once

#pragma region project include
#include "Scene.h"
#pragma endregion

#pragma region forward decleration
class GWorld;
#pragma endregion

/// <summary>
/// main game scene class
/// </summary>
class GMainScene : public CScene
{
public:
#pragma region constructor
	/// <summary>
	/// constructor
	/// </summary>
	GMainScene() : CScene() {}
#pragma endregion

#pragma region public override function
	/// <summary>
	/// initialize scene
	/// </summary>
	virtual void Init() override;

	/// <summary>
	/// cleaning up scene
	/// </summary>
	virtual void Clean() override;
#pragma endregion

private:
#pragma region private variable
	/// <summary>
	/// world
	/// </summary>
	GWorld* m_pWorld;
#pragma endregion

};