#pragma once
#pragma region debug include
#include <iostream>	///TODO: DELETE
#include <string>	///TODO: DELETE
#pragma endregion

#include "TextBubble.h"
#include "Texture.h"
#include "Engine.h"
#include "Macro.h"



#pragma region Constructor

/// <summary>
/// ctor; dont use this; use Dialog.class instead;
/// </summary>
/// <param name="_pos">Position on screen</param>
/// <param name="_size">Size of the middle slice of nine</param>
GTextBubble::GTextBubble(SVector2 _pos, SVector2 _size) : CTexturedObject()
{
	// the Renderer
	CRenderer* ptheRenderer = CEngine::Get()->GetRenderer();

	// 

	// top left corner
	m_position = _pos;
	m_width = (int)_size.X;
	m_height = (int)_size.Y;
	m_pTexture = new CTexture(
		"Texture/Background/T_TextBubble_96x96.png",
		ptheRenderer
	);

#pragma region set srcRect for each part of bubble
	int pos_x = 0;
	int pos_y = 0;
	int c = 0;

	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			// count

			CTexturedObject* theBubblePart = new CTexturedObject(
				SVector2(),
				SVector2()
			);
			// pointer on complete texture;
			theBubblePart->SetTexture(m_pTexture);
			// set to screenspace
			theBubblePart->SetInWorld(false);
			// set srcRect to slice of nine;
			theBubblePart->SetSrcRect(SRect(pos_x, pos_y, 32, 32));

			// add part of bubble to completeTexture[]
			m_pCompleteTexture[c] = theBubblePart;
			// increase count
			c++;
			// shift pos_y + 32
			pos_x += 32;
		}
		// reset pos_x; wieder links in der reihe
		pos_x = 0;
		// shift pos_y + 32; aber eine reihe tiefer
		pos_y += 32;
	}
#pragma endregion
#pragma region set destRect for all parts of bubble

	/*	+---+---------+---+
	*	| 0 |    1    | 2 |
	*	+---+---------+---+
	*	|   |TEXT     |   |
	*	| 3 |   TEXT  | 5 |
	*	|   |     TEXT|   |
	*	+---+---------+---+
	*	| 6 |    7    | 8 |
	*	+---+---------+---+
	*/
	pos_x = (int)m_position.X;
	pos_y = (int)m_position.Y;

	m_pCompleteTexture[0]->SetRect(SRect(pos_x, pos_y, 32, 32));
	m_pCompleteTexture[1]->SetRect(SRect(pos_x + 32, pos_y, m_width, 32));
	m_pCompleteTexture[2]->SetRect(SRect(pos_x + m_width + 32, pos_y, 32, 32));
	// next line;
	pos_y += 32;
	m_pCompleteTexture[3]->SetRect(SRect(pos_x, pos_y, 32, m_height));
	m_pCompleteTexture[4]->SetRect(SRect(pos_x + 32, pos_y, m_width, m_height));
	m_pCompleteTexture[5]->SetRect(SRect(pos_x + m_width + 32, pos_y, 32, m_height));
	// next line;
	pos_y += m_height;
	m_pCompleteTexture[6]->SetRect(SRect(pos_x, pos_y, 32, 32));
	m_pCompleteTexture[7]->SetRect(SRect(pos_x + 32, pos_y, m_width, 32));
	m_pCompleteTexture[8]->SetRect(SRect(pos_x + 32 + m_width, pos_y, 32, 32));
#pragma endregion


}


#pragma endregion
GTextBubble::~GTextBubble()
{

	for (size_t i = 0; i < 8; i++)
	{
		m_pCompleteTexture[i] = nullptr;
	}
	delete m_pTexture;
	m_pTexture = nullptr;
	delete m_pCompleteTexture;
}
#pragma region public overrides

void GTextBubble::Update(float _deltaTime)
{
	CTexturedObject::Update(_deltaTime);
}

void GTextBubble::Render(CRenderer * _pRenderer)
{
	for (size_t i = 0; i < 9; i++)
	{
		m_pCompleteTexture[i]->Render(_pRenderer);
		//LOG_MESSAGE("Texture Source Rect: ", std::to_string((int)i));
		//LOG_MESSAGE("X: ", std::to_string((int)m_pCompleteTexture[i]->GetSrcRect().x));
		//LOG_MESSAGE("Y: ", std::to_string((int)m_pCompleteTexture[i]->GetSrcRect().y));
		//LOG_MESSAGE(" - ", "- -");
	}
}

#pragma endregion
