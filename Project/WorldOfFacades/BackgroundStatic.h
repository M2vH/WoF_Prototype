#pragma once
#include "MoveObject.h"

class CInput;

class GBackgroundStatic :
	public CMoveObject
{
public:
#pragma region constructor
	
	GBackgroundStatic(
		SVector2 _pos,
		SVector2 _size,
		CRenderer* _pRenderer,
		const char* _pFileName
	) : CMoveObject(_pos, _size, _pRenderer, _pFileName) 
	{
		m_inWorld = false;
	};
	
	
	
	
	
	~GBackgroundStatic();

#pragma endregion
#pragma region public override
	void Update(float _deltaTime) override;

	void Render(CRenderer* _pRenderer) override;
#pragma endregion
#pragma region public inline function
	//inline void SetInput(CInput* _pInput) { m_pInput = _pInput; }
#pragma endregion


#pragma region private variable
	//CInput* m_pInput;

#pragma endregion

};

