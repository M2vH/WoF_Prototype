#pragma once

/// <summary>
/// core game class for game logic
/// </summary>
class GGame
{
public:
#pragma region constructor
	/// <summary>
	/// constructor
	/// </summary>
	GGame() {}

	/// <summary>
	/// destructor
	/// </summary>
	~GGame() {}
#pragma endregion

#pragma region public inline function
	/// <summary>
	/// get game
	/// </summary>
	/// <returns>game</returns>
	inline static GGame* Get()
	{
		// create game if not exists
		static GGame* pGame = new GGame();

		// return game
		return pGame;
	}
#pragma endregion

#pragma region public function
	/// <summary>
	/// initialize game
	/// </summary>
	void Init();
#pragma endregion
};