#pragma once

#pragma region project include
#include "Vector2.h"
#pragma endregion

#pragma region forward decleration
class CRenderer;
#pragma endregion

/// <summary>
/// base object class
/// </summary>
class CObject
{
public:
#pragma region constructor
	/// <summary>
	/// constructor
	/// </summary>
	CObject() {}

	/// <summary>
	/// constructor
	/// </summary>
	/// <param name="_pos">position of object</param>
	CObject(SVector2 _pos) : m_position(_pos) {}
#pragma endregion

#pragma region public inline function
	/// <summary>
	/// get position
	/// </summary>
	/// <returns>position</returns>
	inline SVector2 GetPosition() { return m_position; }

	/// <summary>
	/// set position
	/// </summary>
	/// <param name="_pos">position to set</param>
	inline void SetPosition(SVector2 _pos) { m_position = _pos; }

	/// <summary>
	/// add position
	/// </summary>
	/// <param name="_pos">position to add</param>
	inline void AddPosition(SVector2 _pos) { m_position = m_position + _pos; }
#pragma endregion

#pragma region public function
	/// <summary>
	/// update every frame
	/// </summary>
	/// <param name="_deltaTime">time since last frame</param>
	virtual void Update(float _deltaTime) = 0;

	/// <summary>
	/// render every frame
	/// </summary>
	/// <param name="_pRenderer">renderer</param>
	virtual void Render(CRenderer* _pRenderer) = 0;
#pragma endregion

protected:
#pragma region protected variable
	/// <summary>
	/// position of object
	/// </summary>
	SVector2 m_position;

	/// <summary>
	/// angle of object
	/// </summary>
	float m_angle;
#pragma endregion
};