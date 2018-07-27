#pragma once
#include "Object.h"
#include "Engine.h"
#include "BackgroundStatic.h"

class GBackgroundSlide :
	public CObject
{
public:
	/// <summary>
	/// constructor
	/// </summary>
	/// <param name="_filePath">path/to/file<param>
	GBackgroundSlide(const char* _filePath);



	~GBackgroundSlide();

#pragma region public override function
	/// <summary>
	/// update every frame
	/// </summary>
	/// <param name="_deltaTime">time since last frame</param>
	void Update(float _deltaTime) override;

	/// <summary>
	/// render every frame
	/// </summary>
	/// <param name="_pRenderer"></param>
	void Render(CRenderer* _pRenderer) override;
#pragma endregion

	GBackgroundStatic* m_pLeftImage = nullptr;
	GBackgroundStatic* m_pRightImage = nullptr;
	GBackgroundStatic* m_pCenterImage = nullptr;

private:
	const char* m_pFilePath;
	SVector2 m_Size;
	float m_Speed;
	SVector2 m_ResetPosition;



};

