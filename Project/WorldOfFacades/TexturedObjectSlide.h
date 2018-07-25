#pragma once
#pragma region project include
#include "Object.h"
#include "TexturedObject.h"
#include "Rect.h"
#pragma endregion

#pragma region forward decleration
class CRenderer;
class CTexture;
class CTexturedObject;
#pragma endregion

/// <summary>
/// textured object class
/// </summary>
class CTexturedObjectSlide :	public CTexturedObject
{
public:
#pragma region constructor
	/// <summary>
	/// constructor
	/// </summary>
	CTexturedObjectSlide() : CTexturedObject() {}
	
	/// <summary>
	/// constructor
	/// </summary>
	/// <param name="_pos">position of object</param>
	CTexturedObjectSlide(SVector2 _pos) : CTexturedObject(_pos) {}

	/// <summary>
	/// constructor
	/// </summary>
	/// <param name="_pos">position of object</param>
	/// <param name="_size">width and height of rect</param>
	CTexturedObjectSlide(SVector2 _pos, SVector2 _size) : CTexturedObject(_pos)
	{
		m_position = _pos;
		m_rect.x = _pos.X;
		m_rect.y = _pos.Y;
		m_rect.w = _size.X;
		m_rect.h = _size.Y;
	}

	/// <summary>
	/// constructor
	/// </summary>
	/// <param name="_pos">position of object</param>
	/// <param name="_size">width and height of rect</param>
	/// <param name="_pRenderer">renderer</param>
	/// <param name="_pFileName">file path name (relative)</param>
	CTexturedObjectSlide(SVector2 _pos, SVector2 _size, CRenderer* _pRenderer,
		const char* _pFileName) : CTexturedObject(_pos, _size, _pRenderer, _pFileName)
	{
		m_inWorld = false;
	}

	/// <summary>
	/// destructor
	/// </summary>
	~CTexturedObjectSlide();
#pragma endregion

#pragma region public override function
	/// <summary>
	/// update every frame
	/// </summary>
	virtual void Update(float _deltaTime) override;

	/// <summary>
	/// render every frame
	/// </summary>
	/// <param name="_pRenderer">renderer</param>
	virtual void Render(CRenderer* _pRenderer) override;
#pragma endregion

//#pragma region public inline function
//	/// <summary>
//	/// get rect
//	/// </summary>
//	/// <returns>rect of object</returns>
//	inline SRect GetRect() { return m_rect; }
//
//	/// <summary>
//	/// set rect
//	/// </summary>
//	/// <param name="_rect">rect to set</param>
//	inline void SetRect(SRect _rect) { m_rect = _rect; }
//
//	/// <summary>
//	/// get texture
//	/// </summary>
//	/// <returns>texture</returns>
//	inline CTexture* GetTexture() { return m_pTexture; }
//#pragma endregion

protected:
//#pragma region protected variable
//	/// <summary>
//	/// rect of texture
//	/// </summary>
//	SRect m_rect;
//
//	SRect m_srcRect;
//
//	/// <summary>
//	/// texture of object
//	/// </summary>
//	CTexture* m_pTexture = nullptr;
//#pragma endregion
};