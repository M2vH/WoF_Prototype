#pragma once
#include "MoveObject.h"
#include "Macro.h"

class GForegroundSlide :
	public CMoveObject
{
public:
#pragma region constructor

	GForegroundSlide(
		SVector2 _pos, 
		SVector2 _size, 
		CRenderer* _pRenderer,
		const char* _pFileName,
		int m_distance = 1
	) : CMoveObject(_pos, _size, _pRenderer, _pFileName) 
	{
		m_speed = PLAYER_SPEED * m_distance * FOREGROUND_DISTFACTOR;
	};

	~GForegroundSlide();

#pragma endregion

#pragma region public inline function

	void Update(float _deltaTime) override;

	void Render(CRenderer* _pRenderer);

	void SetDistFactor(float _factor) { m_distFactor = _factor; }

	float GetDistFactor() { return m_distFactor; }
#pragma endregion

protected:
	float m_distFactor = FOREGROUND_DISTFACTOR;
	
};

