#pragma once
#include "Text.h"
#include "Game.h"
#include "Macro.h"
//#include "Engine.h"

#pragma region forward declaration
class GTextBubble;
class GGame;
#pragma endregion


class GDialog :
	public CText
{
public:
#pragma region ctor
	/// <summary>
	/// contructor
	/// </summary>
	GDialog(
		SVector2 _pos,
		SVector2 _size,
		const char* _text
	);

	/// <summary>
	/// destructor;
	/// </summary>
	~GDialog();

#pragma endregion
#pragma region public overrides
	/// <summary>
	/// Update every frame;
	/// </summary>
	/// <param name="_deltaTime">time since last frame</param>
	void Update(float _deltaTime) override;

	/// <summary>
	/// Render, if m_isDisplayed == true;
	/// </summary>
	/// <param name="_pRenderer">the renderer</param>
	void Render(CRenderer* _pRenderer) override;
#pragma endregion
#pragma region public functions
	// ToDo (m2vh) delete; parent class has function already;
	//inline void SetFont(CFont* _pfont) { m_pFont = _pfont; };
#pragma endregion


private:
#pragma region private primitives
	/// <summary>
	/// Dialog will be displayed;
	/// </summary>
	bool m_isDisplayed = true;	// ToDo (m2vh) reverse after test;

	/// <summary>
	/// The TextBubble, the text is rendered on;
	/// </summary>
	GTextBubble* m_pTextBubble = nullptr;

	//CFont* m_pFont;

	//SVector2 m_position;

	SColor m_TextColor = BLACK;
#pragma endregion

};

