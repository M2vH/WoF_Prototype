#pragma once
#include "TexturedObject.h"
#include "TextBubble.h"
#include "EnumNpcState.h"

/// <summary>
/// The class to display the TextImages;
/// </summary>
class GDialogImage :
	public CTexturedObject
{
public:
#pragma region ctor

	/// <summary>
	/// ctor;
	/// </summary>
	/// <param name="_pos">position of dialog</param>
	/// <param name="_size">size of textblock</param>
	/// <param name="_margin">distance from text to bubble border</param>
	/// <param name="_fileNames">array of path_to_images</param>
	GDialogImage(SVector2 _pos, SVector2 _size, SVector2 _margin, char** _fileNames);

	~GDialogImage();

#pragma endregion
#pragma region public overrides
	void Update(float _deltaTime) override;
	void Render(CRenderer* pRenderer) override;
#pragma endregion
#pragma region public inline functions
	/// <summary>
	/// Set the display render boolean; will render, if 'true';
	/// </summary>
	/// <param name="_display">set to true for rendering;</param>
	void SetRenderDisplay(bool _display) { m_renderDisplay = _display; }

	/// <summary>
	/// Get the display render value; will render if 'true';
	/// </summary>
	/// <returns></returns>
	bool GetRenderDisplay() { return m_renderDisplay; }

	/// <summary>
	/// set the text according to the state;
	/// </summary>
	/// <param name="_state"></param>
	void SetText(ENPCState _state);
#pragma endregion

private:
#pragma region private variables
	GTextBubble* m_pTheBubble;
	SVector2 m_margin;
	char* m_fileNames[3];
	CTexture* m_AllTextures[3];
	
	/// <summary>
	/// controls the rendering; will render if set to 'true'
	/// </summary>
	bool m_renderDisplay;

#pragma endregion


};

