#pragma once
#pragma region project include
#include "Object.h"
#include "Rect.h"
#include "Enum.h"
#pragma endregion

#pragma region forward decleration
class CRenderer;
class CTexture;
#pragma endregion

/// <summary>
/// textured object class
/// </summary>
class CTexturedObject :	public CObject
{
public:
#pragma region constructor
	/// <summary>
	/// constructor
	/// </summary>
	CTexturedObject() : CObject() {}
	
	/// <summary>
	/// constructor
	/// </summary>
	/// <param name="_pos">position of object</param>
	CTexturedObject(SVector2 _pos) : CObject(_pos) {}

	/// <summary>
	/// constructor
	/// </summary>
	/// <param name="_pos">position of object</param>
	/// <param name="_size">width and height of rect</param>
	CTexturedObject(SVector2 _pos, SVector2 _size) : CObject(_pos)
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
	CTexturedObject(SVector2 _pos, SVector2 _size, CRenderer* _pRenderer,
		const char* _pFileName);

	/// <summary>
	/// destructor
	/// </summary>
	~CTexturedObject();
#pragma endregion

#pragma region public override function
	/// <summary>
	/// update every frame
	/// </summary>
	/// <param name="_deltaTime">time since last frame</param>
	virtual void Update(float _deltaTime) override;

	/// <summary>
	/// render every frame
	/// </summary>
	/// <param name="_pRenderer">renderer</param>
	virtual void Render(CRenderer* _pRenderer) override;
#pragma endregion

#pragma region public inline function
	/// <summary>
	/// set object rendered in world
	/// </summary>
	/// <param name="_inWorld">in world or not</param>
	inline void SetInWorld(bool _inWorld) { m_inWorld = _inWorld; }

	/// <summary>
	/// get collision type of object
	/// </summary>
	/// <returns>collision type</returns>
	inline ECollisionType GetColType() { return m_colType; }

	/// <summary>
	/// set collision type of object
	/// </summary>
	/// <param name="_colType">collision type</param>
	void SetColType(ECollisionType _colType) { m_colType = _colType; }

	/// <summary>
	/// get rect
	/// </summary>
	/// <returns>rect of object</returns>
	inline SRect GetRect() { return m_rect; }

	/// <summary>
	/// set rect
	/// </summary>
	/// <param name="_rect">rect to set</param>
	inline void SetRect(SRect _rect) { m_rect = _rect; }
	
	/// <summary>
	/// get source rect
	/// </summary>
	/// <returns>source rect of object</returns>
	inline SRect GetSrcRect() { return m_srcRect; }

	/// <summary>
	/// set source rect
	/// </summary>
	/// <param name="_rect">rect to set</param>
	inline void SetSrcRect(SRect _rect) { m_srcRect = _rect; }

	/// <summary>
	/// get mirror
	/// </summary>
	/// <returns>mirror value of object</returns>
	inline SVector2 GetMirror() { return m_mirror; }
	
	/// /// <summary>
	/// set mirror
	/// </summary>
	/// <param name="_mirror">value to set</param>
	inline void SetMirror(SVector2 _mirror) { m_mirror = _mirror; }

	/// <summary>
	/// get texture
	/// </summary>
	/// <returns>texture</returns>
	inline CTexture* GetTexture() { return m_pTexture; }
#pragma endregion

protected:
#pragma region protected primitive variable
	/// <summary>
	/// if object is rendered in screen or world space
	/// </summary>
	bool m_inWorld = true;

	/// <summary>
	/// collision type
	/// </summary>
	ECollisionType m_colType;
#pragma endregion

#pragma region protected variable
	/// <summary>
	/// rect of texture
	/// </summary>
	SRect m_rect;

	/// <summary>
	/// source rect of texture
	/// </summary>
	SRect m_srcRect;

	/// <summary>
	/// mirror vector2
	/// x != 0 -> mirror horizontal
	/// y != 0 -> mirror vertical
	/// if x != 0 -> ignore y
	/// </summary>
	SVector2 m_mirror;

	/// <summary>
	/// texture of object
	/// </summary>
	CTexture* m_pTexture = nullptr;
#pragma endregion
};