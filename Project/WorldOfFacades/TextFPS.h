#pragma once

#pragma region project include
#include "Text.h"
#include "Time.h"
#pragma endregion

/// <summary>
/// text class to show fps
/// </summary>
class GTextFPS : public CText
{
public:
#pragma region constructor
	/// <summary>
	/// constructor
	/// </summary>
	/// <param name="_pText">text value</param>
	/// <param name="_pFont">font</param>
	/// <param name="_rect">rect</param>
	/// <param name="_color">color</param>
	GTextFPS(const char* _pText, CFont* _pFont, SRect _rect = SRect(), SColor _color = SColor())
		: CText(_pText, _pFont, _rect, _color) {}

	/// <summary>
	/// destructor
	/// </summary>
	~GTextFPS() {}
#pragma endregion

#pragma region public override function
	/// <summary>
	/// update every frame
	/// </summary>
	/// <param name="_deltaTime">time since last frame</param>
	void Update(float _deltaTime) override
	{
		// text to show
		string text = "FPS: ";

		// append fps value
		text.append(to_string(CTime::GetFPS()));

		// random color
		SColor color = SColor(
			rand() % 255,
			rand() % 255,
			rand() % 255,
			rand() % 255
		);

		// set color
		SetColor(color);

		// set text
		SetText(text.c_str());
	}

	/// <summary>
	/// render every frame
	/// </summary>
	/// <param name="_pRenderer">renderer</param>
	void Render(CRenderer* _pRenderer) override { CText::Render(_pRenderer); }
#pragma endregion
};