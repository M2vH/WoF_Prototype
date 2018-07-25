#pragma once

/// <summary>
/// vector 2 struct
/// </summary>
struct SVector2
{
public:
#pragma region constructor
	/// <summary>
	/// constructor
	/// </summary>
	SVector2() {}

	/// <summary>
	/// constructor
	/// </summary>
	SVector2(float _x, float _y) { X = _x; Y = _y; }
#pragma endregion

#pragma region public primitive variable
	/// <summary>
	/// x value
	/// </summary>
	float X = 0.0f;

	/// <summary>
	/// y value
	/// </summary>
	float Y = 0.0f;
#pragma endregion

#pragma region operator
	/// <summary>
	/// vector2 + vector2
	/// </summary>
	/// <param name="_vec2">vector2</param>
	/// <returns>new vector2</returns>
	SVector2 operator+(SVector2 _vec2)
	{
		return SVector2(X + _vec2.X, Y + _vec2.Y);
	}

	/// <summary>
	/// vector2 * float
	/// </summary>
	/// <param name="_value">float value</param>
	/// <returns>new vector2</returns>
	SVector2 operator*(float _value)
	{
		return SVector2(X * _value, Y * _value);
	}
#pragma endregion
};