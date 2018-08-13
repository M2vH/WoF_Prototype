#pragma once
#include "TexturedObject.h"
class GTextBubble :
	public CTexturedObject
{
public:
	GTextBubble(
		SVector2 _pos,
		SVector2 _size);

	~GTextBubble();

#pragma region public overrides
	void Update(float _deltaTime) override;

	void Render(CRenderer* _pRenderer) override;
#pragma endregion

private:
	CTexturedObject* m_pCompleteTexture[9];
	int m_width;
	int m_height;
};

