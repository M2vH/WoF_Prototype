#pragma once
#pragma region project includes
#include "MoveObject.h"  
#pragma endregion

class GFuryItem :
	public CMoveObject
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
	GFuryItem(SVector2 _pos, SVector2 _size, CRenderer* _pRenderer,
		const char* _pFileName);

	/// <summary>
	/// destructor
	/// </summary>
	~GFuryItem() {};
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
};

