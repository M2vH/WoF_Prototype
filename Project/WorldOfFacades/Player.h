#pragma once

#pragma region project include
#include "MoveObject.h"  
#pragma endregion

/// <summary>
/// player class
/// </summary>
class GPlayer :	public CMoveObject
{
public:
#pragma region constructor
	/// <summary>
	/// constructor
	/// </summary>
	/// <param name="_pos">position of object</param>
	GPlayer(SVector2 _pos) : CMoveObject(_pos) {}

	/// <summary>
	/// constructor
	/// </summary>
	/// <param name="_pos">position of object</param>
	/// <param name="_size">width and height of rect</param>
	GPlayer(SVector2 _pos, SVector2 _size) : CMoveObject(_pos, _size) {}

	/// <summary>
	/// constructor
	/// </summary>
	/// <param name="_pos">position of object</param>
	/// <param name="_size">width and height of rect</param>
	/// <param name="_pRenderer">renderer</param>
	/// <param name="_pFileName">file path name (relative)</param>
	GPlayer(SVector2 _pos, SVector2 _size, CRenderer* _pRenderer,
		const char* _pFileName) : CMoveObject(_pos, _size, _pRenderer, _pFileName) {}

	/// <summary>
	/// destructor
	/// </summary>
	~GPlayer() {}
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

private:
#pragma region private primitive variable
	/// <summary>
	/// is jump active
	/// </summary>
	bool m_jump;

	/// <summary>
	/// time till jump ends
	/// </summary>
	float m_jumpTime;
#pragma endregion
};