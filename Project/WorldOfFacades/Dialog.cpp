#include "Dialog.h"
#include "TextBubble.h"

class GTextBubble;

GDialog::GDialog(
	SVector2 _pos,
	SVector2 _size,
	const char* _text) : 
		CText(
			_text, 
			m_pFont, 
			SRect(_pos.X +32, _pos.Y + 32, _size.X, _size.Y), 
			m_TextColor
		)
{
	m_pTextBubble = new GTextBubble(_pos,_size);
}

/// <summary>
/// destructor
/// </summary>
GDialog::~GDialog()
{
	// ToDo (m2vh) clean up this class
}

void GDialog::Update(float _deltaTime)
{
	CText::Update(_deltaTime);
	// ToDo (m2vh) check if necessary;
	// m_pTextBubble->Update(_deltaTime);
}

void GDialog::Render(CRenderer * _pRenderer)
{
	if (!m_isDisplayed)
	{
		return;
	}
	else
	{
		// render text bubble;
		// ToDo (m2vh) Create TextBubble.class
		m_pTextBubble->Render(_pRenderer);
		// render text;
		CText::Render(_pRenderer);
	}
}
