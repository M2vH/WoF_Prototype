#pragma once

#pragma region project include
#include "TexturedObject.h"
#pragma endregion

/// <summary>
/// inventory class
/// </summary>
class GInventory : public CTexturedObject
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
	GInventory(SVector2 _pos, SVector2 _size, CRenderer* _pRenderer,
		const char* _pFileName);
	
	/// <summary>
	/// destuctor
	/// </summary>
	~GInventory() {};
#pragma endregion

#pragma region public override function
	/// <summary>
	/// update every frame
	/// </summary>
	/// <param name="_deltaTime">time since last frame</param>
	virtual void Update(float _deltaTime) override;

	/// <summary>
	/// render every frame
	/// </summary>
	/// <param name="_pRenderer">renderer</param>
	virtual void Render(CRenderer* _pRenderer) override;
#pragma endregion
};

