#pragma once
#pragma region project include
#include "WorldStatus.h"
#pragma endregion


#pragma region forward declaration
class CFont;
#pragma endregion


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
	~GGame() { Clean(); }
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

	/// <summary>
	/// set gigi font
	/// </summary>
	/// <param name="_pGigiFont">gigi font</param>
	inline void SetGigiFont(CFont* _pGigiFont) { m_pGigiFont = _pGigiFont; }

	/// <summary>
	/// get gigi font
	/// </summary>
	/// <returns>gigi  font</returns>
	inline CFont* GetGigiFont() { return m_pGigiFont; }

	/// <summary>
	/// set pristina font
	/// </summary>
	/// <param name="_pGigiFont">pristina font</param>
	inline void SetPristinaFont(CFont* _pPristinaFont) { m_pPristinaFont = _pPristinaFont; }

	/// <summary>
	/// get pristina font
	/// </summary>
	/// <returns>pristina  font</returns>
	inline CFont* GetPristinaFont() { return m_pPristinaFont; }
#pragma endregion

#pragma region public function
	/// <summary>
	/// initialize game
	/// </summary>
	void Init();

	/// <summary>
	/// clean game
	/// </summary>
	void Clean();
#pragma endregion
private:
#pragma region private variables
	/// <summary>
	/// base gigi font
	/// </summary>
	CFont* m_pGigiFont = nullptr;

	/// <summary>
	/// base Pristina font
	/// </summary>
	CFont* m_pPristinaFont = nullptr;

	/// <summary>
	/// pointer to worldstatus class;
	/// </summary>
	GWorldStatus* m_pWorldStatus;
#pragma endregion

};