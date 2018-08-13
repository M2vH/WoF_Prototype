#pragma once
#include "TexturedObject.h"
#include "TextBubble.h"
class GDIalogImage :
	public CTexturedObject
{
public:
	GDIalogImage(SVector2 _pos, SVector2 _size, SVector2 _margin, char** _fileNames);

	~GDIalogImage();
#pragma region public overrides
	void Update(float _deltaTime) override;
	void Render(CRenderer* pRenderer) override;
#pragma endregion
#pragma region private variables
	GTextBubble* m_pTheBubble;
	SVector2 m_margin;
	char* m_fileNames[3];
	CTexture* m_AllTextures[3];

#pragma endregion


};

