#pragma once
#include "WorldBackground.h"
#include "Player.h"

#pragma region forward declaration
#pragma endregion




/// <summary>
/// the foreground class; is a triptichon of one image circulating endless on the screen; is in screenspace;
/// </summary>
class GForeground :
	public GWorldBackground
{
public:
	GForeground(float _speed, SVector2 _pos, SVector2 _size, CRenderer* _pRenderer,
		const char* _pFileName) : GWorldBackground(_pos, _size, _pRenderer, _pFileName) 
	{
		m_speed = _speed;
		m_inWorld = false;
		m_pPlayer = GPlayer::Get();
		m_pLeftFill->SetInWorld(false);
		m_pRightFill->SetInWorld(false);
	};
	
	
	~GForeground();

#pragma region public override
	void Update(float _deltaTime) override;

	void Render(CRenderer* _pRenderer) override;
#pragma endregion

#pragma region public inline functions
	inline void SetSpeed(float _speed) { m_speed = _speed; }

	inline float GetSpeed() { return m_speed; }


#pragma endregion


private:
#pragma region private inline functions
	/// <summary>
	/// set the new position of the triptichon;
	/// </summary>
	/// <param name="_movement">the value to move</param>
	inline void SetNewPosition(SVector2 _movement);
#pragma endregion

#pragma region private primitive
	/// <summary>
	/// the speed of motion; > 1 is faster than player; negative value moves opposite direction;
	/// </summary>
	float m_speed;

	SVector2 m_movement = SVector2(0,0);
#pragma endregion
#pragma region private variables
	
	/// <summary>
	/// pointer on the the player instance
	/// </summary>
	GPlayer* m_pPlayer;
#pragma endregion

};

