#pragma once
#pragma region project include
#include "TexturedObject.h"  
#pragma endregion

/// <summary>
/// moveable object class
/// </summary>
class CMoveObject :	public CTexturedObject
{
public:
#pragma region constructor
	/// <summary>
	/// constructor
	/// </summary>
	/// <param name="_pos">position of object</param>
	CMoveObject(SVector2 _pos) : CTexturedObject(_pos) {}

	/// <summary>
	/// constructor
	/// </summary>
	/// <param name="_pos">position of object</param>
	/// <param name="_size">width and height of rect</param>
	CMoveObject(SVector2 _pos, SVector2 _size) : CTexturedObject(_pos, _size) {}

	/// <summary>
	/// constructor
	/// </summary>
	/// <param name="_pos">position of object</param>
	/// <param name="_size">width and height of rect</param>
	/// <param name="_pRenderer">renderer</param>
	/// <param name="_pFileName">file path name (relative)</param>
	CMoveObject(SVector2 _pos, SVector2 _size, CRenderer* _pRenderer,
		const char* _pFileName) : CTexturedObject(_pos, _size, _pRenderer, _pFileName) {}

	/// <summary>
	/// destructor
	/// </summary>
	~CMoveObject() {}
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
	/// get movement speed
	/// </summary>
	/// <returns>speed value</returns>
	inline float GetSpeed() { return m_speed; }

	/// <summary>
	/// set movement speed
	/// </summary>
	/// <param name="_speed">value to set</param>
	inline void SetSpeed(float _speed) { m_speed = _speed; }

	/// <summary>
	/// get movement direction
	/// </summary>
	/// <returns>movement direction</returns>
	inline SVector2 GetMovement() { return m_movement; }

	/// <summary>
	/// set movement
	/// </summary>
	/// <param name="_movement">value to set</param>
	inline void SetMovement(SVector2 _movement) { m_movement = _movement; }

	/// <summary>
	/// activate gravity
	/// </summary>
	inline void ActivateGravity() { m_gravity = true; }

	/// <summary>
	/// deactivate gravity
	/// </summary>
	inline void DeactivateGravity() { m_gravity = false; }
#pragma endregion

protected:
#pragma region protected primitive variable
	/// <summary>
	/// if gravity is active
	/// </summary>
	bool m_gravity;

	/// <summary>
	/// object is on ground
	/// </summary>
	bool m_grounded;

	/// <summary>
	/// movement speed
	/// </summary>
	float m_speed;

	/// <summary>
	/// fall time
	/// </summary>
	float m_fallTime = 0.001f;

	/// <summary>
	/// direction
	/// </summary>
	SVector2 m_movement;
#pragma endregion
};